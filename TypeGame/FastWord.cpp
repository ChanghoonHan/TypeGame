#include "FastWord.h"

ITEM FastWord::CheckCorrect(char* answer)
{
	if (!strcmp(m_thisWord, answer))
	{
		EraseWord();
		return FAST;
	}

	return NOTCORRECT;
}

void FastWord::PrintWord()
{
	GoToXY(m_thisWordPos.x, m_thisWordPos.y);
	if (m_hide)
	{
		for (size_t i = 0; i < strlen(m_thisWord); i++)
		{
			cout << "*";
		}
	}
	else
	{
		SetColor(12);
		cout << m_thisWord;
		SetColor(15);
	}
}

FastWord::FastWord()
{
	int probItemWord = rand() % 100;
	strcpy(m_thisWord, m_word[probItemWord]);
	m_thisWordPos.x = rand() % (WIDTH - 16) + 2;
	m_thisWordPos.y = 1;
}


FastWord::~FastWord()
{
}
