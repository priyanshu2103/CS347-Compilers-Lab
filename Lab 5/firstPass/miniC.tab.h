/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 39 "miniC.y" /* yacc.c:1909  */

    #include "codegenHelpers.h"

#line 48 "miniC.tab.h" /* yacc.c:1909  */

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
#line 43 "miniC.y" /* yacc.c:1909  */

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

#line 136 "miniC.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINIC_TAB_H_INCLUDED  */
