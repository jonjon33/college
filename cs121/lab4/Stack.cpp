#include<iostream>
using namespace std;

#include"Stack.h"

Stack::Stack()
{
    head = NULL;
}

void Stack::Push( char ch )
{
    NodePtr n = new Node;   //Allocate

    n->info = ch;           //Initialize
    n->next = NULL;

    if( head == NULL )      //Place (empty list)
    {
        head = n;
    }
    else                    //Place (traverse then place)
    {
        NodePtr p = new Node;
        p = head;
        while( p->next != NULL )
        {
            p = p->next;
        }
        p->next = n;
    }
}

char Stack::Pop()
{
    char retVal = '\n';

    if( head == NULL )
    {
        cout << "Error: Can't pop from empty list" << endl;
    }
    else
    {
        NodePtr curr = head;
        NodePtr prev = NULL;

        while( curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }

        if( prev == NULL )
        {
            head = NULL;
        }
        else
        {
            prev->next = NULL;
        }

        retVal = curr->info;
        delete curr;
    }
    return retVal;
}

void Stack::PrintAll()
{
    if( head == NULL )
    {
        cout << "The Stack is Empty" << endl;
    }
    else
    {
        NodePtr p = head;
        while( p != NULL )
        {
            cout << p->info << endl;
            p = p->next;
        }
    }
}

int Stack::IsEmpty()
{
    if( head == NULL )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

