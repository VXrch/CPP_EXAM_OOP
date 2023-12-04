#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum Status { Active, Blocked };

class Person
{
protected:

	string name;
	string surname;
	int age;
	string phone;

	// to block account
	Status account_status;

	// to search and write to file
	int id;

	// to login
	string nickname;
	string password;

	static int idCounter;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Person(string name, string surname, int age, string phone, Status account_status, string nickname, string password) : name(name), surname(surname), age(age), phone(phone), account_status(account_status), nickname(nickname), password(password)
	{
		id = idCounter++;
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

enum Language { English, Ukrainian, Italian, Spanish, French, German };

enum Genres { Fantasy, ScienceFiction, Dystopian, Action, Mystery, Horror, Thriller, HistoricalFiction, Romance, ContemporaryFiction, MagicalRealism, GraphicNovel, Memoir, Biography, Travel, TrueCrime, Humor };

class Book
{
protected:

	string title;
	string author;
	string discription;
	int year;
	float price;

	Language language;
	vector<Genres> genres;

	float* sale;

	Book(string title, string author, string discription, int year, float price, Language language, vector<Genres> genres, float* sale) : title(title), author(author), discription(discription), year(year), price(price), language(language), genres(), sale(nullptr) {}

	string GetGenreByNumber(int number) const;

	void Print() const;

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
	Language GetLanguage() const
	{
		return language;
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
	void SetSale(float *sale)
	{
		this->sale = sale;
	}
};