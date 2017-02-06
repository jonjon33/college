////
// quick.c - for use with cs270 hw1
// Jon Hanson
////

////
// quickSort(int*,int)
// sorts a passed array with the quick sort method
void quickSort( int *a , int l )
{
    int i,temp;
    int wall = 0;
    int piv = l-1;

    for(i=0;i<l-1;i++)
    {
        if(a[i]<a[piv])
        {
            temp = a[i];
            a[i] = a[wall];
            a[wall] = temp;
            wall++;
        }
    }
    temp = a[piv];
    a[piv] = a[wall];
    a[wall] = temp;

    if(wall>1)
    {
        int aLoLen = wall;
        int aLo[aLoLen];
        for(i=0;i<aLoLen;i++)
            aLo[i] = a[i];
        quickSort(aLo,aLoLen);
        for(i=0;i<aLoLen;i++)
            a[i] = aLo[i];
    }

    if(piv-wall>1)
    {
        int aHiLen = piv - wall;
        int aHi[aHiLen];
        for(i=0;i<aHiLen;i++)
            aHi[i] = a[wall+1+i];
        quickSort(aHi,aHiLen);
        for(i=0;i<aHiLen;i++)
            a[wall+1+i] = aHi[i];
    }

    return;
}
