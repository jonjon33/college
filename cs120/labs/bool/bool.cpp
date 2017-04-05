/* Jonathan Hanson
 * CS120 - 01
 * Sept 10, 2013
 * Lab #2
 *
 * This was a fairly straightforward lab.  I completed all sections, and made the output
 * slightly more detailed than just the integer results.
 *
 *
 */
//////// INCLUDES ////////
#include<iostream>
using namespace std;

//////// MAIN ////////
int main(){

//////// VARIABLE DECLARATIONS ////////
	int prob_num = 1;
	string problem;
	int expression;
	string answer;
	string f = "false";
	string t = "true";
	string i = "an integer";

//////// PROGRAM ////////
	cout << "\n\nLogic and Boolean Lab\n\n";

	do {
		if (prob_num == 1) {
			problem = "7 < 8";
			expression = 7 < 8;
		}
		if (prob_num == 2) {
			problem = "10 > 10";
			expression = 10 > 10;
		}
		if (prob_num == 3) {
			problem = "(7 < 10) || (7 > 10)";
			expression = (7 < 10) || (7 > 10);
		}
		if (prob_num == 4) {
			problem = "(7 < 10) && (7 > 10)";
			expression = (7 < 10) && (7 > 10);
		}
		if (prob_num == 5) {
			problem = "-5 >= 5";
			expression = -5 >= 5;
		}
		if (prob_num == 6) {
			problem = "(7 > 10) || (-5 == 5)";
			expression = (7 > 10) || (-5 == 5);
		}
		if (prob_num == 7) {
			problem = "!(6 == 7)";
			expression = !(6 == 7);
		}
		if (prob_num == 8) {
			problem = "(10 != 11) && (7 > 8)";
			expression = (10 != 11) && (7 > 8);
		}
		if (prob_num == 9) {
			problem = "(7 == 6) || (7 == 7) || (7 == 8)";
			expression = (7 == 6) || (7 == 7) || (7 == 8);
		}
		if (prob_num == 10) {
			problem = "6 < (8 && 9)";
			expression = 6 < (8 && 9);
		}
		if (prob_num == 11) {
			problem = "1 == (6 < 8)";
			expression = 1 == (6 < 8);
		}
		if (prob_num == 12) {
			problem = "0 == ( 0 || 1)";
			expression = 0 == ( 0 || 1);
		}
		if (prob_num == 13) {
			problem = "6 < (5+2)";
			expression = 6 < (5+2);
		}
		if (prob_num == 14) {
			problem = "6 + (5 == 5)";
			expression = 6 + (5 == 5);
		}
		if (prob_num == 15) {
			problem = "(6 < 7) + (7 >= 5)";
			expression = (6 < 7) + (7 >= 5);
		}
				
		if (expression == 0) answer = f;
		if (expression == 1) answer = t;
		if (expression != 0 && expression != 1) answer = i; 

		cout << prob_num << ".  " << problem << "  returns the value:" << endl;
		cout << "\t\t\t\t\t\t\t\t" << expression << " and is " << answer << endl;
		
		prob_num++;

	}while(prob_num<16);
	
	cout << "\n\n";
}
