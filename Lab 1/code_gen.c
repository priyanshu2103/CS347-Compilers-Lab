#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include "lex.h"
#include "name.c"
#include "lex.c"

char *factor(void);
char *factor_div(void);
char *term(void);
char *expression(void);
char *final_expression(void);
char *rel_final(void);

char *newname(void);
void freename(char *name);

void statements()
{
    /*  statements -> expression SEMI  |  expression SEMI statements  */

    char *tempvar1;

    while(!match(EOI))     // this while loop handles the expression SEMI statements part
    {
        tempvar1 = rel_final();

        if(match(SEMI))
            advance();
        else
            {
            	fprintf( stderr, "Line no. %d: Insert missing semicolon\n", yylineno );
            	freename(tempvar1);
            	return;
            }
        freename( tempvar1 );
    }
}
char *rel_final()
{
    /*  rel_final->final_expr|final_expr<final_expr|final_expr=final_expr|final_expr>final_expr */
//..............................TO-DO.........................
    // char *tempvar1;

    // while(!match(EOI))     // this while loop handles the expression SEMI statements part
    // {
    //     tempvar1 = final_expression();

    //     if(match(SEMI))
    //         advance();
    //     else
    //         {
    //         	fprintf( stderr, "Line no. %d: Insert missing semicolon\n", yylineno );
    //         	freename(tempvar1);
    //         	return;
    //         }
    //     freename( tempvar1 );
    // }
    return final_expression();
}

char *final_expression()
{
	// .................. See how to use legal_lookahead in all functions here................
    char  *tempvar1, *tempvar2;

    tempvar1 = expression();
    while( match( MINUS ) )
    {
        advance();
        tempvar2 = expression();
        printf("    %s -= %s\n", tempvar1, tempvar2 );
        freename( tempvar2 );
    }
    return tempvar1;
}
char *expression()
{
    /* expression -> term expression'
     * expression' -> PLUS term expression' |  epsilon
     */
    //expression'-> MINUS term expression'|epsilon
// It is being implemented as while loop as it wants of the form term+term+term+.....
    char  *tempvar1, *tempvar2;

    tempvar1 = term();
    while( match( PLUS ) )
    {
        advance();
        tempvar2 = term();
        printf("    %s += %s\n", tempvar1, tempvar2 );
        freename( tempvar2 );
    }
    return tempvar1;
}

char *term()
{
    char  *tempvar1, *tempvar2 ;

    tempvar1 = factor_div();
    while(match(TIMES))
    {
        advance();
        tempvar2 = factor_div();
        printf("    %s *= %s\n", tempvar1, tempvar2 );
        freename(tempvar2);
    }
    return tempvar1;
}

char *factor_div()
{
    char  *tempvar1, *tempvar2 ;

    tempvar1 = factor();
    while(match(DIV))
    {
        advance();
        tempvar2 = factor();
        printf("    %s /= %s\n", tempvar1, tempvar2 );
        freename(tempvar2);
    }
    return tempvar1;
}
char *factor()
{
    char *tempvar1;

    if( match(NUM_OR_ID) )
    {
	/* Print the assignment instruction. The %0.*s conversion is a form of
	 * %X.Ys, where X is the field width and Y is the maximum number of
	 * characters that will be printed (even if the string is longer). I'm
	 * using the %0.*s to print the string because it's not \0 terminated.
	 * The field has a default width of 0, but it will grow the size needed
	 * to print the string. The ".*" tells printf() to take the maximum-
	 * number-of-characters count from the next argument (yyleng).
	 */

        printf("    %s = %0.*s\n", tempvar1 = newname(), yyleng, yytext );
        advance();
    }
    else if( match(LP) )
    {
        advance();
        tempvar1 = final_expression();
        if( match(RP) )
            advance();
        else
            fprintf(stderr, "%d: Mismatched parenthesis\n", yylineno );
    }
    else
	fprintf( stderr, "%d: Number or identifier expected\n", yylineno );

    return tempvar1;
}

int	legal_lookahead(  first_arg )
int	first_arg;
{
    /* Simple error detection and recovery. Arguments are a 0-terminated list of
     * those tokens that can legitimately come next in the input. If the list is
     * empty, the end of file must come next. Print an error message if
     * necessary. Error recovery is performed by discarding all input symbols
     * until one that's in the input list is found
     *
     * Return true if there's no error or if we recovered from the error,
     * false if we can't recover.
     */

    va_list  	args;
    int		tok;
    int		lookaheads[MAXFIRST], *p = lookaheads, *current;
    int		error_printed = 0;
    int		rval	      = 0;

    va_start( args, first_arg );

    if( !first_arg )
    {
	if( match(EOI) )
	    rval = 1;
    }
    else
    {
	*p++ = first_arg;
	while( (tok = va_arg(args, int)) && p < &lookaheads[MAXFIRST] )
	    *p++ = tok;

	while( !match( SYNCH ) )
	{
	    for( current = lookaheads; current < p ; ++current )
		if( match( *current ) )
		{
		    rval = 1;
		    goto exit;
		}

	    if( !error_printed )
	    {
		fprintf( stderr, "Line %d: Syntax error\n", yylineno );
		error_printed = 1;
	    }

	    advance();
	}
    }

exit:
    va_end( args )
    return rval;
}
