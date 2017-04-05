/********************
Jonathan Hanson
CS 120 - 01
Oct 29, 2013
Lab #9

The program works as assigned.

********************/

#include<iostream>
#include<cstdlib>
#include<string>
#include"line.h"
using namespace std;

int main(){
	int i,example_length;
	string inl;
	char example[100],tocount;
	
	cout << "\nInput a line of text to be used for line 2:\n";
	getline(cin,inl);

	for(i=0;i<inl.length();i++)
		example[i]=inl.at(i);
	
	example_length = inl.length();
	
	line line1,line2(example,example_length);
	
	cout << "\n\n   Line 1 (from default constructor)\n";
	cout << "Length of line: " << line1.get_length() << endl;
	cout << "Line is: ";
	line1.print();
	cout << endl;
	cout << "First char is: " << line1.first() << endl;
	cout << "Last char is: " << line1.last() << endl;
	cout << "Choose a character to count: ";
	cin >> tocount;
	cout << tocount << " appears " << line1.count(tocount) << " times." << endl;

	cout << "\n\n   Line 2 (from constructor using arguments)\n";
	cout << "Length of line: " << line2.get_length() << endl;
	cout << "Line is: ";
	line2.print();
	cout << endl;
	cout << "First char is: " << line2.first() << endl;
	cout << "Last char is: " << line2.last() << endl;
	cout << "Choose a character to count: ";
	cin >> tocount;
	cout << tocount << " appears " << line2.count(tocount) << " times." << endl;
}
