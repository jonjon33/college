/**************************
Jonathan Hanson
CS 120 - 01
October 15, 2013
Lab #7

The user can now save his/her pet in the main menu
and is prompted to save upon exiting the program.
The saved pet can be loaded in the start menu.
As an additional improvement, I made it so that
the pet's hunger cannot go below zero and its
happyness cannot exceed 100. The pet communicates
when it can no longer accept food or be any
happier.

**************************/
#include<iostream>
#include<fstream>
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
	void save();
};

int main(){
	pet pet1;
	int choice;
	int health_check;
	char saveprompt;
	do{
		pet1.print();
		cout << "What would you like to do with your pet?\n";
		cout << " Play (1) \n Feed (2) \n Save (3) \n Exit (0) \n";
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
		case 3:
			pet1.save();
			break;
		default:
			cout << "\nInvalid choice.\n";
			break;
		}
		health_check = pet1.check_health();
	}while(choice != 0 && health_check != 1);
	if(health_check != 1){
		cout << "\nWould you like to save this pet? (y/n) ";
		cin >> saveprompt;
		if (saveprompt == 'y'){
			pet1.save();
			cout << "Saved!\n";
		}
		cout << "\nGoodbye!\n\n";
	}
	return 0;
}

pet::pet(){
	int choice;
	cout << "\nPet Simulator\n";
	do{
		cout << "\n New Game (1)\n Load Game (2)\n";
		cin >> choice;
		switch(choice){		
		case 1:
			hunger = 50;
			happy = 50;
			cout << "Choose a name for your pet (one word): ";
			cin >> name;
			choice = 0;
			break;
		case 2:
			cout << "\nWhat was the name of your pet? ";
			cin >> name;
			ifstream ifs;
			ifs.open(name.c_str());
			if(ifs.fail())
				cout << "That pet doesn't exist";	
			else
				choice = 0;
			ifs >> name;
			ifs >> hunger;
			ifs >> happy;
			ifs.close();
			break;
		}
	}while(choice!=0);
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
			if(happy > 100) cout << "\nI couldn't possibly be any happier!\n";
			else cout << "\nI sure love fetch, but now I'm tired!\n";
			break;
		case 2:
			happy += 5;
			hunger += 1;
			if(happy > 100) cout << "\nI couldn't possibly be any happier!\n";
			else cout << "\nWeeeeee!\n";
			break;
		case 3:
			happy +=2;
			hunger +=2;
			if(happy > 100) cout << "\nI couldn't possibly be any happier!\n";
			else cout << "\nYour face is so weird.\n";
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
			if(hunger < 0) cout << "\nBut I'm FULL.\n";
			else cout << "\nIt's better than starving, I guess.\n";
			break;
		case 2:
			hunger -= 5;
			if(hunger < 0) cout << "\nBut I'm FULL.\n";
			else cout << "\nMMM, Yummy!\n";
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
		cout << "\nYour pet has starved.\n\n";
		return 1;
	}
	if(hunger < 0) hunger = 0;
	if (happy <= 0){
		cout << "\nYour pet has died of a broken heart.\n\n";
		return 1;
	}
	if(happy > 100) happy = 100;
	return 0;
}

void pet::save(){
	ofstream ofs;
	ofs.open(name.c_str());
	ofs << name << endl << hunger << endl << happy;
	ofs.close();
}
