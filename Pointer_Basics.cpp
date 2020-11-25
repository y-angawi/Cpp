// Pointer_Basics.cpp

#include <iostream>
using namespace std;

void demo1();
void demo2();
int add(int const*, int const*);

int main()
{
	/*cout << "Pointers - sample code." << endl;
	demo1();
	demo2();*/

	int a = 6;
	int b = 6;
	cout << add(&a, &b) << endl;

	return 0;
}

void demo1()		// Pointer basics - declaring a pointer, dereferencing a pointer
{
	int x = 25;
	int* p = nullptr;
	// declares variable p as type "pointer to int" (or 'p is a pointer to an int').
	// p is a variable that can store the address of an int. 
	// It is good practice to assigns a nullptr value to the pointer initially.
	// nullptr is a special value indicating that the pointer doesn't
	// point at any memory location.

	p = &x;
	// '&x' means: get the memory address of the variable x. ('&' is the address-of operator)
	// An address is an integer value
	// We can assign the address of x into p, as a pointer variable can store an address

	cout << "x: (value in x): " << x << endl;		//value of x
	cout << "&x: (address of x): " << &x << endl;	//address of x

	cout << "p: (value in p): " << p << endl;		//value stored in p, which is the address of x

	// Dereferencing a pointer variable by using *p
	// Dereferencing means: getting the value from the location that the pointer points to.

	cout << "*p (dereferencing the pointer)(i.e. get value at location where p points to):\t";
	cout << *p << endl;

	// note that, here, the type of *p is the same as the type that the pointer p was declared to point at.
	// p was declared to be a pointer to an int, therefore, *p is of type int

	// Using *p as an l-value  (left-value).
	// Below, we assign the number 99 to the location p is pointing to.
	// Note the slightly different interpretation of *p (as either r-value or l-value)

	*p = 99;
	// put the value 99 at where p is pointing
	// p is pointing at x, so 99 will be put into the variable x

	cout << "... after executing *p = 99;";
	cout << "*p: " << *p << endl;
	cout << "x: (value in x): " << x << endl;	//value of x was changed using pointer p

	/* 2DO in class -- complete in class and confirm your output.
	Q1.
	- decare a variable of type double called 'height' and assign it your height in meters (e.g. 1.56)
	- declare a variable pHeight of type pointer to double;
	- get the address of the height variable and assign it to the pointer pHeight;
	- print out the height variable
	- print out the address of the height variable using '&'
	- print out the value of the pointer pHeight
	- print out the value of the height variable by dereferencing the pHeight pointer variable
	- assign a new value to the height variable e.g. 1.88
	- print out the value
	- assign a new value the height variable using the pointer pHeight  (dereference as an l-value)
	- DRAW a memory diagram on paper to show the state of all variables just before end of main()
	*/
	double h = 1.56;
	double* ph = &h;
	cout << h << endl;
	cout << *ph << endl;
	cout << &h << endl;
	cout << ph << endl;
	h = 1.88;
	cout << h << endl;
	*ph = 2;
	cout << *ph << endl;


	/*
	Q.2 Declare and initialize a double d with the value 3.14.
    Declare a pointer pd and set it to point at the variable d.
    Using the pointer, set the value of d to 3.14159, and output
    the new value of d using the pointer.
	*/
	double d = 3.14;
	double* pd = &d;
	*pd = 3.14159;
	cout << *pd << endl;
	/*
	Q.3 Declare a pointer to a char called pc, but don't assign it a value.
    Print out the value of pc.  Look at the value. What does the value represent?

    Output *pc (that is, the thing that pc is pointing at)
     -- did it run?, if so, study the output. What has happened?  Explain!
	*/
	char c = NULL;
	char* pc = &c;
	
	*pc = 'X';

	cout << pc;
	cout << *pc;

}

// demo2()
// Declares 'pointer to int' type parameters that can accept
// the addresses of int variables.
void swap_by_pointer(int* ptr1, int* ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void swap_by_reference(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void demo2()	// swap values of two variables using by passing their addresses
{
	int x = 22;
	int y = 33;
	swap_by_reference(x, y);
	cout << "After swap_by_reference(): x=" << x << ",  y=" << y << endl;
	swap_by_pointer(&x, &y);	// pass the addresses of x and y - (pass by value)

	cout << "After swap_by_pointer(): x=" << x << ",  y=" << y << endl;

	// pointers can be passed as arguments also, which is really the same 
	// as passing addresses, as a pointer contains an address

	int* pX = &x;	// pX is a pointer to an int (pointing at x)
	int* pY = &y;
	swap_by_pointer(pX, pY);	// passes the adresses of x and y

	cout << "After swap_by_pointer(): x=" << x << ",  y=" << y << endl;

}

/* 2DO
	Q4.
	- write a function called add() with parameters to accept the addresses
	  of two int arguments.  The function should add the values of the objects
	  pointed to, and return an int.  Test your program.

	- how would you prevent the pointer parameters in add() from modifying the
	  objects that they point to.  Try it out.

	  */

int add(int const* a, int const* b) {

	return *a + *b;
}
