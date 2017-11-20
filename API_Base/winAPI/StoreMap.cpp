#include "stdafx.h"
#include "StoreMap.h"


StoreMap::StoreMap()
{
}


StoreMap::~StoreMap()
{
}

HRESULT StoreMap::init()
{
	//배경
	IMAGEMANAGER->addImage("store", "image/store/잡화상점(원본).bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pixelstore", "image/store/잡화상점.bmp", WINSIZEX, WINSIZEY, true, (255, 0, 0));
	//포탈
	_portal = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	_npc = IMAGEMANAGER->addFrameImage("npc", "image/store/storeNPC.bmp", 457, 71, 8, 1, true, RGB(255, 0, 255));

	//NPC
	

	return S_OK;
}
void StoreMap::release()
{

}
void StoreMap::update()
{
	count++;
	if (count % 15 == 0)
	{
		_portal->setFrameX(_portal->getFrameX());
		currentX++;
		if (currentX > _portal->getMaxFrameX())currentX = 0;
	}
	if (count % 60 == 0)
	{
		_npc->setFrameX(_npc->getFrameX());
		storecurrentX++;
		if (storecurrentX > _npc->getMaxFrameX())storecurrentX = 0;
	}
}
void StoreMap::render()
{
	IMAGEMANAGER->findImage("store")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), 500, 340, currentX, 0, 100);
	IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), 230, 405, storecurrentX, 0);
}
