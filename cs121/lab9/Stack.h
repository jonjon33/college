#include<iostream>
#include<iomanip>
using namespace std;

class Stack{
private:
	struct Node{
		int data;
		Node * next;
	};
	typedef Node * NodePtr;
	NodePtr top;
public:
	Stack();
	~Stack();
	void Push(int);
	int Pop();
	void PrintStack();
	int IsEmpty();
};
