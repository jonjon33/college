/**************************
Jonathan Hanson
CS 120 - 01
October 8, 2013
Lab #6

All the assigned changes to the program have been made.
The written portion of the assignment was added to the script file.
**************************/
#include<iostream>
#include<string>
using namespace std;

class pet{
private:
	int hunger;
	int happy;
	string name;
public:
	pet();
	void play();
	void feed();
	void print();
	int check_health();
};

int main(){
	pet pet1;
	int choice;
	int health_check;
	do{
		pet1.print();
		cout << "What would you like to do with your pet?\n";
		cout << " Play (1) \n Feed (2) \n Exit (0) \n";
		cin >> choice;
		switch(choice){
		case 0:
			break;
		case 1:
			pet1.play();
			break;
		case 2:
			pet1.feed();
			break;
		default:
			cout << "\nInvalid choice.\n";
			break;
		}
		health_check = pet1.check_health();
	}while(choice != 0 && health_check != 1);
	cin.ignore();
	cout << "\nPress enter to exit." << endl;
	cin.ignore();
	return 0;
}

pet::pet(){
	hunger = 50;
	happy = 50;
	cout << "Pet's name? (one word) ";
	cin >> name;
}

void pet::play(){
	int choice = 0;
	do{
		cout << "\nWhat should we play?\n";
		cout << " Fetch (1) \n Roll over (2) \n Peek-a-Boo (3) \n Main Menu (0) \n";
		cin >> choice;
		switch(choice){
		case 0:
			break;
		case 1:
			happy += 10;
			hunger += 5;
			cout << "\nI sure love fetch, but now I'm tired!\n";
			break;
		case 2:
			happy += 5;
			hunger += 1;
			cout << "\nWeeeeee!\n";
			break;
		case 3:
			happy +=2;
			hunger +=2;
			cout << "\nYour face is so weird.\n";
			break;
		default:
			cout << "Not a valid choice.\n";
			choice = -1;
			break;
		}
	}while(choice == -1);
}

void pet::feed(){
	int choice = 0;
	do{
		cout << "\nWhat will you feed me?\n";
		cout << " Generic Pet Food (1) \n Fancy Pet Food (2) \n Main Menu (0) \n";
		cin >> choice;
		switch(choice){
		case 0:
			break;
		case 1:
			hunger -= 2;
			cout << "\nIt's better than starving, I guess.\n";
			break;
		case 2:
			hunger -= 5;
			cout << "\nMMM, Yummy!\n";
			break;
		default:
			cout << "Not a valid choice.\n";
			choice = -1;
			break;
		}
	}while(choice == -1);
}

void pet::print(){
	cout << "\nYour pet " << name << " is " << endl;
	cout << "Happy: " << happy << endl;
	cout << "Hungry: " << hunger << endl;
}

int pet::check_health(){
	if(hunger >= 100){
		cout << "\nYour pet has starved.\n";
		return 1;
	}
	if (happy <= 0){
		cout << "\nYour pet has died of a broken heart.\n";
		return 1;
	}
	return 0;
}
