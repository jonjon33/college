#include "Stack.h"

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{

}

void Stack::Push( int data )
{
	NodePtr n = new Node;

	n->data = data;
	n->next = NULL;

	if( top == NULL )
	{
		top = n;
	}
	else
	{
		n->next = top;
		top = n;
	}
}

int Stack::Pop()
{
	int retVal = 0;

	if( top == NULL )
	{
		cout << "Error: Can't pop from empty stack" << endl;
	}
	else
	{
		NodePtr del = new Node;
		retVal = top->data;
		del = top;
		top = top->next;
		del->next = NULL;
		delete del;
	}

	return retVal;
}

void Stack::PrintStack()
{
	if( top == NULL )
	{
		cout << "The Stack is empty" << endl;
	}
	else
	{
		NodePtr p = top;
		cout << "Stack Contents:" << endl;
		while( p != NULL )
		{
			cout << setw(3) << p->data;
			if( p == top )
				cout << " (top)" << endl;
			else
				cout << endl;
			
			p = p->next;
		}
	}
}

int Stack::IsEmpty()
{
	if( top == NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
