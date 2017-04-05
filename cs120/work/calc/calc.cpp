/***************
Jonathan Hanson
CS 120 - 01
Sept 24, 2013
Assignment 4

I used the program I made in lab as a base for this assignment, meaning I
completed 3.4 problems 1, 2, 3, 4, 5, 7 and 3.4.1 problem 1.
***************/
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;

//////// Function Prototypes ////////
void print_menu();
float get_value();
float divide(float,float);
float minimum(float,float);
float cartdist(float,float,float,float);

//////// Main ////////
int main() {
	float operand1, operand2, operand3, operand4, answer;
	int choice, valid_choice;
	string operation;
	srand(time(NULL));
	
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
			operation = " + ";
			answer = operand1 + operand2;
			break;
		case 2:
			cout << "\nSubtraction Calculator\n";
			operand1 = get_value();
			operand2 = get_value();
			operation = " - ";
			answer = operand1 - operand2;
			break;
		case 3:
			cout << "\nDivision Calculator\n";
			operand1 = get_value();
			operand2 = get_value();
			operation = " / ";
			answer = divide(operand1,operand2);
			break;
		case 4:
			cout << "\nMinimum Calculator\n";
			operand1 = get_value();
			operand2 = get_value();
			operation = "Min of ";
			answer = minimum(operand1,operand2);
			break;
		case 5:
			cout << "\nCartesian Distance\n";
			operand1 = get_value();
			operand2 = get_value();
			operand3 = get_value();
			operand4 = get_value();
			operation = "Cartesian distance of ";
			answer = cartdist(operand1,operand2,operand3,operand4);
			break;
		case 6:
			cout << "\nRandom Number\n";
			operand1 = get_value();
			operation = "Random number between 0 and ";
			while(operand1 < 0){
				cout << "Error: Please input positive value\n";
				operand1 = get_value();
			}
			answer = 1 + rand() % int(operand1);
			break;
		case 7:
			cout << "\nSine\n";
			operand1 = get_value();
			operation = "Sine of ";
			answer = sin(operand1 * (3.14159 / 180));
			break;
		case 8:
			cout << "\nVolume of Cylinder\n";
			operand1 = get_value();
			operand2 = get_value();
			operation = "Volume of cylinder with radius and height ";
			while(operand1 < 0 || operand2 < 0){
				cout << "Error: Input positive values\n";
				operand1 = get_value();
				operand2 = get_value();
			}
			answer = 3.14159 * operand1 * operand1 * operand2;
			break;
		default:
			valid_choice = 0;
			cout << "Invalid Choice." << endl;
		}
		if(valid_choice && choice != 0){
			if(choice <= 3) cout << endl << operand1 << operation << operand2 << " = " << answer << endl;
			if(choice == 4 || choice == 8) cout << endl << operation << operand1 << " and " << operand2 << " = " << answer << endl;
			if(choice == 5) cout << endl << operation << operand1 << ", " << operand2 << " and " << operand3 << ", " << operand4 << " = " << answer << endl;
			if(choice == 6 || choice == 7) cout << endl << operation << operand1 << " = " << answer << endl;
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

float cartdist(float x1,float y1,float x2,float y2){
	if(x2-x1 == 0)
		return 0;
	else
		return sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));

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
	cout << "Cartesian Distance (5)" << endl;
	cout << "Random Number (6)" << endl;
	cout << "Sine (7)" << endl;
	cout << "Volume of Cylinder (8)" << endl;
	cout << "Exit (0)" << endl;
	cout << "Enter your choice: ";
}
