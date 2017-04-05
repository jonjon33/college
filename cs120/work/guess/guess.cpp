/**********************************
Jonathan Hanson
CS 120 - 01
Sept 20, 2013
Assignment #3

This program does everything necessary to recieve full credit.
Additionally, I have allowed the player to decide the upper
boundary of the computer's random number and the program
keeps track of the number of games the player has won.

**********************************/
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(){

	int max_num;
	int random_num;
	int guess;
	int guess_counter;
	int score = 0;
	char play_again;
	srand(time(NULL));
	
	do {	
		guess_counter = 0;
		cout << "\n\n + - + - + - Guess my Number! - + - + - + \n\n";
		cout << "Guess my Number is a simple guessing game.\n";
		cout << "I'll think of a random integer between one and\n";
		cout << "whichever number you choose, and you'll try to\n";
		cout << "guess it.\n";
		
		cout << "\nWhat is the highest number I can choose? ";
		cin >> max_num;
		
		while (max_num <= 1){
			cout << "\nThat input won't work, try again: ";
			cin >> max_num;
		}
		
		random_num = 1 + rand() % max_num;
		
		cout << "\nI've got my number.\n";
		
		do{
			if (guess_counter < 1)
				cout << "\nMake a guess: ";
			else
				cout << "\nMake another guess: ";
			cin >> guess;
			while (guess < 1 || guess > max_num){
				cout << "\nThat input won't work, try again: ";
				cin >> guess;
			}
			guess_counter++;
			if(guess < random_num) cout << "\nToo small.";
			if(guess > random_num) cout << "\nToo large.";
			

			
		}while(guess != random_num);
	
	score++;
	
	cout << "\nCongratulations, you've guessed the number!";
	if (guess_counter == 1)
		cout << "\nIt took you " << guess_counter << " guess!!!";
	else
		cout << "\nIt took you " << guess_counter << " guesses.";
	
	if (score == 1)
		cout << "\nYou've won " << score << " game.";
	else
		cout << "\nYou've won " << score << " games.";
	cout << "\nWould you like to play again? (y/n): ";
	cin >> play_again;
	
	}while (play_again == 'y');

	cout << "\nGoodbye!\n\n";
}
