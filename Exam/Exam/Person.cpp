#include "People.h"

void Person::Print() const // basic info
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Surname " << surname << endl;
	cout << "Age: " << age << endl;
	cout << "Phone: " << phone << endl;
}
void Person::PrintSecretInfo() const // info to login
{
	cout << "Nickname: " << nickname << endl;
	cout << "Password: " << password << endl;
}

bool Person::isContinue()
{
	bool ext = false;
	Move move(2, 2);

	while (ext)
	{
		system("cls");
		move.Gotoxy(2, 1); cout << "You can`t register without nickname. Do you want to exit?" << endl;
		move.Gotoxy(2, 2); cout << "Yeah, I want to get out";
		move.Gotoxy(2, 3); cout << "No, I want to continue (back to fill)";
		move.Gotoxy(); cout << ">";

		string go_to = move.CatchMove();

		if (go_to == "enter")
		{
			if (move.Y == 2)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else if (go_to == "up")
		{
			move.Y == 2 ? move.Y = 3 : move.Y++;
		}
		else if (go_to == "down")
		{
			move.Y == 3 ? move.Y = 2 : move.Y--;
		}
	}
}

bool Person::MakeUpPassword()
{
	Move move;
	bool ext = false, password_len = false, fd_capital = false, fd_small = false, fd_numbers = false;
	while (!ext)
	{
		cout << "To exit press [0]" << endl;
		cout << "The password must contain at least 8 characters, numbers capital and small letters." << endl;
		cout << "your password: "; password = move.PasswordAnimation();

		if (password == "0")
		{
			return false;
		}

		for (auto symbhol : password)
		{
			if (isdigit(symbhol))
			{
				fd_numbers = true;
			}
			if (isupper(symbhol))
			{
				fd_capital = true;
			}
			if (islower(symbhol))
			{
				fd_small = true;
			}
		}

		system("cls");
		if (password.length() < 8)
		{
			cout << "Password length is smaller than 8! Make up a longer one!" << endl << endl;
		}
		else
		{
			password_len = true;
		}
		if (fd_numbers == false)
		{
			cout << "The password must have numbers!" << endl << endl;
		}
		if (fd_capital == false)
		{
			cout << "The password must have capital letters!" << endl << endl;
		}
		if (fd_small == false)
		{
			cout << "The password must have small letters!" << endl << endl;
		}

		if (fd_numbers == true && fd_small == true && fd_capital == true && password_len == true)
		{
			return true;
		}

		system("pause");
		system("cls");
	}
}
