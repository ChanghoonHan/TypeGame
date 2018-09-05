#include "TitleScene.h"

int TitleScene::OperatorInput()
{
	char key;

	if (kbhit())
	{
		key = getch();
		if (key == 224)//방향키가 들어오면 한번 더 걸러주기 위함
		{
			key = getch();
		}

		if (key == 13)//엔터가 들어왔을때
		{
			return m_numForSelMenu+1;
		}

		if (key == 72)//윗쪽 방향키가 눌렸을때
		{
			if (m_numForSelMenu > 0)
			{
				m_isSceneModify = true;
				m_numForSelMenu--;
			}
			return 0;
		}

		if (key == 80)//아랫쪽 방향키가 눌렸을때
		{
			if (m_numForSelMenu < 2)
			{
				m_isSceneModify = true;
				m_numForSelMenu++;
			}
			return 0;
		}	
	}

	return 0;
}

void TitleScene::Output()
{

}

void TitleScene::Draw()
{
	if (m_isSceneModify == true || m_isSceneChange == true)
	{
		m_isSceneChange = false;
		m_isSceneModify = false;
		system("cls");
		SetColor(15);
		GoToXY(WIDTH / 2 - 10, HEIGHT / 2 - 3);
		cout << "■■■■■■■■■■" << endl;
		GoToXY(WIDTH / 2 - 10, HEIGHT / 2 - 1);
		cout << "■                ■" << endl;
		GoToXY(WIDTH / 2 - 10, HEIGHT / 2 + 1);
		cout << "■                ■" << endl;
		GoToXY(WIDTH / 2 - 10, HEIGHT / 2 + 3);
		cout << "■■■■■■■■■■" << endl;

		switch (m_numForSelMenu)
		{
		case 0:
			GoToXY(WIDTH / 2 - 10, HEIGHT / 2 - 2);
			cout << "■";
			SetColor(5);
			cout << "▶1.  게임시작";
			SetColor(15);
			cout << "  ■" << endl;
			GoToXY(WIDTH / 2 - 10, HEIGHT / 2);
			cout << "■  2.  랭킹      ■" << endl;
			GoToXY(WIDTH / 2 - 10, HEIGHT / 2 + 2);
			cout << "■  3.  끝내기    ■" << endl;
			break;

		case 1:
			GoToXY(WIDTH / 2 - 10, HEIGHT / 2);
			cout << "■";
			SetColor(5);
			cout << "▶2.  랭킹";
			SetColor(15);
			cout << "      ■" << endl;

			GoToXY(WIDTH / 2 - 10, HEIGHT / 2 - 2);
			cout << "■  1.  게임시작  ■";
			GoToXY(WIDTH / 2 - 10, HEIGHT / 2 + 2);
			cout << "■  3.  끝내기    ■" << endl;
			GoToXY(WIDTH / 2 - 10, HEIGHT / 2 - 1);
			break;

		case 2:
			GoToXY(WIDTH / 2 - 10, HEIGHT / 2 + 2);
			cout << "■";
			SetColor(5);
			cout << "▶3.  끝내기";
			SetColor(15);
			cout << "    ■" << endl;

			GoToXY(WIDTH / 2 - 10, HEIGHT / 2 - 2);
			cout << "■  1.  게임시작  ■";
			GoToXY(WIDTH / 2 - 10, HEIGHT / 2);
			cout << "■  2.  랭킹      ■" << endl;
			break;

		default:
			break;
		}
	}
}

void TitleScene::Update()
{

}

TitleScene::TitleScene()
{
	m_isSceneModify = true;
}

TitleScene::~TitleScene()
{
}