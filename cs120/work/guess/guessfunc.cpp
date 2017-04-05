/**********************************
Jonathan Hanson
CS 120 - 01
Oct 4, 2013
Assignment #5

All the assigned changes have been made.

**********************************/
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int pick_value(int);
int get_guess(int);
int high_low(int,int);

int main(){
	
	int guess_counter;
	int max_num;
	int random_num;
	int guess;
	int check;
	int score = 0;
	char play_again;
	
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

                random_num = pick_value(max_num);

                cout << "\nI've got my number.\n";

                do{
			guess = get_guess(max_num);
                        guess_counter++;
			check = high_low(random_num,guess);
                }while(check ==0);
		
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
		while ( play_again != 'n' && play_again != 'y'){
			cout << "\nThat input won't work, try again: ";
			cin >> play_again;
		}

	}while (play_again == 'y');
	cout << "\nGoodbye!\n\n";
}

int pick_value(int max){
	int random;
	srand(time(NULL));

	random = 1 + rand()% max;

	return random;
}

int get_guess(int max){
	int guess = 0;
	cout << "\nEnter your guess: ";
	cin >> guess;
	while (guess < 1 || guess > max){
		cout << "Error: Please enter a value between 1 and " << max << ": ";
		cin >> guess;
	}
	
	return guess;
}

int high_low(int random, int guess){
	if (random > guess){
		cout << "Too low.\n";
		return 0;
	}
	if (random < guess){
		cout << "Too high.\n";
		return 0;
	}
	if (random == guess){
		return 1;
	}
}
