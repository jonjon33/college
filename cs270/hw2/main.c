#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE 32
#define MAX_INPUT_SIZE 255

int makearg(char *s,char ***args);

int main()
{
    // define variables
    char str[MAX_INPUT_SIZE+1];
    int i;
    int argc;
    char **argv;

    printf("Input string to Parse (max input %i chars, max token %i chars):\n>",MAX_INPUT_SIZE,MAX_TOKEN_SIZE);
    fgets(str,(int)sizeof(str),stdin);

    if( strlen(str) > MAX_INPUT_SIZE )
    {
        printf("Error: Max input size exceeded\n");
        return 0;
    }

    // run parser function
    argc = makearg(str,&argv);

    // output
    if( argc > 0 )
    {
        printf("makearg() Returned Successfully!\n");
        printf("Num of Args:%i\n",argc);
        for(i=0;i<argc;i++)
        {
            printf("Arg #%i:%s\n",i+1,argv[i]);
        }
    }

    else if( argc == 0 )
        printf("Error: Input string empty\n");

    else if( argc == -1 )
        printf("Error: Max token size exceeded\n");

    else
        printf("Error: Unrecognized error. What have you done?\n");

    return 0;
}

int makearg( char *s , char ***args )
{
    // don't waste time if empty
    if(strlen(s)==0) return 0;

    char tokenbuf[MAX_TOKEN_SIZE];
    char **argv;
    char *temp;
    int i;
    int j = 0;
    int argc = 0;

    // get argc on the first pass to mallocate the array
    for(i=0;i<strlen(s)+1;i++)
    {
        if(s[i] == ' ' || s[i] == '\0')
            argc++;
    }

    argv = (char **) malloc(argc*sizeof(char **));

    // second pass to make strings
    argc = 0;
    for(i=0;i<strlen(s)+1;i++)
    {
        // if printable character
        if(s[i] >= '!' && s[i] <= '~')
        {
            if(j<MAX_TOKEN_SIZE)
            {
                tokenbuf[j] = s[i]; // add char to buffer
                j++; // increment buffer index
            }

            else
                return -1;
        }

        // else if delimiter or end of line
        else if(s[i] == ' ' || s[i] == '\n' )
        {
            tokenbuf[j] = '\0'; // give end of str to buffer
            temp = (char *) malloc(strlen(tokenbuf)+1); // allocate the str
            argv[argc] = temp; // give the str ptr to the value at the ptr to char
            strcpy(argv[argc],tokenbuf); // fill the allocated string with the buffer
            argc++; // increment the item count
            j=0; // reset the buffer index
        }

        // if we hit a null, we're done
        else if (s[i] == '\0')
            break;

        // some other char (unexpected) is being parsed
        else
            return -2;
    }

    // output
    *args = argv;
    return argc;
}
