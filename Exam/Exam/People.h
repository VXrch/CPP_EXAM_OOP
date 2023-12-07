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

		friend class FilesWork;

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

		Order() : book(), BooksCounter(0), address(""), coast(0.0), status(None) {}
		Order(Book book) : book(book), BooksCounter(0), address(""), coast(0.0), status(None) {}

		void MakeStatus(string status)
		{
			if (status == "In_Processing")
			{
				this->status = In_Processing;
			}
			else if (status == "Sent")
			{
				this->status = Sent;
			}
			else if (status == "OnTheRroad")
			{
				this->status = OnTheRroad;
			}
			else if (status == "Delivered")
			{
				this->status = Delivered;
			}
			else if (status == "Canceled")
			{
				this->status = Canceled;
			}
			else
			{
				this->status = None;
			}
		}

		string GetStatus() const;
		string GetTitle() const
		{
			return book.GetTitle();
		}
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
	vector<Book> wishlist; // add id of concrete book and add book to preferences

	User() : cart(), orders(), preferences(), wishlist(), Person() {}
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

	void PrintCart() const;
	void PrintOrders() const;
	void PrintWishlist() const;

	void AddToCart(Book Tbook);
	void PlaceOrder(Book Tbook);
	void AddToWishlist(Book Tbook);

	void RemoveFromCart();
	void RemoveFromOrders();
	void RemoveFromWishlist();

	friend class FilesWork;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Admin : public Person
{
public:

	void ChangeBookInfo(Book& book);
	void AddSaleToBook(Book& book);

	friend class FilesWork;
};
