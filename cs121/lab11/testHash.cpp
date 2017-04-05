/* TestHash.cpp
 *   Test the Hash table code.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#include "hash.h"


int main()
{  
      //  Put a few values in the table...
   (void)Insert( "One" );
   (void)Insert( "One" );
   (void)Insert( "Two" );
   (void)Insert( "Four" );
   (void)Insert( "Five" );
   (void)Insert( "Six" );
   (void)Insert( "Nine" );
   
   (void)Insert( "Yes" );
   (void)Insert( "YES" );
   (void)Insert( "No" );
   (void)Insert( "NO" );
   
   PrintHashTable();
         
   return EXIT_SUCCESS;
}
 


 
