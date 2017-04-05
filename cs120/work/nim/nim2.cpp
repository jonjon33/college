/* Jonathan Hanson
 * CS120 - 01
 * Sept 6, 2013
 * Assignment #1
 *
 * All the changes assigned have been applied, with an
 * additional conditional at the end that makes the
 * victory or defeat that much more satisfying or
 * frustrating respectively.
 * Everything functions properly (even the code I wrote!) with the
 * exception of non-integer user input, which I figure
 * we simply haven't learned how to deal with yet.
 *
 * The Game of NIM -
 * A simple program introducing some
 * fundamental programing concepts
 */
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int num_objects;
	int current_player = 1;
	int move;
	srand(time(NULL));
	cout << "\n\nWelcome to NIM.\nYou and your opponent take turns taking objects from a pile.\nYou may take between 1 and 3 objects in a turn.\nWhoever takes the last object loses.\nThink carefully!" << endl;
	cout << "\nHow many objects in the pile?(must be at least 5) ";
	cin >>  num_objects;
	do {
		if (num_objects < 5){
			cout << "That simply will not do; pick a number of objects. (must be at least 5) ";
			cin >> num_objects;
		}
	} while (num_objects < 5);

	cout << num_objects  << " objects remaining" << endl;
	do {
		if (current_player == 1){
			cout << "\nEnter your move (1-3): ";
			cin >> move;
			while (move < 1 || move > 3 || move > num_objects){
				cout << "Illegal move. \nEnter a new move between 1 and 3: ";
				cin >> move;
			}
		} else {
			do {
				move = 1 + rand() % 3;
			} while (move < 1 || move > 3 || move > num_objects);
			cout << "\nYour opponent removes " << move << endl;
		}
		num_objects = num_objects - move;
		cout << num_objects << " objects remaining. \n";
		current_player = (current_player+1) % 2;
	} while (num_objects > 0);
	if (current_player == 0){
	cout << "\nAlas, have been bested by the superior intellect of the computer.\n";
	} else {
	cout << "\nIn an astonishing display of utter brilliance, you defeat the computer!!!\n";
	}
	cin.ignore();
	cout << "\nPress enter to quit.\n";
	cin.ignore();
	return 0;
}
