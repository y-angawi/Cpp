#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Bug
{
protected:
	int id;
	pair<int, int> position;
	int direction;
	int size;
	bool alive;
	list<pair<int, int>> path;
    int eatenBy;
    string type;

public:
    Bug();
	Bug(int id, pair<int, int> position, int direction, int size);
	virtual void move()=0;
    int getID();
    pair<int, int> getPosition();
    int getDirection();
    int getSize();
    bool getStatus();
    int getEatenBy();
    string getType();
    list<pair<int, int>> getPath();
    void addPathToList(int x, int y);
    bool isWayBlocked();

    void setID(int id);
    void setPosition(pair<int, int> position);
    void setDirection(int direction);
    void setSize(int size);
    void setType(string type);
    void setStatus(bool alive);
    void setEatenBy(int eatenBy);
    friend ostream& operator<<(ostream& out, Bug& b);
	~Bug();
};

