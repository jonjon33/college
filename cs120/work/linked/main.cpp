/***************************
Jonathan Hanson
CS 120 - 01
December 6, 2013
Assignment #12

All the assigned changes have been made
and are demonstrated by parts added to
the main program.

***************************/
#include<iostream>
#include<cstdlib>
using namespace std;
#include"robot.h"
#include"node.h"
#include"linkedlist.h"
int main(){
	linkedlist ll;
	const int num_robots = 3;
	robot *robot_ptr;
	for(int i = 0; i < num_robots; i++){
		robot_ptr = new robot(i);
		ll.insert(robot_ptr);
	}
	ll.print();

	cout << "\nTurn all robots left:\n";
	ll.turnLeft();
	ll.print();

	cout << "\nDelete Robot 2, add Robot 99:\n";
	robot_ptr = new robot(99);
	ll.insert(robot_ptr);
	ll.remove(2);
	ll.print();

	cout << "\nRobot 1 left:\n";
	ll.turnLeft(1);
	ll.print();

	cout << "\nRobot 99 left twice:\n";
	ll.turnLeft(99);
	ll.turnLeft(99);
	ll.print();

	cout << "\nAll robots right:\n";
	ll.turnRight();
	ll.print();

	cout << "\nAll robots forward:\n";
	ll.forward();
	ll.print();

	cout << "\nRobot 0 forward 10 times:\n";	
	ll.forward(0);
	ll.forward(0);
	ll.forward(0);
	ll.forward(0);
	ll.forward(0);
	ll.forward(0);
	ll.forward(0);
	ll.forward(0);
	ll.forward(0);
	ll.forward(0);
	ll.print();
	return 0;
}
