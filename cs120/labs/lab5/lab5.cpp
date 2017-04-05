#include<iostream>
using namespace std;
double func(int);

int main(){
    int x,y = 5;
    double answer; 
    // line 1
    cout << x << "   " << y << "   " << answer << endl;   
    cout << "Please enter an integer: ";
    cin >> x;
    answer = func(x);
    // line 2
    cout << x << "   " << y << "   " << answer << endl;
    answer = answer * y;
    // line 3
    cout << x << "   " << y << "   " << answer << endl;
    cout << "The answer is " << answer << endl;
}

double func(int g){
    double y = 0;
    double answer = 0;
    // line 4
    cout << y << "   " << answer << "   " << g << endl;
    answer = g;
    y = answer/2;
    // line 5
    cout << y << "   " << answer << "   " << g << endl;
    return y;
}
