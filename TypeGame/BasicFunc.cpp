#include "basicFunc.h"
#include <conio.h>
#include <Windows.h>

int GetLocalDate()
{
	int date;
	struct tm *t;
	time_t timer;

	timer = time(NULL);
	t = localtime(&timer);
	date = (t->tm_year + 1900) * 10000 + (t->tm_mon + 1) * 100 + t->tm_mday;

	return date;
}

void GoToXY(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}