#include<iostream>
using namespace std;
#include"node.h"

node::node(){
   value = 0;
   next = NULL;
}

void node::set(int v){
   value = v;
}

void node::print(){
   cout << value << endl;
   if(next != NULL)
       next->print();
}

void node::insert(node *n){
   n->next = next;
   next = n;
}

void node::insert(int i){
	node *n;
	n->value = value;
	n->next = next;
	value = i;
	next = n;
}

void node::print_evens(){
	if(value % 2 == 0)
		cout << value << endl;
	if(next != NULL)
		next->print_evens();
}

// needs an insert(int) function
// needs a print_evens() function
