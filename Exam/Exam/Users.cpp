#include "Users.h"

using namespace std;

void User::Print() const
{
	Person::Print();

	bool printed = false;

	if (!preferences.isEmpty())
	{
		preferences.Print();
		printed = true;
	}
	if (!cart.empty())
	{
		cout << "CART:" << endl;
		for (int i = 0; i < cart.size(); i++)
		{
			cout << cart[i] << endl;
		}
		printed = true;
	}
	if (!orders.empty())
	{
		cout << "Orders: " << endl;
		for (int i = 0; i < orders.size(); i++)
		{
			cout << orders[i] << endl;
		}
		printed = true;
	}
	if (printed == false)
	{
		cout << "Shopping cart and order list are empty!" << endl;
	}
}

void User::Preferences::FindFavoriteAuthor()
{
	int maxValue = 0;

	for (const auto& pair : authors)
	{
		if (pair.second > maxValue)
		{
			favoriteAuthor = pair.first;
			maxValue = pair.second;
		}
	}
}
void User::Preferences::FindFavoriteLanguage()
{
	int maxValue = 0;

	for (const auto& pair : languages)
	{
		if (pair.second > maxValue)
		{
			favoriteLanguage = pair.first;
			maxValue = pair.second;
		}
	}
}
void User::Preferences::Print() const
{
	if (!authors.empty())
	{
		cout << "author:" << endl;
		for (const auto& author : authors) {
			cout << "  " << author.first << ": " << author.second << endl;
		}
	}
	if (!languages.empty())
	{
		cout << "Language:" << endl;
		for (const auto& lang : languages) {
			cout << "  " << lang.first << ": " << lang.second << endl;
		}
	}
}