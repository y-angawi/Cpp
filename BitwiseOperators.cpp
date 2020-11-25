#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <cstdlib>
#include <sstream>
#include "TextBlock.h";
typedef void(*questionPtr)(void);

using namespace std;
void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();
void question8();

int main()
{
	std::map<int, questionPtr> functions;
	functions[1] = question1;
	functions[2] = question2;
	functions[3] = question3;
	functions[4] = question4;
	functions[5] = question5;
	functions[6] = question6;
	functions[7] = question7;
	functions[8] = question8;
	int choice;
	do
	{
		cout << "Please select a question to view, -1 to exit " << endl;

		cin >> choice;
		cin.ignore(1000, '\n');
		if (functions.find(choice) != functions.end())
		{
			functions[choice]();
		}
		else if (choice != -1)
		{
			cout << "Function not found" << endl;
		}

	} while (choice != -1);

	return 0;
}

/*Declare and int x; initialize it to 15 decimal, display its size, display its value in decimal and in
hexadecimal (use hex stream manipulator).
Use the left shift operator to shift by 4 bits.
Output the value of x in decimal and hexadecimal.
What is the value of x as binary?*/
void question1()
{
	int x = 15;  // 0x000f in hex
	cout << "Size of X: " << sizeof(x) << endl;  // size of x in bytes (usually 4 bytes for int)
	cout << "X: " << x << endl;
	cout << "x in hex: " << hex << x << endl;

	x = x << 4;	// left shift by 4 bits, pushing in zeros
	cout << "X: " << std::dec << x << endl;
	cout << "x in hex: " << hex << (int)x << endl;  // cast to int  (int)x
}

/*Declare four unsigned char variables and initialise as follows:
alpha = 0xff, red=0x0f, green=0xff, blue=0x00
Declare an int called colour and initialize it to zero.
Using bitwise operators, add the four colour components to ‘colour’ assuming the format is
“ARGB”, one byte per component.*/
void question2()
{
	unsigned char alpha = 0xff;  // 0b11111111
	unsigned char red   = 0x0f;  // 0b00001111
	unsigned char green = 0xf0;	 // 0b11110000
	unsigned char blue  = 0x00;  // 0b00000000

	int color = 0;  // sets all bits to zero
	cout << "alpha: " << std::dec << (int)alpha << endl;
	cout << "red: " << (int)red << endl;
	cout << "green: " << (int)green << endl;
	cout << "blue: " << (int)blue << endl;

	// adding components byte by byte using bitwise OR
	color = color | ( alpha << 24 );  // align alpha byte with leftmost byte in color
	color = color | ( red << 16);     // aliong red byte with second byte in color
	color = color | ( green << 8);
	color = color | ( blue );

	// operations are commonly done in one statement, like the following:

	//color = (alpha << 24)|(red << 16)|(green << 8)|blue;

	// Explained:  colour has 4 bytes (ARGB)
	// left shift alpha value by 24 bits (3 bytes) so that it aligns with leftmost byte
	// left shift red value by 16 bits (2 bytes) to align it with second byte in colour
	// left shift blue value by 8 bits (1 byte) to align with third byte in colour
	// blue value does not need to be shifted
	// OR all of these together to create the 4 byte colour variable.
	// color will have its ARGB values set with alpha,red,green,blue values
	cout << "Colour in Hex: " << std::hex << color <<endl;

}

void toChannels(int color, unsigned char &a, unsigned char &r, unsigned char &g, unsigned char &b)
{
	a = (color & (255 << 24)) >> 24;
	// start with value 255 (i.e. all 1s in binary)
	// shift left by 24 bits, pushing 0s in from right giving 1111111100000...24 zeros...00000
	// 'AND' this value (that has all 1s in leftmost byte) with the color, thus
	// preserving the first byte pattern and blanking the three rightmost bytes/chars
	// shift the result by three bytes to the right giving the final colour value

	r = (color & (255 << 16)) >> 16; // similar but moving by only 2 bytes
	g = (color & (255 << 8)) >> 8;
	b = (color & (255));

}
/*Given an int that represents a colour write a function that will return the Red, Green, Blue
and Alpha values assuming each int is in the format AAAAAAAA RRRRRRRR GGGGGGGG
BBBBBBBBB2*/
void question3()
{
	int color = 0xff0fff00;	// ARGB
	unsigned char alpha, red, green, blue;

	toChannels(color, alpha, red, green, blue);
	// function uses reference parameters to fill the channel values
	cout << "alpha: " << std::dec << (int)alpha << endl;
	cout << "red: " << (int)red << endl;
	cout << "green: " << (int)green << endl;
	cout << "blue: " << (int)blue << endl;

}
bool isEven(int x)
{
	// even numbers have a zero in their rightmost bit
	// 'AND'ing with 1, zeroises all other bits, leaving only the value of the rightmost bit
	// for evaluation
	return (x & 1) == 0;
}
/*Using bitwise
operators, write a function that will determine if an integer is odd.*/
void question4()
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << " is Even " << (isEven(i)==true ? "Yes" : "No") << endl;
	}
}
bool isOdd(int x)
{
	return (x & 1) == 1;
}
/*Using bitwise
operators, write a function that will determine if an integer is even.*/
void question5()
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << " is Odd " << (isOdd(i) == true ? "Yes" : "No") << endl;
	}
}

void toColorInt(int &color, unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	// align the value of the 8 bits in a, with the leftmost byte position in color (ie alpha)
	// align b with the second byte (ie. red)
	// and so on.
	color = (a << 24) | (r << 16) | (g << 8) | b;
}
/*Given the Red, Green, Blue and Alpha values, write a function that will
convert it to a single int in the format described above.*/
void question6()
{
	int color = 0;
	toColorInt(color, 255, 128, 0, 128);
	cout << "Color" << std::hex << color << endl;
}

/*
Ref:  https://en.wikipedia.org/wiki/Parity_bit

A parity bit, or check bit, is a bit added to a string of binary code to ensure
that the total number of 1 - bits in the string is even or odd. Parity bits are used
as the simplest form of error detecting code.There are two variants of parity bits :
even parity bit and odd parity bit.

In serial data transmission, a common format is 7 data bits, an even parity bit,
and one or two stop bits. This format neatly accommodates all the 7 - bit ASCII
characters in a convenient 8 - bit byte.
*/
bool checkParity(int x)
{
	int count = 0;  // count of bits set to 1
	while (x > 0)
	{
		count += (x & 1);	// 'AND' gives 1 if rightmost bit is 1, else 0
		x = x >> 1;			// shift all bits by one place to right, in order to test the next bit
	}
	return isEven(count);
}
/*Implement an Even Parity check algorithm. Parity checking is a common way of detecting
errors over network communication. It works by counting the number of 1 bits in a stream
of binary digits and appending a 1 if there is an uneven number of digits or 0 if there is an
even number.*/
void question7()
{
	for (int i = 0; i < 20; i++)
	{
		cout << "Even Parity Check: " << i << (checkParity(i) ? "Pass" : "Fail") << endl;
	}
}
/*Word processing applications often divided a document into blocks of text with different
properties. As a number of these properties can be just true of false (e.g. bold, italic,
underlined, etc.) they are often implemented as just flags. Using bitwise operators
implement a class to represent a block of text and store the following as binary flags.
 Bold
 Italic
 Underlined
 Highlighted
 Subscript
 Strikethrough*/
void question8()
{
	TextBlock s("Some Text");
	s.setBold(true);
	s.setHighlighted(true);
	s.print();
	s.setBold(false);
	s.setItalic(true);
	s.print();
}
