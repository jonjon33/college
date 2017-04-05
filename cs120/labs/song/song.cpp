/***************************************
Jonathan Hanson
CS 120 - 01
November 12,2013
Lab #11

I tried to work around it, but I have
not been able to resolve the
"Segmentation Error" that arrises when I
try to search for a song title. The
array is created and can be printed, but
the search function does not work, as
shown in the output.

***************************************/
#include<iostream>
using namespace std;

class song{
private:
	string title, artist, album;
	double length;	
public:
	song();
	song(string,string,string,double);
	void print();
	void set_data(string,string,string,double);
	int check_name(string);
	string get_title();
	string get_artist();
	string get_album();
	double get_length();
};

int main(){
	const int LIBRARY_SIZE = 5;
	int choice, i, match, check;
	string in_title, in_artist, in_album;
	double minutes, seconds, in_length;
	song library[LIBRARY_SIZE];
	bool exit = false,error = false;

	cout << "\n\nWelcome to your music library.";
	cout << "\n\nKeep track of your music in one convinient location. The library\nstarts out blank, and you add songs one by one. The library holds\nyour five most recently added songs, in the order they were\nadded.";
	do{
		cout << "\n\nPlease choose an option:\n  1) Add a Song\n  2) List Songs\n  3) Search by Title\n  4) Exit\n";
		cin >> choice;
		switch(choice){
		case 1:
			cin.ignore();
			do{
				error = false;
				cout << "\nEnter title for new song:\n";
				getline(cin,in_title);
				for(i=0;i<LIBRARY_SIZE;i++){
					if(library[i].check_name(in_title)==1){
						cout << "Error: Song with this Title Already Exists";
						error = true;
					}
				}
			}while(error==true);
			cout << "\nEnter artist for new song:\n";
			getline(cin,in_artist);
			cout << "\nEnter album for new song:\n";
			getline(cin,in_album);
			do{
				error = false;
				cout << "\nEnter length for new song (Minutes and Seconds):\nMinutes: ";
				cin >> minutes;
				cout << "Seconds: ";
				cin >> seconds;
				in_length = minutes + (seconds/60);
				if (in_length <= 0){
					cout << "Error: Invalid Song Length";
					error = true;
				}else{
					for(i=LIBRARY_SIZE-1;i>0;i--)
						library[i].set_data(library[i-1].get_title(),library[i-1].get_artist(),library[i-1].get_album(),library[i-1].get_length());
					library[0].set_data(in_title,in_artist,in_album,in_length);
				}
			}while(error==true);
			break;
		case 2:
			cin.ignore();
			cout << endl;
			cout << "Title" << endl;
			cout << "Artist" << endl;
			cout << "Album" << endl;
			cout << "Length" << endl;
			for(i=0;i<LIBRARY_SIZE;i++)
				library[i].print();
			break;
		case 3:
			cin.ignore();
			cout << "\nEnter a title:\n";
			getline(cin,in_title);
			for(i=0;i<LIBRARY_SIZE;i++){
				check = library[i].check_name(in_title);
				if(check == 1) match = i;
			}

			library[i].print();
			
			break;
		case 4:
			exit = true;
			break;
		}
	}while(exit==false);
	cout << "\nGoodbye!\n\n";
}

song::song(){
	title = "";
	artist = "";
	album = "";
	length = 0;
}

song::song(string new_title,string new_artist, string new_album, double new_length){
	title = new_title;
	artist = new_artist;
	album = new_album;
	length = new_length;
}

void song::print(){
	if (length > 0){
		cout << endl;
		cout << title << endl;
		cout << artist << endl;
		cout << album << endl;
		cout << length << endl;
	}
}

void song::set_data(string new_title,string new_artist, string new_album, double new_length){
	title = new_title;
	artist = new_artist;
	album = new_album;
	length = new_length;
}

int song::check_name(string search){
	if(search == title)
		return 1;
	else
		return 0;
}

string song::get_title(){
	return title;
}

string song::get_artist(){
	return artist;
}

string song::get_album(){
	return album;
}

double song::get_length(){
	return length;
}
