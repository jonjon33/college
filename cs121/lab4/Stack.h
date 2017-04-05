#include<iostream>
using namespace std;

class Stack{
private:
    struct Node{
        char info;
        Node * next;
    };

    typedef Node * NodePtr;
    NodePtr head;

public:
    Stack();

    void Push( char );
    char Pop();
    void PrintAll();
    int IsEmpty();
};

