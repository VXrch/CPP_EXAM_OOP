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


		if (!admins.empty())
		{
			is_found = admin.LogIn(admins, nickname, password);
			if (is_found)
				return "admin";
		}

		if (!users.empty())
		{
			is_found = user.LogIn(users, nickname, password);
			if (is_found)
				return "user";
		}

		if (is_found == false)
		{
			cout << "Incorrect data!" << endl;
		}

		system("pause");
		return "false";
	}
	
	bool InRange() const 
	{
		bool ext = false;
		Move move;
		move(1, 0);

		while (!ext)
		{
			move.Gotoxy(2, 0); cout << "Find book in range...";
			move.Gotoxy(2, 1); cout << "Find book by...";
			move.Gotoxy(); cout << "->";

			string go_to = move.CatchMove();

			if (go_to == "enter")
			{
				if (move.Y == 0)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (go_to == "down")
			{
				move.Y == 1 ? move.Y = 0 : move.Y++;
			}
			else if (go_to == "up")
			{
				move.Y == 0 ? move.Y = 1 : move.Y--;
			}
		}
	}
	
	void FindBookInRange() const
	{
		bool ext = false;
		Move move;
		move(1, 1);

		while (!ext)
		{
			move.Gotoxy(2, 0); cout << "-*-*-*-*-*-*-*| Find book by |**-*-*-*-*-*-";
			move.Gotoxy(2, 1); cout << "Number of books";
			move.Gotoxy(2, 2); cout << "FindBookBy_type";
			move.Gotoxy(2, 3); cout << "FindBookBy_title";
			move.Gotoxy(2, 4); cout << "FindBookBy_author";
			move.Gotoxy(2, 5); cout << "FindBookBy_ageRating";
			move.Gotoxy(2, 6); cout << "FindBookBy_year";
			move.Gotoxy(2, 7); cout << "FindBookBy_price";
			move.Gotoxy(2, 8); cout << "FindBookBy_id";
			move.Gotoxy(2, 9); cout << "FindBookBy_Genre";
			move.Gotoxy(2, 10); cout << "FindBookBy_language";
			move.Gotoxy(); cout << "->";

			string go_to = move.CatchMove();

			if (go_to == "enter")
			{
				if (move.Y == 1)
				{

				}
				else if (move.Y == 2)
				{

				}
				else if (move.Y == 3)
				{

				}
				else if (move.Y == 4)
				{

				}
				else if (move.Y == 5)
				{

				}
				else if (move.Y == 6)
				{

				}
				else if (move.Y == 7)
				{

				}
				else if (move.Y == 8)
				{

				}
				else if (move.Y == 9)
				{

				}
				else
				{

				}
			}
			else if (go_to == "down")
			{
				move.Y == 1 ? move.Y = 0 : move.Y++;
			}
			else if (go_to == "up")
			{
				move.Y == 0 ? move.Y = 1 : move.Y--;
			}
		}
	}
	void FindBookBy() const
	{

	}

	void FindBookMenu() const
	{
		bool inRange = InRange();

		if (inRange == true)
		{
			FindBookInRange();
		}
		else
		{

		}
	}

public:

	string StartProgram()
	{
		User user;
		fw.ReadFromFile(library, admins, users);
		Move move;
		move(0, 1);

		bool ext = false;
		while (ext == false)
		{
			system("cls");

			move.Gotoxy(); cout << "-->";
			move.Gotoxy(1, 0); cout << "+-+-+-+-+-| Welcome to book shop! | -+-+-+-+-+" << endl;
			move.Gotoxy(4, 1); cout << "Log in";
			move.Gotoxy(4, 2); cout << "Register";
			move.Gotoxy(4, 3); cout << "Exit";

			string go_to = move.CatchMove();

			if (go_to == "enter")
			{
				if (move.Y == 1)
				{
					if (!users.empty() || !admins.empty())
					{
						string result = "";
						result = LogIn(users, admins);

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
						system("cls");
						cout << "Users data is empty!" << endl;
						system("pause"); system("cls");
					}
				}
				else if (move.Y == 2)
				{
					if (user.Register(users))
					{
						return "user";
					}
				}
				else
				{
					return "exit";
				}
			}
			else if (go_to == "down")
			{
				move.Y == 3 ? move.Y = 1 : move.Y++;
			}
			else if (go_to == "up")
			{
				move.Y == 1 ? move.Y = 3 : move.Y--;
			}
		}
		return "a";
	}	
	void Menu_Admin()
	{
		/*
			Зміна інформації про книгу +
			Додавання книги +
			Видалення книги +
			Додавання знижки на всі книги
			Додавання знижки на книгу за характеристикою
			За назвою
			За жанром
			За автором
			На всі книги
			За мовою видання
			За роком випуску
			За ціною (діапазон)
			За віковим рейтингом
			За типом
			Пошук користувача
			За характристикою
			За іменем
			За фамілією
			За віком
			За номером телефона
			За вподобанням
			В діапазоні
			За віком
			Всіх хто замовив конктетний товар
			Всіх хто замовляв
			За вподобанням
			За автором
			За жанром
			За мовою видання
			За роком випуску
			За роками випуску (діапазон)
			
		
		*/
	}
	void Menu_User()
	{

	}
};

void main()
{

	// Add to write to file and resd from file vector of GENRES in USER

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
