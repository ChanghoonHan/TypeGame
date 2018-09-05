#pragma once
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <time.h>

using namespace std;

//#define SAFE_DELETE(a) if((a) != NULL) delete (a); (a)= NULL;

#define HEIGHT 40
#define WIDTH 120

struct MyPoint
{
	int x;
	int y;
};

struct RankInfo
{
	char name[256];
	int level;
	int score;
	int date;
};

enum ITEM
{
	FAST,
	SLOW,
	STOP,
	HIDE,
	CLEAR,
	HEAL,
	NORMAL,
	NOTCORRECT
};

int GetLocalDate();
void GoToXY(int x, int y);
void SetColor(int color);