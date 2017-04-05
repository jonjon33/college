/********************
Jonathan Hanson
CS 120 - 01
October 25, 2013
Assignments #8

The program functions as assigned.

********************/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main(){
	string fn;
	float val[100];
	int count;
	float largest;
	float smallest;
	float sum;
	float avg;
	float sdsum, sd;
	int i;

	cout << "\nFile Reader 9000\n";
	ifstream ifs;
	do{
		cout << "\nInput filename: ";
		cin >> fn;
		
		ifs.open(fn.c_str());
		if(ifs.fail()) cout << "\nError: Could not find file.\n";
	}while(ifs.fail());

	for(i=0;!ifs.eof();i++){
		ifs >> val[i];
	}
	count = i - 2;
	ifs.close();

	largest = val[0];
	for(i=1;i<=count;i++){
		if(val[i]>largest) largest = val[i];
	}

	smallest = val[0];
	for(i=1;i<=count;i++){
		if(val[i]<smallest) smallest = val[i];
	}
	
	for(i=0;i<=count;i++){
		sum += val[i];
	}
	
	avg = sum/(count+1);

	for(i=0;i<=count;i++){
		sdsum += (val[i]-avg)*(val[i]-avg);
	}
	sd = sqrt(sdsum/(count+1));

	for(i=0;i<=count;i++){
		if(i % 5 == 0 && i != 0){
			cout << endl;
		}
		cout << val[i] << " ";
	}

	cout << endl;
	cout << "\nNumber of Elements: " << count+1;
	cout << "\nMax: " << largest;
	cout << "\nMin: " << smallest;
	cout << "\nSum: " << sum;
	cout << "\nAverage: " << avg;
	cout << "\nStandard Deviation: " << sd;
	cout << endl;
	return 1;
}
