/* memerror.c -- try to find (and fix!) all the memory-related errors
                 in this program that

   Takes a string from the command line.  
   Makes a linked-list out of it in reverse order.  
   Traverse it to construct a string in reverse.  
   Clean up (release memory).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//Fixes compiler warnings for strlen, strcpy

typedef struct st_CharNode 	//Ugly, but works
{
    char theChar;
    struct st_CharNode *next;
} CharNode;


void reverseIt( char *stringbuffer );


int main( int argc, char *argv[] )
{
    char *stringBuffer;

    //  Check number of user supplied arguments.  
    if( argc != 2 )
    {
        fprintf( stderr, "Usage: This reverses the string given on the command line\nProvide one string arguement with main.\n" );	//Made this sensable
        exit( -1 );
    }

    // Copy the argument so we can make changes to it
    stringBuffer = malloc( strlen(argv[1]) );
    strcpy( stringBuffer , argv[1] ); 		//Fixed function usage here

	printf("\n%s\n", stringBuffer);  //debug

	printf("\nReady to reverse\n");  //debug

    // Reverse the string
    reverseIt( stringBuffer );

    // Print the reversed string
    printf( "the reversed string is '%s'\n", stringBuffer );

    return 0;
}


// Build a linked list backwards, then traverse it.

void reverseIt( char *stringbuffer )
{
    CharNode *head, *node;
    char *scan, *stop;
    
    // initialize local vars
    head = node = NULL;

    // find the start and end of the string so we can walk it
    scan = stringbuffer;
    stop = stringbuffer + strlen(stringbuffer) + 1;

	printf("\n%c%c\n", *scan , *stop);	//debug

    // walk the string
    while (*scan != *stop)	//It's not arrays, values must be compared not indices
    {
	printf("\nLoop iterating\n");  //debug
        if (head == NULL)
        {
            head = malloc( sizeof(CharNode*) );
            head->theChar = *scan;
            head->next = NULL;
        }
        else
        {
            node = malloc( sizeof(CharNode*) );
            node->theChar = *scan;
            node->next = head;
            head = node;
        }
        scan++;
    }
	printf("\nLoop Complete\n");	//debug

    // Re-point to the buffer so we can drop the characters
    scan = stringbuffer;


	printf("\nCheck 1\n");	//debug

    //  Traverse the nodes and add them to the string
    while( head != NULL )
    {
        *scan = head->theChar;
        free( head );
        node = head->next;
        head = node;
        scan++;
    }


	printf("\nCheck 2\n");	//debug

    // Release head
    free( head );   

	
	printf("\nCheck 3\n");	//debug
}
