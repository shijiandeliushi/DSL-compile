%{
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "parser.tab.h"  /* Bison 生成的头文件 */

/* 复制字符串函数 */
char* copy_string(const char* src) {
    char* dest = (char*)malloc(strlen(src) + 1);
    if (dest) strcpy(dest, src);
    return dest;
}

/* 行号计数器 */
int line = 1;

%}

/* 正则表达式定义 - 根据HomeLang规范修改 */
DIGIT           [0-9]
DIGIT_NON_ZERO  [1-9]
LETTER          [a-zA-Z]
UNDERSCORE      "_"
DOT             "."

/* 标识符部分（基础标识符） */
IDENTIFIER_PART {LETTER}({LETTER}|{DIGIT}|{UNDERSCORE})*

/* 带点号的标识符 */
DOTTED_IDENTIFIER {IDENTIFIER_PART}({DOT}{IDENTIFIER_PART})*

/* 数字定义 */
INTEGER         {DIGIT_NON_ZERO}{DIGIT}*
FLOAT_NUM       {DIGIT}+\.{DIGIT}+
ZERO_FLOAT      {DIGIT}*\.{DIGIT}+
NUMBER          {INTEGER}|{FLOAT_NUM}|{ZERO_FLOAT}|0

/* 字符串定义 */
STRING          \"([^\"\\]|\\.)*\"

/* 时间点定义 */
TIMEPOINT       ([01]?[0-9]|2[0-3]):[0-5][0-9]

/* 注释 */
COMMENT         \#[^\n]*

/* 空白字符 */
WHITESPACE      [ \t\r]+

%%

    /* ========== 关键字 ========== */
"device"        { printf("line%d: (keyword, %s)\n", line, yytext); }
"as"            { printf("line%d: (keyword, %s)\n", line, yytext); }
"var"           { printf("line%d: (keyword, %s)\n", line, yytext); }
"when"          { printf("line%d: (keyword, %s)\n", line, yytext); }
"then"          { printf("line%d: (keyword, %s)\n", line, yytext); }
"set"           { printf("line%d: (keyword, %s)\n", line, yytext); }
"to"            { printf("line%d: (keyword, %s)\n", line, yytext); }
"between"       { printf("line%d: (keyword, %s)\n", line, yytext); }
"and"           { printf("line%d: (keyword, %s)\n", line, yytext); }
"or"            { printf("line%d: (keyword, %s)\n", line, yytext); }
"time"          { printf("line%d: (keyword, %s)\n", line, yytext); }
"temperature"   { printf("line%d: (keyword, %s)\n", line, yytext); }
"duration"      { printf("line%d: (keyword, %s)\n", line, yytext); }
"bool"          { printf("line%d: (keyword, %s)\n", line, yytext); }
"rule"          { printf("line%d: (keyword, %s)\n", line, yytext); }
"if"            { printf("line%d: (keyword, %s)\n", line, yytext); }
"else"          { printf("line%d: (keyword, %s)\n", line, yytext); }
"while"         { printf("line%d: (keyword, %s)\n", line, yytext); }
"do"            { printf("line%d: (keyword, %s)\n", line, yytext); }
"for"           { printf("line%d: (keyword, %s)\n", line, yytext); }
"after"         { printf("line%d: (keyword, %s)\n", line, yytext); }
"before"        { printf("line%d: (keyword, %s)\n", line, yytext); }
"day"           { printf("line%d: (keyword, %s)\n", line, yytext); }
"of"            { printf("line%d: (keyword, %s)\n", line, yytext); }
"in"            { printf("line%d: (keyword, %s)\n", line, yytext); }

    /* ========== 标识符 ========== */
    /* 支持点号分隔的标识符 */
{DOTTED_IDENTIFIER} { 
    printf("line%d: (identify, %s)\n", line, yytext); 
}

    /* ========== 字面量 ========== */
    /* 字符串字面量 */
{STRING}    { 
    printf("line%d: (string, %s)\n", line, yytext); 
}

    /* 整数数字字面量 */
{INTEGER}    { 
    printf("line%d: (integer, %s)\n", line, yytext); 
}

0           {
    printf("line%d: (integer, %s)\n", line, yytext);
}

    /* 浮点数数字字面量 */
{FLOAT_NUM}     { 
    printf("line%d: (float, %s)\n", line, yytext); 
}

{ZERO_FLOAT}    { 
    printf("line%d: (float, %s)\n", line, yytext); 
}

    /* 布尔值 */
"true"|"false" {
    printf("line%d: (boolean, %s)\n", line, yytext);
}

    /* 时间点 */
{TIMEPOINT} {
    printf("line%d: (timepoint, %s)\n", line, yytext);
}

    /* 状态 */
"on"|"off" {
    printf("line%d: (state, %s)\n", line, yytext);
}

    /* ========== 运算符 ========== */
    /* 比较运算符 */
"=="        { printf("line%d: (operator, %s)\n", line, yytext); }
"!="        { printf("line%d: (operator, %s)\n", line, yytext); }
"<"         { printf("line%d: (operator, %s)\n", line, yytext); }
">"         { printf("line%d: (operator, %s)\n", line, yytext); }
"<="        { printf("line%d: (operator, %s)\n", line, yytext); }
">="        { printf("line%d: (operator, %s)\n", line, yytext); }

    /* 算术运算符 */
"+"         { printf("line%d: (operator, %s)\n", line, yytext); }
"-"         { printf("line%d: (operator, %s)\n", line, yytext); }
"*"         { printf("line%d: (operator, %s)\n", line, yytext); }
"/"         { printf("line%d: (operator, %s)\n", line, yytext); }

    /* 赋值运算符 */
"="         { printf("line%d: (operator, %s)\n", line, yytext); }

    /* ========== 分隔符 ========== */
"("         { printf("line%d: (bracket, %s)\n", line, yytext); }
")"         { printf("line%d: (bracket, %s)\n", line, yytext); }
"{"         { printf("line%d: (bracket, %s)\n", line, yytext); }
"}"         { printf("line%d: (bracket, %s)\n", line, yytext); }
"["         { printf("line%d: (bracket, %s)\n", line, yytext); }
"]"         { printf("line%d: (bracket, %s)\n", line, yytext); }
";"         { printf("line%d: (separator, %s)\n", line, yytext); }
","         { printf("line%d: (separator, %s)\n", line, yytext); }
":"         { printf("line%d: (separator, %s)\n", line, yytext); }
"."         { printf("line%d: (separator, %s)\n", line, yytext); }

    /* ========== 特殊处理 ========== */
    /* 换行符 - 更新行号 */
\n          { 
    line++; 
}

    /* 注释 - 忽略 */
{COMMENT}   { 
    /* 如果需要输出注释，可以取消下面的注释 */
    /* printf("line%d: (comment, %s)\n", line, yytext); */ 
}

    /* 空白字符 - 忽略 */
{WHITESPACE} { /* 忽略空格、制表符、回车 */ }

    /* 其他字符 - 作为错误处理 */
.           { 
    printf("line%d: (error, 非法字符 '%c')\n", line, yytext[0]); 
}

%%

int yywrap() {
    return 1;
}

/* 主函数用于测试 */
int main(){
    SetConsoleOutputCP(65001);
	yyin=fopen("D:/input.txt","r");
	yylex();
	return 0;
}