#include "Student.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <istream>
#include <string>
using namespace std;

Student::Student()
{
    id = 0;
    name = "";
    title = "";
    course = "";
    scores = new int[4];

    this->setScores(0, 0, 0, 0);
}
Student::Student(int ID, string name, string title, string course, int score1, int score2, int score3, int score4)
{
    this->setID(ID);
    this->setName(name);
    this->setTitle(title);
    this->setCourse(course);

    scores = new int[4];
    this->setScores(score1, score2, score3, score4);
}

int Student::getID()
{
    return id;
}

string Student::getName()
{
    return name;
}

string Student::getTitle()
{
    return title;
}

string Student::getCourse()
{
    return course;
}

int* Student::getScores()
{
    return scores;
}

double Student::getAverge()
{
    return (scores[0] + scores[1] + scores[2] + scores[3]) / 4;
}

void Student::setID(int id)
{
    this->id = id;
}

void Student::setName(string name)
{
    this->name = name; 
}

void Student::setTitle(string title)
{
     this->title = title; 
}

void Student::setCourse(string course)
{
     this->course = course;
}

void Student::setScores(int sco1, int sco2, int sco3, int sco4)
{
        this->scores[0] = sco1;
        this->scores[1] = sco2;
        this->scores[2] = sco3;
        this->scores[3] = sco4;
}

// When each Student object goes out of scope, its destructor is called.
// This is your chance to delete any dynamically allocated memory that
// has been allocated by this object.

Student::~Student() {
    delete[] scores;  // delete the array of doubles we allocated dynamically in the constructor
                        // if deleting only a single object, then leave out the brackets []
}

    // Copy constructor
    // Copies the fields from the source object into this object
    // i.e the object being created.
Student::Student(const Student& source)
{
    this->id = source.id;
    this->name = source.name;
    this->title = source.title;
    this->course = source.course;
    this->scores = new int[4];	// dynamically allocate a new object to hold a copy of the location data

    scores[0] = source.scores[0];
    scores[1] = source.scores[1];
    scores[2] = source.scores[2];
    scores[3] = source.scores[3];
}

// Overloaded assignment operator=
Student& Student::operator= (const Student& otherStudent)
{
    // self-assignment guard
    if (this == &otherStudent)
        return *this;			// reference to same object

    // copy data from the source (rhs) to this object (the destination)
    id = otherStudent.id;
    name = otherStudent.name;
    title = otherStudent.title;
    course = otherStudent.course;

    // must make a new location object to store a copy of other student location

    if (scores != nullptr)  // free memory belonging to target object
        delete[] scores;

    scores = new int[4];
    for (int i = 0; i < 4; i++) {
        scores[i] = otherStudent.scores[i];  // copy over the 2 locations
    }

    // return the existing object so we can chain this operator
    return *this;
}

//inline bool

bool Student::operator== (const Student& otherStudent)
{
    // return ture if both objects are equals, false otherwise
    return (id == otherStudent.id
        && name == otherStudent.name
        && title == otherStudent.title
        && course == otherStudent.course
        && scores == otherStudent.scores);
}

bool Student::operator!= (const Student& otherStudent)
{
    // return ture if both objects are equals, false otherwise
    return !(id == otherStudent.id
        && name == otherStudent.name
        && title == otherStudent.title
        && course == otherStudent.course
        && scores == otherStudent.scores);
}
