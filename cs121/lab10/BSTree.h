/*  BSTree.h
    Jonathan Hanson
    CS 121
    Lab 10

    This header defines a Binary Search Tree for use with
    MovieData structs.  It is adapted from the
    Binary Search Tree code provided on Bruce Bolden's
    CS 121 website.

*/

class BSTree {
private:
    struct BSNode{
        MovieDataPtr data;
        BSNode *left;
        BSNode *right;
    };

    typedef struct BSNode *BSNodePtr;

    BSNodePtr root;

    void AddNodeR( BSNodePtr& , MovieDataPtr );
    void DeleteBST( BSNodePtr& );
    void DelHunter( BSNodePtr& , char [] ); //"Hunts" (searches) for node to be deleted
    void DelKiller( BSNodePtr& );           //"Kills" (deletes) node to be deleted
    void ProcessLeftMost( BSNodePtr&, MovieDataPtr );
    int IsLeaf( BSNodePtr t ) { return ( (t->left == NULL) && (t->right == NULL) ); }
    void SearchNodeTitle( BSNodePtr, char [] , int& );
    void SearchNodeYear( BSNodePtr, char [] , int& );
    void SearchNodeActor( BSNodePtr, char [] , int& );
    void PrintBST_InOrder( BSNodePtr );
    void PrintBST_PreOrder( BSNodePtr );
    void PrintBST_PostOrder( BSNodePtr );
    void PrintBST_BackwardPostOrder( BSNodePtr, int );

public:
    BSTree() { root = NULL; }
    ~BSTree() { DeleteBST( root ); }
    int IsEmpty() { return (root == NULL); }
    void AddNode( MovieDataPtr newData ) { AddNodeR( root, newData ); }     //Recursive AddNode function
    void AddNodeI( MovieDataPtr );                                          //Iterative AddNode function
    void SearchNode( char [] , char );
    void DelBoss( char inData[] ) { DelHunter(root, inData); }  //"Puts a bounty on" (calls for deletion of) node to be deleted
    void PrintTree() { PrintBST_InOrder( root ); }
    void PrintInOrder() { PrintBST_InOrder( root ); }
    void PrintPreOrder() { PrintBST_PreOrder( root ); }
    void PrintPostOrder() { PrintBST_PostOrder( root ); }
    void PrintBackwardPostOrder() { PrintBST_BackwardPostOrder( root, 0 ); }    //Prints in tree-shaped output
};

