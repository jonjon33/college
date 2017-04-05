/* Hash.cpp
 *
 *  Hash table implementation from:
 *  Kernighan & Ritchie, The C Programming Language,
 *     Second Edition, Prentice-Hall, 1988.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "hash.h"


const int HASH_TABLE_SIZE = 50031;
static NListPtr hashTable[HASH_TABLE_SIZE];
int bucketCount[HASH_TABLE_SIZE];

    //  Prototypes
static char *Strdup( const char * );  //  in cstring, but....



/*  Hash
 *  Generate hash value for string s
 */

unsigned Hash( const char *s )
{
    unsigned hashVal;
    
    for( hashVal = 0 ; *s != '\0' ; s++ )
        hashVal = *s + 31 * hashVal;
        
    return  hashVal % HASH_TABLE_SIZE;
}


/*  Lookup
 *  Look for s in hashTable
 */

NListPtr Lookup( const char *s )
{
    NListPtr np;
    
    for( np = hashTable[Hash(s)] ; np != NULL ; np = np->next )
    {
        if( strcmp(s, np->name) == 0 )
            return np;    //  found
    }
    
    return NULL;          //  not found
}

/*  Insert
 *  Put (name) in hash table
 */
 
NListPtr Insert( const char *name )
{
    unsigned hashVal;
    NListPtr np;
    
    if( (np = Lookup(name)) == NULL )  // not found
    {
        np = (NListPtr) malloc(sizeof(*np));
        if( np == NULL || (np->name = Strdup(name)) == NULL )
            return NULL;
        hashVal = Hash(name);
        np->next = hashTable[hashVal];
        hashTable[hashVal] = np;
	bucketCount[hashVal]++;
    }
    
    return np;
}


/*  PrintHashTable
 *  Print the hash table contents
 */

void PrintHashTable()
{
    NListPtr np;

/*
    cout << "Hash table contents:" << endl;
    cout << "--------------------\n" << endl;

    for( int i = 0 ; i < HASH_TABLE_SIZE ; i++ )
    {
        np = hashTable[i];
        while( np != NULL )
        {
             cout << setw(3) << i << ":    ";
             cout << np->name;
             cout << endl;
             np = np->next;
        }
    }
*/

    cout << "Bucket Filling:" << endl;
    cout << "---------------" << endl;
    cout << "There are " << HASH_TABLE_SIZE << " buckets:" << endl;
    for( int i = 0 ; i < HASH_TABLE_SIZE ; i++ )
    {
        cout << setw(5) << i << ": " << setw(5) << bucketCount[i] << endl;
    }

    cout << "\n\nBucket Stats:" << endl;
    cout << "-------------" << endl;
    int minBucketIndex = 0, maxBucketIndex = 0;
    int minBucketCount = bucketCount[0], maxBucketCount = bucketCount[0];
    int emptyBuckets = 0;
    for(int i = 0 ; i < HASH_TABLE_SIZE ; i++)
    {
        if(bucketCount[i] < minBucketCount)
        {
            minBucketIndex = i;
            minBucketCount = bucketCount[i];
        }
        if(bucketCount[i] > maxBucketCount)
        {
            maxBucketIndex = i;
            maxBucketCount = bucketCount[i];
        }
        if(bucketCount[i]==0)
	{
	    emptyBuckets++;
	}
    }
    cout << "Fullest Bucket is #" << maxBucketIndex << " with ";
    cout << maxBucketCount << " items."<< endl;
    cout << "Emptiest Bucket is #" << minBucketIndex << " with ";
    cout << minBucketCount << " items."<< endl;
    cout << "There are " << emptyBuckets << " empty buckets." << endl;
}


/*  Strdup
 *  Make a duplicate copy of s
 */

static char *Strdup( const char *s )
{
    char *p;
    
    p = (char *) malloc(strlen(s)+1);  /*  +1 for '\0'  */
    if( p != NULL )
        strcpy(p,s);

    return p;
}
