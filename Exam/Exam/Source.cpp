#pragma once
#include "People.h"

class Library
{
protected:

	struct Pair // How many the same books
	{
		Book book;
		int counter;

		Pair(Book book, int counter) : book(book), counter(counter) {}
	};

	list<Pair> books;

	void AddNewBook()
	{
		try
		{
			Book book;
			book.Fill();

			int count;
			cout << "Enter the number of books (number): "; cin >> count;

			Pair pair(book, count);
			books.push_back(pair);
		}
		catch (...)
		{
			cout << "An error occurred! Failed to create a book!" << endl;
		}
	}
	void DeleteBook()
	{
		for (auto pair : books)
		{
			pair.book.MinInfo();
		}
		cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;

		string title;
		cout << "Enter title: "; getline(cin, title);

		bool found = false;
		for (auto& pair : books)
		{
			if (title == pair.book.title)
			{
				if (pair.counter > 1)
				{
					pair.counter--;
				}
				else if (pair.counter == 1)
				{
					books.remove(pair);
					cout << "Successed!" << endl;

					found = true;
					break;
				}
			}
		}
	}

	friend class Admin;
};

using namespace std;

int Person::idCounter = 0;

void main()
{
	int key = 0;
	while (key != 13)
	{
		key = _getch();
		cout << key << endl;
	}
}