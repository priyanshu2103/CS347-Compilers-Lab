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


#include <cstdio>
#include <cstdlib>
#include <vector>
#include "c_comp.tab.h"

using namespace std;

extern int yylex(void);
extern void yyterminate();
void yyerror(const char *s);
int eval_int_func(char *f_name);
float eval_float_func(char *f_name);
void eval_void_func(char *f_name);
func_call_details * get_func_details(char *);
void eval_func();

typedef struct func_arg
{
  char *arg_name;
  int arg_type;
  int i_val;
  float f_val;
} func_arg;

typedef struct func_call_details
{
  int f_type;
  char *f_name;
  int i_val;
  float f_val;
  int n_args;
  vector <func_arg *> args;
} func_call_details;

vector <func_call_details *> func_list;

int arg_no;
int check_arg_no;
vector <func_arg *> func_arg_list;
// the above 3 won't work in multiple func calls, need to keep a stack of these as well
// need to add print statement to see results

stack <func_call_details *> func_stack;
func_call_details *fc_temp;
int decl_type_check;
// f_type 0 void 1 int 2 float

#line 116 "c_comp.tab.c" /* yacc.c:339  */

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

union YYSTYPE
{
#line 51 "c_comp.y" /* yacc.c:355  */
int ival ; float fval; char * str; struct s{int id_type; char *id_name; int i_val; float f_val;} id_attributes; func_call_details * f_attributes;

#line 196 "c_comp.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_COMP_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "c_comp.tab.c" /* yacc.c:358  */

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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

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
       0,   100,   100,   100,   101,   101,   103,   103,   103,   103,
     103,   103,   104,   104,   106,   106,   106,   106,   108,   108,
     109,   109,   110,   110,   110,   110,   110,   110,   112,   114,
     114,   114,   114,   115,   115,   115,   115,   115,   115,   117,
     117,   118,   118,   118,   119,   120,   121,   123,   123,   124,
     124,   125,   125,   126,   126,   126,   127,   127,   127,   127,
     129,   129,   132,   132,   135,   135,   138,   138,   141,   141,
     144,   144,   147,   147,   147,   148,   148,   150,   150,   161,
     161,   163,   163,   165,   165,   165,   165,   165,   165,   166,
     168,   168,   170,   170,   171,   171,   171,   171,   172,   172,
     172,   172,   173,   173,   173,   174,   174,   176,   176,   177,
     178,   178,   178,   179,   179,   180,   180,   182,   182
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
  "var_decl", "$@1", "$@2", "id_list", "assign", "id_assign_list", "arith",
  "arith_expr", "arith_arg", "func_call", "@3", "call_arg_list",
  "call_arg", "func_decl", "@4", "@5", "@6", "decl_arg_list", "decl_arg",
  "func_def", "@7", "@8", "@9", "@10", "@11", "@12", "def_arg_list",
  "def_arg", "body", "cond", "and_expr", "expr", "switch_case", "cases",
  "case", "default", "break", "for_loop", "for_expr", "for_first",
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

#define YYPACT_NINF -209

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-209)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     209,    74,   -24,     6,    17,    18,  -209,  -209,     5,    29,
      31,    79,   209,  -209,  -209,  -209,  -209,    56,   297,    67,
    -209,  -209,  -209,  -209,  -209,    61,  -209,  -209,  -209,    68,
    -209,    68,    95,   100,   110,    34,   113,  -209,  -209,  -209,
      74,    74,    74,    74,  -209,  -209,   109,   114,   123,   125,
     128,   132,   122,  -209,    46,   135,   143,   146,  -209,   134,
     147,   152,  -209,  -209,  -209,  -209,   158,   113,   113,   287,
     169,   159,   189,  -209,   297,   297,   297,   297,    -4,    63,
      63,    -4,    63,    63,   187,    68,  -209,    -4,    63,    63,
    -209,  -209,  -209,   202,   211,   206,   199,    42,   221,   212,
    -209,    74,    74,   241,    74,    74,    74,    65,   113,   113,
     226,   229,   235,   247,   249,   265,   268,   262,   286,   288,
     289,   290,   300,  -209,  -209,   291,   292,   293,  -209,   134,
     199,    14,   296,   -13,   220,  -209,  -209,   308,  -209,    16,
     111,    74,   129,   246,   252,   220,  -209,  -209,  -209,  -209,
    -209,   301,    -4,  -209,  -209,   220,    63,   299,   302,   220,
     303,   256,   305,   220,   306,  -209,   304,    76,   309,   310,
    -209,   311,  -209,  -209,   220,   312,   187,   258,   313,  -209,
    -209,  -209,  -209,   220,  -209,  -209,   220,   240,   251,   263,
    -209,   270,   271,  -209,  -209,   220,  -209,   307,   314,   151,
     162,   173,  -209,  -209,  -209,  -209,   315,   317,   318,   322,
     323,   220,   295,   220,   295,   220,   295,  -209,  -209,  -209,
     184,   195,   321,   316,  -209,   324,  -209,   325,  -209,   220,
     295,   220,   295,   295,  -209,   295,   295,   326,  -209,   327,
    -209,  -209,  -209,  -209,   295,   295,  -209,  -209
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    33,    34,    35,     0,     0,
       0,     0,     2,     4,     5,     6,     7,    36,     0,    37,
      12,    13,     9,    10,    11,    36,    37,    47,    49,     0,
      51,     0,     0,     0,     0,   110,     0,     1,     3,    28,
       0,     0,     0,     0,     8,    38,     0,     0,     0,     0,
       0,     0,    20,    15,     0,     0,     0,     0,    17,    41,
       0,     0,    14,    16,   111,   112,     0,   113,     0,    36,
       0,    79,    81,    36,    29,    30,    31,    32,    53,    72,
      72,    53,    72,    72,     0,     0,    18,    53,    72,    72,
      44,    45,    46,     0,    42,     0,     0,     0,     0,   115,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,     0,    54,     0,     0,     0,    73,     0,     0,
       0,     0,    22,    21,    19,     0,     0,     0,    40,    41,
       0,     0,     0,   102,     0,   107,   114,     0,   109,    36,
      36,     0,    36,    36,    36,     0,   117,    80,    82,    58,
      59,     0,    53,    75,    76,     0,    72,     0,     0,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
      90,     0,    93,    92,    77,     0,     0,    36,     0,    48,
      55,    61,    74,     0,    50,    65,     0,    33,    34,    35,
      27,    36,    37,    52,    69,     0,    91,     0,     0,     0,
       0,     0,    78,   108,   116,   118,     0,     0,     0,     0,
       0,     0,   105,     0,   105,     0,   105,    63,    67,    71,
       0,     0,     0,     0,    94,     0,    98,     0,   103,     0,
     105,     0,   105,   105,   106,   105,   105,     0,    96,     0,
     100,    95,    99,   104,   105,   105,    97,   101
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -209,   319,  -209,     0,  -209,   320,  -209,  -209,   -20,  -209,
    -143,  -209,     4,   264,    13,  -209,   192,  -209,  -209,  -209,
    -209,  -209,   -74,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,   -79,  -209,   -63,   -51,   233,  -209,  -209,   -82,  -209,
    -209,  -208,  -209,  -209,  -209,  -209,  -209,  -209
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,   174,    14,    15,    29,    31,    53,    54,
     123,    16,    17,    18,    19,    32,    93,    94,    20,    46,
      49,    55,   112,   113,    21,    47,    48,    50,    51,    56,
      57,   116,   117,   175,    70,    71,    72,    22,   132,   133,
     173,   224,    23,    66,    67,    99,   138,    24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,   118,    27,   120,   121,    25,   226,   119,   228,   126,
     127,    58,    13,   125,    26,    65,    98,   100,   190,   131,
     110,   111,   238,   171,   240,   241,    33,   242,   243,   -85,
     -85,    34,    28,   204,   -85,   167,   246,   247,   -85,   -39,
      69,   168,   169,    30,    73,    73,    73,    73,   166,    26,
      35,   172,    36,    26,    26,    26,    26,   147,    62,    63,
      52,   134,    85,     1,    86,   124,    62,    63,     5,     6,
       7,    69,    69,     8,    39,     9,    10,   182,   180,    37,
      26,    26,   178,    45,   145,    44,     1,   114,   115,    62,
      63,     5,     6,     7,    52,     1,     8,   135,     9,    10,
       5,     6,     7,   197,   198,   139,   140,   146,   142,   143,
     144,   202,    69,    69,    26,    26,    59,    26,    26,    26,
     206,    26,    26,   207,   -86,   -86,    60,    61,    68,   -86,
      78,    84,   208,   -86,     1,    79,   212,   214,   216,     5,
       6,     7,   -88,   -88,    80,   177,    81,   -88,   222,    82,
     225,   -88,   227,    83,    26,   181,    87,   230,   232,   185,
      90,    91,    92,   194,    88,   191,   237,    89,   239,    95,
     211,    96,     1,   108,   192,    62,    63,     5,     6,     7,
      97,   213,     8,     1,     9,    10,    62,    63,     5,     6,
       7,   107,   215,     8,     1,     9,    10,    62,    63,     5,
       6,     7,   109,   229,     8,     1,     9,    10,    62,    63,
       5,     6,     7,   122,   231,     8,     1,     9,    10,    62,
      63,     5,     6,     7,   128,   130,     8,   129,     9,    10,
       1,   131,     2,     3,     4,     5,     6,     7,   137,   136,
       8,     1,     9,    10,    62,    63,     5,     6,     7,   161,
     141,     8,   149,     9,    10,   150,   -22,   151,   -22,   -83,
     -83,   -39,   -22,   152,   -83,   -84,   -84,   -23,   -83,   -23,
     -84,   -87,   -87,   -23,   -84,   153,   -87,     1,   156,   -24,
     -87,   -24,   187,   188,   189,   -24,   -25,   -26,   -25,   -26,
     155,   154,   -25,   -26,   101,   102,   103,   104,   105,   106,
      40,    41,    42,    43,    74,    75,    76,    77,   157,   161,
     158,   159,   160,   162,   163,   164,   170,   176,   183,   179,
     184,   165,   186,   193,   196,   195,   199,   200,   201,   209,
     223,    38,   203,   205,   234,   217,   210,   218,   219,   220,
     221,   233,   148,     0,   235,   236,   244,   245,     0,     0,
       0,     0,     0,     0,     0,    64
};

static const yytype_int16 yycheck[] =
{
       0,    80,    26,    82,    83,     1,   214,    81,   216,    88,
      89,    31,    12,    87,     1,    35,    67,    68,   161,    32,
      24,    25,   230,    36,   232,   233,    21,   235,   236,    13,
      14,    26,    26,   176,    18,    21,   244,   245,    22,    21,
      36,    27,    28,    26,    40,    41,    42,    43,   130,    36,
      21,   133,    21,    40,    41,    42,    43,   108,    24,    25,
      26,    19,    16,    21,    18,    85,    24,    25,    26,    27,
      28,    67,    68,    31,    18,    33,    34,   156,   152,     0,
      67,    68,   145,    22,    19,    18,    21,    24,    25,    24,
      25,    26,    27,    28,    26,    21,    31,    97,    33,    34,
      26,    27,    28,    27,    28,   101,   102,   107,   104,   105,
     106,   174,   108,   109,   101,   102,    21,   104,   105,   106,
     183,   108,   109,   186,    13,    14,    26,    17,    15,    18,
      21,     9,   195,    22,    21,    21,   199,   200,   201,    26,
      27,    28,    13,    14,    21,   141,    21,    18,   211,    21,
     213,    22,   215,    21,   141,   155,    21,   220,   221,   159,
      26,    27,    28,   163,    21,   161,   229,    21,   231,    22,
      19,    19,    21,    14,   161,    24,    25,    26,    27,    28,
      22,    19,    31,    21,    33,    34,    24,    25,    26,    27,
      28,    22,    19,    31,    21,    33,    34,    24,    25,    26,
      27,    28,    13,    19,    31,    21,    33,    34,    24,    25,
      26,    27,    28,    26,    19,    31,    21,    33,    34,    24,
      25,    26,    27,    28,    22,    19,    31,    16,    33,    34,
      21,    32,    23,    24,    25,    26,    27,    28,    26,    18,
      31,    21,    33,    34,    24,    25,    26,    27,    28,     9,
       9,    31,    26,    33,    34,    26,    16,    22,    18,    13,
      14,    21,    22,    16,    18,    13,    14,    16,    22,    18,
      18,    13,    14,    22,    22,    26,    18,    21,    16,    16,
      22,    18,    26,    27,    28,    22,    16,    16,    18,    18,
      22,    26,    22,    22,     7,     8,     9,    10,    11,    12,
       3,     4,     5,     6,    40,    41,    42,    43,    22,     9,
      22,    22,    22,    22,    22,    22,    20,     9,    19,    18,
      18,   129,    19,    18,    20,    19,    17,    17,    17,    22,
      35,    12,    20,    20,    18,    20,    22,    20,    20,    17,
      17,    20,   109,    -1,    20,    20,    20,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    23,    24,    25,    26,    27,    28,    31,    33,
      34,    38,    39,    40,    41,    42,    48,    49,    50,    51,
      55,    61,    74,    79,    84,    49,    51,    26,    26,    43,
      26,    44,    52,    21,    26,    21,    21,     0,    38,    18,
       3,     4,     5,     6,    18,    22,    56,    62,    63,    57,
      64,    65,    26,    45,    46,    58,    66,    67,    45,    21,
      26,    17,    24,    25,    42,    45,    80,    81,    15,    49,
      71,    72,    73,    49,    50,    50,    50,    50,    21,    21,
      21,    21,    21,    21,     9,    16,    18,    21,    21,    21,
      26,    27,    28,    53,    54,    22,    19,    22,    71,    82,
      71,     7,     8,     9,    10,    11,    12,    22,    14,    13,
      24,    25,    59,    60,    24,    25,    68,    69,    68,    59,
      68,    68,    26,    47,    45,    59,    68,    68,    22,    16,
      19,    32,    75,    76,    19,    40,    18,    26,    83,    49,
      49,     9,    49,    49,    49,    19,    40,    71,    72,    26,
      26,    22,    16,    26,    26,    22,    16,    22,    22,    22,
      22,     9,    22,    22,    22,    53,    75,    21,    27,    28,
      20,    36,    75,    77,    40,    70,     9,    49,    70,    18,
      59,    40,    68,    19,    18,    40,    19,    26,    27,    28,
      47,    49,    51,    18,    40,    19,    20,    27,    28,    17,
      17,    17,    70,    20,    47,    20,    70,    70,    70,    22,
      22,    19,    70,    19,    70,    19,    70,    20,    20,    20,
      17,    17,    70,    35,    78,    70,    78,    70,    78,    19,
      70,    19,    70,    20,    18,    20,    20,    70,    78,    70,
      78,    78,    78,    78,    20,    20,    78,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    40,    40,    40,
      40,    40,    41,    41,    43,    42,    44,    42,    45,    45,
      46,    46,    47,    47,    47,    47,    47,    47,    48,    49,
      49,    49,    49,    50,    50,    50,    50,    50,    50,    52,
      51,    53,    53,    53,    54,    54,    54,    56,    55,    57,
      55,    58,    55,    59,    59,    59,    60,    60,    60,    60,
      62,    61,    63,    61,    64,    61,    65,    61,    66,    61,
      67,    61,    68,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    77,    78,    78,    79,    79,    80,
      81,    81,    81,    82,    82,    83,    83,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     0,     3,     0,     3,     2,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     3,     0,
       5,     0,     1,     3,     1,     1,     1,     0,     7,     0,
       7,     0,     7,     0,     1,     3,     1,     1,     2,     2,
       0,     7,     0,     9,     0,     7,     0,     9,     0,     7,
       0,     9,     0,     1,     3,     2,     2,     1,     2,     1,
       3,     1,     3,     3,     3,     3,     3,     4,     3,     2,
       6,     7,     2,     2,     5,     7,     7,     9,     5,     7,
       7,     9,     0,     4,     6,     0,     2,     5,     7,     3,
       0,     1,     1,     0,     2,     0,     3,     5,     7
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
        case 14:
#line 106 "c_comp.y" /* yacc.c:1646  */
    {decl_type_check=1;}
#line 1478 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 106 "c_comp.y" /* yacc.c:1646  */
    {decl_type_check=2;}
#line 1484 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 108 "c_comp.y" /* yacc.c:1646  */
    {if((yyvsp[-1].id_attributes).id_type!=decl_type_check) {cout<<"typE mismatch\n"; exit(0);}}
#line 1490 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 108 "c_comp.y" /* yacc.c:1646  */
    {if((yyvsp[-2].id_attributes).id_type!=decl_type_check) {cout<<"typE mismatch\n"; exit(0);}}
#line 1496 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 109 "c_comp.y" /* yacc.c:1646  */
    {(yyval.id_attributes).id_type = (yyvsp[0].id_attributes).id_type = decl_type_check;}
#line 1502 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 109 "c_comp.y" /* yacc.c:1646  */
    {(yyvsp[-2].id_attributes).id_type=decl_type_check; if((yyvsp[-2].id_attributes).id_type!=(yyvsp[0].id_attributes).id_type) {cout<<"tYPe mismatch\n"; exit(0);} (yyval.id_attributes).id_type = (yyvsp[-2].id_attributes).id_type; if((yyvsp[-2].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[-2].id_attributes).i_val=(yyvsp[0].id_attributes).i_val;} else {(yyval.id_attributes).f_val=(yyvsp[-2].id_attributes).f_val=(yyvsp[0].id_attributes).f_val;}}
#line 1508 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 110 "c_comp.y" /* yacc.c:1646  */
    {(yyval.id_attributes).id_type = (yyvsp[0].id_attributes).id_type; if((yyvsp[0].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[0].id_attributes).i_val;} else {(yyval.id_attributes).f_val=(yyvsp[0].id_attributes).f_val;}}
#line 1514 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 110 "c_comp.y" /* yacc.c:1646  */
    {if((yyvsp[-2].id_attributes).id_type!=1) {cout<<"TYpe mismatch\n"; exit(0);} (yyvsp[-2].id_attributes).i_val=(yyvsp[0].ival); (yyval.id_attributes).id_type=1; (yyval.id_attributes).i_val=(yyvsp[-2].id_attributes).i_val;}
#line 1520 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 110 "c_comp.y" /* yacc.c:1646  */
    {if((yyvsp[-2].id_attributes).id_type!=2) {cout<<"TYpe mismatch\n"; exit(0);} (yyvsp[-2].id_attributes).f_val=(yyvsp[0].fval); (yyval.id_attributes).id_type=2; (yyval.id_attributes).f_val=(yyvsp[-2].id_attributes).f_val;}
#line 1526 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 110 "c_comp.y" /* yacc.c:1646  */
    {if((yyvsp[-2].id_attributes).id_type!=(yyvsp[0].id_attributes).id_type) {cout<<"tyPe mismatch\n"; exit(0);} (yyval.id_attributes).id_type=(yyvsp[-2].id_attributes).id_type; if((yyvsp[-2].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[-2].id_attributes).i_val=(yyvsp[0].id_attributes).i_val;} else {(yyval.id_attributes).f_val=(yyvsp[-2].id_attributes).f_val=(yyvsp[0].id_attributes).f_val;}}
#line 1532 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 110 "c_comp.y" /* yacc.c:1646  */
    {if((yyvsp[-2].id_attributes).id_type!=(yyvsp[0].f_attributes)->f_type) {cout<<"tyPe mismatch\n"; exit(0);} (yyval.id_attributes).id_type=(yyvsp[-2].id_attributes).id_type; if((yyvsp[-2].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[-2].id_attributes).i_val=(yyvsp[0].f_attributes)->i_val;} else {(yyval.id_attributes).f_val=(yyvsp[-2].id_attributes).f_val=(yyvsp[0].f_attributes)->f_val;}}
#line 1538 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 110 "c_comp.y" /* yacc.c:1646  */
    {if((yyvsp[-2].id_attributes).id_type!=(yyvsp[0].id_attributes).id_type) {cout<<"tyPe mismatch\n"; exit(0);} (yyval.id_attributes).id_type=(yyvsp[-2].id_attributes).id_type; if((yyvsp[-2].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[-2].id_attributes).i_val=(yyvsp[0].id_attributes).i_val;} else {(yyval.id_attributes).f_val=(yyvsp[-2].id_attributes).f_val=(yyvsp[0].id_attributes).f_val;}}
#line 1544 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 114 "c_comp.y" /* yacc.c:1646  */
    {if((yyvsp[-2].id_attributes).id_type!=(yyvsp[0].id_attributes).id_type) {cout<<"Type mismatch\n"; exit(0);} if((yyvsp[-2].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[-2].id_attributes).i_val + (yyvsp[0].id_attributes).i_val;} else {(yyval.id_attributes).f_val=(yyvsp[-2].id_attributes).f_val + (yyvsp[0].id_attributes).f_val;}}
#line 1550 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 114 "c_comp.y" /* yacc.c:1646  */
    {if((yyvsp[-2].id_attributes).id_type!=(yyvsp[0].id_attributes).id_type) {cout<<"Type mismatch\n"; exit(0);} if((yyvsp[-2].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[-2].id_attributes).i_val + (yyvsp[0].id_attributes).i_val;} else {(yyval.id_attributes).f_val=(yyvsp[-2].id_attributes).f_val + (yyvsp[0].id_attributes).f_val;}}
#line 1556 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 114 "c_comp.y" /* yacc.c:1646  */
    {if((yyvsp[-2].id_attributes).id_type!=(yyvsp[0].id_attributes).id_type) {cout<<"Type mismatch\n"; exit(0);} if((yyvsp[-2].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[-2].id_attributes).i_val + (yyvsp[0].id_attributes).i_val;} else {(yyval.id_attributes).f_val=(yyvsp[-2].id_attributes).f_val + (yyvsp[0].id_attributes).f_val;}}
#line 1562 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 114 "c_comp.y" /* yacc.c:1646  */
    {if((yyvsp[-2].id_attributes).id_type!=(yyvsp[0].id_attributes).id_type) {cout<<"Type mismatch\n"; exit(0);} if((yyvsp[-2].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[-2].id_attributes).i_val + (yyvsp[0].id_attributes).i_val;} else {(yyval.id_attributes).f_val=(yyvsp[-2].id_attributes).f_val + (yyvsp[0].id_attributes).f_val;}}
#line 1568 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 115 "c_comp.y" /* yacc.c:1646  */
    {(yyval.id_attributes).id_type=(yyvsp[0].id_attributes).id_type; if((yyvsp[0].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[0].id_attributes).i_val;} else {(yyval.id_attributes).f_val=(yyvsp[0].id_attributes).f_val;}}
#line 1574 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 115 "c_comp.y" /* yacc.c:1646  */
    {(yyval.id_attributes).id_type=1; (yyval.id_attributes).i_val=(yyvsp[0].ival);}
#line 1580 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 115 "c_comp.y" /* yacc.c:1646  */
    {(yyval.id_attributes).id_type=2; (yyval.id_attributes).f_val=(yyvsp[0].fval);}
#line 1586 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 115 "c_comp.y" /* yacc.c:1646  */
    {(yyval.id_attributes).id_type=(yyvsp[0].id_attributes).id_type; if((yyvsp[0].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[0].id_attributes).i_val;} else {(yyval.id_attributes).f_val=(yyvsp[0].id_attributes).f_val;}}
#line 1592 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 115 "c_comp.y" /* yacc.c:1646  */
    {(yyval.id_attributes).id_type=(yyvsp[0].f_attributes)->f_type; if((yyval.id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[0].f_attributes)->i_val;} else {(yyval.id_attributes).f_val=(yyvsp[0].f_attributes)->f_val;}}
#line 1598 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 115 "c_comp.y" /* yacc.c:1646  */
    {(yyval.id_attributes).id_type = (yyvsp[-1].id_attributes).id_type; if((yyvsp[-1].id_attributes).id_type==1) {(yyval.id_attributes).i_val=(yyvsp[-1].id_attributes).i_val;} else {(yyval.id_attributes).f_val=(yyvsp[-1].id_attributes).f_val;}}
#line 1604 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 117 "c_comp.y" /* yacc.c:1646  */
    {func_call_details * fc= get_func_details((yyvsp[0].id_attributes).id_name); arg_no= fc->n_args; func_arg_list= fc->args; check_arg_no=0; (yyval.f_attributes)->f_type=fc->f_type;}
#line 1610 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 117 "c_comp.y" /* yacc.c:1646  */
    {if((yyval.f_attributes)->f_type==1) {(yyval.f_attributes)->i_val = eval_int_func((yyvsp[-4].id_attributes).id_name)} else if((yyval.f_attributes)->f_type==2) {(yyval.f_attributes)->f_val = eval_float_func((yyvsp[-4].id_attributes).id_name)} else {eval_void_func((yyvsp[-4].id_attributes).id_name)}}
#line 1616 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 119 "c_comp.y" /* yacc.c:1646  */
    {if(check_arg_no >= arg_no) {cout<<"no of args error\n"; exit(0);} func_arg * fa=func_arg_list[check_arg_no]; check_arg_no++; if(fa->arg_type != (yyvsp[0].id_attributes).id_type) {cout<<"type mismatch while calling\n"; exit(0);} if(fa->arg_type==1) {fa->i_val=(yyvsp[0].id_attributes).i_val;} else {fa->f_val=(yyvsp[0].id_attributes).f_val;}}
#line 1622 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 120 "c_comp.y" /* yacc.c:1646  */
    {if(check_arg_no >= arg_no) {cout<<"no of args error\n"; exit(0);} func_arg * fa=func_arg_list[check_arg_no]; check_arg_no++; if(fa->arg_type != 1) {cout<<"type mismatch while calling\n"; exit(0);} fa->i_val=(yyvsp[0].ival);}
#line 1628 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 121 "c_comp.y" /* yacc.c:1646  */
    {if(check_arg_no >= arg_no) {cout<<"no of args error\n"; exit(0);} func_arg * fa=func_arg_list[check_arg_no]; check_arg_no++; if(fa->arg_type != 2) {cout<<"type mismatch while calling\n"; exit(0);} fa->f_val=(yyvsp[0].fval);}
#line 1634 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 123 "c_comp.y" /* yacc.c:1646  */
    {func_call_details * fc= get_func_details((yyvsp[0].id_attributes).id_name); if(fc) {cout<<"func already exists\n"; exit(0);} fc=new func_call_details(); fc->f_type=0; fc->f_name=(yyvsp[0].id_attributes).id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; (yyval.f_attributes)=fc;}
#line 1640 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 123 "c_comp.y" /* yacc.c:1646  */
    {(yyval.f_attributes)->args=func_arg_list; (yyval.f_attributes)->n_args=arg_no; func_list.push_back((yyval.f_attributes));}
#line 1646 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 124 "c_comp.y" /* yacc.c:1646  */
    {func_call_details * fc= get_func_details((yyvsp[0].id_attributes).id_name); if(fc) {cout<<"func already exists\n"; exit(0);} fc=new func_call_details(); fc->f_type=1; fc->f_name=(yyvsp[0].id_attributes).id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; (yyval.f_attributes)=fc;}
#line 1652 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 124 "c_comp.y" /* yacc.c:1646  */
    {(yyval.f_attributes)->args=func_arg_list; (yyval.f_attributes)->n_args=arg_no; func_list.push_back((yyval.f_attributes));}
#line 1658 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 125 "c_comp.y" /* yacc.c:1646  */
    {func_call_details * fc= get_func_details((yyvsp[0].id_attributes).id_name); if(fc) {cout<<"func already exists\n"; exit(0);} fc=new func_call_details(); fc->f_type=2; fc->f_name=(yyvsp[0].id_attributes).id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; (yyval.f_attributes)=fc;}
#line 1664 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 125 "c_comp.y" /* yacc.c:1646  */
    {(yyval.f_attributes)->args=func_arg_list; (yyval.f_attributes)->n_args=arg_no; func_list.push_back((yyval.f_attributes));}
#line 1670 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 127 "c_comp.y" /* yacc.c:1646  */
    {func_arg * fa=new func_arg(); fa->arg_type=1; func_arg_list[arg_no++]= fa;}
#line 1676 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 127 "c_comp.y" /* yacc.c:1646  */
    {func_arg * fa=new func_arg(); fa->arg_type=2; func_arg_list[arg_no++]= fa;}
#line 1682 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 127 "c_comp.y" /* yacc.c:1646  */
    {func_arg * fa=new func_arg(); fa->arg_type=1; func_arg_list[arg_no++]= fa;}
#line 1688 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 127 "c_comp.y" /* yacc.c:1646  */
    {func_arg * fa=new func_arg(); fa->arg_type=2; func_arg_list[arg_no++]= fa;}
#line 1694 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 129 "c_comp.y" /* yacc.c:1646  */
    {func_call_details * fc=new func_call_details(); fc->f_type=0; fc->f_name=(yyvsp[0].id_attributes).id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; (yyval.f_attributes)=fc;}
#line 1700 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 130 "c_comp.y" /* yacc.c:1646  */
    {(yyval.f_attributes)->args=func_arg_list; (yyval.f_attributes)->n_args=arg_no; func_call_details *fc1= get_func_details((yyval.f_attributes)->f_name); if(fc1) {if(fc1->f_type != (yyval.f_attributes)->f_type || fc1->n_args !=(yyval.f_attributes)->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=(yyval.f_attributes)->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back((yyval.f_attributes));}
#line 1706 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 132 "c_comp.y" /* yacc.c:1646  */
    {func_call_details * fc=new func_call_details(); fc->f_type=0; fc->f_name=(yyvsp[0].id_attributes).id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; (yyval.f_attributes)=fc;}
#line 1712 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 133 "c_comp.y" /* yacc.c:1646  */
    {(yyval.f_attributes)->args=func_arg_list; (yyval.f_attributes)->n_args=arg_no; func_call_details *fc1= get_func_details((yyval.f_attributes)->f_name); if(fc1) {if(fc1->f_type != (yyval.f_attributes)->f_type || fc1->n_args !=(yyval.f_attributes)->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=(yyval.f_attributes)->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back((yyval.f_attributes));}
#line 1718 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 135 "c_comp.y" /* yacc.c:1646  */
    {func_call_details * fc=new func_call_details(); fc->f_type=1; fc->f_name=(yyvsp[0].id_attributes).id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; (yyval.f_attributes)=fc;}
#line 1724 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 136 "c_comp.y" /* yacc.c:1646  */
    {(yyval.f_attributes)->args=func_arg_list; (yyval.f_attributes)->n_args=arg_no; func_call_details *fc1= get_func_details((yyval.f_attributes)->f_name); if(fc1) {if(fc1->f_type != (yyval.f_attributes)->f_type || fc1->n_args !=(yyval.f_attributes)->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=(yyval.f_attributes)->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back((yyval.f_attributes));}
#line 1730 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 138 "c_comp.y" /* yacc.c:1646  */
    {func_call_details * fc=new func_call_details(); fc->f_type=1; fc->f_name=(yyvsp[0].id_attributes).id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; (yyval.f_attributes)=fc;}
#line 1736 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 139 "c_comp.y" /* yacc.c:1646  */
    {(yyval.f_attributes)->args=func_arg_list; (yyval.f_attributes)->n_args=arg_no; func_call_details *fc1= get_func_details((yyval.f_attributes)->f_name); if(fc1) {if(fc1->f_type != (yyval.f_attributes)->f_type || fc1->n_args !=(yyval.f_attributes)->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=(yyval.f_attributes)->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back((yyval.f_attributes));}
#line 1742 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 141 "c_comp.y" /* yacc.c:1646  */
    {func_call_details * fc=new func_call_details(); fc->f_type=2; fc->f_name=(yyvsp[0].id_attributes).id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; (yyval.f_attributes)=fc;}
#line 1748 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 142 "c_comp.y" /* yacc.c:1646  */
    {(yyval.f_attributes)->args=func_arg_list; (yyval.f_attributes)->n_args=arg_no; func_call_details *fc1= get_func_details((yyval.f_attributes)->f_name); if(fc1) {if(fc1->f_type != (yyval.f_attributes)->f_type || fc1->n_args !=(yyval.f_attributes)->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=(yyval.f_attributes)->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back((yyval.f_attributes));}
#line 1754 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 144 "c_comp.y" /* yacc.c:1646  */
    {func_call_details * fc=new func_call_details(); fc->f_type=2; fc->f_name=(yyvsp[0].id_attributes).id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; (yyval.f_attributes)=fc;}
#line 1760 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 145 "c_comp.y" /* yacc.c:1646  */
    {(yyval.f_attributes)->args=func_arg_list; (yyval.f_attributes)->n_args=arg_no; func_call_details *fc1= get_func_details((yyval.f_attributes)->f_name); if(fc1) {if(fc1->f_type != (yyval.f_attributes)->f_type || fc1->n_args !=(yyval.f_attributes)->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=(yyval.f_attributes)->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back((yyval.f_attributes));}
#line 1766 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 148 "c_comp.y" /* yacc.c:1646  */
    {func_arg * fa=new func_arg(); fa->arg_type=1; fa->arg_name=(yyvsp[0].id_attributes).id_name; func_arg_list[arg_no++]= fa;}
#line 1772 "c_comp.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 148 "c_comp.y" /* yacc.c:1646  */
    {func_arg * fa=new func_arg(); fa->arg_type=2; fa->arg_name=(yyvsp[0].id_attributes).id_name; func_arg_list[arg_no++]= fa;}
#line 1778 "c_comp.tab.c" /* yacc.c:1646  */
    break;


#line 1782 "c_comp.tab.c" /* yacc.c:1646  */
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
#line 184 "c_comp.y" /* yacc.c:1906  */



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

bool search(char *f_name)
{

}

int eval_int_func(char *f_name)
{

}

float eval_float_func(char *f_name)
{

}

void eval_void_func(char *f_name)
{

}

func_call_details * get_func_details(char *f_name)
{
  // first find if func exists it should return
  func_call_details *fc;
  return fc;
  // or return null

}

void eval_func()
{

}
