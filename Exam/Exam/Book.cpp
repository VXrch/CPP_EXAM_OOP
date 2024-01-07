#include "People.h"

string Book::GetLanguage() const
{
	switch (language)
	{
	case Book::Language::English: return "English";
	case Book::Language::Ukrainian: return "Ukrainian";
	case Book::Language::Italian: return "Italian";
	case Book::Language::Spanish: return "Spanish";
	case Book::Language::French: return "French";
	case Book::Language::German: return "German";
	default: return "";
	}
}
string Book::GetGenre(int number) const
{
	switch (number)
	{
	case 1: return "Fantasy";
	case 2: return "ScienceFiction";
	case 3: return "Dystopian";
	case 4: return "Action";
	case 5: return "Mystery";
	case 6: return "Horror";
	case 7: return "Thriller";
	case 8: return "HistoricalFiction";
	case 9: return "Romance";
	case 10: return "ContemporaryFiction";
	case 11: return "MagicalRealism";
	case 12: return "GraphicNovel";
	case 13: return "Memoir";
	case 14: return "Biography";
	case 15: return "Travel";
	case 16: return "TrueCrime";
	case 17: return "Humor";
	default: return "";
	}
}

void Book::Print() const
{
	cout << "ID: " << id << endl;
	cout << "Title: " << title << endl;
	cout << "author: " << author << endl;
	cout << "discription: " << discription << endl;
	cout << "year: " << year << endl;
	cout << "price: " << price << endl;
	cout << "language: " << GetLanguage() << endl;

	cout << "Genres: " << endl;
	if (genres.empty()) { cout << "None" << endl; }
	else
	{
		string genre;
		for (int i = 0; i < genres.size(); i++)
		{
			genre = GetGenre(genres[i]);
			cout << genre << endl;
		}
	}
}
void Book::PrintMinInfo() const
{
	cout << "ID: " << id << "Title: " << title << " | Author: " << author << " | Language: " << GetLanguage() << endl;
}
void Book::PrintAllGenres() const
{
	cout << "[Fantasy] " << endl;
	cout << " [Science Fiction] " << endl;
	cout << " [Dystopian] " << endl;
	cout << " [Action] " << endl;
	cout << " [Mystery] " << endl;
	cout << " [Horror] " << endl;
	cout << " [Thriller] " << endl;
	cout << " [Historical Fiction] " << endl;
	cout << " [Romance] " << endl;
	cout << " [Contemporary Fiction] " << endl;
	cout << " [Magical Realism] " << endl;
	cout << " [Graphic Novel] " << endl;
	cout << " [Memoir] " << endl;
	cout << " [Biography] " << endl;
	cout << " [Travel] " << endl;
	cout << " [True Crime] " << endl;
	cout << " [Humor]" << endl;
}
void Book::PrintShortInfo() const
{
	cout << "ID: " << id << endl;
	cout << "Title: " << title << endl;
	cout << "author: " << author << endl;
	cout << "language: " << GetLanguage() << endl;
}
void Book::PrintAllGenres(int X = 1, int Y = 1) const
{
	Move move(X, Y);

	move.Gotoxy(X, Y); cout << "[Fantasy] "; Y++;
	move.Gotoxy(X, Y); cout << "[Science Fiction] "; Y++;
	move.Gotoxy(X, Y); cout << "[Dystopian] "; Y++;
	move.Gotoxy(X, Y); cout << "[Action] "; Y++;
	move.Gotoxy(X, Y); cout << "[Mystery] "; Y++;
	move.Gotoxy(X, Y); cout << "[Horror] "; Y++;
	move.Gotoxy(X, Y); cout << "[Thriller] "; Y++;
	move.Gotoxy(X, Y); cout << "[Historical Fiction] "; Y++;
	move.Gotoxy(X, Y); cout << "[Romance] "; Y++;
	move.Gotoxy(X, Y); cout << "[Contemporary Fiction] "; Y++;
	move.Gotoxy(X, Y); cout << "[Magical Realism] "; Y++;
	move.Gotoxy(X, Y); cout << "[Graphic Novel] "; Y++;
	move.Gotoxy(X, Y); cout << "[Memoir] "; Y++;
	move.Gotoxy(X, Y); cout << "[Biography] "; Y++;
	move.Gotoxy(X, Y); cout << "[Travel] "; Y++;
	move.Gotoxy(X, Y); cout << "[True Crime] "; Y++;
	move.Gotoxy(X, Y); cout << "[Humor]";
}
void Book::PrintAndSetLanguage(string title_to_set)
{
	string language;

	Move move(0, 1);
	bool ext = false;

	int i = 0, min = 1;

	while (!ext)
	{
		system("cls");
		i = 0;		

		move.Gotoxy(0, i); cout << "-*-*-*-*-*-*-*-*-+| " << title_to_set << " |+-*-*-*-*-*-*-*-*-";
		i++;
		move.Gotoxy(2, i); cout << "[English]";
		i++;
		move.Gotoxy(2, i); cout << "[Ukrainiah]";
		i++;
		move.Gotoxy(2, i); cout << "[Italiah]";
		i++;
		move.Gotoxy(2, i); cout << "[Spanish]";
		i++;
		move.Gotoxy(2, i); cout << "[French]";
		i++;
		move.Gotoxy(2, i); cout << "[Germah]";
		i++;
		move.Gotoxy(); cout << "->";

		string go_to = move.CatchMove();
		system("cls");

		if (go_to == "enter")
		{
			ext = true;
			switch (i)
			{
			case 1: // English
				language = "English";
			case 2:  // Ukrainian
				language = "Ukrainian";
			case 3:  // Italian
				language = "Italian";
			case 4:  // Spanish 
				language = "Spanish";
			case 5:  // French
				language = "French";
			case 6:  // German
				language = "German";
			}

			MakeLanguage(language);
		}
		else if (go_to == "down")
		{
			move.Y == i - 1 ? move.Y = min : move.Y++;
		}
		else if (go_to == "up")
		{
			move.Y == min ? move.Y = i - 1 : move.Y--;
		}
	}
}

bool Book::Fill()
{
	try
	{
		bool ext = false;

		cout << "Book title: "; getline(cin, title);
		cout << "Author's name: "; getline(cin, author);
		cout << "Enter book discription: "; getline(cin, discription);

		while (!ext)
		{
			system("cls");
			cout << "Age rating:   +\r";
			cout << "Age rating: ";

			if (!(cin >> ageRating))
			{
				cin.clear(); // Clear errors
				cin.ignore(10000, '\n'); // Crear buffer
				cout << "Age rating must be a number! Incorrect argument!" << endl;
				system("pause");
			}
			else
			{
				if (ageRating < 0 || ageRating > 21)
				{
					cout << "Incorrect age rating!" << endl;
					system("pause");
				}
				else
				{
					ext = true;
				}
			}
		}
		ext = false;

		while (!ext)
		{
			system("cls");
			cout << "The year the book was written (number): ";

			if (!(cin >> year))
			{
				cin.clear(); // Clear errors
				cin.ignore(10000, '\n'); // Crear buffer
				cout << "Year must be a number! Incorrect argument!" << endl;
				system("pause");
			}
			else
			{
				if (year <= 0 || year > 2023)
				{
					cout << "Incorrect year!" << endl;
					system("pause");
				}
				else
				{
					ext = true;
				}
			}
		}
		ext = false;

		cout << "Book description: "; getline(cin, this->discription);

		while (!ext)
		{
			system("cls");
			cout << "Book price (number): ";

			if (!(cin >> price))
			{
				cin.clear(); // Clear errors
				cin.ignore(10000, '\n'); // Crear buffer
				cout << "Price must be a number! Incorrect argument!" << endl;
				system("pause");
			}
			else
			{
				if (price <= 0)
				{
					cout << "Incorrect price!" << endl;
					system("pause");
				}
				else
				{
					ext = true;
				}
			}
		}
		ext = false;

		system("cls");
		Move move(2, 1);

		PrintAndSetLanguage("Coose book language");

		int max = 17;
		vector<int> genres_of_this_book;
		while (!ext)
		{
			system("cls");
			cout << "Select the genres of this book: ";

			PrintAllGenres(3, 1);
			if (!genres_of_this_book.empty())
			{
				move.PrintByCoord(2, genres_of_this_book, '+');
			}
			move.Gotoxy(0, move.Y); cout << "->";
			move.Gotoxy(3, 1); cout << "[Finish]";

			string user_move = move.CatchMove();

			if (user_move == "enter")
			{
				switch (move.Y)
				{
				case 1:
					if (!genres_of_this_book.empty()) { ext = true; }
					else { cout << "A book should have at least one genre!" << endl; }
					break;
				case 2:
					if (move.IsUnique(genres_of_this_book, 2)) { genres_of_this_book.push_back(2); }
					else { DeleteValue(genres_of_this_book, 2); }
					break;
				case 3:
					if (move.IsUnique(genres_of_this_book, 3)) { genres_of_this_book.push_back(3); }
					else { DeleteValue(genres_of_this_book, 3); }
					break;
				case 4:
					if (move.IsUnique(genres_of_this_book, 4)) { genres_of_this_book.push_back(4); }
					else { DeleteValue(genres_of_this_book, 4); }
					break;
				case 5:
					if (move.IsUnique(genres_of_this_book, 5)) { genres_of_this_book.push_back(5); }
					else { DeleteValue(genres_of_this_book, 5); }
					break;
				case 6:
					if (move.IsUnique(genres_of_this_book, 6)) { genres_of_this_book.push_back(6); }
					else { DeleteValue(genres_of_this_book, 6); }
					break;
				case 7:
					if (move.IsUnique(genres_of_this_book, 7)) { genres_of_this_book.push_back(7); }
					else { DeleteValue(genres_of_this_book, 7); }
					break;
				case 8:
					if (move.IsUnique(genres_of_this_book, 8)) { genres_of_this_book.push_back(8); }
					else { DeleteValue(genres_of_this_book, 8); }
					break;
				case 9:
					if (move.IsUnique(genres_of_this_book, 9)) { genres_of_this_book.push_back(9); }
					else { DeleteValue(genres_of_this_book, 9); }
					break;
				case 10:
					if (move.IsUnique(genres_of_this_book, 10)) { genres_of_this_book.push_back(10); }
					else { DeleteValue(genres_of_this_book, 10); }
					break;
				case 11:
					if (move.IsUnique(genres_of_this_book, 11)) { genres_of_this_book.push_back(11); }
					else { DeleteValue(genres_of_this_book, 11); }
					break;
				case 12:
					if (move.IsUnique(genres_of_this_book, 12)) { genres_of_this_book.push_back(12); }
					else { DeleteValue(genres_of_this_book, 12); }
					break;
				case 13:
					if (move.IsUnique(genres_of_this_book, 13)) { genres_of_this_book.push_back(13); }
					else { DeleteValue(genres_of_this_book, 13); }
					break;
				case 14:
					if (move.IsUnique(genres_of_this_book, 14)) { genres_of_this_book.push_back(14); }
					else { DeleteValue(genres_of_this_book, 14); }
					break;
				case 15:
					if (move.IsUnique(genres_of_this_book, 15)) { genres_of_this_book.push_back(15); }
					else { DeleteValue(genres_of_this_book, 15); }
					break;
				case 16:
					if (move.IsUnique(genres_of_this_book, 16)) { genres_of_this_book.push_back(16); }
					else { DeleteValue(genres_of_this_book, 16); }
					break;
				case 17:
					if (move.IsUnique(genres_of_this_book, 17)) { genres_of_this_book.push_back(17); }
					else { DeleteValue(genres_of_this_book, 17); }
					break;
				case 18:
					if (move.IsUnique(genres_of_this_book, 18)) { genres_of_this_book.push_back(18); }
					else { DeleteValue(genres_of_this_book, 18); }
					break;
				}
			}
			else if (user_move == "down")
			{
				move.Y == max ? move.Y = 1 : move.Y++;
			}
			else if (user_move == "up")
			{
				move.Y == 1 ? move.Y = max : move.Y--;
			}
			system("cls");
		}

		for (int i = 0; i < genres_of_this_book.size(); i++)
		{
			genres_of_this_book[i] -= 2;
		}
		genres = MakeGenres(genres_of_this_book);

		id = idCounter;
		idCounter++;

		return true;
	}
	catch (const exception&)
	{
		cout << "An error appeared during the filling process!" << endl;
		return false;
	}
}