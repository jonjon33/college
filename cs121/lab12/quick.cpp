#include<iostream>
#include<fstream>
using namespace std;

const int MAX_ARRAY = 10000;

void Quicksort( int a[], int first, int last , int &compCount , int &swapCount );
int Pivot( int a[], int first, int last , int &compCount , int &swapCount  );

void  Swap( int &v1, int &v2 , int &swapCount );
void  PrintArray( int A[], int nElements );


int main()
{
    int sortArray[MAX_ARRAY];
    int nA = 0, swapCount = 0, compCount = 0;

    ifstream ifs;
    int i = 0;

    cout << "Quick Sort Statistics" << endl;

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
    Quicksort( sortArray, 0, nA-1 , compCount , swapCount);
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
    Quicksort( sortArray, 0, nA-1 , compCount , swapCount);
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
    Quicksort( sortArray, 0, nA-1 , compCount , swapCount);
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
    Quicksort( sortArray, 0, nA-1 , compCount , swapCount);
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
    Quicksort( sortArray, 0, nA-1 , compCount , swapCount);
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
    Quicksort( sortArray, 0, nA-1 , compCount , swapCount);
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
    Quicksort( sortArray, 0, nA-1 , compCount , swapCount);
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
    Quicksort( sortArray, 0, nA-1 , compCount , swapCount);
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
    Quicksort( sortArray, 0, nA-1 , compCount , swapCount);
    cout << "Comparisons processed: " << compCount << endl;
    cout << "      Swaps processed: " << swapCount << endl;
    nA = 0;
    swapCount = 0;
    compCount = 0;
    ifs.close();
    return 0;
}

void Quicksort( int a[], int first, int last , int &compCount , int &swapCount )
{
    int pivot;

    if( first < last ) {
        pivot = Pivot( a, first, last , compCount , swapCount );
        Quicksort( a, first, pivot-1 , compCount , swapCount );
        Quicksort( a, pivot+1, last , compCount , swapCount );
    }
}

int Pivot( int a[], int first, int last , int &compCount , int &swapCount )
{
    int p = first;
    int pivot = a[first];

    for( int i = first+1 ; i <= last ; i++ ) {
        compCount++;
        if( a[i] <= pivot )
        {
            p++;
            Swap( a[i], a[p] , swapCount );
        }
    }

    Swap( a[p], a[first], swapCount );

    return p;
}

void  Swap( int &v1, int &v2 ,  int &swapCount)
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
