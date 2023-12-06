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
	cout << "Title: " << title << endl;
	cout << "author: " << author << endl;
	cout << "discription: " << discription << endl;
	cout << "year: " << year << endl;
	cout << "price: " << price << endl;
	cout << "language: " << language << endl;

	cout << "Genres: " << endl;
	if (genres.empty())
	{
		cout << "None" << endl;
	}
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
void Book::MinInfo() const
{
	cout << "Title: " << title << " | Author: " << author << " | Language: " << language << endl;
}
void Book::PrintAllGenres() const
{
	cout << "[Fantasy] ";
	cout << " [Science Fiction] ";
	cout << " [Dystopian] ";
	cout << " [Action] ";
	cout << " [Mystery] ";
	cout << " [Horror] ";
	cout << " [Thriller] ";
	cout << " [Historical Fiction] ";
	cout << " [Romance] ";
	cout << " [Contemporary Fiction] ";
	cout << " [Magical Realism] ";
	cout << " [Graphic Novel] ";
	cout << " [Memoir] ";
	cout << " [Biography] ";
	cout << " [Travel] ";
	cout << " [True Crime] ";
	cout << " [Humor]";
}
void Book::PrintShortInfo() const
{
	cout << "Title: " << title << endl;
	cout << "author: " << author << endl;
	cout << "language: " << language << endl;
}
void Book::PrintAllLanguages() const
{
	cout << "[English] ";
	cout << " [Ukrainiah] ";
	cout << " [Italiah] ";
	cout << " [Spanish] ";
	cout << " [French] ";
	cout << " [Germah]";
}
void Book::PrintAllGenres(int X = 1, int Y = 1) const
{
	Move move(X, Y);

	move.Gotoxy(X, Y); cout << "[Fantasy] "; Y++;
	move.Gotoxy(X, Y); cout << " [Science Fiction] "; Y++;
	move.Gotoxy(X, Y); cout << " [Dystopian] "; Y++;
	move.Gotoxy(X, Y); cout << " [Action] "; Y++;
	move.Gotoxy(X, Y); cout << " [Mystery] "; Y++;
	move.Gotoxy(X, Y); cout << " [Horror] "; Y++;
	move.Gotoxy(X, Y); cout << " [Thriller] "; Y++;
	move.Gotoxy(X, Y); cout << " [Historical Fiction] "; Y++;
	move.Gotoxy(X, Y); cout << " [Romance] "; Y++;
	move.Gotoxy(X, Y); cout << " [Contemporary Fiction] "; Y++;
	move.Gotoxy(X, Y); cout << " [Magical Realism] "; Y++;
	move.Gotoxy(X, Y); cout << " [Graphic Novel] "; Y++;
	move.Gotoxy(X, Y); cout << " [Memoir] "; Y++;
	move.Gotoxy(X, Y); cout << " [Biography] "; Y++;
	move.Gotoxy(X, Y); cout << " [Travel] "; Y++;
	move.Gotoxy(X, Y); cout << " [True Crime] "; Y++;
	move.Gotoxy(X, Y); cout << " [Humor]";
}
void Book::PrintAllLanguages(int X = 1, int Y = 1) const
{
	Move move(X, Y);

	move.Gotoxy(X, Y); cout << "[English] "; Y++;
	move.Gotoxy(X, Y); cout << " [Ukrainiah] "; Y++;
	move.Gotoxy(X, Y); cout << " [Italiah] "; Y++;
	move.Gotoxy(X, Y); cout << " [Spanish] "; Y++;
	move.Gotoxy(X, Y); cout << " [French] "; Y++;
	move.Gotoxy(X, Y); cout << " [Germah]"; Y++;
}

void Book::Fill()
{
	try
	{
		cout << "Book title: "; getline(cin, title);
		cout << "Author's name: "; getline(cin, author);
		cout << "Age rating (number): "; cin >> ageRating;
		cout << "The year the book was written (number): "; cin >> year;
		cout << "Book description: "; getline(cin, discription);
		cout << "Book price (number): "; cin >> price;
		cout << "\tOK!" << endl;
		system("pause");
		system("cls");

		Move move(2, 2);
		bool ext = false;

		while (!ext)
		{
			move.Gotoxy(2, 1); cout << "Coose book language: ";

			PrintAllLanguages(move.X, move.Y);
			move.Gotoxy(1, move.Y); cout << ">";
			string user_move = move.CatchMove();

			if (user_move == "enter")
			{
				ext = true;
				switch (move.Y)
				{
				case 2: // English
					language = English; break;
				case 3:  // Ukrainian
					language = Ukrainian; break;
				case 4:  // Italian
					language = Italian; break;
				case 5:  // Spanish
					language = Spanish; break;
				case 6:  // French
					language = French; break;
				case 7:  // German
					language = German; break;
				}
			}
			else if (user_move == "up")
			{
				move.Y == 2 ? move.Y = 7 : move.Y++;
			}
			else if (user_move == "down")
			{
				move.Y == 7 ? move.Y = 2 : move.Y--;
			}
		}

		cout << "Enter book's language: ";

		while (!ext)
		{
			PrintAllGenres(move.X, move.Y);
			move.Gotoxy(1, move.Y); cout << ">";
			move.Gotoxy(2, 19); cout << "Exit";
			string user_move = move.CatchMove();

			if (user_move == "enter")
			{
				ext = true;
				switch (move.Y)
				{
				case 2:
					if (IsUnique(Fantasy))
					{
						genres.push_back(Fantasy);
						Successed();
					}
					else { Fail(); }
					break;
				case 3:
					if (IsUnique(ScienceFiction))
					{
						genres.push_back(ScienceFiction);
						Successed();
					}
					else { Fail(); }
					break;
				case 4:
					if (IsUnique(Dystopian))
					{
						genres.push_back(Dystopian);
						Successed();
					}
					else { Fail(); }
					break;
				case 5:
					if (IsUnique(Action))
					{
						genres.push_back(Action);
						Successed();
					}
					else { Fail(); }
					break;
				case 6:
					if (IsUnique(Mystery))
					{
						genres.push_back(Mystery);
						Successed();
					}
					else { Fail(); }
					break;
				case 7:
					if (IsUnique(Horror))
					{
						genres.push_back(Horror);
						Successed();
					}
					else { Fail(); }
					break;
				case 8:
					if (IsUnique(Thriller))
					{
						genres.push_back(Thriller);
						Successed();
					}
					else { Fail(); }
					break;
				case 9:
					if (IsUnique(HistoricalFiction))
					{
						genres.push_back(HistoricalFiction);
						Successed();
					}
					else { Fail(); }
					break;
				case 10:
					if (IsUnique(Romance))
					{
						genres.push_back(Romance);
						Successed();
					}
					else { Fail(); }
					break;
				case 11:
					if (IsUnique(ContemporaryFiction))
					{
						genres.push_back(ContemporaryFiction);
						Successed();
					}
					else { Fail(); }
					break;
				case 12:
					if (IsUnique(MagicalRealism))
					{
						genres.push_back(MagicalRealism);
						Successed();
					}
					else { Fail(); }
					break;
				case 13:
					if (IsUnique(GraphicNovel))
					{
						genres.push_back(GraphicNovel);
						Successed();
					}
					else { Fail(); }
					break;
				case 14:
					if (IsUnique(Memoir))
					{
						genres.push_back(Memoir);
						Successed();
					}
					else { Fail(); }
					break;
				case 15:
					if (IsUnique(Biography))
					{
						genres.push_back(Biography);
						Successed();
					}
					else { Fail(); }
					break;
				case 16:
					if (IsUnique(Travel))
					{
						genres.push_back(Travel);
						Successed();
					}
					else { Fail(); }
					break;
				case 17:
					if (IsUnique(TrueCrime))
					{
						genres.push_back(TrueCrime);
						Successed();
					}
					else { Fail(); }
					break;
				case 18:
					if (IsUnique(Humor))
					{
						genres.push_back(Humor);
						Successed();
					}
					else { Fail(); }
					break;
				case 19:
					ext = true; break;
				}
			}
			else if (user_move == "up")
			{
				move.Y == 2 ? move.Y = 19 : move.Y++;
			}
			else if (user_move == "down")
			{
				move.Y == 19 ? move.Y = 2 : move.Y--;
			}
			system("cls");
		}

		id = idCounter;
		idCounter++;
	}
	catch (const exception&)
	{
		throw "Error";
	}
}