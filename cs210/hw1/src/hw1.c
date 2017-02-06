// hw1.c
// Jon Hanson
// March 10, 2016
// CS 210 - Programming Languages
// Homework 1 - CCX Lexer

// To Do
// - global list length func?


// includes
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//defines
#define CCX_KEYWORD_COUNT 34
#define CCX_OPERATOR_COUNT 27
#define CCX_WHITESPACE_COUNT 6

// global lexer states
typedef enum {
    LEX_FRESH ,         // first char of new lexeme
    LEX_INDET_ALPH ,    // indeterminate alphabetic lexeme
                        //  - fill until invalid char, then check keywords
    LEX_INDET_SYM ,     // indeterminate symbol lexeme
                        //  - get 2nd char, check comment, check 2-char ops,
                        //     check 1 char ops
    LEX_COMMENT ,       // comment - fill hist until end condition
    LEX_STR ,           // string - fill hist until end condion
    LEX_CHAR ,          // character literal - fill hist until end condition
    LEX_NUM             // numeric literal - fill until invalid char
} lexerState;

// global lists for checking
char *ccxKeywords[] = {
    "accessor" , "and" , "array" , "begin" , "bool" , "case" , "else" ,
    "elsif" , "end" , "exit" , "function" , "if" , "in" , "integer" ,
    "interface" , "is" , "loop" , "module" , "mutator" , "natural" , "null" ,
    "of" , "or" , "others" , "out" , "positive" , "procedure" , "return" ,
    "struct" , "subtype" , "then" , "type" , "when" , "while"
};

char *ccxOperators[] = {
    "." , "<" , ">" , "(" , ")" , "+" , "-" , "*" , "/" , "|" , "&" , ";" ,
    "," , ":" , "[" , "]" , "=" , ":=" , ".." , "<<" , ">>" , "<>" , "<=" ,
    ">=" , "**" , "!=" , "=>"
};

char *ccxWhitespace[] = {
    " " , "\n" , "\t" , "\r" , "\v" , "\f"
};

// prototypes
void parseLexeme( char , lexerState* , char* );

//
// function: int main( int , char** )
//
int main( int argc , char* argv[] )
{
    FILE* fd;                   // input file descriptor
    char ch;                    // read char buffer
    char hist[512];             // history of characters read
    lexerState lex = LEX_FRESH; // current lexer state

    // Check for proper arg count
    switch(argc)
    {
    case 1:
        printf("Error: No filename argument\n");
        exit(1);
    case 2:
        break;
    default:
        printf("Error: Extraneous arguements\n");
        exit(1);
    }

    // open and check fd of given filename
    fd = fopen(argv[1],"r");
    if( fd == NULL )
    {
        printf("Error: Couldn't open %s\n",argv[1]);
        exit(2);
    }

    // get the first char and go
    ch = fgetc(fd);
    while( ch != EOF )
    {
        parseLexeme(ch,&lex,hist);  // process the character
        ch = fgetc(fd);             // get another
    }

    return 0;
}

//
//
void parseLexeme( char ch , lexerState *lex , char *hist )
{
    int i = 0;
    char temp[2] = {ch,'\0'};  // convert input char to string for strcpy/strcat

    // if fresh start a new hist,else append
    if( *lex == LEX_FRESH )
        strcpy(hist,temp);
    else
        strcat(hist,temp);

    // lexer state machine
    switch( *lex )
    {
    case LEX_FRESH:
        // first char switch
        switch( ch )
        {
        // " is guaranteed string
        case '\"':
            *lex = LEX_STR;
            return;

        // ' is guaranteed char
        case '\'':
            *lex = LEX_CHAR;
            return;

        // handle ranges, bad input in default
        default:
            // number is guaranteed num
            if( ch >= '0' && ch <= '9' )
            {
                *lex = LEX_NUM;
                return;
            }

            // alphabetic sends to indeterminate alpha
            if( (ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') )
            {
                *lex = LEX_INDET_ALPH;
                return;
            }

            // check for 1st char operator (or comment!) match
            for(i=0;i<CCX_OPERATOR_COUNT;i++)
            {
                if(!strncmp(hist,ccxOperators[i],1))
                {
                    *lex = LEX_INDET_SYM;
                    return;
                }
            }

            // check for whitespace (then ignore it!)
            for(i=0;i<CCX_WHITESPACE_COUNT;i++)
            {
                if(!strncmp(hist,ccxWhitespace[i],1))
                {
                    *lex = LEX_FRESH;
                    return;
                }
            }

            // simple kill on fall through (to UNK)
            printf("ERROR: ENCOUNTERED UNK (LEX_FRESH)\n");
            exit(3);
        }
        break;

    // building a comment or operation (some symbol was 1st char)
    case LEX_INDET_SYM:
        // check if its a comment
        if(!strncmp(hist,"/*",2))
        {
            *lex = LEX_COMMENT;
            return;
        }

        // check 2-char operators (this is max length)
        for(i=0;i<CCX_OPERATOR_COUNT;i++)
        {
            if(!strncmp(hist,ccxOperators[i],2))
            {
                // found an operator! (2-char)
                printf("%s (operator)\n",hist);
                *lex = LEX_FRESH;
                return;
            }
        }

        // check 1-char operators
        for(i=0;i<CCX_OPERATOR_COUNT;i++)
        {
            if(!strncmp(hist,ccxOperators[i],1))
            {
                // found an operator! (1-char)
                printf("%c (operator)\n",hist[0]); // possible corner cut
                *lex = LEX_FRESH;
                parseLexeme(ch,lex,hist);  // recur w/ 'extra' (new) char
                return;
            }
        }

        // kill on fall through
        printf("ERROR: ENCOUNTERED UNK (LEX_INDET_SYM)\n");
        exit(3);

    // building an identifier or a keyword (some a-z was 1st char)
    case LEX_INDET_ALPH:
        // if new char is invalid
        if( !( ch >= 'a' && ch <= 'z' ) &&
            !( ch >= 'A' && ch <= 'Z' ) &&
            !( ch >= '0' && ch <= '9' ) &&
            !( ch == '_' ) )
        {
            // clear new char from hist (recur it later)
            hist[strlen(hist)-1] = '\0';

            // check hist against keyword list
            for(i=0;i<CCX_KEYWORD_COUNT;i++)
            {
                if(!strcmp(hist,ccxKeywords[i]))
                {
                    // found a keyword
                    printf("%s (keyword)\n",hist);
                    *lex = LEX_FRESH;
                    parseLexeme(ch,lex,hist); // recur w/ 'invalid' (new) char
                    return;
                }
            }

            printf("%s (identifier)\n",hist);
            *lex = LEX_FRESH;
            parseLexeme(ch,lex,hist); // recur w/ 'invalid' (new) char
            return;
        }
        break;

    // building a comment (found "/*")
    case LEX_COMMENT:
        // check if our current char is last of end condition ('/')
        if( ch == '/' )
        {
            // if prev char is '*' (making "*/")
            if( hist[strlen(hist)-2] == '*' )
            {
                // found a comment!
                printf("%s (comment)\n",hist);
                *lex = LEX_FRESH;
                return;
            }
        }
        break;

    // building a string (found a starting double quote)
    case LEX_STR:
        // check current char for end condition (")
        if( ch == '"' )
        {
            // found a string!
            printf("%s (string)\n",hist);
            *lex = LEX_FRESH;
            return;
        }
        break;

    // building a char (found a starting single quote)
    case LEX_CHAR:
        // check current char for end condition (')
        if( ch == '\'' )
        {
            // found a character literal!
            printf("%s (character literal)\n",hist);
            *lex = LEX_FRESH;
            return;
        }
        break;

    // building a numeric literal (some 0-9 was 1st char)
    case LEX_NUM:
        // if invalid num literal char found
        if( !( ch >= '0' && ch <= '9' ) &&
            !( ch >= 'a' && ch <= 'f' ) &&
            !( ch >= 'A' && ch <= 'F' ) &&
            !( ch == '_' || ch == '.' || ch == '#' ) )
        {
            // clear new char from hist (recur it later)
            hist[strlen(hist)-1] = '\0';

            // found a number!
            printf("%s (numeric literal)\n",hist);
            *lex = LEX_FRESH;
            parseLexeme(ch,lex,hist); // recur w/ 'invalid' (new) char

            return;
        }
        break;

    // exit on catastrophic failure (probably a typo)
    default:
        printf("ERROR: NON-EXISTANT STATE or FALL THROUGH\n");
        exit(4);
    }

    return;
}
