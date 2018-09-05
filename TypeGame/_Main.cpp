#include "BasicFunc.h"
#include "Scene.h"
#include "TitleScene.h"
#include "GameIntroScene.h"
#include "GameScene.h"
#include "RankScene.h"

int Scene::m_numForSelMenu = 0;
RankData* Scene::m_rankDataPtr = NULL;
bool Scene::m_isSceneChange = true;

int main()
{
	srand(time(NULL));
	system("mode con: cols=120 lines=40");

	Scene* scene[4] = { NULL, };
	TitleScene titleScene;
	GameIntroScene gameIntroScene;
	GameScene gameScene;
	RankScene rankScene;
	int sceneNum = 0;
	int newSceneNum = 0;
	
	scene[0] = &titleScene;
	scene[1] = &gameIntroScene;
	scene[2] = &rankScene;
	scene[3] = &gameScene;

	scene[sceneNum]->Draw();

	while (true)
	{
		newSceneNum = scene[sceneNum]->OperatorInput();
		
		if (newSceneNum == 3)
		{
			return 0;
		}

		if (newSceneNum > 3)
		{
			newSceneNum--;
		}

		sceneNum = newSceneNum;
		scene[sceneNum]->Draw();
		scene[sceneNum]->Update();
	}
}