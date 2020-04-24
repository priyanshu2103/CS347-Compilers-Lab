/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "c_comp.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include "c_comp.tab.h"

extern int yylex(void);
extern void yyterminate();
void yyerror(const char *s);


#line 78 "c_comp.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "c_comp.tab.h".  */
#ifndef YY_YY_C_COMP_TAB_H_INCLUDED
# define YY_YY_C_COMP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PLUS = 258,
    MINUS = 259,
    MULT = 260,
    DIV = 261,
    LE = 262,
    GE = 263,
    EQ = 264,
    NEQ = 265,
    LT = 266,
    GT = 267,
    AND = 268,
    OR = 269,
    EXCL = 270,
    COMMA = 271,
    COL = 272,
    SEMI = 273,
    LC = 274,
    RC = 275,
    LP = 276,
    RP = 277,
    VOID = 278,
    INT_DECL = 279,
    FLOAT_DECL = 280,
    ID = 281,
    INT = 282,
    FLOAT = 283,
    IF = 284,
    ELSE = 285,
    SWITCH = 286,
    CASE = 287,
    FOR = 288,
    WHILE = 289,
    BREAK = 290,
    DEFAULT = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_COMP_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 166 "c_comp.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   550

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    51,    52,    52,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    57,    57,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    67,    67,    69,    69,    69,
      69,    70,    70,    70,    70,    70,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    75,    76,    76,    78,    78,
      78,    79,    79,    80,    80,    80,    80,    82,    82,    82,
      82,    82,    82,    83,    83,    84,    84,    86,    86,    88,
      88,    90,    90,    90,    91,    91,    93,    93,    94,    94,
      94,    94,    97,    97,    99,    99,   101,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   102,   102,   103,   105,
     105,   107,   107,   108,   108,   108,   108,   109,   109,   109,
     109,   110,   110,   110,   111,   111,   113,   113,   114,   115,
     115,   115,   115,   116,   116,   117,   117,   117,   119,   119
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "MULT", "DIV", "LE",
  "GE", "EQ", "NEQ", "LT", "GT", "AND", "OR", "EXCL", "COMMA", "COL",
  "SEMI", "LC", "RC", "LP", "RP", "VOID", "INT_DECL", "FLOAT_DECL", "ID",
  "INT", "FLOAT", "IF", "ELSE", "SWITCH", "CASE", "FOR", "WHILE", "BREAK",
  "DEFAULT", "$accept", "stmts", "stmt", "stmt_wo_func", "stmt_with_func",
  "var_decl", "int_id_list", "int_assign", "int_id_assign_list",
  "float_id_list", "float_assign", "float_id_assign_list", "arith",
  "int_arith", "int_arith_arg", "float_arith", "float_arith_arg",
  "func_call", "call_arg_list", "func_decl", "decl_arg_list", "decl_arg",
  "func_def", "def_arg_list", "def_arg", "body", "if_else", "mif", "uif",
  "simple_stmts", "simple_stmt", "cond", "and_expr", "expr", "switch_case",
  "cases", "case", "default", "break", "for_loop", "for_expr", "for_first",
  "for_second", "for_third", "while_loop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -183

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-183)))

#define YYTABLE_NINF -45

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     272,   482,   163,    -8,    13,    21,    57,    56,    62,    72,
      -6,    83,   127,   154,   272,  -183,  -183,  -183,  -183,   122,
     351,   150,   360,   364,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,   151,   155,  -183,  -183,  -183,  -183,   364,
     172,   482,  -183,   181,   182,  -183,   187,    10,  -183,   114,
      27,  -183,   183,   186,   199,   203,     6,   208,   210,   119,
       6,  -183,  -183,  -183,    79,    79,    79,    79,  -183,    47,
      47,    47,    47,   229,   234,  -183,  -183,  -183,  -183,    34,
     223,    93,   151,  -183,   231,    93,   155,  -183,   239,   237,
     140,   140,     6,  -183,   511,  -183,   521,   241,   247,   251,
     248,   252,   263,  -183,  -183,  -183,   254,     6,   258,    79,
      57,   351,  -183,   351,   351,   351,    47,    57,   360,  -183,
     360,   360,   360,   261,   266,   262,   273,   280,   291,   265,
    -183,   282,   285,   290,  -183,   304,  -183,   293,  -183,   186,
    -183,   295,   305,   294,   313,  -183,    79,    79,   308,    79,
      79,    79,    47,    47,   328,    47,    47,    47,   315,     6,
       6,   319,   318,   321,   299,   354,   348,   372,  -183,  -183,
     358,   140,   383,    93,    94,  -183,  -183,   394,    75,   405,
    -183,  -183,  -183,   363,   365,   351,   351,    79,   351,   351,
     351,   360,   360,    47,   360,   360,   360,  -183,   352,  -183,
    -183,   318,    98,   366,    45,   369,   416,  -183,  -183,   375,
    -183,   416,  -183,  -183,  -183,   416,  -183,  -183,   115,    39,
    -183,   184,   193,   416,  -183,   167,   201,  -183,   228,   219,
     416,  -183,  -183,  -183,   351,   360,   315,   367,   145,   368,
     377,  -183,   378,  -183,  -183,   204,   416,   481,   482,   321,
     491,   492,   514,   515,  -183,  -183,  -183,   370,   516,   427,
     438,   449,     8,   238,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,   519,   520,   416,   504,   416,   504,   416,   504,
     460,   471,   522,   523,  -183,   524,  -183,   525,  -183,   416,
     504,   416,   504,   504,  -183,   504,   504,   526,  -183,   527,
    -183,  -183,  -183,  -183,   504,   504,  -183,  -183
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    41,    42,    51,     0,
       0,     0,     0,     0,     2,     4,     5,     6,     7,    43,
       0,    52,     0,     8,    13,    14,     9,    79,    80,    82,
      10,    11,    12,     0,     0,    42,    51,    88,    89,    90,
       0,    86,    91,    43,    52,    44,     0,    19,    15,     0,
      28,    16,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     1,     3,    35,     0,     0,     0,     0,    36,     0,
       0,     0,     0,    19,    28,    83,    87,    45,    54,     0,
       0,     0,     0,    17,     0,     0,     0,    26,    56,     0,
       0,     0,     0,    43,     0,    52,     0,     0,    92,    94,
       0,     0,    19,   130,   131,   132,     0,   133,     0,     0,
      41,    37,    44,    38,    39,    40,     0,    50,    46,    53,
      47,    48,    49,    63,    64,     0,    61,     0,    73,    21,
      20,     0,     0,     0,    18,    30,    29,     0,    27,     0,
      55,    63,    64,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,    65,    66,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
      57,    65,    66,     0,     0,    98,    99,     0,   101,    96,
      97,   104,   105,     0,   107,   102,   103,    84,    79,    93,
      95,     0,     0,     0,   121,    21,     0,   126,   134,     0,
     128,     0,   138,    58,    62,     0,    67,    74,    41,    42,
      25,    43,    44,     0,    69,    50,    51,    34,    52,    53,
       0,    71,    59,    60,   100,   106,     0,     0,     0,     0,
       0,   109,     0,   112,   111,     0,    77,     0,    82,     0,
       0,     0,     0,     0,    81,    85,   110,     0,     0,     0,
       0,     0,    41,    44,    78,   127,   136,   137,   139,    68,
      70,    72,     0,     0,     0,   124,     0,   124,     0,   124,
       0,     0,     0,     0,   113,     0,   117,     0,   122,     0,
     124,     0,   124,   124,   125,   124,   124,     0,   115,     0,
     119,   114,   118,   123,   124,   124,   116,   120
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,   529,  -183,    49,  -183,     3,   -45,  -183,  -151,   -43,
    -183,  -166,     4,    20,   202,   126,   -18,     0,   401,  -183,
     -81,  -183,  -183,   -74,  -183,    99,   390,  -145,   314,   -33,
      -1,   -57,   389,  -183,     5,  -176,  -183,  -183,  -182,  -183,
    -183,  -183,  -183,  -183,  -183
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,   246,    16,    17,    48,    49,   130,    51,
      52,   136,    18,    19,    20,    21,    22,    23,    89,    24,
     125,   126,    25,   127,   128,   247,    26,    27,    28,    40,
      29,    97,    98,    99,    30,   203,   204,   244,   284,    31,
     106,   107,   166,   210,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    39,    45,   108,    37,    38,    42,   133,    76,   143,
     144,   137,   227,   198,   104,    57,   105,   245,    46,    80,
      58,    92,    43,   220,   -21,   237,   -21,     2,   243,    53,
     -21,    81,     6,    35,    36,   145,    84,   134,    96,    47,
      41,    39,    96,   138,    37,    38,    42,    50,    85,    15,
     165,   118,   120,   121,   122,   -22,    45,   -22,   123,   124,
      45,   -22,   103,    15,   112,   112,   112,   112,   116,   119,
     119,   119,   119,   117,    96,    36,    93,   202,    53,   227,
      93,   242,    54,   267,    93,    93,    93,    93,    55,    96,
     214,   254,    45,    56,   220,   286,   116,   288,   266,   217,
     109,   225,   199,   226,    59,   110,    35,    45,   298,   112,
     300,   301,    93,   302,   303,   109,   119,   131,   132,   238,
     218,   219,   306,   307,   174,   239,   240,    93,    44,    43,
      82,   -21,    83,   -21,   191,   192,    53,   194,   195,   196,
      63,    96,    96,    33,    34,   102,   112,   112,    60,   112,
     112,   112,   119,   119,    61,   119,   119,   119,    39,    45,
      45,    37,    38,    42,   141,   142,    93,    93,    68,    93,
      93,    93,   257,   258,   222,   235,   178,    73,   229,    93,
      93,    74,    95,   -30,     2,   -30,    95,   112,    53,     6,
      35,    36,    75,   119,   221,    95,    95,    95,    95,    86,
     -23,    87,   -23,    77,    78,   248,   -23,    93,    79,   -24,
     248,   -24,    88,   207,   248,    76,   212,   -31,    95,   -31,
      90,   216,   248,   -31,    91,     2,   224,   101,   231,   248,
     262,   219,   226,    95,   100,   -33,    39,   -33,    80,    37,
      38,    42,    44,    84,   -32,   263,   -32,    41,    39,   129,
     -32,    37,    38,    42,   -24,   139,   -24,   135,    94,   140,
     -24,   159,    94,   158,   160,   221,   111,   113,   114,   115,
     161,   162,   163,   248,   174,   248,   164,   248,    95,    95,
     167,    95,    95,    95,   170,    95,    95,   168,   248,   171,
     248,     1,   169,     2,    94,     3,     4,     5,     6,     7,
       8,     9,   172,    10,   228,    11,    12,   173,   175,    94,
     250,   176,   177,   178,   251,   179,   183,   187,   206,    95,
       2,   181,   252,    33,    34,     6,    35,    36,     9,   253,
      10,   182,    11,    12,     1,   184,     2,   193,   201,    33,
      34,     6,    35,    36,     9,   264,    10,   205,   185,   186,
     202,   188,   189,   190,    64,    65,    66,    67,   275,   277,
     279,    94,    94,    69,    70,    71,    72,   -44,   -44,   -44,
     -44,   228,   208,   282,   209,   285,   213,   287,   245,   290,
     292,   232,   236,   233,   249,   259,   241,   256,   297,   234,
     299,   211,   272,     2,   260,   261,    33,    34,     6,    35,
      36,     9,   215,    10,     2,    11,    12,    33,    34,     6,
      35,    36,     9,   223,    10,     2,    11,    12,    33,    34,
       6,    35,    36,     9,   230,    10,     2,    11,    12,    33,
      34,     6,    35,    36,     9,     1,    10,     2,    11,    12,
      33,    34,     6,    35,    36,     9,   274,    10,     2,    11,
      12,    33,    34,     6,    35,    36,     9,   276,    10,     2,
      11,    12,    33,    34,     6,    35,    36,     9,   278,    10,
       2,    11,    12,    33,    34,     6,    35,    36,     9,   289,
      10,     2,    11,    12,    33,    34,     6,    35,    36,     9,
     291,    10,     2,    11,    12,    33,    34,     6,    35,    36,
       9,   265,    10,     2,    11,    12,    33,    34,     6,    35,
      36,   268,   269,    10,    64,    65,    66,    67,   146,   147,
     148,   149,   150,   151,    69,    70,    71,    72,   152,   153,
     154,   155,   156,   157,   270,   271,   280,   281,   273,   283,
     180,   294,   293,    62,   295,   296,   304,   305,   197,   200,
     255
};

static const yytype_uint16 yycheck[] =
{
       1,     1,     2,    60,     1,     1,     1,    81,    41,    90,
      91,    85,   178,   158,    59,    21,    59,     9,    26,     9,
      26,    15,     2,   174,    16,   201,    18,    21,   204,    21,
      22,    21,    26,    27,    28,    92,     9,    82,    56,    26,
      41,    41,    60,    86,    41,    41,    41,    26,    21,     0,
     107,    69,    70,    71,    72,    16,    56,    18,    24,    25,
      60,    22,    59,    14,    64,    65,    66,    67,    21,    69,
      70,    71,    72,    26,    92,    28,    56,    32,    21,   245,
      60,    36,    26,   249,    64,    65,    66,    67,    26,   107,
     171,   236,    92,    21,   245,   277,    21,   279,   249,   173,
      21,    26,   159,    28,    21,    26,    27,   107,   290,   109,
     292,   293,    92,   295,   296,    21,   116,    24,    25,    21,
      26,    27,   304,   305,     9,    27,    28,   107,     2,   109,
      16,    16,    18,    18,   152,   153,    21,   155,   156,   157,
      18,   159,   160,    24,    25,    26,   146,   147,    21,   149,
     150,   151,   152,   153,     0,   155,   156,   157,   158,   159,
     160,   158,   158,   158,    24,    25,   146,   147,    18,   149,
     150,   151,    27,    28,   174,   193,     9,    26,   178,   159,
     160,    26,    56,    16,    21,    18,    60,   187,    21,    26,
      27,    28,    20,   193,   174,    69,    70,    71,    72,    16,
      16,    18,    18,    22,    22,   206,    22,   187,    21,    16,
     211,    18,    26,   164,   215,   248,   167,    16,    92,    18,
      21,   172,   223,    22,    21,    21,   177,    17,   179,   230,
      26,    27,    28,   107,    26,    16,   236,    18,     9,   236,
     236,   236,   116,     9,    16,   245,    18,   248,   248,    26,
      22,   248,   248,   248,    16,    16,    18,    26,    56,    22,
      22,    14,    60,    22,    13,   245,    64,    65,    66,    67,
      22,    19,     9,   274,     9,   276,    22,   278,   152,   153,
      22,   155,   156,   157,    22,   159,   160,    26,   289,    16,
     291,    19,    26,    21,    92,    23,    24,    25,    26,    27,
      28,    29,    22,    31,   178,    33,    34,    16,    26,   107,
     211,    26,    22,     9,   215,    22,    22,     9,    19,   193,
      21,    26,   223,    24,    25,    26,    27,    28,    29,   230,
      31,    26,    33,    34,    19,    22,    21,     9,    19,    24,
      25,    26,    27,    28,    29,   246,    31,    26,   146,   147,
      32,   149,   150,   151,     3,     4,     5,     6,   259,   260,
     261,   159,   160,     3,     4,     5,     6,     3,     4,     5,
       6,   245,    18,   274,    26,   276,    18,   278,     9,   280,
     281,    18,    30,    18,     9,    17,    20,    20,   289,   187,
     291,    19,    22,    21,    17,    17,    24,    25,    26,    27,
      28,    29,    19,    31,    21,    33,    34,    24,    25,    26,
      27,    28,    29,    19,    31,    21,    33,    34,    24,    25,
      26,    27,    28,    29,    19,    31,    21,    33,    34,    24,
      25,    26,    27,    28,    29,    19,    31,    21,    33,    34,
      24,    25,    26,    27,    28,    29,    19,    31,    21,    33,
      34,    24,    25,    26,    27,    28,    29,    19,    31,    21,
      33,    34,    24,    25,    26,    27,    28,    29,    19,    31,
      21,    33,    34,    24,    25,    26,    27,    28,    29,    19,
      31,    21,    33,    34,    24,    25,    26,    27,    28,    29,
      19,    31,    21,    33,    34,    24,    25,    26,    27,    28,
      29,    20,    31,    21,    33,    34,    24,    25,    26,    27,
      28,    20,    20,    31,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    20,    20,    17,    17,    22,    35,
     139,    18,    20,    14,    20,    20,    20,    20,   158,   160,
     236
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    21,    23,    24,    25,    26,    27,    28,    29,
      31,    33,    34,    38,    39,    40,    41,    42,    49,    50,
      51,    52,    53,    54,    56,    59,    63,    64,    65,    67,
      71,    76,    81,    24,    25,    27,    28,    42,    49,    54,
      66,    67,    71,    50,    52,    54,    26,    26,    43,    44,
      26,    46,    47,    21,    26,    26,    21,    21,    26,    21,
      21,     0,    38,    18,     3,     4,     5,     6,    18,     3,
       4,     5,     6,    26,    26,    20,    66,    22,    22,    21,
       9,    21,    16,    18,     9,    21,    16,    18,    26,    55,
      21,    21,    15,    50,    51,    52,    53,    68,    69,    70,
      26,    17,    26,    42,    43,    46,    77,    78,    68,    21,
      26,    51,    54,    51,    51,    51,    21,    26,    53,    54,
      53,    53,    53,    24,    25,    57,    58,    60,    61,    26,
      45,    24,    25,    60,    43,    26,    48,    60,    46,    16,
      22,    24,    25,    57,    57,    68,     7,     8,     9,    10,
      11,    12,     7,     8,     9,    10,    11,    12,    22,    14,
      13,    22,    19,     9,    22,    68,    79,    22,    26,    26,
      22,    16,    22,    16,     9,    26,    26,    22,     9,    22,
      55,    26,    26,    22,    22,    51,    51,     9,    51,    51,
      51,    53,    53,     9,    53,    53,    53,    63,    64,    68,
      69,    19,    32,    72,    73,    26,    19,    40,    18,    26,
      80,    19,    40,    18,    57,    19,    40,    60,    26,    27,
      45,    50,    54,    19,    40,    26,    28,    48,    52,    54,
      19,    40,    18,    18,    51,    53,    30,    72,    21,    27,
      28,    20,    36,    72,    74,     9,    40,    62,    67,     9,
      62,    62,    62,    62,    64,    65,    20,    27,    28,    17,
      17,    17,    26,    54,    62,    20,    45,    48,    20,    20,
      20,    20,    22,    22,    19,    62,    19,    62,    19,    62,
      17,    17,    62,    35,    75,    62,    75,    62,    75,    19,
      62,    19,    62,    20,    18,    20,    20,    62,    75,    62,
      75,    75,    75,    75,    20,    20,    75,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    40,    40,    40,
      40,    40,    40,    41,    41,    42,    42,    43,    43,    44,
      44,    45,    45,    45,    45,    45,    46,    46,    47,    47,
      48,    48,    48,    48,    48,    49,    49,    50,    50,    50,
      50,    51,    51,    51,    51,    51,    52,    52,    52,    52,
      53,    53,    53,    53,    53,    54,    55,    55,    56,    56,
      56,    57,    57,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    64,    65,    65,    66,    66,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    75,    75,    76,    76,    77,    78,
      78,    78,    78,    79,    79,    80,    80,    80,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     3,     1,
       3,     1,     3,     3,     3,     3,     2,     3,     1,     3,
       1,     3,     3,     3,     3,     2,     2,     3,     3,     3,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     4,     1,     3,     6,     6,
       6,     1,     3,     1,     1,     2,     2,     6,     8,     6,
       8,     6,     8,     1,     3,     2,     2,     1,     2,     1,
       1,     7,     1,     3,     5,     7,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       4,     3,     3,     3,     3,     3,     4,     3,     2,     6,
       7,     2,     2,     5,     7,     7,     9,     5,     7,     7,
       9,     0,     4,     6,     0,     2,     5,     7,     3,     0,
       1,     1,     1,     0,     2,     0,     3,     3,     5,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
      
#line 1494 "c_comp.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 121 "c_comp.y" /* yacc.c:1906  */



int main()
{
  yyparse();
  printf("\nValid\n");
  return 0;
}

void yyerror(const char *s)
{
  printf("ERROR: %s\n", s);
  exit(0);
}
