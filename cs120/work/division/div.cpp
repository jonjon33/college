/* Jonathan Hanson
 * CS120 - 01
 * Sept 13, 2013
 * Assignment #2
 *
 * This is a simple and straightforward program that prompts
 * the user through basic division problems with integers.
 * Both the quotient and the remainder are given, and the
 * program can be rerun or exited by the user.
 *
 */
//////// INCLUDES ////////
#include<iostream>
using namespace std;

//////// MAIN ////////
int main(){

//////// VARIABLE DECLARATIONS ////////
	int dividend;
	int divisor;
	int quotient;
	int remainder;
	float float_quotient;
	char run_again;

//////// PROGRAM ////////	
	cout << "\n\\ \\ \\ \\ \\ \\ \\ \\ \\ \\ DIVISION CALCULATOR 9000 / / / / / / / / / /\n";
	do {
		cout << "\nPlease enter a dividend for your desired division: ";
		cin >> dividend;
		cout << "Now please enter a divisor for your desired division: ";
		cin >> divisor;
		while (divisor == 0){
		cout << "Sorry, this is not possible. Pick a non-zero divisor: ";
		cin >> divisor;
		}
		quotient = dividend / divisor;
		remainder = dividend % divisor;
		float_quotient = (1. * dividend) / (1. * divisor);
		cout << "The quotient of " << dividend << "/" << divisor << " = " << quotient << " with a remainder of " << remainder << endl;
		cout << "Or " << float_quotient << endl;
		cout << "\nWould you like to run Division Calculator 9000 again? (y/n): ";
		cin >> run_again;
	} while (run_again == 'y');
	cout << "\nGoodbye!\n\n";
}
