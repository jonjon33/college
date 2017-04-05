#include<iostream>
using namespace std;

class linkedlist{
private:
	int count;
	node *head;
public:
	linkedlist();
	void insert(robot *);
	void print();
	void forward();
	void forward(int);
	void turnLeft();
	void turnLeft(int);
	void turnRight();
	void turnRight(int);
	void remove(int);
};

linkedlist::linkedlist(){
	head = NULL;
	count = 0;
}

void linkedlist::insert(robot *rp){
	node *n;
	n = new node;
	n->set_data(rp);
	n->set_next(head);
	head = n;
	count++;
}

void linkedlist::remove(int n){
	if(head == NULL)
		return;
	if((head->get_data())->getID() == n){
		node *temp;
		temp = head;
		head = head->get_next();
		temp -> remove_data();
		delete temp;
		count--;
	}else{
		if(head->remove(n) == 1)
			count--;
	}
}

void linkedlist::print(){
	cout << "There are " << count;
	cout << " robots in the list: \n";
	if(head != NULL)
		head->print();
}

void linkedlist::forward(){
	if(head != NULL)
		head->forward();
}

void linkedlist::forward(int id){
	if(head == NULL)
		return;
	if((head->get_data())->getID() == id)
		(head->get_data())->forward();
	else
		head->forward(id);
}

void linkedlist::turnLeft(){
	if(head != NULL)
		head->turnLeft();
}

void linkedlist::turnLeft(int id){
	if(head == NULL)
		return;
	if((head->get_data())->getID() == id)
		(head->get_data())->turnLeft();
	else
		head->turnLeft(id);
}

void linkedlist::turnRight(){
	if(head != NULL)
		head->turnRight();
}

void linkedlist::turnRight(int id){
	if(head == NULL)
		return;
	if((head->get_data())->getID() == id)
		(head->get_data())->turnRight();
	else
		head->turnRight(id);
}
