#pragma once
#include "Base_classes.h"
#include <map>

using namespace std;

class Admin : public Person
{




};

class User : public Person
{
	class Preferences
	{
		
		map<string, int> authors;
		map<string, int> languages;

		string favoriteAuthor;
		string favoriteLanguage;

		void FindFavoriteAuthor();
		void FindFavoriteLanguage();

	public:

		Preferences() : authors(), languages() {}

		string GetFavAuthor() const
		{
			return favoriteAuthor;
		}
		string GetFavLanguage() const
		{
			return favoriteLanguage;
		}

		bool isEmpty() const
		{
			if (authors.empty() && languages.empty())
			{
				return true;
			}
			return false;
		}
		void Print() const;

		void NewBook(string author, string language)
		{
			this->authors[author]++;
			this->languages[language]++;

			FindFavoriteAuthor();
			FindFavoriteLanguage();
		}
	};
	struct Order
	{
		enum Status { None, In_Processing, Sent, OnTheRroad, Delivered, Canceled };

		Book book;
		int BooksCounter;

		string address;
		float coast;

		Status status;

		Order(Book book) : book(book), BooksCounter(0), address(""), coast(0.0), status(None) {}
		float GetCoast()
		{
			if (BooksCounter != 0)
			{
				return book.GetPrice() * BooksCounter;
			}
			else
			{
				return book.GetPrice();
			}
		}

		/// <summary>
		/// [0 = None][1 = In_Processing][2 = Sent][3 = OnTheRroad][4 = Delivered][5 = Canceled]
		/// </summary>
		/// <param name="number"></param>
		void SetStatus(int number)
		{
			switch (number)
			{
			case 0: status = None; break;
			case 1: status = In_Processing; break;
			case 2: status = Sent; break;
			case 3: status = OnTheRroad; break;
			case 4: status = Delivered; break;
			case 5: status = Canceled; break;
			default: cout << "Wrong number!" << endl; break;
			}
		}
	};

	Preferences preferences;
	vector<Book> cart;
	vector<Order> orders;
	vector<string> wishlist; // add id of concrete book and add book to preferences

	User(string name, string surname, int age, string phone, string nickname, string password) : cart(), orders(), preferences(), wishlist(), Person(name, surname, age, phone, nickname, password) {}

public:

	void Print() const override;

	string GetFavoriteAuthor() const
	{
		return preferences.GetFavAuthor();
	}
	string GetFavoriteLanguage() const
	{
		return preferences.GetFavLanguage();
	}

	void PlaceOrder(Book book)
	{
		try 
		{
			Order order(book);
			cout << "Enter the number of books you want to order: "; cin >> order.BooksCounter;
			if (!(cin >> order.BooksCounter))
			{
				throw runtime_error("Invorrect type! Try entering a number next time!");
			}
			if (order.BooksCounter == 0)
			{
				cout << "Minimum number to order is 1 book!" << endl;
			}
			cout << "Enter the address for delivery: "; cin >> order.address;
			cout << "Total coast will be: " << order.GetCoast();

			string password;
			cout << "Enter your account password to confirm your order (or [0] to cansel): "; cin >> password;

			if (password == this->password)
			{
				order.SetStatus(1);
				orders.push_back(order);
				cout << "The order was successfully placed! You can see the order status in the \"My Orders\" menu!" << endl;
			}
			else
			{
				throw runtime_error("Incorrect password!");
			}
		}
		catch (...)
		{
			cout << "The checkout process was interrupted. Try again later!" << endl;
		}
	}
};