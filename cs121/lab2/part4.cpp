/* showargs.cpp
 * Main Argument Test Program
 * Jonathan Hanson		Sept 11, 2014
 * Lab #2			CS 121
 *
 * Part 4 - Argument based Calculator
 *
 * Arguments supplied must be 1) file location, 2) int, 3) operator (+,-,*,/) 4) int.
 * There may be no more and no fewer arguments.  The multiplication operator raises
 * complications discussed in the responses to lab questions.
 *
 */
#include<iostream>
#include<stdlib.h>
using namespace std;

int main( int argc, char *argv[] )
{
	const int REQUIRED_ARGS = 4;		//File name then 3 args
	int i;
	int arg2;
	char arg3;
	int arg4;
	char *cPtr;
	int ans;

	if ( argc == REQUIRED_ARGS )
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

		arg2 = atoi( cPtr );
		

		//Check Argument 3 for operator
		cPtr = argv[2];

		for( i = 0 ; cPtr[i] != NULL ; i++ )
		{
			//Do nothing (but keep track of i)
		}
		if( i == 1 )
		{
			switch( cPtr[0] )
			{
			case '+':
				break;
			case '-':
				break;
			case '*':
				break;
			case '/':
				break;
			default:
				cout << "Error: Unexpected char in argument 3; must be '+', '-', '*', or '/'" << endl;
				return 1;
			}
		}
		else
		{
			cout << "Error: Unexpected char in argument 3; must be '+', '-', '*', or '/'" << endl;
			return 1;
		}

		arg3 = *cPtr;				


		//Check Argument 4 for INT
		cPtr = argv[3];
		for( i = 0 ; cPtr[i] != NULL ; i++ )
		{
			if( cPtr[i] >= '0' && cPtr[i] <= '9' )
			{
				//Do nothing
			}
			else
			{
				cout << "Error: Unexpected char in argument 4; must be int" << endl;
				return 1;
			}
		}

		arg4 = atoi( cPtr );


		cout << "Calculating:" << endl;
		cout << arg2 << " " << arg3 << " " << arg4 << " = ";

		switch( arg3 )
		{
		case '+':
			ans = arg2 + arg4;
			break;
		case '-':
			ans = arg2 - arg4;
			break;
		case '*':
			ans = arg2 * arg4;
			break;
		case '/':
			ans = arg2 / arg4;
			break;
		}

		cout << ans << endl;

	}
	else
	{
		cout << ( "Error: At Least 3 Args Required" ) << endl;
		return 1;
	}

	return 0;
}
