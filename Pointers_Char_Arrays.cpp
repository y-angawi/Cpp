// Pointers_Char_Arrays.cpp : 

/*
Demonstrates a C-style string, which is an array of chars.
Using Pointers to access an array of 'char'

NB: Strings in C are stored in an array of char, terminated with a null value i.e '\0'
Note that there is a string class in C++ that makes dealing with strings easy,
but many systems still use the older C-style array of chars.
*/

#include <iostream>
using namespace std;

int main()
{
	char name[20] = "James";
	// The char array name[] is filled with the characters 'J', 'a', ....
	// and terminated by a null character '\0'
	// The '\0' character is added to the end of the string (i.e, as the sixth character)

	char town[] = { 'A', 'r', 'd', 'e', 'e', '\0' };
	// in this case we explicitly filled each character. We must put in the '\0'
	// in this case. The size of the array will be 6 in this case.

	cout << name << endl;
	cout << town << endl;

	// Print out the characters one-by-one
	int i = 0;
	while (name[i] != '\0')		// while we have not reached the '\0'
	{
		cout << name[i];  // output the character
		i++;
	}
	cout << endl;

	// Print out the characters using a pointer
	char* p;	// p is a pointer to a char
	p = name;	// name of an array is the address of first array element
				// so, p now points at the first character ( i.e. 'J' )

	while (*p != '\0')	// Iterate over the characters using a pointer
	{
		cout << *p;
		p++;
	}
	cout << endl << endl;

	// We can write 'difficult to read' code in C, which is a novelty, but
	// doesn't do much for program clarity.
	// What do you think the while() loop below does?

	char buffer[40];			// temporary storage array
	char* pBuffer = buffer;		// pointer to buffer
	p = name;

	while (*pBuffer++ = *p++);  // yes, it's all in one line !

	cout << "Buffer contains: " << buffer << endl;

	// The above is BAD practice because it is difficult to understand.

	//*** Exercise - add the code for each question at the end of the question.
	//    Compile run and test as you go. Study the output carefully.

	// Q.1.
	// Declare an array called nameAndTown, i.e. char nameAndTown[50];
	// Now fill the nameAndTown array with the name from name[], 
	// followed by a comma, and then by a space, and then by the
	// townname from the town array.  
	// Remember to terminate the string with a '\0'.  
	// Print out your result.

	// a. Use array notation.
	// b. Use pointer notation.

	return 0;
}
