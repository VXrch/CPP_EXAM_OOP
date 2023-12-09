#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

class IncorrectValue : public exception
{
public:

	friend ostream& operator<<(ostream& os, const IncorrectValue& obj)
	{
		os << "An incorrect data type has been entered! ";
		return os;
	}
};
class IdDoesNotExist : public exception
{
public:

	friend ostream& operator<<(ostream& os, const IdDoesNotExist& obj) 
	{
		os << "That id doesn't exist! ";
		return os;
	}
};
class PermissionDenied : public exception
{
public:

	friend ostream& operator<<(ostream& os, const PermissionDenied& obj)
	{
		os << "This menu is for administrators only. Permission denied!";
		return os;
	}
};


struct Move
{
	int X;
	int Y;

	Move() : X(0), Y(0) {}
	Move(int X, int Y) : X(X), Y(Y) {}

	void Gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void Gotoxy()
	{
		COORD coord;
		coord.X = this->X;
		coord.Y = this->Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	string CatchMove()
	{
		system("cls");
		bool ext = false;

		while (ext == false)
		{
			int key = _getch();

			if (key == 13) // Enter
			{
				return "enter";
			}
			else if (key == 87 || key == 119) // [W / w] [up]
			{
				return "up";
			}
			else if (key == 83 || key == 115) // [S / s] [down]
			{
				return "down";
			}
			else if (key == 224)
			{
				key = _getch();

				if (key == 72) // up
				{
					return "up";
				}
				else if (key == 80) // down
				{
					return "down";
				}
			}
		}
	}

	string PasswordAnimation()
	{
		bool ext = false;
		string password;
		int password_len = 0;

		while (!ext)
		{
			
			
		}
	}

	void hidecursor()
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);
	}

	template<typename T>
	void SecureEnter(T &temp)
	{
		if (cin >> temp)
		{
			// Everything is fine!
		}
		else
		{
			cin.clear();
			cin.ignore(10000, '\n');
			throw IncorrectValue();
		}
	}

	void operator()(int X, int Y)
	{
		this->X = X;
		this->Y = Y;
	}
};