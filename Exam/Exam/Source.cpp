#pragma once
#include "FilesWork.h"

using namespace std;

int Person::idCounter = 0;
unsigned int Book::idCounter = 0;

class Menu
{
	Library library;
	vector<Admin> admins;
	vector<User> users;
	FilesWork fw;

	string LogIn(vector<User> users, vector<Admin> admins)
	{
		Admin admin; User user;

		bool is_found = false;
		string nickname, password;

		cout << "Enter your nickname: "; cin >> nickname;
		cout << "Enter your password: "; cin >> password;

		is_found = admin.LogIn(admins, nickname, password);
		if (is_found)
			return "admin";

		is_found = user.LogIn(users, nickname, password);
		if (is_found)
			return "user";

		if (is_found == false)
		{
			cout << "Incorrect data!" << endl;
		}
		return "false";
	}

public:

	Menu() : library(), admins(), users(), fw() {}

	string StartProgram()
	{
		fw.ReadFromFile(library, admins, users);
		Move move(1, 3);

		bool ext = false;
		while (ext == false)
		{
			system("cls");

			move.Gotoxy(3, 0); cout << "Welcome to book shop!" << endl;
			move.Gotoxy(3, 1); cout << "Log in";
			move.Gotoxy(3, 2); cout << "Register";

			move.Gotoxy(); cout << "->";

			string go_to = move.CatchMove();

			/*if (go_to == "enter")
			{
				if (move.Y == 2)
				{
					string result = LogIn(users, admins);
					if (result == "admin")
					{
						return "admin";
					}
					else if (result == "user")
					{
						return "user";
					}
				}
				else
				{
					if (users[0].Register(users))
					{
						return "user";
					}
				}
			}
			else if (go_to == "up")
			{
				move.Y == 2 ? move.Y = 3 : move.Y++;
			}
			else if (go_to == "down")
			{
				move.Y == 3 ? move.Y = 2 : move.Y--;
			}*/
		}
		return "a";
	}	
};

void main()
{
	Move move;
	move.hidecursor();
	
	Menu MainMenu;
	string Who_I_Am = MainMenu.StartProgram();
	if (Who_I_Am == "admin")
	{
		cout << "MAIN MENU ADMIN" << endl;
	}
	else if (Who_I_Am == "user")
	{
		cout << "MAIN MENU USER" << endl;
	}
}
