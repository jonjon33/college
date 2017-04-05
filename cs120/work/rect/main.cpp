/********************
Jonathan Hanson
CS 120 - 01
October 18, 2013
Assignment #7

The rect class contains all the assigned methods
and the program runs in a simple menu format.

********************/

#include<iostream>
#include<cmath>
#include"rect.h"
using namespace std;

void print_menu();

int main(){
	int choice;
	rect r;
	cout << "\nRectangle Creator\n";
	r.get_w();
	r.get_h();
	r.get_pos();
	r.print();
	do{
		print_menu();
		cin >> choice;
		switch(choice){
		case 0:
			choice = -1;
			break;
		case 1:
			r.get_w();
			r.get_h();
			r.get_pos();
			r.print();
			break;
		case 2:
			r.print();
			break;
		case 3:
			r.area();
			break;
		case 4:
			r.perimeter();
			break;
		case 5:
			r.distance();
			break;
		default:
			cout << "Invalid input.\n";
			break;
		}
	}while(choice != -1);
	cout << "\nGoodbye!\n\n";
	return 1;
}

void print_menu(){
	cout << "\n Enter New Values (1)";
	cout << "\n Reprint Current Values (2)";
	cout << "\n Calculate Area (3)";
	cout << "\n Calculate Perimeter (4)";
	cout << "\n Calculate Distance from Origin (5)";
	cout << "\n Exit (0)";
	cout << endl;
}
