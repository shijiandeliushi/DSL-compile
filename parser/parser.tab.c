/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser\\parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"  // 包含 AST 相关定义

#include <windows.h>
#include "symbol.h"
#include "../semantic/semantic.h"
#include "../codegen/codegen.h"





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

#line 102 "parser\\parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEVICE = 3,                     /* DEVICE  */
  YYSYMBOL_AS = 4,                         /* AS  */
  YYSYMBOL_VAR = 5,                        /* VAR  */
  YYSYMBOL_SET = 6,                        /* SET  */
  YYSYMBOL_TO = 7,                         /* TO  */
  YYSYMBOL_BETWEEN = 8,                    /* BETWEEN  */
  YYSYMBOL_AND = 9,                        /* AND  */
  YYSYMBOL_OR = 10,                        /* OR  */
  YYSYMBOL_NOT = 11,                       /* NOT  */
  YYSYMBOL_TIME = 12,                      /* TIME  */
  YYSYMBOL_TEMPERATURE = 13,               /* TEMPERATURE  */
  YYSYMBOL_TIMEPOINT = 14,                 /* TIMEPOINT  */
  YYSYMBOL_BOOL0 = 15,                     /* BOOL0  */
  YYSYMBOL_FLOAT0 = 16,                    /* FLOAT0  */
  YYSYMBOL_INT0 = 17,                      /* INT0  */
  YYSYMBOL_STATE = 18,                     /* STATE  */
  YYSYMBOL_RULE = 19,                      /* RULE  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_AFTER = 25,                     /* AFTER  */
  YYSYMBOL_BEFORE = 26,                    /* BEFORE  */
  YYSYMBOL_DAY = 27,                       /* DAY  */
  YYSYMBOL_OF = 28,                        /* OF  */
  YYSYMBOL_WEEK = 29,                      /* WEEK  */
  YYSYMBOL_IN_TOKEN = 30,                  /* IN_TOKEN  */
  YYSYMBOL_LIGHT = 31,                     /* LIGHT  */
  YYSYMBOL_AIR_CONDITIONER = 32,           /* AIR_CONDITIONER  */
  YYSYMBOL_WATER_HEATER = 33,              /* WATER_HEATER  */
  YYSYMBOL_TELEVISION = 34,                /* TELEVISION  */
  YYSYMBOL_WASHER = 35,                    /* WASHER  */
  YYSYMBOL_FRIDGE = 36,                    /* FRIDGE  */
  YYSYMBOL_ELECTRIC_FAN = 37,              /* ELECTRIC_FAN  */
  YYSYMBOL_FALSE0 = 38,                    /* FALSE0  */
  YYSYMBOL_TRUE0 = 39,                     /* TRUE0  */
  YYSYMBOL_ON0 = 40,                       /* ON0  */
  YYSYMBOL_OFF = 41,                       /* OFF  */
  YYSYMBOL_MON = 42,                       /* MON  */
  YYSYMBOL_TUE = 43,                       /* TUE  */
  YYSYMBOL_WED = 44,                       /* WED  */
  YYSYMBOL_THU = 45,                       /* THU  */
  YYSYMBOL_FRI = 46,                       /* FRI  */
  YYSYMBOL_SAT = 47,                       /* SAT  */
  YYSYMBOL_SUN = 48,                       /* SUN  */
  YYSYMBOL_IDENTIFIER = 49,                /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 50,            /* STRING_LITERAL  */
  YYSYMBOL_INT_NUMBER = 51,                /* INT_NUMBER  */
  YYSYMBOL_FLOAT_NUMBER = 52,              /* FLOAT_NUMBER  */
  YYSYMBOL_EQ = 53,                        /* EQ  */
  YYSYMBOL_NEQ = 54,                       /* NEQ  */
  YYSYMBOL_LT = 55,                        /* LT  */
  YYSYMBOL_GT = 56,                        /* GT  */
  YYSYMBOL_LE = 57,                        /* LE  */
  YYSYMBOL_GE = 58,                        /* GE  */
  YYSYMBOL_PLUS = 59,                      /* PLUS  */
  YYSYMBOL_MINUS = 60,                     /* MINUS  */
  YYSYMBOL_TIMES = 61,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 62,                    /* DIVIDE  */
  YYSYMBOL_ASSIGN = 63,                    /* ASSIGN  */
  YYSYMBOL_LPAREN = 64,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 65,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 66,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 67,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 68,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 69,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 70,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 71,                     /* COMMA  */
  YYSYMBOL_COLON = 72,                     /* COLON  */
  YYSYMBOL_DOT = 73,                       /* DOT  */
  YYSYMBOL_UNARY_MINUS = 74,               /* UNARY_MINUS  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_program = 76,                   /* program  */
  YYSYMBOL_deviceDeclarationList = 77,     /* deviceDeclarationList  */
  YYSYMBOL_deviceDeclaration = 78,         /* deviceDeclaration  */
  YYSYMBOL_deviceType = 79,                /* deviceType  */
  YYSYMBOL_variableDeclarationList = 80,   /* variableDeclarationList  */
  YYSYMBOL_variableDeclaration = 81,       /* variableDeclaration  */
  YYSYMBOL_valueType = 82,                 /* valueType  */
  YYSYMBOL_idnetifierList = 83,            /* idnetifierList  */
  YYSYMBOL_variableAssignmentList = 84,    /* variableAssignmentList  */
  YYSYMBOL_variableAssignment = 85,        /* variableAssignment  */
  YYSYMBOL_expression = 86,                /* expression  */
  YYSYMBOL_timeCondition = 87,             /* timeCondition  */
  YYSYMBOL_dayList = 88,                   /* dayList  */
  YYSYMBOL_days = 89,                      /* days  */
  YYSYMBOL_day = 90,                       /* day  */
  YYSYMBOL_primary = 91,                   /* primary  */
  YYSYMBOL_ruleList = 92,                  /* ruleList  */
  YYSYMBOL_rule = 93,                      /* rule  */
  YYSYMBOL_stateList = 94,                 /* stateList  */
  YYSYMBOL_state = 95,                     /* state  */
  YYSYMBOL_assignStatement = 96,           /* assignStatement  */
  YYSYMBOL_action = 97,                    /* action  */
  YYSYMBOL_status = 98,                    /* status  */
  YYSYMBOL_number = 99,                    /* number  */
  YYSYMBOL_switch = 100,                   /* switch  */
  YYSYMBOL_ifStatement = 101,              /* ifStatement  */
  YYSYMBOL_whileStatement = 102,           /* whileStatement  */
  YYSYMBOL_forStatement = 103,             /* forStatement  */
  YYSYMBOL_range = 104,                    /* range  */
  YYSYMBOL_condition = 105                 /* condition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   235

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   329


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    95,   106,   113,   135,   136,   137,   138,
     139,   140,   141,   146,   157,   164,   172,   173,   174,   175,
     176,   177,   180,   184,   189,   200,   209,   216,   219,   224,
     231,   242,   249,   258,   265,   275,   282,   289,   297,   305,
     313,   322,   329,   342,   351,   357,   363,   371,   377,   382,
     387,   390,   393,   396,   399,   402,   405,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   422,   428,   435,   445,
     451,   458,   459,   460,   461,   462,   465,   474,   484,   486,
     488,   492,   493,   496,   497,   502,   526,   539,   553,   565
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEVICE", "AS", "VAR",
  "SET", "TO", "BETWEEN", "AND", "OR", "NOT", "TIME", "TEMPERATURE",
  "TIMEPOINT", "BOOL0", "FLOAT0", "INT0", "STATE", "RULE", "IF", "ELSE",
  "WHILE", "DO", "FOR", "AFTER", "BEFORE", "DAY", "OF", "WEEK", "IN_TOKEN",
  "LIGHT", "AIR_CONDITIONER", "WATER_HEATER", "TELEVISION", "WASHER",
  "FRIDGE", "ELECTRIC_FAN", "FALSE0", "TRUE0", "ON0", "OFF", "MON", "TUE",
  "WED", "THU", "FRI", "SAT", "SUN", "IDENTIFIER", "STRING_LITERAL",
  "INT_NUMBER", "FLOAT_NUMBER", "EQ", "NEQ", "LT", "GT", "LE", "GE",
  "PLUS", "MINUS", "TIMES", "DIVIDE", "ASSIGN", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA",
  "COLON", "DOT", "UNARY_MINUS", "$accept", "program",
  "deviceDeclarationList", "deviceDeclaration", "deviceType",
  "variableDeclarationList", "variableDeclaration", "valueType",
  "idnetifierList", "variableAssignmentList", "variableAssignment",
  "expression", "timeCondition", "dayList", "days", "day", "primary",
  "ruleList", "rule", "stateList", "state", "assignStatement", "action",
  "status", "number", "switch", "ifStatement", "whileStatement",
  "forStatement", "range", "condition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   149,     7,    22,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,   -20,  -143,   157,  -143,    -2,  -143,    48,  -143,
    -143,  -143,  -143,  -143,  -143,     8,    -5,  -143,   -17,  -143,
       9,  -143,   -59,   138,    12,  -143,    44,  -143,  -143,  -143,
      15,   138,     5,  -143,    49,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,   138,    13,  -143,  -143,    18,  -143,  -143,
    -143,    65,    67,    93,    92,    78,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,  -143,     4,
     116,  -143,  -143,    97,  -143,    58,   139,   148,   148,   -11,
     -11,   -11,   -11,   -43,   -43,  -143,  -143,    81,    77,    99,
     103,    82,    56,  -143,  -143,  -143,  -143,  -143,  -143,   128,
      76,   159,   138,   138,   115,   138,  -143,  -143,  -143,   169,
    -143,   -35,   100,   126,   153,   189,    36,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,   -15,  -143,  -143,  -143,  -143,  -143,
    -143,    98,  -143,  -143,   154,   198,   155,  -143,  -143,   169,
    -143,     4,   156,   173,   160,  -143,    79,     4,   158,   161,
    -143,    80,   175,     4,  -143,   162,   102,  -143,  -143
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     4,     6,     7,     8,     9,    10,
      11,    12,     0,     1,     0,     3,     0,    14,     0,    17,
      16,    18,    19,    20,    21,     0,     0,    13,     0,    25,
       0,    23,     0,     0,     0,    24,     2,    67,     5,    15,
       0,     0,     0,    65,     0,    61,    62,    63,    64,    57,
      58,    59,    60,     0,     0,    28,    27,     0,    66,    22,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,    44,    45,     0,    29,    41,    42,    37,    38,    36,
      35,    40,    39,    33,    34,    31,    32,     0,     0,     0,
       0,     0,     0,    70,    75,    71,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,    68,    69,    43,     0,
      46,     0,    89,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,     0,    49,    83,    84,    80,    81,
      82,     0,    78,    79,     0,     0,     0,    76,    47,     0,
      77,     0,     0,     0,     0,    48,     0,     0,     0,     0,
      85,     0,     0,     0,    86,     0,     0,    88,    87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,   225,  -143,  -143,   214,  -143,  -143,  -143,
     204,   -33,  -143,  -143,  -143,    84,  -143,  -143,   199,  -142,
    -101,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
     121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    12,    16,    17,    25,    32,    28,
      29,   122,    55,   120,   134,   135,    56,    36,    37,   102,
     103,   104,   105,   141,   142,   143,   106,   107,   108,   154,
     123
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      54,   117,    34,    14,     1,   136,   137,    13,    60,   156,
      97,    39,    40,    61,   138,   161,   139,   140,    76,    77,
      65,   166,    66,    67,    98,     1,    99,    14,   100,    18,
      62,    63,    26,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    66,    67,    26,    74,    75,
      76,    77,    30,   101,   148,   117,   149,    31,    33,    38,
     117,    57,    97,    34,    59,   117,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    98,    64,    99,    80,
     100,    81,   126,    78,    79,    97,    97,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    98,
      98,    99,    99,   100,   100,   101,   147,    82,    97,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    83,    98,   116,    99,   109,   100,   110,   101,   101,
     111,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   112,   118,    84,   119,   115,   160,   164,    66,    41,
      42,   101,    43,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   113,   125,    44,   121,   114,   150,   168,
      19,    20,    21,    22,    23,    24,    45,    46,    47,    48,
       5,     6,     7,     8,     9,    10,    11,    49,    50,    51,
      52,   144,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    53,    70,    71,    72,    73,    74,    75,    76,
      77,   127,   128,   129,   130,   131,   132,   133,   145,   146,
     151,   152,   157,   153,   158,   159,   165,   163,    15,   162,
      27,   167,    35,   155,   124,    58
};

static const yytype_uint8 yycheck[] =
{
      33,   102,    19,     5,     3,    40,    41,     0,    41,   151,
       6,    70,    71,     8,    49,   157,    51,    52,    61,    62,
      53,   163,     9,    10,    20,     3,    22,     5,    24,    49,
      25,    26,    49,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     9,    10,    49,    59,    60,
      61,    62,     4,    49,    69,   156,    71,    49,    63,    50,
     161,    49,     6,    19,    49,   166,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    20,    28,    22,    14,
      24,    14,   115,    70,    66,     6,     6,     9,    10,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    20,
      20,    22,    22,    24,    24,    49,    70,    14,     6,     9,
      10,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    29,    20,    67,    22,     9,    24,    30,    49,    49,
      49,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    64,    14,    65,    68,    63,    67,    67,     9,    11,
      12,    49,    14,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    64,    49,    27,     7,    64,    70,    67,
      13,    14,    15,    16,    17,    18,    38,    39,    40,    41,
      31,    32,    33,    34,    35,    36,    37,    49,    50,    51,
      52,    65,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    64,    55,    56,    57,    58,    59,    60,    61,
      62,    42,    43,    44,    45,    46,    47,    48,    65,    30,
      66,    23,    66,    68,    51,    65,    51,    66,     3,    71,
      16,    69,    28,   149,   113,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    76,    77,    78,    31,    32,    33,    34,    35,
      36,    37,    79,     0,     5,    78,    80,    81,    49,    13,
      14,    15,    16,    17,    18,    82,    49,    81,    84,    85,
       4,    49,    83,    63,    19,    85,    92,    93,    50,    70,
      71,    11,    12,    14,    27,    38,    39,    40,    41,    49,
      50,    51,    52,    64,    86,    87,    91,    49,    93,    49,
      86,     8,    25,    26,    28,    86,     9,    10,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    70,    66,
      14,    14,    14,    29,    65,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,     6,    20,    22,
      24,    49,    94,    95,    96,    97,   101,   102,   103,     9,
      30,    49,    64,    64,    64,    63,    67,    95,    14,    68,
      88,     7,    86,   105,   105,    49,    86,    42,    43,    44,
      45,    46,    47,    48,    89,    90,    40,    41,    49,    51,
      52,    98,    99,   100,    65,    65,    30,    70,    69,    71,
      70,    66,    23,    68,   104,    90,    94,    66,    51,    65,
      67,    94,    71,    66,    67,    51,    94,    69,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    77,    77,    78,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    81,    82,    82,    82,    82,
      82,    82,    83,    83,    84,    84,    85,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    92,    92,    93,    94,
      94,    95,    95,    95,    95,    95,    96,    97,    98,    98,
      98,    99,    99,   100,   100,   101,   102,   103,   104,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     1,     5,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     4,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     1,     4,     1,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     3,     3,     5,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     5,     2,
       1,     1,     1,     1,     1,     1,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     7,     8,     9,     5,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: deviceDeclarationList variableDeclarationList variableAssignmentList ruleList  */
#line 86 "parser\\parser.y"
                                                                                      { ast_root = create_node("Program"); 
                                                    add_child(ast_root, (yyvsp[-3].ast_node));
                                                    add_child(ast_root, (yyvsp[-2].ast_node));
                                                    add_child(ast_root, (yyvsp[-1].ast_node));
                                                    add_child(ast_root, (yyvsp[0].ast_node));
                                                  }
#line 1332 "parser\\parser.tab.c"
    break;

  case 3: /* deviceDeclarationList: deviceDeclarationList deviceDeclaration  */
#line 96 "parser\\parser.y"
                     {
                         /* 构建 DeviceDeclarationList 节点，结构：
                            DeviceDeclarationList
                            ├─ DeviceDeclarationList (子节点，由前一个 deviceDeclarationList 产生式返回的 AST 节点)
                            └─ DeviceDeclaration (子节点，由 deviceDeclaration 产生式返回的 AST 节点)
                         */
                         (yyval.ast_node) = create_node("DeviceDeclarationList");
                         add_child((yyval.ast_node), (yyvsp[-1].ast_node));  // 前一个设备声明列表
                         add_child((yyval.ast_node), (yyvsp[0].ast_node));  // 当前设备声明
                     }
#line 1347 "parser\\parser.tab.c"
    break;

  case 4: /* deviceDeclarationList: deviceDeclaration  */
#line 107 "parser\\parser.y"
                     {
                         /* 单个设备声明时，直接返回该设备声明的 AST 节点 */
                         (yyval.ast_node) = create_node("DeviceDeclarationList");
                         add_child((yyval.ast_node), (yyvsp[0].ast_node));
                     }
#line 1357 "parser\\parser.tab.c"
    break;

  case 5: /* deviceDeclaration: DEVICE deviceType IDENTIFIER AS STRING_LITERAL  */
#line 114 "parser\\parser.y"
                 {
                     /* 构建 DeviceDeclaration 节点，结构：
                        DeviceDeclaration
                        ├─ DEVICE (终结符)
                        ├─ DeviceType (子节点，由 deviceType 产生式返回的 AST 节点)
                        ├─ Identifier (终结符)
                        ├─ AS (终结符)
                        └─ StringLiteral (终结符)
                     */
                     (yyval.ast_node) = create_node("DeviceDeclaration");
                     /* 把终结符 DEVICE 也作为叶子节点加入 */
                     { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
                     /* deviceType 已经返回 AST 节点 */
                     add_child((yyval.ast_node), (yyvsp[-3].ast_node));
                     /* 标识符、AS、字符串作为叶子节点 */
                     { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                     { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
                     { ASTNode *node = create_node("StringLiteral"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
                     //print_ast_tree($$);  // 打印当前设备声明的 AST
                 }
#line 1382 "parser\\parser.tab.c"
    break;

  case 6: /* deviceType: LIGHT  */
#line 135 "parser\\parser.y"
                            { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1388 "parser\\parser.tab.c"
    break;

  case 7: /* deviceType: AIR_CONDITIONER  */
#line 136 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1394 "parser\\parser.tab.c"
    break;

  case 8: /* deviceType: WATER_HEATER  */
#line 137 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1400 "parser\\parser.tab.c"
    break;

  case 9: /* deviceType: TELEVISION  */
#line 138 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1406 "parser\\parser.tab.c"
    break;

  case 10: /* deviceType: WASHER  */
#line 139 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1412 "parser\\parser.tab.c"
    break;

  case 11: /* deviceType: FRIDGE  */
#line 140 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1418 "parser\\parser.tab.c"
    break;

  case 12: /* deviceType: ELECTRIC_FAN  */
#line 141 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1424 "parser\\parser.tab.c"
    break;

  case 13: /* variableDeclarationList: variableDeclarationList variableDeclaration  */
#line 147 "parser\\parser.y"
                     {
                         /* 构建 VariableDeclarationList 节点，结构：
                            VariableDeclarationList
                            ├─ VariableDeclarationList (子节点，由前一个 variableDeclarationList 产生式返回的 AST 节点)
                            └─ VariableDeclaration (子节点，由 variableDeclaration 产生式返回的 AST 节点)
                         */
                         (yyval.ast_node) = create_node("VariableDeclarationList");
                         add_child((yyval.ast_node), (yyvsp[-1].ast_node));  // 前一个变量声明列表
                         add_child((yyval.ast_node), (yyvsp[0].ast_node));  // 当前变量声明
                     }
#line 1439 "parser\\parser.tab.c"
    break;

  case 14: /* variableDeclarationList: variableDeclaration  */
#line 158 "parser\\parser.y"
                     {
                         /* 单个变量声明时，直接返回该变量声明的 AST 节点 */
                         (yyval.ast_node) = create_node("VariableDeclarationList");
                         add_child((yyval.ast_node), (yyvsp[0].ast_node));
                     }
#line 1449 "parser\\parser.tab.c"
    break;

  case 15: /* variableDeclaration: VAR valueType idnetifierList SEMICOLON  */
#line 165 "parser\\parser.y"
                   {(yyval.ast_node) = create_node("varibleDeclaration");
                   { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                   add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                   add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                   { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1459 "parser\\parser.tab.c"
    break;

  case 16: /* valueType: TIMEPOINT  */
#line 172 "parser\\parser.y"
                       { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1465 "parser\\parser.tab.c"
    break;

  case 17: /* valueType: TEMPERATURE  */
#line 173 "parser\\parser.y"
                       { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1471 "parser\\parser.tab.c"
    break;

  case 18: /* valueType: BOOL0  */
#line 174 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1477 "parser\\parser.tab.c"
    break;

  case 19: /* valueType: FLOAT0  */
#line 175 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1483 "parser\\parser.tab.c"
    break;

  case 20: /* valueType: INT0  */
#line 176 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1489 "parser\\parser.tab.c"
    break;

  case 21: /* valueType: STATE  */
#line 177 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1495 "parser\\parser.tab.c"
    break;

  case 22: /* idnetifierList: idnetifierList COMMA IDENTIFIER  */
#line 180 "parser\\parser.y"
                                               {(yyval.ast_node) = create_node("IdentifierList");
                                                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                                                { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
                                                { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1504 "parser\\parser.tab.c"
    break;

  case 23: /* idnetifierList: IDENTIFIER  */
#line 184 "parser\\parser.y"
                              {(yyval.ast_node) = create_node("IdentifierList");
                                { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1511 "parser\\parser.tab.c"
    break;

  case 24: /* variableAssignmentList: variableAssignmentList variableAssignment  */
#line 190 "parser\\parser.y"
                     {
                         /* 构建 VariableAssignmentList 节点，结构：
                            VariableAssignmentList
                            ├─ VariableAssignmentList (子节点，由前一个 variableAssignmentList 产生式返回的 AST 节点)
                            └─ VariableAssignment (子节点，由 variableAssignment 产生式返回的 AST 节点)
                         */
                         (yyval.ast_node) = create_node("VariableAssignmentList");
                         add_child((yyval.ast_node), (yyvsp[-1].ast_node));  // 前一个变量赋值列表
                         add_child((yyval.ast_node), (yyvsp[0].ast_node));  // 当前变量赋值
                     }
#line 1526 "parser\\parser.tab.c"
    break;

  case 25: /* variableAssignmentList: variableAssignment  */
#line 201 "parser\\parser.y"
                     {
                         /* 单个变量赋值时，直接返回该变量赋值的 AST 节点 */
                         (yyval.ast_node) = create_node("VariableAssignmentList");
                         add_child((yyval.ast_node), (yyvsp[0].ast_node));
                     }
#line 1536 "parser\\parser.tab.c"
    break;

  case 26: /* variableAssignment: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 210 "parser\\parser.y"
                   {(yyval.ast_node) = create_node("variableAssignment");
                   { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                   { ASTNode *node = create_node("AssignmentOperator"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                   add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                   { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1546 "parser\\parser.tab.c"
    break;

  case 27: /* expression: primary  */
#line 217 "parser\\parser.y"
            { (yyval.ast_node) = create_node("Expression"); add_child((yyval.ast_node), (yyvsp[0].ast_node)); }
#line 1552 "parser\\parser.tab.c"
    break;

  case 28: /* expression: timeCondition  */
#line 220 "parser\\parser.y"
            { (yyval.ast_node) = create_node("Expression"); add_child((yyval.ast_node), (yyvsp[0].ast_node)); }
#line 1558 "parser\\parser.tab.c"
    break;

  case 29: /* expression: LPAREN expression RPAREN  */
#line 225 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression"); 
                add_child((yyval.ast_node), (yyvsp[-1].ast_node)); // 括号内的表达式
            }
#line 1567 "parser\\parser.tab.c"
    break;

  case 30: /* expression: NOT expression  */
#line 232 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                ASTNode *kw = create_node("Keyword"); set_node_string_value(kw, (yyvsp[-1].str_val)); add_child((yyval.ast_node), kw);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1577 "parser\\parser.tab.c"
    break;

  case 31: /* expression: expression TIMES expression  */
#line 243 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "*"); add_child((yyval.ast_node), op);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1588 "parser\\parser.tab.c"
    break;

  case 32: /* expression: expression DIVIDE expression  */
#line 250 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "/"); add_child((yyval.ast_node), op);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1599 "parser\\parser.tab.c"
    break;

  case 33: /* expression: expression PLUS expression  */
#line 259 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "+"); add_child((yyval.ast_node), op);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1610 "parser\\parser.tab.c"
    break;

  case 34: /* expression: expression MINUS expression  */
#line 266 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "-"); add_child((yyval.ast_node), op);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1621 "parser\\parser.tab.c"
    break;

  case 35: /* expression: expression GT expression  */
#line 276 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *op = create_node("Operator"); set_node_string_value(op, ">"); add_child((yyval.ast_node), op);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1632 "parser\\parser.tab.c"
    break;

  case 36: /* expression: expression LT expression  */
#line 283 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "<"); add_child((yyval.ast_node), op);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1643 "parser\\parser.tab.c"
    break;

  case 37: /* expression: expression EQ expression  */
#line 290 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "=="); add_child((yyval.ast_node), op);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1654 "parser\\parser.tab.c"
    break;

  case 38: /* expression: expression NEQ expression  */
#line 298 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "!="); add_child((yyval.ast_node), op);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1665 "parser\\parser.tab.c"
    break;

  case 39: /* expression: expression GE expression  */
#line 306 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *op = create_node("Operator"); set_node_string_value(op, ">="); add_child((yyval.ast_node), op);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1676 "parser\\parser.tab.c"
    break;

  case 40: /* expression: expression LE expression  */
#line 314 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *op = create_node("Operator"); set_node_string_value(op, "<="); add_child((yyval.ast_node), op);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1687 "parser\\parser.tab.c"
    break;

  case 41: /* expression: expression AND expression  */
#line 323 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("Expression");
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *kw = create_node("Keyword"); set_node_string_value(kw, (yyvsp[-1].str_val)); add_child((yyval.ast_node), kw);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1698 "parser\\parser.tab.c"
    break;

  case 42: /* expression: expression OR expression  */
#line 330 "parser\\parser.y"
            {
                (yyval.ast_node) = create_node("OrOperator"); // 保持你原有的命名习惯
                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                ASTNode *kw = create_node("Keyword"); set_node_string_value(kw, (yyvsp[-1].str_val)); add_child((yyval.ast_node), kw);
                add_child((yyval.ast_node), (yyvsp[0].ast_node));
            }
#line 1709 "parser\\parser.tab.c"
    break;

  case 43: /* timeCondition: TIME BETWEEN TIMEPOINT AND TIMEPOINT  */
#line 343 "parser\\parser.y"
             {(yyval.ast_node) = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }

             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1722 "parser\\parser.tab.c"
    break;

  case 44: /* timeCondition: TIME AFTER TIMEPOINT  */
#line 352 "parser\\parser.y"
             {(yyval.ast_node) = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1732 "parser\\parser.tab.c"
    break;

  case 45: /* timeCondition: TIME BEFORE TIMEPOINT  */
#line 358 "parser\\parser.y"
             {(yyval.ast_node) = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1742 "parser\\parser.tab.c"
    break;

  case 46: /* timeCondition: DAY OF WEEK IN_TOKEN dayList  */
#line 364 "parser\\parser.y"
             {(yyval.ast_node) = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
             add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1753 "parser\\parser.tab.c"
    break;

  case 47: /* dayList: LBRACKET days RBRACKET  */
#line 372 "parser\\parser.y"
        {(yyval.ast_node) = create_node("DayList");
        { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
        add_child((yyval.ast_node), (yyvsp[-1].ast_node));
        { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1762 "parser\\parser.tab.c"
    break;

  case 48: /* days: days COMMA day  */
#line 378 "parser\\parser.y"
    {(yyval.ast_node) = create_node("Days"); 
    add_child((yyval.ast_node), (yyvsp[-2].ast_node));
    { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
    add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1771 "parser\\parser.tab.c"
    break;

  case 49: /* days: day  */
#line 383 "parser\\parser.y"
    {(yyval.ast_node) = create_node("Days"); 
    add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1778 "parser\\parser.tab.c"
    break;

  case 50: /* day: MON  */
#line 388 "parser\\parser.y"
{(yyval.ast_node) = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1785 "parser\\parser.tab.c"
    break;

  case 51: /* day: TUE  */
#line 391 "parser\\parser.y"
    {(yyval.ast_node) = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1792 "parser\\parser.tab.c"
    break;

  case 52: /* day: WED  */
#line 394 "parser\\parser.y"
    {(yyval.ast_node) = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1799 "parser\\parser.tab.c"
    break;

  case 53: /* day: THU  */
#line 397 "parser\\parser.y"
    {(yyval.ast_node) = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1806 "parser\\parser.tab.c"
    break;

  case 54: /* day: FRI  */
#line 400 "parser\\parser.y"
    {(yyval.ast_node) = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1813 "parser\\parser.tab.c"
    break;

  case 55: /* day: SAT  */
#line 403 "parser\\parser.y"
    {(yyval.ast_node) = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1820 "parser\\parser.tab.c"
    break;

  case 56: /* day: SUN  */
#line 406 "parser\\parser.y"
    {(yyval.ast_node) = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1827 "parser\\parser.tab.c"
    break;

  case 57: /* primary: IDENTIFIER  */
#line 411 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("Identifier"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1833 "parser\\parser.tab.c"
    break;

  case 58: /* primary: STRING_LITERAL  */
#line 412 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("StringLiteral"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1839 "parser\\parser.tab.c"
    break;

  case 59: /* primary: INT_NUMBER  */
#line 413 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("IntegerLiteral"); set_node_int_value((yyval.ast_node), (yyvsp[0].int_val)); }
#line 1845 "parser\\parser.tab.c"
    break;

  case 60: /* primary: FLOAT_NUMBER  */
#line 414 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("FloatLiteral"); set_node_float_value((yyval.ast_node), (yyvsp[0].float_val)); }
#line 1851 "parser\\parser.tab.c"
    break;

  case 61: /* primary: FALSE0  */
#line 415 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("BooleanLiteral"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1857 "parser\\parser.tab.c"
    break;

  case 62: /* primary: TRUE0  */
#line 416 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("BooleanLiteral"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1863 "parser\\parser.tab.c"
    break;

  case 63: /* primary: ON0  */
#line 417 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("BooleanLiteral"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1869 "parser\\parser.tab.c"
    break;

  case 64: /* primary: OFF  */
#line 418 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("BooleanLiteral"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1875 "parser\\parser.tab.c"
    break;

  case 65: /* primary: TIMEPOINT  */
#line 419 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("TimePoint"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1881 "parser\\parser.tab.c"
    break;

  case 66: /* ruleList: ruleList rule  */
#line 423 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("RuleList");
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 add_child((yyval.ast_node), (yyvsp[0].ast_node));
             }
#line 1891 "parser\\parser.tab.c"
    break;

  case 67: /* ruleList: rule  */
#line 429 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("RuleList");
                 add_child((yyval.ast_node), (yyvsp[0].ast_node));
             }
#line 1900 "parser\\parser.tab.c"
    break;

  case 68: /* rule: RULE IDENTIFIER LBRACE stateList RBRACE  */
#line 436 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("Rule");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1913 "parser\\parser.tab.c"
    break;

  case 69: /* stateList: stateList state  */
#line 446 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("StateList");
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 add_child((yyval.ast_node), (yyvsp[0].ast_node));
             }
#line 1923 "parser\\parser.tab.c"
    break;

  case 70: /* stateList: state  */
#line 452 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("StateList");
                 add_child((yyval.ast_node), (yyvsp[0].ast_node));
             }
#line 1932 "parser\\parser.tab.c"
    break;

  case 71: /* state: action  */
#line 458 "parser\\parser.y"
             {(yyval.ast_node) = create_node("State"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1938 "parser\\parser.tab.c"
    break;

  case 72: /* state: ifStatement  */
#line 459 "parser\\parser.y"
                   {(yyval.ast_node) = create_node("State"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1944 "parser\\parser.tab.c"
    break;

  case 73: /* state: whileStatement  */
#line 460 "parser\\parser.y"
                      {(yyval.ast_node) = create_node("State"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1950 "parser\\parser.tab.c"
    break;

  case 74: /* state: forStatement  */
#line 461 "parser\\parser.y"
                    {(yyval.ast_node) = create_node("State"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1956 "parser\\parser.tab.c"
    break;

  case 75: /* state: assignStatement  */
#line 462 "parser\\parser.y"
                       {(yyval.ast_node) = create_node("State"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1962 "parser\\parser.tab.c"
    break;

  case 76: /* assignStatement: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 466 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("AssignStatement");
                 { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1974 "parser\\parser.tab.c"
    break;

  case 77: /* action: SET IDENTIFIER TO status SEMICOLON  */
#line 475 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("Action");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1987 "parser\\parser.tab.c"
    break;

  case 78: /* status: number  */
#line 485 "parser\\parser.y"
        {(yyval.ast_node) = create_node("Status"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1993 "parser\\parser.tab.c"
    break;

  case 79: /* status: switch  */
#line 487 "parser\\parser.y"
        {(yyval.ast_node) = create_node("Status"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1999 "parser\\parser.tab.c"
    break;

  case 80: /* status: IDENTIFIER  */
#line 489 "parser\\parser.y"
        {(yyval.ast_node) = create_node("Status"); ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node);}
#line 2005 "parser\\parser.tab.c"
    break;

  case 81: /* number: INT_NUMBER  */
#line 492 "parser\\parser.y"
                   {(yyval.ast_node) = create_node("IntegerLiteral"); set_node_int_value((yyval.ast_node), (yyvsp[0].int_val));}
#line 2011 "parser\\parser.tab.c"
    break;

  case 82: /* number: FLOAT_NUMBER  */
#line 493 "parser\\parser.y"
                       {(yyval.ast_node) = create_node("FloatLiteral"); set_node_float_value((yyval.ast_node), (yyvsp[0].float_val));}
#line 2017 "parser\\parser.tab.c"
    break;

  case 83: /* switch: ON0  */
#line 496 "parser\\parser.y"
            {(yyval.ast_node) = create_node("Switch"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val));}
#line 2023 "parser\\parser.tab.c"
    break;

  case 84: /* switch: OFF  */
#line 497 "parser\\parser.y"
              {(yyval.ast_node) = create_node("Switch"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val));}
#line 2029 "parser\\parser.tab.c"
    break;

  case 85: /* ifStatement: IF LPAREN condition RPAREN LBRACE stateList RBRACE  */
#line 503 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("IfStatement");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-6].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-5].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-4].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
                 //add_child($$, $8);
             }
#line 2045 "parser\\parser.tab.c"
    break;

  case 86: /* whileStatement: WHILE LPAREN condition RPAREN DO LBRACE stateList RBRACE  */
#line 527 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("WhileStatement");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-7].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-6].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-5].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 2061 "parser\\parser.tab.c"
    break;

  case 87: /* forStatement: FOR LPAREN IDENTIFIER IN_TOKEN range RPAREN LBRACE stateList RBRACE  */
#line 540 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("ForStatement");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-8].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-7].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[-6].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-5].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-4].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 2078 "parser\\parser.tab.c"
    break;

  case 88: /* range: LBRACKET INT_NUMBER COMMA INT_NUMBER RBRACKET  */
#line 554 "parser\\parser.y"
            {
                 (yyval.ast_node) = create_node("Range");
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
                { ASTNode *node = create_node("INT_NUMBER"); set_node_int_value(node, (yyvsp[-3].int_val)); add_child((yyval.ast_node), node); }
             
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("INT_NUMBER"); set_node_int_value(node, (yyvsp[-1].int_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
            }
#line 2092 "parser\\parser.tab.c"
    break;

  case 89: /* condition: expression  */
#line 565 "parser\\parser.y"
                    {(yyval.ast_node) = create_node("Condition"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 2098 "parser\\parser.tab.c"
    break;


#line 2102 "parser\\parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 568 "parser\\parser.y"


int main(int argc, char **argv) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = fopen("D:\\input.txt", "r");
    }

    if (!yyin) {
        fprintf(stderr, "无法打开输入文件\n");
        return 1;
    }

    printf("--- 步骤 1: 语法分析与 AST 构建 ---\n");
    if (yyparse() == 0 && ast_root) {
        printf("语法分析成功！\n");
        print_ast_tree(ast_root);

        printf("\n--- 步骤 2: 构建符号表 ---\n");
        init_symbol_table();
        build_symbol_table(ast_root);
        printf("\n=== 符号表内容 ===\n");
        print_symbol_table();

        printf("\n--- 步骤 3: 语义检查 ---\n");
        check_semantics(ast_root);

        printf("\n--- 步骤 4: 目标代码生成 (Python) ---\n");
        printf("========================================\n");
        generate_code(ast_root, 0);
        printf("========================================\n");
        
        printf("\n编译完成。\n");
    } else {
        printf("编译失败。\n");
    }

    if (yyin != stdin) fclose(yyin);
    return 0;
}
