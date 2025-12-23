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

#line 99 "parser\\parser.tab.c"

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
  YYSYMBOL_WHEN = 6,                       /* WHEN  */
  YYSYMBOL_THEN = 7,                       /* THEN  */
  YYSYMBOL_SET = 8,                        /* SET  */
  YYSYMBOL_TO = 9,                         /* TO  */
  YYSYMBOL_BETWEEN = 10,                   /* BETWEEN  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_NOT = 13,                       /* NOT  */
  YYSYMBOL_TIME = 14,                      /* TIME  */
  YYSYMBOL_TEMPERATURE = 15,               /* TEMPERATURE  */
  YYSYMBOL_DURATION = 16,                  /* DURATION  */
  YYSYMBOL_BOOL0 = 17,                     /* BOOL0  */
  YYSYMBOL_FLOAT0 = 18,                    /* FLOAT0  */
  YYSYMBOL_INT0 = 19,                      /* INT0  */
  YYSYMBOL_RULE = 20,                      /* RULE  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_DO = 24,                        /* DO  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_AFTER = 26,                     /* AFTER  */
  YYSYMBOL_BEFORE = 27,                    /* BEFORE  */
  YYSYMBOL_DAY = 28,                       /* DAY  */
  YYSYMBOL_OF = 29,                        /* OF  */
  YYSYMBOL_WEEK = 30,                      /* WEEK  */
  YYSYMBOL_IN_TOKEN = 31,                  /* IN_TOKEN  */
  YYSYMBOL_LIGHT = 32,                     /* LIGHT  */
  YYSYMBOL_AIR_CONDITIONER = 33,           /* AIR_CONDITIONER  */
  YYSYMBOL_WATER_HEATER = 34,              /* WATER_HEATER  */
  YYSYMBOL_TELEVISION = 35,                /* TELEVISION  */
  YYSYMBOL_WASHER = 36,                    /* WASHER  */
  YYSYMBOL_FRIDGE = 37,                    /* FRIDGE  */
  YYSYMBOL_ELECTRIC_FAN = 38,              /* ELECTRIC_FAN  */
  YYSYMBOL_FALSE0 = 39,                    /* FALSE0  */
  YYSYMBOL_TRUE0 = 40,                     /* TRUE0  */
  YYSYMBOL_ON = 41,                        /* ON  */
  YYSYMBOL_OFF = 42,                       /* OFF  */
  YYSYMBOL_MON = 43,                       /* MON  */
  YYSYMBOL_TUE = 44,                       /* TUE  */
  YYSYMBOL_WED = 45,                       /* WED  */
  YYSYMBOL_THU = 46,                       /* THU  */
  YYSYMBOL_FRI = 47,                       /* FRI  */
  YYSYMBOL_SAT = 48,                       /* SAT  */
  YYSYMBOL_SUN = 49,                       /* SUN  */
  YYSYMBOL_IDENTIFIER = 50,                /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 51,            /* STRING_LITERAL  */
  YYSYMBOL_TIMEPOINT = 52,                 /* TIMEPOINT  */
  YYSYMBOL_INT_NUMBER = 53,                /* INT_NUMBER  */
  YYSYMBOL_FLOAT_NUMBER = 54,              /* FLOAT_NUMBER  */
  YYSYMBOL_EQ = 55,                        /* EQ  */
  YYSYMBOL_NEQ = 56,                       /* NEQ  */
  YYSYMBOL_LT = 57,                        /* LT  */
  YYSYMBOL_GT = 58,                        /* GT  */
  YYSYMBOL_LE = 59,                        /* LE  */
  YYSYMBOL_GE = 60,                        /* GE  */
  YYSYMBOL_PLUS = 61,                      /* PLUS  */
  YYSYMBOL_MINUS = 62,                     /* MINUS  */
  YYSYMBOL_TIMES = 63,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 64,                    /* DIVIDE  */
  YYSYMBOL_ASSIGN = 65,                    /* ASSIGN  */
  YYSYMBOL_LPAREN = 66,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 67,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 68,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 69,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 70,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 71,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 72,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 73,                     /* COMMA  */
  YYSYMBOL_COLON = 74,                     /* COLON  */
  YYSYMBOL_DOT = 75,                       /* DOT  */
  YYSYMBOL_UNARY_MINUS = 76,               /* UNARY_MINUS  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_program = 78,                   /* program  */
  YYSYMBOL_deviceDeclarationList = 79,     /* deviceDeclarationList  */
  YYSYMBOL_deviceDeclaration = 80,         /* deviceDeclaration  */
  YYSYMBOL_deviceType = 81,                /* deviceType  */
  YYSYMBOL_variableDeclarationList = 82,   /* variableDeclarationList  */
  YYSYMBOL_variableDeclaration = 83,       /* variableDeclaration  */
  YYSYMBOL_valueType = 84,                 /* valueType  */
  YYSYMBOL_idnetifierList = 85,            /* idnetifierList  */
  YYSYMBOL_variableAssignmentList = 86,    /* variableAssignmentList  */
  YYSYMBOL_variableAssignment = 87,        /* variableAssignment  */
  YYSYMBOL_expression = 88,                /* expression  */
  YYSYMBOL_relational_op = 89,             /* relational_op  */
  YYSYMBOL_additive_op = 90,               /* additive_op  */
  YYSYMBOL_multiplicative_op = 91,         /* multiplicative_op  */
  YYSYMBOL_timeCondition = 92,             /* timeCondition  */
  YYSYMBOL_dayList = 93,                   /* dayList  */
  YYSYMBOL_days = 94,                      /* days  */
  YYSYMBOL_day = 95,                       /* day  */
  YYSYMBOL_deviceCondition = 96,           /* deviceCondition  */
  YYSYMBOL_primary = 97,                   /* primary  */
  YYSYMBOL_ruleList = 98,                  /* ruleList  */
  YYSYMBOL_rule = 99,                      /* rule  */
  YYSYMBOL_stateList = 100,                /* stateList  */
  YYSYMBOL_state = 101,                    /* state  */
  YYSYMBOL_action = 102,                   /* action  */
  YYSYMBOL_ifStatement = 103,              /* ifStatement  */
  YYSYMBOL_elseStatement = 104,            /* elseStatement  */
  YYSYMBOL_whileStatement = 105,           /* whileStatement  */
  YYSYMBOL_forStatement = 106,             /* forStatement  */
  YYSYMBOL_range = 107,                    /* range  */
  YYSYMBOL_condition = 108                 /* condition  */
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
#define YYLAST   227

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   331


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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    92,   103,   110,   132,   133,   134,   135,
     136,   137,   138,   143,   154,   161,   169,   170,   171,   172,
     173,   174,   177,   181,   186,   197,   206,   213,   214,   215,
     216,   221,   225,   230,   236,   242,   248,   256,   256,   256,
     256,   256,   256,   261,   261,   267,   267,   272,   281,   287,
     293,   301,   307,   311,   316,   316,   316,   316,   316,   316,
     316,   320,   326,   327,   328,   329,   330,   331,   332,   335,
     341,   348,   358,   364,   371,   372,   373,   374,   377,   387,
     400,   408,   411,   424,   438,   448,   460
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
  "WHEN", "THEN", "SET", "TO", "BETWEEN", "AND", "OR", "NOT", "TIME",
  "TEMPERATURE", "DURATION", "BOOL0", "FLOAT0", "INT0", "RULE", "IF",
  "ELSE", "WHILE", "DO", "FOR", "AFTER", "BEFORE", "DAY", "OF", "WEEK",
  "IN_TOKEN", "LIGHT", "AIR_CONDITIONER", "WATER_HEATER", "TELEVISION",
  "WASHER", "FRIDGE", "ELECTRIC_FAN", "FALSE0", "TRUE0", "ON", "OFF",
  "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN", "IDENTIFIER",
  "STRING_LITERAL", "TIMEPOINT", "INT_NUMBER", "FLOAT_NUMBER", "EQ", "NEQ",
  "LT", "GT", "LE", "GE", "PLUS", "MINUS", "TIMES", "DIVIDE", "ASSIGN",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "SEMICOLON", "COMMA", "COLON", "DOT", "UNARY_MINUS", "$accept",
  "program", "deviceDeclarationList", "deviceDeclaration", "deviceType",
  "variableDeclarationList", "variableDeclaration", "valueType",
  "idnetifierList", "variableAssignmentList", "variableAssignment",
  "expression", "relational_op", "additive_op", "multiplicative_op",
  "timeCondition", "dayList", "days", "day", "deviceCondition", "primary",
  "ruleList", "rule", "stateList", "state", "action", "ifStatement",
  "elseStatement", "whileStatement", "forStatement", "range", "condition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,   138,    17,     1,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,   -27,  -135,   148,  -135,     0,  -135,    20,  -135,
    -135,  -135,  -135,  -135,  -135,   -25,   -20,  -135,   -17,  -135,
     -13,  -135,   -63,   129,     3,  -135,    34,  -135,  -135,  -135,
      10,   129,    25,    26,  -135,  -135,   149,  -135,  -135,  -135,
    -135,   129,     9,  -135,  -135,  -135,   -12,  -135,  -135,  -135,
      27,    43,    64,    48,  -135,  -135,  -135,  -135,  -135,  -135,
     129,    65,   129,   129,  -135,  -135,  -135,  -135,  -135,   129,
     129,   129,    76,   106,  -135,  -135,    87,    92,  -135,   130,
      51,    92,    92,    92,    69,    74,    79,    80,     5,  -135,
    -135,  -135,  -135,  -135,    78,    61,   132,   129,   129,   108,
    -135,  -135,  -135,   153,  -135,   129,    92,    93,   110,   128,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,    90,  -135,    30,
     116,   154,   133,  -135,  -135,  -135,    76,   142,   -41,   144,
       6,    76,   139,   140,   146,   193,    11,   164,   165,    76,
     151,  -135,  -135,   150,   152,    36,    76,  -135,  -135,  -135,
      75,  -135
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     4,     6,     7,     8,     9,    10,
      11,    12,     0,     1,     0,     3,     0,    14,     0,    16,
      17,    18,    19,    20,    21,     0,     0,    13,     0,    25,
       0,    23,     0,     0,     0,    24,     2,    70,     5,    15,
       0,     0,     0,     0,    66,    67,    62,    63,    68,    64,
      65,     0,     0,    28,    29,    27,     0,    69,    22,    31,
       0,     0,     0,     0,    37,    38,    39,    40,    41,    42,
       0,     0,     0,     0,    43,    44,    45,    46,    26,     0,
       0,     0,     0,     0,    48,    49,     0,    61,    30,    32,
      33,    36,    35,    34,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,     0,     0,     0,     0,     0,     0,
      71,    72,    47,     0,    50,     0,    86,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,     0,    53,     0,
       0,     0,     0,    51,    52,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,    79,    82,     0,     0,     0,     0,    85,    84,    83,
       0,    80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,   214,  -135,  -135,   204,  -135,  -135,  -135,
     194,   -33,   178,  -135,  -135,  -135,  -135,  -135,    98,  -135,
    -135,  -135,   190,  -134,   -97,  -135,  -135,  -135,  -135,  -135,
    -135,   119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    12,    16,    17,    25,    32,    28,
      29,   116,    79,    80,    81,    53,   114,   127,   128,    54,
      55,    36,    37,    98,    99,   100,   101,   151,   102,   103,
     139,   117
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,   111,   140,    34,     1,    14,    14,   146,    59,    39,
      40,   142,   143,    94,    94,   155,     1,    13,    71,    94,
      72,    73,   160,    18,    30,    31,    95,    95,    96,    96,
      97,    97,    95,    26,    96,    60,    97,    87,    38,    89,
      90,    72,    73,   111,    94,    33,    91,    92,    93,   111,
      26,    61,    62,    56,    34,    63,    82,    95,   111,    96,
      58,    97,    72,   111,    64,    65,    66,    67,    68,    69,
      74,    75,    76,    77,   110,   145,    72,    73,    86,    83,
     152,    78,   129,    94,    94,    64,    65,    66,    67,    68,
      69,    74,    75,    76,    77,    84,    95,    95,    96,    96,
      97,    97,   135,    72,    73,   159,    64,    65,    66,    67,
      68,    69,    74,    75,    76,    77,    85,   104,   105,   106,
      64,    65,    66,    67,    68,    69,    74,    75,    76,    77,
     112,   113,    88,   120,   121,   122,   123,   124,   125,   126,
     107,   115,    41,    42,   161,   108,   109,    64,    65,    66,
      67,    68,    69,    74,    75,    76,    77,    43,   119,   132,
     130,   133,    19,    20,    21,    22,    23,    24,    44,    45,
       5,     6,     7,     8,     9,    10,    11,   131,   137,    46,
      47,    48,    49,    50,   136,    64,    65,    66,    67,    68,
      69,    74,    75,    76,    77,    51,   120,   121,   122,   123,
     124,   125,   126,   138,    64,    65,    66,    67,    68,    69,
     141,   144,   147,   148,   149,   150,   153,    15,   154,   156,
      27,   157,    35,   158,    70,   134,    57,   118
};

static const yytype_uint8 yycheck[] =
{
      33,    98,   136,    20,     3,     5,     5,   141,    41,    72,
      73,    52,    53,     8,     8,   149,     3,     0,    51,     8,
      11,    12,   156,    50,     4,    50,    21,    21,    23,    23,
      25,    25,    21,    50,    23,    10,    25,    70,    51,    72,
      73,    11,    12,   140,     8,    65,    79,    80,    81,   146,
      50,    26,    27,    50,    20,    29,    68,    21,   155,    23,
      50,    25,    11,   160,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    69,    69,    11,    12,    30,    52,
      69,    72,   115,     8,     8,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    52,    21,    21,    23,    23,
      25,    25,    72,    11,    12,    69,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    52,    11,    31,    50,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      52,    70,    67,    43,    44,    45,    46,    47,    48,    49,
      66,     9,    13,    14,    69,    66,    66,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    28,    50,    31,
      67,    71,    14,    15,    16,    17,    18,    19,    39,    40,
      32,    33,    34,    35,    36,    37,    38,    67,    24,    50,
      51,    52,    53,    54,    68,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    66,    43,    44,    45,    46,
      47,    48,    49,    70,    55,    56,    57,    58,    59,    60,
      68,    67,    73,    73,    68,    22,    52,     3,    53,    68,
      16,    71,    28,    71,    46,   127,    36,   108
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    78,    79,    80,    32,    33,    34,    35,    36,
      37,    38,    81,     0,     5,    80,    82,    83,    50,    14,
      15,    16,    17,    18,    19,    84,    50,    83,    86,    87,
       4,    50,    85,    65,    20,    87,    98,    99,    51,    72,
      73,    13,    14,    28,    39,    40,    50,    51,    52,    53,
      54,    66,    88,    92,    96,    97,    50,    99,    50,    88,
      10,    26,    27,    29,    55,    56,    57,    58,    59,    60,
      89,    88,    11,    12,    61,    62,    63,    64,    72,    89,
      90,    91,    68,    52,    52,    52,    30,    88,    67,    88,
      88,    88,    88,    88,     8,    21,    23,    25,   100,   101,
     102,   103,   105,   106,    11,    31,    50,    66,    66,    66,
      69,   101,    52,    70,    93,     9,    88,   108,   108,    50,
      43,    44,    45,    46,    47,    48,    49,    94,    95,    88,
      67,    67,    31,    71,    95,    72,    68,    24,    70,   107,
     100,    68,    52,    53,    67,    69,   100,    73,    73,    68,
      22,   104,    69,    52,    53,   100,    68,    71,    71,    69,
     100,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    77,    78,    79,    79,    80,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    83,    84,    84,    84,    84,
      84,    84,    85,    85,    86,    86,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    90,    90,    91,    91,    92,    92,    92,
      92,    93,    94,    94,    95,    95,    95,    95,    95,    95,
      95,    96,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    99,   100,   100,   101,   101,   101,   101,   102,   103,
     104,   104,   105,   106,   107,   107,   108
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     1,     5,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     4,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     1,     4,     1,     1,     1,
       3,     2,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     3,     3,
       5,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     5,     2,     1,     1,     1,     1,     1,     5,     8,
       4,     0,     8,     9,     5,     5,     1
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
#line 83 "parser\\parser.y"
                                                                                      { ast_root = create_node("Program"); 
                                                    add_child(ast_root, (yyvsp[-3].ast_node));
                                                    add_child(ast_root, (yyvsp[-2].ast_node));
                                                    add_child(ast_root, (yyvsp[-1].ast_node));
                                                    add_child(ast_root, (yyvsp[0].ast_node));
                                                  }
#line 1331 "parser\\parser.tab.c"
    break;

  case 3: /* deviceDeclarationList: deviceDeclarationList deviceDeclaration  */
#line 93 "parser\\parser.y"
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
#line 1346 "parser\\parser.tab.c"
    break;

  case 4: /* deviceDeclarationList: deviceDeclaration  */
#line 104 "parser\\parser.y"
                     {
                         /* 单个设备声明时，直接返回该设备声明的 AST 节点 */
                         (yyval.ast_node) = create_node("DeviceDeclarationList");
                         add_child((yyval.ast_node), (yyvsp[0].ast_node));
                     }
#line 1356 "parser\\parser.tab.c"
    break;

  case 5: /* deviceDeclaration: DEVICE deviceType IDENTIFIER AS STRING_LITERAL  */
#line 111 "parser\\parser.y"
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
#line 1381 "parser\\parser.tab.c"
    break;

  case 6: /* deviceType: LIGHT  */
#line 132 "parser\\parser.y"
                            { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1387 "parser\\parser.tab.c"
    break;

  case 7: /* deviceType: AIR_CONDITIONER  */
#line 133 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1393 "parser\\parser.tab.c"
    break;

  case 8: /* deviceType: WATER_HEATER  */
#line 134 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1399 "parser\\parser.tab.c"
    break;

  case 9: /* deviceType: TELEVISION  */
#line 135 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1405 "parser\\parser.tab.c"
    break;

  case 10: /* deviceType: WASHER  */
#line 136 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1411 "parser\\parser.tab.c"
    break;

  case 11: /* deviceType: FRIDGE  */
#line 137 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1417 "parser\\parser.tab.c"
    break;

  case 12: /* deviceType: ELECTRIC_FAN  */
#line 138 "parser\\parser.y"
                             { (yyval.ast_node) = create_node("DeviceType"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val)); }
#line 1423 "parser\\parser.tab.c"
    break;

  case 13: /* variableDeclarationList: variableDeclarationList variableDeclaration  */
#line 144 "parser\\parser.y"
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
#line 1438 "parser\\parser.tab.c"
    break;

  case 14: /* variableDeclarationList: variableDeclaration  */
#line 155 "parser\\parser.y"
                     {
                         /* 单个变量声明时，直接返回该变量声明的 AST 节点 */
                         (yyval.ast_node) = create_node("VariableDeclarationList");
                         add_child((yyval.ast_node), (yyvsp[0].ast_node));
                     }
#line 1448 "parser\\parser.tab.c"
    break;

  case 15: /* variableDeclaration: VAR valueType idnetifierList SEMICOLON  */
#line 162 "parser\\parser.y"
                   {(yyval.ast_node) = create_node("varibleDeclaration");
                   { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                   add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                   add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                   { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1458 "parser\\parser.tab.c"
    break;

  case 16: /* valueType: TIME  */
#line 169 "parser\\parser.y"
                  { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1464 "parser\\parser.tab.c"
    break;

  case 17: /* valueType: TEMPERATURE  */
#line 170 "parser\\parser.y"
                       { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1470 "parser\\parser.tab.c"
    break;

  case 18: /* valueType: DURATION  */
#line 171 "parser\\parser.y"
                      { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1476 "parser\\parser.tab.c"
    break;

  case 19: /* valueType: BOOL0  */
#line 172 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1482 "parser\\parser.tab.c"
    break;

  case 20: /* valueType: FLOAT0  */
#line 173 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1488 "parser\\parser.tab.c"
    break;

  case 21: /* valueType: INT0  */
#line 174 "parser\\parser.y"
                        { (yyval.ast_node) = create_node("ValueType"); ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
#line 1494 "parser\\parser.tab.c"
    break;

  case 22: /* idnetifierList: idnetifierList COMMA IDENTIFIER  */
#line 177 "parser\\parser.y"
                                               {(yyval.ast_node) = create_node("IdentifierList");
                                                add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                                                { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
                                                { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1503 "parser\\parser.tab.c"
    break;

  case 23: /* idnetifierList: IDENTIFIER  */
#line 181 "parser\\parser.y"
                              {(yyval.ast_node) = create_node("IdentifierList");
                                { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1510 "parser\\parser.tab.c"
    break;

  case 24: /* variableAssignmentList: variableAssignmentList variableAssignment  */
#line 187 "parser\\parser.y"
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
#line 1525 "parser\\parser.tab.c"
    break;

  case 25: /* variableAssignmentList: variableAssignment  */
#line 198 "parser\\parser.y"
                     {
                         /* 单个变量赋值时，直接返回该变量赋值的 AST 节点 */
                         (yyval.ast_node) = create_node("VariableAssignmentList");
                         add_child((yyval.ast_node), (yyvsp[0].ast_node));
                     }
#line 1535 "parser\\parser.tab.c"
    break;

  case 26: /* variableAssignment: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 207 "parser\\parser.y"
                   {(yyval.ast_node) = create_node("variableAssignment");
                   { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                   { ASTNode *node = create_node("AssignmentOperator"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                   add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                   { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1545 "parser\\parser.tab.c"
    break;

  case 27: /* expression: primary  */
#line 213 "parser\\parser.y"
                  {(yyval.ast_node) = create_node("Expression"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1551 "parser\\parser.tab.c"
    break;

  case 30: /* expression: LPAREN expression RPAREN  */
#line 217 "parser\\parser.y"
            {(yyval.ast_node) = create_node("Expression"); 
            { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
            add_child((yyval.ast_node), (yyvsp[-1].ast_node));
            { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1560 "parser\\parser.tab.c"
    break;

  case 31: /* expression: NOT expression  */
#line 222 "parser\\parser.y"
            {(yyval.ast_node) = create_node("Expression");
            { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
            add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1568 "parser\\parser.tab.c"
    break;

  case 32: /* expression: expression AND expression  */
#line 226 "parser\\parser.y"
            {(yyval.ast_node) = create_node("Expression");
            { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
            add_child((yyval.ast_node), (yyvsp[-2].ast_node));
            add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1577 "parser\\parser.tab.c"
    break;

  case 33: /* expression: expression OR expression  */
#line 231 "parser\\parser.y"
            {(yyval.ast_node) = create_node("OrOperator");
            { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
            add_child((yyval.ast_node), (yyvsp[-2].ast_node));
            add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1586 "parser\\parser.tab.c"
    break;

  case 34: /* expression: expression multiplicative_op expression  */
#line 237 "parser\\parser.y"
            {(yyval.ast_node) = create_node("Expression");
            add_child((yyval.ast_node), (yyvsp[-1].ast_node));
            add_child((yyval.ast_node), (yyvsp[-2].ast_node));
            add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1595 "parser\\parser.tab.c"
    break;

  case 35: /* expression: expression additive_op expression  */
#line 243 "parser\\parser.y"
            {(yyval.ast_node) = create_node("Expression");
            add_child((yyval.ast_node), (yyvsp[-1].ast_node));
            add_child((yyval.ast_node), (yyvsp[-2].ast_node));
            add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1604 "parser\\parser.tab.c"
    break;

  case 36: /* expression: expression relational_op expression  */
#line 249 "parser\\parser.y"
            {(yyval.ast_node) = create_node("Expression");
            add_child((yyval.ast_node), (yyvsp[-1].ast_node));
            add_child((yyval.ast_node), (yyvsp[-2].ast_node));
            add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1613 "parser\\parser.tab.c"
    break;

  case 42: /* relational_op: GE  */
#line 257 "parser\\parser.y"
         { (yyval.ast_node) = create_node("Operator"); 
         { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); add_child((yyval.ast_node), node);} }
#line 1620 "parser\\parser.tab.c"
    break;

  case 44: /* additive_op: MINUS  */
#line 262 "parser\\parser.y"
         { (yyval.ast_node) = create_node("Operator"); 
         { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); add_child((yyval.ast_node), node);}
          }
#line 1628 "parser\\parser.tab.c"
    break;

  case 46: /* multiplicative_op: DIVIDE  */
#line 268 "parser\\parser.y"
         { (yyval.ast_node) = create_node("Operator"); 
         { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node);add_child((yyval.ast_node), node); } 
          }
#line 1636 "parser\\parser.tab.c"
    break;

  case 47: /* timeCondition: TIME BETWEEN TIMEPOINT AND TIMEPOINT  */
#line 273 "parser\\parser.y"
             {(yyval.ast_node) = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }

             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1649 "parser\\parser.tab.c"
    break;

  case 48: /* timeCondition: TIME AFTER TIMEPOINT  */
#line 282 "parser\\parser.y"
             {(yyval.ast_node) = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1659 "parser\\parser.tab.c"
    break;

  case 49: /* timeCondition: TIME BEFORE TIMEPOINT  */
#line 288 "parser\\parser.y"
             {(yyval.ast_node) = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("TimePoint"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1669 "parser\\parser.tab.c"
    break;

  case 50: /* timeCondition: DAY OF WEEK IN_TOKEN dayList  */
#line 294 "parser\\parser.y"
             {(yyval.ast_node) = create_node("TimeCondition");
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
             { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
             add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1680 "parser\\parser.tab.c"
    break;

  case 51: /* dayList: LBRACKET days RBRACKET  */
#line 302 "parser\\parser.y"
        {(yyval.ast_node) = create_node("DayList");
        { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
        add_child((yyval.ast_node), (yyvsp[-1].ast_node));
        { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1689 "parser\\parser.tab.c"
    break;

  case 52: /* days: days day  */
#line 308 "parser\\parser.y"
    {(yyval.ast_node) = create_node("Days"); 
    add_child((yyval.ast_node), (yyvsp[-1].ast_node));
    add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1697 "parser\\parser.tab.c"
    break;

  case 53: /* days: day  */
#line 312 "parser\\parser.y"
    {(yyval.ast_node) = create_node("Days"); 
    add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1704 "parser\\parser.tab.c"
    break;

  case 60: /* day: SUN  */
#line 317 "parser\\parser.y"
    {(yyval.ast_node) = create_node("Day"); 
    { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }}
#line 1711 "parser\\parser.tab.c"
    break;

  case 61: /* deviceCondition: IDENTIFIER relational_op expression  */
#line 321 "parser\\parser.y"
            {(yyval.ast_node) = create_node("DeviceCondition");
            { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
            add_child((yyval.ast_node), (yyvsp[-1].ast_node));
            add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1720 "parser\\parser.tab.c"
    break;

  case 62: /* primary: IDENTIFIER  */
#line 326 "parser\\parser.y"
                    {(yyval.ast_node) = create_node("Identifier"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val));}
#line 1726 "parser\\parser.tab.c"
    break;

  case 63: /* primary: STRING_LITERAL  */
#line 327 "parser\\parser.y"
                        {(yyval.ast_node) = create_node("StringLiteral"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val));}
#line 1732 "parser\\parser.tab.c"
    break;

  case 64: /* primary: INT_NUMBER  */
#line 328 "parser\\parser.y"
                    {(yyval.ast_node) = create_node("IntegerLiteral"); set_node_int_value((yyval.ast_node), (yyvsp[0].int_val));}
#line 1738 "parser\\parser.tab.c"
    break;

  case 65: /* primary: FLOAT_NUMBER  */
#line 329 "parser\\parser.y"
                      {(yyval.ast_node) = create_node("FloatLiteral"); set_node_float_value((yyval.ast_node), (yyvsp[0].float_val));}
#line 1744 "parser\\parser.tab.c"
    break;

  case 66: /* primary: FALSE0  */
#line 330 "parser\\parser.y"
                {(yyval.ast_node) = create_node("BooleanLiteral"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val));}
#line 1750 "parser\\parser.tab.c"
    break;

  case 67: /* primary: TRUE0  */
#line 331 "parser\\parser.y"
               {(yyval.ast_node) = create_node("BooleanLiteral"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val));}
#line 1756 "parser\\parser.tab.c"
    break;

  case 68: /* primary: TIMEPOINT  */
#line 332 "parser\\parser.y"
                   {(yyval.ast_node) = create_node("TimePoint"); set_node_string_value((yyval.ast_node), (yyvsp[0].str_val));}
#line 1762 "parser\\parser.tab.c"
    break;

  case 69: /* ruleList: ruleList rule  */
#line 336 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("RuleList");
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 add_child((yyval.ast_node), (yyvsp[0].ast_node));
             }
#line 1772 "parser\\parser.tab.c"
    break;

  case 70: /* ruleList: rule  */
#line 342 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("RuleList");
                 add_child((yyval.ast_node), (yyvsp[0].ast_node));
             }
#line 1781 "parser\\parser.tab.c"
    break;

  case 71: /* rule: RULE IDENTIFIER LBRACE stateList RBRACE  */
#line 349 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("Rule");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1794 "parser\\parser.tab.c"
    break;

  case 72: /* stateList: stateList state  */
#line 359 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("StateList");
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 add_child((yyval.ast_node), (yyvsp[0].ast_node));
             }
#line 1804 "parser\\parser.tab.c"
    break;

  case 73: /* stateList: state  */
#line 365 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("StateList");
                 add_child((yyval.ast_node), (yyvsp[0].ast_node));
             }
#line 1813 "parser\\parser.tab.c"
    break;

  case 74: /* state: action  */
#line 371 "parser\\parser.y"
             {(yyval.ast_node) = create_node("State"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1819 "parser\\parser.tab.c"
    break;

  case 75: /* state: ifStatement  */
#line 372 "parser\\parser.y"
                   {(yyval.ast_node) = create_node("State"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1825 "parser\\parser.tab.c"
    break;

  case 76: /* state: whileStatement  */
#line 373 "parser\\parser.y"
                      {(yyval.ast_node) = create_node("State"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1831 "parser\\parser.tab.c"
    break;

  case 77: /* state: forStatement  */
#line 374 "parser\\parser.y"
                    {(yyval.ast_node) = create_node("State"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1837 "parser\\parser.tab.c"
    break;

  case 78: /* action: SET IDENTIFIER TO expression SEMICOLON  */
#line 378 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("Action");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("Identifier"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1850 "parser\\parser.tab.c"
    break;

  case 79: /* ifStatement: IF LPAREN condition RPAREN LBRACE stateList RBRACE elseStatement  */
#line 388 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("IfStatement");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-7].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-6].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-5].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-2].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[0].ast_node));
             }
#line 1866 "parser\\parser.tab.c"
    break;

  case 80: /* elseStatement: ELSE LBRACE stateList RBRACE  */
#line 401 "parser\\parser.y"
             {
                 (yyval.ast_node) = create_node("ElseStatement");
                 { ASTNode *node = create_node("Keyword"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 add_child((yyval.ast_node), (yyvsp[-1].ast_node));
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
             }
#line 1878 "parser\\parser.tab.c"
    break;

  case 82: /* whileStatement: WHILE LPAREN condition RPAREN DO LBRACE stateList RBRACE  */
#line 412 "parser\\parser.y"
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
#line 1894 "parser\\parser.tab.c"
    break;

  case 83: /* forStatement: FOR LPAREN IDENTIFIER IN_TOKEN range RPAREN LBRACE stateList RBRACE  */
#line 425 "parser\\parser.y"
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
#line 1911 "parser\\parser.tab.c"
    break;

  case 84: /* range: LBRACKET INT_NUMBER COMMA INT_NUMBER RBRACKET  */
#line 439 "parser\\parser.y"
            {
                 (yyval.ast_node) = create_node("Range");
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
                { ASTNode *node = create_node("INT_NUMBER"); set_node_int_value(node, (yyvsp[-3].int_val)); add_child((yyval.ast_node), node); }
             
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("INT_NUMBER"); set_node_int_value(node, (yyvsp[-1].int_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
            }
#line 1925 "parser\\parser.tab.c"
    break;

  case 85: /* range: LBRACKET TIMEPOINT COMMA TIMEPOINT RBRACKET  */
#line 449 "parser\\parser.y"
        {
                 (yyval.ast_node) = create_node("Range");
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-4].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("TIMEPOINT"); set_node_string_value(node, (yyvsp[-3].str_val)); add_child((yyval.ast_node), node); }
             
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[-2].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("TIMEPOINT"); set_node_string_value(node, (yyvsp[-1].str_val)); add_child((yyval.ast_node), node); }
                 { ASTNode *node = create_node("fenjiefu"); set_node_string_value(node, (yyvsp[0].str_val)); add_child((yyval.ast_node), node); }
        }
#line 1939 "parser\\parser.tab.c"
    break;

  case 86: /* condition: expression  */
#line 460 "parser\\parser.y"
                    {(yyval.ast_node) = create_node("Condition"); add_child((yyval.ast_node), (yyvsp[0].ast_node));}
#line 1945 "parser\\parser.tab.c"
    break;


#line 1949 "parser\\parser.tab.c"

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

#line 463 "parser\\parser.y"


int main(int argc, char **argv) {
    /* 在 Windows 下设置控制台为 UTF-8，add_child($$, $5);便于显示中文 */
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
