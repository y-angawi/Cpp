#pragma once
#include "Bug.h"
#include <vector>
using namespace std;

class Hopper : public Bug
{
	int hopLength;
public:
	Hopper(int id, pair<int, int> position, int direction, int size, int hopLength);
	void move();
	int getHopLength();
	void setHopLength(int hopLength);
	friend ostream& operator<<(ostream& out, Hopper& h);
	~Hopper();
};

