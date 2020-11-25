
#include "Crawler.h"
#include <stdlib.h>     /* srand, rand */
#include <vector>
using namespace std;


Crawler::Crawler(int id, pair<int, int> position, int direction, int size) : Bug(id, position, direction, size){}

void Crawler::move()
{
	int first = 0;
	int second = 0;
	if (!isWayBlocked()) {
		if (direction == 1) {
			second = position.second--;
			setPosition(make_pair(position.first, second));
			addPathToList(position.first, second);
		}
		else if (direction == 2) {
			first = position.first++;
			setPosition(make_pair(first, position.second));
			addPathToList(first, position.second);
		}
		else if (direction == 3) {
			second = position.second++;
			setPosition(make_pair(position.first, second));
			addPathToList(position.first, second);
		}
		else if (direction == 4) {
			first = position.first--;
			setPosition(make_pair(first, position.second));
			addPathToList(first, position.second);
		}
	}else
	{
		bool moved = false;
		int newDir = 0;
		while (!moved) {
			newDir = rand() % 40 + 1; /* (or % 4) generate secret number between 1 and 4 */
			setDirection(newDir);
			if (!isWayBlocked()) {

				if (direction == 1) {
					second = position.second--;
					setPosition(make_pair(position.first, second));
					addPathToList(position.first, second);
					moved = true;
				}
				else if (direction == 2) {
					first = position.first++;
					setPosition(make_pair(first, position.second));
					addPathToList(first, position.second);
					moved = true;
				}
				else if (direction == 3) {
					second = position.second++;
					setPosition(make_pair(position.first, second));
					addPathToList(position.first, second);
					moved = true;
				}
				else if (direction == 4) {
					first = position.first--;
					setPosition(make_pair(first, position.second));
					addPathToList(first, position.second);
					moved = true;
				}
			}
			
		}
	}
}

ostream& operator<<(ostream& out, Crawler& bug)
{
	out << "Bug Details: " << endl;
	out << "ID : " << bug.id << endl;
	out << "Type : Crawler" << endl;
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
		out << "Status : Eaten By " << bug.eatenBy << endl;
	}

	return out;
}

Crawler::~Crawler(){}
