// checks whether the given token has been #defined earlier in the file or in an included file
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
using namespace std;

class Student
{
private:
    int id;
    string name;
    string title;
    string course;
    int score1, score2, score3, score4;
    int* scores;
public:
    Student();
    Student(int ID, string name, string title, string course, int score1, int score2, int score3, int score4);
    int getID();
    string getName();
    string getTitle();
    string getCourse();
    int* getScores();

    double getAverge();

    void setID(int id);
    void setName(string name);
    void setTitle(string title);
    void setCourse(string course);
    void setScores(int sco1, int sco2, int sco3, int sco4);

    void print();
    Student(const Student& source);
    Student& operator= (const Student& otherStudent);
    bool operator==(const Student& otherStudent);
	bool operator!=(const Student& otherStudent);
    friend ostream& operator<<(ostream& out, Student& s);
    friend istream& operator>>(istream& in, Student& s);
    ~Student();
};
#endif
