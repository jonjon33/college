#include<iostream>
#include<cmath>
#include"rect.h"
using namespace std;

rect::rect(){
	w = 1;
	h = 1;
	x = 0;
	y = 0;
}
void rect::get_w(){
	cout << "\nInput any value for the width: ";
	cin >> w;
	if(w < 0) w = 0;
}
void rect::get_h(){
	cout << "Input any value for the height: ";
	cin >> h;
	if(h < 0) h = 0;
}
void rect::get_pos(){
	cout << "Input an integer value for the x position: ";
	cin >> x;
	cout << "Input an integer value for the y position: ";
	cin >> y;
}
void rect::print(){
	cout << "\nPosition: " << x << "," << y;
	cout << "\nWidth: " << w;
	cout << "\nHeight: " << h << endl;
}
void rect::area(){
	double a;
	a = w*h;
	cout << "\nArea: " << a << endl;
}
void rect::perimeter(){
	double p;
	p = 2*w+2*h;
	cout << "\nPerimeter: " << p << endl;
}
void rect::distance(){
	double d;
	d = sqrt(double(x)*double(x)+double(y)*double(y));
	cout << "\nDistance: " << d << endl;
}
