// Pointers_Arrays_Functions.cpp

/*
Demonstrates :
- passing arrays to functions
- using pointers to access arrays passed to functions

When an array is passed to a function, what is actually passed is 
the ADDRESS of the first element of the array.

If we pass an address into a function as an argument, then a pointer parameter
must be defined in the function header to accept the address.

When the address of an object (or array) is passed into a function, 
the code in the function has access to the object that the pointer is pointing at,
and may change its value.
(unless the pointer is defined as a pointer to a 'const object').

*/

#include <iostream>
using namespace std;

void increase(int* px, int n);  // function prototype
void display(int* p, int n);

int main()
{
	int x[4] = { 10,20,30,40 };

	cout << "x[] = ";
	display(x, 4);		// passes the address of the array, and the number of elements
						// Remember, the name of array is address of first element in array
	increase(x, 4);	

	cout << "After increase() \nx[] = ";
	display(x, 4);

	return 0;
}

void increase(int* px, int n)  // px is a pointer to an int. It will point to
{                               // the first element in the array x[].
	for (int i = 0; i < n; i++)
	{
		*px = *px + 1;            // add one to the element that px is pointing to.
		px++;                     // increment the pointer to point at the next array element
	}
}

void display(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *p << ",";
		p++;
	}
	cout << endl;
}



//*** Exercise ************

// Q.1.
// Declare two arrays of type int, of length 5,  in main() called y[] and z[]
// Fill one array with values.
// Write a function called copy() that will accept two array arguments,
//  - pointers to int -
// and will copy the contents of one array to the other array using pointer notation.
// Pass in the length of the source array.  Here is the function prototype:
//    void copy(int* pTarget, int* pSource, int n)


