#include "People.h"

void Person::Print() const // basic info
{
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

bool Person::Register(vector<Person> all_users)
{
	try
	{
		bool ext = false;

		cout << "Fill out the form with information about yourself: " << endl;
		cout << "Your name: "; getline(cin, name);
		cout << "Your surname: "; getline(cin, surname);
		cout << "Phone number: "; getline(cin, phone);

		while (!ext)
		{
			system("cls");
			cout << "your age (number): ";
			if (!(cin >> age))
			{
				cin.clear(); // Clear errors
				cin.ignore(10000, '\n'); // Crear buffer
				cout << "Age must be a number! Incorrect argument!" << endl;
			}
			else
			{
				ext = true;
			}
		}
		ext = false;

		system("cls"); cout << "Ok!" << endl; system("pause"); system("cls");

		while (!ext)
		{
			bool go = false;
			go = MakeNickname(all_users);

			if (go == false)
			{
				if (isContinue() == true)
				{
					system("cls");
				}
				else
				{
					return false;
				}
			}
			else
			{
				ext = true;
			}
		}
		ext = false;

		while (!ext)
		{
			bool go = false;
			go = MakeUpPassword();

			if (go == false)
			{
				if (!isContinue())
				{
					system("cls");
					return false;
				}
			}
			else
			{
				ext = true;
			}
		}

		idCounter++;
		id = idCounter;

		return true;
	}
	catch (const exception& exception)
	{
		cout << exception.what() << endl;
		return false;
	}
}
bool Person::LogIn(vector<Person> all_users)
{
	bool nckname = false;
	bool pswrd = false;
	cout << "Enter your nickname: "; cin >> nickname;
	cout << "Enter your password: "; cin >> password;

	for (int i = 0; i < all_users.size(); i++)
	{
		if (all_users[i].GetNickname() == nickname)
		{
			nckname;
		}
	}
	return true;
}

bool Person::MakeNickname(vector<Person> all_users)
{
	bool ext = false, go = false;
	while (!ext)
	{
		cout << "To exit press [0]" << endl;
		cout << "Make up a nickname:"; cin >> nickname;

		if (nickname == "0")
		{
			system("cls");
			return false;
		}
		else
		{
			for (int i = 0; i < all_users.size(); i++)
			{
				if (nickname == all_users[i].GetNickname())
				{
					cout << "This nickname already exists. Please enter another one!" << endl;
					system("pause"); system("cls");
					go = false;
					break;
				}
			}
			if (go == true)
			{
				system("cls");
				return true;
			}
			go = true;
		}
	}
}
bool Person::MakeUpPassword()
{
	bool ext = false;
	while (!ext)
	{
		cout << "To exit press [0]" << endl;
		cout << "The password must contain at least 8 characters, numbers and letters." << endl;
		cout << "your password: "; cin >> password;

		if (password == "0")
		{
			return false;
		}

		if (password.length() < 8)
		{

		}
	}
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




