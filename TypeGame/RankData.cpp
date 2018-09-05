#include "RankData.h"

void RankData::PrintRank()
{
	for (size_t i = 0; i < m_rankCount; i++)
	{
		GoToXY(WIDTH / 2 - 25, HEIGHT / 2 - 5 + i);
		cout << i + 1 << "\t" << m_rank[i].name << "\t\t" << m_rank[i].level
			<< "\t" << m_rank[i].score << "\t" << m_rank[i].date;
	}

	return;
}

void RankData::SaveRankToFile()
{
	FILE* file = fopen("rank.txt", "w");
	fprintf(file, "%d ", m_rankCount);

	for (size_t i = 0; i < m_rankCount; i++)
	{
		fprintf(file, "%s %d %d %d", m_rank[i].name, m_rank[i].level, m_rank[i].score, m_rank[i].date);
	}

	fclose(file);
	return;
}

void RankData::LoadRankFromFile()
{
	FILE* file = fopen("rank.txt", "r");
	if (file == NULL)
	{
		return;
	}

	fscanf(file, "%d ", &m_rankCount);

	for (size_t i = 0; i < m_rankCount; i++)
	{
		fscanf(file, "%s %d %d %d ", m_rank[i].name, &m_rank[i].level, &m_rank[i].score, &m_rank[i].date);
	}

	fclose(file);
	return;
}

void RankData::InputNewRank(RankInfo rank)
{
	RankInfo temp;

	if (m_rankCount == 0) {
		m_rank[m_rankCount++] = rank;
		return;
	}

	if (m_rankCount < 10) {
		for (size_t i = 0; i < m_rankCount; i++)
		{
			if (m_rank[i].score <= rank.score)
			{
				for (size_t j = m_rankCount; j > i; j--)
				{
					m_rank[j] = m_rank[j - 1];
				}
				m_rank[i] = rank;
				m_rankCount++;
				return;
			}
		}
		return;
	}

	for (size_t i = 0; i < 10; i++)
	{
		if (m_rank[i].score <= rank.score)
		{
			for (size_t j = 9; j > i; j--)
			{
				m_rank[j] = m_rank[j - 1];
			}
			m_rank[i] = rank;
			return;
		}
	}

	return;
}

RankData::RankData()
{
	m_rankCount = 0;
}


RankData::~RankData()
{
}
