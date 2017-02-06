////
// main.c
// Jon Hanson
////

////
// defines
#define ARR_LEN 16

////
// global variables
int arr[ARR_LEN];

////
// function prototypes
void fillArray(int*,int);
void printArray(int*,int);

void bubbleSort(int*,int);
void insertionSort(int*,int);
void quickSort(int*,int);


////
// main()
int main()
{
    // bubble sort
    fillArray(arr,ARR_LEN);
    printArray(arr,ARR_LEN);
    bubbleSort(arr,ARR_LEN);
    printArray(arr,ARR_LEN);

    // insertion sort
    fillArray(arr,ARR_LEN);
    printArray(arr,ARR_LEN);
    insertionSort(arr,ARR_LEN);
    printArray(arr,ARR_LEN);

    // quicksort
    fillArray(arr,ARR_LEN);
    printArray(arr,ARR_LEN);
    quickSort(arr,ARR_LEN);
    printArray(arr,ARR_LEN);

    return 0;
}
