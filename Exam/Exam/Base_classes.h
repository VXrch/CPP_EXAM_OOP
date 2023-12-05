#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Person
{
protected:

	enum Status { None, Active, Blocked };

	string name;
	string surname;
	string phone;
	int age;

	// to block account
	Status account_status;

	// to search and write to file
	int id;

	// to login
	string nickname;
	string password;

	static int idCounter;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Person() : name(""), surname(""), age(0), phone(""), account_status(None), nickname(""), password("") {}
	Person(string name, string surname, int age, string phone, string nickname, string password) : name(name), surname(surname), age(age), phone(phone), account_status(Active), nickname(nickname), password(password)
	{
		idCounter++;
		id = idCounter;
	}

	virtual void Print() const; // basic info
	virtual void PrintSecretInfo() const; // info to login

	// Get
	string GetName() const
	{
		return name;
	}
	string GetSurname() const
	{
		return surname;
	}
	string GetPhone() const
	{
		return phone;
	}
	string GetNickname() const
	{
		return nickname;
	}
	string GetPassword() const
	{
		return password;
	}

	int GetAge() const
	{
		return age;
	}
	int GetID() const
	{
		return id;
	}

	Status GetStatus() const
	{
		return account_status;
	}

	// Set
	void SetName(string name)
	{
		this->name = name;
	}
	void SetSurname(string surname)
	{
		this->surname = surname;
	}
	void SetPhone(string phone)
	{
		this->phone = phone;
	}
	void SetNickname(string nickname)
	{
		this->nickname = nickname;
	}
	void SetPassword(string password)
	{
		this->password = password;
	}

	void SetStatus(Status account_status)
	{
		this->account_status = account_status;
	}
	
	void SetAge(int age)
	{
		this->age = age;
	}
	void SetID(int id)
	{
		this->id = id;
	}

	void SetIDCounter(int idcounter)
	{
		this->idCounter = idcounter;
	}
};

class Book
{
protected:

	enum Language { None, English, Ukrainian, Italian, Spanish, French, German };
	enum Genres { None, Fantasy, ScienceFiction, Dystopian, Action, Mystery, Horror, Thriller, HistoricalFiction, Romance, ContemporaryFiction, MagicalRealism, GraphicNovel, Memoir, Biography, Travel, TrueCrime, Humor };

	struct Type
	{
		string type;

		Type() : type("") {}

		void SetType(int year, string language, int ageRating)
		{
			type = to_string(year), language.at(0), ageRating;
		}
	};

	string title;
	string author;
	string discription;
	int ageRating;
	int year;
	float price;

	static int idCounter;
	int id;

	Language language;
	vector<Genres> genres;

	float* sale;
	Type type;

	Book() : title(""), author(""), discription(""), ageRating(0), year(0), price(0), id(0), language(None), genres(), type() {}
	Book(string title, string author, string discription, int year, int ageRating, float price, Language language, vector<Genres> genres, float* sale) : title(title), author(author), discription(discription), year(year), ageRating(ageRating), price(price), language(language), genres(), sale(nullptr) 
	{
		idCounter++;
		id = idCounter;
	}

	string GetGenre(int number) const;
	string GetGenre(int i) const;
	string GetLanguage() const;

	void Print() const;

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

public:

	string GetTitle() const
	{
		return title;
	}
	string GetAuthor() const
	{
		return author;
	}
	int GetYear() const
	{
		return year;
	}
	float GetPrice() const
	{
		return price;
	}
	vector<Genres> GetGenres() const
	{
		return genres;
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
	int GetID() const
	{
		return id;
	}
};

class Library
{
	struct Pair // How many the same books
	{
		Book book;
		int counter;
	};

	list<Pair> books;
};