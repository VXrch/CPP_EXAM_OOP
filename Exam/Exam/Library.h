#pragma once


class Library
{
	struct Pair // How many the same books
	{
		Book book;
		int counter;
	};

	list<Pair> books;
};
