#include<iostream>
#include<cstring>
using namespace std;

#include"MovieData.h"
#include "BSTree.h"

void BSTree::DeleteBST( BSNodePtr& t )
{
    if( t != NULL )
    {
        DeleteBST( t->left );
        DeleteBST( t->right );
        delete  t;
        t = NULL;
    }
}

void BSTree::DelHunter( BSNodePtr& t, char inData[] )
{
    if( t == NULL )
        return;
    else if( inData == t->data->title )
        DelKiller( t );
    else if( inData < t->data->title )
        DelHunter( t->left, inData );
    else
        DelHunter( t->right, inData );
}


void BSTree::DelKiller( BSNodePtr& t )
{
    BSNodePtr del;

    if( IsLeaf(t) )
    {
       delete t;
       t = NULL;
    }
    else if( t->left == NULL )
    {
       del = t;
       t = t->right;
       del->right = NULL;
       delete del;
    }
    else if( t->right == NULL )
    {
       del = t;
       t = t->left;
       del->left = NULL;
       delete del;
    }
    else
    {
       MovieDataPtr replacement = new MovieData;

       ProcessLeftMost( t->right, replacement );
       t->data = replacement;
    }
}


void BSTree::ProcessLeftMost( BSNodePtr& t, MovieDataPtr theItem )
{
   if( t->left != NULL )
      ProcessLeftMost( t->left, theItem );
   else
   {
      theItem = t->data;
      BSNodePtr del = t;
      t = t->right;
      del->right = NULL;
      delete  del;
   }
}

void BSTree::AddNodeR( BSNodePtr& t, MovieDataPtr newData )
{
    if( t == NULL )
    {
        BSNodePtr n = new BSNode;
        n->data = new MovieData;
        movieDataCpy(n->data,newData);
        n->left = NULL;
        n->right = NULL;
        t = n;
    }
    else if (strcmp(newData->title,t->data->title) <= 0)
    {
        AddNodeR(t->left, newData);
    }
    else
    {
        AddNodeR(t->right, newData);
    }
}

void BSTree::AddNodeI( MovieDataPtr newData )
{
    BSNodePtr n = new BSNode;
    n->data = new MovieData;
    movieDataCpy(n->data,newData);
    n->left = NULL;
    n->right = NULL;

    if( root == NULL )
    {
        root = n;
    }
    else
    {
        BSNodePtr curr = root;
        BSNodePtr prev;

        while( curr != NULL )
        {
            prev = curr;
            if( strcmp(newData->title,curr->data->title) == 0 )
                return;
            else if( strcmp(newData->title,curr->data->title) < 0 )
                curr = curr->left;
            else
                curr = curr->right;
        }
        if( strcmp(newData->title,prev->data->title) < 0 )
            prev->left = n;
        else
            prev->right = n;
    }
}

void BSTree::SearchNodeTitle( BSNodePtr t, char key[] , int& matchCount )
{
    if( t != NULL )
    {

	SearchNodeTitle(t->left,key,matchCount);

    if( strcmp(key,t->data->title) == 0 )  //Match found, print result
    {
        cout << "\"" << t->data->title << "\" was found" << endl;
        cout << " Title:\n        " << t->data->title << endl;
        cout << "  Year:\n        " << t->data->year << endl;
        cout << "Actors:\n";
        for(int i = 0; i < t->data->actor_count ; i++)
        {
            cout << "        " << t->data->actor_list[i] << endl;
        }
        matchCount++;
    }

	SearchNodeTitle(t->right,key,matchCount);

    }
    else
    {
        return;
    }
}

void BSTree::SearchNodeYear( BSNodePtr t, char key[], int& matchCount )
{
    if( t != NULL )
    {

	SearchNodeYear(t->left,key,matchCount);

    if( strcmp(key,t->data->year) == 0 )  //Match found, print result
    {
        cout << "\"" << t->data->title << "\" was made in " << t->data->year << endl;
        matchCount++;
    }

	SearchNodeYear(t->right,key,matchCount);

    }
    else
    {
        return;
    }
}

void BSTree::SearchNodeActor( BSNodePtr t, char key[], int& matchCount )
{
    if( t != NULL )
    {

	SearchNodeActor(t->left,key,matchCount);

    for(int i = 0 ; i < t->data->actor_count ; i++)
    {
        if( strcmp(key,t->data->actor_list[i]) == 0 )  //Match found, print result
        {
            cout << t->data->actor_list[i] << " was in \"" << t->data->title << "\"" << endl;
            matchCount++;
        }
    }

	SearchNodeActor(t->right,key,matchCount);

    }
    else
    {
        return;
    }
}

void BSTree::SearchNode( char searchKey[] , char searchType )
{
    int matchCount = 0;

    switch ( searchType )
    {
    case 't':
        cout << "\n\nSearching for Title: \"" << searchKey << "\"" << endl;
        SearchNodeTitle(root, searchKey, matchCount);
        break;
    case 'y':
        cout << "\n\nSearching for Year: \"" << searchKey << "\"" << endl;
        SearchNodeYear(root, searchKey, matchCount);
        break;
    case 'a':
        cout << "\n\nSearching for Actor: \"" << searchKey << "\"" << endl;
        SearchNodeActor(root, searchKey, matchCount);
        break;
    default:
        cout << "Error: Invalid Search Type" << endl;
        break;
    }
    if( matchCount == 0 )
    {
        cout << "No matches found for \"" << searchKey << "\"." << endl;
    }
}


void BSTree::PrintBST_InOrder( BSNodePtr t )
{
   if( t != NULL)
   {
     PrintBST_InOrder( t->left );
     cout << t->data->title << endl;
     PrintBST_InOrder( t->right );
   }
}


void BSTree::PrintBST_PreOrder( BSNodePtr t )
{
    if( t != NULL )
    {
        cout << t->data->title << endl;
        PrintBST_PreOrder( t->left );
        PrintBST_PreOrder( t->right );
    }
}


void BSTree::PrintBST_PostOrder( BSNodePtr t )
{
    if( t != NULL )
    {
        PrintBST_PostOrder( t->left );
        PrintBST_PostOrder( t->right );
        cout << t->data->title << endl;
    }
}

void BSTree::PrintBST_BackwardPostOrder( BSNodePtr t, int depth )
{
    const int INDENT = 5;

    if( t != NULL )
    {
        PrintBST_BackwardPostOrder( t->right, depth+1 );
        for( int i = 0 ; i < INDENT*depth ; i++ )
            cout << " ";
            for(int j = 0 ; j < 5 ; j++) //print just initials
                cout << t->data->title[j];
            cout << endl;
        PrintBST_BackwardPostOrder( t->left, depth+1 );
    }
}

