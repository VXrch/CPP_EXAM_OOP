#include "Library.h"
 
void Library::AddNewBook()
{
	try
	{
		Move m;
		Book book; 
		book.Fill();

		bool ext = false;
		int count = 0;

		while (!ext)
		{
			system("cls");
			cout << "Number of copies of the book (number): ";

			if (!(cin >> count))
			{
				cin.clear(); // Clear errors
				cin.ignore(10000, '\n'); // Crear buffer
				cout << "Number of copies must be a number! Incorrect argument!" << endl;
			}
			else
			{
				ext = true;
			}
		}
				
		Pair pair(book, count);
		books.push_back(pair);
	}
	catch (...)
	{
		cout << "An error occurred! Failed to create a book!" << endl;
	}
}
void Library::AddNewBook(Book book, int counter)
{
	try
	{
		Pair pair(book, counter);
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
void Library::DeleteBook(Book& book)
{
	try
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (&book == &books[i].book)
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
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].counter == number)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
			if (found == false)
			{
				cout << "There are no books that would satisfy the request" << endl;
			}
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_NumberOfBooks(int min_number, int max_number) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].counter >= min_number && books[i].counter <= max_number)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
			if (found == false)
			{
				cout << "There are no books that would satisfy the request" << endl;
			}
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_NumberOfBooks(int number, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].counter == number)
			{
				books[i].book.PrintShortInfo();
				id.push_back(i);
				found = true;
			}
			if (found == false)
			{
				cout << "There are no books that would satisfy the request" << endl;
			}
			return id;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_NumberOfBooks(int min_number, int max_number, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].counter >= min_number && books[i].counter <= max_number)
			{
				books[i].book.PrintShortInfo();
				id.push_back(i);
				found = true;
			}
			if (found == false)
			{
				cout << "There are no books that would satisfy the request" << endl;
			}
			return id;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_title(string title) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetTitle() == title)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_title(vector<string> titles) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < titles.size(); j++)
			{
				if (books[i].book.GetTitle() == titles[j])
				{
					books[i].book.PrintShortInfo();
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_title(string title, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetTitle() == title)
			{
				books[i].book.PrintShortInfo();
				id.push_back(i);
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_title(vector<string> titles, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < titles.size(); j++)
			{
				if (books[i].book.GetTitle() == titles[j])
				{
					books[i].book.PrintShortInfo();
					id.push_back(i);
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_author(string author) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetAuthor() == author)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_author(vector<string> authors) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < authors.size(); j++)
			{
				if (books[i].book.GetAuthor() == authors[j])
				{
					books[i].book.PrintShortInfo();
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_author(string author, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetAuthor() == author)
			{
				books[i].book.PrintShortInfo();
				id.push_back(i);
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_author(vector<string> authors, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < authors.size(); j++)
			{
				if (books[i].book.GetAuthor() == authors[j])
				{
					books[i].book.PrintShortInfo();
					id.push_back(i);
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_ageRating(int ageRating) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetAgeRating() == ageRating)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_ageRating(vector<int> ageRatings) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < ageRatings.size(); j++)
			{
				if (books[i].book.GetAgeRating() == ageRatings[j])
				{
					books[i].book.PrintShortInfo();
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_ageRating(int min_rating, int max_rating) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetYear() >= min_rating && books[i].book.GetYear() <= max_rating)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_ageRating(int ageRating, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetAgeRating() == ageRating)
			{
				books[i].book.PrintShortInfo();
				id.push_back(i);
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_ageRating(int min_rating, int max_rating, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetYear() >= min_rating && books[i].book.GetYear() <= max_rating)
			{
				books[i].book.PrintShortInfo();
				id.push_back(i);
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_year(int year) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetYear() == year)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_year(vector<int> year) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < year.size(); j++)
			{
				if (books[i].book.GetYear() == year[j])
				{
					books[i].book.PrintShortInfo();
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_year(int min_year, int max_year) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetYear() >= min_year && books[i].book.GetYear() <= max_year)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;

	}
}
vector<int> Library::FindBookBy_year(int year, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetYear() == year)
			{
				books[i].book.PrintShortInfo();
				id.push_back(i);
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_year(int min_year, int max_year, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetYear() >= min_year && books[i].book.GetYear() <= max_year)
			{
				books[i].book.PrintShortInfo();
				id.push_back(i);
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;

	}
}

void Library::FindBookBy_price(float price) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetPrice() == price)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_price(vector<float> price) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < price.size(); j++)
			{
				if (books[i].book.GetPrice() == price[j])
				{
					books[i].book.PrintShortInfo();
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_price(float min_price, float max_price) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetPrice() >= min_price && books[i].book.GetPrice() <= max_price)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_price(float price, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetPrice() == price)
			{
				books[i].book.PrintShortInfo();
				id.push_back(i);
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_price(float min_price, float max_price, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetPrice() >= min_price && books[i].book.GetPrice() <= max_price)
			{
				books[i].book.PrintShortInfo();
				id.push_back(i);
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_id(unsigned int id) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetID() == id)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (const exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_id(vector<unsigned int> id) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < id.size(); j++)
			{
				if (books[i].book.GetID() == id[j])
				{
					books[i].book.PrintShortInfo();
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_id(int min_id, int max_id) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (min_id <= books[i].book.GetID() && books[i].book.GetID() <= max_id)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_id(unsigned int id, bool return_value) const
{
	try
	{
		vector<int> vector_id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetID() == id)
			{
				books[i].book.PrintShortInfo();
				vector_id.push_back(i);
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
			throw IdDoesNotExist();
		}
		return vector_id;
	}
	catch (const exception&)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_id(int min_id, int max_id, bool return_value) const
{
	try
	{
		vector<int> vector_id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (min_id <= books[i].book.GetID() && books[i].book.GetID() <= max_id)
			{
				books[i].book.PrintShortInfo();
				vector_id.push_back(i);
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return vector_id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_Genre(string genre) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < books[i].book.GetGenresSize(); j++)
			{
				if (books[i].book.GetGenre(j) == genre)
				{
					books[i].book.PrintShortInfo();
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_Genre(vector<string> genres) const
{
	try
	{
		bool found = false;
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
						found = true;
					}
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_Genre(string genre, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < books[i].book.GetGenresSize(); j++)
			{
				if (books[i].book.GetGenre(j) == genre)
				{
					books[i].book.PrintShortInfo();
					id.push_back(i);
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_Genre(vector<string> genres, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
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
						id.push_back(i);
						found = true;
					}
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}

void Library::FindBookBy_language(string language) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetLanguage() == language)
			{
				books[i].book.PrintShortInfo();
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
void Library::FindBookBy_language(vector<string> languages) const
{
	try
	{
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < languages.size(); j++)
			{
				if (books[i].book.GetLanguage() == languages[i])
				{
					books[i].book.PrintShortInfo();
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_language(string language, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].book.GetLanguage() == language)
			{
				books[i].book.PrintShortInfo();
				id.push_back(i);
				found = true;
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
vector<int> Library::FindBookBy_language(vector<string> languages, bool return_value) const
{
	try
	{
		vector<int> id;
		bool found = false;
		for (int i = 0; i < books.size(); i++)
		{
			for (int j = 0; j < languages.size(); j++)
			{
				if (books[i].book.GetLanguage() == languages[i])
				{
					books[i].book.PrintShortInfo();
					id.push_back(i);
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "There are no books that would satisfy the request" << endl;
		}
		return id;
	}
	catch (...)
	{
		cout << "An unspecified error has occurred" << endl;
	}
}
