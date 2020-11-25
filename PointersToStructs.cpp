// pointers to structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t {
	string title;
	int year;
};

void displayByReference(movies_t& pMovie);
void displayByPointer(movies_t* pMovie);
void displayPassByValue(movies_t movie);

int main()
{
	movies_t films[4] = { {"Jaws",1990}, {"Ted",1997} };

	//string mystr;

	//movies_t amovie;
	//movies_t* pmovie;
	//pmovie = &amovie;

	//cout << "Enter title: ";
	//getline(cin, pmovie->title);
	//cout << "Enter year: ";
	//getline(cin, mystr);
	//(stringstream)mystr >> pmovie->year;

	//cout << "\nYou have entered:\n";
	//cout << pmovie->title;
	//cout << " (" << pmovie->year << ")\n";

	displayByReference(films[0]);
	return 0;
}

void displayByReference(const movies_t& refMovie) {

	cout << refMovie.title << endl;
	cout << refMovie.year << endl;
}

void displayByPointer(const movies_t* pMovie) {

	cout << pMovie->title << endl;
	cout << pMovie->year << endl;
}

void displayPassByValue(movies_t movie) {  /// creates local copy of struct object

	cout << movie.title << endl;
	cout << movie.year << endl;
}
