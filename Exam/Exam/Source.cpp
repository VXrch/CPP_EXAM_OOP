#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <list>
#include <map>

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