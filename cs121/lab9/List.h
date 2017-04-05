#include<iostream>
#include<iomanip>
using namespace std;

class List{
private:
	struct Node{
		int data;
		Node * next;
	};
	typedef Node * NodePtr;

	NodePtr head;
	int count;
public:
	List();
	~List();
	
	void AddToEnd(int);
	int RemoveFromFront();
	void PrintList();
	int IsEmpty();
};
