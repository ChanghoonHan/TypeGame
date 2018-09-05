#include "User.h"

void User::Init()
{
	m_life = 12;
}

RankInfo User::GetRankInfo()
{
	RankInfo rank;
	rank.date = GetLocalDate();
	rank.level = m_level;
	strcpy(rank.name, m_name);
	rank.score = m_score;

	return rank;
}

void User::SaveGameResult(int score, int level)
{
	system("cls");
	GoToXY(WIDTH / 2 - 25, HEIGHT / 2);
	cout << "게임종료!!! 사용자의 이름을 입력하세요 : ";
	cin >> m_name;
	m_score = score;
	m_level = level;
	m_date = GetLocalDate();
}

void User::PrintHeart()
{
	int demage = 12 - m_life;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			GoToXY(m_heartPos.x + (j * 2), m_heartPos.y + i);
			if (demage-- > 0)
			{
				cout << "□";
			}
			else
			{
				cout << "♥";
			}
		}
	}
}

void User::MinusHeart()
{
	m_life--;
	PrintHeart();
}

bool User::IsDead()
{
	if (m_life == 0)
	{
		return true;
	}

	return false;
}

void User::PlusHeart()
{
	if (m_life < 12)
	{
		m_life++;
		PrintHeart();
	}
}

User::User()
{
	m_life = 12;
	m_heartPos.x = WIDTH / 2 - 2;
	m_heartPos.y = HEIGHT - 4;
}

User::~User()
{
}
