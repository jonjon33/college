/***************
Jonathan Hanson
CS 120 - 01
Sept 24, 2013
Lab 4 Part 2

In addition to the changes assigned I rearranged the menu to feel more natural,
added labels so the user is reminded what operation he or she selected, and
removed the annoying bug where upon exit the previous answer is stated again.
***************/
#include<iostream>
using namespace std;

//////// Function Prototypes ////////
void print_menu();
float get_value();
float divide(float,float);
float minimum(float,float);

//////// Main ////////
int main() {
	float operand1, operand2, answer;
	int choice, valid_choice;
	
	cout << "\n\nSimple Calculator\n\n";
	cout << "Created by: Jonathan Hanson\nSept 24, 2013\n";
	cout << "This program uses functions and a simple, menu-based\nformat to make basic math operations easy and fun.\n";
	cout << "Input the integer labels in the menu to navigate, and\ninput floating point numbers or integers as operands.\n";


	do{
		print_menu();
		cin >> choice;
		valid_choice = 1;
		switch(choice){
		case 0:
			break;
		case 1:
			cout << "\nAddition Calculator\n";
			operand1 = get_value();
			operand2 = get_value();
			answer = operand1 + operand2;
			break;
		case 2:
			cout << "\nSubtraction Calculator\n";
			operand1 = get_value();
			operand2 = get_value();
			answer = operand1 - operand2;
			break;
		case 3:
			cout << "\nDivision Calculator\n";
			operand1 = get_value();
			operand2 = get_value();
			answer = divide(operand1,operand2);
			break;
		case 4:
			cout << "\nMinimum Calculator\n";
			operand1 = get_value();
			operand2 = get_value();
			answer = minimum(operand1,operand2);
			break;
		default:
			valid_choice = 0;
			cout << "Invalid Choice." << endl;
		}
		if(valid_choice && choice != 0){
			cout << endl << "Answer = " << answer << endl;
		}
	}while(choice != 0);
	
	cout << "\nGoodbye!\n\n";

	return 0;
}

//////// Functions ////////
float divide(float dividend, float divisor){
	if(divisor == 0)
		return 0;
	else
		return (dividend/divisor);
}

float minimum(float value1, float value2){
	if(value1 < value2)
		return value1;
	else
		return value2;
}

float get_value(){
	float temp_value;
		cout << "Enter a value: ";
		cin >> temp_value;
		return temp_value;
}

void print_menu(){
	cout << endl;
	cout << "Add (1)" << endl;
	cout << "Subtract (2)" << endl;
	cout << "Divide (3)" << endl;
	cout << "Minimum (4)" << endl;
	cout << "Exit (0)" << endl;
	cout << "Enter your choice: ";
}
