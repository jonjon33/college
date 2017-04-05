#include<iostream>
#include<cmath>
#include<string>
#include"line.h"
using namespace std;

line::line(){
	length = 0;
}

line::line(char a[], int l){
	int i;
	length = l;
	for(i=0;i<length&&i<100;i++)
		the_line[i]=a[i];
}

int line::get_length(){
	return length;
}

void line::print(){
	int i;
	for(i=0;i<length;i++)
		cout << the_line[i];
}

char line::first(){
	return the_line[0];
}

char line::last(){
	return the_line[(length-1)];
}

int line::count(char c){
	int count = 0, i;
	for(i=0;i<length;i++){
		if(the_line[i]==c){
			count++;
		}
	}
	return count;
}
