#pragma once
#include "Base_classes.h"
#include <map>

using namespace std;

class Admin : public Person
{




};

class User : public Person
{
	struct Preferences
	{
		map<string, int> authors;
		map<string, int> language;

		Preferences() : authors(), language() {}

		bool isEmpty() const
		{
			if (authors.empty() && language.empty())
			{
				return true;
			}
			return false;
		}
		void Print() const
		{
			if (!authors.empty())
			{
				cout << "Authors:" << endl;
				for (const auto& author : authors) {
					cout << "  " << author.first << ": " << author.second << endl;
				}
			}
			if (!language.empty())
			{
				cout << "Language:" << endl;
				for (const auto& lang : language) {
					cout << "  " << lang.first << ": " << lang.second << endl;
				}
			}
		}
	};

	Preferences preferences;
	vector<string> cart;
	vector<string> orders;

	User(string name, string surname, int age, string phone, string nickname, string password) : cart(), orders(), preferences(), Person(name, surname, age, phone, nickname, password) {}

public:

	void Print() const override
	{
		Person::Print();

		if (!preferences.isEmpty())
		{
			preferences.Print();
		}


	}

};