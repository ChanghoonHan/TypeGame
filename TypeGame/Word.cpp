#include "Word.h"

bool Word::IsStop()
{
	return m_stop;
}

bool Word::CanDropWord()
{
	if ((m_thisWordPos.x > (WIDTH / 2 - 11) && m_thisWordPos.x < (WIDTH / 2 + 11)) ||
		((m_thisWordPos.x + strlen(m_thisWord)) >(WIDTH / 2 - 10)) && (m_thisWordPos.x < (WIDTH / 2 - 10)))
	{
		if (m_thisWordPos.y + 1 == HEIGHT - 7)
		{
			return false;
		}
	}

	if (m_thisWordPos.y + 1 == HEIGHT)
	{
		return false;
	}

	return true;
}

bool Word::DropWord()
{
	if (CanDropWord())
	{
		if (m_thisWordPos.y != 1)
		{
			EraseWord();
		}

		if (!m_stop)
		{
			m_thisWordPos.y++;
		}

		PrintWord();
		return true;
	}

	EraseWord();
	return false;
}

void Word::EraseWord()
{
	GoToXY(m_thisWordPos.x, m_thisWordPos.y);
	for (size_t i = 0; i < strlen(m_thisWord); i++)
	{
		cout << " ";
	}
}

int Word::GetScore()
{
	return strlen(m_thisWord);
}

void Word::UnHide()
{
	m_hide = false;
}

void Word::UnStop()
{
	m_stop = false;
}

void Word::setWordFromFile()
{
	FILE* file = fopen("word.txt", "r");

	if (file == NULL)
	{
		return;
	}

	for (size_t i = 0; i < 100; i++)
	{
		char buf[256];
		fscanf(file, "%s", buf);
		strcpy(m_word[i], buf);
	}

	fclose(file);
}

Word::Word()
{
}


Word::~Word()
{
}
