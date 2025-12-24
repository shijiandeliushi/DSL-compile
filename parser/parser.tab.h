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
#line 34 "parser/parser.y"

#include "ast.h"

#line 53 "parser/parser.tab.h"

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
    SET = 261,                     /* SET  */
    TO = 262,                      /* TO  */
    BETWEEN = 263,                 /* BETWEEN  */
    AND = 264,                     /* AND  */
    OR = 265,                      /* OR  */
    NOT = 266,                     /* NOT  */
    TIME = 267,                    /* TIME  */
    TEMPERATURE = 268,             /* TEMPERATURE  */
    TIMEPOINT = 269,               /* TIMEPOINT  */
    BOOL0 = 270,                   /* BOOL0  */
    FLOAT0 = 271,                  /* FLOAT0  */
    INT0 = 272,                    /* INT0  */
    RULE = 273,                    /* RULE  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    WHILE = 276,                   /* WHILE  */
    DO = 277,                      /* DO  */
    FOR = 278,                     /* FOR  */
    AFTER = 279,                   /* AFTER  */
    BEFORE = 280,                  /* BEFORE  */
    DAY = 281,                     /* DAY  */
    OF = 282,                      /* OF  */
    WEEK = 283,                    /* WEEK  */
    IN_TOKEN = 284,                /* IN_TOKEN  */
    LIGHT = 285,                   /* LIGHT  */
    AIR_CONDITIONER = 286,         /* AIR_CONDITIONER  */
    WATER_HEATER = 287,            /* WATER_HEATER  */
    TELEVISION = 288,              /* TELEVISION  */
    WASHER = 289,                  /* WASHER  */
    FRIDGE = 290,                  /* FRIDGE  */
    ELECTRIC_FAN = 291,            /* ELECTRIC_FAN  */
    FALSE0 = 292,                  /* FALSE0  */
    TRUE0 = 293,                   /* TRUE0  */
    ON0 = 294,                     /* ON0  */
    OFF = 295,                     /* OFF  */
    MON = 296,                     /* MON  */
    TUE = 297,                     /* TUE  */
    WED = 298,                     /* WED  */
    THU = 299,                     /* THU  */
    FRI = 300,                     /* FRI  */
    SAT = 301,                     /* SAT  */
    SUN = 302,                     /* SUN  */
    IDENTIFIER = 303,              /* IDENTIFIER  */
    STRING_LITERAL = 304,          /* STRING_LITERAL  */
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
    UNARY_MINUS = 328              /* UNARY_MINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "parser/parser.y"

    int int_val;
    double float_val;
    char *str_val;
    ASTNode *ast_node;

#line 150 "parser/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_PARSER_TAB_H_INCLUDED  */
