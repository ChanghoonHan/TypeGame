#pragma once
#include "Word.h"
class HealWord :
	public Word
{
	virtual ITEM CheckCorrect(char* answer);
	virtual void PrintWord();

public:
	HealWord();
	virtual ~HealWord();
};

