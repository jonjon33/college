/* lab6.c
 * Descriptive Statistics in C
 * Jonathan Hanson
 * Lab #6
 *
 * Take a column of data and find min, max, avg,
 * and standard deviation. Do not use C++.
 *
 */

#include<stdio.h>	//using various I/O functions
#include<math.h>	//using sqrt()

void ShowHeader( FILE * , double * , double * , double * , double * );
void ReadColumn( FILE * , double * , int * );
void UpdateDescriptiveStats( double * , int * , double * , double * , double * );
void CalcStdDev( double * , int * , double * , double * );

int main()
{
    char outFileName[8] = "outfile";		//name of output file
    char inFileName[100];			//empty array for input file name
    double fileData[100];			//empty array for file data
    int itemCount = 0;				//# of items in file
    int i = 0;					//multipurpose index
    FILE *ofp, *ifp;				// out and in file pointers
    double min = 0, max = 0, avg = 0, stdDev = 0;	//descriptive stat vars

    //Prompt for an input file name
    printf("Enter name of file to analyze:\n");
    scanf("%99s",inFileName);

    //Open if valid, else end with error
    ifp = fopen(inFileName,"r");
    if( ifp == NULL )
    {
        printf( "Error opening file: %s\n", inFileName );
        return -1;
    }
    printf("File Opened Successfully\n");

    //Create output file
    ofp = fopen(outFileName,"w");

    //Read data from a file
    ReadColumn( ifp , fileData , &itemCount );

    //Find descriptive statistics based on read file
    UpdateDescriptiveStats( fileData , &itemCount , &min , &max , &avg );

    //Find std dev using previously found avg
    CalcStdDev( fileData , &itemCount , &avg , &stdDev );

    //Print info to display and write to file
    printf("Descriptive Statsitics of Contained Data:\n");
    printf("Min:\t\tMax:\t\tAvg:\t\tStd Dev:\n%lf\t%lf\t%lf\t%lf\n", min , max , avg, stdDev);
    ShowHeader( ofp , &min , &max , &avg , &stdDev );

    //Close files and end program
    fclose( ifp );
    fclose( ofp );
    return 0;
}

//Prints the same output printed to the console to an output file
void ShowHeader( FILE *ofp , double *min , double *max , double *avg , double *stdDev )
{
    fprintf( ofp , "Descriptive Statsitics of Contained Data:\n");
    fprintf( ofp , "Min:\t\tMax:\t\tAvg:\t\tStd Dev:\n%lf\t%lf\t%lf\t%lf\n", *min , *max , *avg, *stdDev);
}

//Takes a column of data and stores each value in an array
void ReadColumn( FILE *ifp , double *fileData , int *itemCount )
{
    int i = 0;
    double temp;
    *itemCount = 0;
    //Scan a temp value and use it if != EOF
    while( fscanf( ifp , "%lf" , &temp ) != EOF )
    {
        fileData[i] = temp;
        *itemCount = *itemCount + 1;
        i = i + 1;
    }
}

//Calculates the values for descriptive statistics of data
void UpdateDescriptiveStats( double *fileData , int *itemCount , double *min , double *max , double *avg )
{
    int i = 0;
    double sum = 0;

    *min = fileData[0];
    *max = fileData[0];

    //For each data point
    for( i = 0 ; i < *itemCount ; i++)
    {
        //Look for smaller
        if( fileData[i] < *min )
        {
            *min = fileData[i];
        }
        //Lool for bigger
        if( fileData[i] > *max )
        {
            *max = fileData[i];
        }
	//Calculate sum for averaging
        sum += fileData[i];
    }
    //Take average
    *avg = sum / *itemCount;
}

//Calculates the standard deviation
void CalcStdDev( double *fileData , int *itemCount , double *avg , double *stdDev )
{
    int i = 0;
    double n = *itemCount;	//double required to avoid truncation
    double sum = 0;
    //Sum of (xi - avg)^2 from 1 to n
    for( i = 0 ; i < *itemCount ; i++ )
    {
        sum += ( fileData[i] - *avg ) * ( fileData[i] - *avg );
    }
    //Calculate the standard deviation
    *stdDev = sqrt( ( 1 / ( n - 1 ) ) * sum );
}

