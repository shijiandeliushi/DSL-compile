%{
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include "..\\..\\parser\\parser.tab.h"







/* 复制字符串函数 */
char* copy_string(const char* src) {
    char* dest = (char*)malloc(strlen(src) + 1);
    if (dest) strcpy(dest, src);
    return dest;
}

/* 行号计数器 */
int line = 1;

/* 外部 yylval（由 parser/bison 定义） */
/* 注意：若使用 reentrant 解析器，需调整 yylex 签名并使用传入的 yylval 指针 */
extern YYSTYPE yylval;

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
"device"        { yylval.str_val = copy_string(yytext); return DEVICE; }
"as"            { yylval.str_val = copy_string(yytext); return AS; }
"var"           { yylval.str_val = copy_string(yytext); return VAR; }
"when"          { yylval.str_val = copy_string(yytext); return WHEN; }
"then"          { yylval.str_val = copy_string(yytext); return THEN; }
"set"           { yylval.str_val = copy_string(yytext); return SET; }
"to"            { yylval.str_val = copy_string(yytext); return TO; }
"between"       { yylval.str_val = copy_string(yytext); return BETWEEN; }
"and"           { yylval.str_val = copy_string(yytext); return AND; }
"or"            { yylval.str_val = copy_string(yytext); return OR; }
"time"          { yylval.str_val = copy_string(yytext); return TIME; }
"temperature"   { yylval.str_val = copy_string(yytext); return TEMPERATURE; }
"duration"      { yylval.str_val = copy_string(yytext); return DURATION; }
"bool"          { yylval.str_val = copy_string(yytext); return BOOL0; }
"int"           {yylval.str_val = copy_string(yytext); return INT0;}
"float"         {yylval.str_val = copy_string(yytext); return FLOAT0;}
"rule"          { yylval.str_val = copy_string(yytext); return RULE; }
"if"            { yylval.str_val = copy_string(yytext); return IF; }
"else"          { yylval.str_val = copy_string(yytext); return ELSE; }
"while"         { yylval.str_val = copy_string(yytext); return WHILE; }
"do"            { yylval.str_val = copy_string(yytext); return DO; }
"for"           { yylval.str_val = copy_string(yytext); return FOR; }
"after"         { yylval.str_val = copy_string(yytext); return AFTER; }
"before"        { yylval.str_val = copy_string(yytext); return BEFORE; }
"day"           { yylval.str_val = copy_string(yytext); return DAY; }
"of"            { yylval.str_val = copy_string(yytext); return OF; }
"week"          { yylval.str_val = copy_string(yytext); return WEEK; }
"in"            { yylval.str_val = copy_string(yytext); return IN_TOKEN; }
"LIGHT"            { yylval.str_val = copy_string(yytext); return LIGHT; }
"AIR_CONDITIONER"  { yylval.str_val = copy_string(yytext); return AIR_CONDITIONER; }
"WATER_HEATER"     { yylval.str_val = copy_string(yytext); return WATER_HEATER; }
"TELEVISION"       { yylval.str_val = copy_string(yytext); return TELEVISION; }
"WASHER"           { yylval.str_val = copy_string(yytext); return WASHER; }
"FRIDGE"           { yylval.str_val = copy_string(yytext); return FRIDGE; }
"ELECTRIC_FAN"     { yylval.str_val = copy_string(yytext); return ELECTRIC_FAN; }


"false"           { yylval.str_val = copy_string(yytext); return FALSE0; }
"true"            { yylval.str_val = copy_string(yytext); return TRUE0; }
"on"              { yylval.str_val = copy_string(yytext); return ON; }
"off"             { yylval.str_val = copy_string(yytext); return OFF; }

"mon"            { yylval.str_val = copy_string(yytext); return MON; }
"tue"            { yylval.str_val = copy_string(yytext); return TUE; }
"wed"            { yylval.str_val = copy_string(yytext); return WED; }
"thu"            { yylval.str_val = copy_string(yytext); return THU; }
"fri"            { yylval.str_val = copy_string(yytext); return FRI; }
"sat"            { yylval.str_val = copy_string(yytext); return SAT; }
"sun"            { yylval.str_val = copy_string(yytext); return SUN; }
    /* ========== 标识符 ========== */
    /* 支持点号分隔的标识符 */
{DOTTED_IDENTIFIER} { 
    yylval.str_val = copy_string(yytext);
    return IDENTIFIER;
}

    /* ========== 字面量 ========== */
    /* 字符串字面量 */
{STRING}    { 
    /* 去掉两端引号，简单处理转义可在需要时扩展 */
    int len = strlen(yytext);
    if (len >= 2) {
        char *s = (char*)malloc(len-1);
        strncpy(s, yytext+1, len-2);
        s[len-2] = '\0';
        yylval.str_val = s;
    } else {
        yylval.str_val = copy_string(yytext);
    }
    return STRING_LITERAL;
}

   
    /* 整数数字字面量 */
{INTEGER}    { 
    yylval.int_val = atoi(yytext);
    return INT_NUMBER;
}

0           {
    yylval.int_val = 0;
    return INT_NUMBER;
}

    /* 浮点数数字字面量 */
{FLOAT_NUM}     { 
    yylval.float_val = atof(yytext);
    return FLOAT_NUMBER;
}

{ZERO_FLOAT}    { 
    yylval.float_val = atof(yytext);
    return FLOAT_NUMBER;
}

   
    /* 时间点 */
{TIMEPOINT} {
    yylval.str_val = copy_string(yytext);
    return TIMEPOINT;
}

 


    /* ========== 运算符 ========== */
    /* 比较运算符 */
"=="        { yylval.str_val = copy_string(yytext); return EQ; }
"!="        { yylval.str_val = copy_string(yytext); return NEQ; }
"<"         { yylval.str_val = copy_string(yytext); return LT; }
">"         { yylval.str_val = copy_string(yytext); return GT; }
"<="        { yylval.str_val = copy_string(yytext); return LE; }
">="        { yylval.str_val = copy_string(yytext); return GE; }

    /* 算术运算符 */
"+"         { yylval.str_val = copy_string(yytext); return PLUS; }
"-"         { yylval.str_val = copy_string(yytext); return MINUS; }
"*"         { yylval.str_val = copy_string(yytext); return TIMES; }
"/"         { yylval.str_val = copy_string(yytext); return DIVIDE; }

    /* 赋值运算符 */
"="         { yylval.str_val = copy_string(yytext); return ASSIGN; }

    /* ========== 分隔符 ========== */
"("         { yylval.str_val = copy_string(yytext); return LPAREN; }
")"         { yylval.str_val = copy_string(yytext); return RPAREN; }
"{"         { yylval.str_val = copy_string(yytext); return LBRACE; }
"}"         { yylval.str_val = copy_string(yytext); return RBRACE; }
"["         { yylval.str_val = copy_string(yytext); return LBRACKET; }
"]"         { yylval.str_val = copy_string(yytext); return RBRACKET; }
";"         { yylval.str_val = copy_string(yytext); return SEMICOLON; }
","         { yylval.str_val = copy_string(yytext); return COMMA; }
":"         { yylval.str_val = copy_string(yytext); return COLON; }
"."         { yylval.str_val = copy_string(yytext); return DOT; }

    /* ========== 特殊处理 ========== */
    /* 换行符 - 更新行号 */
\n          { 
    line++; 
}

    /* 注释 - 忽略 */
    {COMMENT}   { /* ignore comment */ }

    /* 空白字符 - 忽略 */
{WHITESPACE} { /* 忽略空格、制表符、回车 */ }

    /* 其他字符 - 作为错误处理 */
    .           { 
        /* 你可以改成返回一个 ERROR token */
        fprintf(stderr, "line%d: 非法字符 '%c'\n", line, yytext[0]); 
    }

%%

int yywrap() {
    return 1;
}

/* 注意：lexer 不应定义 main。由 parser 的 main 控制输入文件和解析流程。
   如果需要单独测试 lexer，请在外部调用生成的 lexer 可执行或创建测试程序。 */