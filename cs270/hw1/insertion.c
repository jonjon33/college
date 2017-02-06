////
// insertion.c - for use with cs270 hw1
// Jon Hanson
////

////
// insertionSort(int*,int)
// sorts a passed array with the insertion sort method
void insertionSort( int *a , int l )
{
    int i,j,temp;
    for( i = 1 ; i < l ; i++ )
    {
        j = i;
        while( j >= 0 && a[j] < a [j-1] )
        {
            temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
    }

    return;
}
