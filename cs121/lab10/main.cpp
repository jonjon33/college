/*  main.cpp
    Jonathan Hanson
    CS 121
    Lab 10

    This program reads the movie database and provides
    a menu-based user interface that allows
    printing the whole list and searching specific
    titles, years, and actors.

*/

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

#include"MovieData.h"
#include"BSTree.h"

int main()
{
    int i = 0, menuOption = 0;
    char filename[256] = "movies.txt";
    char tempStr[256];
    MovieDataPtr tempMovieData = new MovieData;
    BSTree T;
    ifstream ifs;
    ifs.open(filename);
    if( !ifs.is_open() )
    {
        cout << "Error: Couldn't open file \"" << filename << "\"" << endl;
        ifs.close();
        return -1;
    }
    else
    {
        cout << "Movie Database successfully read from: \"" << filename << "\"" << endl;
        while( !ifs.eof() )
        {
            ifs.get(tempStr,1024,'(');               //Get title
            tempStr[strlen(tempStr)-1] = '\000';     //Get rid of space between end of title and start of parens
            strcpy(tempMovieData->title,tempStr);    //Copy over title
            ifs.get(tempStr,2);                      //Get the first paren
            ifs.get(tempStr,5);                      //Get the year
            strcpy(tempMovieData->year,tempStr);     //Copy over year
            ifs.getline(tempStr,1024);               //Get rest of line (last paren)
            ifs.getline(tempStr,1024);               //Get first actor
            for( i = 0 , tempMovieData->actor_count = 0 ; tempStr[0] != '\0' ; i++ )       //Loop to copy actors and increment actor_count
            {
                //cout << "Iterating..." << endl;
                strcpy(tempMovieData->actor_list[i],tempStr);
                //cout << "We've input: \"" << tempStr << "\"" << endl;
                tempMovieData->actor_count++;
                ifs.getline(tempStr,1024);
            }
            //cout << tempMovieData->title << endl;
            T.AddNode( tempMovieData );
        }
    }

    while( 1 )
    {
        cout << "\n\nMovie Database Program" << endl;
        cout << "Menu:" << endl;
        cout << " 1) List all titles in order" << endl;
        cout << " 2) List all titles as a tree" << endl;
        cout << " 3) Search movies by title" << endl;
        cout << " 4) Search movies by year" << endl;
        cout << " 5) Search actors" << endl;
        cout << " 6) Quit" << endl;
        menuOption = 0;
        cin >> menuOption;
        switch( menuOption )
        {
        case 1:
            cout << "\nPrinting Database with In Order Traversal:" << endl;
            T.PrintInOrder();
            break;
        case 2:
            cout << "\nPrinting Title abbreviations in tree form:" << endl;
            T.PrintBackwardPostOrder();
            break;
        case 3:
            cout << "\nInput title to search:" << endl;
            cin.ignore();
            cin.getline(tempStr,1024);
            T.SearchNode( tempStr , 't' );  //Search uses char flags to indicate search type
                                            //'t' = title
            break;
        case 4:
            cout << "\nInput year to search:" << endl;
            cin.ignore();
            cin.getline(tempStr,1024);
            T.SearchNode( tempStr , 'y' );  //Search uses char flags to indicate search type
                                            //'y' = year
            break;
        case 5:
            cout << "\nInput actor to search:" << endl;
            cin.ignore();
            cin.getline(tempStr,1024);
            T.SearchNode( tempStr , 'a' );  //Search uses char flags to indicate search type
                                            //'a' = actor
            break;
        case 6:
            ifs.close();
            return 0;
        default:
            cout << "Error: Invalid Input" << endl;
            break;
        }
    }
}
