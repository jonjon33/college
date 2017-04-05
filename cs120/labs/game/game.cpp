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
const int board_length = 20;

int main(){
	int current_player = 1, roll;
	string current_name;
	int player1_position = 0, player2_position = 0;
	int skip1 = 0, skip2 = 0;
	char current_symbol;
	square the_board[board_length];
	srand(time(NULL));

	cout << "\n\nCrew Racer II\n\n";
	cout << "In Crew Racer II, player 1 controls the American\nOlympic Crew Team and player 2 controls the Canadian\nOlympic Crew Team as they compete for gold. Each\nplayer rolls to see how far his or her team rows on a\ngiven turn. Spaces marked with a ? contain cute\nducklings that slow players down, and spaces marked\nwith a * contain a tailwind that helps the player\nforward. The first player to reach the goal wins.\n\n";

	cout << "Player 1, what is your name? ";
	cin >> name1;
	current_name = name1;
	cout << "Player 2, what is your name? ";
	cin >> name2;
	cout << "\nWelcome " << name1 << " and " << name2 << "!\n\n";
	cout << name1 << ", type a character for your boat: ";
	cin >> p1;
	cout << name2 <<", type a character for your boat: ";
	cin >> p2;
	cout << "\n";

	read_board(the_board);
	print_board(the_board,player1_position,1);
	print_board(the_board,player2_position,2);
	cin.ignore();
	do{
		cout << "\n" << current_name << ", type enter to roll.";
		cin.ignore();
		roll = 1 + (rand() % 5);
		cout << current_name << " rolled a " << roll << ".";
		if(current_player == 1){
			player1_position += roll;
			check_position(player1_position);
			player1_position += the_board[player1_position].action();
			check_position(player1_position);
			current_symbol = the_board[player1_position].get_symbol();
			if(current_symbol == '@') skip1++;
			if(current_symbol == '>') skip2++;
		}else{
			player2_position += roll;
			check_position(player2_position);
			player2_position += the_board[player2_position].action();
			check_position(player2_position);
			current_symbol = the_board[player2_position].get_symbol();
			if(current_symbol == '@') skip2++;
			if(current_symbol == '>') skip1++;
		}
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
	current_player = (current_player % 2) + 1;
	if(current_player==1) current_name = name1;
	if(current_player==2) current_name = name2;
	cout << endl << current_name << " Wins!!!\n";
	cin.ignore();
	return 0;
}

void read_board(square b[]){
	ifstream infile;
	infile.open("game.txt");
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
