#include "stdafx.h"
#include "StarcraftScene.h"
#include "BattleCruiser.h"


HRESULT StarcraftScene::init(void)
{
	ship = new BattleCruiser;
	ship->init("BATTLECRUISER", WINSIZEX / 2, WINSIZEY / 2);//���� ����

	return S_OK;
}

void StarcraftScene::release(void)
{
}

void StarcraftScene::update(void)
{
	ship->update();
}

void StarcraftScene::render()
{
	ship->render();
	char str[128];
	sprintf(str, "��Ÿũ����Ʈ ��");
	TextOut(getMemDC(), WINSIZEX / 2 - 200, WINSIZEY / 2, str, strlen(str));
}

StarcraftScene::StarcraftScene()
{
}


StarcraftScene::~StarcraftScene()
{
}
