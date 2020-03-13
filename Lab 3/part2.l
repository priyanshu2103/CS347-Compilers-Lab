/* Declaring two counters one for number
of lines other for number of characters */
%{
#include<stdlib.h>
#include<string.h>
#include "part2.tab.h"
%}

b   [ ]*

%option noyywrap

%%

{b}"SELECT"|"select"{b}                           {printf("<%s> ",yytext ); return SELECT;}
{b}"PROJECT"|"project"{b}                         {printf("<%s> ",yytext ); return PROJECT;}
{b}"CARTESIAN_PRODUCT"|"cartesian_project"{b}     {printf("<%s> ",yytext ); return CARTESIAN_PRODUCT;}
{b}"EQUI_JOIN"|"equi_join"{b}                     {printf("<%s> ",yytext );	return EQUI_JOIN;}
{b}"<="|">="|"="|"<>"{b}                {printf("<%s> ",yytext ); return OPER;}
{b}"<"{b}               											 {printf("<%s> ",yytext ); return LT;}
{b}">"{b}               											 {printf("<%s> ",yytext ); return GT;}

{b}"AND"|"and"|"OR"|"or"{b}                   {printf("<%s> ",yytext ); return LOG;}
{b}"not"|"NOT"{b}                   					{printf("<%s> ",yytext ); return NOT;}

{b}","{b}                                       {printf("<%s> ",yytext ); return COMMA;}
{b}"\."{b}                                      {printf("<%s> ",yytext ); return DOT;}
{b}"("{b}                                       {printf("<%s> ",yytext ); return LP;}
{b}")"{b}                                       {printf("<%s> ",yytext ); return RP;}
{b}[A-Za-z_][0-9A-Za-z_]*{b}                    {printf("<%s> ",yytext ); return ID; }
{b}[0-9]+{b}                                    {printf("<%s> ",yytext ); return INT; }
{b}"'"{b}																			{printf("<%s> ",yytext ); return QUOTE;}
%%
