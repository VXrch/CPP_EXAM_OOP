# include "Base_classes.h"

using namespace std;

void Person::Print() const // basic info
{
	cout << "Name: " << name << endl;
	cout << "Surname " << surname << endl;
	cout << "Age: " << age << endl;
	cout << "Phone: " << phone << endl;
}
void Person::PrintSecretInfo() const // info to login
{
	cout << "Nickname: " << nickname << endl;
	cout << "Password: " << password << endl;
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
string Book::GetGenre(int i) const
{
	switch (genres[i])
	{
	case Fantasy: return "Fantasy";
	case ScienceFiction: return "ScienceFiction";
	case Dystopian: return "Dystopian";
	case Action: return "Action";
	case Mystery: return "Mystery";
	case Horror: return "Horror";
	case Thriller: return "Thriller";
	case HistoricalFiction: return "HistoricalFiction";
	case Romance: return "Romance";
	case ContemporaryFiction: return "ContemporaryFiction";
	case MagicalRealism: return "MagicalRealism";
	case GraphicNovel: return "GraphicNovel";
	case Memoir: return "Memoir";
	case Biography: return "Biography";
	case Travel: return "Travel";
	case TrueCrime: return "TrueCrime";
	case Humor: return "Humor";
	}
	return "";
}