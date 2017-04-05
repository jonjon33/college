#include <iostream>
#include <fstream>
using namespace std;

const int MAX_ARRAY = 10000;

void  Mergesort( int a[], int first, int last , int &compCount , int &swapCount );
void  Merge( int a[], int firstLeft,  int lastLeft, int firstRight, int lastRight, int &compCount , int &swapCount );
void  Swap( int &v1, int &v2 , int &swapCount );
void  PrintArray( int A[], int nElements );

int main()
{
    int sortArray[MAX_ARRAY];
    int nA = 0, swapCount = 0, compCount = 0;

    ifstream ifs;
    int i = 0;

    cout << "Merge Sort Statistics" << endl;

    cout << "\nData Set: 100 Random Values" << endl;
    ifs.open( "data100r.txt" );
    if( !ifs.is_open() )
    {
        cout << "Error opening file" << endl;
        ifs.close();
        return 1;
    }
    else
    {
        for( i = 0 ; !ifs.eof() ; i++ )
        {
            ifs >> sortArray[i];
            nA++;
        }
    }
    Mergesort( sortArray, 0, nA-1 , compCount , swapCount);
    cout << "Comparisons processed: " << compCount << endl;
    cout << "      Swaps processed: " << swapCount << endl;
    nA = 0;
    swapCount = 0;
    compCount = 0;
    ifs.close();

    cout << "\nData Set: 100 Low to High Values" << endl;
    ifs.open( "data100lth.txt" );
    if( !ifs.is_open() )
    {
        cout << "Error opening file" << endl;
        ifs.close();
        return 1;
    }
    else
    {
        for( i = 0 ; !ifs.eof() ; i++ )
        {
            ifs >> sortArray[i];
            nA++;
        }
    }
    Mergesort( sortArray, 0, nA-1 , compCount , swapCount);
    cout << "Comparisons processed: " << compCount << endl;
    cout << "      Swaps processed: " << swapCount << endl;
    nA = 0;
    swapCount = 0;
    compCount = 0;
    ifs.close();

    cout << "\nData Set: 100 High to Low Values" << endl;
    ifs.open( "data100htl.txt" );
    if( !ifs.is_open() )
    {
        cout << "Error opening file" << endl;
        ifs.close();
        return 1;
    }
    else
    {
        for( i = 0 ; !ifs.eof() ; i++ )
        {
            ifs >> sortArray[i];
            nA++;
        }
    }
    Mergesort( sortArray, 0, nA-1 , compCount , swapCount);
    cout << "Comparisons processed: " << compCount << endl;
    cout << "      Swaps processed: " << swapCount << endl;
    nA = 0;
    swapCount = 0;
    compCount = 0;
    ifs.close();

    cout << "\nData Set: 1000 Random Values" << endl;
    ifs.open( "data1000r.txt" );
    if( !ifs.is_open() )
    {
        cout << "Error opening file" << endl;
        ifs.close();
        return 1;
    }
    else
    {
        for( i = 0 ; !ifs.eof() ; i++ )
        {
            ifs >> sortArray[i];
            nA++;
        }
    }
    Mergesort( sortArray, 0, nA-1 , compCount , swapCount);
    cout << "Comparisons processed: " << compCount << endl;
    cout << "      Swaps processed: " << swapCount << endl;
    nA = 0;
    swapCount = 0;
    compCount = 0;
    ifs.close();

    cout << "\nData Set: 1000 Low to High Values" << endl;
    ifs.open( "data1000lth.txt" );
    if( !ifs.is_open() )
    {
        cout << "Error opening file" << endl;
        ifs.close();
        return 1;
    }
    else
    {
        for( i = 0 ; !ifs.eof() ; i++ )
        {
            ifs >> sortArray[i];
            nA++;
        }
    }
    Mergesort( sortArray, 0, nA-1 , compCount , swapCount);
    cout << "Comparisons processed: " << compCount << endl;
    cout << "      Swaps processed: " << swapCount << endl;
    nA = 0;
    swapCount = 0;
    compCount = 0;
    ifs.close();

    cout << "\nData Set: 1000 High to Low Values" << endl;
    ifs.open( "data1000htl.txt" );
    if( !ifs.is_open() )
    {
        cout << "Error opening file" << endl;
        ifs.close();
        return 1;
    }
    else
    {
        for( i = 0 ; !ifs.eof() ; i++ )
        {
            ifs >> sortArray[i];
            nA++;
        }
    }
    Mergesort( sortArray, 0, nA-1 , compCount , swapCount);
    cout << "Comparisons processed: " << compCount << endl;
    cout << "      Swaps processed: " << swapCount << endl;
    nA = 0;
    swapCount = 0;
    compCount = 0;
    ifs.close();

    cout << "\nData Set: 10000 Random Values" << endl;
    ifs.open( "data10000r.txt" );
    if( !ifs.is_open() )
    {
        cout << "Error opening file" << endl;
        ifs.close();
        return 1;
    }
    else
    {
        for( i = 0 ; !ifs.eof() ; i++ )
        {
            ifs >> sortArray[i];
            nA++;
        }
    }
    Mergesort( sortArray, 0, nA-1 , compCount , swapCount);
    cout << "Comparisons processed: " << compCount << endl;
    cout << "      Swaps processed: " << swapCount << endl;
    nA = 0;
    swapCount = 0;
    compCount = 0;
    ifs.close();

    cout << "\nData Set: 10000 Low to High Values" << endl;
    ifs.open( "data10000lth.txt" );
    if( !ifs.is_open() )
    {
        cout << "Error opening file" << endl;
        ifs.close();
        return 1;
    }
    else
    {
        for( i = 0 ; !ifs.eof() ; i++ )
        {
            ifs >> sortArray[i];
            nA++;
        }
    }
    Mergesort( sortArray, 0, nA-1 , compCount , swapCount);
    cout << "Comparisons processed: " << compCount << endl;
    cout << "      Swaps processed: " << swapCount << endl;
    nA = 0;
    swapCount = 0;
    compCount = 0;
    ifs.close();

    cout << "\nData Set: 10000 High to Low Values" << endl;
    ifs.open( "data10000htl.txt" );
    if( !ifs.is_open() )
    {
        cout << "Error opening file" << endl;
        ifs.close();
        return 1;
    }
    else
    {
        for( i = 0 ; !ifs.eof() ; i++ )
        {
            ifs >> sortArray[i];
            nA++;
        }
    }
    Mergesort( sortArray, 0, nA-1 , compCount , swapCount);
    cout << "Comparisons processed: " << compCount << endl;
    cout << "      Swaps processed: " << swapCount << endl;
    nA = 0;
    swapCount = 0;
    compCount = 0;
    ifs.close();
    return 0;
}


void Mergesort( int a[], int first, int last , int &compCount , int &swapCount )
{
    int  middle;

    //cout << "\nMergesort:" << endl;
    //cout << "Mergesort::first: " << first << endl;
    //cout << "Mergesort::last:  " << last  << endl;

    if( first < last ) {
        middle = (first + last)/2;
        //cout << "Mergesort::middle:  " << middle << endl;
        Mergesort( a, first, middle, compCount , swapCount );
        Mergesort( a, middle+1, last, compCount , swapCount );
        Merge( a, first, middle, middle+1, last , compCount , swapCount );
    }
}

void Merge( int a[], int firstLeft, int lastLeft, int firstRight, int lastRight , int &compCount , int &swapCount )
{
    int tempArray[MAX_ARRAY];
    int  index = firstLeft;
    int  firstSave = firstLeft;

    //cout << "Merge::firstLeft:  " << firstLeft   << endl;
    //cout << "Merge::lastLeft:   " << lastLeft    << endl;
    //cout << "Merge::firstRight: " << firstRight  << endl;
    //cout << "Merge::lastRight:  " << lastRight   << endl;

        //  Merge segments (array subsets)
    while( (firstLeft <= lastLeft) && (firstRight <= lastRight) )
    {
        compCount++;
        if( a[firstLeft] < a[firstRight] )
        {
           tempArray[index] = a[firstLeft];
           firstLeft++;
        }
        else
        {
           tempArray[index] = a[firstRight];
           firstRight++;
        }
        index++;
    }
        //  Copy remainder of left array into tempArray
    while( firstLeft <= lastLeft )
    {
        tempArray[index] = a[firstLeft];
        firstLeft++;
        index++;
    }

        //  Copy remainder of right array into tempArray
    while( firstRight <= lastRight )
    {
        tempArray[index] = a[firstRight];
        firstRight++;
        index++;
    }

        //  Copy back into original array
    for( index = firstSave ; index <= lastRight ; index++ )
        a[index] = tempArray[index];
}

void  Swap( int &v1 , int &v2 , int &swapCount )
{
    int  tmpVal;

    tmpVal = v1;
    v1 = v2;
    v2 = tmpVal;
    swapCount++;
}

void  PrintArray( int A[], int nElements )
{
    cout << "[ ";

    for( int i = 0 ; i < nElements ; i++ )
    {
        cout << A[i] ;
        if( i < nElements-1 )
           cout << ", ";
    }

    cout << " ] " << endl;
}

