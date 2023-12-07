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

	void AddNewBook();
	void DeleteBook();

public:

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

	void FindBookBy_NumberOfBooks(int min_number) const;
	void FindBookBy_NumberOfBooks(int min_number, int max_number) const;

	void FindBookBy_type(string type) const;

	void FindBookBy_title(string title) const;
	void FindBookBy_title(vector<string> titles) const;

	void FindBookBy_author(string author) const;
	void FindBookBy_author(vector<string> authors) const;

	void FindBookBy_ageRating(int ageRating) const;
	void FindBookBy_ageRating(vector<int> ageRatings) const;
	void FindBookBy_ageRating(int min_rating, int max_rating) const;

	void FindBookBy_year(int year) const;
	void FindBookBy_year(vector<int> year) const;
	void FindBookBy_year(int min_year, int max_year) const;

	void FindBookBy_price(float price) const;
	void FindBookBy_price(vector<float> price) const;
	void FindBookBy_price(float min_price, float max_price) const;

	void FindBookBy_id(unsigned int id) const;
	void FindBookBy_id(vector<unsigned int> id) const;

	void FindBookBy_Genre(string genre) const;
	void FindBookBy_Genre(vector<string> genres) const;

	void FindBookBy_language(string language) const;
	void FindBookBy_language(vector<string> languages) const;

	friend class FilesWork;
};