// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main()
{
	string mystr;
	float price = 0;
	int quat = 0;
	cout << "Enter Price: ";
	getline(cin, mystr);
	stringstream(mystr) >> price;
	cout << "Enter Quantity: ";
	getline(cin, mystr);
	stringstream(mystr) >> quat;
	cout << "Price is " << price << " Quantity is " << quat;

  int foo = 5;
	auto x = foo;
	string mystr;
	cout << "what is your name? ";
	getline(cin, mystr);
	cout << "Hello " << mystr << ".\n";
	cout << "What's your favorite team? ";
	getline(cin, mystr);
	cout << "I Like " << mystr << " too!.\n";

	x = 19;
	cout << x << endl;
	int number;
	cout << "Please Enter a number: ";
	cin >> number;
	cout << "tyhe Number is " << number << endl;
	cout << "it's double " << number * 2 << endl;
	cout << number * 5 << endl;
	cout << number + x << endl;
    cout << "Hello World!\n"<< endl;
	cout << sizeof (int) << endl;
	cout << sizeof(double) << endl;
	cin.get();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
