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

	front = IMAGEMANAGER->findImage("store");
	back = IMAGEMANAGER->findImage("pixelstore");

	portal.x = 923;
	portal.y = 530;
	portal.rc = RectMakeCenter(portal.x, portal.y, 2, 10);
	portal.pattern = 0;
	portal.currentX = 0;
	portal._img = IMAGEMANAGER->findImage("portal");

	PORTAL.push_back(portal);

	
	//NPC
	storenpc.x = 452;
	storenpc.y = 536;
	storenpc.rc = RectMake(storenpc.x, storenpc.y, 50, 80);
	storenpc.currentX = 0;
	storenpc._img = IMAGEMANAGER->findImage("storenpc");
	NPC.push_back(storenpc);

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
		for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++) 
		{
			i->_img->setFrameX(i->_img->getFrameX());
			i->currentX++;
			if (i->currentX > i->_img->getMaxFrameX())i->currentX = 0;
		}
	}

	//NPC
	if (count % 50 == 0)
	{
		for (vector<tagrect>::iterator i = NPC.begin(); i != NPC.end(); i++) 
		{
			i->currentX++;
			if (i->currentX > i->_img->getMaxFrameX())i->currentX = 0;
		}
	}
}
void StoreMap::render()
{
	//배경 
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, cam->width, cam->height);
	//포탈그리기
	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++)
	{
		i->_img->alphaFrameRender(getMemDC(), i->x - 50 - cam->camPoint.x, i->y - 50 - cam->camPoint.y, i->currentX, 0, 150);
	}


	//NPC
	for (vector<tagrect>::iterator i = NPC.begin(); i != NPC.end(); i++)
	{
		i->_img->frameRender(getMemDC(), i->rc.left - cam->camPoint.x, i->rc.top - cam->camPoint.y, i->currentX, 0);
	}
	Rectangle(getMemDC(), portal.rc.left, portal.rc.top, portal.rc.right, portal.rc.bottom);
}
