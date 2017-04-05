#include<iostream>
#include"List.h"
using namespace std;

int main()
{
	List L1, L2;
	L1.AddToEnd(3);
	L1.AddToEnd(6);
	L1.AddToEnd(9);
	L2.AddToEnd(2);
	L2.AddToEnd(4);
	L2.AddToEnd(8);
	
	L1.PrintList();
	L2.PrintList();

	return 0;
}
