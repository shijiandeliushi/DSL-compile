/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 31 "parser\\parser.y"

#include "ast.h"

#line 53 "parser\\parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DEVICE = 258,                  /* DEVICE  */
    AS = 259,                      /* AS  */
    VAR = 260,                     /* VAR  */
    WHEN = 261,                    /* WHEN  */
    THEN = 262,                    /* THEN  */
    SET = 263,                     /* SET  */
    TO = 264,                      /* TO  */
    BETWEEN = 265,                 /* BETWEEN  */
    AND = 266,                     /* AND  */
    OR = 267,                      /* OR  */
    TIME = 268,                    /* TIME  */
    TEMPERATURE = 269,             /* TEMPERATURE  */
    DURATION = 270,                /* DURATION  */
    BOOL0 = 271,                   /* BOOL0  */
    RULE = 272,                    /* RULE  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    WHILE = 275,                   /* WHILE  */
    DO = 276,                      /* DO  */
    FOR = 277,                     /* FOR  */
    AFTER = 278,                   /* AFTER  */
    BEFORE = 279,                  /* BEFORE  */
    DAY = 280,                     /* DAY  */
    OF = 281,                      /* OF  */
    WEEK = 282,                    /* WEEK  */
    IN_TOKEN = 283,                /* IN_TOKEN  */
    LIGHT = 284,                   /* LIGHT  */
    AIR_CONDITIONER = 285,         /* AIR_CONDITIONER  */
    WATER_HEATER = 286,            /* WATER_HEATER  */
    TELEVISION = 287,              /* TELEVISION  */
    WASHER = 288,                  /* WASHER  */
    FRIDGE = 289,                  /* FRIDGE  */
    ELECTRIC_FAN = 290,            /* ELECTRIC_FAN  */
    FALSE0 = 291,                  /* FALSE0  */
    TRUE0 = 292,                   /* TRUE0  */
    ON = 293,                      /* ON  */
    OFF = 294,                     /* OFF  */
    MON = 295,                     /* MON  */
    TUE = 296,                     /* TUE  */
    WED = 297,                     /* WED  */
    THU = 298,                     /* THU  */
    FRI = 299,                     /* FRI  */
    SAT = 300,                     /* SAT  */
    SUN = 301,                     /* SUN  */
    IDENTIFIER = 302,              /* IDENTIFIER  */
    STRING_LITERAL = 303,          /* STRING_LITERAL  */
    TIMEPOINT = 304,               /* TIMEPOINT  */
    INT_NUMBER = 305,              /* INT_NUMBER  */
    FLOAT_NUMBER = 306,            /* FLOAT_NUMBER  */
    EQ = 307,                      /* EQ  */
    NEQ = 308,                     /* NEQ  */
    LT = 309,                      /* LT  */
    GT = 310,                      /* GT  */
    LE = 311,                      /* LE  */
    GE = 312,                      /* GE  */
    PLUS = 313,                    /* PLUS  */
    MINUS = 314,                   /* MINUS  */
    TIMES = 315,                   /* TIMES  */
    DIVIDE = 316,                  /* DIVIDE  */
    ASSIGN = 317,                  /* ASSIGN  */
    LPAREN = 318,                  /* LPAREN  */
    RPAREN = 319,                  /* RPAREN  */
    LBRACE = 320,                  /* LBRACE  */
    RBRACE = 321,                  /* RBRACE  */
    LBRACKET = 322,                /* LBRACKET  */
    RBRACKET = 323,                /* RBRACKET  */
    SEMICOLON = 324,               /* SEMICOLON  */
    COMMA = 325,                   /* COMMA  */
    COLON = 326,                   /* COLON  */
    DOT = 327,                     /* DOT  */
    UNARY_MINUS = 328,             /* UNARY_MINUS  */
    NOT = 329                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "parser\\parser.y"

    int int_val;
    double float_val;
    char *str_val;
    ASTNode *ast_node;

#line 151 "parser\\parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_PARSER_TAB_H_INCLUDED  */
