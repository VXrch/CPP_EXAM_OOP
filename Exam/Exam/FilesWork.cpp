#include "FilesWork.h"

//#define MyDebug

void FilesWork::ReadLibrary(Library& library)
{
	string filename = "Library.txt";
	ifstream inputFile(filename);

	if (inputFile.is_open())
	{
		Book book;
		string temp, counter;

		while (!inputFile.eof())
		{
			vector<string> genres;

			getline(inputFile, counter);

			if (counter.empty())
				break;

			getline(inputFile, book.title);
			getline(inputFile, book.author);
			getline(inputFile, book.discription);

			getline(inputFile, temp);
			book.ageRating = stoi(temp);

			getline(inputFile, temp);
			book.year = stoi(temp);

			getline(inputFile, temp);
			book.price = stoi(temp);

			getline(inputFile, temp);
			book.idCounter = stoi(temp);

			getline(inputFile, temp);
			book.id = stoi(temp);

			getline(inputFile, temp);
			book.MakeLanguage(temp);

			getline(inputFile, temp);
			book.sale = stoi(temp);

			getline(inputFile, temp);
			book.MakeType(temp);

			getline(inputFile, temp);
			while (temp != "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-")
			{
				genres.push_back(temp);
				getline(inputFile, temp);
			}

			book.genres = book.MakeGenres(genres);

			library.AddNewBook(book, stoi(counter));
		}

		inputFile.close();
	}
#ifdef MyDebug
	else
	{
		cout << "File does not exist!" << endl;
	}
#endif
}
void FilesWork::WriteLibrary(Library& library)
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
#ifdef MyDebug
	else
	{
		cout << "I can't open the file!" << endl;
	}
#endif
}

void FilesWork::ReadAdmins(vector<Admin>& admins)
{
	string filename = "Admin.txt";
	ifstream inputFile(filename);

	if (inputFile.is_open())
	{
		Admin admin;
		string age, temp;

		while (!inputFile.eof())
		{
			getline(inputFile, temp);

			if (temp.empty())
				break;

			admin.idCounter = stoi(temp);

			getline(inputFile, admin.name);
			getline(inputFile, admin.surname);
			getline(inputFile, admin.phone);

			getline(inputFile, age);
			admin.age = stoi(age);

			getline(inputFile, temp);
			admin.MakeStatus(temp);

			getline(inputFile, temp);
			admin.id = stoi(temp);

			getline(inputFile, admin.nickname);
			getline(inputFile, admin.password);

			admins.push_back(admin);
		}

		inputFile.close();
	}
#ifdef MyDebug
	else
	{
		cout << "File does not exist!" << endl;
	}
#endif
}
void FilesWork::WriteAdmins(vector<Admin>& admins)
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
		}
		outputFile.close();
	}
#ifdef MyDebug
	else
	{
		cout << "I can't open the file!" << endl;
	}
#endif
}

void FilesWork::ReadUsers(vector<User>& users)
{
	string filename = "Users.txt";
	ifstream inputFile(filename);

	if (inputFile.is_open())
	{
		string first, second, temp;

		while (!inputFile.eof())
		{
			User user;
			User::Order order;

			getline(inputFile, temp);

			if (temp.empty())
				break;

			user.idCounter = stoi(temp);

			getline(inputFile, user.name);
			getline(inputFile, user.surname);
			getline(inputFile, user.phone);

			getline(inputFile, temp);
			user.age = stoi(temp);

			getline(inputFile, temp);
			user.MakeStatus(temp);

			getline(inputFile, temp);
			user.id = stoi(temp);

			getline(inputFile, user.nickname);
			getline(inputFile, user.password);

			// PREFERENCES
			getline(inputFile, user.preferences.favoriteAuthor);
			getline(inputFile, user.preferences.favoriteLanguage);
			getline(inputFile, user.preferences.favoriteGenre);

			getline(inputFile, first);
			while (first != "+_+_+_+_+_+_+_+_+")
			{
				getline(inputFile, second);
				user.preferences.authors.insert(make_pair(first, stoi(second)));
			}

			getline(inputFile, first);
			while (first != "+_+_+_+_+_+_+_+_+")
			{
				getline(inputFile, second);
				user.preferences.languages.insert(make_pair(first, stoi(second)));
			}

			getline(inputFile, first);
			while (first != "+_+_+_+_+_+_+_+_+")
			{
				getline(inputFile, second);
				user.preferences.genres.insert(make_pair(first, stoi(second)));
			}

			//ORDERS
			getline(inputFile, temp);
			while (temp != "+_+_+_+_+_+_+_+_+")
			{
				order.MakeStatus(temp);

				getline(inputFile, temp);
				order.coast = stoi(temp);

				getline(inputFile, order.address);

				getline(inputFile, temp);
				order.BooksCounter = stoi(temp);


				// ORDERS -> BOOK
				vector<string> genres;

				getline(inputFile, order.book.title);
				getline(inputFile, order.book.author);
				getline(inputFile, order.book.discription);

				getline(inputFile, temp);
				order.book.ageRating = stoi(temp);

				getline(inputFile, temp);
				order.book.year = stoi(temp);

				getline(inputFile, temp);
				order.book.price = stoi(temp);

				getline(inputFile, temp);
				order.book.idCounter = stoi(temp);

				getline(inputFile, temp);
				order.book.id = stoi(temp);

				getline(inputFile, temp);
				order.book.MakeLanguage(temp);

				getline(inputFile, temp);
				order.book.sale = stoi(temp);

				getline(inputFile, temp);
				order.book.MakeType(temp);

				getline(inputFile, temp);
				while (temp != "|-|-|-|-|-|-|-|-|-|-|-|")
				{
					genres.push_back(temp);
					getline(inputFile, temp);
				}

				order.book.genres = order.book.MakeGenres(genres);
				user.orders.push_back(order);

				getline(inputFile, temp);
			}

			// WISHESLIST
			Book book;

			getline(inputFile, temp);
			while (temp != "+_+_+_+_+_+_+_+_+")
			{
				vector<string> genres;

				getline(inputFile, book.title);
				getline(inputFile, book.author);
				getline(inputFile, book.discription);

				getline(inputFile, temp);
				book.ageRating = stoi(temp);

				getline(inputFile, temp);
				book.year = stoi(temp);

				getline(inputFile, temp);
				book.price = stoi(temp);

				getline(inputFile, temp);
				book.idCounter = stoi(temp);

				getline(inputFile, temp);
				book.id = stoi(temp);

				getline(inputFile, temp);
				book.MakeLanguage(temp);

				getline(inputFile, temp);
				book.sale = stoi(temp);

				getline(inputFile, temp);
				book.MakeType(temp);

				getline(inputFile, temp);
				while (temp != "|-|-|-|-|-|-|-|-|-|-|-|")
				{
					genres.push_back(temp);
					getline(inputFile, temp);
				}

				book.genres = book.MakeGenres(genres);
				user.wishlist.push_back(book);

				getline(inputFile, temp);
			}

			// CART
			Book book2;

			getline(inputFile, temp);
			while (temp != "+_+_+_+_+_+_+_+_+")
			{
				vector<string> genres;

				getline(inputFile, book2.title);
				getline(inputFile, book2.author);
				getline(inputFile, book2.discription);

				getline(inputFile, temp);
				book2.ageRating = stoi(temp);

				getline(inputFile, temp);
				book2.year = stoi(temp);

				getline(inputFile, temp);
				book2.price = stoi(temp);

				getline(inputFile, temp);
				book2.idCounter = stoi(temp);

				getline(inputFile, temp);
				book2.id = stoi(temp);

				getline(inputFile, temp);
				book2.MakeLanguage(temp);

				getline(inputFile, temp);
				book2.sale = stoi(temp);

				getline(inputFile, temp);
				book2.MakeType(temp);

				getline(inputFile, temp);
				while (temp != "|-|-|-|-|-|-|-|-|-|-|-|")
				{
					genres.push_back(temp);
					getline(inputFile, temp);
				}

				book2.genres = book2.MakeGenres(genres);
				user.cart.push_back(book2);

				getline(inputFile, temp);
			}

			users.push_back(user);
		}

		inputFile.close();
	}
#ifdef MyDebug
	else
	{
		cout << "File does not exist!" << endl;
	}
#endif
}
void FilesWork::WriteUsers(vector<User>& users)
{
#ifdef MyDebug


#endif

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
			outputFile << users[i].preferences.favoriteGenre << endl;

			for (const auto& entry : users[i].preferences.authors)
			{
				outputFile << entry.first << endl << entry.second << endl;
			}
			outputFile << "+_+_+_+_+_+_+_+_+" << endl;
			for (const auto& entry : users[i].preferences.languages)
			{
				outputFile << entry.first << endl << entry.second << endl;
			}
			outputFile << "+_+_+_+_+_+_+_+_+" << endl;
			for (const auto& entry : users[i].preferences.genres)
			{
				outputFile << entry.first << endl << entry.second << endl;
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
				outputFile << "|-|-|-|-|-|-|-|-|-|-|-|" << endl; // End of one order!
			}
			outputFile << "+_+_+_+_+_+_+_+_+" << endl; // End of vecrot orders!

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

				for (int k = 0; k < users[i].wishlist.size(); k++)
				{
					outputFile << users[i].wishlist[j].GetGenre(users[i].wishlist[j].genres[k]) << endl;
				}
				outputFile << "|-|-|-|-|-|-|-|-|-|-|-|" << endl; // End of one book!
			}
			outputFile << "+_+_+_+_+_+_+_+_+" << endl; // End of vecrot wishlist!

			// CART
			for (int j = 0; j < users[i].cart.size(); j++)
			{
				outputFile << users[i].cart[j].title << endl;
				outputFile << users[i].cart[j].author << endl;
				outputFile << users[i].cart[j].discription << endl;
				outputFile << users[i].cart[j].ageRating << endl;
				outputFile << users[i].cart[j].year << endl;
				outputFile << users[i].cart[j].price << endl;
				outputFile << users[i].cart[j].idCounter << endl;
				outputFile << users[i].cart[j].id << endl;
				outputFile << users[i].cart[j].GetLanguage() << endl;
				outputFile << users[i].cart[j].sale << endl;
				outputFile << users[i].cart[j].GetType() << endl;

				for (int k = 0; k < users[i].cart.size(); k++)
				{
					outputFile << users[i].cart[j].GetGenre(users[i].cart[j].genres[k]) << endl;
				}
				outputFile << "|-|-|-|-|-|-|-|-|-|-|-|" << endl; // End of one book!
			}
			outputFile << "+_+_+_+_+_+_+_+_+" << endl; // End of vecrot cart!
		}

		outputFile.close();
	}
#ifdef MyDebug
	else
	{
		cout << "I can't open the file!" << endl;
	}
#endif
}
