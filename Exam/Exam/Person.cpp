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
