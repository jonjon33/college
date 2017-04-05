#include<iostream>
#include"Stack.h"
using namespace std;

int main()
{
	Stack S;

	cout << "Push 1-10 to stack in order" << endl;
	S.Push(1);
	S.Push(2);
	S.Push(3);
	S.Push(4);
	S.Push(5);
	S.Push(6);
	S.Push(7);
	S.Push(8);
	S.Push(9);
	S.Push(10);

	S.PrintStack();

	cout << "Pop through 11 times (intentionally popping empty case)" << endl;
	S.Pop();
	S.Pop();
	S.Pop();
	S.Pop();
	S.Pop();
	S.Pop();
	S.Pop();
	S.Pop();
	S.Pop();
	S.Pop();
	S.Pop();

	S.PrintStack();

	return 0;	
}
