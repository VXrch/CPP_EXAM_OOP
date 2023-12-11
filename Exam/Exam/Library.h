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

	vector<Pair> books;

	void AddNewBook(Book book, int counter);

	void DeleteBook();

	Pair MakePair(Book book, int counter)
	{
		Pair pair(book, counter);
		return pair;
	}

public:

	void AddNewBook();
	void DeleteBook(Book &book);

	int GetBooksSize() const
	{
		return books.size();
	}
	bool IsExistId(int id) const
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (id == books[i].book.GetID())
			{
				return true;
			}
		}
		throw IdDoesNotExist();
	}
	int GetBookIterator_by_ID(int id) const
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (id == books[i].book.GetID())
			{
				return i;
			}
		}
		throw exception();
	}

	vector<Book> GetBooks() const
	{
		vector<Book> vb;
		for (int i = 0; i < books.size(); i++)
		{
			vb.push_back(books[i].book);
		}
		return vb;
	}

	void PrintBook(int number) const
	{
		books[number].book.Print();
	}

	void PrintAllBooks() const
	{
		for (int i = 0; i < books.size(); i++)
		{
			cout << "Number of books: "; books[i].counter; cout << " | "; books[i].book.PrintMinInfo();
		}
	}

	int FindByID(int id) const
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetID() == id)
			{
				return i;
			}
		}
	}

	void FindBookBy_NumberOfBooks(int number) const;
	void FindBookBy_NumberOfBooks(int min_number, int max_number) const;

	vector<int> FindBookBy_NumberOfBooks(int number, bool return_value) const;
	vector<int> FindBookBy_NumberOfBooks(int min_number, int max_number, bool return_value) const;

	void FindBookBy_type(string type) const;

	void FindBookBy_title(string title) const;
	void FindBookBy_title(vector<string> titles) const;

	vector<int> FindBookBy_title(string title, bool return_value) const;
	vector<int> FindBookBy_title(vector<string> titles, bool return_value) const;

	void FindBookBy_author(string author) const;
	void FindBookBy_author(vector<string> authors) const;

	vector<int> FindBookBy_author(string author, bool return_value) const;
	vector<int> FindBookBy_author(vector<string> authors, bool return_value) const;

	void FindBookBy_ageRating(int ageRating) const;
	void FindBookBy_ageRating(vector<int> ageRatings) const;
	void FindBookBy_ageRating(int min_rating, int max_rating) const;

	vector<int> FindBookBy_ageRating(int ageRating, bool return_value) const;
	vector<int> FindBookBy_ageRating(int min_rating, int max_rating, bool return_value) const;

	void FindBookBy_year(int year) const;
	void FindBookBy_year(vector<int> year) const;
	void FindBookBy_year(int min_year, int max_year) const;

	vector<int> FindBookBy_year(int year, bool return_value) const;
	vector<int> FindBookBy_year(int min_year, int max_year, bool return_value) const;

	void FindBookBy_price(float price) const;
	void FindBookBy_price(vector<float> price) const;
	void FindBookBy_price(float min_price, float max_price) const;

	vector<int> FindBookBy_price(float price, bool return_value) const;
	vector<int> FindBookBy_price(float min_price, float max_price, bool return_value) const;

	void FindBookBy_id(unsigned int id) const;
	void FindBookBy_id(int min_id, int max_id) const;
	void FindBookBy_id(vector<unsigned int> id) const;
	vector<int> FindBookBy_id(unsigned int id, bool return_value) const;
	vector<int> FindBookBy_id(int min_id, int max_id, bool return_value) const;

	void FindBookBy_Genre(string genre) const;
	void FindBookBy_Genre(vector<string> genres) const;
	vector<int> FindBookBy_Genre(string genre, bool return_value) const;
	vector<int> FindBookBy_Genre(vector<string> genres, bool return_value) const;

	void FindBookBy_language(string language) const;
	void FindBookBy_language(vector<string> languages) const;
	vector<int> FindBookBy_language(string language, bool return_value) const;
	vector<int> FindBookBy_language(vector<string> languages, bool return_value) const;

	Book& operator[](int number)
	{
		return books[number].book;
	}

	friend class FilesWork;
};