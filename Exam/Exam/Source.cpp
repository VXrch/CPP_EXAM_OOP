#pragma once
#include "FilesWork.h"

using namespace std;

int Person::idCounter = 0;
unsigned int Book::idCounter = 0;
void menu(Library& library, vector<Admin>& admins, vector<User>& users);

void main()
{
	Library library;
	vector<Admin> admins;
	vector<User> users;

	menu(library, admins, users);



}

void menu(Library& library, vector<Admin>& admins, vector<User>& users)
{
	FilesWork fw;
	fw.ReadFromFile(library, admins, users);

	system("pause");


}
