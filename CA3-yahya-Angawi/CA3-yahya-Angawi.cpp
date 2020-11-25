// CA3-yahya-Angawi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>      // file stream
#include <string>
#include <istream>
#include <sstream>    // string stream
#include <algorithm>
#include <exception>
#include <vector>
#include "Student.h"
#include "Student.cpp"


using namespace std;

 ostream& operator<<(ostream& out, Student& student)     //output
{
    out << "Student Details: " << endl;
    out << "ID : " << student.id << endl;
    out << "Title : " << student.title << endl;
    out << "Name : " << student.name << endl;
    out << "Course : " << student.course << endl;
    out << "Score One : " << student.scores[0] << endl;
    out << "Score Two : " << student.scores[1] << endl;
    out << "Score Three : " << student.scores[2] << endl;
    out << "Score Four : " << student.scores[3] << endl;
    out << "Scores Average : " << student.getAverge() << endl;
    return out;
}
 istream& operator>>(istream& in, Student& student)
{
    cout << "Enter ID: ";
    in >> student.id;
    if (student.id < 1) throw exception("Invalid ID! ID Must Be Larger Or equal To One");

    in.ignore(); // the next token somehow is "\n" i needed to ignor it
    cout << "Enter Name: ";
    getline(in, student.name);
    if (student.name.size() < 4) throw exception("Invalid Name Length! Name Must Be At Least Four Charachters Long");

    cout << "Enter Title: ";
    getline(in, student.title);
    if (student.title.size() < 2) throw exception("Invalid Title Length! Title Must Be At Least Two Charachters Long");

    cout << "Enter Course: ";
    getline(in, student.course);
    if (student.course.size() < 4) throw exception("Invalid Course Length! Course Must Be At Least Four Charachters Long");

    cout << "Enter First Score: ";
    in >> student.scores[0];

    cout << "Enter Second Score: ";
    in >> student.scores[1];

    cout << "Enter Third Score: ";
    in >> student.scores[2];

    cout << "Enter Fourth Score: ";
    in >> student.scores[3];
    if (!(student.scores[0] >= 0 && student.scores[0] <= 100
        || student.scores[1] >= 0 && student.scores[1] <= 100
        || student.scores[2] >= 0 && student.scores[2] <= 100
        || student.scores[3] >= 0 && student.scores[3] <= 100))
        throw exception("Invalid Scores Value! Scores Must Be Between Zero And A Hundred Inclusively");

    return in;
}

bool checkIDExistence(vector<Student>& students, int id)
{
    for (Student s : students)
    {
        if (s.getID() == id) return true;
    }
    return false;
}

void addStudentInVector(vector<Student>& students) {

    Student  s;
    cin >> s;
    int id = s.getID();
    if (!checkIDExistence(students, id) && id != 0) { //add if id does not exist
        students.push_back(s);
        cout << "The Student Was Add." << endl;
    }
    else
    {
        cout << "Cannot Add The Student. ID Not Valid Or A Student With Same ID Already Exist. No Duplicates Are Allowed." << endl;
    }

}

void displayAllStudents(vector<Student>& students)
{
    if (students.size() == 0) cout << "There Are No Elements To Display!" << endl;
    for (Student s : students)
    {
        cout << s << endl << endl;
    }
}

void removeStudentById(vector<Student>& students, int id)
{
    vector<Student>::iterator iter = students.begin();
    bool isFound = false;
    for (iter = students.begin(); iter != students.end(); iter++)
    {
        if (iter->getID() == id) {
            iter = students.erase(iter); // After erasing, iter is now pointing the next location.
           if(iter != students.begin()) --iter; // Go to the prev location because of ++iter in the end of for loop.
            isFound = true;
            cout << "Student Was Removed!" << endl;
            break;
        }
    }
    if (!isFound) {
        cout << "Student Not Found" << endl;
    }
}

Student findStudentById(vector<Student>& students, int id)
{
    Student s;
    for (Student st : students)
    {

        if (st.getID() == id) {

            s = st;
        }
    }
    return s;
}

void showFailingStudents(vector<Student>& students)
{
    for (Student s : students)
    {
        double avg = s.getAverge();

        if (avg < 40) {

             cout << s << endl << endl;
        }
    }
}

int buildGrades(int score1, int score2, int score3, int score4)
{
    int grades = 0;

    grades = grades | score1;
    grades = grades << 8;

    grades = grades | score2;
    grades = grades << 8;

    grades = grades | score3;
    grades = grades << 8;

    grades = grades | score4;

    return grades;

}


/*
* Open text file as an input file stream (ifstream)
* Read text line-by-line from the file
* Parse each line of text.
*/

void readFromFile(vector<Student>& students) {
    cout << "Reding from text file." << endl << endl;

    string line;
    ifstream inStream("students.txt"); // open file as input file stream

    if (inStream.good())  // if file opened successfully, and not empty
    {

        while (getline(inStream, line))   // read a line until false returned , getline() from <string> library
        {

            int id = 0;
            string title;
            string name;
            string course;
            int grades = 0;

            try
            {
                stringstream strStream(line);

                string str;
                getline(strStream, str, ';');

                id = stoi(str); // string to int (throws exceptions)

                getline(strStream, title, ';');

                getline(strStream, name, ';');

                getline(strStream, str, ';');
                grades = stoi(str);

                getline(strStream, course, ';');

                int mask = 0xff;

                int score1 = grades & mask;
                grades = grades >> 8;
                int score2 = grades & mask;
                grades = grades >> 8;
                int score3 = grades & mask;
                grades = grades >> 8;
                int score4 = grades & mask;

                Student  s(id, name, title, course, score1, score2, score3, score4);
                students.push_back(s);

            }
            catch (invalid_argument const& e)
            {
                (void)e;
                cout << "Bad input: std::invalid_argument thrown" << '\n';
                cerr << e.what() << endl;
                system("PAUSE");//used to keep display on screen
            }
            catch (out_of_range const& e)
            {
                (void)e;
                cout << "Integer overflow: std::out_of_range thrown" << '\n';
                cerr << e.what() << endl;
                system("PAUSE");//used to keep display on screen
            }
        }
        inStream.close();
    }
    else
        cout << "Unable to open file, or file is empty.";
}

void writeToFile(vector<Student>& students)
{
    ofstream outStream("students.txt");  // write mode (overwrites existing data)

    if (outStream.good())
    {
        for (Student s : students)
        {

            int id = s.getID();
            string title  = s.getTitle();
            string name = s.getName();
            int* scores = s.getScores();
            int score1 = scores[0];
            int score2 = scores[1];
            int score3 = scores[2];
            int score4 = scores[3];
            int grades = buildGrades(score1, score2, score3, score4);
            string course = s.getCourse();

            outStream << id << ";" << title << ";" << name << ";" << grades << ";" << course << endl;
        }

        outStream.close(); //  close file
        cout << "Students Data Was written To File.\n" << endl;
    }
    else {
        cout << "Unable to open file";
    }

}

bool compareByName( Student& s1, Student& s2)
{
    return s1.getName() < s2.getName();
}

bool compareByAverge( Student& s1, Student& s2)
{
    return s1.getAverge() < s2.getAverge();
}

// sorts data alphabetically by name using bubble sort
vector<Student> sortByName(vector<Student> students)
{
    vector<Student> sorted = students;
    sort(sorted.begin(), sorted.end(), compareByName);

    return sorted;
}
// sorts data by average in an acending order using bubble sort
vector<Student> sortByAverage(vector<Student> students)
{

    vector<Student> sorted = students;
    sort(sorted.begin(), sorted.end(), compareByAverge);

    return sorted;
}

vector<Student> ShowStudentsInCourse(vector<Student>& students, string course)
{
    vector<Student> inCourse;

    for (Student s : students)
    {

        if (s.getCourse() == course) {

            inCourse.push_back(s);
        }
    }
    return inCourse;
}

void display_menu()
{
    system("CLS");//clears screen

    cout << "***************MENU***************" << endl;
    cout << "1. To Add A New Student" << endl;
    cout << "2. To Show Students Details On A Coure Order By Student Name" << endl;
    cout << "3. To Show Students Details On A Coure Order By Average Student Grades" << endl;
    cout << "4. To Find A Student By ID" << endl;
    cout << "5. To Remove A Student By ID" << endl;
    cout << "6. To Show Failing Students" << endl;
    cout << "7. To Show All Students Details" << endl;
    cout << "8. To Exit" << endl;
    cout << "=================================" << endl << endl;
}

int get_choice()
{
    int choice = 0;
    while (choice < 1 || choice > 8)
    {
        display_menu();
        cout << "Please enter your menu choice: ";

        cin >> choice;
        cin.clear();//if users choice not an int and from 1 to 8 clears error state of stream
        cin.ignore(100, '\n');//discard characters remaining in the input buffer
    }
    return choice;
}


void act_on_choice()
{
    vector<Student> students;
    readFromFile(students);
    system("PAUSE");//used to keep display on screen
    vector<Student> inCourse;
    vector<Student> sorted;
    string course;
    int id;
    int choice = 0;
    bool keepLooping = true;
    while (keepLooping)
    {
        try {
            // declaring and initialising variable
            // "choice" with value returned from get_choice()
            choice = get_choice();
            switch (choice)
            {

            case 1:
                system("CLS");//clears screen
                addStudentInVector(students);
                system("PAUSE");//used to keep display on screen
                break;

            case 2:
                system("CLS");
                cout << "Please Enter Course Name: ";
                cin >> course;
                inCourse = ShowStudentsInCourse(students, course);
                sorted = sortByName(inCourse);
                displayAllStudents(sorted);
                system("PAUSE");
                break;

            case 3:
                system("CLS");
                cout << "Please Enter Course Name: ";
                cin >> course;
                inCourse = ShowStudentsInCourse(students, course);
                sorted = sortByAverage(inCourse);
                displayAllStudents(sorted);
                system("PAUSE");
                break;

            case 4: {
                system("CLS");
                cout << "Please Enter Student's ID: ";
                cin >> id;
                Student sid = findStudentById(students, id);
                if (sid.getID() > 0) {
                    cout << sid;
                }
                else
                {
                    cout << "Student With ID " << id << " Does Not Exist!" << endl;
                }
                system("PAUSE");
            }
                  break;

            case 5:
                system("CLS");
                cout << "Please Enter Student's ID: ";
                cin >> id;
                removeStudentById(students, id);
                system("PAUSE");
                break;

            case 6:
                system("CLS");
                showFailingStudents(students);
                system("PAUSE");
                break;

            case 7:
                system("CLS");
                displayAllStudents(students);
                system("PAUSE");
                break;

            case 8:
                cout << "Shutting Down...." << endl;
                cout << "Writing To A File...." << endl;
                writeToFile(students);
                keepLooping = false;
                break;
            }
        }
        catch(exception const& e)
            {
            (void)e;
            // cerr is an object of class ostream that represents the standard error stream
            cerr << e.what() << endl;
            system("PAUSE");//used to keep display on screen
            continue;
            }
    }
}

int main()
{
    act_on_choice();
    return 0;
}
vector<pair<pair<int, int>, vector<Bug*>>> prepareToEatBug(vector<Bug*>& bugs)
{
    vector<Bug*> sorted = sortBySize(bugs); // chk
    vector<pair<pair<int, int>, vector<Bug*>>> eatBug;
    try {
        for (int i = 0; i < 10; i++)
        {
            for (size_t j = 0; j < sorted.size(); j++) //  || j < 10
            {
                size_t sec = j;
                int convertdata = static_cast<int>(sec);
                pair<int, int> poss = eatBug[i].first;

                poss.first = i;


                poss.second = convertdata;
                pair<int, int> pos = sorted[j]->getPosition();
                if (eatBug[i].first == pos)
                {
                    eatBug[i].second.push_back(sorted[j]);
                }
            }
        }
    }
    catch (exception const& e)
    {
        (void)e;
        // cerr is an object of class ostream that represents the standard error stream
        cerr << e.what() << endl;
        system("PAUSE");//used to keep display on screen
    }
    return eatBug;
}
