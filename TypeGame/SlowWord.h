#pragma once
#include "Word.h"
class SlowWord :
	public Word
{
public:
	virtual ITEM CheckCorrect(char* answer);
	virtual void PrintWord();

	SlowWord();
	virtual ~SlowWord();
};

