
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
		Order order(Tbook);
		cout << "Enter the number of books you want to order: "; cin >> order.BooksCounter;
		if (!(cin >> order.BooksCounter))
		{
			throw runtime_error("Invorrect type! Try entering a number next time!");
		}
		if (order.BooksCounter == 0)
		{
			cout << "Minimum number to order is 1 book!" << endl;
		}
		cout << "Enter the address for delivery: "; cin >> order.address;
		cout << "Total coast will be: " << order.GetCoast();

		string password;
		cout << "Enter your account password to confirm your order (or [0] to cansel): "; cin >> password;

		if (password == this->password)
		{
			order.SetStatus(1);
			orders.push_back(order);
			preferences.NewBook(Tbook);
			cout << "The order was successfully placed! You can see the order status in the \"My Orders\" menu!" << endl;
		}
		else
		{
			throw runtime_error("Incorrect password!");
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
		wishlist.push_back(Tbook.GetID());
		preferences.NewBook(Tbook);
	}
	catch (const exception&)
	{
		cout << "Something went wrong when adding a book to your wish list!" << endl;
	}
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
