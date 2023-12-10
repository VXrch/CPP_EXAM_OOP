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
	Status MakeSttatusFromString(string status)
	{
		if (status == "Active")
		{
			return Active;
		}
		else if (status == "Blocked")
		{
			return Blocked;
		}
		else
		{
			return None;
		}
	}

	void Print() const; // basic info
	virtual void PrintSecretInfo() const; // info to login

	bool isContinue();
	bool MakeUpPassword();
	inline void Exist()
	{
		cout << "This nickname already exists. Please enter another one!" << endl;
		system("pause"); system("cls");
	}

	// Get
	virtual string GetName() const
	{
		return name;
	}
	virtual string GetSurname() const
	{
		return surname;
	}
	virtual string GetPhone() const
	{
		return phone;
	}
	virtual string GetNickname() const
	{
		return nickname;
	}
	virtual string GetPassword() const
	{
		return password;
	}

	virtual int GetAge() const
	{
		return age;
	}
	virtual int GetID() const
	{
		return id;
	}

	virtual string GetStatus() const
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

	void SetStatus(string account_status)
	{
		Status to_make = MakeSttatusFromString(account_status);
		this->account_status = to_make;
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
