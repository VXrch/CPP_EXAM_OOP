#include "Library.h"
 
void Library::AddNewBook()
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
void Library::DeleteBook()
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			books[i].book.PrintMinInfo();
		}
		cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;

		string title;
		cout << "Enter title: "; getline(cin, title);

		for (int i = 0; i < books.size(); i++)
		{
			if (title == books[i].book.GetTitle())
			{
				if (books[i].counter > 1)
				{
					books[i].counter--;
				}
				else if (books[i].counter == 1)
				{
					books.erase(books.begin() + i);
					cout << "Successed!" << endl;
					break;
				}
			}
		}
	}
	catch (...)
	{
		cout << "I got an error when I deleted the book!" << endl;
	}
}

void Library::FindBookBy_NumberOfBooks(int number) const
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].counter == number)
		{
			books[i].book.PrintShortInfo();
		}
	}
}
void Library::FindBookBy_NumberOfBooks(int min_number, int max_number) const
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].counter >= min_number && books[i].counter <= max_number)
		{
			books[i].book.PrintShortInfo();
		}
	}
}

void Library::FindBookBy_type(string type) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetType() == type)
			{
				books[i].book.PrintShortInfo();
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_title(string title) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetTitle() == title)
			{
				books[i].book.PrintShortInfo();
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_title(vector<string> titles) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < titles.size(); j++)
			{
				if (books[i].book.GetTitle() == titles[j])
				{
					books[i].book.PrintShortInfo();
				}
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_author(string author) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetAuthor() == author)
			{
				books[i].book.PrintShortInfo();
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_author(vector<string> authors) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < authors.size(); j++)
			{
				if (books[i].book.GetAuthor() == authors[j])
				{
					books[i].book.PrintShortInfo();
				}
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_ageRating(int ageRating) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetAgeRating() == ageRating)
			{
				books[i].book.PrintShortInfo();
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_ageRating(vector<int> ageRatings) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < ageRatings.size(); j++)
			{
				if (books[i].book.GetAgeRating() == ageRatings[j])
				{
					books[i].book.PrintShortInfo();
				}
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_ageRating(int min_rating, int max_rating) const
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].book.GetYear() >= min_rating && books[i].book.GetYear() <= max_rating)
		{
			books[i].book.PrintShortInfo();
		}
	}
}

void Library::FindBookBy_year(int year) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetYear() == year)
			{
				books[i].book.PrintShortInfo();
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_year(vector<int> year) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < year.size(); j++)
			{
				if (books[i].book.GetYear() == year[j])
				{
					books[i].book.PrintShortInfo();
				}
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_year(int min_year, int max_year) const
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].book.GetYear() >= min_year && books[i].book.GetYear() <= max_year)
		{
			books[i].book.PrintShortInfo();
		}
	}
}

void Library::FindBookBy_price(float price) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetPrice() == price)
			{
				books[i].book.PrintShortInfo();
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_price(vector<float> price) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < price.size(); j++)
			{
				if (books[i].book.GetPrice() == price[j])
				{
					books[i].book.PrintShortInfo();
				}
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_price(float min_price, float max_price) const
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].book.GetPrice() >= min_price && books[i].book.GetPrice() <= max_price)
		{
			books[i].book.PrintShortInfo();
		}
	}
}

void Library::FindBookBy_id(unsigned int id) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetID() == id)
			{
				books[i].book.PrintShortInfo();
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_id(vector<unsigned int> id) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < id.size(); j++)
			{
				if (books[i].book.GetID() == id[j])
				{
					books[i].book.PrintShortInfo();
				}
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_Genre(string genre) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < books[i].book.GetGenresSize(); j++)
			{
				if (books[i].book.GetGenre(j) == genre)
				{
					books[i].book.PrintShortInfo();
				}
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_Genre(vector<string> genres) const
{
	try
	{
		vector<string> books_genres;

		for (int i = 0; i < books[i].book.GetGenresSize(); i++)
		{
			genres.push_back(books[i].book.GetGenre(i));
		}

		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < books_genres.size(); j++)
			{
				for (int k = 0; k < genres.size(); k++)
				{
					if (books_genres[j] == genres[k])
					{
						books[i].book.PrintShortInfo();
					}
				}
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_language(string language) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetLanguage() == language)
			{
				books[i].book.PrintShortInfo();
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_language(vector<string> languages) const
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < languages.size(); j++)
			{
				if (books[i].book.GetLanguage() == languages[i])
				{
					books[i].book.PrintShortInfo();
				}
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
