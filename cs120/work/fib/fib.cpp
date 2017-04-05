#include<iostream>
using namespace std;

int fib(int,int&);

int main(){
	int value;
	char loop;
	int count = 0;
	do{
		cout << "What Fibonacci number would you like? ";
		cin >> value;
		cout << "The " << value;
		switch(value%10){
		case 1:
			cout << "st";
			break;
		case 2:
			cout << "nd";
			break;
		case 3:
			cout << "rd";
			break;
		default:
			cout << "th";
			break;
		}
		cout << " Fibonacci number is: " << fib(value,count) << endl;
		cout << "It required " << count << " function calls.\n";
		cout << "Run again? (y/n) ";
		cin >> loop;
		count = 0;
	}while(loop == 'y');
	cout << endl;
}

int fib(int x,int& c){
   c++;
   if(x == 0){
      return 0;
   }
   if(x == 1){
      return 1;
   }
   return(fib(x-1,c) + fib(x-2,c));
}
