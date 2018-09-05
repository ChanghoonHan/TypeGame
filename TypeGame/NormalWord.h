#pragma once
#include "Word.h"
class NormalWord :
	public Word
{
public:
	virtual ITEM CheckCorrect(char* answer);
	virtual void PrintWord();

	NormalWord();
	virtual ~NormalWord();
};

