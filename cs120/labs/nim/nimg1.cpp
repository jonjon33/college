/*  Jonathan Hanson
 * CS120 - 01
 * Sept 17, 2013
 * Lab #3
 *
 * NIM with graphical output using a do-while loop.
 *
 *
 * The Game of NIM -
 * A simple program introducing some
 * fundamental programing concepts
 */
//////// INCLUDES ////////
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;

//////// MAIN ////////
int main()
{
//////// VARIABLE DECLARATIONS ////////
	int num_objects;
	int max_take;
	int current_player;
	int move;
	int comment;
	int graphic;
	int cwins = 0;
	int pwins = 0;
	char object = '#';
	string play_again;
	srand(time(NULL));

//////// STRING VARIATIONS ////////
	string com1 = "This will make for an interesting game.";
	string com2 = "Those will do nicely.";
	string com3 = "This will be a rather long game; good thing only one of us ages.";
	string com4 = "Why don't you just watch paint dry instead. It will go by faster.";
	string com5 = "Don't have a long enough attention span for a real game?";
	string com6 = "Perhaps next time you'll select more enjoyable parameters.";
	string comend1 = "I am not surprised that your feeble mind was unable to defeat me.";
	string comend2 = "Alas, I have been bested.  Congratulations!";


//////// INTRO SEQUENCE ////////
	cout << "\n\nWelcome to NIM.\nI am your computer opponent, and likely your intellectual superior.\nYou and I will take turns taking objects from a pile.\nWhoever takes the last object loses.\nGood luck, you'll need it.";

//////// GAME LOOP ////////
	do {
		if( cwins==0 && pwins==0 ){ //First Time Through
			cout << endl << "\nSince I'm feeling generous, you may select the number of objects in the pile. (input a postive integer): ";
			cin >> num_objects;
			cout << "Additionally, you may select the largest quantity of objects you or I can take in a turn. (input a postive integer): ";
			cin >> max_take;
		}else{
			cout << endl << "\nHow many objects would you like in the pile this time? ";
			cin >>  num_objects;
			cout << "What is the largest quantity of objects a player may take this time? ";
			cin >> max_take;
		}
		
		comment = 1 + rand() % 2;
		if (num_objects/max_take < 2) comment = 5 + rand() % 2;
		if (num_objects/max_take > 18) comment = 3 + rand() % 2;
		
		cout << endl;
		if (comment == 1) cout << com1;
		if (comment == 2) cout << com2;
		if (comment == 3) cout << com3;
		if (comment == 4) cout << com4;
		if (comment == 5) cout << com5;
		if (comment == 6) cout << com6;

		cout << "\n\nUp to " << max_take << " objects can be taken in a turn.\n";
		
		graphic = 0;  //GRAPHICAL OUTPUT
		do{
			if (graphic % 10 == 0)
				cout << endl << object << "   ";
			else
				cout << object << "   ";
			graphic++;
		}while (graphic < num_objects);
		
		cout << endl << num_objects  << " objects remaining\n";

		current_player = 1 + rand() % 2;
		if (current_player == 1)
			cout << "\nI have randomly decided that you will go first.\n";
		else
			cout << "\nI have randomly decided that I will go first.\n";

//////// MAKING MOVES ////////
		do {
			if (current_player == 1){
				cout << "\nEnter your move (1-" << max_take << "): ";
				cin >> move;
				while (move < 1 || move > max_take || move > num_objects){
					cout << "Illegal move. \nEnter a new move between 1 and " << max_take << ": ";
					cin >> move;
				}
			} else {
				if (num_objects == 1){
					move = 1;
				}else{
					if (max_take > num_objects){
						move = num_objects - 1;
					}else{
						move = (num_objects-1) % (max_take + 1);
						if (move == 0){
							move = 1 + rand() % max_take;
						}
					}
				}
				cout << "\nI remove " << move << endl;
			}
			num_objects = num_objects - move;
			
			if (num_objects != 0){ //GRAPHIC OUTPUT
		                graphic = 0; 
	        	        do{
	                        	if (graphic % 10 == 0)
	                                	cout << endl << object << "   ";
        	                	else
	                                	cout << object << "   ";
	                        	graphic++;
	                	}while (graphic < num_objects);
			}

			cout << endl << num_objects << " objects remaining. \n";

			current_player = (current_player+1) % 2;
		} while (num_objects > 0);

//////// ENDING SEQUENCE ////////
		if (current_player == 0){
			cwins++;
			cout << endl << comend1 << endl;
		} else {
			pwins++;
			cout << endl << comend2 << endl;
		}
		cout << "\nYou have won " << pwins << " games and I have won " << cwins << " games.\n";
		cout << "\nWould you like to play again? ";
		cin >> play_again;
	} while (play_again == "Yes" || play_again == "yes" || play_again == "Y" || play_again == "y" || play_again == "Sure" || play_again == "sure"); // END GAME LOOP
	cout << "\nGoodbye!\n" << endl;
	return 0;
}
