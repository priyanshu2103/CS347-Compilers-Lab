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

#ifndef YY_YY_C_COMP_TAB_H_INCLUDED
# define YY_YY_C_COMP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 40 "c_comp.y" /* yacc.c:1909  */

  #include "helper.h"

#line 48 "c_comp.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PLUS = 258,
    MINUS = 259,
    MULT = 260,
    DIV = 261,
    MOD = 262,
    LE = 263,
    GE = 264,
    EQ = 265,
    NEQ = 266,
    LT = 267,
    GT = 268,
    AND = 269,
    OR = 270,
    EXCL = 271,
    COMMA = 272,
    COL = 273,
    SEMI = 274,
    LC = 275,
    RC = 276,
    LP = 277,
    RP = 278,
    VOID = 279,
    INT_DECL = 280,
    FLOAT_DECL = 281,
    ID = 282,
    INT = 283,
    FLOAT = 284,
    IF = 285,
    ELSE = 286,
    SWITCH = 287,
    CASE = 288,
    FOR = 289,
    WHILE = 290,
    BREAK = 291,
    DEFAULT = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "c_comp.y" /* yacc.c:1909  */
int ival ; float fval; char * str; struct s{int id_type; char *id_name; int i_val; float f_val;} id_attributes; struct func_call_details * f_attributes;

#line 101 "c_comp.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_COMP_TAB_H_INCLUDED  */
