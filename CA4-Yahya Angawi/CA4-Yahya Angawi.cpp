// Inheritence.cpp : Defines the entry point for the console application.
//
#include "Bug.h"
#include "Bug.cpp"
#include "Hopper.h"
#include "Hopper.cpp"
#include "Crawler.h"
#include "Crawler.cpp"
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <algorithm>
#include <exception>
#include <vector>      
#include <string>    
using namespace std;
                            
void displayAllBugs(vector<Bug*>& bugs)
{
	for (Bug* b : bugs)
	{
		cout << *b << endl << endl;
	}
}

bool compareBySize(Bug* bg1, Bug* bg2)
{
    return bg1->getSize() > bg2->getSize();
}
// sorts data by size in an acending order using bubble sort
vector<Bug*> sortBySize(vector<Bug*> bugs)
{

    vector<Bug*> sorted = bugs;
    sort(sorted.begin(), sorted.end(), compareBySize);

    return sorted;
}

void moveAllBugs(vector<Bug*>& bugs)
{
    for (Bug* bg : bugs)
    {
        bg->move();
    }
    vector<Bug*> sorted = sortBySize(bugs); // chk
    int sizeSum = 0;
    for (size_t i = 0; i < sorted.size(); i++)
    {
        Bug* bigBug = sorted[i];
        sizeSum = bigBug->getSize();
        for (size_t j = i+1; j < sorted.size(); j++)
        {
            Bug* bg = sorted[j];
            if (bg->getPosition() == bigBug->getPosition() && bg->getSize() < bigBug->getSize()) // Two or more bugs equal in size won’t be able to eat each.
            {
                bg->setStatus(false);
                bg->setEatenBy(bigBug->getID());
                sizeSum += bg->getSize();
            }
        }
        bigBug->setSize(sizeSum);
    }
    cout << "All Bugs Were Moved!" << endl << endl;
}

void findBugById(vector<Bug*>& bugs, int id)
{
    bool found = false;
    for (Bug* bg : bugs)
    {

        if (bg->getID() == id) {

            cout << *bg;
            found = true;
        }
    }
    if (found == false)
    {
        cout << "Bug With ID " << id << " Does Not Exist!" << endl;
    }
}

string listToString(list<pair<int, int>> list)
{
    stringstream s;
    for (pair<int, int> pr : list)
    {
        s << "(" << pr.first << ", " << pr.second << "), ";
    }
    s.str().pop_back(); // to delete the extra comma at the end
    return s.str();
}

void lifeHistory(vector<Bug*>& bugs)
{

    for (Bug* bg : bugs)
    {
        string path;
        cout << bg->getID();
        if (typeid(bg) == typeid(Crawler)) {
            cout << " Crawler ";
        }
        else { cout << " Hopper "; }
        list<pair<int, int>> list = bg->getPath();
        path = listToString(list);
        cout << path;
        if(bg->getStatus() == true){
            cout << " Alive!" << endl << endl;
        }else{ 
            cout << " Eaten By " + bg->getEatenBy() << endl << endl;
        }
    }
}

void displayAllCells(vector<Bug*>& bugs)
{
    for (int i = 0; i < 10; i++) 
    {
        string empty = "Empty";
        int id = 0;
        for (size_t j = 0; j < bugs.size(); j++)
        {
            if (j < 10) 
            {
                cout << "(" << i << "," << j << "): ";
            }else{ cout << "(" << i << "," << 9 << "): "; }
            
            if (bugs[j]->getPosition().first == i && bugs[j]->getPosition().second == j)
            {
               
                empty = bugs[j]->getType();
                id = bugs[j]->getID();
                cout << empty << " " << id <<"," << endl << endl;
                
            }
            else
            {
                cout << empty << "," << endl << endl;
            }
        }
    }
    
}

void readFromFile(vector<Bug*>& bugs)
{
    cout << "Reding from text file." << endl << endl;

    string line;
    ifstream inStream("D:/C++/CA4/CA4-Yahya Angawi/bugs.txt"); // open file as input file stream

    if (inStream.good())  // if file opened successfully, and not empty
    {

        while (getline(inStream, line))   // read a line until false returned , getline() from <string> library
        {

            string type;
            int id = 0;
            int x = 0;
            int y = 0;
            int direction = 0;
            int size = 0;
            int hopLength = 0;
            try
            {
                stringstream strStream(line);

                string str;

                getline(strStream, type, ';');

                getline(strStream, str, ';');
                id = stoi(str); // string to int (throws exceptions)
                
                getline(strStream, str, ';');
                x = stoi(str);
                
                getline(strStream, str, ';');
                y = stoi(str);
                
                getline(strStream, str, ';');
                direction = stoi(str);
                
                getline(strStream, str, ';');
                size = stoi(str);
                
                pair<int, int> pos = make_pair(x, y);
                if (type == "H") {
                    getline(strStream, str, ';');
                    hopLength = stoi(str);
                    
                    Hopper* h = new Hopper(id, pos, direction, size, hopLength);
                    h->setType("Hopper");
                    bugs.push_back(h);
                }
                else {
                    Crawler* c = new Crawler(id, pos, direction, size);
                    c->setType("Crawler");
                    bugs.push_back(c);
                }

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
    { 
        cout << "Unable to open file, or file is empty." << endl; 
        system("PAUSE"); // had to add it to show the above message
    }

}

void writeToFile(vector<Bug*>& bugs)
{
    ofstream outStream("bugs_life.out");  // write mode (overwrites existing data)

    if (outStream.good())
    {

        for (Bug* bg : bugs)
        {
            int id = bg->getID();
            string type;
            if (typeid(bg) == typeid(Crawler))
            {
                type = "Crawler";
            }
            else
            {
                type = "Hopper";
            }

            string status;
            if (bg->getStatus() == true)
            {
                status = "Alive!";
            }
            else
            {
                status = "Eaten By " + bg->getEatenBy();
            }
            list<pair<int, int>> list = bg->getPath();
            string path = listToString(list);
            outStream << id << ";" << type << "; Path:" << path << ";" << status << endl;
        }
        outStream.close(); //  close file
        cout << "Bugs Life History Data Was written To File.\n" << endl;
    }
    else {
        cout << "Unable to open file";
    }

}

void display_menu()
{
    system("CLS");//clears screen

    cout << "***************MENU***************" << endl;
    cout << "1. To Initialize Bug Board" << endl;
    cout << "2. To Display All Bugs" << endl;
    cout << "3. To Find A Bug By ID" << endl;
    cout << "4. To Tap the Bug Board (Causes Move All, Then Fight/Eat)" << endl;
    cout << "5. To Display Life History Of All Bugs (Path Taken)" << endl;
    cout << "6. To Display All Cells And Their Bugs" << endl;
    cout << "7. To Exit (Write Life History Of All Bugs To File)" << endl;
    cout << "=================================" << endl << endl;
}

int get_choice()
{
    int choice = 0;
    while (choice < 1 || choice > 7)
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
    vector<Bug*> bugs;
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
                readFromFile(bugs);
                system("PAUSE");//used to keep display on screen
                break;

            case 2:
                system("CLS");
                displayAllBugs(bugs);
                system("PAUSE");
                break;

            case 3:
                system("CLS");
                cout << "Please Enter Bug's ID: ";
                cin >> id;
                findBugById(bugs, id);
                system("PAUSE");
                break;

            case 4: 
                system("CLS");
                moveAllBugs(bugs);
                system("PAUSE");
                  break;

            case 5:
                system("CLS");
                lifeHistory(bugs);
                system("PAUSE");
                break;

            case 6:
                system("CLS");
                displayAllCells(bugs);
                system("PAUSE");
                break;

            case 7:
                cout << "Shutting Down...." << endl;
                cout << "Writing To A File...." << endl;
                writeToFile(bugs);
                
                for (Bug* bg : bugs)
                {
                    delete bg;	// free the memory;
                }
                /*int size = bugs.size();
               for (int i = 0, size = bugs.size(); i < size; i++) {
                   Bug* bg = bugs.at(i);
                   delete bg;
                }*/
                /*vector<unique_ptr<Bug*>>::iterator i;
                for (i = bugs.begin(); i < bugs.end(); i++)
                    delete* i;*/
                //while (!bugs.empty()) delete bugs.back(), bugs.pop_back();
                //bugs.clear(); // clear the contents of the vector as the objects it points to have been freed.
                keepLooping = false;
                break;
            }
        }
        catch (exception const& e)
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
