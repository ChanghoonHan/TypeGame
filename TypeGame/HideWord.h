#pragma once
#include "Word.h"
class HideWord :
	public Word
{
public:
	virtual ITEM CheckCorrect(char* answer);
	virtual void PrintWord();

	HideWord();
	virtual ~HideWord();
};

