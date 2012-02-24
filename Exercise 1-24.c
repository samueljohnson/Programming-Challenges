/* Exercise 1-24, page 34 in 'The C Programming Language (2nd Edition)'
 * Program to check for rudimentary syntax errors like unbalanced
 * parantheses, brackets, braces, quotes, and comments.
 * 
 * 
 * Samuel Johnson <esamueljohnson@gmail.com>
 */

#include <stdio.h>

int main ( int argc, char *argv[] )
{
  int inbrace=0, inbrack=0, inparan=0, x, pastx, incomment=0, insquote=0, indquote=0, error=0;
    if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename\n", argv[0] );
    }
    else 
    {
        // We assume argv[1] is a filename to open
        FILE *file = fopen( argv[1], "r" );

        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else 
        {  
            /* read one character at a time from file, stopping at EOF, which
               indicates the end of the file.  Note that the idiom of "assign
               to a variable, check the value" used below works because
               the assignment statement evaluates to the value assigned. */
            while  ( ( x = fgetc( file ) ) != EOF )
            {
	      if(x=='\'') {
		if(insquote)
		  insquote=0;
		else
		  insquote=1;
	      }
	      if(x=='"') {
		if(indquote)
		  indquote=0;
		else
		  indquote=1;
	      }
	      switch(x) {
		case '*':
		  if(pastx=='/')
		    incomment=1;
		  break;
		case '/':
		  if(pastx=='*')
		    incomment=0;
		  break;
		case '{':
		  if(!incomment && !insquote && !indquote)
		    ++inbrace;
		  break;
		case '}':
		  if(!incomment && !insquote && !indquote)
		    if(--inbrace<0)
		      error=1;
		  break;
		case '(':
		  if(!incomment && !insquote && !indquote)
		    ++inparan;
		  break;
		case ')':
		  if(!incomment && !insquote && !indquote)
		    if(--inparan<0)
		      error=1;
		  break;
		case '[':
		  if(!incomment && !insquote && !indquote)
		    ++inbrack;
		  break;
		case ']':
		  if(!incomment && !insquote && !indquote)
		    if(--inbrack<0)
		      error=1;
		  break;
		default:
		  break;
	       }
	       pastx=x;
	      }    
         }
	    if(inbrace>0) {
	      printf("%d braces needs to be closed\n",inbrace);
	      error=1;
	    }
	    if(inbrace<0) {
	      printf("There are %d open braces\n",-1*inbrace);
	      error=1;
	    }
	    if(inparan>0) {
	      printf("%d parantheses needs to be closed\n",inparan);
	      error=1;
	    }
	    if(inparan<0) {
	      printf("There are %d open parantheses\n",-1*inparan);
	      error=1;
	    }
	    if(inbrack>0) {
	      printf("%d brackets needs to be closed\n",inbrack);
	      error=1;
	    }
	    if(inbrack<0) {
	      printf("There are %d open brackets\n",-1*inbrack);
	      error=1;
	    }
	    if(error || indquote || insquote)
	      printf("The program is invalid!\n");
	    else if(!inbrace)
	      if(!inbrack)
		printf("The program is valid!\n");
            fclose( file );
        }
}
