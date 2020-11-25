#pragma once
#include "Bug.h"
#include <vector>
using namespace std;

class Crawler :	public Bug
{

public:
	Crawler(int id, pair<int, int> position, int direction, int size);
	void move();
	friend ostream& operator<<(ostream& out, Crawler& h);
	~Crawler();
};

