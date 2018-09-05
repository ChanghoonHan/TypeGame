#pragma once
#include "basicFunc.h"

class User
{
	char m_name[256];
	MyPoint m_heartPos;
	int m_life;
	int m_score;
	int m_level;
	int m_date;

public:
	RankInfo GetRankInfo();
	void Init();
	void MinusHeart();
	void PlusHeart();
	void PrintHeart();
	bool IsDead();
	void SaveGameResult(int score, int level);

	User();
	~User();
};