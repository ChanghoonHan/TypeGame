#pragma once
#include "Scene.h"
#include "RankData.h"

class RankScene :
	public Scene
{
	RankData m_rankData;
	
public:
	virtual int OperatorInput();
	virtual void Output();
	virtual void Draw();
	virtual void Update();

	RankScene();
	virtual ~RankScene();
};

