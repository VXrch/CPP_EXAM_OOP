#include "People.h"

bool User::MakeNickname(const vector<User> all_users)
{
	bool ext = false, go = true;
	while (!ext)
	{
		cout << "To exit press [0]" << endl;
		cout << "Make up a nickname:  "; cin >> nickname;

		if (nickname == "0")
		{
			system("cls");
			return false;
		}
		else
		{
			for (int i = 0; i < all_users.size(); i++)
			{
				if (nickname == all_users[i].GetNickname())
				{
					cout << "This nickname already exists. Please enter another one!" << endl;
					system("pause"); system("cls");
					go = false;
					break;
				}
			}
			if (go == true)
			{
				system("cls");
				return true;
			}
			go = true;
		}
	}
}

bool User::Register(const vector<User> all_users)
{
	try
	{
		system("cls");
		bool ext = false;

		cout << "Fill out the form with information about yourself: " << endl;
		cout << "Your name: "; getline(cin, name);
		cout << "Your surname: "; getline(cin, surname);
		cout << "Phone number: "; getline(cin, phone);

		while (!ext)
		{
			system("cls");
			cout << "your age (number): ";
			if (!(cin >> age))
			{
				cin.clear(); // Clear errors
				cin.ignore(10000, '\n'); // Crear buffer

				cout << "Age must be a number! Incorrect argument!" << endl;
				system("pause");
			}
			else
			{
				ext = true;
			}
		}
		ext = false;

		system("cls"); cout << "Ok!" << endl; system("pause"); system("cls");

		while (!ext)
		{
			bool go = MakeNickname(all_users);

			if (go == false)
			{
				if (isContinue() == true)
				{
					system("cls");
				}
				else
				{
					return false;
				}
			}
			else
			{
				ext = true;
			}
		}
		ext = false;

		while (!ext)
		{
			bool go = false;
			go = MakeUpPassword();

			if (go == false)
			{
				if (!isContinue())
				{
					system("cls");
					return false;
				}
			}
			else
			{
				ext = true;
			}
		}

		account_status = Active;

		idCounter++;
		id = idCounter;

		return true;
	}
	catch (const exception& exception)
	{
		cout << exception.what() << endl;
		return false;
	}
}
User User::LogIn(vector<User> users, string nickname, string password)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].nickname == nickname)
		{
			if (users[i].password == password)
			{
				return users[i];
			}
		}
	}
	return User();
}

void User::Print() const
{
	Person::Print();

	preferences.Print();

	cout << "Cart:" << endl;
	PrintCart();

	cout << "Orders: " << endl;
	PrintOrders();

}
void User::PrintCart() const
{
	if (!cart.empty())
	{
		for (int i = 0; i < cart.size(); i++)
		{
			cart[i].PrintShortInfo();
		}
	}
	else
	{
		cout << "Shopping cart list is empty!" << endl;
	}
}
void User::PrintWishlist() const
{
	for (int i = 0; i < wishlist.size(); i++)
	{
		wishlist[i].PrintShortInfo();
	}
}
void User::PrintOrders() const
{
	if (!orders.empty())
	{
		for (int i = 0; i < orders.size(); i++)
		{
			orders[i].Print();
		}
	}
	else
	{
		cout << "Orders list is empty!" << endl;
	}
}

void User::AddToCart(Book Tbook)
{
	try
	{
		cart.push_back(Tbook);
		preferences.NewBook(Tbook);
	}
	catch (const exception&)
	{
		cout << "Something went wrong while adding the book to your cart." << endl;
	}
}
void User::PlaceOrder(Book Tbook)
{
	try
	{
		Move m;
		Order order(Tbook);

		bool ext = false;
		while (!ext)
		{
			cout << "Enter the number of books you want to order: "; m.SecureEnter(order.BooksCounter);

			if (order.BooksCounter == 0)
			{
				cout << "Minimum number to order is 1 book!" << endl;
			}
			else
			{
				ext = true;
			}
		}
		
		cout << "Enter the address for delivery: "; cin >> order.address;
		cout << "Total coast will be: " << (order.GetCoast() - discount);

		string password;

		ext = false;
		while (!ext)
		{
			cout << "Enter your account password to confirm your order (or [0] to cansel): "; cin >> password;

			if (password == "0")
			{
				ext = true;
			}
			if (password == this->password)
			{
				order.SetStatus(1);
				order.coast = order.GetCoast() - discount;

				orders.push_back(order);
				preferences.NewBook(Tbook);

				cout << "The order was successfully placed! You can see the order status in the \"My Orders\" menu!" << endl;
			}
			else
			{
				cout << "Incorrect password!" << endl;
			}
		}
	}
	catch (...)
	{
		cout << "The checkout process was interrupted. Try again later!" << endl;
	}
}
void User::AddToWishlist(Book Tbook)
{
	try
	{
		wishlist.push_back(Tbook);
		preferences.NewBook(Tbook);
	}
	catch (const exception&)
	{
		cout << "Something went wrong when adding a book to your wish list!" << endl;
	}
}

void User::RemoveFromCart()
{
	PrintCart();

	if (cart.empty())
	{
		cout << "Cart is empty!" << endl;
		return;
	}

	string title;
	cout << "Enter book title: "; getline(cin, title);

	for (auto book = cart.begin(); book != cart.end(); )
	{
		if (title == book->GetTitle())
		{
			book = cart.erase(book);
			cout << "Book was removed from cart!" << endl;
			return;
		}
		else
		{
			++book;
		}
	}
	cout << "Book is not found!" << endl;
}
void User::RemoveFromOrders()
{
	PrintOrders();

	if (orders.empty())
	{
		cout << "Orders list is empty!" << endl;
		return;
	}

	string title;
	cout << "Enter book title: "; getline(cin, title);

	int i = 0;
	for (auto book = orders.begin(); book != orders.end(); i++)
	{
		if (title == orders[i].GetTitle())
		{
			book = orders.erase(book);
			cout << "Book was removed from cart!" << endl;
			return;
		}
		else
		{
			++book;
		}
	}
	cout << "Book is not found!" << endl;
}
void User::RemoveFromWishlist()
{
	if (wishlist.empty())
	{
		cout << "Wishlist is empty!" << endl;
		return;
	}

	string title;
	cout << "Enter book title: "; getline(cin, title);

	for (auto book = wishlist.begin(); book != wishlist.end(); )
	{
		if (title == book->GetTitle())
		{
			book = wishlist.erase(book);
			cout << "Book was removed from wishlist!" << endl;
			return;
		}
		else
		{
			++book;
		}
	}
	cout << "Book is not found!" << endl;
}

void User::Order::Print() const
{
	cout << "Book: " << book.GetTitle() << endl;
	cout << "Number of books: " << BooksCounter << endl;
	cout << "Delivery address: " << address << endl;
	cout << "Total coast (with delivery): " << coast << endl;
	cout << "Status: " << GetStatus() << endl;
}
float User::Order::GetCoast() const
{
	if (BooksCounter != 0)
	{
		return book.GetPrice() * BooksCounter;
	}
	else
	{
		return book.GetPrice();
	}
}
string User::Order::GetStatus() const
{
	switch (status)
	{
	case 0: return "None";
	case 1: return "In_Processing";
	case 2: return "Sent";
	case 3: return "OnTheRroad";
	case 4: return "Delivered";
	case 5: return "Canceled";
	}
}
void User::Order::SetStatus(int number)
{
	switch (number)
	{
	case 0: status = None; break;
	case 1: status = In_Processing; break;
	case 2: status = Sent; break;
	case 3: status = OnTheRroad; break;
	case 4: status = Delivered; break;
	case 5: status = Canceled; break;
	default: cout << "Wrong number!" << endl; break;
	}
}

void User::Preferences::NewBook(Book book)
{
	this->authors[book.GetAuthor()]++;
	this->languages[book.GetLanguage()]++;
	
	vector<string> string_genre = book.GetAllGenres_string();
	for (int i = 0; i < string_genre.size(); i++)
	{
		this->genres[string_genre[i]]++;
	}

	FindFavoriteAuthor();
	FindFavoriteLanguage();
}
bool User::Preferences::isEmpty() const
{
	if (authors.empty() && languages.empty())
	{
		return true;
	}
	return false;
}

void User::Preferences::Print() const
{
	if (!authors.empty())
	{
		cout << "author:" << endl;
		for (const auto& author : authors) {
			cout << "  " << author.first << ": " << author.second << endl;
		}
	}
	if (!languages.empty())
	{
		cout << "Language:" << endl;
		for (const auto& lang : languages) {
			cout << "  " << lang.first << ": " << lang.second << endl;
		}
	}
}
void User::Preferences::FindFavoriteAuthor()
{
	int maxValue = 0;

	for (const auto& pair : authors)
	{
		if (pair.second > maxValue)
		{
			favoriteAuthor = pair.first;
			maxValue = pair.second;
		}
	}
}
void User::Preferences::FindFavoriteLanguage()
{
	int maxValue = 0;

	for (const auto& pair : languages)
	{
		if (pair.second > maxValue)
		{
			favoriteLanguage = pair.first;
			maxValue = pair.second;
		}
	}
}
void User::Preferences::FindFavoriteGenre()
{
	int maxValue = 0;

	for (const auto& pair : genres)
	{
		if (pair.second > maxValue)
		{
			favoriteGenre = pair.first;
			maxValue = pair.second;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Admin::ChangeBookInfo(Book& book)
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

void Admin::AddSaleToBook(Book& book)
{
	try
	{
		float sale;
		cout << "Enter sale in percentage (for example: [20.6]): "; cin >> sale;
		book.SetSale(sale);
	}
	catch (...)
	{
		cout << "Sale must be a number!" << endl;
	}
}

bool Admin::MakeNickname(const vector<User> all_users, const vector<Admin> all_admins)
{
	bool ext = false, go = true;
	while (!ext)
	{
		cout << "To exit press [0]" << endl;
		cout << "Make up a nickname:  "; cin >> nickname;

		if (nickname == "0")
		{
			system("cls");
			return false;
		}
		else
		{
			for (int i = 0; i < all_users.size(); i++)
			{
				if (nickname == all_users[i].GetNickname())
				{
					Exist();
					go = false;
					break;
				}
			}
			if (go == true)
			{
				for (int i = 0; i < all_users.size(); i++)
				{
					if (nickname == all_users[i].GetNickname())
					{
						Exist();
						go = false;
						break;
					}
				}
			}
			
			if (go == true)
			{
				system("cls");
				return true;
			}
			go = true;
		}
	}
}

bool Admin::Register(vector<User> all_users, vector<Admin> all_admins)
{
	try
	{
		system("cls");
		bool ext = false;

		cout << "Fill out the form with information about yourself: " << endl;
		cout << "Your name: "; getline(cin, name);
		cout << "Your surname: "; getline(cin, surname);
		cout << "Phone number: "; getline(cin, phone);

		while (!ext)
		{
			system("cls");
			cout << "your age (number): ";
			if (!(cin >> age))
			{
				cin.clear(); // Clear errors
				cin.ignore(10000, '\n'); // Crear buffer

				cout << "Age must be a number! Incorrect argument!" << endl;
				system("pause");
			}
			else
			{
				ext = true;
			}
		}
		ext = false;

		system("cls"); cout << "Ok!" << endl; system("pause"); system("cls");

		while (!ext)
		{
			bool go = MakeNickname(all_users, all_admins);

			if (go == false)
			{
				if (isContinue() == true)
				{
					system("cls");
				}
				else
				{
					return false;
				}
			}
			else
			{
				ext = true;
			}
		}
		ext = false;

		while (!ext)
		{
			bool go = false;
			go = MakeUpPassword();

			if (go == false)
			{
				if (!isContinue())
				{
					system("cls");
					return false;
				}
			}
			else
			{
				ext = true;
			}
		}

		account_status = Active;

		idCounter++;
		id = idCounter;

		return true;
	}
	catch (const exception& exception)
	{
		cout << exception.what() << endl;
		return false;
	}
}
Admin Admin::LogIn(vector<Admin> admins, string nickname, string password)
{
	for (int i = 0; i < admins.size(); i++)
	{
		if (admins[i].nickname == nickname)
		{
			if (admins[i].password == password)
			{
				return admins[i];
			}
		}
	}
	return Admin();
}
