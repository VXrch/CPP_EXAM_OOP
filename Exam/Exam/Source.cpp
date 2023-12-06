#pragma once
#include "People.h"

class Library
{
	struct Pair // How many the same books
	{
		Book book;
		int counter;
	};

	list<Pair> books;
};

using namespace std;

int Person::idCounter = 0;

void main()
{
	int key = 0;
	while (key != 13)
	{
		key = _getch();
		cout << key << endl;
	}
}