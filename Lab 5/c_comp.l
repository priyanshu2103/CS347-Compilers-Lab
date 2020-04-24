%{

#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "c_comp.tab.h"
char *trimwhitespace(char *str);

%}

b   [ ]*

%option noyywrap

%%

{b}"+"{b}                                               {return PLUS;}
{b}"-"{b}                                               {return MINUS;}
{b}"*"{b}                                               {return MULT;}
{b}"/"{b}                                               {return DIV;}
{b}"<="{b}                                              {return LE;}
{b}">="{b}                                              {return GE;}
{b}"="{b}                                               {return EQ;}
{b}"!="{b}                                              {return NEQ;}
{b}"<"{b}               																{return LT;}
{b}">"{b}               																{return GT;}
{b}"&&"{b}                                              {return AND;}
{b}"||"{b}                                              {return OR;}
{b}"!"{b}                                  							{return EXCL;}
{b}","{b}                                       				{return COMMA;}
{b}":"{b}                                       				{return COL;}
{b}";"{b}                                       				{return SEMI;}
{b}"{"{b}                                       				{return LC;}
{b}"}"{b}                                       				{return RC;}
{b}"("{b}                                       				{return LP;}
{b}")"{b}                                       				{return RP;}
{b}"void"{b}                                            {return VOID;}
{b}"int"{b}                                             {return INT_DECL;}
{b}"float"{b}                                           {return FLOAT_DECL;}
{b}"if"{b}                                              {return IF;}
{b}"else"{b}                                            {return ELSE;}
{b}"switch"{b}                                          {return SWITCH;}
{b}"case"{b}                                            {return CASE;}
{b}"for"{b}                                             {return FOR;}
{b}"while"{b}                                           {return WHILE;}
{b}"break"{b}                                           {return BREAK;}
{b}"default"{b}                                         {return DEFAULT;}
{b}[A-Za-z_][0-9A-Za-z_]*{b}                    				{return ID;}
{b}[0-9]+{b}                                    				{return INT;}
{b}[0-9]+\.[0-9]+{b}                                    {return FLOAT;}

%%

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}
