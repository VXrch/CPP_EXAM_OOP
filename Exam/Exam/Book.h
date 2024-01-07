#pragma once
#include "Move.h"

class Book
{
protected:

	enum Language { English, Ukrainian, Italian, Spanish, French, German };
	enum Genres { Fantasy, ScienceFiction, Dystopian, Action, Mystery, Horror, Thriller, HistoricalFiction, Romance, ContemporaryFiction, MagicalRealism, GraphicNovel, Memoir, Biography, Travel, TrueCrime, Humor };

	string title;
	string author;
	string discription;
	int ageRating;
	int year;
	float price;

	static unsigned int idCounter;
	unsigned int id;

	Language language;
	vector<Genres> genres;

	float sale;

private:

	vector<Genres> MakeGenres(vector<int> genres)
	{
		vector<Genres> new_genres;

		for (int i = 0; i < genres.size(); i++)
		{
			if (genres[i] == 0)
			{
				new_genres.push_back(Fantasy);
			}
			else if (genres[i] == 1)
			{
				new_genres.push_back(ScienceFiction);
			}
			else if (genres[i] == 2)
			{
				new_genres.push_back(Dystopian);
			}
			else if (genres[i] == 3)
			{
				new_genres.push_back(Action);
			}
			else if (genres[i] == 4)
			{
				new_genres.push_back(Mystery);
			}
			else if (genres[i] == 5)
			{
				new_genres.push_back(Horror);
			}
			else if (genres[i] == 6)
			{
				new_genres.push_back(Thriller);
			}
			else if (genres[i] == 7)
			{
				new_genres.push_back(HistoricalFiction);
			}
			else if (genres[i] == 8)
			{
				new_genres.push_back(Romance);
			}
			else if (genres[i] == 9)
			{
				new_genres.push_back(ContemporaryFiction);
			}
			else if (genres[i] == 10)
			{
				new_genres.push_back(MagicalRealism);
			}
			else if (genres[i] == 11)
			{
				new_genres.push_back(GraphicNovel);
			}
			else if (genres[i] == 12)
			{
				new_genres.push_back(Memoir);
			}
			else if (genres[i] == 13)
			{
				new_genres.push_back(Biography);
			}
			else if (genres[i] == 14)
			{
				new_genres.push_back(Travel);
			}
			else if (genres[i] == 15)
			{
				new_genres.push_back(TrueCrime);
			}
			else if (genres[i] == 16)
			{
				new_genres.push_back(Humor);
			}
		}
		return new_genres;
	}
	vector<Genres> MakeGenres(vector<string> genres)
	{
		vector<Genres> new_genres;

		for (int i = 0; i < genres.size(); i++)
		{
			if (genres[i] == "Fantasy")
			{
				new_genres.push_back(Fantasy);
			}
			else if (genres[i] == "ScienceFiction")
			{
				new_genres.push_back(ScienceFiction);
			}
			else if (genres[i] == "Dystopian")
			{
				new_genres.push_back(Dystopian);
			}
			else if (genres[i] == "Action")
			{
				new_genres.push_back(Action);
			}
			else if (genres[i] == "Mystery")
			{
				new_genres.push_back(Mystery);
			}
			else if (genres[i] == "Horror")
			{
				new_genres.push_back(Horror);
			}
			else if (genres[i] == "Thriller")
			{
				new_genres.push_back(Thriller);
			}
			else if (genres[i] == "HistoricalFiction")
			{
				new_genres.push_back(HistoricalFiction);
			}
			else if (genres[i] == "Romance")
			{
				new_genres.push_back(Romance);
			}
			else if (genres[i] == "ContemporaryFiction")
			{
				new_genres.push_back(ContemporaryFiction);
			}
			else if (genres[i] == "MagicalRealism")
			{
				new_genres.push_back(MagicalRealism);
			}
			else if (genres[i] == "GraphicNovel")
			{
				new_genres.push_back(GraphicNovel);
			}
			else if (genres[i] == "Memoir")
			{
				new_genres.push_back(Memoir);
			}
			else if (genres[i] == "Biography")
			{
				new_genres.push_back(Biography);
			}
			else if (genres[i] == "Travel")
			{
				new_genres.push_back(Travel);
			}
			else if (genres[i] == "TrueCrime")
			{
				new_genres.push_back(TrueCrime);
			}
			else if (genres[i] == "Humor")
			{
				new_genres.push_back(Humor);
			}
		}
		return new_genres;
	}
	void MakeLanguage(string language)
	{
		if (language == "English")
		{
			this->language = English;
		}
		else if (language == "Ukrainian")
		{
			this->language = Ukrainian;
		}
		else if (language == "Italian")
		{
			this->language = Italian;
		}
		else if (language == "Spanish")
		{
			this->language = Spanish;
		}
		else if (language == "French")
		{
			this->language = French;
		}
		else if (language == "German")
		{
			this->language = German;
		}
		else
		{
			this->language = English;
		}
	}

public:

	Book() : title(""), author(""), discription(""), ageRating(0), year(0), price(0), id(0), language(English), genres(), sale(0) {}
	bool Fill();

	Genres ToGenre(string genre)
	{
		if (genre == "Fantasy")
		{
			return Fantasy;
		}
		else if (genre == "ScienceFiction")
		{
			return ScienceFiction;
		}
		else if (genre == "Dystopian")
		{
			return Dystopian;
		}
		else if (genre == "Action")
		{
			return Action;
		}
		else if (genre == "Mystery")
		{
			return Mystery;
		}
		else if (genre == "Horror")
		{
			return Horror;
		}
		else if (genre == "Thriller")
		{
			return Thriller;
		}
		else if (genre == "HistoricalFiction")
		{
			return HistoricalFiction;
		}
		else if (genre == "Romance")
		{
			return Romance;
		}
		else if (genre == "ContemporaryFiction")
		{
			return ContemporaryFiction;
		}
		else if (genre == "MagicalRealism")
		{
			return MagicalRealism;
		}
		else if (genre == "GraphicNovel")
		{
			return GraphicNovel;
		}
		else if (genre == "Memoir")
		{
			return Memoir;
		}
		else if (genre == "Biography")
		{
			return Biography;
		}
		else if (genre == "Travel")
		{
			return Travel;
		}
		else if (genre == "TrueCrime")
		{
			return TrueCrime;
		}
		else if (genre == "Humor")
		{
			return Humor;
		}
	}
	Language ToLanguage(string language)
	{
		if (language == "English")
		{
			return English;
		}
		else if (language == "Ukrainian")
		{
			return Ukrainian;
		}
		else if (language == "Italian")
		{
			return Italian;
		}
		else if (language == "Spanish")
		{
			return Spanish;
		}
		else if (language == "French")
		{
			return French;
		}
		else if (language == "German")
		{
			return German;
		}
		else
		{
			return English;
		}
	}

	template <typename T>
	void DeleteValue(vector<T>& delete_from, T value_to_delete)
	{
		for (auto it = delete_from.begin(); it != delete_from.end(); ) 
		{
			if (*it == value_to_delete) 
			{
				it = delete_from.erase(it);
			}
			else 
			{
				++it;
			}
		}
	}

	void Print() const;
	void PrintMinInfo() const;
	void PrintShortInfo() const;
	void PrintAllGenres() const;
	void PrintAllGenres(int X, int Y) const;
	void PrintAndSetLanguage(string title_to_set);

	string GetLanguage() const;
	string GetGenre(int number) const;
	int GetGenresSize() const
	{
		return genres.size();
	}
	vector<Genres> GetAllGenres() const
	{
		return genres;
	}
	vector<string> GetAllGenres_string() const
	{
		vector<string> string_genres;

		for (int i = 0; i < genres.size(); i++)
		{
			switch (genres[i])
			{
			case Book::Fantasy: string_genres.push_back("Fantasy"); break;
			case Book::ScienceFiction:string_genres.push_back("ScienceFiction"); break;
			case Book::Dystopian:string_genres.push_back("Dystopian"); break;
			case Book::Action:string_genres.push_back("Action"); break;
			case Book::Mystery:string_genres.push_back("Mystery"); break;
			case Book::Horror:string_genres.push_back("Horror"); break;
			case Book::Thriller:string_genres.push_back("Thriller"); break;
			case Book::HistoricalFiction:string_genres.push_back("HistoricalFiction"); break;
			case Book::Romance:string_genres.push_back("Romance"); break;
			case Book::ContemporaryFiction:string_genres.push_back("ContemporaryFiction"); break;
			case Book::MagicalRealism:string_genres.push_back("MagicalRealism"); break;
			case Book::GraphicNovel:string_genres.push_back("GraphicNovel"); break;
			case Book::Memoir:string_genres.push_back("Memoir"); break;
			case Book::Biography:string_genres.push_back("Biography"); break;
			case Book::Travel:string_genres.push_back("Travel"); break;
			case Book::TrueCrime:string_genres.push_back("TrueCrime"); break;
			case Book::Humor:string_genres.push_back("Humor"); break;
			}
		}
		return string_genres;
	}

	bool IsUnique(vector<Book> search_in, Book value) const
	{
		for (int i = 0; i < search_in.size(); i++)
		{
			if (value == search_in[i])
			{
				return false;
			}
		}
		return true;
	}

	int GetYear() const
	{
		return year;
	}
	float GetSale() const
	{
		return sale;
	}
	float GetPrice() const
	{
		return price;
	}
	string GetTitle() const
	{
		return title;
	}
	string GetAuthor() const
	{
		return author;
	}
	unsigned int GetID() const
	{
		return id;
	}
	int GetAgeRating() const
	{
		return ageRating;
	}

protected:

	Book(string title, string author, string discription, int year, int ageRating, float price, Language language, vector<Genres> genres, float* sale) : title(title), author(author), discription(discription), year(year), ageRating(ageRating), price(price), language(language), genres(), sale(0)
	{
		id = idCounter;
		idCounter++;
	}

	void SetYear(int year)
	{
		this->year = year;
	}
	void SetSale(float sale)
	{
		this->sale = sale;
	}
	void SetPrice(float price)
	{
		this->price = price;
	}
	void SetTitle(string title)
	{
		this->title = title;
	}
	void SetGenres(Genres genre)
	{
		this->genres.push_back(genre);
	}
	void SetAuthor(string author)
	{
		this->author = author;
	}
	void SetAgeRating(int ageRating)
	{
		this->ageRating = ageRating;
	}
	void SetLanguage(Language language)
	{
		this->language = language;
	}

	void ChangeLanguage()
	{
		Move move(2, 2);
		bool ext = false;

		int i = 0, min = 1;

		while (!ext)
		{
			system("cls");
			i = 0;

			move.Gotoxy(0, i); cout << "-*-*-*-*-*-*-*-*-+| Set new language |+-*-*-*-*-*-*-*-*-";
			i++;
			move.Gotoxy(2, i); cout << "[English] ";
			i++;
			move.Gotoxy(2, i); cout << "[Ukrainiah] ";
			i++;
			move.Gotoxy(2, i); cout << "[Italiah] ";
			i++;
			move.Gotoxy(2, i); cout << "[Spanish] ";
			i++;
			move.Gotoxy(2, i); cout << "[French] ";
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
					language = English; break;
				case 2:  // Ukrainian
					language = Ukrainian; break;
				case 3:  // Italian
					language = Italian; break;
				case 4:  // Spanish
					language = Spanish; break;
				case 5:  // French
					language = French; break;
				case 6:  // German
					language = German; break;
				}
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

	bool operator==(Book temp)
	{
		if (this->author == temp.author && this->title == temp.title && this->id == temp.id && this->discription == temp.discription && this->sale == temp.sale && this->price == temp.price)
		{
			return true;
		}
		return false;
	}

	friend class Admin;
	friend struct Order;
	friend class FilesWork;
};
