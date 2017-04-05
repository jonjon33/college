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

	ptr++; 
	cout << "*ptr: " << *ptr << endl; 
	cout << "ptr: " << ptr << endl; 

	*++ptr; 
	cout << "*++ptr: " << *ptr << endl; 
	cout << "ptr: " << ptr << endl; 
 
	*ptr++; 
	cout << "*ptr++: " << *ptr << endl; 
	cout << "ptr: " << ptr << endl; 

	ptr = arr; // reset ptr 

	// fun with cout repeat last couple of commands 
	cout << "*++ptr: " << *++ptr << endl; 
	cout << "ptr: " << ptr << endl; 
 
	cout << "*ptr++: " << *ptr++ << endl; 
	cout << "ptr: " << ptr << endl; 
 
	ptr = arr; // reset ptr 
 
	*ptr += 1; 
	cout << "*ptr: " << *ptr << endl; 
	cout << "ptr: " << ptr << endl; 
 
	cout << "*(ptr+1) %i\n" << *(ptr+1) << endl; 
	cout << "*(ptr+1): " << *(ptr+1) << endl; 
 
	ptr = arr; // reset ptr 
 
 
	*(arr+2) = *ptr+100; 
	cout << "*(arr+2): " << *(arr+2) << endl; 
 
	ptr = arr + 5; 
	cout << "*ptr: " << *ptr << endl; 
	cout << "ptr: " << ptr << endl; 
 
	ptr = arr; // reset ptr 
 
	arr[2] = *(ptr + 5); 
	cout << "arr[2]: " << arr[2] << endl; 
 
	ptr = (arr + 10); 
	cout << "*ptr: " << *ptr << endl; 
	cout << "ptr: " << ptr << endl;

	return 0;

}// end main
