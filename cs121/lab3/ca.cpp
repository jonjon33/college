/* ca.cpp
 * CS 121		Sept 25, 2014
 * Lab #3		Jonathan Hanson
 *
 * Cellular Automata in a Dynamic Array
 *
 */
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

int checkFile( string , int );

void printState( int[] , int );

int * update( int[] , int );

int main()
{
	//Var Declarations
	int menuOption = 3;
	int i = 0;
	int runProgram = 0;
	int maxIterations = 20;

	int cellCount = 10;
	int *CellArrayPtr = new int[cellCount];

	string fileName;
	ifstream ifs;

	srand(time(NULL));


	//Main Loop
	while( 1 )
	{
		//Menu
		cout << "One Dimentional Cellular Automata Simulation" << endl;
		cout << "  1) Generate Random Simulation State" << endl;
		cout << "  2) Load Simulation State from File" << endl;
		cout << "  3) Help" << endl;
		cout << "  4) Exit" << endl;
		
		cin >> menuOption;

		switch( menuOption )
		{
		case 1:		//Generate Random
			cout << "Generating file..." << endl;
			for( i = 0 ; i < cellCount ; i++ )
			{
				CellArrayPtr[i] = rand() % 2;
			}
			
			runProgram = 1;

			break;
		case 2:		//Load from File
			cout << "Enter the name of the file to load" << endl;
			cin >> fileName;
			ifs.open( fileName.c_str() );
			if( ifs.good() && checkFile( fileName , cellCount ) )
			{
				for( i = 0 ; i < cellCount ; i++ )
				{
					ifs >> CellArrayPtr[i];
				}
				ifs >> CellArrayPtr[i];
			}
			else
			{
				cout << "Error: Couldn't read file. Check if file exists." << endl;
				ifs.close();
				return 1;
			}
			ifs.close();

			runProgram = 1;

			break;
		case 3:
			cout << "This program simulates the life cycle\nof simple cells.  If a cell has one\nand only one living neighbor each\niteration, then it becomes alive.\n\nFiles can be generated randomly or\nimported from a file.\n\nEnsure the file contains only the\ncell states (1s and 0s) and white\nspace between each cell's state.\nAlso ensure that the cell count\nmatches the necessary cell count\nof: " << cellCount <<endl;
			cout << "Returning to Menu..." << endl;
			break;
		case 4:
			ifs.close();
			delete [] CellArrayPtr;
			cout << "Goodbye!" << endl;
			return 0;
		default:
			cout << "Error: Invalid Input" << endl;
			cout << "Returning to Menu..." << endl;
			break;
		}
		
		if( runProgram )
		{
			cout << "Staring Simulation..." << endl;
			printState( CellArrayPtr , cellCount );
			for( i = 0 ; i < maxIterations ; i++ )
			{
				CellArrayPtr = update( CellArrayPtr , cellCount );
				printState( CellArrayPtr , cellCount );
			}
			cout << "End of Simulation" << endl;
			cout << "Returning to Menu..." << endl;
			runProgram = 0;
		}
	}
}

int checkFile ( string fileName , int bufSize )
{
	cout << "Checking File..." << endl;

	int checkVal = 0;
	int count = 0;
	ifstream ifs;
	ifs.open( fileName.c_str() );
	while( 1 )
	{
		ifs >> checkVal;
		if( ifs.eof() )
			break;
		if( checkVal == 0 || checkVal == 1)
		{
			count++;
		}
		else
		{
			cout << "Error: invalid character in file" << endl;
			ifs.close();
			return 0;
		}
	}
	
	if ( count != bufSize )
	{
		cout << "Error: cell count doesn't match" << endl;
		ifs.close();
		return 0;
	}

	ifs.close();
	return 1;
}

void printState(int a[], int cellCount)
{
	int i = 0;
	for( i = 0 ; i < cellCount ; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int * update( int a[], int cellCount)
{
	int i = 0;
	int neighborCheck = 0;
	int *newState = new int[cellCount];
	for ( i = 0 ; i < cellCount ; i++ )
	{
		if( i == 0 )
		{
			neighborCheck = a[i+1];
		}
		if ( i == ( cellCount - 1 ) )
		{
			neighborCheck = a[i-1];
		}
		if( i > 0 && i < ( cellCount - 1 ) )
		{
			neighborCheck = a[i-1] + a[i+1];
		}

		if( neighborCheck == 1 )
		{
			newState[i] = 1;
		}
		else
		{
			newState[i] = 0;
		}
	}
	
	return newState;
}
