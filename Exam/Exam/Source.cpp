#pragma once
#include "Library.h"
#include <fstream>

using namespace std;

int Person::idCounter = 0;
unsigned int Book::idCounter = 0;

class FilesWork
{
	void ReadLibrary(Library& library)
	{
		string filename = "Library.txt";
		ifstream inputFile(filename);

		if (inputFile.is_open())
		{
			Book book;
			vector<string> genres;
			
			string temp, genre, counter, title, author, discription, ageRating, year, price, idCounter, id, language, sale, type;
			
			int i = 0, j = 0;

			while (!inputFile.eof())
			{

				getline(inputFile, counter);

				if (counter.empty())
					break;

				counter = stoi(counter);

				getline(inputFile, title); 
				book.title = title;
				
				getline(inputFile, author); 
				book.author = author;
				
				getline(inputFile, discription); 
				book.discription = discription;
				
				
				getline(inputFile, ageRating); 
				book.ageRating = stoi(ageRating);
				
				getline(inputFile, year); 
				book.year = stoi(year);
				
				getline(inputFile, price); 
				book.price = stoi(price);
				
				getline(inputFile, idCounter); 
				book.idCounter = stoi(idCounter);
				
				getline(inputFile, id); 
				book.idCounter = stoi(idCounter);
				
				getline(inputFile, language); 
				book.language = book.MakeLanguage(language);
				
				getline(inputFile, sale); 
				book.idCounter = stoi(idCounter);
				
				getline(inputFile, type); 
				book.idCounter = stoi(idCounter);

				getline(inputFile, genre);
				while (temp != "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-")
				{
					genres.push_back(genre);
					getline(inputFile, genre);
				}

				book.genres = book.MakeGenres(genres);

				/*
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
				*/
			}

			inputFile.close();
		}
		else 
		{
			cout << "I can't open the file!" << endl;
		}
	}
	void WriteLibrary(Library& library)
	{
		string filename = "Library.txt";
		ofstream outputFile(filename);

		if (outputFile.is_open()) 
		{
			for (int i = 0; i < library.books.size(); i++)
			{
				outputFile << library.books[i].counter << endl;
				outputFile << library.books[i].book.title << endl;
				outputFile << library.books[i].book.author << endl;
				outputFile << library.books[i].book.discription << endl;
				outputFile << library.books[i].book.ageRating << endl;
				outputFile << library.books[i].book.year << endl;
				outputFile << library.books[i].book.price << endl;
				outputFile << library.books[i].book.idCounter << endl;
				outputFile << library.books[i].book.id << endl;
				outputFile << library.books[i].book.GetLanguage() << endl;
				outputFile << library.books[i].book.sale << endl;
				outputFile << library.books[i].book.GetType() << endl;
				
				for (int j = 0; j < library.books[i].book.genres.size(); j++)
				{
					outputFile << library.books[i].book.GetGenre(library.books[i].book.genres[j]) << endl;
				}
				outputFile << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
			}

			outputFile.close();
		}
		else 
		{
			cout << "I can't open the file!" << endl;
		}
	}

	void ReadAdmins(vector<Admin>& admins)
	{
		string filename = "Admin.txt";
		ofstream outputFile(filename);

		if (outputFile.is_open())
		{
			for (int i = 0; i < admins.size(); i++)
			{
				outputFile << admins[i].idCounter << endl;
				outputFile << admins[i].name << endl;
				outputFile << admins[i].surname << endl;
				outputFile << admins[i].phone << endl;
				outputFile << admins[i].age << endl;
				outputFile << admins[i].GetStatus() << endl;
				outputFile << admins[i].id << endl;
				outputFile << admins[i].nickname << endl;
				outputFile << admins[i].password << endl;
				cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
			}
			outputFile.close();
		}
		else
		{
			cout << "I can't open the file!" << endl;
		}
	}
	void WriteAdmins(vector<Admin>& admins)
	{
		string filename = "Admin.txt";
		ofstream outputFile(filename);

		if (outputFile.is_open())
		{
			for (int i = 0; i < admins.size(); i++)
			{
				outputFile << admins[i].idCounter << endl;
				outputFile << admins[i].name << endl;
				outputFile << admins[i].surname << endl;
				outputFile << admins[i].phone << endl;
				outputFile << admins[i].age << endl;
				outputFile << admins[i].GetStatus() << endl;
				outputFile << admins[i].id << endl;
				outputFile << admins[i].nickname << endl;
				outputFile << admins[i].password << endl;
				cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
			}
			outputFile.close();
		}
		else
		{
			cout << "I can't open the file!" << endl;
		}
	}
	
	void ReadUsers(vector<User>& users)
	{
		string filename = "Users.txt";
		ofstream outputFile(filename);

		if (outputFile.is_open())
		{
			for (int i = 0; i < users.size(); i++)
			{
				outputFile << users[i].idCounter << endl;
				outputFile << users[i].name << endl;
				outputFile << users[i].surname << endl;
				outputFile << users[i].phone << endl;
				outputFile << users[i].age << endl;
				outputFile << users[i].GetStatus() << endl;
				outputFile << users[i].id << endl;
				outputFile << users[i].nickname << endl;
				outputFile << users[i].password << endl;

				// PREFERENCES
				outputFile << users[i].preferences.favoriteAuthor << endl;
				outputFile << users[i].preferences.favoriteLanguage << endl;

				for (const auto& entry : users[i].preferences.authors) 
				{
					outputFile << entry.first << "|||||" << entry.second << std::endl;
				}
				outputFile << "+_+_+_+_+_+_+_+_+" << endl;
				for (const auto& entry : users[i].preferences.languages) 
				{
					outputFile << entry.first << "|||||" << entry.second << std::endl;
				}
				outputFile << "+_+_+_+_+_+_+_+_+" << endl;

				//ORDERS
				for (int j = 0; j < users[i].orders.size(); j++)
				{
					outputFile << users[i].orders[j].GetStatus() << endl;
					outputFile << users[i].orders[j].coast << endl;
					outputFile << users[i].orders[j].address << endl;
					outputFile << users[i].orders[j].BooksCounter << endl;

					outputFile << users[i].orders[j].book.title << endl;
					outputFile << users[i].orders[j].book.author << endl;
					outputFile << users[i].orders[j].book.discription << endl;
					outputFile << users[i].orders[j].book.ageRating << endl;
					outputFile << users[i].orders[j].book.year << endl;
					outputFile << users[i].orders[j].book.price << endl;
					outputFile << users[i].orders[j].book.idCounter << endl;
					outputFile << users[i].orders[j].book.id << endl;
					outputFile << users[i].orders[j].book.GetLanguage() << endl;
					outputFile << users[i].orders[j].book.sale << endl;
					outputFile << users[i].orders[j].book.GetType() << endl;

					for (int k = 0; k < users[i].orders.size(); k++)
					{
						outputFile << users[i].orders[j].book.GetGenre(users[i].orders[j].book.genres[k]) << endl;
					}
					outputFile << "|-|-|-|-|-|-|-|-|-|-|-|" << endl;
				}

				// WISHESLIST

				for (int j = 0; j < users[i].wishlist.size(); j++)
				{
					outputFile << users[i].wishlist[j].title << endl;
					outputFile << users[i].wishlist[j].author << endl;
					outputFile << users[i].wishlist[j].discription << endl;
					outputFile << users[i].wishlist[j].ageRating << endl;
					outputFile << users[i].wishlist[j].year << endl;
					outputFile << users[i].wishlist[j].price << endl;
					outputFile << users[i].wishlist[j].idCounter << endl;
					outputFile << users[i].wishlist[j].id << endl;
					outputFile << users[i].wishlist[j].GetLanguage() << endl;
					outputFile << users[i].wishlist[j].sale << endl;
					outputFile << users[i].wishlist[j].GetType() << endl;

					for (int k = 0; k < users[i].orders.size(); k++)
					{
						outputFile << users[i].wishlist[j].GetGenre(users[i].wishlist[j].genres[k]) << endl;
					}
				}

				cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
			}
			outputFile.close();
		}
		else
		{
			cout << "I can't open the file!" << endl;
		}
	}
	void WriteUsers(vector<User>& users)
	{
		string filename = "Users.txt";
		ofstream outputFile(filename);

		if (outputFile.is_open())
		{
			for (int i = 0; i < users.size(); i++)
			{
				outputFile << users[i].idCounter << endl;
				outputFile << users[i].name << endl;
				outputFile << users[i].surname << endl;
				outputFile << users[i].phone << endl;
				outputFile << users[i].age << endl;
				outputFile << users[i].GetStatus() << endl;
				outputFile << users[i].id << endl;
				outputFile << users[i].nickname << endl;
				outputFile << users[i].password << endl;

				// PREFERENCES
				outputFile << users[i].preferences.favoriteAuthor << endl;
				outputFile << users[i].preferences.favoriteLanguage << endl;

				for (const auto& entry : users[i].preferences.authors) 
				{
					outputFile << entry.first << "|||||" << entry.second << std::endl;
				}
				outputFile << "+_+_+_+_+_+_+_+_+" << endl;
				for (const auto& entry : users[i].preferences.languages) 
				{
					outputFile << entry.first << "|||||" << entry.second << std::endl;
				}
				outputFile << "+_+_+_+_+_+_+_+_+" << endl;

				//ORDERS
				for (int j = 0; j < users[i].orders.size(); j++)
				{
					outputFile << users[i].orders[j].GetStatus() << endl;
					outputFile << users[i].orders[j].coast << endl;
					outputFile << users[i].orders[j].address << endl;
					outputFile << users[i].orders[j].BooksCounter << endl;

					outputFile << users[i].orders[j].book.title << endl;
					outputFile << users[i].orders[j].book.author << endl;
					outputFile << users[i].orders[j].book.discription << endl;
					outputFile << users[i].orders[j].book.ageRating << endl;
					outputFile << users[i].orders[j].book.year << endl;
					outputFile << users[i].orders[j].book.price << endl;
					outputFile << users[i].orders[j].book.idCounter << endl;
					outputFile << users[i].orders[j].book.id << endl;
					outputFile << users[i].orders[j].book.GetLanguage() << endl;
					outputFile << users[i].orders[j].book.sale << endl;
					outputFile << users[i].orders[j].book.GetType() << endl;

					for (int k = 0; k < users[i].orders.size(); k++)
					{
						outputFile << users[i].orders[j].book.GetGenre(users[i].orders[j].book.genres[k]) << endl;
					}
					outputFile << "|-|-|-|-|-|-|-|-|-|-|-|" << endl;
				}

				// WISHESLIST

				for (int j = 0; j < users[i].wishlist.size(); j++)
				{
					outputFile << users[i].wishlist[j].title << endl;
					outputFile << users[i].wishlist[j].author << endl;
					outputFile << users[i].wishlist[j].discription << endl;
					outputFile << users[i].wishlist[j].ageRating << endl;
					outputFile << users[i].wishlist[j].year << endl;
					outputFile << users[i].wishlist[j].price << endl;
					outputFile << users[i].wishlist[j].idCounter << endl;
					outputFile << users[i].wishlist[j].id << endl;
					outputFile << users[i].wishlist[j].GetLanguage() << endl;
					outputFile << users[i].wishlist[j].sale << endl;
					outputFile << users[i].wishlist[j].GetType() << endl;

					for (int k = 0; k < users[i].orders.size(); k++)
					{
						outputFile << users[i].wishlist[j].GetGenre(users[i].wishlist[j].genres[k]) << endl;
					}
				}

				cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
			}
			outputFile.close();
		}
		else
		{
			cout << "I can't open the file!" << endl;
		}
	}

public:

	void WriteToFile(Library& library, vector<Admin>& admins, vector<User>& users)
	{
		WriteLibrary(library);
		WriteAdmins(admins);
		WriteUsers(users);
	}
	void ReadFromFile(Library& library, vector<Admin>& admins, vector<User>& users)
	{
		ReadLibrary(library);
		ReadAdmins(admins);
		ReadUsers(users);
	}
};

void menu(Library& library, vector<Admin>& admins, vector<User>& users);

void main()
{
	Library library;
	vector<Admin> admins;
	vector<User> users;





}

void menu(Library& library, vector<Admin>& admins, vector<User>& users)
{




}
