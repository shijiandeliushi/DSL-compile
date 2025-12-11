%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"  /* Bison 生成的头文件 */

 /* 复制字符串函数 */
char* copy_string(const char* src) {
    char* dest = (char*)malloc(strlen(src) + 1);
    if (dest) strcpy(dest, src);
    return dest;
}

 /* 行号计数器 */
int yylineno = 1;

 /* 当前列位置（可选） */
int yycolumn = 1;

 /* 更新位置信息 */
#define YY_USER_ACTION \
    yycolumn += yyleng;

%}

 /* 正则表达式定义 */
DIGIT       [0-9]
LETTER      [a-zA-Z_]
ID          {LETTER}({LETTER}|{DIGIT})*
INT_NUM     {DIGIT}+
FLOAT_NUM   {DIGIT}+\.{DIGIT}+([eE][+-]?{DIGIT}+)?
STRING      \"([^\"\\]|\\.)*\"
COMMENT     "//".*
MULTI_COMMENT  "/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+"/"

%%
    /* 规则部分 */

    /* 关键字 */
"int"       { return INT; }
"float"     { return FLOAT; }
"void"      { return VOID; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"return"    { return RETURN; }

    /* 整数常量 */
{INT_NUM}   { 
    yylval.int_val = atoi(yytext); 
    return INT_NUMBER; 
}

    /* 浮点数常量 */
{FLOAT_NUM} { 
    yylval.float_val = atof(yytext); 
    return FLOAT_NUMBER; 
}

    /* 标识符 */
{ID}        { 
    yylval.str_val = copy_string(yytext); 
    return IDENTIFIER; 
}

    /* 字符串字面量 */
{STRING}    { 
    /* 去掉两边的引号，处理转义字符 */
    char *str = copy_string(yytext);
    if (strlen(str) >= 2) {
        str[strlen(str)-1] = '\0';      /* 去掉末尾引号 */
        yylval.str_val = copy_string(str + 1); /* 跳过开头引号 */
        free(str);
    } else {
        yylval.str_val = copy_string("");
    }
    return STRING_LITERAL; 
}

    /* 运算符 */
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return TIMES; }
"/"         { return DIVIDE; }
"="         { return ASSIGN; }
"=="        { return EQ; }
"!="        { return NEQ; }
"<"         { return LT; }
">"         { return GT; }
"<="        { return LE; }
">="        { return GE; }

    /* 分隔符 */
"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
";"         { return SEMICOLON; }
","         { return COMMA; }

    /* 注释 - 忽略 */
{COMMENT}   { /* 忽略单行注释 */ }
{MULTI_COMMENT} { /* 忽略多行注释 */ }

    /* 空白字符 - 忽略 */
[ \t]+      { /* 忽略空格和制表符 */ }

    /* 换行符 - 更新行号 */
\n          { 
    yylineno++; 
    yycolumn = 1; 
}

    /* 其他字符 - 作为错误处理 */
.           { 
    fprintf(stderr, "第 %d 行第 %d 列: 非法字符 '%c' (0x%02X)\n", 
            yylineno, yycolumn, yytext[0], yytext[0]); 
    return yytext[0]; 
}

%%

int yywrap() {
    return 1;
}

 /* 辅助函数：重置词法分析器状态 */
void reset_lexer() {
    yylineno = 1;
    yycolumn = 1;
}