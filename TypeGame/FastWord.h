#pragma once
#include "Word.h"

class FastWord :
	public Word
{
	virtual ITEM CheckCorrect(char* answer);
	virtual void PrintWord();
public:
	FastWord();
	virtual ~FastWord();
};

