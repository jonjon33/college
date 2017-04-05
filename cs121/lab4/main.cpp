#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

#include"Stack.h"

int CompareStrings( string , string , int );

int main()
{
    //Variable Declarations
    int i = 0 , j = 0;
    int alphaCharCount = 0;
    string inputStr = "";
    Stack Phrase;

    //Prompt
    cout << "\nPalindrome Checker   rekcehC emordnilaP" << endl;
    cout << "Enter a word or phrase: " << endl;

    //Take all of cin
    getline( cin , inputStr );

    //Count the alphabetic characters
    for( i = 0 ; i < inputStr.size() ; i++ )
    {
        if( tolower( inputStr[i] ) >= 'a' && tolower( inputStr[i] ) <= 'z' )
        {
            alphaCharCount++;
        }
    }

    //Give an error if no alphabetic characters exist
    if( alphaCharCount == 0 )
    {
        cout << "Error: Input contains no checkable characters" << endl;
        return 1;
    }

    //Declare dynamic arrays of char with size of alphaCharCount
    char *lowerForwardStr = new char[alphaCharCount];
    char *lowerReverseStr = new char[alphaCharCount];

    //Push inputStr to the stack and create a string of the lowercase
    //alphabet characters lowerForwardStr
    for( i = 0 , j = 0 ; i < inputStr.size() ; i++ )
    {
        if( tolower( inputStr[i] ) >= 'a' && tolower( inputStr[i] ) <= 'z' )
        {
            lowerForwardStr[j] = tolower( inputStr[i] );
            j++;
            Phrase.Push( tolower( inputStr[i] ) );
        }
    }

    //Pop through the stack and record the values in lowerReverseStr
    i = 0;
    while( !Phrase.IsEmpty() )
    {
        lowerReverseStr[i] = Phrase.Pop();
        i++;
    }

    //Compare the strings and print the result
    if( CompareStrings( lowerForwardStr , lowerReverseStr , alphaCharCount ) )
    {
        cout << "\n\"" << inputStr << "\" is a palindrome\n" << endl;
    }
    else
    {
        cout << "\n\"" << inputStr << "\" is not a palindrome\n" << endl;
    }

    //Release memory
    delete [] lowerForwardStr;
    delete [] lowerReverseStr;

    return 0;
}

//Takes two strings and their length and compares each char
//returns true if each match, false otherwise
int CompareStrings( string str1 , string str2 , int strlen)
{
    int i = 0;
    int retVal = 0;

    for( i = 0 ; i < strlen ; i++)
    {
        if( str1[i] == str2[i] )
        {
	    //Do nothing
        }
        else
        {
            return 0;
        }
    }

    return 1;
}

