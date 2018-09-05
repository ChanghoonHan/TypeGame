#include "GameIntroScene.h"

int GameIntroScene::OperatorInput()
{
	return 4;
}

void GameIntroScene::Output()
{

}

void GameIntroScene::Update()
{

}

void GameIntroScene::Draw()
{
	PrintGameMap();
	PrintGameIntro();
}

GameIntroScene::GameIntroScene()
{

}


GameIntroScene::~GameIntroScene()
{

}

void GameIntroScene::DeleteIntro()
{
	for (size_t j = 0; j < 30; j++)
	{
		GoToXY(WIDTH / 2 - 25, j + 2);
		cout << "                                                                       ";
	}

	GoToXY(WIDTH / 2 - 25, 2);
	cout << "                                                                       ";
	return;
}

void GameIntroScene::GetOneLineFromFile(FILE* file)
{
	char ch;
	int count = 0;
	fscanf(file, "%c", &ch);
	buf[count++] = ch;

	while (true)
	{
		fscanf(file, "%c", &ch);

		if (feof(file))
		{
			buf[count++] = '\0';
			break;
		}

		if (ch == '\n')
		{
			buf[count++] = '\0';
			break;
		}

		buf[count++] = ch;
	}

	return;
}

void GameIntroScene::PrintGameIntro()
{
	const int storyLineCount = 30;
	int i, j;

	FILE* file = fopen("story.txt", "r");

	if (file == NULL)
	{
		return;
	}

	i = 0;
	while (!feof(file))
	{
		char skip;
		if (kbhit())
		{
			skip = getch();
			if (skip == 13)
			{
				DeleteIntro();
				return;
			}
		}

		GetOneLineFromFile(file);

		if (i != storyLineCount)
		{
			strcpy(story[i], buf);
			GoToXY(WIDTH / 2 - 25, i + 2);
			cout << story[i];
			Sleep(500);
			i++;
		}

		else
		{
			Sleep(500);
			for (size_t j = 0; j < storyLineCount - 1; j++)
			{
				strcpy(story[j], story[j + 1]);
			}
			strcpy(story[storyLineCount - 1], buf);

			for (size_t j = 0; j < storyLineCount - 1; j++)
			{
				GoToXY(WIDTH / 2 - 25, j + 2);
				cout << "                                                                       ";
				GoToXY(WIDTH / 2 - 25, j + 2);
				cout << story[j];
			}

			GoToXY(WIDTH / 2 - 25, storyLineCount + 1);
			cout << "                                                                       ";
			GoToXY(WIDTH / 2 - 25, storyLineCount + 1);
			cout << story[storyLineCount - 1];
		}
	}

	
	Sleep(2000);
	DeleteIntro();
	
	return;
}