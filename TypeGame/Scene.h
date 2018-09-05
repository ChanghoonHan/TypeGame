#pragma once
#include "BasicFunc.h"
#include "RankData.h"

using namespace std;

class Scene
{
protected:
	static RankData* m_rankDataPtr;
	static bool m_isSceneChange;
	static int m_numForSelMenu;

	void PrintGameMap();
	void PrintAnswerBox();

public:
	virtual int OperatorInput() = 0;
	virtual void Output() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;

	Scene();
	virtual ~Scene();
};

