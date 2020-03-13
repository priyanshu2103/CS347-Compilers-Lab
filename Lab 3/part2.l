/* Declaring two counters one for number
of lines other for number of characters */
%{
#include<stdlib.h>
#include<string.h>
#include "part2.tab.h"
extern int ln;
%}

b   [ ]*

%option noyywrap

%%

{b}"SELECT"{b}|{b}"select"{b}                           {return SELECT;}
{b}"PROJECT"{b}|{b}"project"{b}                         {return PROJECT;}
{b}"CARTESIAN_PRODUCT"{b}|{b}"cartesian_project"{b}     {return CARTESIAN_PRODUCT;}
{b}"EQUI_JOIN"{b}|{b}"equi_join"{b}                     {return EQUI_JOIN;}
{b}"<="{b}|{b}">="{b}|{b}"="{b}|{b}"<>"{b}              {return OPER;}
{b}"<"{b}               											 					{return LT;}
{b}">"{b}               											 					{return GT;}
{b}"AND"{b}|{b}"and"{b}|{b}"OR"{b}|{b}"or"{b}           {return LOG;}
{b}"not"{b}|{b}"NOT"{b}                   							{return NOT;}
{b}","{b}                                    				  	{return COMMA;}
{b}"\."{b}                                      				{return DOT;}
{b}"("{b}                                       				{return LP;}
{b}")"{b}                                       				{return RP;}
{b}[A-Za-z_][0-9A-Za-z_]*{b}                    				{return ID; }
{b}[0-9]+{b}                                    				{return INT; }
{b}"'"{b}																		 						{return QUOTE;}
{b}\n{b} 																								{ln++;return NEWLINE;}
%%
