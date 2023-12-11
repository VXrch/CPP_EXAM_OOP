#pragma once
#include "Person.h"

class User : public Person
{
	class Preferences
	{
		map<string, int> authors;
		map<string, int> languages;
		map<string, int> genres;

		string favoriteAuthor;
		string favoriteLanguage;
		string favoriteGenre;

		void FindFavoriteAuthor();
		void FindFavoriteLanguage();
		void FindFavoriteGenre();

		friend class FilesWork;

	public:

		Preferences() : authors(), languages() {}

		string GetFavAuthor() const
		{
			return favoriteAuthor;
		}
		string GetFavLanguage() const
		{
			return favoriteLanguage;
		}
		string GetFavGenre() const
		{
			return favoriteGenre;
		}

		bool isEmpty() const;
		void Print() const;

		void NewBook(Book book);
	};
	struct Order
	{
		enum Status { None, In_Processing, Sent, OnTheRroad, Delivered, Canceled };

		Book book;
		int BooksCounter;

		string address;
		float coast;

		Status status;

		Order() : book(), BooksCounter(0), address(""), coast(0.0), status(None) {}
		Order(Book book) : book(book), BooksCounter(0), address(""), coast(0.0), status(None) {}

		void MakeStatus(string status)
		{
			if (status == "In_Processing")
			{
				this->status = In_Processing;
			}
			else if (status == "Sent")
			{
				this->status = Sent;
			}
			else if (status == "OnTheRroad")
			{
				this->status = OnTheRroad;
			}
			else if (status == "Delivered")
			{
				this->status = Delivered;
			}
			else if (status == "Canceled")
			{
				this->status = Canceled;
			}
			else
			{
				this->status = None;
			}
		}

		string GetStatus() const;
		string GetTitle() const
		{
			return book.GetTitle();
		}
		float GetCoast() const;
		void Print() const;

		/// <summary>
		/// [0 = None][1 = In_Processing][2 = Sent][3 = OnTheRroad][4 = Delivered][5 = Canceled]
		/// </summary>
		/// <param name="number"></param>
		void SetStatus(int number);
	};

	Preferences preferences;
	float discount;

	vector<Book> cart;
	vector<Order> orders;
	vector<Book> wishlist; // add id of concrete book and add book to preferences

public:

	User() : cart(), orders(), preferences(), discount(0), wishlist(), Person() {}
	User(string name, string surname, int age, string phone, string nickname, string password) : cart(), orders(), preferences(), discount(), wishlist(), Person(name, surname, age, phone, nickname, password) {}

	void Print() const;
	bool isEmpty() const
	{
		if (account_status == None && nickname == "" && password == "")
		{
			return true;
		}
		return false;
	}

	// GET
	string GetFavoriteAuthor() const
	{
		return preferences.GetFavAuthor();
	}
	string GetFavoriteLanguage() const
	{
		return preferences.GetFavLanguage();
	}
	string GetFavoriteGenre() const
	{
		return preferences.GetFavGenre();
	}

	string GetStatus() const override
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

	string GetPassword() const override
	{
		return Person::GetPassword();
	}
	string GetNickname() const override
	{
		return Person::GetNickname();
	}
	string GetSurname() const override
	{
		return Person::GetSurname();
	}
	string GetPhone() const override
	{
		return Person::GetPhone();
	}
	string GetName() const override
	{
		return Person::GetName();
	}
	int GetAge() const override
	{
		return Person::GetAge();
	}
	int GetID() const override
	{
		return Person::GetID();
	}

	int GetWisheslistSize() const
	{
		return wishlist.size();
	}
	int GetOrdersSize() const 
	{
		return orders.size();
	}
	int GetCartSize() const
	{
		return cart.size();
	}

	void GetRecomendations(vector<Book> books)
	{
		if (books.empty())
		{
			cout << "The catalog is empty." << endl;
			return;
		}

		bool find = false;

		vector<Book> print_books;
		Move m;

		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].GetAuthor() == this->GetFavoriteAuthor() || books[i].GetLanguage() == this->GetFavoriteLanguage())
			{
				if (books[i].IsUnique(print_books, books[i]))
					print_books.push_back(books[i]);
			}

			vector<string> genres = books[i].GetAllGenres_string();
			for (int i = 0; i < genres.size(); i++)
			{
				if (genres[i] == this->GetFavoriteAuthor())
				{
					if (books[i].IsUnique(print_books, books[i]))
						print_books.push_back(books[i]);
				}
			}
		}

		if (find == false)
		{
			for (int i = 0; i < books.size(); i++)
			{
				books[i].PrintMinInfo();
			}
		}
		else
		{
			for (int i = 0; i < print_books.size(); i++)
			{
				print_books[i].PrintShortInfo();
			}
		}
	}

	// OTHER
	bool MakeNickname(const vector<User> all_users, const vector<Admin> all_admins);
	void SetDiscount(float discount)
	{
		if (discount >= 0)
		{
			this->discount = discount;
		}
		else
		{
			cout << "Incorrect discount!" << endl;
		}
	}

	bool Register(const vector<User> all_users, const vector<Admin> all_admins);
	User LogIn(vector<User>& users, string nickname, string password);

	// PRINT
	void PrintCart() const;
	void PrintOrders() const;
	void PrintWishlist() const;
	void PrintShortInfo() const
	{
		cout << "Name: " << name << " | Surname: " << surname << " | Age: " << age << " | Wishes: " << GetWisheslistSize() << " | Orders: " << GetOrdersSize() << endl;
	}

	// VECTORS
	void AddToCart(Book Tbook);
	void PlaceOrder(Book Tbook);
	void AddToWishlist(Book Tbook);

	void RemoveFromCart();
	void RemoveFromOrders();
	void RemoveFromWishlist();

	friend class FilesWork;
	friend class Admin;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Admin : public Person
{
public:

	void ChangeBookInfo(Book& book);
	void ChangeUserInfo(User& user)
	{
		int i = 0, min = 1;

		string temp;
		int int_temp;

		vector<int> result;

		Move move;
		move(0, min);

		bool ext = false, found = false;
		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(3, i); cout << "-*-*-*-*-*-*-*| Change user info |**-*-*-*-*-*-";
			i++;
			move.Gotoxy(3, i); cout << "Name";
			i++;
			move.Gotoxy(3, i); cout << "Surname";
			i++;
			move.Gotoxy(3, i); cout << "Phone number";
			i++;
			move.Gotoxy(3, i); cout << "Nickname";
			i++;
			move.Gotoxy(3, i); cout << "Age";
			i++;
			move.Gotoxy(3, i); cout << "Account status";
			i++;
			move.Gotoxy(3, i); cout << "Exit";
			i++;
			move.Gotoxy(); cout << "->";

			string go_to = move.CatchMove();
			system("cls");

			if (go_to == "enter")
			{
				try
				{
					if (move.Y == 1)
					{
						cout << "Enter new name: "; getline(cin, temp);
						user.SetName(temp);
					}
					else if (move.Y == 2)
					{
						cout << "Enter new surname: "; getline(cin, temp);
						user.SetSurname(temp);
					}
					else if (move.Y == 3)
					{
						cout << "Enter new phone number: "; getline(cin, temp);
						user.SetPhone(temp);
					}
					else if (move.Y == 4)
					{
						cout << "Enter new nickname: "; getline(cin, temp);
						user.SetNickname(temp);
					}
					else if (move.Y == 5)
					{
						cout << "Enter new age: "; move.SecureEnter(int_temp);
						user.SetAge(int_temp);
					}
					else if (move.Y == 6)
					{
						cout << "Enter new status: "; getline(cin, temp);
						user.SetStatus(temp);
					}
					else
					{
						ext = true;
					}
				}
				catch (const IncorrectValue& except)
				{
					cout << except << "Try again next time." << endl;
				}
				catch (...)
				{
					cout << "There was an unexpected error! Maybe you should try again later." << endl;
				}
				system("pause"); system("cls");
			}
			else if (go_to == "down")
			{
				move.Y == i ? move.Y = min : move.Y++;
			}
			else if (go_to == "up")
			{
				move.Y == min ? move.Y = i : move.Y--;
			}
		}
	}
	void AddSaleToBook(Book& book);

	bool MakeNickname(const vector<User> all_users, vector<Admin> all_admins);
	bool isValidPassword() const
	{
		Move move;

		string password = move.PasswordAnimation();
		
		if (password == this->password)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void ChangeUserStatus(User& user)
	{
		bool ext = false;
		int i = 0, min = 1;

		Move move;
		move(0, 0);

		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(2, i); cout << "-*-*-*-*-*-*-*-*-+| Choose status to set |+-*-*-*-*-*-*-*-*-";
			i++;
			move.Gotoxy(2, i); cout << "Active";
			i++;
			move.Gotoxy(2, i); cout << "Blocked";
			i++;
			move.Gotoxy(2, i); cout << "Come back";
			i++;
			move.Gotoxy(); cout << "->";

			string go_to = move.CatchMove();
			system("cls");

			if (go_to == "enter")
			{
				try
				{
					if (move.Y == 1)
					{
						user.account_status = Active;
					}
					else if (move.Y == 2)
					{
						user.account_status = Blocked;
					}
					else // Come back
					{
						ext = true;
					}
				}
				catch (const IncorrectValue& except)
				{
					cout << except << endl;
				}
				catch (...)
				{
					cout << "An unexpected error!" << endl;
				}
				system("pause"); system("cls");
			}
			else if (go_to == "down")
			{
				move.Y == i ? move.Y = min : move.Y++;
			}
			else if (go_to == "up")
			{
				move.Y == min ? move.Y = i : move.Y--;
			}
		}
	}

	string GetNickname() const override
	{
		return nickname;
	}
	int GetID() const override
	{
		return id;
	}

	bool isEmpty() const
	{
		if (account_status == None && nickname == "" && password == "")
		{
			return true;
		}
		return false;
	}

	bool Register(vector<User> all_users, vector<Admin> all_admins);
	Admin LogIn(vector<Admin> admins, string nickname, string password);
};
