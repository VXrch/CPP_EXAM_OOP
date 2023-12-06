
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
