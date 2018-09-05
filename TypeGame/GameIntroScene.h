#pragma once
#include "Scene.h"
class GameIntroScene :
	public Scene
{
	char buf[256];
	char story[30][256];

	void DeleteIntro();
	void GetOneLineFromFile(FILE* file);
	void PrintGameIntro();
public:
	virtual int OperatorInput();
	virtual void Output();
	virtual void Draw();
	virtual void Update();

	GameIntroScene();
	virtual ~GameIntroScene();
};

