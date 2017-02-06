////
// bubble.c - for use with cs270 hw1
// Jon Hanson
////

////
// bubbleSort(int*,int)
// sorts a passed array with the bubble sort method
void bubbleSort( int *a , int l )
{
    int i,temp;
    int done = 0;
    while(!done)
    {
        done = 1;
        for( i = 1 ; i < l ; i++ )
        {
            if( a[i-1] > a[i] )
            {
                temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                done = 0;
            }
        }
    }

    return;
}
