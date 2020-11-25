// Pointers_and_Arrays.cpp
/*
   Using Pointers to access arrays.
   Pointer Arithmetic - incrementing pointers and using them to access arrays.

   NB:  The name of an array is a constant pointer to the first element of an array.
*/

#include <iostream>
using namespace std;

int main()
{
	int x[4] = { 10,20,30,40 };  //

	int* p;    // declare p as a 'pointer to an int'
			   // a pointer is variable that can store the address of an object

	p = x;   // Remember that the name of the array is a constant pointer to
			 // the beginning of the array. So, x is the address of the
			 // first element of the array.  ( Note that we do not use &x )
			 // Pointer 'p' now points at the first element in the array x.

	//cout << "Value stored in pointer p = " << p << endl;

	//cout << "Value at *p = " << *p << endl; // dereference the pointer p giving
	//										// the first element in the array.

	p++;  // Increment the pointer p.  This means increase the value of the pointer
		  // so that it points at the next element in the array x[].
		  // When we increment a pointer it is incremeneted by the length of
		  // the type of the object it points to.  Here, p is a pointer to int,
		  // so, the value 4 (assuming 4-byte pointer)  is actually added to
		  // the address stoired in the pointer.
		  // Incrementing a pointer always moves the pointer forward to the start of
		  // the next element in an array.

	//cout << "Value stored in pointer p should be greater than it was, p = " << p << endl;

	//cout << "Value at *p = " << *p << endl; // should print second element from array x[]

	p = p + 2;  // this will move the pointer on by two elements, leaving it pointing
				// at the last element in the array.

	*p = 99;   // Assigns the value 99 to where p is pointing, i.e. in the last
			   // element of the array. The pointer is dereferenced.

   // At this point the pointer p is pointing to the last element in the array.
   // If we want to print out the array elements using the pointer we must set the
   // pointer to point to the beginning of the array, as follows:

	p = x;     // p is reset to point at the start of array

	//for (int i = 0; i < 4; i++)
	//{
	//	cout << *p << ", ";  // dereference pointer to access what pointer is pointing at
	//	p++;                 // move the pointer on to the next element
	//}

	// The danger with pointers :
	/*cout << "\nDanger ! Programmer error ! - pointer accessing beyond end of array. *p = ";
	cout << *p << endl;*/

	// Even worse danger !!! What is the problem below.
	// What happens when you execute this.
	/**p = 666;
	cout << *p << endl;*/

	//*** Exercise - add the code for each question at the end of the question.
	//    Compile run and test as you go. Study the output carefully.

	//Q.1 Declare and initialize an array d[] of 10 double values.
	//    Declare a pointer pd and put it pointing at the beginning of the array.
	//    Write a for loop that will use the pointer to double the value of
	//    every array element.
	// or double d[10] = ....
	double d[10] = {1.5, 5.5, 6.2, 4.2, 7.1, 8.00, 5.0, 4.9, 9.0, 7.6};
	double* pd = d;

	for (int i = 0; i < 10; i++, pd++)
	{
		*pd *= *pd;
		cout << *pd << ", ";

	}

	//Q.2 Set the pointer pd to point at the last element in the array.
	//    Can we get the address of the last element x[3] ?
	//    Be careful that it is pointing at the last one, and not beyond
	//    the last element.
	//    Use a for loop, and the pointer, to print the array elements in reverse order.


	system("PAUSE");  //  comment out if necessary
	return 0;
}
