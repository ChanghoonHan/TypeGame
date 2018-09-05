#pragma once
#include "Word.h"
class StopWord :
	public Word
{
public:
	virtual ITEM CheckCorrect(char* answer);
	virtual void PrintWord();

	StopWord();
	~StopWord();
};

