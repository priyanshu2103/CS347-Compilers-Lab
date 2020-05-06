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
#line 1 "miniC.y" /* yacc.c:339  */

#pragma GCC diagnostic ignored "-Wwrite-strings"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "codegenHelpers.h"
#include <stack>
#include <algorithm>

using namespace std;
#define YYERROR_VERBOSE 1

extern int yylex();
extern int yyparse();
extern int yyleng;
extern char* yytext;
extern int yylineno;
void yyerror(const char* s);

int ofc, nxtqd, sc, fnd, numPar;
string txt, condVar;
eletype rst;
vector<typeRecord*> typRecLst, gloVars;
stack<vector<typeRecord*> > paraLstStk;
typeRecord* variableRec;
vector<int> ddl;
vector<string> funcInstr, sthVar, dl;
registerSet Set_temp;
vector<funcEntry*> functionEntryRec, FuncCallPtrLst;
funcEntry* FuncActPtr;
funcEntry* FuncCallPtr;
bool errFnd;

vector<pair<string,int>> sVar;

#line 104 "miniC.tab.c" /* yacc.c:339  */

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
   by #include "miniC.tab.h".  */
#ifndef YY_YY_MINIC_TAB_H_INCLUDED
# define YY_YY_MINIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 39 "miniC.y" /* yacc.c:355  */

    #include "codegenHelpers.h"

#line 138 "miniC.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    NUMFLOAT = 261,
    NUMINT = 262,
    ID = 263,
    NEWLINE = 264,
    READ = 265,
    PRINT = 266,
    COLON = 267,
    QUESTION = 268,
    DOT = 269,
    LCB = 270,
    RCB = 271,
    LSB = 272,
    RSB = 273,
    LP = 274,
    RP = 275,
    SEMI = 276,
    COMMA = 277,
    ASSIGN = 278,
    IF = 279,
    ELSE = 280,
    CASE = 281,
    BREAK = 282,
    DEFAULT = 283,
    CONTINUE = 284,
    WHILE = 285,
    FOR = 286,
    RETURN = 287,
    SWITCH = 288,
    MAIN = 289,
    LSHIFT = 290,
    RSHIFT = 291,
    PLUSASG = 292,
    MINASG = 293,
    MULASG = 294,
    MODASG = 295,
    DIVASG = 296,
    INCREMENT = 297,
    DECREMENT = 298,
    XOR = 299,
    BITAND = 300,
    BITOR = 301,
    PLUS = 302,
    MINUS = 303,
    DIV = 304,
    MUL = 305,
    MOD = 306,
    NOT = 307,
    AND = 308,
    OR = 309,
    LT = 310,
    GT = 311,
    LE = 312,
    GE = 313,
    EQUAL = 314,
    NOTEQUAL = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 43 "miniC.y" /* yacc.c:355  */

    float floatval;
    int intval;
    char *idName;
    int quad;

    struct expression expr;
    struct stmt stmtval;
    struct switchcaser switchCase;
    struct switchtemp switchTemp;
    struct whileexp whileexpval;
    struct shortcircuit shortCircuit;
    struct condition2temp ctemp;

#line 226 "miniC.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINIC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "miniC.tab.c" /* yacc.c:358  */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   298

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    78,    81,    82,    83,    84,    87,    97,
     123,   133,   155,   162,   174,   175,   178,   190,   203,   214,
     223,   231,   243,   254,   260,   268,   274,   283,   289,   295,
     295,   305,   313,   322,   375,   400,   424,   432,   442,   445,
     459,   460,   463,   464,   467,   544,   647,   757,   761,   767,
     818,   819,   822,   837,   837,   854,   872,   909,   960,  1011,
    1062,  1113,  1166,  1176,  1203,  1213,  1221,  1221,  1241,  1241,
    1260,  1267,  1267,  1283,  1290,  1299,  1309,  1317,  1323,  1335,
    1335,  1360,  1369,  1376,  1381,  1388,  1396,  1409,  1409,  1427,
    1441,  1450,  1466,  1480,  1488,  1495,  1494,  1538,  1560,  1559,
    1593,  1604,  1613,  1622,  1640,  1658,  1676,  1694,  1713,  1731,
    1746,  1789,  1832,  1847,  1890,  1933,  1954,  1969,  1983,  2014,
    2022,  2029,  2036,  2043,  2056,  2063,  2086,  2109,  2132,  2157,
    2196,  2254,  2263
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "NUMFLOAT",
  "NUMINT", "ID", "NEWLINE", "READ", "PRINT", "COLON", "QUESTION", "DOT",
  "LCB", "RCB", "LSB", "RSB", "LP", "RP", "SEMI", "COMMA", "ASSIGN", "IF",
  "ELSE", "CASE", "BREAK", "DEFAULT", "CONTINUE", "WHILE", "FOR", "RETURN",
  "SWITCH", "MAIN", "LSHIFT", "RSHIFT", "PLUSASG", "MINASG", "MULASG",
  "MODASG", "DIVASG", "INCREMENT", "DECREMENT", "XOR", "BITAND", "BITOR",
  "PLUS", "MINUS", "DIV", "MUL", "MOD", "NOT", "AND", "OR", "LT", "GT",
  "LE", "GE", "EQUAL", "NOTEQUAL", "$accept", "MAIN_PROG", "PROG",
  "MAINFUNCTION", "MAIN_HEAD", "FUNC_DEF", "FUNC_HEAD", "RES_ID",
  "DECL_PLIST", "DECL_PL", "DECL_PARAM", "BODY", "STMT_LIST", "STMT",
  "$@1", "VAR_DECL", "D", "T", "L", "DEC_ID_ARR", "DEC_BR_DIMLIST",
  "FUNC_CALL", "PARAMLIST", "PLIST", "$@2", "ASG", "LHS", "SWITCHCASE",
  "TEMP1", "TEMP2", "CASELIST", "$@3", "$@4", "$@5", "M3", "N3", "P3",
  "Q3", "Q4", "FORLOOP", "FOREXP", "$@6", "ASG1", "M1", "M2", "IFSTMT",
  "$@7", "IFEXP", "WHILESTMT", "WHILEEXP", "TP1", "CONDITION1", "$@8",
  "CONDITION2", "$@9", "EXPR1", "EXPR21", "EXPR2", "TERM", "FACTOR",
  "ID_ARR", "BR_DIMLIST", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF -229

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-229)))

#define YYTABLE_NINF -95

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,   -32,  -229,    43,     5,    83,  -229,    44,  -229,    48,
      92,  -229,   124,   148,   139,  -229,  -229,  -229,  -229,  -229,
     246,   246,   116,  -229,    21,   137,  -229,   140,   147,  -229,
    -229,  -229,    20,   153,   153,  -229,    12,    13,   150,   151,
      14,    15,    12,   154,   153,   153,    85,   109,   158,    42,
    -229,  -229,   161,  -229,   157,   -11,  -229,  -229,  -229,  -229,
     160,  -229,   164,   126,   128,  -229,  -229,   107,    46,  -229,
      95,   166,   163,   162,  -229,   177,   179,    12,   170,   161,
    -229,  -229,    12,   168,   172,   173,   171,   175,   246,   174,
     178,    12,  -229,  -229,   180,   182,   183,    12,  -229,   176,
      12,  -229,  -229,  -229,  -229,  -229,  -229,   101,  -229,  -229,
      66,  -229,    12,    12,    12,    12,    12,    12,   184,   246,
     246,  -229,  -229,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,  -229,  -229,  -229,  -229,   116,  -229,
     187,  -229,   186,  -229,   198,   197,   169,    12,    12,  -229,
    -229,   204,  -229,  -229,   205,  -229,    12,  -229,   181,  -229,
     206,  -229,  -229,  -229,  -229,  -229,  -229,   246,   207,   208,
     185,   188,    46,    46,   100,   100,   100,   100,   100,   100,
    -229,  -229,  -229,  -229,  -229,   210,  -229,  -229,    12,  -229,
     219,  -229,  -229,   218,  -229,  -229,   224,   217,  -229,    12,
      12,  -229,  -229,  -229,  -229,    12,   228,  -229,  -229,   128,
    -229,  -229,   114,   223,  -229,    28,   232,   242,  -229,  -229,
    -229,   252,  -229,  -229,   245,   243,  -229,  -229,  -229,   246,
      12,   251,  -229,   246,   250,  -229,   203,   255,  -229,  -229,
     248,   114,   203,  -229,  -229,   114,  -229
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    40,    41,     0,     0,     0,     3,     0,     6,     0,
       0,     7,     0,     0,     0,    13,     1,     2,     4,     5,
       0,     0,    15,    38,    44,    39,    42,     0,    37,    40,
     122,   120,   129,     0,     0,    29,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
      22,    23,     0,   123,     0,     0,    28,    25,    77,    26,
       0,    27,     0,    55,    97,   100,   102,   109,   112,   116,
     117,     0,     0,    14,    17,     0,     0,     0,    46,     0,
       9,    36,     0,    53,   130,   129,     0,     0,     0,     0,
       0,     0,    31,    32,     0,     0,     0,    83,    82,     0,
       0,   127,   128,   121,   119,   118,   101,   117,     8,    21,
      44,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,   126,    10,    11,     0,    18,
       0,    45,     0,    43,     0,     0,    50,     0,     0,    34,
      35,     0,   124,    90,     0,    93,     0,    81,     0,    33,
       0,    56,    57,    58,    59,    61,    60,     0,     0,     0,
       0,     0,   110,   111,   105,   106,   107,   108,   103,   104,
     114,   113,   115,    16,    47,     0,   131,    49,     0,    54,
       0,    30,    89,     0,    73,    64,     0,    86,    91,     0,
       0,    48,    52,   132,    92,    83,     0,    78,    85,    96,
      99,    76,    70,     0,    79,     0,     0,     0,    84,    75,
      65,     0,    65,    63,     0,     0,    68,    65,    71,     0,
      83,     0,    66,     0,     0,    74,     0,     0,    72,    88,
       0,    70,     0,    80,    69,    70,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -229,  -229,  -229,   264,  -229,   266,  -229,  -229,  -229,  -229,
     134,   -21,  -229,   225,  -229,     4,  -229,     3,  -229,   201,
    -229,  -229,  -229,  -229,  -229,   -35,  -229,  -229,  -229,  -186,
    -228,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,   -91,    63,  -229,  -229,  -229,  -229,  -229,  -229,
     220,  -229,  -229,    86,  -229,    82,   237,    -3,    26,    -2,
     -23,  -229
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    10,    72,    73,
      74,    48,    49,    50,    88,    51,    12,    52,    25,    26,
      78,    53,   145,   146,   147,    54,    55,    56,   206,   226,
     217,   237,   231,   233,   205,   240,   225,   214,   118,    57,
      58,   219,    99,    95,   213,    59,   208,    60,    61,    62,
     122,    63,   170,    64,   171,    65,    66,    67,    68,    69,
      70,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,    89,    14,    13,    11,    16,   158,    98,    13,    19,
      86,    87,   112,   244,    90,    94,    96,   246,    30,    31,
      32,   101,   102,   105,   107,    75,   113,   114,   115,   116,
     117,    36,    91,   -84,    97,   220,   228,    82,    76,    83,
     -12,   232,   141,    28,    77,    29,     2,   144,    30,    31,
      32,    15,    33,    34,    44,    45,   154,    35,   -19,    20,
      46,    36,    98,    21,    47,   160,    37,   151,   -19,    38,
     -19,    39,    40,    41,    42,    43,   221,   161,   162,   163,
     164,   165,   166,    76,    44,    45,     1,     2,     3,    77,
      46,   103,   104,    85,    47,   131,   132,   133,   168,   169,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,    22,   189,   190,   211,    30,    31,    32,   -62,    29,
       2,   193,   174,   175,   176,   177,   178,   179,    36,   180,
     181,   182,   -62,   -62,   -62,   -62,   -62,   134,   135,   235,
     215,    75,   216,   134,   135,    23,   196,   123,   124,   172,
     173,    44,    45,   202,   123,   124,    24,    46,    27,    79,
      80,    85,   125,   126,   127,   128,   129,   130,    81,   110,
      98,    92,    93,   100,   108,   119,   107,   107,   111,   120,
     -94,   -94,   136,   137,   138,   139,   140,   142,   -51,   148,
      82,   188,   149,   185,   152,    98,   150,   159,   153,   167,
     155,   156,   194,   157,    28,   184,    29,     2,   234,    30,
      31,    32,   238,    33,    34,   241,   186,   187,    35,   -20,
     191,   245,    36,   197,   198,   192,   195,    37,   201,   -20,
      38,   -20,    39,    40,    41,    42,    43,   203,   204,   199,
     207,   200,   -87,   212,   222,    44,    45,    28,   218,    29,
       2,    46,    30,    31,    32,    47,    33,    34,   223,   227,
     229,    35,   -20,   236,   230,    36,   239,   242,   243,    17,
      37,    18,   183,    38,   109,    39,    40,    41,    42,    43,
     143,   224,   210,   121,   106,   209,     0,     0,    44,    45,
       0,     0,     0,     0,    46,     0,     0,     0,    47
};

static const yytype_int16 yycheck[] =
{
      21,    36,    34,     0,     0,     0,    97,    42,     5,     5,
      33,    34,    23,   241,     1,     1,     1,   245,     6,     7,
       8,    44,    45,    46,    47,    22,    37,    38,    39,    40,
      41,    19,    19,    19,    19,     7,   222,    17,    17,    19,
      19,   227,    77,     1,    23,     3,     4,    82,     6,     7,
       8,     8,    10,    11,    42,    43,    91,    15,    16,    15,
      48,    19,    97,    15,    52,   100,    24,    88,    26,    27,
      28,    29,    30,    31,    32,    33,    48,   112,   113,   114,
     115,   116,   117,    17,    42,    43,     3,     4,     5,    23,
      48,     6,     7,     8,    52,    49,    50,    51,   119,   120,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    19,   147,   148,   205,     6,     7,     8,    23,     3,
       4,   156,   125,   126,   127,   128,   129,   130,    19,   131,
     132,   133,    37,    38,    39,    40,    41,    42,    43,   230,
      26,   138,    28,    42,    43,    21,   167,    47,    48,   123,
     124,    42,    43,   188,    47,    48,     8,    48,    19,    22,
      20,     8,    55,    56,    57,    58,    59,    60,    21,     8,
     205,    21,    21,    19,    16,    15,   199,   200,    21,    15,
      54,    53,    16,    20,    22,     8,     7,    17,    20,    17,
      17,    22,    21,     7,    20,   230,    21,    21,    20,    15,
      20,    19,    21,    20,     1,    18,     3,     4,   229,     6,
       7,     8,   233,    10,    11,   236,    18,    20,    15,    16,
      16,   242,    19,    16,    16,    20,    20,    24,    18,    26,
      27,    28,    29,    30,    31,    32,    33,    18,    20,    54,
      16,    53,    25,    15,    12,    42,    43,     1,    25,     3,
       4,    48,     6,     7,     8,    52,    10,    11,    16,     7,
      15,    15,    16,    12,    21,    19,    16,    12,    20,     5,
      24,     5,   138,    27,    49,    29,    30,    31,    32,    33,
      79,   218,   200,    63,    47,   199,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    62,    63,    64,    65,    66,    67,
      68,    76,    77,    78,    34,     8,     0,    64,    66,    76,
      15,    15,    19,    21,     8,    79,    80,    19,     1,     3,
       6,     7,     8,    10,    11,    15,    19,    24,    27,    29,
      30,    31,    32,    33,    42,    43,    48,    52,    72,    73,
      74,    76,    78,    82,    86,    87,    88,   100,   101,   106,
     108,   109,   110,   112,   114,   116,   117,   118,   119,   120,
     121,    72,    69,    70,    71,    78,    17,    23,    81,    22,
      20,    21,    17,    19,   122,     8,   121,   121,    75,    86,
       1,    19,    21,    21,     1,   104,     1,    19,    86,   103,
      19,   121,   121,     6,     7,   121,   117,   121,    16,    74,
       8,    21,    23,    37,    38,    39,    40,    41,    99,    15,
      15,   111,   111,    47,    48,    55,    56,    57,    58,    59,
      60,    49,    50,    51,    42,    43,    16,    20,    22,     8,
       7,    86,    17,    80,    86,    83,    84,    85,    17,    21,
      21,    72,    20,    20,    86,    20,    19,    20,   103,    21,
      86,    86,    86,    86,    86,    86,    86,    15,    72,    72,
     113,   115,   119,   119,   118,   118,   118,   118,   118,   118,
     120,   120,   120,    71,    18,     7,    18,    20,    22,    86,
      86,    16,    20,    86,    21,    20,    72,    16,    16,    54,
      53,    18,    86,    18,    20,    95,    89,    16,   107,   114,
     116,   103,    15,   105,    98,    26,    28,    91,    25,   102,
       7,    48,    12,    16,   104,    97,    90,     7,    90,    15,
      21,    93,    90,    94,    72,   103,    12,    92,    72,    16,
      96,    72,    12,    20,    91,    72,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    63,    63,    64,    65,
      66,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    75,
      74,    74,    74,    74,    74,    74,    74,    74,    76,    77,
      78,    78,    79,    79,    80,    80,    80,    81,    81,    82,
      83,    83,    84,    85,    84,    86,    86,    86,    86,    86,
      86,    86,    87,    88,    89,    90,    92,    91,    93,    91,
      91,    94,    91,    95,    96,    97,    98,    99,   100,   102,
     101,   101,   103,   103,   104,   105,   106,   107,   106,   108,
     108,   109,   110,   110,   111,   113,   112,   112,   115,   114,
     114,   116,   116,   117,   117,   117,   117,   117,   117,   117,
     118,   118,   118,   119,   119,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   122,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     1,     4,     4,
       4,     4,     2,     2,     1,     0,     3,     1,     2,     1,
       0,     2,     1,     1,     2,     1,     1,     1,     1,     0,
       4,     2,     2,     3,     3,     3,     2,     1,     2,     2,
       1,     1,     1,     3,     1,     3,     2,     3,     4,     4,
       1,     0,     3,     0,     2,     1,     3,     3,     3,     3,
       3,     3,     1,     8,     0,     0,     0,     8,     0,     7,
       0,     0,     5,     0,     0,     0,     0,     0,     5,     0,
      13,     3,     1,     0,     0,     0,     4,     0,    11,     4,
       3,     4,     5,     3,     0,     0,     5,     1,     0,     5,
       1,     2,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     1,     2,     2,
       1,     2,     1,     1,     3,     2,     2,     2,     2,     1,
       2,     3,     4
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
        case 8:
#line 88 "miniC.y" /* yacc.c:1646  */
    {
        delVarLst(FuncActPtr, sc);
        sc=0;
        FuncActPtr=NULL;
        string s = "function end";
        gen(funcInstr, s, nxtqd);
    }
#line 1522 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 98 "miniC.y" /* yacc.c:1646  */
    {   
        sc=1;
        FuncActPtr = new funcEntry;
        FuncActPtr->name = string("main");
        FuncActPtr->returnType = INTEGER;
        FuncActPtr->numofpars = 0;
        FuncActPtr->parameterList.clear();
        FuncActPtr->variableList.clear();  
        FuncActPtr->functionOffset = 0;      ;
        typRecLst.clear();
        searchFunction(FuncActPtr, functionEntryRec, fnd);
        if (fnd) {
            cout << "ERROR : Line no. " << yylineno << ", Function " << FuncActPtr->name <<  " is getting re-declared." << endl;
            delete FuncActPtr;
            FuncActPtr = NULL;
        }   
        else {
            addFunction(FuncActPtr, functionEntryRec);
            string s = "function begin main";
            sc = 2; 
            gen(funcInstr, s, nxtqd);
        }
    }
#line 1550 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 124 "miniC.y" /* yacc.c:1646  */
    {
        delVarLst(FuncActPtr, sc); 
        string s = "function end";
        FuncActPtr = NULL;
        sc = 0;
        gen(funcInstr, s, nxtqd);
    }
#line 1562 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "miniC.y" /* yacc.c:1646  */
    {
        int fnd = 0;
        searchFunction(FuncActPtr, functionEntryRec, fnd);
        if(fnd){
            cout << "ERROR : Line no. " << yylineno << ": Function " << FuncActPtr->name <<  " is being re-declared" << endl;
            errFnd = true;
            delete FuncActPtr;
        }   
        else{
            FuncActPtr->numofpars = typRecLst.size();
            FuncActPtr->functionOffset = 0;
            FuncActPtr->parameterList = typRecLst;
            typRecLst.clear();
            addFunction(FuncActPtr, functionEntryRec);
            string s = "function begin _" + FuncActPtr->name;
            sc = 2; 
            gen(funcInstr, s, nxtqd);
        }
    }
#line 1586 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 156 "miniC.y" /* yacc.c:1646  */
    {   
        sc=1;
        FuncActPtr = new funcEntry;
        FuncActPtr->name = string((yyvsp[0].idName));
        FuncActPtr->returnType = rst;
    }
#line 1597 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 163 "miniC.y" /* yacc.c:1646  */
    {
        sc=1;
        FuncActPtr = new funcEntry;
        FuncActPtr->name = string((yyvsp[0].idName));
        FuncActPtr->returnType = NULLVOID;
    }
#line 1608 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 179 "miniC.y" /* yacc.c:1646  */
    {
        typeRecord* pn = NULL;
        int fnd = 0;
        searchPars(variableRec->name, typRecLst, fnd, pn);
        if(fnd){
            cout << "ERROR : Line no. " << yylineno << " Redeclaration of parameter " << variableRec->name <<endl;
        } else {
            typRecLst.push_back(variableRec);
        }
        
    }
#line 1624 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 191 "miniC.y" /* yacc.c:1646  */
    {  
        typeRecord* pn = NULL;
        int fnd = 0;
        searchPars(variableRec->name, typRecLst, fnd , pn );
        if (fnd){
            cout << "ERROR : Line no. " << yylineno << ": Redeclaration of parameter " << variableRec->name <<endl;
        } else {
            typRecLst.push_back(variableRec);
        }
    }
#line 1639 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 204 "miniC.y" /* yacc.c:1646  */
    {
        variableRec = new typeRecord;
        variableRec->name = string((yyvsp[0].idName));
        variableRec->sc = sc;
        variableRec->type = SIMPLE;
        variableRec->tag = VARIABLE;
        variableRec->eleType = rst;
    }
#line 1652 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 215 "miniC.y" /* yacc.c:1646  */
    {
		(yyval.stmtval).brkLst = new vector<int>;
        merge((yyval.stmtval).brkLst, (yyvsp[0].stmtval).brkLst);
        (yyval.stmtval).nxtLst = new vector<int>;
        merge((yyval.stmtval).nxtLst, (yyvsp[0].stmtval).nxtLst);
        (yyval.stmtval).contLst = new vector<int>;
        merge((yyval.stmtval).contLst, (yyvsp[0].stmtval).contLst);
    }
#line 1665 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 224 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector<int>;
    }
#line 1675 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 232 "miniC.y" /* yacc.c:1646  */
    {
		(yyval.stmtval).brkLst = new vector<int>;
        merge((yyval.stmtval).brkLst, (yyvsp[-1].stmtval).brkLst);
        merge((yyval.stmtval).brkLst, (yyvsp[0].stmtval).brkLst);
        (yyval.stmtval).nxtLst = new vector<int>;
        merge((yyval.stmtval).nxtLst, (yyvsp[-1].stmtval).nxtLst);
        merge((yyval.stmtval).nxtLst, (yyvsp[0].stmtval).nxtLst);
        (yyval.stmtval).contLst = new vector<int>;
        merge((yyval.stmtval).contLst, (yyvsp[-1].stmtval).contLst);
        merge((yyval.stmtval).contLst, (yyvsp[0].stmtval).contLst);
    }
#line 1691 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 244 "miniC.y" /* yacc.c:1646  */
    {
    	(yyval.stmtval).brkLst = new vector<int>;
        merge((yyval.stmtval).brkLst, (yyvsp[0].stmtval).brkLst);
        (yyval.stmtval).nxtLst = new vector<int>;
        merge((yyval.stmtval).nxtLst, (yyvsp[0].stmtval).nxtLst);
        (yyval.stmtval).contLst = new vector<int>;
        merge((yyval.stmtval).contLst, (yyvsp[0].stmtval).contLst);
    }
#line 1704 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 255 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
    }
#line 1714 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 261 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
        if ((yyvsp[-1].expr).type != NULLVOID && (yyvsp[-1].expr).type != ERRORTYPE)
            Set_temp.freeRegister(*((yyvsp[-1].expr).registerName));
    }
#line 1726 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 269 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
    }
#line 1736 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 275 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
        merge((yyval.stmtval).contLst, (yyvsp[0].stmtval).contLst);
        merge((yyval.stmtval).brkLst, (yyvsp[0].stmtval).brkLst);

    }
#line 1749 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 284 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
    }
#line 1759 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 290 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
    }
#line 1769 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 295 "miniC.y" /* yacc.c:1646  */
    {sc++;}
#line 1775 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 296 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
        delVarLst(FuncActPtr, sc);
        sc--;
        merge((yyval.stmtval).contLst, (yyvsp[-1].stmtval).contLst);
        merge((yyval.stmtval).brkLst, (yyvsp[-1].stmtval).brkLst);
    }
#line 1789 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 306 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
        (yyval.stmtval).brkLst->push_back(nxtqd);  
        gen(funcInstr, "goto L", nxtqd);      
    }
#line 1801 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 314 "miniC.y" /* yacc.c:1646  */
    {

        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
        (yyval.stmtval).contLst->push_back(nxtqd);
        gen(funcInstr, "goto L", nxtqd);
    }
#line 1814 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 323 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
        if ((yyvsp[-1].expr).type != ERRORTYPE && FuncActPtr != NULL) {
            if (FuncActPtr->returnType == NULLVOID && (yyvsp[-1].expr).type != NULLVOID) {
                cout << "ERROR : Line no. " << yylineno << " Function " << FuncActPtr->name << " should return void type, not " << (yyvsp[-1].expr).type << endl;
            }
            else if (FuncActPtr->returnType != NULLVOID && (yyvsp[-1].expr).type == NULLVOID) {
                cout << "ERROR : Line no. " << yylineno << ": function " << FuncActPtr->name << " should return non-void type" << endl;
            }
            else {
                string s;
                if (FuncActPtr->returnType != NULLVOID && (yyvsp[-1].expr).type != NULLVOID) {
                    if ((yyvsp[-1].expr).type == INTEGER && FuncActPtr->returnType == FLOATING)  {
                        string floatReg = Set_temp.getFloatRegister();
                        s = floatReg + " = " + "convertToFloat(" + *((yyvsp[-1].expr).registerName) + ")";
                        cout << "Warning : " << "Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                        gen(funcInstr, s, nxtqd);
                        s = "return " + floatReg;
                        gen(funcInstr, s, nxtqd);
                        Set_temp.freeRegister(*((yyvsp[-1].expr).registerName));
                        Set_temp.freeRegister(floatReg);
                    }
                    else if ((yyvsp[-1].expr).type == FLOATING && FuncActPtr->returnType == INTEGER) {
                        string intReg = Set_temp.getRegister();
                        s = intReg + " = " + "convertToInt(" + *((yyvsp[-1].expr).registerName) + ")";
                        cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion"<< endl;
                        gen(funcInstr, s, nxtqd);
                        s = "return " + intReg;
                        gen(funcInstr, s, nxtqd);
                        Set_temp.freeRegister(*((yyvsp[-1].expr).registerName));
                        Set_temp.freeRegister(intReg);                        
                    }
                    else {
                        s = "return " + *((yyvsp[-1].expr).registerName);
                        gen(funcInstr, s, nxtqd);
                        Set_temp.freeRegister(*((yyvsp[-1].expr).registerName));
                    }
                }
                else if (FuncActPtr->returnType == NULLVOID && (yyvsp[-1].expr).type == NULLVOID) {
                    s = "return";
                    gen(funcInstr, s, nxtqd);
                }
                else {
                    errFnd = 1;
                    cout << "ERROR : Line no. " << yylineno << ": Exactly one of function " << FuncActPtr->name << "and this return statement has void return type" << endl;
                    if ((yyvsp[-1].expr).type != NULLVOID) Set_temp.freeRegister(*((yyvsp[-1].expr).registerName));
                } 
            }
        }
    }
#line 1871 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 376 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
        if((yyvsp[-1].expr).type == ERRORTYPE){
            errFnd = true;
        }
        else{
            string registerName;
            if ((yyvsp[-1].expr).type == INTEGER){
                registerName = Set_temp.getRegister();
            }
            else {
                registerName = Set_temp.getFloatRegister();
            }
            string s;
            s = "read " + registerName;
            gen(funcInstr, s, nxtqd);
            s = (*((yyvsp[-1].expr).registerName)) + " = " +  registerName;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(registerName);
            if ((yyvsp[-1].expr).offsetRegName != NULL) Set_temp.freeRegister(*((yyvsp[-1].expr).offsetRegName));
        }
    }
#line 1900 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 401 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
        if((yyvsp[-1].expr).type == ERRORTYPE){
            errFnd = true;
        }
        else{
            string registerName;
            if ((yyvsp[-1].expr).type == INTEGER){
                registerName = Set_temp.getRegister();
            }
            else {
                registerName = Set_temp.getFloatRegister();
            }
            string s = registerName + " = " + (*((yyvsp[-1].expr).registerName)) ;
            gen(funcInstr, s, nxtqd);
            s = "print " + registerName;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(registerName);
            if ((yyvsp[-1].expr).offsetRegName != NULL) Set_temp.freeRegister(*((yyvsp[-1].expr).offsetRegName));
        }
    }
#line 1928 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 425 "miniC.y" /* yacc.c:1646  */
    {
        errFnd = 1;
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
        cout << "ERROR : Line no. " + to_string(yylineno) + ": Syntax error" << endl;
    }
#line 1940 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 433 "miniC.y" /* yacc.c:1646  */
    {
        errFnd = 1;
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst = new vector<int>;
        (yyval.stmtval).contLst = new vector <int>;
        cout << "ERROR : Line no. " + to_string(yylineno) + ": Syntax error" << endl;
    }
#line 1952 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 446 "miniC.y" /* yacc.c:1646  */
    { 
        patchDT(rst, typRecLst, sc);
        if(sc > 1){
            insertSymTable(typRecLst, FuncActPtr);
            
        }
        else if(sc == 0){
            insertGVars(typRecLst, gloVars);
        }
        typRecLst.clear();
    }
#line 1968 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 459 "miniC.y" /* yacc.c:1646  */
    { rst = INTEGER; }
#line 1974 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 460 "miniC.y" /* yacc.c:1646  */
    { rst = FLOATING; }
#line 1980 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 468 "miniC.y" /* yacc.c:1646  */
    {   
        typeRecord* vn = NULL;
        int fnd = 0;
        if(FuncActPtr!=NULL && sc > 0){
            searchVars(string((yyvsp[0].idName)), FuncActPtr, fnd, vn, sc);
            if (fnd) {
                if(vn->isValid==true){
                    cout << "ERROR : Line no. :" << yylineno << " The Variable " << string((yyvsp[0].idName)) << " is already declared at same level " << sc << endl ;
                }
                else{
                    if(vn->eleType == rst){
                        vn->isValid=true;
                        vn->maxdloffset = max(vn->maxdloffset,1);
                        vn->type=SIMPLE;
                    }
                    else {
                        variableRec = new typeRecord;
                        variableRec->name = string((yyvsp[0].idName));
                        variableRec->sc = sc;
                        variableRec->isValid=true;
                        variableRec->type = SIMPLE;
                        variableRec->tag = VARIABLE;
                        variableRec->maxdloffset=1;
                        typRecLst.push_back(variableRec);
                    }
                }
            }
            else if (sc == 2) {
                typeRecord* pn = NULL;
                searchPars(string((yyvsp[0].idName)), FuncActPtr->parameterList, fnd , pn);
                if (fnd) {
                    cout << "ERROR : Line no. " << yylineno << " The Variable " << string((yyvsp[0].idName)) << " is already declared in parameters " << endl ;
                } 
                else {
                    variableRec = new typeRecord;
                    variableRec->name = string((yyvsp[0].idName));
                    variableRec->sc = sc;
                    variableRec->isValid=true;
                    variableRec->type = SIMPLE;
                    variableRec->tag = VARIABLE;
                    variableRec->maxdloffset=1;
                    typRecLst.push_back(variableRec);
                }
            }
            else {
                variableRec = new typeRecord;
                variableRec->name = string((yyvsp[0].idName));
                variableRec->sc = sc;
                variableRec->isValid=true;
                variableRec->maxdloffset=1;
                variableRec->type = SIMPLE;
                variableRec->tag = VARIABLE;
                typRecLst.push_back(variableRec);
            }
        }
        else if(sc == 0){
            searchGVars(string((yyvsp[0].idName)), gloVars, fnd, vn, sc);
            if (fnd) {
                cout << "ERROR : Line no. :" << yylineno << " The Variable " << string((yyvsp[0].idName)) << " is already declared at global level " << endl ;
            }
            else{
                variableRec = new typeRecord;
                variableRec->name = string((yyvsp[0].idName));
                variableRec->isValid=true;
                variableRec->type = SIMPLE;
                variableRec->sc = sc;
                variableRec->maxdloffset=1;
                variableRec->tag = VARIABLE;
                typRecLst.push_back(variableRec);   
            }
        } 
        else {
            errFnd = true;
        }
        
    }
#line 2061 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 545 "miniC.y" /* yacc.c:1646  */
    {
        typeRecord* vn = NULL;
        int fnd = 0;
        if(FuncActPtr!=NULL){
            searchVars(string((yyvsp[-2].idName)), FuncActPtr, fnd, vn, sc);
            bool varCreated = false;;
            if (fnd) {
                if(vn->isValid==true){
                    cout << " ERROR : Line no. :" << yylineno << " The Variable " << string((yyvsp[-2].idName)) << " is already declared at same level " << sc << endl ;
                }
                else{
                    if(vn->eleType == rst){
                        vn->isValid=true;
                        vn->maxdloffset = max(vn->maxdloffset,1);
                        vn->type=SIMPLE;
                        varCreated = true;
                    }
                    else {
                        variableRec = new typeRecord;
                        variableRec->name = string((yyvsp[-2].idName));
                        variableRec->type = SIMPLE;
                        variableRec->sc = sc;
                        variableRec->isValid=true;
                        variableRec->tag = VARIABLE;
                        variableRec->maxdloffset=1;
                        typRecLst.push_back(variableRec);
                        varCreated = true;
                    }
                }
            }
            else if (sc == 2) {
                typeRecord* pn = NULL;
                searchPars(string((yyvsp[-2].idName)), FuncActPtr->parameterList, fnd , pn);
                if (fnd) {
                    cout << "ERROR : Line no. " << yylineno << " The Variable " << string((yyvsp[-2].idName)) << " is already declared at parameter level " << endl ;
                } 
                else {
                    variableRec = new typeRecord;
                    variableRec->name = string((yyvsp[-2].idName));
                    variableRec->sc = sc;
                    variableRec->maxdloffset=1;
                    variableRec->isValid=true;
                    variableRec->type = SIMPLE;
                    variableRec->tag = VARIABLE;
                    typRecLst.push_back(variableRec);
                    varCreated = true;
                }
            }
            else {
                variableRec = new typeRecord;
                variableRec->name = string((yyvsp[-2].idName));
                variableRec->type = SIMPLE;
                variableRec->tag = VARIABLE;
                variableRec->sc = sc;
                variableRec->maxdloffset=1;
                variableRec->isValid=true;
                typRecLst.push_back(variableRec);
                varCreated = true;
            }
            if(varCreated){
                if ((yyvsp[0].expr).type == ERRORTYPE) {
                    errFnd = true;
                }
                else if ((yyvsp[0].expr).type == NULLVOID) {
                    cout << "ERROR : Line no. " << yylineno << ": Cannot assign void to non-void type " << string((yyvsp[-2].idName)) << endl;
                    errFnd = true;
                }
                else {
                    string registerName;
                    if (rst == INTEGER && (yyvsp[0].expr).type == FLOATING) {
                        registerName = Set_temp.getRegister();
                        string s = registerName + " = convertToInt(" + (*((yyvsp[0].expr).registerName)) + ")";   
                        cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                        gen(funcInstr, s, nxtqd);
                        Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
                    }
                    else if(rst == FLOATING && ((yyvsp[0].expr).type == INTEGER || (yyvsp[0].expr).type == BOOLEAN)) {
                        registerName = Set_temp.getFloatRegister();
                        string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expr).registerName)) + ")"; 
                        cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                        gen(funcInstr, s, nxtqd); 
                        Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
                    }
                    else {
                        registerName = *((yyvsp[0].expr).registerName);
                    }
                    string dataType = eletypeMapper(rst);
                    dataType += "_" + to_string(sc);
                    string s =  "_" + string((yyvsp[-2].idName)) + "_" + dataType + " = " + registerName ;
                    gen(funcInstr, s, nxtqd);
                    Set_temp.freeRegister(registerName);
                }   
            }
        }
        else if(sc == 0){
            cout << "ERROR : Line No " << yylineno << " ID assignments not allowed in global level variable " << string((yyvsp[-2].idName)) << endl;
            errFnd = true;
        }
        else {
            errFnd = true;
        }
    }
#line 2168 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 648 "miniC.y" /* yacc.c:1646  */
    {  
        if (FuncActPtr != NULL) {
            typeRecord* vn = NULL;
            int fnd = 0;
            searchVars(string((yyvsp[-1].idName)), FuncActPtr, fnd, vn,sc); 
            if (fnd) {
                if(vn->isValid==true){
                    cout << "ERROR : Line no. " << yylineno << " The Variable " << string((yyvsp[-1].idName)) << " is already declared at same level " << sc << endl;
                }
                else{
                    if(vn->eleType == rst){
                        vn->isValid=true;
                        int a=1;
                        for(auto it : ddl){
                            a*=(it);
                        }
                        vn->maxdloffset = max(vn->maxdloffset,a);
                        if(vn->type==ARRAY){
                            vn->dl.clear();           
                        }
                        vn->type=ARRAY;
                        vn->dl = ddl;
                    }
                    else {
                        variableRec = new typeRecord;
                        variableRec->name = string((yyvsp[-1].idName));
                        variableRec->type = ARRAY;
                        variableRec->sc = sc;
                        variableRec->dl = ddl;
                        variableRec->tag = VARIABLE;
                        variableRec->isValid=true;
                        int a=1;
                        for(auto it : ddl){
                            a*=(it);
                        }
                        variableRec->maxdloffset = a;
                        typRecLst.push_back(variableRec);
                    }
                }
            }
            else if (sc == 2) {
                typeRecord* pn = NULL;
                searchPars(string((yyvsp[-1].idName)), FuncActPtr->parameterList, fnd, pn);
                if (fnd) {
                    cout << "ERROR : Line no. " << yylineno << "The Variable " << string((yyvsp[-1].idName)) << " is already declared at parameter level " << endl;
                } 
                else {
                    variableRec = new typeRecord;
                    variableRec->name = string((yyvsp[-1].idName));
                    variableRec->type = ARRAY;
                    variableRec->dl = ddl;
                    variableRec->isValid=true;
                    variableRec->tag = VARIABLE;
                    variableRec->sc = sc;
                    
                    int a=1;
                    for(auto it : ddl){
                        a*=(it);
                    }
                    variableRec->maxdloffset = a;
                    typRecLst.push_back(variableRec);
                }
            }
            else{
                variableRec = new typeRecord;        
                variableRec->name = string((yyvsp[-1].idName));
                variableRec->type = ARRAY;
                variableRec->dl = ddl;
                variableRec->isValid=true;
                variableRec->tag = VARIABLE;
                variableRec->sc = sc;
                
                int a=1;
                for(auto it : ddl){
                    a*=(it);
                }
                variableRec->maxdloffset = a;
                typRecLst.push_back(variableRec);
            }
        } 
        else if(sc == 0){
            typeRecord* vn = NULL;
            searchGVars(string((yyvsp[-1].idName)), gloVars, fnd, vn, sc);
            if (fnd) {
                cout << "ERROR : Line no. " << yylineno << " The Variable " << string((yyvsp[-1].idName)) << " is already declared at global level " << endl;
            }
            else{
                variableRec = new typeRecord;
                variableRec->name = string((yyvsp[-1].idName));
                variableRec->type = ARRAY;
                variableRec->tag = VARIABLE;
                variableRec->sc = sc;
                variableRec->dl = ddl;
                variableRec->isValid=true;
                int a=1;
                for(auto it : ddl){
                    a*=(it);
                }
                variableRec->maxdloffset = a;
                typRecLst.push_back(variableRec);   
            }
        }   
        else{
            errFnd = 1;
        }
        ddl.clear();
    }
#line 2280 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 758 "miniC.y" /* yacc.c:1646  */
    {
        ddl.push_back(atoi((yyvsp[-1].idName)));
    }
#line 2288 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 762 "miniC.y" /* yacc.c:1646  */
    {
        ddl.push_back(atoi((yyvsp[-1].idName)));
    }
#line 2296 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 768 "miniC.y" /* yacc.c:1646  */
    {
        FuncCallPtr = new funcEntry;
        FuncCallPtr->name = string((yyvsp[-3].idName));
        FuncCallPtr->numofpars = typRecLst.size();
        FuncCallPtr->parameterList = typRecLst;
        
        int fnd = 0;
        int vfound=0;
        typeRecord* vn;
        searchVars(FuncCallPtr->name,FuncActPtr,vfound,vn,sc);
        if (vfound) {
            (yyval.expr).type = ERRORTYPE;
            cout<< "ERROR : Line no." << yylineno << " The object being called "<< FuncCallPtr->name << " is not a function or function pointer"<< endl;
        }
        else {
            compareFunction(FuncCallPtr,functionEntryRec,fnd);
            (yyval.expr).type = ERRORTYPE;
            if (fnd == 0) {
                cout << "ERROR : Line no. " << yylineno << " There does not exist a function with name " << string((yyvsp[-3].idName))  << endl;
            }
            else if (fnd == -1) {
                cout << "ERROR : Line no. " << yylineno << " Call parameter list does not match with defined paramters of function " << string((yyvsp[-3].idName)) << endl;
            }
            else {
                (yyval.expr).type = FuncCallPtr->returnType;
                if(FuncCallPtr->returnType == INTEGER){
                    (yyval.expr).registerName = new string(Set_temp.getRegister());
                    gen(funcInstr, "refparam " + (*((yyval.expr).registerName)), nxtqd);
                    gen(funcInstr, "call _" + FuncCallPtr->name + ", " + to_string(typRecLst.size() + 1 ), nxtqd);      
                }
                else if(FuncCallPtr->returnType == FLOATING){
                    (yyval.expr).registerName = new string(Set_temp.getFloatRegister());
                    gen(funcInstr, "refparam " + (*((yyval.expr).registerName)), nxtqd);
                    gen(funcInstr, "call _" + FuncCallPtr->name + ", " + to_string(typRecLst.size() + 1 ), nxtqd);      
                }
                else if (FuncCallPtr->returnType == NULLVOID) {
                    (yyval.expr).registerName = NULL;
                    gen(funcInstr, "call _" + FuncCallPtr->name + ", " + to_string(typRecLst.size()), nxtqd);      
                }
                else {
                    cout << "ERROR : Line no. " << yylineno << ": Illegal return type of function " << FuncCallPtr->name << endl;
                }
            }
        }
        typRecLst.clear();
        typRecLst.swap(paraLstStk.top());
        paraLstStk.pop();
    }
#line 2349 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 819 "miniC.y" /* yacc.c:1646  */
    {paraLstStk.push(typRecLst); typRecLst.clear();}
#line 2355 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 823 "miniC.y" /* yacc.c:1646  */
    {
        variableRec = new typeRecord;
        variableRec->eleType = (yyvsp[0].expr).type;
        if ((yyvsp[0].expr).type == ERRORTYPE) {
            errFnd = true;
        }
        else {
            variableRec->name = *((yyvsp[0].expr).registerName);
            variableRec->type = SIMPLE;
            gen(funcInstr, "param " +  *((yyvsp[0].expr).registerName), nxtqd);   
            Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
        }
        typRecLst.push_back(variableRec);
    }
#line 2374 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 837 "miniC.y" /* yacc.c:1646  */
    {paraLstStk.push(typRecLst); typRecLst.clear();}
#line 2380 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 838 "miniC.y" /* yacc.c:1646  */
    {
        variableRec = new typeRecord;
        variableRec->eleType = (yyvsp[0].expr).type;
        if ((yyvsp[0].expr).type == ERRORTYPE) {
            errFnd = true;
        }
        else {
            variableRec->name = *((yyvsp[0].expr).registerName);
            variableRec->type = SIMPLE; 
            gen(funcInstr, "param " +  *((yyvsp[0].expr).registerName), nxtqd);   
            Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
        }
        typRecLst.push_back(variableRec);
    }
#line 2399 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 855 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.expr).type = (yyvsp[0].shortCircuit).type;
        if((yyval.expr).type != ERRORTYPE && (yyval.expr).type != NULLVOID) {
            (yyval.expr).registerName = (yyvsp[0].shortCircuit).registerName;
            if((yyvsp[0].shortCircuit).jmpLst!=NULL){
                vector<int>* qList = new vector<int>;
                qList->push_back(nxtqd);
                gen(funcInstr,"goto L",nxtqd);
                backpatch((yyvsp[0].shortCircuit).jmpLst, nxtqd, funcInstr);
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
                gen(funcInstr,(*((yyval.expr).registerName)) + " = 1",nxtqd) ;
                backpatch(qList,nxtqd,funcInstr);
                qList->clear();
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
            }
        }
    }
#line 2421 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 873 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expr).type == ERRORTYPE || (yyvsp[0].expr).type == ERRORTYPE) {
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else if ((yyvsp[0].expr).type == NULLVOID) {
            cout << "ERROR : Line no. " << yylineno << " Cannot assign void to non-void type " << *((yyvsp[-2].expr).registerName) << endl;
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else {
            string registerName;
            (yyval.expr).type = (yyvsp[-2].expr).type;
            if ((yyvsp[-2].expr).type == INTEGER && (yyvsp[0].expr).type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expr).registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else if((yyvsp[-2].expr).type == FLOATING && ((yyvsp[0].expr).type == INTEGER || (yyvsp[0].expr).type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expr).registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else {
                registerName = *((yyvsp[0].expr).registerName);
            }
            string s = (*((yyvsp[-2].expr).registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            (yyval.expr).registerName = new string(registerName);
            if ((yyvsp[-2].expr).offsetRegName != NULL) Set_temp.freeRegister(*((yyvsp[-2].expr).offsetRegName));
        }
    }
#line 2462 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 910 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expr).type == ERRORTYPE || (yyvsp[0].expr).type == ERRORTYPE) {
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else if ((yyvsp[0].expr).type == NULLVOID) {
            cout << "ERROR : Line no. " << yylineno << " Cannot assign void to non-void type " << *((yyvsp[-2].expr).registerName) << endl;
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else {
            (yyval.expr).type = (yyvsp[-2].expr).type;
            string registerName;
            if ((yyvsp[-2].expr).type == INTEGER && (yyvsp[0].expr).type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expr).registerName)) + ")";  
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else if((yyvsp[-2].expr).type == FLOATING && ((yyvsp[0].expr).type == INTEGER || (yyvsp[0].expr).type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expr).registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else {
                registerName = *((yyvsp[0].expr).registerName);
            }
            string s, tempReg;
            if((yyvsp[-2].expr).type == INTEGER){
                tempReg = Set_temp.getRegister();
                s = tempReg + " = " + (*((yyvsp[-2].expr).registerName));
                gen(funcInstr, s, nxtqd);
            }
            else{
                tempReg = Set_temp.getFloatRegister();
                s = tempReg + " = " + (*((yyvsp[-2].expr).registerName));   
                gen(funcInstr, s, nxtqd);
            }
            s = registerName + " = " + registerName + " + " + tempReg;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(tempReg);
            s = (*((yyvsp[-2].expr).registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            (yyval.expr).registerName = new string(registerName);
            if ((yyvsp[-2].expr).offsetRegName != NULL) Set_temp.freeRegister(*((yyvsp[-2].expr).offsetRegName));
        }
    }
#line 2517 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 961 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expr).type == ERRORTYPE || (yyvsp[0].expr).type == ERRORTYPE) {
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else if ((yyvsp[0].expr).type == NULLVOID) {
            cout << "ERROR : Line no. " << yylineno << " Cannot assign void to non-void type " << *((yyvsp[-2].expr).registerName) << endl;
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else {
            (yyval.expr).type = (yyvsp[-2].expr).type;
            string registerName;
            if ((yyvsp[-2].expr).type == INTEGER && (yyvsp[0].expr).type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expr).registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else if((yyvsp[-2].expr).type == FLOATING && ((yyvsp[0].expr).type == INTEGER || (yyvsp[0].expr).type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expr).registerName)) + ")"; 
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else {
                registerName = *((yyvsp[0].expr).registerName);
            }
            string s, tempReg;
            if((yyvsp[-2].expr).type == INTEGER){
                tempReg = Set_temp.getRegister();
                s = tempReg + " = " + (*((yyvsp[-2].expr).registerName));
                gen(funcInstr, s, nxtqd);
            }
            else{
                tempReg = Set_temp.getFloatRegister();
                s = tempReg + " = " + (*((yyvsp[-2].expr).registerName));   
                gen(funcInstr, s, nxtqd);
            }
            s = registerName + " = " + registerName + " - " + tempReg;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(tempReg);
            s = (*((yyvsp[-2].expr).registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            (yyval.expr).registerName = new string(registerName);
            if ((yyvsp[-2].expr).offsetRegName != NULL) Set_temp.freeRegister(*((yyvsp[-2].expr).offsetRegName));
        }
    }
#line 2572 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1012 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expr).type == ERRORTYPE || (yyvsp[0].expr).type == ERRORTYPE) {
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else if ((yyvsp[0].expr).type == NULLVOID) {
            cout << "ERROR :Line no. " << yylineno << " Cannot assign void to non-void type " << *((yyvsp[-2].expr).registerName) << endl;
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else {
            (yyval.expr).type = (yyvsp[-2].expr).type;
            string registerName;
            if ((yyvsp[-2].expr).type == INTEGER && (yyvsp[0].expr).type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expr).registerName)) + ")"; 
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else if((yyvsp[-2].expr).type == FLOATING && ((yyvsp[0].expr).type == INTEGER || (yyvsp[0].expr).type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expr).registerName)) + ")";  
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else {
                registerName = *((yyvsp[0].expr).registerName);
            }
            string s, tempReg;
            if((yyvsp[-2].expr).type == INTEGER){
                tempReg = Set_temp.getRegister();
                s = tempReg + " = " + (*((yyvsp[-2].expr).registerName));
                gen(funcInstr, s, nxtqd);
            }
            else{
                tempReg = Set_temp.getFloatRegister();
                s = tempReg + " = " + (*((yyvsp[-2].expr).registerName));   
                gen(funcInstr, s, nxtqd);
            }
            s = registerName + " = " + registerName + " * " + tempReg;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(tempReg);
            s = (*((yyvsp[-2].expr).registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            (yyval.expr).registerName = new string(registerName);
            if ((yyvsp[-2].expr).offsetRegName != NULL) Set_temp.freeRegister(*((yyvsp[-2].expr).offsetRegName));
        }
    }
#line 2627 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1063 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].expr).type == ERRORTYPE || (yyvsp[-2].expr).type == ERRORTYPE ) {
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else if ((yyvsp[0].expr).type == NULLVOID) {
            cout << "ERROR : Line no. " << yylineno << " Cannot assign void to non-void type " << *((yyvsp[-2].expr).registerName) << endl;
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else {
            (yyval.expr).type = (yyvsp[-2].expr).type;
            string registerName;
            if ((yyvsp[-2].expr).type == INTEGER && (yyvsp[0].expr).type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expr).registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else if((yyvsp[-2].expr).type == FLOATING && ((yyvsp[0].expr).type == INTEGER || (yyvsp[0].expr).type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expr).registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else {
                registerName = *((yyvsp[0].expr).registerName);
            }
            string s, tempReg;
            if((yyvsp[-2].expr).type == INTEGER){
                tempReg = Set_temp.getRegister();
                s = tempReg + " = " + (*((yyvsp[-2].expr).registerName));
                gen(funcInstr, s, nxtqd);
            }
            else{
                tempReg = Set_temp.getFloatRegister();
                s = tempReg + " = " + (*((yyvsp[-2].expr).registerName));   
                gen(funcInstr, s, nxtqd);
            }
            s = registerName + " = " + registerName + " / " + tempReg;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(tempReg);
            s = (*((yyvsp[-2].expr).registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            (yyval.expr).registerName = new string(registerName);
            if ((yyvsp[-2].expr).offsetRegName != NULL) Set_temp.freeRegister(*((yyvsp[-2].expr).offsetRegName));
        }
    }
#line 2682 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1114 "miniC.y" /* yacc.c:1646  */
    {
        if (  (yyvsp[0].expr).type == ERRORTYPE || (yyvsp[-2].expr).type == ERRORTYPE) {
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else if ((yyvsp[0].expr).type == NULLVOID) {
            cout << "ERROR : Line no. " << yylineno << " Cannot assign void to non-void type " << *((yyvsp[-2].expr).registerName) << endl;
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else {
            string registerName;
            (yyval.expr).type = (yyvsp[-2].expr).type;
            if ((yyvsp[-2].expr).type == INTEGER && (yyvsp[0].expr).type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*((yyvsp[0].expr).registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else if((yyvsp[-2].expr).type == FLOATING && ((yyvsp[0].expr).type == INTEGER || (yyvsp[0].expr).type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*((yyvsp[0].expr).registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
            }
            else {
                registerName = *((yyvsp[0].expr).registerName);
            }
            string s, tempReg;
            if((yyvsp[-2].expr).type == INTEGER){
                tempReg = Set_temp.getRegister();
                s = tempReg + " = " + (*((yyvsp[-2].expr).registerName));
                gen(funcInstr, s, nxtqd);
            }
            else{
                tempReg = Set_temp.getFloatRegister();
                s = tempReg + " = " + (*((yyvsp[-2].expr).registerName));   
                gen(funcInstr, s, nxtqd);
            }
            s = registerName + " = " + registerName + " % " + tempReg;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(tempReg);
            s = (*((yyvsp[-2].expr).registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            (yyval.expr).registerName = new string(registerName);
            if ((yyvsp[-2].expr).offsetRegName != NULL) Set_temp.freeRegister(*((yyvsp[-2].expr).offsetRegName));
        }
    }
#line 2737 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1167 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.expr).type = (yyvsp[0].expr).type;
        if ((yyval.expr).type != ERRORTYPE) {
            (yyval.expr).registerName = (yyvsp[0].expr).registerName;
            (yyval.expr).offsetRegName = (yyvsp[0].expr).offsetRegName;
        } 
    }
#line 2749 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1177 "miniC.y" /* yacc.c:1646  */
    {
        delVarLst(FuncActPtr,sc);
        sc--;

        int q=nxtqd;
        vector<int>* qList = new vector<int>;
        qList->push_back(q);
        gen(funcInstr, "goto L", nxtqd);
        backpatch((yyvsp[-3].whileexpval).falseList, nxtqd, funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
        reverse((yyvsp[-1].switchCase).casepair->begin(), (yyvsp[-1].switchCase).casepair->end());
        for(auto it : *((yyvsp[-1].switchCase).casepair)){
            if(it.first == "default"){
                gen(funcInstr, "goto L"+to_string(it.second), nxtqd);
            }
            else{
                gen(funcInstr, "if "+ (*((yyvsp[-5].expr).registerName)) +" == "+ it.first + " goto L" + to_string(it.second), nxtqd);
            }
        }
        (yyvsp[-1].switchCase).casepair->clear();
        backpatch(qList, nxtqd, funcInstr);
        backpatch((yyvsp[-1].switchCase).brkLst, nxtqd, funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
    }
#line 2778 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1204 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.whileexpval).begin=nxtqd;
        (yyval.whileexpval).falseList = new vector<int>;
        (yyval.whileexpval).falseList->push_back(nxtqd);
        gen(funcInstr, "goto L", nxtqd);
        sc++;
    }
#line 2790 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1214 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.switchTemp).casepair = new vector<pair<string,int>>;

    }
#line 2799 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1221 "miniC.y" /* yacc.c:1646  */
    {
        (yyvsp[0].switchTemp).casepair->push_back(make_pair("-"+string((yyvsp[-1].idName)), nxtqd));
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
        }
#line 2808 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1226 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.switchCase).brkLst = new vector<int>;
        (yyval.switchCase).nxtLst = new vector<int>;
        (yyval.switchCase).contLst = new vector <int>;
        (yyval.switchCase).casepair = new vector<pair<string,int>>;
        merge((yyval.switchCase).brkLst, (yyvsp[0].switchCase).brkLst);
        merge((yyval.switchCase).contLst,(yyvsp[0].switchCase).contLst);
        merge((yyval.switchCase).nxtLst, (yyvsp[0].switchCase).nxtLst);
        merge((yyval.switchCase).contLst,(yyvsp[-1].stmtval).contLst);
        merge((yyval.switchCase).nxtLst, (yyvsp[-1].stmtval).nxtLst);
        merge((yyval.switchCase).brkLst, (yyvsp[-1].stmtval).brkLst);
        mergeSwitch((yyval.switchCase).casepair, (yyvsp[0].switchCase).casepair);
        mergeSwitch((yyval.switchCase).casepair, (yyvsp[-4].switchTemp).casepair);
    }
#line 2827 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1241 "miniC.y" /* yacc.c:1646  */
    {
        (yyvsp[0].switchTemp).casepair->push_back(make_pair(string((yyvsp[-1].idName)), nxtqd));
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
        }
#line 2836 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1246 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.switchCase).brkLst = new vector<int>;
        (yyval.switchCase).nxtLst = new vector<int>;
        (yyval.switchCase).contLst = new vector <int>;
        (yyval.switchCase).casepair = new vector<pair<string,int>>;
        merge((yyval.switchCase).brkLst, (yyvsp[-1].stmtval).brkLst);
        merge((yyval.switchCase).contLst,(yyvsp[-1].stmtval).contLst);
        merge((yyval.switchCase).nxtLst, (yyvsp[-1].stmtval).nxtLst);
        merge((yyval.switchCase).contLst,(yyvsp[0].switchCase).contLst);
        merge((yyval.switchCase).brkLst, (yyvsp[0].switchCase).brkLst);
        merge((yyval.switchCase).nxtLst, (yyvsp[0].switchCase).nxtLst);
        mergeSwitch((yyval.switchCase).casepair, (yyvsp[0].switchCase).casepair);
        mergeSwitch((yyval.switchCase).casepair, (yyvsp[-4].switchTemp).casepair);
    }
#line 2855 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1261 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.switchCase).brkLst = new vector<int>;
        (yyval.switchCase).nxtLst = new vector<int>;
        (yyval.switchCase).contLst = new vector <int>;
        (yyval.switchCase).casepair = new vector<pair<string,int>>;
    }
#line 2866 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1267 "miniC.y" /* yacc.c:1646  */
    {
        (yyvsp[0].switchTemp).casepair->push_back(make_pair("default", nxtqd));
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
    }
#line 2875 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1271 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.switchCase).nxtLst = new vector<int>;
        (yyval.switchCase).brkLst = new vector<int>;
        (yyval.switchCase).casepair = new vector<pair<string,int>>;
        (yyval.switchCase).contLst = new vector <int>;
        merge((yyval.switchCase).brkLst, (yyvsp[0].stmtval).brkLst);
        merge((yyval.switchCase).contLst,(yyvsp[0].stmtval).contLst);
        merge((yyval.switchCase).nxtLst, (yyvsp[0].stmtval).nxtLst);
        mergeSwitch((yyval.switchCase).casepair, (yyvsp[-2].switchTemp).casepair);
    }
#line 2890 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1284 "miniC.y" /* yacc.c:1646  */
    { 
        (yyval.quad) = nxtqd;
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd); 
    }
#line 2899 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1291 "miniC.y" /* yacc.c:1646  */
    { 
        (yyval.whileexpval).begin = nxtqd; 
        (yyval.whileexpval).falseList = new vector<int>;
        (yyval.whileexpval).falseList->push_back(nxtqd);
        gen(funcInstr, "goto L", nxtqd);
    }
#line 2910 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1300 "miniC.y" /* yacc.c:1646  */
    { 
        (yyval.whileexpval).falseList = new vector<int>;
        (yyval.whileexpval).falseList->push_back(nxtqd);
        gen(funcInstr, "goto L", nxtqd);
        (yyval.whileexpval).begin = nxtqd; 
        gen(funcInstr, "L"+to_string(nxtqd)+":", nxtqd);
    }
#line 2922 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1310 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.whileexpval).begin = nxtqd;
        (yyval.whileexpval).falseList = new vector<int>;
        (yyval.whileexpval).falseList->push_back(nxtqd);
    }
#line 2932 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1318 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.quad) = nxtqd;
    }
#line 2940 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1324 "miniC.y" /* yacc.c:1646  */
    {
        delVarLst(FuncActPtr, sc);
        sc--;
        gen(funcInstr, "goto L" + to_string((yyvsp[-4].whileexpval).begin), nxtqd); 
        merge((yyvsp[-4].whileexpval).falseList,(yyvsp[-1].stmtval).brkLst);
        backpatch((yyvsp[-1].stmtval).contLst,(yyvsp[-4].whileexpval).begin, funcInstr);
        backpatch((yyvsp[-4].whileexpval).falseList, nxtqd, funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd); 
    }
#line 2954 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1335 "miniC.y" /* yacc.c:1646  */
    {
        if((yyvsp[-1].expr).type!=NULLVOID){
            gen(funcInstr, "if "+ (*((yyvsp[-1].expr).registerName)) + " == 0 goto L", nxtqd);
        }
    }
#line 2964 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1340 "miniC.y" /* yacc.c:1646  */
    {
        backpatch((yyvsp[-1].whileexpval).falseList,(yyvsp[-8].quad),funcInstr);
        backpatch((yyvsp[-4].whileexpval).falseList,nxtqd,funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd); 
        (yyval.whileexpval).falseList = new vector<int>;
        if((yyvsp[-7].expr).type!=NULLVOID){
            (yyval.whileexpval).falseList->push_back((yyvsp[-6].whileexpval).begin);            
        }
        (yyval.whileexpval).begin = (yyvsp[-4].whileexpval).begin;
        sc++;
        if((yyvsp[-10].expr).type!=NULLVOID){
            Set_temp.freeRegister(*((yyvsp[-10].expr).registerName));
        }
        if((yyvsp[-7].expr).type!=NULLVOID){
            Set_temp.freeRegister(*((yyvsp[-7].expr).registerName));
        }
        if((yyvsp[-2].expr).type!=NULLVOID){
            Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
        }
    }
#line 2989 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1361 "miniC.y" /* yacc.c:1646  */
    {
        errFnd = 1;
        (yyval.whileexpval).falseList = new vector<int>;
        cout << "ERROR : Line no. " + to_string(yylineno) + " Syntax error in for loop, discarded token till RP" << endl;
        sc++;
    }
#line 3000 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1370 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.expr).type= (yyvsp[0].expr).type;
        if ((yyvsp[0].expr).type != ERRORTYPE && (yyvsp[0].expr).type != NULLVOID) {
            (yyval.expr).registerName = (yyvsp[0].expr).registerName;
        }
    }
#line 3011 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1376 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.expr).type = NULLVOID;
    }
#line 3019 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1382 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.quad)=nxtqd;
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
    }
#line 3028 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1389 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.stmtval).nxtLst = new vector<int>;
        ((yyval.stmtval).nxtLst)->push_back(nxtqd);
        gen(funcInstr, "goto L", nxtqd);
    }
#line 3038 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1397 "miniC.y" /* yacc.c:1646  */
    {
        delVarLst(FuncActPtr,sc);
        sc--;
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst= new vector<int>;
        (yyval.stmtval).contLst= new vector<int>;
        merge((yyval.stmtval).brkLst, (yyvsp[-1].stmtval).brkLst);
        merge((yyval.stmtval).nxtLst, (yyvsp[-3].whileexpval).falseList);
        merge((yyval.stmtval).contLst, (yyvsp[-1].stmtval).contLst);
        backpatch((yyval.stmtval).nxtLst,nxtqd,funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
    }
#line 3055 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1409 "miniC.y" /* yacc.c:1646  */
    {delVarLst(FuncActPtr,sc);}
#line 3061 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1410 "miniC.y" /* yacc.c:1646  */
    {
        delVarLst(FuncActPtr,sc);
        sc--;
        (yyval.stmtval).brkLst = new vector<int>;
        (yyval.stmtval).nxtLst= new vector<int>;
        (yyval.stmtval).contLst= new vector<int>;
        backpatch((yyvsp[-10].whileexpval).falseList,(yyvsp[-3].quad),funcInstr);
        merge((yyval.stmtval).nxtLst,(yyvsp[-5].stmtval).nxtLst );
        backpatch((yyval.stmtval).nxtLst,nxtqd,funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
        merge((yyval.stmtval).brkLst, (yyvsp[-8].stmtval).brkLst);
        merge((yyval.stmtval).contLst, (yyvsp[-8].stmtval).contLst);
        merge((yyval.stmtval).brkLst, (yyvsp[-1].stmtval).brkLst);
        merge((yyval.stmtval).contLst, (yyvsp[-1].stmtval).contLst);
    }
#line 3081 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1428 "miniC.y" /* yacc.c:1646  */
    {
        if((yyvsp[-1].expr).type != ERRORTYPE && (yyvsp[-1].expr).type!=NULLVOID){
            (yyval.whileexpval).falseList = new vector <int>;
            (yyval.whileexpval).falseList->push_back(nxtqd);
            if((yyvsp[-1].expr).type == NULLVOID){
                cout << "ERROR : Line no. " << yylineno << "if statement condition can't be empty" << endl;
                errFnd=true;
            }
            gen(funcInstr, "if "+ (*((yyvsp[-1].expr).registerName)) + " == 0 goto L", nxtqd);
            sc++;
            Set_temp.freeRegister(*((yyvsp[-1].expr).registerName));
        } 
    }
#line 3099 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1442 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.whileexpval).falseList = new vector <int>;
        errFnd = 1;
        cout << "ERROR : Line no. " + to_string(yylineno) + " There is Syntax error in if statement, discarding tokens till RP" << endl;
        sc++;
    }
#line 3110 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1451 "miniC.y" /* yacc.c:1646  */
    {
        delVarLst(FuncActPtr,sc);
        sc--;

        gen(funcInstr, "goto L" + to_string((yyvsp[-3].whileexpval).begin), nxtqd);
        backpatch((yyvsp[-1].stmtval).nxtLst, (yyvsp[-3].whileexpval).begin, funcInstr);
        backpatch((yyvsp[-1].stmtval).contLst, (yyvsp[-3].whileexpval).begin, funcInstr);
        (yyval.stmtval).nxtLst = new vector<int>;
        merge((yyval.stmtval).nxtLst, (yyvsp[-3].whileexpval).falseList);
        merge((yyval.stmtval).nxtLst, (yyvsp[-1].stmtval).brkLst);
        backpatch((yyval.stmtval).nxtLst,nxtqd,funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
    }
#line 3128 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1467 "miniC.y" /* yacc.c:1646  */
    {
        sc++;
        if((yyvsp[-1].expr).type == NULLVOID || (yyvsp[-1].expr).type == ERRORTYPE){
            errFnd = true;
            cout << "ERROR : Line no. " << yylineno << " The Expression in if statement can't be empty"<<endl;
        }
        else{
            (yyval.whileexpval).falseList = new vector<int>;
            ((yyval.whileexpval).falseList)->push_back(nxtqd);
            gen(funcInstr, "if " + *((yyvsp[-1].expr).registerName) + "== 0 goto L", nxtqd);
            (yyval.whileexpval).begin = (yyvsp[-3].quad); 
        }
    }
#line 3146 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1481 "miniC.y" /* yacc.c:1646  */
    {   
        (yyval.whileexpval).falseList = new vector<int>;
        cout << "ERROR : Line no. " + to_string(yylineno) + " There's a Syntax error in while loop, discarding tokens till RP" << endl;
        sc++;
    }
#line 3156 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1489 "miniC.y" /* yacc.c:1646  */
    {
    (yyval.ctemp).temp = new vector<int>;
}
#line 3164 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1495 "miniC.y" /* yacc.c:1646  */
    {
        if((yyvsp[-1].shortCircuit).type!=ERRORTYPE){
            (yyvsp[0].ctemp).temp->push_back(nxtqd);
            gen(funcInstr, "if " + *((yyvsp[-1].shortCircuit).registerName) + "!= 0 goto L", nxtqd);

        }
    }
#line 3176 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1503 "miniC.y" /* yacc.c:1646  */
    {
        if( (yyvsp[0].shortCircuit).type==ERRORTYPE || (yyvsp[-4].shortCircuit).type==ERRORTYPE){
            (yyval.shortCircuit).type = ERRORTYPE;
        }
        else if((yyvsp[-4].shortCircuit).type == NULLVOID || (yyvsp[0].shortCircuit).type == NULLVOID){
            (yyval.shortCircuit).type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << " Both the expessions are NULL" << endl;
        }
        else{
            (yyval.shortCircuit).type = BOOLEAN;
            (yyval.shortCircuit).registerName = new string(Set_temp.getRegister());
            vector<int>* qList = new vector<int>;
            if((yyvsp[0].shortCircuit).jmpLst!=NULL){
                qList->push_back(nxtqd);
                gen(funcInstr,"goto L",nxtqd);
                backpatch((yyvsp[0].shortCircuit).jmpLst, nxtqd, funcInstr);
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
                gen(funcInstr,(*((yyvsp[0].shortCircuit).registerName)) + " = 0",nxtqd) ;
                backpatch(qList,nxtqd,funcInstr);
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
                qList->clear();
            }
            
            (yyval.shortCircuit).jmpLst = new vector<int>;
            merge((yyval.shortCircuit).jmpLst,(yyvsp[-4].shortCircuit).jmpLst);
            
            merge((yyval.shortCircuit).jmpLst, (yyvsp[-3].ctemp).temp);
            ((yyval.shortCircuit).jmpLst)->push_back(nxtqd);
            gen(funcInstr, "if " + *((yyvsp[0].shortCircuit).registerName) + "!= 0 goto L", nxtqd);
            string s = (*((yyval.shortCircuit).registerName)) + " = 0";   
            gen(funcInstr,s,nxtqd);
            Set_temp.freeRegister(*((yyvsp[-4].shortCircuit).registerName));
            Set_temp.freeRegister(*((yyvsp[0].shortCircuit).registerName)); 
        }
    }
#line 3216 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1539 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.shortCircuit).type = (yyvsp[0].shortCircuit).type;
        if ((yyval.shortCircuit).type != ERRORTYPE && (yyval.shortCircuit).type != NULLVOID) {
            (yyval.shortCircuit).registerName = (yyvsp[0].shortCircuit).registerName; 
            if((yyvsp[0].shortCircuit).jmpLst!=NULL){
                vector<int>* qList = new vector<int>;
                qList->push_back(nxtqd);
                gen(funcInstr,"goto L",nxtqd);
                backpatch((yyvsp[0].shortCircuit).jmpLst, nxtqd, funcInstr);
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
                gen(funcInstr,(*((yyval.shortCircuit).registerName)) + " = 0",nxtqd) ;
                backpatch(qList,nxtqd,funcInstr);
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
                qList->clear();   
            }
        }
    }
#line 3238 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1560 "miniC.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-1].shortCircuit).type!=ERRORTYPE ){

          ((yyvsp[0].ctemp).temp)->push_back(nxtqd);
         gen(funcInstr, "if " + *((yyvsp[-1].shortCircuit).registerName) + " == 0 " +" goto L", nxtqd);
      } 
    }
#line 3250 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1568 "miniC.y" /* yacc.c:1646  */
    {
        if (  (yyvsp[0].expr).type==ERRORTYPE || (yyvsp[-4].shortCircuit).type==ERRORTYPE) {
            (yyval.shortCircuit).type = ERRORTYPE;
        }
        else if((yyvsp[-4].shortCircuit).type == NULLVOID || (yyvsp[0].expr).type == NULLVOID){
            (yyval.shortCircuit).type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ": Both the expessions are NULL" << endl;
        }
        else{
            (yyval.shortCircuit).type = BOOLEAN;
            (yyval.shortCircuit).registerName = new string(Set_temp.getRegister());
            (yyval.shortCircuit).jmpLst = new vector<int>;
            merge((yyval.shortCircuit).jmpLst,(yyvsp[-4].shortCircuit).jmpLst);
            vector<int>* qList = new vector<int>;
            
            merge((yyval.shortCircuit).jmpLst, (yyvsp[-3].ctemp).temp);
            ((yyval.shortCircuit).jmpLst)->push_back(nxtqd);
            gen(funcInstr, "if " + *((yyvsp[0].expr).registerName) + " == 0 "+" goto L", nxtqd);

            string s = (*((yyval.shortCircuit).registerName)) + " = 1";   
            gen(funcInstr,s,nxtqd);
            Set_temp.freeRegister(*((yyvsp[-4].shortCircuit).registerName));
            Set_temp.freeRegister(*((yyvsp[0].expr).registerName));   
        }
    }
#line 3280 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1594 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.shortCircuit).type = (yyvsp[0].expr).type;
        if ((yyvsp[0].expr).type != ERRORTYPE && (yyvsp[0].expr).type != NULLVOID) {
            (yyval.shortCircuit).registerName = (yyvsp[0].expr).registerName; 
            (yyval.shortCircuit).jmpLst = new vector<int>;
            (yyval.shortCircuit).jmpLst=NULL;   
        }
    }
#line 3293 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1605 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.expr).type = (yyvsp[0].expr).type;
        if ((yyvsp[0].expr).type != ERRORTYPE && (yyvsp[0].expr).type != NULLVOID) {
            (yyval.expr).registerName = (yyvsp[0].expr).registerName;
            string s = (*((yyval.expr).registerName)) + " = ~" + (*((yyvsp[0].expr).registerName));   
            gen(funcInstr, s, nxtqd);
        }
    }
#line 3306 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1614 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.expr).type = (yyvsp[0].expr).type;
        if ((yyvsp[0].expr).type != ERRORTYPE && (yyvsp[0].expr).type != NULLVOID) {
            (yyval.expr).registerName = (yyvsp[0].expr).registerName;    
        }
    }
#line 3317 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1623 "miniC.y" /* yacc.c:1646  */
    {
        if ( (yyvsp[0].expr).type == ERRORTYPE || (yyvsp[-2].expr).type == ERRORTYPE ) {
            (yyval.expr).type = ERRORTYPE;
        }
        else if( (yyvsp[0].expr).type == NULLVOID || (yyvsp[-2].expr).type == NULLVOID ){
            (yyval.expr).type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << " Both the expessions should not be  NULL" << endl;
        }
        else {
            (yyval.expr).type = BOOLEAN;
            (yyval.expr).registerName = new string(Set_temp.getRegister());     
            string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[-2].expr).registerName)) + " == " + (*((yyvsp[0].expr).registerName))   ;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
            Set_temp.freeRegister(*((yyvsp[0].expr).registerName));  
        }   
    }
#line 3339 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1641 "miniC.y" /* yacc.c:1646  */
    {
        if( (yyvsp[0].expr).type == ERRORTYPE || (yyvsp[-2].expr).type == ERRORTYPE ){
            (yyval.expr).type = ERRORTYPE;
        }
        else if( (yyvsp[0].expr).type == NULLVOID || (yyvsp[-2].expr).type == NULLVOID ){
            (yyval.expr).type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ":Both the expessions cannot be  NULL" << endl;
        }
        else{
            (yyval.expr).type = BOOLEAN;
            (yyval.expr).registerName = new string(Set_temp.getRegister());     
            string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[-2].expr).registerName)) + " != " + (*((yyvsp[0].expr).registerName));   
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
            Set_temp.freeRegister(*((yyvsp[0].expr).registerName));  
        }   
    }
#line 3361 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1659 "miniC.y" /* yacc.c:1646  */
    {
        if( (yyvsp[0].expr).type == ERRORTYPE || (yyvsp[-2].expr).type == ERRORTYPE){
            (yyval.expr).type = ERRORTYPE;
        }
        else if( (yyvsp[0].expr).type == NULLVOID || (yyvsp[-2].expr).type == NULLVOID){
            (yyval.expr).type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            (yyval.expr).type = BOOLEAN;
            (yyval.expr).registerName = new string(Set_temp.getRegister());     
            string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[-2].expr).registerName)) + " < " + (*((yyvsp[0].expr).registerName));   
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
            Set_temp.freeRegister(*((yyvsp[0].expr).registerName));  
        }   
    }
#line 3383 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1677 "miniC.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].expr).type == ERRORTYPE || (yyvsp[0].expr).type == ERRORTYPE){
            (yyval.expr).type = ERRORTYPE;
        }
        else if((yyvsp[-2].expr).type == NULLVOID || (yyvsp[0].expr).type == NULLVOID){
            (yyval.expr).type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            (yyval.expr).type = BOOLEAN;
            (yyval.expr).registerName = new string(Set_temp.getRegister());     
            string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[-2].expr).registerName)) + " > " + (*((yyvsp[0].expr).registerName));   
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
            Set_temp.freeRegister(*((yyvsp[0].expr).registerName));  
        }   
    }
#line 3405 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1695 "miniC.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].expr).type == ERRORTYPE || (yyvsp[0].expr).type == ERRORTYPE){
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;
        }
        else if( (yyvsp[0].expr).type == NULLVOID || (yyvsp[-2].expr).type == NULLVOID){
            (yyval.expr).type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            (yyval.expr).type = BOOLEAN;
            (yyval.expr).registerName = new string(Set_temp.getRegister());     
            string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[-2].expr).registerName)) + " <= " + (*((yyvsp[0].expr).registerName));   
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
            Set_temp.freeRegister(*((yyvsp[0].expr).registerName));  
        }   
    }
#line 3428 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1714 "miniC.y" /* yacc.c:1646  */
    {
        if( (yyvsp[0].expr).type == ERRORTYPE || (yyvsp[-2].expr).type == ERRORTYPE ){
            (yyval.expr).type = ERRORTYPE;
        }
        else if((yyvsp[-2].expr).type == NULLVOID || (yyvsp[0].expr).type == NULLVOID){
            (yyval.expr).type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            (yyval.expr).type = BOOLEAN;
            (yyval.expr).registerName = new string(Set_temp.getRegister());     
            string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[-2].expr).registerName)) + " >= " + (*((yyvsp[0].expr).registerName));  
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
            Set_temp.freeRegister(*((yyvsp[0].expr).registerName));  
        }   
    }
#line 3450 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1732 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.expr).type = (yyvsp[0].expr).type; 
        if((yyval.expr).type == ERRORTYPE){
            errFnd = true;
        }
        else{
            if((yyvsp[0].expr).type != NULLVOID){
                (yyval.expr).registerName = new string(*((yyvsp[0].expr).registerName)); 
                delete (yyvsp[0].expr).registerName; 
            }
        }    
    }
#line 3467 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1747 "miniC.y" /* yacc.c:1646  */
    {
        if ( (yyvsp[0].expr).type == ERRORTYPE || (yyvsp[-2].expr).type == ERRORTYPE ) {
            (yyval.expr).type = ERRORTYPE; 
            errFnd = true; 
        }
        else {
            if (arithmeticCompatible((yyvsp[-2].expr).type, (yyvsp[0].expr).type)) {
                (yyval.expr).type = compareTypes((yyvsp[-2].expr).type,(yyvsp[0].expr).type);

                if ((yyvsp[-2].expr).type == INTEGER && (yyvsp[0].expr).type == FLOATING) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[-2].expr).registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
                    (yyvsp[-2].expr).registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }
                else if ((yyvsp[-2].expr).type == FLOATING && (yyvsp[0].expr).type == INTEGER) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[0].expr).registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
                    (yyvsp[0].expr).registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }

                if ((yyval.expr).type == INTEGER) 
                    (yyval.expr).registerName = new string(Set_temp.getRegister());
                else
                    (yyval.expr).registerName = new string(Set_temp.getFloatRegister());
                    
                string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[-2].expr).registerName)) + " + " + (*((yyvsp[0].expr).registerName));;   
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));   
            }
            else {
                cout << "ERROR : Line no. " << yylineno <<" Type mismatch in expression" << endl;
                (yyval.expr).type = ERRORTYPE;
            }
        }
    }
#line 3514 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1790 "miniC.y" /* yacc.c:1646  */
    {
        if ( (yyvsp[0].expr).type == ERRORTYPE || (yyvsp[-2].expr).type == ERRORTYPE ) {
            (yyval.expr).type = ERRORTYPE;
            errFnd = true;  
        }
        else {
            if (arithmeticCompatible((yyvsp[-2].expr).type, (yyvsp[0].expr).type)) {
                (yyval.expr).type = compareTypes((yyvsp[-2].expr).type,(yyvsp[0].expr).type);

                if ((yyvsp[-2].expr).type == INTEGER && (yyvsp[0].expr).type == FLOATING) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[-2].expr).registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
                    (yyvsp[-2].expr).registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }
                else if ((yyvsp[-2].expr).type == FLOATING && (yyvsp[0].expr).type == INTEGER) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[0].expr).registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
                    (yyvsp[0].expr).registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }

                if ((yyval.expr).type == INTEGER) 
                    (yyval.expr).registerName = new string(Set_temp.getRegister());
                else
                    (yyval.expr).registerName = new string(Set_temp.getFloatRegister());
                    
                string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[-2].expr).registerName)) + " - " + (*((yyvsp[0].expr).registerName));;   
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));   
            }
            else {
                cout << "ERROR : Line no. " << yylineno << " Type mismatch in expression" << endl;
                (yyval.expr).type = ERRORTYPE;
            }
        }
    }
#line 3561 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1833 "miniC.y" /* yacc.c:1646  */
    { 
        (yyval.expr).type = (yyvsp[0].expr).type; 
        if ((yyvsp[0].expr).type == ERRORTYPE) {
            errFnd = true;
        }
        else {
            if((yyvsp[0].expr).type!= NULLVOID){
                (yyval.expr).registerName = new string(*((yyvsp[0].expr).registerName)); 
                delete (yyvsp[0].expr).registerName;
            }         
        } 
    }
#line 3578 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1848 "miniC.y" /* yacc.c:1646  */
    {
        if ( (yyvsp[0].expr).type == ERRORTYPE || (yyvsp[-2].expr).type == ERRORTYPE) {
            (yyval.expr).type = ERRORTYPE;  
        }
        else {
            if (arithmeticCompatible((yyvsp[-2].expr).type, (yyvsp[0].expr).type)) {
                (yyval.expr).type = compareTypes((yyvsp[-2].expr).type,(yyvsp[0].expr).type);

                if ((yyvsp[-2].expr).type == INTEGER && (yyvsp[0].expr).type == FLOATING) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[-2].expr).registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
                    (yyvsp[-2].expr).registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }
                else if ((yyvsp[-2].expr).type == FLOATING && (yyvsp[0].expr).type == INTEGER) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[0].expr).registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
                    (yyvsp[0].expr).registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }

                if ((yyval.expr).type == INTEGER) 
                    (yyval.expr).registerName = new string(Set_temp.getRegister());
                else
                    (yyval.expr).registerName = new string(Set_temp.getFloatRegister());
                    
                string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[-2].expr).registerName)) + " * " + (*((yyvsp[0].expr).registerName));;   
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));   
            }
            else {
                cout << "Error: " << "Line no. " << yylineno << ":  ";
                cout << "Type mismatch in expression" << endl;
                (yyval.expr).type = ERRORTYPE;
            }
        }
    }
#line 3625 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1891 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].expr).type == ERRORTYPE || (yyvsp[-2].expr).type == ERRORTYPE) {
        (yyval.expr).type = ERRORTYPE;  
        }
        else {
            if (arithmeticCompatible((yyvsp[-2].expr).type, (yyvsp[0].expr).type)) {
                (yyval.expr).type = compareTypes((yyvsp[-2].expr).type,(yyvsp[0].expr).type);

                if ((yyvsp[-2].expr).type == INTEGER && (yyvsp[0].expr).type == FLOATING) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[-2].expr).registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+" Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
                    (yyvsp[-2].expr).registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }
                else if ((yyvsp[-2].expr).type == FLOATING && (yyvsp[0].expr).type == INTEGER) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*((yyvsp[0].expr).registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*((yyvsp[0].expr).registerName));
                    (yyvsp[0].expr).registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }

                if ((yyval.expr).type == INTEGER) 
                    (yyval.expr).registerName = new string(Set_temp.getRegister());
                else
                    (yyval.expr).registerName = new string(Set_temp.getFloatRegister());
                    
                string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[-2].expr).registerName)) + " / " + (*((yyvsp[0].expr).registerName));   
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));   
            }
            else {
                cout << "Error: " << "Line no. " << yylineno << ": ";
                cout << "Type mismatch in expression" << endl;
                (yyval.expr).type = ERRORTYPE;
            }
        }   
    }
#line 3672 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1934 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].expr).type == ERRORTYPE || (yyvsp[0].expr).type == ERRORTYPE) {
            (yyval.expr).type = ERRORTYPE;  
        }
        else {
            if ((yyvsp[-2].expr).type == INTEGER && (yyvsp[0].expr).type == INTEGER) {
                (yyval.expr).type = INTEGER;
                (yyval.expr).registerName = new string(Set_temp.getRegister());  
                string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[-2].expr).registerName)) + " % " + (*((yyvsp[0].expr).registerName));;   
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*((yyvsp[-2].expr).registerName));
                Set_temp.freeRegister(*((yyvsp[0].expr).registerName));   
            }
            else {
                cout << "Error: " << "Line no. " << yylineno << ": ";
                cout << "Type mismatch in expression" << endl;
                (yyval.expr).type = ERRORTYPE;
            }
        }   
    }
#line 3697 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1955 "miniC.y" /* yacc.c:1646  */
    { 
        (yyval.expr).type = (yyvsp[0].expr).type; 
        if ((yyvsp[0].expr).type == ERRORTYPE) {
            errFnd = true;
        }
        else {
            if((yyvsp[0].expr).type != NULLVOID){
                (yyval.expr).registerName = new string(*((yyvsp[0].expr).registerName)); 
                delete (yyvsp[0].expr).registerName;
            }  
        } 
    }
#line 3714 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1970 "miniC.y" /* yacc.c:1646  */
    { 
        (yyval.expr).type = (yyvsp[0].expr).type;
        if ((yyval.expr).type != ERRORTYPE) {
            if ((yyval.expr).type == INTEGER)
                (yyval.expr).registerName = new string(Set_temp.getRegister());
            else (yyval.expr).registerName = new string(Set_temp.getFloatRegister());
            string s = (*((yyval.expr).registerName)) + " = " + (*((yyvsp[0].expr).registerName)) ;
            gen(funcInstr, s, nxtqd);
            if((yyvsp[0].expr).offsetRegName != NULL){
                Set_temp.freeRegister((*((yyvsp[0].expr).offsetRegName)));
            }
        }
    }
#line 3732 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1984 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.expr).type = (yyvsp[0].expr).type;
        if((yyvsp[0].expr).type != ERRORTYPE){
            string s="";
            if ((yyval.expr).type == INTEGER){
                (yyval.expr).registerName = new string(Set_temp.getRegister());
                string temp=Set_temp.getRegister();
                string temp1=Set_temp.getRegister();
                gen(funcInstr, temp + " = 0", nxtqd);
                gen(funcInstr, temp1 + " = " +  (*((yyvsp[0].expr).registerName)), nxtqd);
                s = (*((yyval.expr).registerName)) + " = " + temp + " -" + temp1 ;
                Set_temp.freeRegister(temp);
                Set_temp.freeRegister(temp1);
            }
            else{ 
                (yyval.expr).registerName = new string(Set_temp.getFloatRegister());
                string temp=Set_temp.getFloatRegister();
                string temp1=Set_temp.getRegister();
                gen(funcInstr, temp + " = 0", nxtqd);
                gen(funcInstr, temp1 + " = " +  (*((yyvsp[0].expr).registerName)), nxtqd);
                s = (*((yyval.expr).registerName)) + " = 0 -" + temp1 ;
                Set_temp.freeRegister(temp);
                Set_temp.freeRegister(temp1);
            }
            gen(funcInstr, s, nxtqd);
            if((yyvsp[0].expr).offsetRegName != NULL){
                Set_temp.freeRegister((*((yyvsp[0].expr).offsetRegName)));
            }
        }       
    }
#line 3767 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 2015 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.expr).type = INTEGER; 
        (yyval.expr).registerName = new string(Set_temp.getRegister());
        string s = (*((yyval.expr).registerName)) + " = -" + string((yyvsp[0].idName)) ;
        gen(funcInstr, s, nxtqd);  
        
    }
#line 3779 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 2023 "miniC.y" /* yacc.c:1646  */
    { 
        (yyval.expr).type = INTEGER; 
        (yyval.expr).registerName = new string(Set_temp.getRegister());
        string s = (*((yyval.expr).registerName)) + " = " + string((yyvsp[0].idName)) ;
        gen(funcInstr, s, nxtqd);  
    }
#line 3790 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 2030 "miniC.y" /* yacc.c:1646  */
    {
        (yyval.expr).type = FLOATING;
        (yyval.expr).registerName = new string(Set_temp.getFloatRegister());
        string s = (*((yyval.expr).registerName)) + " = " + string((yyvsp[0].idName)) ;
        gen(funcInstr, s, nxtqd);  
    }
#line 3801 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 2037 "miniC.y" /* yacc.c:1646  */
    { 
        (yyval.expr).type = FLOATING;
        (yyval.expr).registerName = new string(Set_temp.getFloatRegister());
        string s = (*((yyval.expr).registerName)) + " = " + string((yyvsp[0].idName)) ;
        gen(funcInstr, s, nxtqd);  
    }
#line 3812 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 2044 "miniC.y" /* yacc.c:1646  */
    { 
        (yyval.expr).type = (yyvsp[0].expr).type; 
        if ((yyvsp[0].expr).type == ERRORTYPE) {
            if ((yyvsp[0].expr).type == NULLVOID){
                delete FuncCallPtr;
            }
            else {
                (yyval.expr).registerName = (yyvsp[0].expr).registerName;
                delete FuncCallPtr;
            }
        }; 
    }
#line 3829 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 2057 "miniC.y" /* yacc.c:1646  */
    { 
        (yyval.expr).type = (yyvsp[-1].expr).type; 
        if ((yyvsp[-1].expr).type != ERRORTYPE) {
            (yyval.expr).registerName = (yyvsp[-1].expr).registerName;
        }
    }
#line 3840 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 2064 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].expr).type == INTEGER) {
            (yyval.expr).type = INTEGER;   
            string newReg = Set_temp.getRegister();
            (yyval.expr).registerName = new string(newReg); 
            string s = newReg + " = " + (*((yyvsp[-1].expr).registerName)) ;
            gen(funcInstr, s, nxtqd); 
            string newReg2 = Set_temp.getRegister();
            s = newReg2 + " = " + newReg + " + 1"; 
            gen(funcInstr, s, nxtqd);
            s = (*((yyvsp[-1].expr).registerName)) + " = " + newReg2; 
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(newReg2);
            if((yyvsp[-1].expr).offsetRegName != NULL){
                Set_temp.freeRegister((*((yyvsp[-1].expr).offsetRegName)));
            }
        }
        else {
            (yyval.expr).type = ERRORTYPE;
            cout << "Error: " << "Line no. " << yylineno << " Cannot increment a variable of non-integer type "<< *((yyvsp[-1].expr).registerName) << endl; 
        }
    }
#line 3867 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 2087 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].expr).type == INTEGER) {
            (yyval.expr).type = INTEGER;   
            string newReg = Set_temp.getRegister();
            (yyval.expr).registerName = new string(newReg);
            string s = newReg + " = " + (*((yyvsp[-1].expr).registerName)); 
            gen(funcInstr, s, nxtqd);
            string newReg2 = Set_temp.getRegister();
            s = newReg2 + " = " + newReg + " - 1"; 
            gen(funcInstr, s, nxtqd);
            s = (*((yyvsp[-1].expr).registerName)) + " = " + newReg2; 
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(newReg2); 
            if((yyvsp[-1].expr).offsetRegName != NULL){
                Set_temp.freeRegister((*((yyvsp[-1].expr).offsetRegName)));
            }    
        }
        else {
            (yyval.expr).type = ERRORTYPE;
            cout << "ERROR : Line no. " << yylineno << " Cannot increment non-integer type variable " << *((yyvsp[-1].expr).registerName) << endl; 
        }
    }
#line 3894 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 2110 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].expr).type == INTEGER) {
            (yyval.expr).type = INTEGER;   
            string newReg = Set_temp.getRegister();
            string s = newReg + " = " + (*((yyvsp[0].expr).registerName));
            gen(funcInstr, s, nxtqd);
            string newReg2 = Set_temp.getRegister();
            (yyval.expr).registerName = new string(newReg2);
            s = newReg2 + " = " + newReg + " + 1"; 
            gen(funcInstr, s, nxtqd);
            s = (*((yyvsp[0].expr).registerName)) + " = " + newReg2; 
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(newReg); 
            if((yyvsp[0].expr).offsetRegName != NULL){
                Set_temp.freeRegister((*((yyvsp[0].expr).offsetRegName)));
            }     
        }
        else {
            (yyval.expr).type = ERRORTYPE;
            cout << "Error: Line no. " << yylineno << " Cannot increment non-integer type variable "<<*((yyvsp[0].expr).registerName) << endl; 
        }
    }
#line 3921 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 2133 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].expr).type == INTEGER) {
            (yyval.expr).type = INTEGER;   
            string newReg = Set_temp.getRegister();
            string s = newReg + " = " + (*((yyvsp[0].expr).registerName)); 
            gen(funcInstr, s, nxtqd);
            string newReg2 = Set_temp.getRegister();
            (yyval.expr).registerName = new string(newReg2);
            s = newReg2 + " = " + newReg + " - 1"; 
            gen(funcInstr, s, nxtqd);
            s = (*((yyvsp[0].expr).registerName)) + " = " + newReg2; 
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(newReg);
            if((yyvsp[0].expr).offsetRegName != NULL){
                Set_temp.freeRegister((*((yyvsp[0].expr).offsetRegName)));
            }         
        }
        else {
            (yyval.expr).type = ERRORTYPE;
            cout << "Error Line no. " << yylineno << " Cannot increment a variable of non-integer type" << *((yyvsp[0].expr).registerName) << endl; 
        }
    }
#line 3948 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 2158 "miniC.y" /* yacc.c:1646  */
    {   
        typeRecord* vn = NULL;
        int fnd = 0;
        searchCallVars(string((yyvsp[0].idName)), FuncActPtr, fnd, vn, gloVars); 
        (yyval.expr).offsetRegName = NULL;
        if(fnd){
            if (vn->type == SIMPLE) {
                (yyval.expr).type = vn->eleType;
                string dataType = eletypeMapper((yyval.expr).type);
                dataType += "_" + to_string(vn->sc);
                (yyval.expr).registerName = new string("_" + string((yyvsp[0].idName)) + "_" + dataType);
            }
            else {
                (yyval.expr).type = ERRORTYPE;
                cout << "Error: Line no. " << yylineno <<  (yyvsp[0].idName) << " is declared as an array but is being used as a singleton" << endl; 
            }
        }
        else {
            if (FuncActPtr != NULL)
                searchPars(string ((yyvsp[0].idName)), FuncActPtr->parameterList, fnd, vn);
            if (fnd) {
                if (vn->type == SIMPLE) {
                    (yyval.expr).type = vn->eleType;
                    string dataType = eletypeMapper((yyval.expr).type);
                    dataType += "_" + to_string(vn->sc);
                    (yyval.expr).registerName = new string("_" + string((yyvsp[0].idName)) + "_" + dataType);
                }
                else {
                    (yyval.expr).type = ERRORTYPE;
                    cout << "Error: Line no. " << yylineno <<  (yyvsp[0].idName) << " is declared as an array but is being used as a singleton" << endl;
                }
            }
            else {
                (yyval.expr).type = ERRORTYPE;
                cout << "Error: " << "Line no. " << yylineno << " Undeclared identifier " << (yyvsp[0].idName) << endl;
            }
        }
    }
#line 3991 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 2197 "miniC.y" /* yacc.c:1646  */
    {
        int fnd = 0;
        typeRecord* vn = NULL;
        (yyval.expr).offsetRegName = NULL; 
        if((yyvsp[0].expr).type == ERRORTYPE){
            errFnd = true;
            (yyval.expr).type = ERRORTYPE;
        }
        else{
            searchCallVars(string((yyvsp[-1].idName)), FuncActPtr, fnd, vn, gloVars); 
            if(fnd){
                if (vn->type == ARRAY) {
                    if (dl.size() == vn->dl.size()) {
                        (yyval.expr).type = vn->eleType;
                        string offsetRegister = Set_temp.getRegister();
                        string dimlistRegister = Set_temp.getRegister();
                        string s = offsetRegister + " = 0";
                        gen(funcInstr, s, nxtqd);
                        for (int i = 0; i < vn->dl.size(); i++) {
                            s = offsetRegister + " = " + offsetRegister + " + " + dl[i];
                            gen(funcInstr, s, nxtqd);
                            if (i != vn->dl.size()-1) {
                                s = dimlistRegister + " = " + to_string(vn->dl[i+1]);
                                gen(funcInstr, s, nxtqd);                                
                                s = offsetRegister + " = " + offsetRegister + " * " + dimlistRegister;
                                gen(funcInstr, s, nxtqd);
                            }
                            Set_temp.freeRegister(dl[i]);
                        }
                        string dataType = eletypeMapper((yyval.expr).type);
                        dataType += "_" + to_string(vn->sc); 
                        s = "_" + string((yyvsp[-1].idName)) + "_" + dataType ;
                        s += "[" + offsetRegister + "]";
                        (yyval.expr).registerName = new string(s);
                        Set_temp.freeRegister(dimlistRegister);
                        (yyval.expr).offsetRegName = new string(offsetRegister);
                        
                    }
                    else {
                        (yyval.expr).type = ERRORTYPE;
                        cout << "Error: " << "Line no. " << yylineno << " Dimension mismatch: " << (yyvsp[-1].idName) << " should have " << dl.size() <<" dimensions" << endl;
                    }
                }
                else {
                    (yyval.expr).type = ERRORTYPE;
                    cout << "Error: " << "Line no. " << yylineno << " " <<  string((yyvsp[-1].idName)) << " is declared as a singleton but is being used as an array" << endl; 
                }
            }
            else {
                (yyval.expr).type = ERRORTYPE;
                cout << "Error: " << "Line no. " << yylineno << " " << "Undeclared identifier " << (yyvsp[-1].idName) << endl;
            }
            dl.clear();
        }
    }
#line 4051 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 2255 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].expr).type == INTEGER) {
            dl.push_back(*((yyvsp[-1].expr).registerName));
        }
        else {
            cout << "Error: " << "Line no. " << yylineno << " " << "One of the dimension of an array cannot be evaluated to integer" << endl;
        }
    }
#line 4064 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 2264 "miniC.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].expr).type == INTEGER) {
            dl.push_back(*((yyvsp[-1].expr).registerName));
        }
        else {
            cout << "Error: " << "Line no. " << yylineno << " " << "One of the dimension of an array cannot be evaluated to integer" << endl;
        }  
    }
#line 4077 "miniC.tab.c" /* yacc.c:1646  */
    break;


#line 4081 "miniC.tab.c" /* yacc.c:1646  */
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
#line 2274 "miniC.y" /* yacc.c:1906  */


void yyerror(const char *s)
{      
    errFnd=1;
    fprintf (stderr, "%s\n", s);
}

int main(int argc, char **argv)
{
    nxtqd = 0;
    sc = 0;
    fnd = 0;
    ofc = 0;
    errFnd=false;
    sthVar.clear();
    dl.clear();
    
    yyparse();
    populateOffsets(functionEntryRec, gloVars);
    ofstream outinter;
    outinter.open("./output/intermediate.txt");
    if(!errFnd){
        for(auto it:funcInstr){
            outinter<<it<<endl;
        }
        cout << BOLD(FGRN("Intermediate Code Generated")) << endl;
    } else {
        cout << BOLD(FRED("Exited without intermediate code generation")) << endl;
    }
    outinter.close();
}
