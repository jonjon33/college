// Jonathan Hanson
// CS 120 - 01
// Sept 6, 2013
// The game of Nim
#include<iostream>
#include<cstdlib>
using namespace std;
int main() {
    int num_objects = 23;
    int current_player = 1; 
    int move;
    cout << "Remove 1-3 objects, try to force your opponent to remove the last one." << endl;
    do { // beginning of the game loop
        cout << num_objects << " objects left!" << endl;
        if (current_player == 1) { // user's move
            do {
                cout << "Your move: ";
                cin >> move;
            } while (move < 1 || move > 3 || move > num_objects);
        } else { // computer's move
            do {
                move = 1 + rand() % 3;
            } while (move < 1 || move > 3 || move > num_objects);
            cout << "Computer removed " << move << endl;
        }
        num_objects = num_objects - move; // adjust objects
        current_player = (current_player + 1) % 2; // adjust turn
    } while (num_objects > 0); // end of the game loop
    cout << "Player " << current_player << " wins!!!" << endl;
    return 0;
}
