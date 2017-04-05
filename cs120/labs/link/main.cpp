/**************************************
Jonathan Hanson
CS 120 - 01
December 3, 2013
Lab #13

All the assigned changes have been made
to the linked list program.

**************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#include"node.h"

int main(){
	srand(time(NULL));
	node head;
	head.set(-99);
	node *n;
	for(int i = 0; i < 10; i++){
		n = new node;
		n->set(i);
		head.insert(n);
	}
	head.print();

	node head2;
	head2.set(-99);

	for(int i=0;i<19;i++){
		n = new node;
		n->set(rand());
		head2.insert(n);
	}

	cout << "All values:" << endl;
	head2.print();
	cout << endl << "Just the evens:" << endl;
	head2.print_evens();
}
