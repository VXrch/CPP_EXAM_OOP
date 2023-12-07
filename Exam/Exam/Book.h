#pragma once
#include "Move.h"

class Book
{
protected:

	enum Language { English, Ukrainian, Italian, Spanish, French, German };
	enum Genres { Fantasy, ScienceFiction, Dystopian, Action, Mystery, Horror, Thriller, HistoricalFiction, Romance, ContemporaryFiction, MagicalRealism, GraphicNovel, Memoir, Biography, Travel, TrueCrime, Humor };

	struct Type
	{
		string type;

		Type() : type("") {}
		Type(int number) : type("0") {}

		void SetType(int year, string language, int ageRating)
		{
			type = to_string(year), language, ageRating;
		}
	};

	string title;
	string author;
	string discription;
	int ageRating;
	int year;
	float price;

	static unsigned int idCounter;
	unsigned int id;

	Language language;
	vector<Genres> genres;

	float sale;
	Type type;

private:

	inline void Successed() const
	{
		system("cls"); cout << "Successed!" << endl; system("pause");
	}
	inline void Fail() const
	{
		system("cls"); cout << "This genre is alredy entered!" << endl; system("pause");
	}

public:

	Book() : title(""), author(""), discription(""), ageRating(0), year(0), price(0), id(0), language(English), genres(), sale(0), type(0) {}
	bool Fill();

	void Print() const;
	void PrintMinInfo() const;
	void PrintShortInfo() const;
	void PrintAllGenres() const;
	void PrintAllLanguages() const;
	void PrintAllGenres(int X, int Y) const;
	void PrintAllLanguages(int X, int Y) const;

	string GetLanguage() const;
	string GetGenre(int number) const;
	int GetGenresSize() const
	{
		return genres.size();
	}
	vector<Genres> GetAllGenres() const
	{
		return genres;
	}

	int GetYear() const
	{
		return year;
	}
	float GetSale() const
	{
		return sale;
	}
	string GetType() const
	{
		return type.type;
	}
	float GetPrice() const
	{
		return price;
	}
	string GetTitle() const
	{
		return title;
	}
	string GetAuthor() const
	{
		return author;
	}
	unsigned int GetID() const
	{
		return id;
	}
	int GetAgeRating() const
	{
		return ageRating;
	}

protected:

	Book(string title, string author, string discription, int year, int ageRating, float price, Language language, vector<Genres> genres, float* sale) : title(title), author(author), discription(discription), year(year), ageRating(ageRating), price(price), language(language), genres(), sale(0)
	{
		id = idCounter;
		idCounter++;
	}

	void SetYear(int year)
	{
		this->year = year;
	}
	void SetSale(float sale)
	{
		if (sale < 100)
		{
			this->sale = sale;
		}
		else
		{
			cout << "Sale must be < 100%" << endl;
		}
	}
	void SetPrice(float price)
	{
		this->price = price;
	}
	void SetTitle(string title)
	{
		this->title = title;
	}
	void SetGenres(Genres genre)
	{
		this->genres.push_back(genre);
	}
	void SetAuthor(string author)
	{
		this->author = author;
	}
	void SetAgeRating(int ageRating)
	{
		this->ageRating = ageRating;
	}
	void SetLanguage(Language language)
	{
		this->language = language;
	}

	bool IsUnique(Genres genre) const
	{
		for (int i = 0; i < genres.size(); i++)
		{
			if (genre == genres[i])
			{
				return false;
			}
		}
		return true;
	}

	void ChangeLanguage()
	{
		Move move(2, 2);
		bool ext = false;

		while (!ext)
		{
			move.Gotoxy(2, 1); cout << "Choose new language: ";

			PrintAllLanguages(move.X, move.Y);
			move.Gotoxy(1, move.Y); cout << ">";
			string user_move = move.CatchMove();

			if (user_move == "enter")
			{
				ext = true;
				switch (move.Y)
				{
				case 2: // English
					language = English; break;
				case 3:  // Ukrainian
					language = Ukrainian; break;
				case 4:  // Italian
					language = Italian; break;
				case 5:  // Spanish
					language = Spanish; break;
				case 6:  // French
					language = French; break;
				case 7:  // German
					language = German; break;
				}
			}
			else if (user_move == "up")
			{
				move.Y == 2 ? move.Y = 7 : move.Y++;
			}
			else if (user_move == "down")
			{
				move.Y == 7 ? move.Y = 2 : move.Y--;
			}
		}
	}

	friend class Admin;
	friend struct Order;
};
