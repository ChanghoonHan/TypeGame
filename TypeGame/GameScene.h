#pragma once
#include "Scene.h"
#include "User.h"
#include "Word.h"
#include "NormalWord.h"
#include "StopWord.h"
#include "SlowWord.h"
#include "FastWord.h"
#include "HideWord.h"
#include "HealWord.h"
#include "ClearWord.h"

class GameScene : public Scene
{
	int m_frame;
	int m_score;
	int m_level;
	int m_answerlen;
	int m_baseSpeed;
	int m_wordSpeed;
	int m_levelBetweenWord;
	int m_betweenWord;
	int m_wordCount;
	char m_answer[256];

	int m_hideCount;
	int m_stopCount;
	int m_speedCount;
	int m_CHCount;

	bool m_isGameOver;
	bool m_isSceneModify;
	bool m_isUserLifeChage;

	User m_user;
	Word* m_wordList[40];

	void PrintScoreLevel();
	void InstantiateWord();
	void PrintItemEffectName(ITEM item);
	void UseItem(ITEM item);
	void InitWordList();
	void InitGameScene();

public:
	virtual int OperatorInput();
	virtual void Output();
	virtual void Draw();
	virtual void Update();

	GameScene();
	virtual ~GameScene();
};

