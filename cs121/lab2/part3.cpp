/* showargs.cpp
 * Main Argument Test Program
 * Jonathan Hanson		Sept 11, 2014
 * Lab #2			CS 121
 *
 * Part 3 - Argument Conversion
 *
 * At least three arguments in addition to the file location must be supplied, the first
 * being an int, the second being a double (float), and the rest being any valid argument type.
 *
 */
#include<iostream>
#include<stdlib.h>
using namespace std;

int main( int argc, char *argv[] )
{
	const int MIN_ARGS = 3;		//File name then 3 args
	int i;
	int arg2;
	double arg3;
	char *cPtr;
	int decPoint = 0;	//Would prefer a more graceful check for decimal point in double value

	if ( argc > MIN_ARGS )
	{
		//Check Argument 2 for INT
		cPtr = argv[1];
		for( i = 0 ; cPtr[i] != NULL ; i++ )
		{
			if( cPtr[i] >= '0' && cPtr[i] <= '9' )
			{
				//Do nothing
			}
			else
			{
				cout << "Error: Unexpected char in argument 2; must be int" << endl;
				return 1;
			}
		}

		//Convert Argument 2 to INT value
		arg2 = atoi( cPtr );


		//Check Argument 3 for DOUBLE (FLOAT)
		cPtr = argv[2];
		for( i = 0 ; cPtr[i] != NULL ; i++ )
		{
			if( cPtr[i] >= '0' && cPtr[i] <= '9' )
			{
				//Do nothing
			}
			else
			{
				if( cPtr[i] == '.' && decPoint == 0 )
				{
					decPoint = 1;
				}
				else
				{
					cout << "Error: Unexpected char in argument 3; must be double" << endl;
					return 1;
				}
			}
		}
		
		//Convert Argument 3 to DOUBLE Value
		arg3 = atof( cPtr );


		//Print the argument count and arguments
		cout << "Arg Count: " << argc << endl;
		for( i=0;i<argc;i++ )
		{
			cout << argv[i] << endl;
		}
	}
	else
	{
		cout << ( "Error: At Least 3 Args Required" ) << endl;
		return 1;
	}

	return 0;
}
