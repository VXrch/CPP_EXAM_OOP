#pragma once


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

	float* sale;
	Type type;

	Book() : title(""), author(""), discription(""), ageRating(0), year(0), price(0), id(0), language(English), genres(), sale(nullptr), type(0) {}
	Book(string title, string author, string discription, int year, int ageRating, float price, Language language, vector<Genres> genres, float* sale) : title(title), author(author), discription(discription), year(year), ageRating(ageRating), price(price), language(language), genres(), sale(nullptr)
	{
		idCounter++;
		id = idCounter;
	}

	void SetTitle(string title)
	{
		this->title = title;
	}
	void SetAuthor(string author)
	{
		this->author = author;
	}
	void SetYear(int year)
	{
		this->year = year;
	}
	void SetPrice(float price)
	{
		this->price = price;
	}
	void SetLanguage(Language language)
	{
		this->language = language;
	}
	void SetGenres(Genres genre)
	{
		this->genres.push_back(genre);
	}
	void SetSale(float* sale)
	{
		this->sale = sale;
	}
	void SetAgeRating(int ageRating)
	{
		this->ageRating = ageRating;
	}

	void ChangeLanguage()
	{
		system("cls");
		PrintAllLanguages(1, 1);

	}

	friend class Admin;
	friend struct Order;

public:

	void Print() const;
	void PrintShortInfo() const;
	void PrintAllGenres() const;
	void PrintAllLanguages() const;
	void PrintAllGenres(int X, int Y) const;
	void PrintAllLanguages(int X, int Y) const;

	string GetLanguage() const;
	string GetGenre(int number) const;

	int GetYear() const
	{
		return year;
	}
	float GetSale() const
	{
		if (sale == nullptr)
		{
			return 0;
		}
		return *sale;
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
	vector<Genres> GetAllGenres() const
	{
		return genres;
	}
};
