#include<iostream>
#include"Stack.h"
#include"List.h"
using namespace std;

void zipList(List&,List&,List&);
void removeNegative(List&);

int main()
{
	Stack S;
	List L1, L2, L3, Lzip;

	cout << "Exam Questions Coded" << endl;
	cout << "Part 1:" << endl;
	cout << "Stack method interface defined in Stack.h" << endl;
	cout << "Printing an empty Stack" << endl;
	S.PrintStack();
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
	cout << "Pop four values from the stack";
	S.Pop();
	S.Pop();
	S.Pop();
	S.Pop();
	S.PrintStack();

	cout << "\n\n" << endl;

	cout << "Part 2:" << endl;
	cout << "Zip function" << endl;
	cout << "Lists 1 and 2 created with AddToEnd(int)" << endl;
	L1.AddToEnd(1);
	L1.AddToEnd(3);
	L1.AddToEnd(5);
	L2.AddToEnd(2);
	L2.AddToEnd(4);
	L2.AddToEnd(6);
	cout << "L1:" << endl;
	L1.PrintList();
	cout << "L2:" << endl;
	L2.PrintList();
	cout << "Zipped List:" << endl;
	zipList(L1,L2,Lzip);
	Lzip.PrintList();

	cout << "\n\n" << endl;

	cout << "Part 3:" << endl;
	cout << "Remove netagive values function" << endl;
	cout << "List three is created with AddToEnd(int)" << endl;
	L3.AddToEnd(1);
	L3.AddToEnd(-2);
	L3.AddToEnd(3);
	L3.AddToEnd(-4);
	L3.AddToEnd(5);
	L3.AddToEnd(-6);
	cout << "L3:" << endl;
	L3.PrintList();

	cout << "L3 without Negatives:" << endl;
	removeNegative(L3);
	L3.PrintList();

	return 0;	
}

void zipList(List& L1, List& L2, List& Lzip)
{
	Stack S;
	while( !L2.IsEmpty() )
		S.Push(L2.RemoveFromFront());
	while( !S.IsEmpty() )
		L2.AddToEnd(S.Pop());
	while( !L2.IsEmpty() )
	{
		Lzip.AddToEnd(L1.RemoveFromFront());
		Lzip.AddToEnd(L2.RemoveFromFront());
	}
}

void removeNegative(List& L3)
{
	List Ltemp;
	int readVal;
	while(!L3.IsEmpty())
	{
		readVal = L3.RemoveFromFront();
		if( readVal >= 0 )
			Ltemp.AddToEnd(readVal);
	}
	while(!Ltemp.IsEmpty())
	{
		L3.AddToEnd(Ltemp.RemoveFromFront());
	}
}
