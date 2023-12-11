#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <map>
#include <type_traits>

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
class EmptyData : public exception
{
public:

	friend ostream& operator<<(ostream& os, const EmptyData& obj)
	{
		os << "The transferred data is empty!";
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
		string password;
		int password_len = 0;

		char key = '-';

		while (key != '\r')
		{
			system("cls");

			cout << "- - - Enter password - - -" << endl;
			for (int i = 0; i < password_len; i++)
			{
				cout << "*";
			}

			key = _getch();

			if (key == '\b')
			{
				if (!password.empty())
				{
					password.erase(password.size() - 1);
					password_len--;
				}
			}
			else if (key != '\r')
			{
				password += key;
				password_len++;

				cout << key;
				for (int i = 0; i < 16000; i += 1)
				{
					if (_kbhit())
					{
						break;
					}
				}
			}
		}
		return password;
	}

	bool IsUnique(vector<int> search_in, int value) const
	{
		for (int i = 0; i < search_in.size(); i++)
		{
			if (value == search_in[i])
			{
				return false;
			}
		}
		return true;
	}
	bool IsUnique(vector<float> search_in, float value) const
	{
		for (int i = 0; i < search_in.size(); i++)
		{
			if (value == search_in[i])
			{
				return false;
			}
		}
		return true;
	}
	bool IsUnique(vector<string> search_in, string value) const
	{
		for (int i = 0; i < search_in.size(); i++)
		{
			if (value == search_in[i])
			{
				return false;
			}
		}
		return true;
	}

	void PrintByCoord(int X, vector<int> Y, char symbhol)
	{
		for (int i = 0; i < Y.size(); i++)
		{
			Gotoxy(X, Y[i]); cout << symbhol;
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
			return;
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