#pragma once



class Admin : public Person
{
public:

	void ChangeBookInfo(Book& book)
	{
		Move move;
		move.X = 1;
		move.Y = 2;

		int key;
		bool ext = false;

		string temp_str;
		float temp_flt;
		int temp_int;

		while (ext == false)
		{
			system("cls");

			move.Gotoxy(move.X, move.Y);
			move.Gotoxy(2, 1);  cout << "Change: ";
			move.Gotoxy(2, 2);  cout << "- Title";
			move.Gotoxy(2, 3);  cout << "- Author";
			move.Gotoxy(2, 4);  cout << "- Discription";
			move.Gotoxy(2, 5);  cout << "- Age rating";
			move.Gotoxy(2, 6);  cout << "- Year";
			move.Gotoxy(2, 7);  cout << "- Price";
			move.Gotoxy(2, 8);  cout << "- Language";
			move.Gotoxy(2, 9);  cout << "- Genres";

			key = _getch();
			if (key == 13) // Enter
			{
				switch (move.Y)
				{
				case 2: // Title 
					cout << "Enter new title: "; cin >> temp_str;
					book.SetTitle(temp_str);
					break;
				case 3: // Author
					cout << "Enter new author: "; cin >> temp_str;
					book.SetAuthor(temp_str);
					break;
				case 4:  // Discription
					cout << "Enter new description: "; cin >> temp_str;
					book.SetAuthor(temp_str);
					break;
				case 5:  // Age rating
					cout << "Enter new description: "; cin >> temp_int;
					book.SetAgeRating(temp_int);
					break;
				case 6:  // Year
					cout << "Enter new description: "; cin >> temp_int;
					book.SetYear(temp_int);
					break;
				case 7:  // Price
					cout << "Enter new description: "; cin >> temp_flt;
					book.SetPrice(temp_flt);
					break;
				case 8:  // Language
					book.ChangeLanguage();
					break;
				case 9:  // Genres
					book.ChangeLanguage();
					break;
				}
			}
			else if (key == 87 || key == 119) // [D / d] [up]
			{
				if (move.Y == 1)
				{
					move.X = 1;
					move.Y = 2;
				}
			}
			else if (key == 83 || key == 115) // [S / s] [down]
			{

			}
			else if (key == 224)
			{
				key = _getch();

				if (key == 72) // up
				{

				}
				else if (key == 80) // down
				{

				}
			}
		}
	}
};

class User : public Person
{
	class Preferences
	{
		map<string, int> authors;
		map<string, int> languages;

		string favoriteAuthor;
		string favoriteLanguage;

		void FindFavoriteAuthor();
		void FindFavoriteLanguage();

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

		Order(Book book) : book(book), BooksCounter(0), address(""), coast(0.0), status(None) {}

		string GetStatus() const;
		float GetCoast() const;
		void Print() const;

		/// <summary>
		/// [0 = None][1 = In_Processing][2 = Sent][3 = OnTheRroad][4 = Delivered][5 = Canceled]
		/// </summary>
		/// <param name="number"></param>
		void SetStatus(int number);
	};

	Preferences preferences;

	vector<Book> cart;
	vector<Order> orders;
	vector<unsigned int> wishlist; // add id of concrete book and add book to preferences

	User(string name, string surname, int age, string phone, string nickname, string password) : cart(), orders(), preferences(), wishlist(), Person(name, surname, age, phone, nickname, password) {}

public:

	void Print() const;

	string GetFavoriteAuthor() const
	{
		return preferences.GetFavAuthor();
	}
	string GetFavoriteLanguage() const
	{
		return preferences.GetFavLanguage();
	}

	void PrintOrders() const;
	void PrintCart() const;

	void AddToCart(Book Tbook);
	void PlaceOrder(Book Tbook);
	void AddToWishlist(Book Tbook);
};