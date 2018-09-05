#pragma once
#include "Scene.h"
class TitleScene : public Scene
{	
	bool m_isSceneModify;

public:
	virtual int OperatorInput();
	virtual void Output();
	virtual void Draw();
	virtual void Update();

	TitleScene();
	virtual ~TitleScene();
};

