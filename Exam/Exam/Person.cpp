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
