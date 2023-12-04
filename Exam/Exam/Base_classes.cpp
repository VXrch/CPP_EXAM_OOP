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
			genre = GetGenreByNumber(genres[i]);
			cout << genre << endl;
		}
	}
}
string Book::GetGenreByNumber(int number) const
{
	switch (number)
	{
	case Fantasy: return "Fantasy";
	case ScienceFiction: return "Science Fiction";
	case Dystopian: return "Dystopian";
	case Action: return "Action";
	case Mystery: return "Mystery";
	case Horror: return "Horror";
	case Thriller: return "Thriller";
	case HistoricalFiction: return "Historical Fiction";
	case Romance: return "Romance";
	case ContemporaryFiction: return "Contemporary Fiction";
	case MagicalRealism: return "Magical Realism";
	case GraphicNovel: return "Graphic Novel";
	case Memoir: return "Memoir";
	case Biography: return "Biography";
	case Travel: return "Travel";
	case TrueCrime: return "TrueCrime";
	case Humor: return "Humor";
	default: return "None";
	}
}