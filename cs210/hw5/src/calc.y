%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sym.h"
%}

%union {
    double dval;
    struct sym * symptr;
}


%token <symptr> CONST
%token <symptr> NAME
%token <dval> NUMBER
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS

%type <dval> expression

%%

statement_list
    : statement '\n'
    | statement_list statement '\n'
    ;

statement
    : '?' { symPrint(); }
    | CONST '=' expression { printf("error: assign to const\n"); }
    | NAME '=' expression { $1->value = $3; }
    | expression { printf("= %g\n", $1); }
    ;

expression
    : expression '+' expression { $$ = $1 + $3; }
    | expression '-' expression { $$ = $1 - $3; }
    | expression '*' expression { $$ = $1 * $3; }
    | expression '/' expression
        {   if ($3 == 0)
            {
                printf("error: div by zero\n");
                $$ = $1;
            }
            else
            {
                $$ = $1 / $3;
            }
        }
    | '-' expression %prec UMINUS { $$ = -$2; }
    | '(' expression ')' { $$ = $2; }
    | CONST { $$ = $1->value; }
    | NUMBER
    | NAME { $$ = $1->value; }
    ;

%%

void symInit()
{
    struct sym * pSym;

    pSym = symLookup("PI");
    pSym->value = 3.14159;

    pSym = symLookup("PHI");
    pSym->value = 1.61803;
}

struct sym * symLookup( char * newName )
{
    extern struct sym * SYM_LIST_HEAD;
    struct sym * prev;
    struct sym * pSym;

    if( !SYM_LIST_HEAD )
    {
        SYM_LIST_HEAD = (struct sym *)malloc(sizeof(struct sym));
        SYM_LIST_HEAD->name = strdup(newName);
        SYM_LIST_HEAD->next = NULL;
        return SYM_LIST_HEAD;
    }


    for( pSym = SYM_LIST_HEAD ; pSym ; pSym = pSym->next )
    {
        if( strcmp(pSym->name,newName) == 0 )
            return pSym;

        prev = pSym;
    }

    pSym = (struct sym *)malloc(sizeof(struct sym));
    pSym->name = strdup(newName);
    pSym->next = NULL;
    prev->next = pSym;
    return pSym;

    yyerror("reached non-existant end of sym list");
    exit(-1);
    return NULL; /* unreachable */
}

void symPrint()
{
    extern struct sym * SYM_LIST_HEAD;
    struct sym * pSym;
    int symCount = 0;

    symBubbleSort();

    for(pSym = SYM_LIST_HEAD ; pSym ; pSym = pSym->next)
    {
        symCount++;
    }

    printf("num_syms: %d\n",symCount);

    for(pSym = SYM_LIST_HEAD ; pSym ; pSym = pSym->next)
    {
        printf("\t%s => %f\n",pSym->name,pSym->value);
    }
}

void symBubbleSort()
{
    extern struct sym * SYM_LIST_HEAD;
    struct sym * pSym;
    struct sym * prev = NULL;
    struct sym * pEnd = NULL;
    int done;

    do
    {
        done = 1;
        prev = NULL;
        pSym = SYM_LIST_HEAD;

        while(pSym && pSym->next != pEnd)
        {
            if(pSym->name[0] > pSym->next->name[0])
            {
                symSwap(prev,pSym,pSym->next);
                done = 0;
            }
            prev = pSym;
            pSym = pSym->next;
        }
        pEnd = pSym;
    }
    while(!done);
}

void symSwap(struct sym * pPrev, struct sym * pCurr, struct sym * pNext)
{
    extern struct sym * SYM_LIST_HEAD;

    if(!pPrev)
    {
        pCurr->next = pNext->next;
        pNext->next = pCurr;
        SYM_LIST_HEAD = pNext;
    }
    else
    {
        pPrev->next = pNext;
        pCurr->next = pNext->next;
        pNext->next = pCurr;
    }
}
