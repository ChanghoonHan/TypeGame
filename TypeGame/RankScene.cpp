#include "RankScene.h"

int RankScene::OperatorInput()
{
	m_isSceneChange = true;
	m_numForSelMenu = 0;
	return 0;
}

void RankScene::Output()
{

}

void RankScene::Draw()
{
	system("cls");
	GoToXY(WIDTH / 2 - 25, HEIGHT / 2 - 7);
	cout << "����\t�̸�\t\t�ܰ�\t����\t��¥";
	
	m_rankData.PrintRank();

	getch();
}

void RankScene::Update()
{

}

RankScene::RankScene()
{
	m_rankData.LoadRankFromFile();
	m_rankDataPtr = &m_rankData;
}


RankScene::~RankScene()
{
}
