/*******************
Jonathan Hanson
CS 120 - 01
Sept 24, 2013
Lab 4 Part 1
*******************/
#include<iostream>
using namespace std;

int main(){
	int print_num;
	string message = "Hi there.";

	cout << "\n\nLab 4: Part 1\n\n";
	cout << "Input an integer: ";
	cin >> print_num;
	while(int(print_num) > 0){
		cout << message << endl;
		print_num--;
	}
}
