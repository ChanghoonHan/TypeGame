#include "Scene.h"

void Scene::PrintAnswerBox()
{
	GoToXY(WIDTH / 2 - 9, HEIGHT - 7);
	cout << "忙式式式式式式式式式式式式式式式式忖";
	GoToXY(WIDTH / 2 - 9, HEIGHT - 6);
	cout << "弛";
	GoToXY(WIDTH / 2 + 8, HEIGHT - 6);
	cout << "弛";
	GoToXY(WIDTH / 2 - 9, HEIGHT - 5);
	cout << "戌式式式式式式式式式式式式式式式式戎";
}

void Scene::PrintGameMap()
{
	system("cls");

	GoToXY(0, 0);
	cout << "嬴檜蠱 : ";
	GoToXY(WIDTH / 2 - 16, 0);
	cout << "Score : " << 0 << "\t\tLevel : " << 1;

	for (size_t j = 0; j < WIDTH; j += 2)
	{
		GoToXY(j, 1);
		cout << "﹥";
	}

	for (size_t i = HEIGHT - 4; i < 40; i++)
	{
		GoToXY(WIDTH / 2 - 2, i);
		cout << "ⅥⅥⅥ";
	}

	PrintAnswerBox();
}

Scene::Scene()
{
}

Scene::~Scene()
{
}
