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
    FLOAT0 = 272,                  /* FLOAT0  */
    INT0 = 273,                    /* INT0  */
    RULE = 274,                    /* RULE  */
    IF = 275,                      /* IF  */
    ELSE = 276,                    /* ELSE  */
    WHILE = 277,                   /* WHILE  */
    DO = 278,                      /* DO  */
    FOR = 279,                     /* FOR  */
    AFTER = 280,                   /* AFTER  */
    BEFORE = 281,                  /* BEFORE  */
    DAY = 282,                     /* DAY  */
    OF = 283,                      /* OF  */
    WEEK = 284,                    /* WEEK  */
    IN_TOKEN = 285,                /* IN_TOKEN  */
    LIGHT = 286,                   /* LIGHT  */
    AIR_CONDITIONER = 287,         /* AIR_CONDITIONER  */
    WATER_HEATER = 288,            /* WATER_HEATER  */
    TELEVISION = 289,              /* TELEVISION  */
    WASHER = 290,                  /* WASHER  */
    FRIDGE = 291,                  /* FRIDGE  */
    ELECTRIC_FAN = 292,            /* ELECTRIC_FAN  */
    FALSE0 = 293,                  /* FALSE0  */
    TRUE0 = 294,                   /* TRUE0  */
    ON = 295,                      /* ON  */
    OFF = 296,                     /* OFF  */
    MON = 297,                     /* MON  */
    TUE = 298,                     /* TUE  */
    WED = 299,                     /* WED  */
    THU = 300,                     /* THU  */
    FRI = 301,                     /* FRI  */
    SAT = 302,                     /* SAT  */
    SUN = 303,                     /* SUN  */
    IDENTIFIER = 304,              /* IDENTIFIER  */
    STRING_LITERAL = 305,          /* STRING_LITERAL  */
    TIMEPOINT = 306,               /* TIMEPOINT  */
    INT_NUMBER = 307,              /* INT_NUMBER  */
    FLOAT_NUMBER = 308,            /* FLOAT_NUMBER  */
    EQ = 309,                      /* EQ  */
    NEQ = 310,                     /* NEQ  */
    LT = 311,                      /* LT  */
    GT = 312,                      /* GT  */
    LE = 313,                      /* LE  */
    GE = 314,                      /* GE  */
    PLUS = 315,                    /* PLUS  */
    MINUS = 316,                   /* MINUS  */
    TIMES = 317,                   /* TIMES  */
    DIVIDE = 318,                  /* DIVIDE  */
    ASSIGN = 319,                  /* ASSIGN  */
    LPAREN = 320,                  /* LPAREN  */
    RPAREN = 321,                  /* RPAREN  */
    LBRACE = 322,                  /* LBRACE  */
    RBRACE = 323,                  /* RBRACE  */
    LBRACKET = 324,                /* LBRACKET  */
    RBRACKET = 325,                /* RBRACKET  */
    SEMICOLON = 326,               /* SEMICOLON  */
    COMMA = 327,                   /* COMMA  */
    COLON = 328,                   /* COLON  */
    DOT = 329,                     /* DOT  */
    UNARY_MINUS = 330,             /* UNARY_MINUS  */
    NOT = 331                      /* NOT  */
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

#line 153 "parser\\parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_PARSER_TAB_H_INCLUDED  */
