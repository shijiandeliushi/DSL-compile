%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AST 节点定义
typedef struct ASTNode {
    char *type;            // 节点类型
    char *value;           // 节点值
    struct ASTNode *left;  // 左子节点
    struct ASTNode *right; // 右子节点
} ASTNode;

// 创建 AST 节点
ASTNode* create_node(char *type, char *value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->left = node->right = NULL;
    return node;
}

// 打印 AST
void print_ast(ASTNode *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("%s", node->type);
    if (node->value) printf(": %s", node->value);
    printf("\n");
    print_ast(node->left, depth + 1);
    print_ast(node->right, depth + 1);
}

// 声明词法分析器函数
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

// 错误处理函数
void yyerror(const char *s) {
    fprintf(stderr, "错误 (第 %d 行): %s\n", yylineno, s);
}

// 根节点
ASTNode *ast_root = NULL;
%}

/* 定义语义值类型 */
%union {
    int int_val;
    double float_val;
    char *str_val;
    ASTNode *ast_node;
}

/* 声明终结符并关联类型 */
%token <int_val> INT_NUMBER
%token <float_val> FLOAT_NUMBER
%token <str_val> IDENTIFIER STRING_LITERAL

/* 关键字 - 不需要值 */
%token INT FLOAT VOID IF ELSE WHILE FOR RETURN

/* 运算符和分隔符 - 不需要值 */
%token PLUS MINUS TIMES DIVIDE ASSIGN
%token EQ NEQ LT GT LE GE
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA

/* 声明非终结符的类型 */
%type <ast_node> program declaration_list declaration
%type <ast_node> var_declaration type_specifier
%type <ast_node> statement_list statement compound_statement
%type <ast_node> expression_statement expression
%type <ast_node> additive_expression multiplicative_expression
%type <ast_node> primary_expression selection_statement
%type <ast_node> iteration_statement jump_statement

/* 优先级和结合性定义 */
%left OR
%left AND
%left EQ NEQ
%left LT GT LE GE
%left PLUS MINUS
%left TIMES DIVIDE
%right UNARY_MINUS NOT
%nonassoc LPAREN RPAREN

/* 起始符号 */
%start program

%%
/* 语法规则 */

/* 程序由一系列声明组成 */
program:
    declaration_list {
        ast_root = $1;
        printf("语法分析成功！\n");
        $$ = $1;
    }
    ;

/* 声明列表 */
declaration_list:
    declaration {
        $$ = create_node("DECLARATION_LIST", NULL);
        $$->left = $1;
    }
    | declaration_list declaration {
        // 将新声明添加到列表末尾
        ASTNode *current = $1;
        while (current->right) current = current->right;
        current->right = $2;
        $$ = $1;
    }
    ;

/* 声明可以是变量声明或函数声明（简化版只实现变量） */
declaration:
    var_declaration SEMICOLON {
        $$ = $1;
    }
    ;

/* 变量声明 */
var_declaration:
    type_specifier IDENTIFIER {
        $$ = create_node("VAR_DECL", $2);
        $$->left = $1;  // 类型作为左子节点
    }
    | type_specifier IDENTIFIER ASSIGN expression {
        $$ = create_node("VAR_DECL_WITH_INIT", $2);
        $$->left = $1;      // 类型
        $$->right = $4;     // 初始值
    }
    ;

/* 类型说明符 */
type_specifier:
    INT {
        $$ = create_node("TYPE", "int");
    }
    | FLOAT {
        $$ = create_node("TYPE", "float");
    }
    | VOID {
        $$ = create_node("TYPE", "void");
    }
    ;

/* 语句列表 */
statement_list:
    statement {
        $$ = create_node("STATEMENT_LIST", NULL);
        $$->left = $1;
    }
    | statement_list statement {
        ASTNode *current = $1;
        while (current->right) current = current->right;
        current->right = $2;
        $$ = $1;
    }
    ;

/* 语句 */
statement:
    expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    ;

/* 表达式语句 */
expression_statement:
    expression SEMICOLON {
        $$ = $1;
    }
    | SEMICOLON {  /* 空语句 */
        $$ = create_node("EMPTY_STATEMENT", NULL);
    }
    ;

/* 复合语句 */
compound_statement:
    LBRACE statement_list RBRACE {
        $$ = $2;
        $$->type = "COMPOUND_STATEMENT";
    }
    ;

/* 选择语句 (if-else) */
selection_statement:
    IF LPAREN expression RPAREN statement {
        $$ = create_node("IF_STATEMENT", NULL);
        $$->left = $3;      // 条件
        $$->right = $5;     // then 分支
    }
    | IF LPAREN expression RPAREN statement ELSE statement {
        $$ = create_node("IF_ELSE_STATEMENT", NULL);
        $$->left = $3;      // 条件
        $$->right = create_node("IF_BRANCHES", NULL);
        $$->right->left = $5;    // then 分支
        $$->right->right = $7;   // else 分支
    }
    ;

/* 循环语句 */
iteration_statement:
    WHILE LPAREN expression RPAREN statement {
        $$ = create_node("WHILE_STATEMENT", NULL);
        $$->left = $3;      // 条件
        $$->right = $5;     // 循环体
    }
    ;

/* 跳转语句 */
jump_statement:
    RETURN expression SEMICOLON {
        $$ = create_node("RETURN", NULL);
        $$->left = $2;
    }
    | RETURN SEMICOLON {
        $$ = create_node("RETURN", "void");
    }
    ;

/* 表达式层次结构 */
expression:
    IDENTIFIER ASSIGN expression {
        $$ = create_node("ASSIGN", $1);
        $$->left = $3;
    }
    | additive_expression
    ;

additive_expression:
    multiplicative_expression
    | additive_expression PLUS multiplicative_expression {
        $$ = create_node("BIN_OP", "+");
        $$->left = $1;
        $$->right = $3;
    }
    | additive_expression MINUS multiplicative_expression {
        $$ = create_node("BIN_OP", "-");
        $$->left = $1;
        $$->right = $3;
    }
    ;

multiplicative_expression:
    primary_expression
    | multiplicative_expression TIMES primary_expression {
        $$ = create_node("BIN_OP", "*");
        $$->left = $1;
        $$->right = $3;
    }
    | multiplicative_expression DIVIDE primary_expression {
        $$ = create_node("BIN_OP", "/");
        $$->left = $1;
        $$->right = $3;
    }
    ;

primary_expression:
    INT_NUMBER {
        char buffer[20];
        sprintf(buffer, "%d", $1);
        $$ = create_node("INT_CONST", buffer);
    }
    | FLOAT_NUMBER {
        char buffer[30];
        sprintf(buffer, "%f", $1);
        $$ = create_node("FLOAT_CONST", buffer);
    }
    | IDENTIFIER {
        $$ = create_node("IDENTIFIER", $1);
    }
    | STRING_LITERAL {
        $$ = create_node("STRING_LITERAL", $1);
    }
    | LPAREN expression RPAREN {
        $$ = $2;
    }
    | MINUS primary_expression %prec UNARY_MINUS {
        $$ = create_node("UNARY_OP", "-");
        $$->left = $2;
    }
    ;

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "无法打开文件: %s\n", argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
        printf("请输入代码，以 Ctrl+Z (Windows) 结束:\n");
    }
    
    printf("开始语法分析...\n");
    if (yyparse() == 0) {
        printf("\n=== 抽象语法树 (AST) ===\n");
        if (ast_root) {
            print_ast(ast_root, 0);
        } else {
            printf("AST 为空\n");
        }
        printf("=== 分析完成 ===\n");
    }
    
    if (yyin != stdin) fclose(yyin);
    return 0;
}