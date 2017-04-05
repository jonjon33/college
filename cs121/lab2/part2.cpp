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
	const int MIN_ARGS = 3;		//File name then 3 args
	int i;

	if ( argc > MIN_ARGS )
	{
		cout << "Arg Count: " << argc << endl;
		for( i=0;i<argc;i++ )
		{
			cout << argv[i] << endl;
		}
	}
	else
	{
		cout << "Error: At Least 3 Arguments Required" << endl;
		return 1;
	}

	return 0;
}
