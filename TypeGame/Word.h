#pragma once
#include "BasicFunc.h"

class Word
{
protected:
	char m_thisWord[256];
	MyPoint m_thisWordPos;

	static bool m_hide;
	static bool m_stop;
	static char m_word[100][256];

	bool CanDropWord();

public:
	bool DropWord();
	void EraseWord();
	int GetScore();
	
	virtual ITEM CheckCorrect(char* answer) = 0;
	virtual void PrintWord() = 0;

	static bool IsStop();
	static void UnHide();
	static void UnStop();
	static void setWordFromFile();
	
	Word();
	virtual ~Word();
};

