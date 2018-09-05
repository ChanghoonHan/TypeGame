#pragma once
#include "Word.h"
class ClearWord :
	public Word
{
public:
	virtual ITEM CheckCorrect(char* answer);
	virtual void PrintWord();

	ClearWord();
	virtual ~ClearWord();
};

