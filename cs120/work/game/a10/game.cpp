/**************************
Jonathan Hanson
CS 120 - 01
November 8, 2013
Assignment #10 AND Lab #10

All the assigned changes have been made for both the lab and the
assignment. On the day of lab, I was getting an error that I
couldn't fix at the time, so I worked throughout the week making
the changes for the lab and the assignment.

Assignment notes: The random move moves the player
forward or back 5 spaces, and the momentum added characteristic is
described in the game.

**************************/
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

class square{
private:
	int move;
	string message;
	char symbol;
public:
	square();
	void print();
	int action();
	char get_symbol();
	void set(int,char,string);
};

void print_board(square[],int,int);
void read_board(square[]);
void check_position(int&);

char p1,p2;
string name1,name2;
int current_game;
const int board_length = 36;

int main(){
	int current_player = 1, roll;
	int momentum1 = 0, momentum2 = 0;
	string current_name;
	int player1_position = 0, player2_position = 0;
	int skip1 = 0, skip2 = 0;
	char current_symbol;
	bool random_move;
	square the_board[board_length];
	srand(time(NULL));

	cout << "\n\nGame Master 9000\n\n";
	cout << "Choose your game:\n 1) Crew Racer II\n 2) Dragster Challenge\n";
	cin >> current_game;

	if(current_game==1){
		cout << "\n\nCrew Racer II\n\n";
		cout << "In Crew Racer II, player 1 controls the American\nOlympic Crew Team and player 2 controls the Canadian\nOlympic Crew Team as they compete for gold. Each\nplayer rolls to see how far his or her team rows on a\ngiven turn. The first player to reach the goal wins.\n\nSpecial Squares:\n ? Row backward to let ducklings cross, go back 2 squares\n * A tailwind blows you forward, advance 1 square\n @ Stuck in a whirlpool, lose a turn\n > Rhythmic chanting distracts opponents, roll again\n # Wind gust blows you to a random square\n\n";
	}
	if(current_game==2){
		cout << "\n\nDragster Challenge\n\n";
		cout << "In Dragster Challenge, the players control state-of-\nthe-art supercars and race them down a track. Each\nplayer rolls to see how fast his or her car drives on\na given turn. The first player to reach the goal wins.\n\nSpecial Squares:\n ? Slide on an oil slick, go back 2 squares\n * An efficient gear shift helps you forward, advance 1 square\n @ Engine stalls, lose a turn\n > You hit the boosters, roll again\n # A hidden teleporter sends you to a random square\n\n";
	}
	
	cout << "What sets this game appart is the momentum characteristic.\nMomentum increases each turn and is added to a player's roll.\nIf the player hits a trouble square (#,@, or ?) though, his\nor her momentum is reset to zero.\n\n";

	cout << "Player 1, what is your name? ";
	cin >> name1;
	current_name = name1;
	cout << "Player 2, what is your name? ";
	cin >> name2;
	cout << "\nWelcome " << name1 << " and " << name2 << "!\n\n";
	cout << name1 << ", type a character for your marker on the board: ";
	cin >> p1;
	cout << name2 << ", type a character for your marker on the board: ";
	cin >> p2;
	cout << "\n";

	read_board(the_board);
	print_board(the_board,player1_position,1);
	print_board(the_board,player2_position,2);
	cin.ignore();
	do{
		cout << "\n" << current_name << ", type enter to roll.";
		cin.ignore();
		do{		
			roll = 1 + (rand() % 5);
			if(random_move != true){
				if(current_player==1) cout << current_name << " rolled a " << roll << " ( + momentum of " << momentum1 << ").";
				if(current_player==2) cout << current_name << " rolled a " << roll << " ( + momentum of " << momentum2 << ").";
			}
			random_move = false;
			if(current_player == 1){
				player1_position += roll + momentum1;
				if(random_move != true) momentum1++;
				check_position(player1_position);
				player1_position += the_board[player1_position].action();
				check_position(player1_position);
				current_symbol = the_board[player1_position].get_symbol();
				if(current_symbol == '?') momentum1 = 0;
				if(current_symbol == '@'){
					skip1++;
					momentum1 = 0;
				}
				if(current_symbol == '>') skip2++;
				if(current_symbol == '#'){
					random_move = true;
					momentum2 = 0;
				}
			}else{
				player2_position += roll + momentum2;
				if(random_move != true) momentum2++;
				check_position(player2_position);
				player2_position += the_board[player2_position].action();
				check_position(player2_position);
				current_symbol = the_board[player2_position].get_symbol();
				if(current_symbol == '?') momentum2 = 0;
				if(current_symbol == '@'){
					skip2++;
					momentum2 = 0;
				}
				if(current_symbol == '>') skip1++;
				if(current_symbol == '#'){
					random_move = true;
					momentum2 = 0;
				}
			}
		}while(random_move==true);
		print_board(the_board,player1_position,1);
		print_board(the_board,player2_position,2);

		current_player = (current_player % 2) + 1;

		if(current_player==1){
			if(skip1 > 0){
				current_player = 2;
				skip1--;
			}
		}
		if(current_player==2){
			if(skip2 > 0){
				current_player = 1;
				skip2--;
			}
		}

		if(current_player==1) current_name = name1;
		if(current_player==2) current_name = name2;
	}while((player1_position<board_length - 1) && (player2_position<board_length - 1));
	if(player1_position >= board_length - 1) current_player = 1;
	if(player2_position >= board_length - 1) current_player = 2;
	if(current_player==1) current_name = name1;
	if(current_player==2) current_name = name2;
	cout << endl << current_name << " Wins!!!\n";
	cin.ignore();
	return 0;
}

void read_board(square b[]){
	ifstream infile;
	if(current_game==1) infile.open("game.txt");
	if(current_game==2) infile.open("game2.txt");
	int square_number, square_move;
	string square_message;
	char square_symbol;
	while(!infile.eof()){
		infile >> square_number >> square_move >> square_symbol;
		getline(infile,square_message);
		if(square_number < board_length)
			b[square_number].set(square_move,square_symbol,square_message);
	}
}

void print_board(square b[],int player_position, int player_number){
	if(player_number==1){
		for(int i = 0;i < board_length-1;i++)
			cout << " -";
		cout << "|-\n";
	}
	for(int i = 0;i <= board_length-1;i++){
		if(i != player_position){
			cout << "|";
			b[i].print();
		}else{
			if(player_number==1)
				cout << "|" << p1;
			else
				cout << "|" <<p2;
		}
	}
	cout << endl;

	for(int i = 0;i < board_length-1;i++)
		cout << " -";
	cout << "|";
	if(player_number==1)
		cout << "Goal\n";
	else
		cout << "-\n";
}

void check_position(int& p){
	if(p < 0)
		p=0;
	if(p >= board_length)
		p = board_length - 1;
}

square::square(){
	symbol = ' ';
	move = 0;
	message = "";
}

int square::action(){
	cout << "\n" << message << "\n\n";
	return move;
}

char square::get_symbol(){
	return symbol;
}

void square::print(){
	cout << symbol;
}

void square::set(int m, char s, string a_message){
	move = m;
	symbol = s;
	message = a_message;
}
