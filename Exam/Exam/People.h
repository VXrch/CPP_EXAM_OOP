#pragma once
#include "Person.h"

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

		bool isEmpty() const;
		void Print() const;

		void NewBook(Book book);
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

		string GetStatus() const;
		float GetCoast() const;
		void Print() const;

		/// <summary>
		/// [0 = None][1 = In_Processing][2 = Sent][3 = OnTheRroad][4 = Delivered][5 = Canceled]
		/// </summary>
		/// <param name="number"></param>
		void SetStatus(int number);
	};

	Preferences preferences;

	vector<Book> cart;
	vector<Order> orders;
	vector<unsigned int> wishlist; // add id of concrete book and add book to preferences

	User(string name, string surname, int age, string phone, string nickname, string password) : cart(), orders(), preferences(), wishlist(), Person(name, surname, age, phone, nickname, password) {}

public:

	void Print() const;

	string GetFavoriteAuthor() const
	{
		return preferences.GetFavAuthor();
	}
	string GetFavoriteLanguage() const
	{
		return preferences.GetFavLanguage();
	}

	void PrintOrders() const;
	void PrintCart() const;

	void AddToCart(Book Tbook);
	void PlaceOrder(Book Tbook);
	void AddToWishlist(Book Tbook);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Admin : public Person
{
public:

	void ChangeBookInfo(Book& book);
};