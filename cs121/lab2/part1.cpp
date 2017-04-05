/* showargs.cpp
 * Main Argument Test Program
 * Jonathan Hanson		Sept 11, 2014
 * Lab #3			CS 121
 *
 * Part 1 - Raw Arg Display
 *
 */
#include<iostream>
using namespace std;

int main( int argc, char *argv[] )
{
	int i;

	cout << "Arg Count: " << argc << endl;
	for( i=0;i<argc;i++ )
	{
		cout << argv[i] << endl;
	}

	return 1;
}
