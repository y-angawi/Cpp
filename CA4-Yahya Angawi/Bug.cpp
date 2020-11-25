#include "Bug.h"
#include <iostream>
#include <vector>
#include <fstream>      // file stream
#include <string>
#include <istream>
#include <sstream>    // string stream
#include <algorithm>
#include <exception>
using namespace std;


Bug::Bug()
{
	this->setID(0);
	this->setPosition(make_pair(0, 0));
	this->setDirection(2);
	this->setSize(1);
	this->setStatus(true);
}

Bug::Bug(int id, pair<int, int> position, int direction, int size)
{
	this->setID(id);
	this->setPosition(position);
	this->setDirection(direction);
	this->setSize(size);
	this->setStatus(true);
}

Bug::~Bug(){}

int Bug::getID()
{
	return id;
}

pair<int, int> Bug::getPosition()
{
	return position;
}

int Bug::getDirection()
{
	return direction;
}

int Bug::getSize()
{
	return size;
}

bool Bug::getStatus()
{
	return alive;
}

int Bug::getEatenBy()
{
	return eatenBy;
}

string Bug::getType()
{
	return type;
}

list<pair<int, int>> Bug::getPath()
{
	return path;
}

void Bug::addPathToList(int x, int y)
{
	path.push_back(make_pair(x, y));
}

bool Bug::isWayBlocked()
{
	if (direction == 1) { return position.second == 0; }
	else if (direction == 2) { return position.first == 9; }
	else if (direction == 3) { return position.second == 9; }
	else if (direction == 4) { return position.first == 0; }
	return false;
}

void Bug::setID(int id)
{
	this->id = id;
}

void Bug::setPosition(pair<int, int> position)
{
	this->position = position;
}

void Bug::setDirection(int direction)
{
	this->direction = direction;
}

void Bug::setSize(int size)
{
	this->size = size;
}

void Bug::setType(string type)
{
	this->type = type;
}

void Bug::setStatus(bool alive)
{
	this->alive = alive;
}

void Bug::setEatenBy(int eatenBy)
{
	this->eatenBy = eatenBy;
}

ostream& operator<<(ostream& out, Bug& bug)
{
	out << "Bug Details: " << endl;
	out << "ID : " << bug.id << endl;

	out << "Location : " << "(" << bug.position.first << "," << bug.position.second << ")" << endl;
	if (bug.direction == 1) { out << "Direction : North" << endl; }
	else if (bug.direction == 2) { out << "Direction : East" << endl; }
	else if (bug.direction == 3) { out << "Direction : South" << endl; }
	else { out << "Direction : West" << endl; }
	out << "Size : " << bug.size << endl;
	if (bug.alive == true) {
		out << "Status : Alive!" << endl;
	}
	else {
		out << "Status : Eaten By " << bug.alive << endl;
	}

	return out;
}
