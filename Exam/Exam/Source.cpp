#pragma once
#include "FilesWork.h"

using namespace std;

struct Who_I_Am
{
	string status;
	User* user;
	Admin* admin;

	Who_I_Am() : status("none"), user(nullptr), admin(nullptr) {}
};

int Person::idCounter = 0;
unsigned int Book::idCounter = 0;

Admin static_admin;
User static_user;

class Menu
{
	Library library;
	vector<Admin> admins;
	vector<User> users;
	FilesWork fw;

	string LogIn(vector<User> users, vector<Admin> admins, Who_I_Am& me)
	{
		Move move; Admin admin; User user;

		bool is_found = false;
		string nickname, password;

		cout << "Enter your nickname: "; cin >> nickname;
		cout << "Enter your password: "; password = move.PasswordAnimation();

		if (!admins.empty())
		{
			admin = admin.LogIn(admins, nickname, password);
			if (!admin.isEmpty())
			{
				static_admin = admin;
				me.admin = &static_admin;
				me.status = "admin";
				return me.status;
			}
		}

		if (!users.empty())
		{
			user = user.LogIn(users, nickname, password);
			if (!user.isEmpty())
			{
				static_user = user;
				me.user = &static_user;
				me.status = "user";
				return me.status;
			}
		}

		if (is_found == false)
		{
			cout << "Incorrect data!" << endl; 
			sc();
		}
		
		return "false";
	}

	inline void sc() const
	{
		system("pause"); system("cls");
	}

	bool InRange() const
	{
		bool ext = false;
		int i = 0; int min = 0;
		Move move;
		move(0, min);

		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(2, i); cout << "Find book in range...";
			i++;
			move.Gotoxy(2, i); cout << "Find book by...";
			i++;
			move.Gotoxy(); cout << "->";

			string go_to = move.CatchMove();
			system("cls");

			if (go_to == "enter")
			{
				if (move.Y == 0)
				{
					return true;
				}
				else
				{
					return false;
				}
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

	void FindBookBy() const
	{
		bool ext = false;
		int int_temp = 0;
		string temp;

		int i = 0, min = 1;

		Move move;
		move(0, min);

		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(3, i); cout << "-*-*-*-*-*-*-*| Find book by |**-*-*-*-*-*-"; i++;
			move.Gotoxy(3, i); cout << "Number of books"; i++;
			move.Gotoxy(3, i); cout << "Type"; i++;
			move.Gotoxy(3, i); cout << "Title"; i++;
			move.Gotoxy(3, i); cout << "Author"; i++;
			move.Gotoxy(3, i); cout << "Age rating"; i++;
			move.Gotoxy(3, i); cout << "Year"; i++;
			move.Gotoxy(3, i); cout << "Price"; i++;
			move.Gotoxy(3, i); cout << "Id"; i++;
			move.Gotoxy(3, i); cout << "Genre"; i++;
			move.Gotoxy(3, i); cout << "Language"; i++;
			move.Gotoxy(); cout << "->";

			string go_to = move.CatchMove();
			system("cls");

			if (go_to == "enter")
			{
				try
				{
					if (move.Y == 1)
					{
						cout << "Enter number of books: ";
						move.SecureEnter(int_temp);
						library.FindBookBy_NumberOfBooks(int_temp);
					}
					else if (move.Y == 2)
					{
						cout << "Enter type to search: "; cin >> temp;
						library.FindBookBy_type(temp);
					}
					else if (move.Y == 3)
					{
						cout << "Enter title to search: "; cin >> temp;
						library.FindBookBy_title(temp);
					}
					else if (move.Y == 4)
					{
						cout << "Enter author to search: "; cin >> temp;
						library.FindBookBy_author(temp);
					}
					else if (move.Y == 5)
					{
						cout << "Enter age rating: ";
						move.SecureEnter(int_temp);
						library.FindBookBy_ageRating(int_temp);
					}
					else if (move.Y == 6)
					{
						cout << "Enter book year: ";
						move.SecureEnter(int_temp);
						library.FindBookBy_year(int_temp);
					}
					else if (move.Y == 7)
					{
						cout << "Enter number of books: ";

						float price;
						move.SecureEnter(price);

						library.FindBookBy_price(int_temp);
					}
					else if (move.Y == 8)
					{
						cout << "Enter book id: ";
						move.SecureEnter(int_temp);
						library.FindBookBy_id(int_temp);
					}
					else if (move.Y == 9)
					{
						cout << "Enter genre to search: "; cin >> temp;
						library.FindBookBy_Genre(temp);
					}
					else
					{
						cout << "Enter language to search: "; cin >> temp;
						library.FindBookBy_language(temp);
					}
				}
				catch (const IncorrectValue& except)
				{
					cout << except << endl;
				}
				catch (const IdDoesNotExist& except)
				{
					cout << except << endl;
				}
				catch (...)
				{
					cout << "There was an unexpected error! Maybe you should try again later." << endl;
				}
				sc();
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
	void FindBookInRange() const
	{
		bool ext = false;
		int r1, r2;
		int i = 0, min = 1;
		string temp;

		Move move;
		move(0, min);

		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(3, i); cout << "-*-*-*-*-*-*-*| Find book by |**-*-*-*-*-*-";
			i++;
			move.Gotoxy(3, i); cout << "Number of books";
			i++;
			move.Gotoxy(3, i); cout << "Age rating";
			i++;
			move.Gotoxy(3, i); cout << "Year";
			i++;
			move.Gotoxy(3, i); cout << "Price";
			i++;
			move.Gotoxy(3, i); cout << "Id";
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
						cout << "Find by number of books" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: "; move.SecureEnter(r2);

						library.FindBookBy_NumberOfBooks(r1, r2);
					}
					else if (move.Y == 2)
					{
						cout << "Find by age rating" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: "; move.SecureEnter(r2);

						library.FindBookBy_ageRating(r1, r2);
					}
					else if (move.Y == 3)
					{
						cout << "Find by year" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: "; move.SecureEnter(r2);

						library.FindBookBy_year(r1, r2);
					}
					else if (move.Y == 4)
					{
						cout << "Find by price" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: "; move.SecureEnter(r2);

						library.FindBookBy_price(r1, r2);
					}
					else
					{
						cout << "Find by id" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: ";  move.SecureEnter(r2);

						library.FindBookBy_id(r1, r2);
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
				sc();
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
	void FindBookMenu() const
	{
		system("cls");
		bool inRange = InRange();

		system("cls");
		if (inRange == true)
		{
			FindBookInRange();
		}
		else
		{
			FindBookBy();
		}
	}

	int ChooseBook(int id) const
	{
		try
		{
			system("cls");
			library.IsExistId(id);

			return library.GetBookIterator_by_ID(id);
		}
		catch (const IdDoesNotExist& except)
		{
			cout << except << endl;
			sc();
		}
	}

	void User_WorkWithBook(int id, Who_I_Am& me)
	{
		bool ext = false;
		int i = 0, min = 1;
		Move move;
		move(0, 0);

		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(2, i); cout << "Choose what do you want to do next: ";
			i++;
			move.Gotoxy(2, i); cout << "Add to cart";
			i++;
			move.Gotoxy(2, i); cout << "Add to wishlist";
			i++;
			move.Gotoxy(2, i); cout << "Place an order";
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

					}
					else if (move.Y == 2)
					{

					}
					else if (move.Y == 3)
					{

					}
					else
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
					cout << "There was an unexpected error! Maybe you should try again later." << endl;
				}
				sc();
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
	void Admin_WorkWithBook(int id, Who_I_Am& me)
	{
		if (me.admin == nullptr)
		{
			throw PermissionDenied();
		}

		bool ext = false;
		int i = 0, min = 1;
		Move move;
		move(0, 0);

		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(2, i); cout << "-*-*-*-*-*-*-*-*-+| Choose what do you want to do nex |+-*-*-*-*-*-*-*-*-";
			i++;
			move.Gotoxy(2, i); cout << "Change book information";
			i++;
			move.Gotoxy(2, i); cout << "Add a discount to the book";
			i++;
			move.Gotoxy(2, i); cout << "Delete this book";
			i++;
			move.Gotoxy(2, i); cout << "Come back";
			i++;
			move.Gotoxy(); cout << "->";

			string go_to = move.CatchMove();
			system("cls");

			if (go_to == "enter")
			{
				if (move.Y == 1) // Change book information
				{
					me.admin->ChangeBookInfo(library[id]);
				}
				else if (move.Y == 2) // Add a discount to the book
				{
					me.admin->AddSaleToBook(library[id]);
				}
				else if (move.Y == 3) // Delete this book
				{
					library.DeleteBook(library[id]);
				}
				else // Come back
				{
					ext = true;
				}
				sc();
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

	void User_SelectBook(Who_I_Am& me)
	{
		try
		{
			system("cls");
			Move move;

			int id_of_this_book;
			cout << "Enter book id: ";
			move.SecureEnter(id_of_this_book);

			library.IsExistId(id_of_this_book);

			Admin_WorkWithBook(id_of_this_book, me);
		}
		catch (const IncorrectValue& except)
		{
			cout << except << endl;
			sc();
		}
		catch (const IdDoesNotExist& except)
		{
			cout << except << endl;
			sc();
		}
		catch (...)
		{
			cout << "There was an unexpected error! Maybe you should try again later." << endl;
			sc();
		}
	}
	void Admin_SelectBook(Who_I_Am& me)
	{
		try
		{
			system("cls");
			Move move;

			int id_to_search;
			cout << "Enter book id: ";
			move.SecureEnter(id_to_search);

			library.FindBookBy_NumberOfBooks(id_to_search);

			Admin_WorkWithBook(id_to_search, me);
		}
		catch (const IncorrectValue& except)
		{
			cout << except << "Try again next time." << endl;
			sc();
		}
		catch (const PermissionDenied& except)
		{
			cout << except << endl;
			sc();
		}
		catch (...)
		{
			cout << "There was an unexpected error! Maybe you should try again later." << endl;
			sc();
		}
	}

	void FindBook(Who_I_Am& me)
	{
		system("cls");
		FindBookMenu();

		Move move;
		int i = 0, min = 0;
		move(0, min);

		bool ext = false;
		while (ext == false)
		{
			i = 0;

			move.Gotoxy(1, i); cout << "Come back";
			i++;
			move.Gotoxy(1, i); cout << "Select a book";
			i++;
			move.Gotoxy(); cout << ">";

			string go_to = move.CatchMove();

			if (go_to == "enter")
			{
				if (move.Y == 0)
				{
					ext = true;
				}
				else
				{
					if (me.status == "admin")
					{
						Admin_SelectBook(me);
					}
					else
					{
						User_SelectBook(me);
					}
				}
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

public:

	string StartProgram(Who_I_Am& me)
	{
		User user;
		fw.ReadFromFile(library, admins, users);
		int i = 0, min = 1;
		Move move;
		move(0, min);

		bool ext = false;
		while (ext == false)
		{
			system("cls");
			i = 0;

			move.Gotoxy(1, i); cout << "+-+-+-+-+-| Welcome to book shop! | -+-+-+-+-+" << endl; 
			i++;
			move.Gotoxy(4, i); cout << "Log in";
			i++;
			move.Gotoxy(4, i); cout << "Register";
			i++;
			move.Gotoxy(4, i); cout << "Exit";
			i++;
			move.Gotoxy(); cout << "-->";

			string go_to = move.CatchMove();
			system("cls");

			if (go_to == "enter")
			{
				if (move.Y == 1)
				{
					if (!users.empty() || !admins.empty())
					{
						string result = "";
						result = LogIn(users, admins, me);

						if (result == "admin")
						{
							return "admin";
						}
						else if (result == "user")
						{
							return "user";
						}
					}
					else
					{
						cout << "Users data is empty!" << endl;
					}
				}
				else if (move.Y == 2)
				{
					if (user.Register(users))
					{
						static_user = user;
						me.user = &static_user;
						me.status = "user";

						users.push_back(user);
						return me.status;
					}
				}
				else
				{
					return "exit";
				}
			}
			else if (go_to == "down")
			{
				move.Y == 3 ? move.Y = 1 : move.Y++;
			}
			else if (go_to == "up")
			{
				move.Y == 1 ? move.Y = 3 : move.Y--;
			}
		}
		return "a";
	}

	void FinishProgram()
	{
		system("cls");
		fw.WriteToFile(library, admins, users);
	}

	void Menu_Admin(Who_I_Am& me)
	{
		FindBook(me);
		/*
			Зміна інформації про книгу +
			Додавання книги +
			Видалення книги +
			Додавання знижки на всі книги
			Додавання знижки на книгу за характеристикою
			За назвою
			За жанром
			За автором
			На всі книги
			За мовою видання
			За роком випуску
			За ціною (діапазон)
			За віковим рейтингом
			За типом
			Пошук користувача
			За характристикою
			За іменем
			За фамілією
			За віком
			За номером телефона
			За вподобанням
			В діапазоні
			За віком
			Всіх хто замовив конктетний товар
			Всіх хто замовляв
			За вподобанням
			За автором
			За жанром
			За мовою видання
			За роком випуску
			За роками випуску (діапазон)
		*/
	}
	void Menu_User(Who_I_Am& me)
	{

	}
};

void main()
{
	Move move;
	move.hidecursor();
	
	static_admin = Admin();
	static_user = User();

	Who_I_Am me;

	Menu MainMenu;
	string Who_I_Am = MainMenu.StartProgram(me);

	if (me.status == "admin")
	{
		MainMenu.Menu_Admin(me);
	}
	else if (me.status == "user")
	{
		MainMenu.Menu_User(me);
	}

	MainMenu.FinishProgram();
}
