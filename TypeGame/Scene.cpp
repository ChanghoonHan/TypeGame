#include "Scene.h"

void Scene::PrintAnswerBox()
{
	GoToXY(WIDTH / 2 - 9, HEIGHT - 7);
	cout << "������������������������������������";
	GoToXY(WIDTH / 2 - 9, HEIGHT - 6);
	cout << "��";
	GoToXY(WIDTH / 2 + 8, HEIGHT - 6);
	cout << "��";
	GoToXY(WIDTH / 2 - 9, HEIGHT - 5);
	cout << "������������������������������������";
}

void Scene::PrintGameMap()
{
	system("cls");

	GoToXY(0, 0);
	cout << "������ : ";
	GoToXY(WIDTH / 2 - 16, 0);
	cout << "Score : " << 0 << "\t\tLevel : " << 1;

	for (size_t j = 0; j < WIDTH; j += 2)
	{
		GoToXY(j, 1);
		cout << "��";
	}

	for (size_t i = HEIGHT - 4; i < 40; i++)
	{
		GoToXY(WIDTH / 2 - 2, i);
		cout << "������";
	}

	PrintAnswerBox();
}

Scene::Scene()
{
}

Scene::~Scene()
{
}
