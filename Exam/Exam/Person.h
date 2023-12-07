#pragma once
#include "Book.h"

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

	Person() : name(""), surname(""), phone(""), age(0), account_status(None), id(0), nickname(""), password("") {}
	Person(string name, string surname, int age, string phone, string nickname, string password) : name(name), surname(surname), age(age), phone(phone), account_status(Active), nickname(nickname), password(password)
	{
		idCounter++;
		id = idCounter;
	}

	void MakeStatus(string status)
	{
		if (status == "Active")
		{
			this->account_status = Active;
		}
		else if (status == "Blocked")
		{
			this->account_status = Blocked;
		}
		else
		{
			this->account_status = None;
		}
	}

	void Print() const; // basic info
	virtual void PrintSecretInfo() const; // info to login

	bool isContinue();

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

	string GetStatus() const
	{
		if (account_status == 0)
		{
			return "None";
		}
		else if (account_status == 1)
		{
			return "Active";
		}
		else
		{
			return "Blocked";
		}
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

	friend class FilesWork;
};
