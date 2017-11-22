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
	portal.x = 900;
	portal.y = 530;
	portal.rc = RectMakeCenter(portal.x, portal.y, 5, 20);
	portal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
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
		portal._img->setFrameX(portal._img->getFrameX());
		currentX++;
		if (currentX > portal._img->getMaxFrameX())currentX = 0;
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

	Rectangle(getMemDC(), portal.rc.left, portal.rc.top, portal.rc.right, portal.rc.bottom);
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), portal.x - 50, portal.y - 50, currentX, 0, 150);
	IMAGEMANAGER->findImage("npc")->frameRender(getMemDC(), 450, 540, storecurrentX, 0);
}
