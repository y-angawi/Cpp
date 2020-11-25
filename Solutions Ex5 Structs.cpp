// Structs.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t {
	string title;
	int year;
};
/*Question 2
Add a function void display( movies_t & pMovie ), that will use a reference to
a movies_t struct to display its contents. Should we use ‘const’ here?*/
void display(const movies_t& movie)   // movie is a Reference to a movies_t struct
{
	cout << movie.title;
	cout << " (" << movie.year << ")\n";
}
/*Question 3
Add a version of the display() function that will use pointer notation to access and
display the contents of a passed struct. Should we use ‘const’ here?*/
void display(const movies_t* movie)	// movie is a Pointer to a movie_t struct
{
	cout << movie->title;
	cout << " (" << movie->year << ")\n";
}
/*Question 4
Create and initialize an array of four movie_t structs. Write a function display() that
will display all struct elements in the array. Write two versions – using array notation
and pointer notation.*/
void displayAllArrayNotation(const movies_t* movies, int size)
{

	cout << "Array Notation\n" << string(20, '=') << endl;
	for (int i = 0; i < size; i++)
	{
		display(movies[i]);
	}
	cout << endl;
}

void displayAllPointerNotation(const movies_t* movies, int size)
{
	cout << "Pointer Notation\n" << string(20, '=') << endl;

	for (int i = 0; i < size; i++, movies++)
	{
		display(movies);
	}
	cout << endl;
}

/*Question 5
A dynamic array is one that can grow in size as required. Define a structure called
arrayList (or vector), with the following data members:
- array of int
- capacity of array (i.e. current size of the array)
- count (i.e. the number of values in the array currently)*/
struct Vector
{
	int* arr;
	int capacity;
	int size = 0;
};

void create(Vector& vect)
{
	vect.arr = new int[10];
	vect.capacity = 10;
}

void add(int x, Vector& vect)
{
	if (vect.size == vect.capacity)
	{
		int* temp = new int[vect.capacity * 2];	// allocate double the amount of memory

		for (int i = 0; i < vect.size; i++)
		{
			temp[i] = vect.arr[i];		// copy elements from old to new array
		}
		delete[] vect.arr; // free up the previous array block
		vect.arr = temp;
		vect.capacity *= 2;
	}
	vect.arr[vect.size] = x;
	vect.size++;
}

void pack(Vector& vect)
{
	int* temp = new int[vect.size];  // allocate just enough memory to hold the elements
	for (int i = 0; i < vect.size; i++)
	{
		temp[i] = vect.arr[i];
	}
	delete[] vect.arr;	// free up the old memory block
	vect.arr = temp;
	vect.capacity = vect.size;
}
void display(Vector& vect)
{
	cout << "Vector {capacity: " << vect.capacity << "; Size:" << vect.size << "}" << endl;
	cout << "[";
	for (int i = 0; i < vect.size; i++)
	{
		if (i != 0)
		{
			cout << ",";
		}
		cout << vect.arr[i];
	}
	cout << "]" << endl;
}
int main()
{
	string mystr;

	movies_t amovie;
	movies_t* pmovie;
	pmovie = &amovie;

	cout << "Enter title: ";
	getline(cin, pmovie->title);
	cout << "Enter year: ";
	getline(cin, mystr);
	(stringstream)mystr >> pmovie->year;

	cout << "\nYou have entered:\n";
	display(*pmovie);
	display(pmovie);


	/*Question 4*/
	movies_t* movies = new movies_t[4];
	movies[0].title = "Avengers Assemble";
	movies[0].year = 2012;
	movies[1].title = "Iron man";
	movies[1].year = 2008;
	movies[2].title = "Joker";
	movies[2].year = 2019;
	movies[3].title = "Knives Out";
	movies[3].year = 2019;

	displayAllArrayNotation(movies, 4);
	displayAllPointerNotation(movies, 4);
	cout << "\n\n\n\nQuestion 5" << endl;
	Vector v;
	create(v);
	for (int i = 0; i < 10; i++)
	{
		add(i, v);
	}
	display(v);
	for (int i = 10; i < 15; i++)
	{
		add(i, v);
	}
	display(v);
	pack(v);
	display(v);
	return 0;
}
