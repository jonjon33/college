#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class robot{
private:
	int direction;
	int energy;
	int ID;
	int moved;
public:
	robot(int);
	void forward();
	void turnLeft();
	void turnRight();
	void refresh() {moved = 0;}
	void draw();
	void print();
//	void move(int &, int &);
	int getID() {return ID;}
};

void robot::turnLeft(){
	energy--;
	direction = (direction + 3) % 4;
}
void robot::turnRight(){
	energy--;
	direction = (direction + 1) % 4;
}
void robot::forward(){
	energy -= 2;
}
robot::robot(int id){
	energy = 50;
	ID = id;
	moved = 0;
	direction = 0;
}
void robot::draw(){
	switch(direction){
	case 0:
		cout << "^";
		break;
	case 1:
		cout << ">";
		break;
	case 2:
		cout << "v";
		break;
	case 3:
		cout << "<";
		break;
	}
}
void robot::print(){
	cout << "Robot " << ID << ": Energy = " << energy << "   Direction = " << direction;
}
/*
void robot::move(int &x, int &y){
	if(moved == 1)
		return;
	switch(rand()%4){
	case 0:
		turnLeft();
		break;
	case 1:
		turnRight();
		break;
	case 2:
	case 3:
		forward(x,y);
		break;
	default:
		cout << "Error in robot move." << endl;
	}
	moved = 1;
}
*/
