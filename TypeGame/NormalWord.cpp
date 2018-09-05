#include "NormalWord.h"

ITEM NormalWord::CheckCorrect(char* answer)
{
	if (!strcmp(m_thisWord, answer))
	{
		EraseWord();
		return NORMAL;
	}

	return NOTCORRECT;
}

void NormalWord::PrintWord()
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
		cout << m_thisWord;
	}
}

NormalWord::NormalWord()
{
	int probItemWord = rand() % 100;
	strcpy(m_thisWord, m_word[probItemWord]);
	m_thisWordPos.x = rand() % (WIDTH - 16) + 2;
	m_thisWordPos.y = 1;
}


NormalWord::~NormalWord()
{
}
