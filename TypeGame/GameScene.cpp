#include "GameScene.h"

bool Word::m_hide = false;
bool Word::m_stop = false;
char Word::m_word[100][256] = { "" };

void GameScene::InstantiateWord()
{
	if (!Word::IsStop())
	{
		int probWord = rand() % 18;

		if (++m_wordCount == 40)
		{
			m_wordCount = 0;
		}

		switch (probWord)
		{
		case FAST:
			m_wordList[m_wordCount] = new FastWord;
			break;
		case SLOW:
			m_wordList[m_wordCount] = new SlowWord;
			break;
		case STOP:
			m_wordList[m_wordCount] = new StopWord;
			break;
		case HIDE:
			m_wordList[m_wordCount] = new HideWord;
			break;
		case CLEAR:
			m_wordList[m_wordCount] = new ClearWord;
			break;
		case HEAL:
			m_wordList[m_wordCount] = new HealWord;
			break;
		default:
			m_wordList[m_wordCount] = new NormalWord;
			break;
		}
	}
}

void GameScene::UseItem(ITEM item)
{
	switch (item)
	{
	case FAST:
		m_speedCount = 0;
		m_wordSpeed -= 15;
		break;
	case SLOW:
		m_speedCount = 0;
		m_wordSpeed += 15;
		break;
	case STOP:
		m_stopCount = 0;
		break;
	case HIDE:
		m_hideCount = 0;
		break;
	case CLEAR:
		m_CHCount = 0;
		InitWordList();
		break;
	case HEAL:
		m_CHCount = 0;
		m_user.PlusHeart();
		break;
	default:
		
		break;
	}

	PrintItemEffectName(item);
}

int GameScene::OperatorInput()
{
	if (m_isGameOver)
	{
		m_isGameOver = false;
		return 2;//랭크씬으로..
	}

	char buf;

	if (kbhit())
	{
		m_isSceneModify = true;

		buf = getch();

		if (buf == 13)
		{
			m_answer[m_answerlen] = '\0';
			PrintAnswerBox();
			m_answerlen = 0;

			for (size_t i = 0; i < 40; i++)
			{
				if (m_wordList[i] != NULL)//살아있는 단어인가
				{
					ITEM item = m_wordList[i]->CheckCorrect(m_answer);
					if (item != NOTCORRECT)//단어와 입력값이 일치하는가
					{
						UseItem(item);
						//////아이템사용하기

						m_score += m_wordList[i]->GetScore();
						delete(m_wordList[i]);//단어제거
						m_wordList[i] = NULL;
						
						if (m_score >= 50 * m_level)//스코어가 50점씩 증가할 때 레밸 증가
						{
							m_level++;
							m_baseSpeed -= 1;
							if (m_levelBetweenWord > 2)
							{
								m_levelBetweenWord--;
							}
						}
					}
				}
			}

			m_answer[0] = '\0';
		}
		else if (buf == 8)
		{
			if (m_answerlen != 0)
			{
				m_answerlen--;
				m_answer[m_answerlen] = '\0';
			}
		}
		else
		{
			if (m_answerlen < 15)
			{
				m_answer[m_answerlen] = buf;
				m_answer[m_answerlen + 1] = '\0';
				m_answerlen++;
			}
		}
		return 4;
	}

	return 4;
}

void GameScene::Output()
{

}

void GameScene::InitWordList()
{
	for (size_t i = 0; i < 40; i++)
	{
		if (m_wordList[i] != NULL)
		{
			delete(m_wordList[i]);
			m_wordList[i] = NULL;
		}
	}
}

void GameScene::InitGameScene()
{
	m_frame = 0;
	m_score = 0;
	m_level = 1;
	m_answerlen = 0;
	m_baseSpeed = 30;
	m_wordSpeed = m_baseSpeed;
	m_levelBetweenWord = 8;
	m_betweenWord = m_levelBetweenWord;
	m_isUserLifeChage = false;
	m_isGameOver = false;
	m_wordCount = 0;
	m_answer[0] = '\0';
	m_isSceneModify = true;
	memset(m_wordList, NULL, sizeof(Word*) * 40);

	m_hideCount = 3;
	m_stopCount = 3;
	m_CHCount = 3;
	m_speedCount = 10;

	Word::setWordFromFile();
}

void GameScene::Update()
{	
	m_frame++;
	if (m_frame >= m_wordSpeed)
	{
		if (m_betweenWord >= m_levelBetweenWord)
		{
			m_betweenWord = 0;

			InstantiateWord();
		}

		m_frame = 0;

		for (size_t i = 0; i < 40; i++)
		{
			if (m_wordList[i] != NULL)
			{
				if (!m_wordList[i]->DropWord())
				{
					delete(m_wordList[i]);//단어제거
					m_wordList[i] = NULL;
					m_user.MinusHeart();
					if (m_user.IsDead())
					{
						m_isGameOver = true;
						m_user.SaveGameResult(m_score, m_level);
						InitWordList();
						m_isSceneChange = true;
						m_rankDataPtr->InputNewRank(m_user.GetRankInfo());
						m_rankDataPtr->SaveRankToFile();
						return;
					}
				}
			}
		}

		m_hideCount++;
		m_stopCount++;
		m_speedCount++;
		m_CHCount++;
		m_betweenWord++;

		if (m_hideCount == 3)
		{
			Word::UnHide();
			PrintItemEffectName(NORMAL);
		}

		if (m_CHCount == 3)
		{
			PrintItemEffectName(NORMAL);
		}

		if (m_stopCount == 3)
		{
			Word::UnStop();
			PrintItemEffectName(NORMAL);
		}

		if (m_speedCount == 10)
		{
			m_wordSpeed = m_baseSpeed;
			PrintItemEffectName(NORMAL);
		}
	}

	if (m_isUserLifeChage)
	{
		m_user.PrintHeart();
		m_isUserLifeChage = false;
	}

	Sleep(1000 / 60);
}

void GameScene::Draw()
{
	if (m_isSceneChange)
	{
		InitGameScene();
		m_isSceneChange = false;
	}

	if(m_isSceneModify)
	{
		m_isSceneModify = false;
		GoToXY(WIDTH / 2 - 7, HEIGHT - 6);
		cout << "               ";
		GoToXY(WIDTH / 2 - 7, HEIGHT - 6);
		cout << m_answer;
		PrintAnswerBox();
		PrintScoreLevel();
	}
}

void GameScene::PrintScoreLevel()
{
	GoToXY(WIDTH / 2 - 8, 0);
	cout << m_score;
	GoToXY(WIDTH / 2 + 12, 0);
	cout << m_level;
}

void GameScene::PrintItemEffectName(ITEM item)
{
	GoToXY(10, 0);
	cout << "        ";
	GoToXY(10, 0);

	switch (item)
	{
	case FAST:
		cout << "FAST";
		break;
	case SLOW:
		cout << "SLOW";
		break;
	case STOP:
		cout << "STOP";
		break;
	case HIDE:
		cout << "HIDE";
		break;
	case CLEAR:
		cout << "CLEAR";
		break;
	case HEAL:
		cout << "HEAL";
		break;
	default:
		cout << "        ";
		break;
	}
}

GameScene::GameScene()
{
	InitGameScene();
}

GameScene::~GameScene()
{
}
