#include<iostream>
using namespace std;

class node{
private:
	node *next;
	robot *data;
public:
	node();
	void set_next(node *n) {next = n;}
	void set_data(robot *d) {data = d;}
	node *get_next() {return next;}
	robot *get_data() {return data;}
	void print();
	void forward();
	void forward(int);
	void turnLeft();
	void turnLeft(int);
	void turnRight();
	void turnRight(int);
	int remove(int);
	void remove_data() {delete data;}
};

node::node(){
	next = NULL;
	data = NULL;
}

void node::print(){
	if(next != NULL)
		next -> print();
	data->print();
	cout << endl;
}

/*
void node::oneLeft(){
	data -> turnLeft();
	data -> print();
	cout << endl;
}
*/

void node::forward(){
	data -> forward();
	if(next != NULL)
		next -> forward();
}

void node::forward(int id){
	if(next != NULL){
		if((next->data)->getID() == id)
			(next->data)->forward();
		else
			next->forward(id);
	}
}

void node::turnLeft(){
	data -> turnLeft();
	if(next != NULL)
		next -> turnLeft();
}

void node::turnLeft(int id){
	if(next != NULL){
		if((next->data)->getID() == id)
			(next->data)->turnLeft();
		else
			next->turnLeft(id);
	}
}

void node::turnRight(){
	data -> turnRight();
	if(next != NULL)
		next -> turnRight();
}

void node::turnRight(int id){
	if(next != NULL){
		if((next->data)->getID() == id)
			(next->data)->turnRight();
		else
			next->turnRight(id);
	}
}

int node::remove(int n){
	if(next != NULL){
		if((next -> data) -> getID() == n){
			node *temp;
			temp = next;
			next = next -> next;
			temp -> remove_data();
			delete temp;
			return(1);
		}else{
			return(next -> remove(n));
		}
	}
	return 0;
}

