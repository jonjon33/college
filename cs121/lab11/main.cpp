/*
 */
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;

#include"hash.h"

void Search( const char * );

int main()
{
	string filename = "dict4.txt";
	string inStr = "";
	ifstream ifs;
	ifs.open(filename.c_str());
	if(ifs.is_open())
	{
		while( !ifs.eof() )
		{
			//cout << "Reading: " << inStr << endl;
			getline(ifs,inStr);
			if(inStr != ""){
				(void)Insert(inStr.c_str());
			}
		}
	}
	else
	{
		cout << "Error opening: " << filename << endl;
		ifs.close();
		return 1;
	}
	PrintHashTable();

	cout << "\n\nExample Searches:" << endl;
	cout << "-----------------" << endl;
	Search("axle");
	Search("blarg");
	Search("confirm");
	Search("incandescent");
	Search("pry");
	Search("razzle-dazzle");
	Search("superobese");
	Search("transportee");
	Search("wistful");
	Search("zygomaticoauricularis");

	ifs.close();

	return 0;
}

void Search( const char* s)
{
	NListPtr searchPtr;
	cout << "Looking up: " << s << endl;
	searchPtr = Lookup(s);
	if(searchPtr != NULL){
		cout << "\"" <<searchPtr->name << "\" is in bucket #";
		cout << Hash(s) << "." << endl << endl;
	}
	else
	{
		cout << "\"" << s << "\" is not in the hash table." << endl << endl;
	}
}
