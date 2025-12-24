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
    NOT = 268,                     /* NOT  */
    TIME = 269,                    /* TIME  */
    TEMPERATURE = 270,             /* TEMPERATURE  */
    DURATION = 271,                /* DURATION  */
    BOOL0 = 272,                   /* BOOL0  */
    FLOAT0 = 273,                  /* FLOAT0  */
    INT0 = 274,                    /* INT0  */
    RULE = 275,                    /* RULE  */
    IF = 276,                      /* IF  */
    ELSE = 277,                    /* ELSE  */
    WHILE = 278,                   /* WHILE  */
    DO = 279,                      /* DO  */
    FOR = 280,                     /* FOR  */
    AFTER = 281,                   /* AFTER  */
    BEFORE = 282,                  /* BEFORE  */
    DAY = 283,                     /* DAY  */
    OF = 284,                      /* OF  */
    WEEK = 285,                    /* WEEK  */
    IN_TOKEN = 286,                /* IN_TOKEN  */
    LIGHT = 287,                   /* LIGHT  */
    AIR_CONDITIONER = 288,         /* AIR_CONDITIONER  */
    WATER_HEATER = 289,            /* WATER_HEATER  */
    TELEVISION = 290,              /* TELEVISION  */
    WASHER = 291,                  /* WASHER  */
    FRIDGE = 292,                  /* FRIDGE  */
    ELECTRIC_FAN = 293,            /* ELECTRIC_FAN  */
    FALSE0 = 294,                  /* FALSE0  */
    TRUE0 = 295,                   /* TRUE0  */
    ON0 = 296,                     /* ON0  */
    OFF = 297,                     /* OFF  */
    MON = 298,                     /* MON  */
    TUE = 299,                     /* TUE  */
    WED = 300,                     /* WED  */
    THU = 301,                     /* THU  */
    FRI = 302,                     /* FRI  */
    SAT = 303,                     /* SAT  */
    SUN = 304,                     /* SUN  */
    IDENTIFIER = 305,              /* IDENTIFIER  */
    STRING_LITERAL = 306,          /* STRING_LITERAL  */
    TIMEPOINT = 307,               /* TIMEPOINT  */
    INT_NUMBER = 308,              /* INT_NUMBER  */
    FLOAT_NUMBER = 309,            /* FLOAT_NUMBER  */
    EQ = 310,                      /* EQ  */
    NEQ = 311,                     /* NEQ  */
    LT = 312,                      /* LT  */
    GT = 313,                      /* GT  */
    LE = 314,                      /* LE  */
    GE = 315,                      /* GE  */
    PLUS = 316,                    /* PLUS  */
    MINUS = 317,                   /* MINUS  */
    TIMES = 318,                   /* TIMES  */
    DIVIDE = 319,                  /* DIVIDE  */
    ASSIGN = 320,                  /* ASSIGN  */
    LPAREN = 321,                  /* LPAREN  */
    RPAREN = 322,                  /* RPAREN  */
    LBRACE = 323,                  /* LBRACE  */
    RBRACE = 324,                  /* RBRACE  */
    LBRACKET = 325,                /* LBRACKET  */
    RBRACKET = 326,                /* RBRACKET  */
    SEMICOLON = 327,               /* SEMICOLON  */
    COMMA = 328,                   /* COMMA  */
    COLON = 329,                   /* COLON  */
    DOT = 330,                     /* DOT  */
    UNARY_MINUS = 331              /* UNARY_MINUS  */
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
