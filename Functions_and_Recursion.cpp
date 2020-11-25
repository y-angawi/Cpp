// Functions_and_Recursion.cpp 
/*
Demonstrates:
Function calls with parameters
Stack based variables (i.e. automatic variables) created and removed from the stack
Call-stack (Stack Frame) (Activation Records) [ you must draw diagrams of these ]
Call-by-Value and Call-by-Reference
Recursion

*/
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

double density(double width, double height, double depth, double weight);
int charToDecimal(char);
void increment(int&);
void swap(int&, int&);
int sumRandom(int start, int end);
void divide(int a);
int fibonacci(int n);


// function prototypes
//void function1();
//int square(int); // prototype for function square
//int sum(int, int);
//
//int recursiveSum(int n);
//int factorial(int a);
//
//void demoPassByValue(int, double);
//void demoPassByReference(int& x, double& z);	// reference parameters

int main()
{
	//Heap (aka Free Store)
	//std::cout << "Function calls and Stack Variables\n";
	//function1();	// call a function that returns void (i.e. no return value)

	//int a = 10; // value to square (local automatic variable in main)
	//cout << a << " squared: " << square(a) << endl; // display a squared

	int result;
	int x = 3;
	int y = 4;
	//result = sum(x, y);
	//cout << "sum(3,4) = " << result << endl;*/

	// Recursion 
	//result = recursiveSum(3);  // sum up values from 3 down to 1
	//cout << "recursiveSum( 3 ) = " << result << endl;

	//int number = 4;
	//cout << number << " factorial (4!) = " << factorial(number) << endl;

	double d = 3.14;

	demoPassByValue(x, d);
	cout << "after calling demoCallByValue() x=" << x << ", d=" << d << endl;

	demoPassByReference(x, d);
	cout << "after calling demoCallByValue() x=" << x << ", d=" << d << endl;
	cout << "x and y have been changed by the function, using references." << endl;

	//return 0;  // indicate successful termination of main()

	// Exer 2-2
	//double result = density(5.6, 10.5, 2.3, 7.9);
	//cout << result << endl;
	// Exer 2-3
	//cout << charToDecimal('a') << endl;
	// Exer 2-5
	//int z = 10;
	//cout << z << endl;
	//increment(z);
	//cout << z << endl;
	//int aa = 10;
	//int bb = 20; 
	// Exer 2-6
	//cout << "The old Value for A is " << aa << "The old Value for A is " << bb << endl;
	//swap(aa, bb);

	// Exer 2-7
	//cout << sumRandom(20, 200)<< endl;
	// Exer 2-9
	//divide(10);

	// Exer 2-10
	//int resultt =fibonacci(10);
	//cout << resultt << endl;
	//for (int i = 1; i <= 15; i++) {
		//cout << fibonacci(i) << endl;
	}
}

double density(double width, double height, double depth, double weight) {

	double volume = width * height * depth;

	return weight / volume;
}

// exercse 3
int charToDecimal(char a) {
	return a;
}

// exercse 5
void increment(int& a) {

	a++;
 
}


// exercse 6
void swap(int& a, int& b) {

	int z = a;
	a = b;
	b = z;
	cout << "The new Value for A is " << a << "The new Value for B is " << b << endl;
}


// exercse 7
int sumRandom(int start, int end) {
	
	srand((unsigned int)time(nullptr)); // use current time as seed for random generator
	int random = rand();
	int sum = 0;
	for (int i = start; i <= end; i++) {
		
		sum += rand();
	
	}
	return sum;
}

// Recursion- exercse 8
int factorial(int a)
{
	if (a > 1)
		return (a * factorial(a - 1));

	return 1;	// 2DO: Draw a call-stack at this point of execution
}

// Recursion- exercse 9
void divide(int a) {
	
	cout << a << endl;
	if (a < 1) {
		return ;
		
	}
	
	return divide(a / 2);
}
// Recursion- exercse 10
int fibonacci(int n) {
	
	if (n == 1) return 0;
	
	if (n == 2) return 1;

	return fibonacci(n - 1) + fibonacci(n - 2);
	
}


//void function1()
//{
//	int x = 4;
//	cout << "In function1(), x = " << x << endl;
//	// 2DO: draw the call-stack at this point
//}
//
//// returns the square of an integer
//int square(int x)	// x is a parameter  (a local variable in this function)
//{
//	return x * x;  // "2DO: draw the call stack just before this returns
//}
//
//int sum(int x, int y)
//{
//	int sum = x + y;
//	return sum;		// 2DO: draw the stack frame with variables at this point
//}
//
///*
//	To understand recursiveSum() you must think of summing the numbers in this way:
//	To sum all numbers from 3 down to 1
//	   result = recursiveSum( 3 )
//			          3           + recursiveSum( 2 )
//	which is:         3           +       2          + recursiveSum( 1 )
//	which is:         3           +       2          +        1
//*/
//
//int recursiveSum(int n)
//{
//	if (n == 1)			// terminating condition
//		return 1;		// 
//
//	return n + recursiveSum(n - 1);  // recursive call
//}
//

//
//void demoPassByValue(int x, double z)
//{
//	cout << "x = " << x << endl;
//	x = 777;	// Changes the local x, but does NOT change the value of x in main()
//				// 2DO: Draw the call stack, and you will see why this is so.
//
//	z = 8.11;    // has no effect on value of y in main()
//}
//
//// Pass by Reference  - (using Reference Parameters)
//void demoPassByReference(int& x, double& z)
//{
//	// Parameters - x is a reference to an int, and it is bound to x in main() when called
//	//              z is a reference to a double, and is bound to variable d from main() when called
//
//	x = 2000;	// This WILL change the value of x in main, because this x is 
//				// a reference parameter that refers to the variable x in main()
//				// 2DO: Draw the Call-Stack, and you will see why this is so.
//
//	z = 8.11;    // This will change the value of y in main(), because z is a reference to y in main()
//}




