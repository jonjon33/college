#include<iostream>
#include<fstream>
using namespace std;

const int MAX_ARRAY = 10000;

void  SelectionSort( int A[], int nElements , int &compCount , int &swapCount );
int IndexOfSmallest( int A[], int iStart, int iEnd , int &compCount , int &swapCount );

void  PrintArray( int A[], int nElements );


int main()
{
    int sortArray[MAX_ARRAY];
    int nA = 0, swapCount = 0, compCount = 0;

    ifstream ifs;
    int i = 0;

    cout << "Selection Sort Statistics" << endl;

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
    SelectionSort( sortArray, nA , compCount , swapCount);
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
    SelectionSort( sortArray, nA , compCount , swapCount);
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
    SelectionSort( sortArray, nA , compCount , swapCount);
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
    SelectionSort( sortArray, nA , compCount , swapCount);
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
    SelectionSort( sortArray, nA , compCount , swapCount);
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
    SelectionSort( sortArray, nA , compCount , swapCount);
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
    SelectionSort( sortArray, nA , compCount , swapCount);
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
    SelectionSort( sortArray, nA , compCount , swapCount);
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
    SelectionSort( sortArray, nA , compCount , swapCount);
    cout << "Comparisons processed: " << compCount << endl;
    cout << "      Swaps processed: " << swapCount << endl;
    nA = 0;
    swapCount = 0;
    compCount = 0;
    ifs.close();
    return 0;
}

void  SelectionSort( int A[], int nElements , int &compCount , int &swapCount )
{
    int iSmallest;
    int  tmp;

    //cout << "------------------------" << endl;
    //cout << "In SelectionSort():" << endl;

    for( int i = 0 ; i < nElements ; i++ )
    {
        //cout << " Pass: " << i << endl;
        iSmallest = IndexOfSmallest( A, i, nElements-1 , compCount , swapCount );

            //  swap
        swapCount++;
        if( iSmallest > i )
        {
            tmp = A[i];
            A[i] = A[iSmallest];
            A[iSmallest] = tmp;
        }

        //PrintArray( A, nElements );
    }

    //cout << "SelectionSort() finished" << endl;
    //cout << "------------------------" << endl;
}

int IndexOfSmallest( int A[], int iStart, int iEnd , int &compCount , int &swapCount )
{
    int    index = -1;
    int  aMin = A[iStart];

    for( int i = iStart ; i <= iEnd ; i++ )
    {
        compCount++;
        if( A[i] < aMin )
        {
            aMin = A[i];
            index = i;
        }
    }

    //cout << "IndexOfSmallest:  " << index << endl;

    return index;
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
