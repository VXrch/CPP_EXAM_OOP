#pragma once


struct Move
{
	int X;
	int Y;

	Move() : X(0), Y(0) {}
	Move(int X, int Y) : X(0), Y(0) {}

	void Gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	string CatchMove()
	{
		int key = _getch();

		if (key == 13) // Enter
		{
			return "enter";
		}
		else if (key == 87 || key == 119) // [W / w] [up]
		{
			return "up";
		}
		else if (key == 83 || key == 115) // [S / s] [down]
		{

		}
		else if (key == 224)
		{
			key = _getch();

			if (key == 72) // up
			{

			}
			else if (key == 80) // down
			{

			}
		}
	}

	void operator++()
	{
		Y++;
	}
};
