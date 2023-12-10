#pragma once
#include "FilesWork.h"

using namespace std;

class WorkWithPeople
{
	vector<int> FindUserInRange(vector<User>& v_users)
	{
		if (v_users.empty())
		{
			throw EmptyData();
		}

		int r1, r2;
		int i = 0, min = 1;
		string temp;

		vector<int> result;

		Move move;
		move(0, min);

		bool ext = false;
		while (!ext)
		{
			result.clear();
			system("cls");
			i = 0;

			move.Gotoxy(3, i); cout << "-*-*-*-*-*-*-*| Find user in range by |**-*-*-*-*-*-";
			i++;
			move.Gotoxy(3, i); cout << "Purchase quantity";
			i++;
			move.Gotoxy(3, i); cout << "Age";
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
						cout << "Find by purchase quantity" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: "; move.SecureEnter(r2);

						for (int i = 0; i < v_users.size(); i++)
						{
							if (r1 <= v_users[i].GetCartSize() && v_users[i].GetCartSize() <= r2)
							{
								result.push_back(i);
							}
						}
					}
					else if (move.Y == 2)
					{
						cout << "Find by age" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: "; move.SecureEnter(r2);

						for (int i = 0; i < v_users.size(); i++)
						{
							if (r1 <= v_users[i].GetAge() && v_users[i].GetAge() <= r2)
							{
								result.push_back(i);
							}
						}
					}
					else
					{
						cout << "Find by id" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: ";  move.SecureEnter(r2);

						for (int i = 0; i < v_users.size(); i++)
						{
							if (r1 <= v_users[i].GetID() && v_users[i].GetID() <= r2)
							{
								result.push_back(i);
							}
						}
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
		return result;
	}
	int FindUserBy(vector<User>& v_users)
	{
		if (v_users.empty())
		{
			throw EmptyData();
		}

		User user; Admin admin;

		int i = 0, min = 1;

		string temp;
		int int_temp;

		vector<int> result;

		Move move;
		move(0, min);

		bool ext = false;
		while (!ext)
		{
			result.clear();
			system("cls");
			i = 0;

			move.Gotoxy(3, i); cout << "-*-*-*-*-*-*-*| Find user in range by |**-*-*-*-*-*-";
			i++;
			move.Gotoxy(3, i); cout << "Favorite author";
			i++;
			move.Gotoxy(3, i); cout << "Favorite language";
			i++;
			move.Gotoxy(3, i); cout << "Favorite genre";
			i++;
			move.Gotoxy(3, i); cout << "Name";
			i++;
			move.Gotoxy(3, i); cout << "Surname";
			i++;
			move.Gotoxy(3, i); cout << "Phone number";
			i++;
			move.Gotoxy(3, i); cout << "Nickname";
			i++;
			move.Gotoxy(3, i); cout << "Id";
			i++;
			move.Gotoxy(3, i); cout << "Age";
			i++;
			move.Gotoxy(3, i); cout << "Purchase quantity";
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
						cout << "Find by Favorite author" << endl;
						cin >> temp;

						for (int i = 0; i < v_users.size(); i++)
						{
							if (temp == v_users[i].GetFavoriteAuthor())
							{
								result.push_back(i);
							}
						}
					}
					else if (move.Y == 2)
					{
						cout << "Find by Favorite language" << endl;
						cin >> temp;

						for (int i = 0; i < v_users.size(); i++)
						{
							if (temp == v_users[i].GetFavoriteLanguage())
							{
								result.push_back(i);
							}
						}
					}
					else if (move.Y == 3)
					{
						cout << "Find by Favorite genre" << endl;
						cin >> temp;

						for (int i = 0; i < v_users.size(); i++)
						{
							if (temp == v_users[i].GetFavoriteGenre())
							{
								result.push_back(i);
							}
						}
					}
					else if (move.Y == 4)
					{
						cout << "Find by Name" << endl;
						cin >> temp;

						for (int i = 0; i < v_users.size(); i++)
						{
							if (temp == v_users[i].GetName())
							{
								result.push_back(i);
							}
						}
					}
					else if (move.Y == 5)
					{
						cout << "Find by Surname" << endl;
						cin >> temp;

						for (int i = 0; i < v_users.size(); i++)
						{
							if (temp == v_users[i].GetSurname())
							{
								result.push_back(i);
							}
						}
					}
					else if (move.Y == 6)
					{
						cout << "Find by Phone number" << endl;
						cin >> temp;

						for (int i = 0; i < v_users.size(); i++)
						{
							if (temp == v_users[i].GetPhone())
							{
								result.push_back(i);
							}
						}
					}
					else if (move.Y == 7)
					{
						cout << "Find by Nickname" << endl;
						cin >> temp;

						for (int i = 0; i < v_users.size(); i++)
						{
							if (temp == v_users[i].GetNickname())
							{
								result.push_back(i);
							}
						}
					}
					else if (move.Y == 8)
					{
						cout << "Find by Id" << endl;
						move.SecureEnter(int_temp);

						for (int i = 0; i < v_users.size(); i++)
						{
							if (int_temp == v_users[i].GetID())
							{
								result.push_back(i);
							}
						}
					}
					else if (move.Y == 9)
					{
						cout << "Find by Age" << endl;
						move.SecureEnter(int_temp);

						for (int i = 0; i < v_users.size(); i++)
						{
							if (int_temp == v_users[i].GetAge())
							{
								result.push_back(i);
							}
						}
					}
					else if (move.Y == 10)
					{
						cout << "Find by Purchase quantity" << endl;
						move.SecureEnter(int_temp);

						for (int i = 0; i < v_users.size(); i++)
						{
							if (int_temp == v_users[i].GetOrdersSize())
							{
								result.push_back(i);
							}
						}
					}
					else if (move.Y == 11)
					{
						cout << "Find by Account status" << endl;
						cin >> temp;

						for (int i = 0; i < v_users.size(); i++)
						{
							if (temp == v_users[i].GetStatus())
							{
								result.push_back(i);
							}
						}
					}
					else
					{
						return true;
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

	friend class Menu;
};

class Menu
{
	static Admin static_admin;
	static User static_user;

	struct Who_I_Am
	{
		string status;
		User* user;
		Admin* admin;

		Who_I_Am() : status("none"), user(nullptr), admin(nullptr) {}
	};
	
	Who_I_Am me;

	Library library;
	vector<Admin> admins;
	vector<User> users;
	FilesWork fw;


	// ADMIN
	void Admin_WorkWithBook(int iter)
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
					me.admin->ChangeBookInfo(library[iter]);
				}
				else if (move.Y == 2) // Add a discount to the book
				{
					me.admin->AddSaleToBook(library[iter]);
				}
				else if (move.Y == 3) // Delete this book
				{
					library.DeleteBook(library[iter]);
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
	void Admin_WorkWithUser_inRange(vector<int> results)
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

			move.Gotoxy(2, i); cout << "-*-*-*-*-*-*-*-*-+| Choose what do you want to do next |+-*-*-*-*-*-*-*-*-";
			i++;
			move.Gotoxy(2, i); cout << "Make a discount (before removing the discount manually)";
			i++;
			move.Gotoxy(2, i); cout << "Change users status";
			i++;
			move.Gotoxy(2, i); cout << "Exit";
			i++;
			move.Gotoxy(); cout << "->";

			string go_to = move.CatchMove();
			system("cls");

			if (go_to == "enter")
			{
				try
				{
					if (move.Y == 1) // Make a discount
					{
						if (me.admin->isValidPassword())
						{
							float discount;
							for (int i = 0; i < results.size(); i++)
							{
								move.SecureEnter(discount);
								users[results[i]].SetDiscount(discount);
							}
						}
						else
						{
							throw PermissionDenied();
						}
					}
					else if (move.Y == 2) // Change users status
					{
						
						if (me.admin->isValidPassword())
						{
							for (int i = 0; i < results.size(); i++)
							{
								me.admin->ChangeUserStatus(users[results[i]]);
							}
						}
						else
						{
							throw PermissionDenied();
						}
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
				catch (const PermissionDenied& except)
				{
					cout << except << endl;
				}
				catch (...)
				{
					cout << "An unexpected error!" << endl;
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

	void AddDiscount_inRange()
	{
		if (me.status != "admin")
			throw PermissionDenied();

		bool ext = false;
		int i = 0, min = 1, r1, r2;

		vector<int> result_iter;

		Move move;
		move(0, min);

		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(2, i); cout << "-*-*-*-*-*-*-*| Add a discount on books in the range by|*-*-*-*-*-*-*-";
			i++;
			move.Gotoxy(2, i); cout << "Age rating";
			i++;
			move.Gotoxy(2, i); cout << "Release date";
			i++;
			move.Gotoxy(2, i); cout << "Number of copies";
			i++;
			move.Gotoxy(2, i); cout << "Price";
			i++;
			move.Gotoxy(); cout << "->";

			string go_to = move.CatchMove();
			system("cls");

			if (go_to == "enter")
			{
				try
				{
					if (move.Y == 1) // Age rating
					{
						cout << "Find by age rating" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: ";  move.SecureEnter(r2);

						system("cls");
						cout << "|-|-| A discount will be added to all books below |-|-|" << endl << endl;
						vector<int> result_iter = library.FindBookBy_ageRating(r1, r2, true);

						cout << "To add a discount, press [ENTER]" << endl;

						int key = _getch();
						if (key == 13) // Enter
						{
							float discount;
							cout << "Enter a discount: "; move.SecureEnter(discount);

							for (int i = 0; i < result_iter.size(); i++)
							{
								me.admin->AddSaleToBook(library[result_iter[i]]);
							}
						}
					}
					else if (move.Y == 2) // Release date
					{
						cout << "Find by release data" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: ";  move.SecureEnter(r2);

						system("cls");
						cout << "|-|-| A discount will be added to all books below |-|-|" << endl << endl;
						vector<int> result_iter = library.FindBookBy_year(r1, r2, true);

						cout << "To add a discount, press [ENTER]" << endl;

						int key = _getch();
						if (key == 13) // Enter
						{
							float discount;
							cout << "Enter a discount: "; move.SecureEnter(discount);

							for (int i = 0; i < result_iter.size(); i++)
							{
								me.admin->AddSaleToBook(library[result_iter[i]]);
							}
						}
					}
					else if (move.Y == 2) // Number of copies
					{
						cout << "Find by number of copies" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: ";  move.SecureEnter(r2);

						system("cls");
						cout << "|-|-| A discount will be added to all books below |-|-|" << endl << endl;
						vector<int> result_iter = library.FindBookBy_NumberOfBooks(r1, r2, true);

						cout << "To add a discount, press [ENTER]" << endl;

						int key = _getch();
						if (key == 13) // Enter
						{
							float discount;
							cout << "Enter a discount: "; move.SecureEnter(discount);

							for (int i = 0; i < result_iter.size(); i++)
							{
								me.admin->AddSaleToBook(library[result_iter[i]]);
							}
						}
					}
					else // Price
					{
						cout << "Find by price" << endl;

						cout << "Min range: "; move.SecureEnter(r1);
						cout << "Max range: ";  move.SecureEnter(r2);

						system("cls");
						cout << "|-|-| A discount will be added to all books below |-|-|" << endl << endl;
						vector<int> result_iter = library.FindBookBy_price(r1, r2, true);

						cout << "To add a discount, press [ENTER]" << endl;

						int key = _getch();
						if (key == 13) // Enter
						{
							float discount;
							cout << "Enter a discount: "; move.SecureEnter(discount);

							for (int i = 0; i < result_iter.size(); i++)
							{
								me.admin->AddSaleToBook(library[result_iter[i]]);
							}
						}
					}
				}
				catch (const IncorrectValue& except)
				{
					cout << except << endl;
				}
				catch (const exception& except)
				{
					cout << "Unknown error!" << endl;
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
	void Admin_SelectBook()
	{
		try
		{
			system("cls");
			Move move;

			int id_to_search;
			cout << "Enter book id: ";
			move.SecureEnter(id_to_search);

			library.FindBookBy_NumberOfBooks(id_to_search);

			Admin_WorkWithBook(id_to_search);
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
	void Menu_Admin()
	{
		if (me.status != "admin")
			throw PermissionDenied();

		bool ext = false;
		int i = 0; int min = 1;
		Move move;
		move(0, min);

		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(2, i); cout << "-*-*-*-*-*-*-*| Admin menu |*-*-*-*-*-*-*-";
			i++;
			move.Gotoxy(2, i); cout << "Register a new administrator account";
			i++;
			move.Gotoxy(2, i); cout << "Add a book to the library";
			i++;
			move.Gotoxy(2, i); cout << "Add a discount to the books";
			i++;
			move.Gotoxy(2, i); cout << "Find book";
			i++;
			move.Gotoxy(2, i); cout << "Find user";
			i++;
			move.Gotoxy(); cout << "->";

			string go_to = move.CatchMove();
			system("cls");

			if (go_to == "enter")
			{
				try
				{
					if (move.Y == 1) // Register a new administrator account
					{
						Admin admin;
						admin.Register(users, admins);
					}
					else if (move.Y == 2) // Add a book to the library
					{
						library.AddNewBook();
					}
					else if (move.Y == 3) // Add a discount to the books
					{
						if (InRange())
						{
							AddDiscount_inRange();
						}
					}
					else if (move.Y == 4) // Find book
					{
						FindBook();
					}
					else // Find user
					{
						FindUser();
					}
				}
				catch (const PermissionDenied& except)
				{
					cout << except << endl;
				}
				catch (const exception& except)
				{
					cout << "Unknown error!" << endl;
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
	void FindUser()
	{
		try
		{
			if (me.status != "admin")
			{
				throw PermissionDenied();
			}

			WorkWithPeople wwp;


			if (InRange("user"))
			{
				vector<int> result_of_find = wwp.FindUserInRange(users);
				
				if (Continue())
				{
					Admin_WorkWithUser_inRange(result_of_find);
				}
			}
			else
			{
				int result_of_find = wwp.FindUserBy(users);

				if (Continue())
				{
					me.admin->ChangeUserInfo(users[result_of_find]);
				}
			}
		}
		catch (const PermissionDenied& except)
		{
			cout << except << endl;
		}
		catch (...)
		{
			cout << "An unexpected error!" << endl;
		}
	}
	void FindBook()
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
						Admin_SelectBook();
					}
					else
					{
						User_SelectBook();
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

	// USER
	void User_WorkWithBook(int iter)
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
						me.user->AddToCart(library[iter]);
					}
					else if (move.Y == 2)
					{
						me.user->AddToWishlist(library[iter]);
					}
					else if (move.Y == 3)
					{
						me.user->PlaceOrder(library[iter]);
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
	void User_SelectBook()
	{
		try
		{
			system("cls");
			Move move;

			int id_of_this_book;
			cout << "Enter book id: ";
			move.SecureEnter(id_of_this_book);

			library.IsExistId(id_of_this_book);

			User_WorkWithBook(id_of_this_book);
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
	void Menu_User()
	{

	}

	// FOR ALL
	string LogIn(vector<User> users, vector<Admin> admins)
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

	bool InRange(string what = "book") const
	{
		bool ext = false;
		int i = 0; int min = 0;
		Move move;
		move(0, min);

		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(2, i); cout << "Find " << what << " in range...";
			i++;
			move.Gotoxy(2, i); cout << "Find " << what << " by...";
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
	bool Continue() const
	{
		int i = 0; int min = 0;
		Move move;
		move(0, min);

		bool ext = false;
		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(2, i); cout << "Continue to work with that";
			i++;
			move.Gotoxy(2, i); cout << "Come back";
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

			move.Gotoxy(3, i); cout << "-*-*-*-*-*-*-*| Find book in range by |**-*-*-*-*-*-";
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
						float fr1, fr2;
						cout << "Find by price" << endl;

						cout << "Min range: "; move.SecureEnter(fr1);
						cout << "Max range: "; move.SecureEnter(fr2);

						library.FindBookBy_price(fr1, fr2);
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
		if (InRange())
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


public:

	inline void sc() const
	{
		system("pause"); system("cls");
	}

	string StartProgram()
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
						result = LogIn(users, admins);

						if (result == "admin")
						{
							Menu_Admin();
						}
						else if (result == "user")
						{
							Menu_User();
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
						Menu_User();
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
	}
	void FinishProgram()
	{
		system("cls");
		fw.WriteToFile(library, admins, users);
	}
};


int Person::idCounter = 0;
unsigned int Book::idCounter = 0;
Admin Menu::static_admin;
User Menu::static_user;


void main()
{
	// Рекомендации (по preferences) for users

	Move move;
	move.hidecursor();
	Menu MainMenu;
	string ext;

	do
	{
		string ext = MainMenu.StartProgram();

		if (ext == "error")
		{
			cout << "For some unknown reason, the menu was closed!" << endl; 
			MainMenu.sc();
		}

	} while (ext == "exit");
	
	MainMenu.FinishProgram();
}
