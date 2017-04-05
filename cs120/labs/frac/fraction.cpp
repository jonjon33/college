#include<iostream>
#include<cmath>
#include"fraction.h"
using namespace std;

fraction::fraction(){
	numerator=0;
	denominator=1;
}

fraction::fraction(int a, int b){
	numerator = a;
	denominator= b;
}

int fraction::getNum(){
	return numerator;
}

int fraction::getDen(){
	return denominator;
}

void fraction::setNum(int a){
	numerator = a;
}

void fraction::setDen(int b){
	if(b != 0){
		denominator = b;
	}else{
		cout << "ERROR: Divide by 0. '1' has been used instead";
		denominator = 1;
	}
}

bool fraction::equals(fraction b){
	if(numerator == b.numerator && denominator == b.denominator){
		return true;
	}else{
		return false;
	}
}

fraction fraction::add(fraction b){
	int commonden,sumnum;
	
	commonden = denominator*b.denominator;
	sumnum = (numerator*b.denominator) + (b.numerator*denominator);
	
	return fraction(sumnum,commonden);
}

void fraction::reduce(){
	int i;
	for(i=2;i<numerator||i<denominator;i++){
		if(numerator % i == 0 && denominator % i == 0){
			numerator /= i;
			denominator /= i;
			i = 1;
		}
	}
}
