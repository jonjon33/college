#include <iostream> 
using namespace std; 
int main(){
	int arr[] = { 200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000};
	int *ptr = arr;

	/* This gives us an idea of the memory map */
	cout << "Size of ptr is " << sizeof(ptr) << endl;
	cout << "Size of arr[0] is " << sizeof(arr[0]) << endl;

	cout << "arr: " << arr << endl;
	cout << "ptr: " << ptr << endl;

	cout << "arr[1]: " << &arr[1] << endl;
	cout << "arr[9]: " << &arr[9] << endl;

	cout << "&ptr: " << &ptr << endl;
	/* end memory map */
	return 0;

}// end main
