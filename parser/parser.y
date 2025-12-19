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
%token <str_val> DEVICE AS VAR WHEN THEN SET TO BETWEEN AND OR TIME TEMPERATURE DURATION BOOL0 RULE
%token IF ELSE WHILE DO FOR AFTER BEFORE DAY OF WEEK IN_TOKEN
%token <str_val> LIGHT AIR_CONDITIONER WATER_HEATER TELEVISION WASHER FRIDGE ELECTRIC_FAN
%token <str_val> FALSE0 TRUE0 ON OFF
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
program: deviceDeclarationList { ast_root = $1; }

deviceDeclarationList: deviceDeclarationList deviceDeclaration
                     {
                         /* 构建 DeviceDeclarationList 节点，结构：
                            DeviceDeclarationList
                            ├─ DeviceDeclarationList (子节点，由前一个 deviceDeclarationList 产生式返回的 AST 节点)
                            └─ DeviceDeclaration (子节点，由 deviceDeclaration 产生式返回的 AST 节点)
                         */
                         $$ = create_node("DeviceDeclarationList", NULL);
                         add_child($$, $1);  // 前一个设备声明列表
                         add_child($$, $2);  // 当前设备声明
                     }
                   | deviceDeclaration
                     {
                         /* 单个设备声明时，直接返回该设备声明的 AST 节点 */
                         $$ = create_node("DeviceDeclarationList", NULL);
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
                     $$ = create_node("DeviceDeclaration", NULL);
                     /* 把终结符 DEVICE 也作为叶子节点加入 */
                     add_child($$, create_node("DEVICE", $1));
                     /* deviceType 已经返回 AST 节点 */
                     add_child($$, $2);
                     /* 标识符、AS、字符串作为叶子节点 */
                     add_child($$, create_node("Identifier", $3));
                     add_child($$, create_node("AS", $4));
                     add_child($$, create_node("StringLiteral", $5));
                     //print_ast_tree($$);  // 打印当前设备声明的 AST
                 }

deviceType: LIGHT           { $$ = create_node("DeviceType", $1); }
          | AIR_CONDITIONER  { $$ = create_node("DeviceType", $1); }
          | WATER_HEATER     { $$ = create_node("DeviceType", $1); }
          | TELEVISION       { $$ = create_node("DeviceType", $1); }
          | WASHER           { $$ = create_node("DeviceType", $1); }
          | FRIDGE           { $$ = create_node("DeviceType", $1); }
          | ELECTRIC_FAN     { $$ = create_node("DeviceType", $1); }
          ;



%%

int main(int argc, char **argv) {
    /* 在 Windows 下设置控制台为 UTF-8，便于显示中文 */
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