#include"List.h"

List::List()
{
	head = NULL;
	count = 0;
}

List::~List()
{

}

void List::AddToEnd( int data )
{
	NodePtr n = new Node;

	n->data = data;
	n->next = NULL;

	if( head == NULL )
	{
		head = n;
	}
	else
	{
		NodePtr p = new Node;
		p = head;
		while ( p->next != NULL )
			p = p->next;
		p->next = n;
	}
	count++;
}

int List::RemoveFromFront()
{
	int retVal = 0;
	if( head == NULL )
	{
		cout << "Error: Can't remove from empty list" << endl;
	}
	else
	{
		NodePtr del = new Node;
		retVal = head->data;
		del = head;
		head = head->next;
		del->next = NULL;
		delete del;
		count--;
	}
	return retVal;
}

void List::PrintList()
{
	if( head == NULL )
	{
		cout << "The List is Empty" << endl;
	}
	else
	{
		NodePtr p = new Node;
		p = head;
		while( p != NULL )
		{
			cout << setw(3) << p->data;
			if( p == head )
			{
				cout << " (head)" << endl;
			}
			else
			{
				cout << endl;
			}
			p = p->next;
		}
	}
}

int List::IsEmpty()
{
	if( head == NULL )
		return 1;
	else
		return 0;
}
