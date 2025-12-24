%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"  // 包含 AST 相关定义

#include <windows.h>





// 声明词法分析器函数
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

// 错误处理函数
void yyerror(const char *s) {
    fprintf(stderr, "错误 (第 %d 行): %s\n", yylineno, s);
}


ASTNode *ast_root = NULL;
%}

/* Ensure ASTNode type is visible to the generated header (parser.tab.h)
    so other files that include it (lexer) see the typedef before YYSTYPE. */
%code requires {
#include "ast.h"
}

/* 定义语义值类型 */
%union {
    int int_val;
    double float_val;
    char *str_val;
    ASTNode *ast_node;
}

/* 终结符（token）声明：把 lexer 中可能返回的 token 列出并关联 union 字段（若有） */
%token <str_val> DEVICE AS VAR WHEN THEN SET TO BETWEEN AND OR NOT TIME TEMPERATURE DURATION BOOL0 FLOAT0 INT0 RULE
%token <str_val> IF ELSE WHILE DO FOR AFTER BEFORE DAY OF WEEK IN_TOKEN
%token <str_val> LIGHT AIR_CONDITIONER WATER_HEATER TELEVISION WASHER FRIDGE ELECTRIC_FAN
%token <str_val> FALSE0 TRUE0 ON0 OFF
%token <str_val> MON TUE WED THU FRI SAT SUN

%token <str_val> IDENTIFIER STRING_LITERAL TIMEPOINT
%token <int_val> INT_NUMBER
%token <float_val> FLOAT_NUMBER

%token <str_val> EQ NEQ LT GT LE GE
%token <str_val> PLUS MINUS TIMES DIVIDE ASSIGN
%token <str_val> LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token <str_val> SEMICOLON COMMA COLON DOT

/* 声明非终结符的类型 */
%type <ast_node> program deviceDeclarationList deviceDeclaration deviceType
%type <ast_node> variableDeclarationList variableDeclaration valueType idnetifierList 
%type <ast_node> variableAssignmentList variableAssignment expression primary
%type <ast_node>    timeCondition dayList days day 
%type <ast_node> ruleList rule
%type <ast_node> stateList state action status number switch 
%type <ast_node> ifStatement  whileStatement forStatement range condition
/* 优先级和结合性定义 */ 
%left OR
%left AND
%left EQ NEQ
%left LT GT LE GE
%left PLUS MINUS
%left TIMES DIVIDE //TIMES是*
%right UNARY_MINUS NOT
%nonassoc LPAREN RPAREN

/* 起始符号 */
%start program

%%
/* 语法规则 */
//字母全部大写的终结符，由词法分析器yylex()返回的，小写字母开头的时非终结符
program: deviceDeclarationList variableDeclarationList variableAssignmentList ruleList{ ast_root = create_node("Program"); 
                                                    add_child(ast_root, $1);
                                                    add_child(ast_root, $2);
                                                    add_child(ast_root, $3);
                                                    add_child(ast_root, $4);
                                                  }


//设备声明部分
deviceDeclarationList: deviceDeclarationList deviceDeclaration
                     {
                         /* 构建 DeviceDeclarationList 节点，结构：
                            DeviceDeclarationList
                            ├─ DeviceDeclarationList (子节点，由前一个 deviceDeclarationList 产生式返回的 AST 节点)
                            └─ DeviceDeclaration (子节点，由 deviceDeclaration 产生式返回的 AST 节点)
                         */
                         $$ = create_node("DeviceDeclarationList");
                         add_child($$, $1);  // 前一个设备声明列表
                         add_child($$, $2);  // 当前设备声明
                     }
                   | deviceDeclaration
                     {
                         /* 单个设备声明时，直接返回该设备声明的 AST 节点 */
                         $$ = create_node("DeviceDeclarationList");
                         add_child($$, $1);
                     }
                   ;
deviceDeclaration: DEVICE deviceType IDENTIFIER AS STRING_LITERAL
                 {
                     /* 构建 DeviceDeclaration 节点，结构：
                        DeviceDeclaration
                        ├─ DEVICE (终结符)
                        ├─ DeviceType (子节点，由 deviceType 产生式返回的 AST 节点)
                        ├─ Identifier (终结符)
                        ├─ AS (终结符)
                        └─ StringLiteral (终结符)
                     */
                     $$ = create_node("DeviceDeclaration");
                     /* 把终结符 DEVICE 也作为叶子节点加入 */
                     { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
                     /* deviceType 已经返回 AST 节点 */
                     add_child($$, $2);
                     /* 标识符、AS、字符串作为叶子节点 */
                     { ASTNode *node = create_node("Identifier"); set_node_string_value(node, $3); add_child($$, node); }
                     { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $4); add_child($$, node); }
                     { ASTNode *node = create_node("StringLiteral"); set_node_string_value(node, $5); add_child($$, node); }
                     //print_ast_tree($$);  // 打印当前设备声明的 AST
                 }

deviceType: LIGHT           { $$ = create_node("DeviceType"); set_node_string_value($$, $1); }
          | AIR_CONDITIONER  { $$ = create_node("DeviceType"); set_node_string_value($$, $1); }
          | WATER_HEATER     { $$ = create_node("DeviceType"); set_node_string_value($$, $1); }
          | TELEVISION       { $$ = create_node("DeviceType"); set_node_string_value($$, $1); }
          | WASHER           { $$ = create_node("DeviceType"); set_node_string_value($$, $1); }
          | FRIDGE           { $$ = create_node("DeviceType"); set_node_string_value($$, $1); }
          | ELECTRIC_FAN     { $$ = create_node("DeviceType"); set_node_string_value($$, $1); }
          ;


//变量声明部分
variableDeclarationList: variableDeclarationList variableDeclaration
                     {
                         /* 构建 VariableDeclarationList 节点，结构：
                            VariableDeclarationList
                            ├─ VariableDeclarationList (子节点，由前一个 variableDeclarationList 产生式返回的 AST 节点)
                            └─ VariableDeclaration (子节点，由 variableDeclaration 产生式返回的 AST 节点)
                         */
                         $$ = create_node("VariableDeclarationList");
                         add_child($$, $1);  // 前一个变量声明列表
                         add_child($$, $2);  // 当前变量声明
                     }
                   | variableDeclaration
                     {
                         /* 单个变量声明时，直接返回该变量声明的 AST 节点 */
                         $$ = create_node("VariableDeclarationList");
                         add_child($$, $1);
                     }
                   ;
variableDeclaration: VAR valueType idnetifierList SEMICOLON
                   {$$ = create_node("varibleDeclaration");
                   { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
                   add_child($$, $2);
                   add_child($$, $3);
                   { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $4); add_child($$, node); }}

//valueType是关键字
valueType:TIME    { $$ = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
        | TEMPERATURE  { $$ = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
        | DURATION    { $$ = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
        | BOOL0         { $$ = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
        | FLOAT0        { $$ = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
        | INT0          { $$ = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
        ;

idnetifierList:idnetifierList COMMA IDENTIFIER {$$ = create_node("IdentifierList");
                                                add_child($$, $1);
                                                { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $2); add_child($$, node); }
                                                { ASTNode *node = create_node("Identifier"); set_node_string_value(node, $3); add_child($$, node); }}
                | IDENTIFIER  {$$ = create_node("IdentifierList");
                                { ASTNode *node = create_node("Identifier"); set_node_string_value(node, $1); add_child($$, node); }}
                ;

//变量赋值部分
variableAssignmentList: variableAssignmentList variableAssignment
                     {
                         /* 构建 VariableAssignmentList 节点，结构：
                            VariableAssignmentList
                            ├─ VariableAssignmentList (子节点，由前一个 variableAssignmentList 产生式返回的 AST 节点)
                            └─ VariableAssignment (子节点，由 variableAssignment 产生式返回的 AST 节点)
                         */
                         $$ = create_node("VariableAssignmentList");
                         add_child($$, $1);  // 前一个变量赋值列表
                         add_child($$, $2);  // 当前变量赋值
                     }
                   | variableAssignment
                     {
                         /* 单个变量赋值时，直接返回该变量赋值的 AST 节点 */
                         $$ = create_node("VariableAssignmentList");
                         add_child($$, $1);
                     }
                   ;


variableAssignment: IDENTIFIER ASSIGN expression SEMICOLON
                   {$$ = create_node("variableAssignment");
                   { ASTNode *node = create_node("Identifier"); set_node_string_value(node, $1); add_child($$, node); }
                   { ASTNode *node = create_node("AssignmentOperator"); set_node_string_value(node, $2); add_child($$, node); }
                   add_child($$, $3);
                   { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $4); add_child($$, node); }}

expression: primary 
            { $$ = create_node("Expression"); add_child($$, $1); }
            
          | timeCondition
            { $$ = create_node("Expression"); add_child($$, $1); }
            
          /* 【关键】这里不要加 | deviceCondition */
          
          | LPAREN expression RPAREN 
            {
                $$ = create_node("Expression"); 
                add_child($$, $2); // 括号内的表达式
            }
            
          /* 逻辑非 */
          | NOT expression
            {
                $$ = create_node("Expression");
                ASTNode *kw = create_node("Keyword"); set_node_string_value(kw, $1); add_child($$, kw);
                add_child($$, $2);
            }
            
          /* 二元运算：直接写 expression 操作符 expression */
          /* 这样 Bison 才能利用 %left 定义的优先级 */
          
          /* 乘除 */
          | expression TIMES expression
            {
                $$ = create_node("Expression");
                add_child($$, $1);
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "*"); add_child($$, op);
                add_child($$, $3);
            }
          | expression DIVIDE expression
            {
                $$ = create_node("Expression");
                add_child($$, $1);
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "/"); add_child($$, op);
                add_child($$, $3);
            }
            
          /* 加减 */
          | expression PLUS expression
            {
                $$ = create_node("Expression");
                add_child($$, $1);
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "+"); add_child($$, op);
                add_child($$, $3);
            }
          | expression MINUS expression
            {
                $$ = create_node("Expression");
                add_child($$, $1);
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "-"); add_child($$, op);
                add_child($$, $3);
            }
            
          /* 比较运算 (解决了你的报错) */
          /* 这样写，IDENTIFIER > IDENTIFIER 也是合法的 */
          | expression GT expression
            {
                $$ = create_node("Expression");
                add_child($$, $1);
                ASTNode *op = create_node("Operator"); set_node_string_value(op, ">"); add_child($$, op);
                add_child($$, $3);
            }
          | expression LT expression
            {
                $$ = create_node("Expression");
                add_child($$, $1);
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "<"); add_child($$, op);
                add_child($$, $3);
            }
          | expression EQ expression
            {
                $$ = create_node("Expression");
                add_child($$, $1);
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "=="); add_child($$, op);
                add_child($$, $3);
            }
          /* 请按此模式补充 NEQ (!=), GE (>=), LE (<=) 等其他比较符 */
          | expression NEQ expression
            {
                $$ = create_node("Expression");
                add_child($$, $1);
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "!="); add_child($$, op);
                add_child($$, $3);
            }

            | expression GE expression
            {
                $$ = create_node("Expression");
                add_child($$, $1);
                ASTNode *op = create_node("Operator"); set_node_string_value(op, ">="); add_child($$, op);
                add_child($$, $3);
            }

            | expression LE expression
            {
                $$ = create_node("Expression");
                add_child($$, $1);
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "<="); add_child($$, op);
                add_child($$, $3);
            }
          /* 逻辑运算 AND/OR */

          | expression AND expression
            {
                $$ = create_node("Expression");
                add_child($$, $1);
                ASTNode *kw = create_node("Keyword"); set_node_string_value(kw, $2); add_child($$, kw);
                add_child($$, $3);
            }
          | expression OR expression
            {
                $$ = create_node("OrOperator"); // 保持你原有的命名习惯
                add_child($$, $1);
                ASTNode *kw = create_node("Keyword"); set_node_string_value(kw, $2); add_child($$, kw);
                add_child($$, $3);
            }
          ;
// 关系操作符：==, !=, <, >, <=, >=




timeCondition:TIME BETWEEN TIMEPOINT  AND  TIMEPOINT
             {$$ = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $2); add_child($$, node); }
             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, $3); add_child($$, node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $4); add_child($$, node); }

             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, $5); add_child($$, node); }
             }
            | TIME  AFTER  TIMEPOINT
             {$$ = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $2); add_child($$, node); }
             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, $3); add_child($$, node); }
             }
            | TIME  BEFORE  TIMEPOINT
             {$$ = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $2); add_child($$, node); }
             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, $3); add_child($$, node); }
             }
            |  DAY  OF  WEEK  IN_TOKEN  dayList
             {$$ = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $2); add_child($$, node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $3); add_child($$, node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $4); add_child($$, node); }
             add_child($$, $5);}
            ;
dayList:LBRACKET days RBRACKET
        {$$ = create_node("DayList");
        { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $1); add_child($$, node); }
        add_child($$, $2);
        { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $3); add_child($$, node); }}

days:days COMMA day
    {$$ = create_node("Days"); 
    add_child($$, $1);
    { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $2); add_child($$, node); }
    add_child($$, $3);}
    | day
    {$$ = create_node("Days"); 
    add_child($$, $1);}
    ;

day:MON 
{$$ = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }}
    | TUE
    {$$ = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }}
    | WED 
    {$$ = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }}
    | THU 
    {$$ = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }}
    | FRI
    {$$ = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }}
    | SAT 
    {$$ = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }}
    | SUN
    {$$ = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }}



primary: IDENTIFIER     { $$ = create_node("Identifier"); set_node_string_value($$, $1); }
       | STRING_LITERAL { $$ = create_node("StringLiteral"); set_node_string_value($$, $1); }
       | INT_NUMBER     { $$ = create_node("IntegerLiteral"); set_node_int_value($$, $1); }
       | FLOAT_NUMBER   { $$ = create_node("FloatLiteral"); set_node_float_value($$, $1); }
       | FALSE0         { $$ = create_node("BooleanLiteral"); set_node_string_value($$, $1); } 
       | TRUE0          { $$ = create_node("BooleanLiteral"); set_node_string_value($$, $1); }
       | ON0            { $$ = create_node("BooleanLiteral"); set_node_string_value($$, $1); }
       | OFF            { $$ = create_node("BooleanLiteral"); set_node_string_value($$, $1); }
       | TIMEPOINT      { $$ = create_node("TimePoint"); set_node_string_value($$, $1); }
       ;
//规则部分
ruleList: ruleList rule
             {
                 $$ = create_node("RuleList");
                 add_child($$, $1);
                 add_child($$, $2);
             }
        | rule
             {
                 $$ = create_node("RuleList");
                 add_child($$, $1);
             }
        ;   

rule:RULE IDENTIFIER LBRACE stateList RBRACE 
             {
                 $$ = create_node("Rule");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
                 { ASTNode *node = create_node("Identifier"); set_node_string_value(node, $2); add_child($$, node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $3); add_child($$, node); }
                 add_child($$, $4);
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $5); add_child($$, node); }
             }

stateList: stateList state
             {
                 $$ = create_node("StateList");
                 add_child($$, $1);
                 add_child($$, $2);
             }
        | state
             {
                 $$ = create_node("StateList");
                 add_child($$, $1);
             }
        ;   
//命令陈述
state:action {$$ = create_node("State"); add_child($$, $1);}
     | ifStatement {$$ = create_node("State"); add_child($$, $1);}
     | whileStatement {$$ = create_node("State"); add_child($$, $1);}
     | forStatement {$$ = create_node("State"); add_child($$, $1);}
     ;

action:SET IDENTIFIER TO status SEMICOLON
             {
                 $$ = create_node("Action");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
                 { ASTNode *node = create_node("Identifier"); set_node_string_value(node, $2); add_child($$, node); }
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $3); add_child($$, node); }
                 add_child($$, $4);
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $5); add_child($$, node); }
             }

status: number 
        {$$ = create_node("Status"); add_child($$, $1);}
        | switch
        {$$ = create_node("Status"); add_child($$, $1);}
        ;

number: INT_NUMBER {$$ = create_node("IntegerLiteral"); set_node_int_value($$, $1);}
        | FLOAT_NUMBER {$$ = create_node("FloatLiteral"); set_node_float_value($$, $1);}
//源语言所有的花括号后面都没有分号

switch: ON0 {$$ = create_node("Switch"); set_node_string_value($$, $1);}
        | OFF {$$ = create_node("Switch"); set_node_string_value($$, $1);}
        ;



ifStatement: IF LPAREN condition RPAREN LBRACE stateList RBRACE //elseStatement
             {
                 $$ = create_node("IfStatement");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $2); add_child($$, node); }
                 add_child($$, $3);
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $4); add_child($$, node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $5); add_child($$, node); }
                 add_child($$, $6);
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $7); add_child($$, node); }
                 //add_child($$, $8);
             }
/*
elseStatement: ELSE LBRACE stateList RBRACE 
             {
                 $$ = create_node("ElseStatement");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $2); add_child($$, node); }
                 add_child($$, $3);
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $4); add_child($$, node); }
             }
             |
             ;
*/
whileStatement: WHILE LPAREN condition RPAREN DO LBRACE stateList RBRACE
             {
                 $$ = create_node("WhileStatement");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $2); add_child($$, node); }
                 add_child($$, $3);
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $4); add_child($$, node); }
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $5); add_child($$, node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $6); add_child($$, node); }
                 add_child($$, $7);
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $8); add_child($$, node); }
             }

forStatement: FOR LPAREN IDENTIFIER IN_TOKEN range RPAREN LBRACE stateList RBRACE
             {
                 $$ = create_node("ForStatement");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $1); add_child($$, node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $2); add_child($$, node); }
                 { ASTNode *node = create_node("Identifier"); set_node_string_value(node, $3); add_child($$, node); }
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, $4); add_child($$, node); }
                 add_child($$, $5);
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $6); add_child($$, node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $7); add_child($$, node); }
                 add_child($$, $8);
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $9); add_child($$, node); }
             }

range:LBRACKET INT_NUMBER COMMA INT_NUMBER RBRACKET 
            {
                 $$ = create_node("Range");
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $1); add_child($$, node); }
                { ASTNode *node = create_node("INT_NUMBER"); set_node_int_value(node, $2); add_child($$, node); }
             
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $3); add_child($$, node); }
                 { ASTNode *node = create_node("INT_NUMBER"); set_node_int_value(node, $4); add_child($$, node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $5); add_child($$, node); }
            }
        | LBRACKET TIMEPOINT COMMA TIMEPOINT RBRACKET 
        {
                 $$ = create_node("Range");
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $1); add_child($$, node); }
                 { ASTNode *node = create_node("TIMEPOINT"); set_node_string_value(node, $2); add_child($$, node); }
             
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $3); add_child($$, node); }
                 { ASTNode *node = create_node("TIMEPOINT"); set_node_string_value(node, $4); add_child($$, node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, $5); add_child($$, node); }
        }
        ;

condition:expression{$$ = create_node("Condition"); add_child($$, $1);}


%%

int main(int argc, char **argv) {
    /* 在 Windows 下设置控制台为 UTF-8，add_child($$, $5);便于显示中文 */
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif
    /* 优先使用命令行指定的输入文件；否则使用仓库根下的 D:\\input.txt 作为默认输入 */
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "无法打开文件: %s\n", argv[1]);
            return 1;
        }
    } else {
        const char *default_path = "D:\\input.txt";
        yyin = fopen(default_path, "r");
        if (!yyin) {
            fprintf(stderr, "无法打开默认输入文件: %s\n", default_path);
            return 1;
        }
    }
    
    printf("开始语法分析...\n");
    if (yyparse() == 0) {
        printf("\n=== 抽象语法树 (AST) ===\n");
        if (ast_root) {
            print_ast_tree(ast_root);
        } else {
            printf("AST 为空\n");
        }
        printf("=== 分析完成 ===\n");
    }
    
    if (yyin != stdin) fclose(yyin);
    return 0;
}