/* memerror.c -- try to find (and fix!) all the memory-related errors
                 in this program that

   Takes a string from the command line.  
   Makes a linked-list out of it in reverse order.  
   Traverse it to construct a string in reverse.  
   Clean up (release memory).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//This new line resolves compiler warnings by including
			//strcpy() and strlen()

typedef struct st_CharNode 
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
        //fprintf( stderr, "usage: %s string.  This reverses the string "
        //         "given on the command line\n" );
        fprintf(stderr, "Usage: This program reverses one string passed as\n"
		"an arguement from the command line.\n");  //Made error
							   //understandable
        exit( -1 );
    }

    // Copy the argument so we can make changes to it
    stringBuffer = malloc( strlen(argv[1]) );
    //strcpy( argv[1], stringBuffer );
    strcpy( stringBuffer , argv[1] );  //Fixed to proper usage:
				       //strcpy( destination , source)

    // Reverse the string
    reverseIt( stringBuffer );

    // Print the reversed string
    //printf( "the reversed string is '%s'\n", *stringBuffer );
    printf( "The reversed string is '%s'\n" , stringBuffer ); //stringBuffer
							      //cannot be
							      //dereferenced

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

    // walk the string
    //while (scan < stop)
    while (*scan != *stop) //Scan and stop cannot be traversed with indices
			   //like arrays, they must have their values compared
    {
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

    // Re-point to the buffer so we can drop the characters
    scan = stringbuffer;

    //  Traverse the nodes and add them to the string
    while( head != NULL )
    {
        *scan = head->theChar;
        free( head );
        node = head->next;
        head = node;
        scan++;
    }

    // Release head
    free( head );   
}
