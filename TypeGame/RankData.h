#pragma once
#include "BasicFunc.h"

class RankData
{
	int m_rankCount;
	RankInfo m_rank[10];

public:
	void PrintRank();
	void InputNewRank(RankInfo rank);
	void SaveRankToFile();
	void LoadRankFromFile();
	RankData();
	~RankData();
};

