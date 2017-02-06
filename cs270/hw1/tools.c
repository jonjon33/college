////
// tools.c - for use with cs270 hw1
// Jon Hanson
////

////
// includes
#include<stdio.h>
#include<stdlib.h>

////
// defines
#define MAX_VAL 100

////
// fillarray(int*,int)
// fills a passed array with random numbers
void fillArray( int *a , int l )
{
    int i;
    for( i = 0 ; i < l ; i++ )
    {
        a[i] = rand()%(MAX_VAL)+1;
    }

    return;
}

////
// printArray(int*,int)
// prints a passed array's elements to console
void printArray( int *a , int l )
{
    int i;
    for( i = 0 ; i < l ; i++ )
    {
        printf("%i ",a[i]);
    }
    printf("\n");
    return;
}
