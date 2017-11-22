#include "../stdafx.h"
#include "ForestMap.h"


ForestMap::ForestMap()
{
}


ForestMap::~ForestMap()
{
}


HRESULT ForestMap::init()
{

	////////////////////////////////////////////////////////////////////////////////포탈
	portal.x = 50;
	portal.y = 620;
	portal.rc = RectMake(portal.x, portal.y, 50, 80);
	portal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	portal.currentX = 0;

	//배경 움직이는 변수
	moveX = 0;
	moveY = 210;

	return S_OK;
}
void ForestMap::release()
{
	SAFE_DELETE(portal._img);
}
void ForestMap::update()
{
	portal.rc = RectMakeCenter(portal.x, portal.y, 5, 20);
	//키매니저
	Keymanager();
	//프레임
	Frame();
}
void ForestMap::render()
{
	IMAGEMANAGER->findImage("forest")->render(getMemDC(), 0, 0, moveX, moveY, WINSIZEX, WINSIZEY);
	//포탈
	Rectangle(getMemDC(), portal.rc.left, portal.rc.top, portal.rc.right, portal.rc.bottom);
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), portal.x - 50, portal.y - 50, portal.currentX, 0, 150);
}
//키 
void ForestMap::Keymanager()
{
	
	if (KEYMANAGER->isStayKeyDown(VK_UP) && moveY > 0)
	{
		moveY -= 3;
		//포탈
		portal.y += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 250)
	{
		moveY += 3;
		//포탈
		portal.y -= 3;
	}
}
//프레임
void ForestMap::Frame()
{
	//프레임 돌리는 거
	count++;
	//포탈
	if (count % 15 == 0)
	{
		portal._img->setFrameX(portal._img->getFrameX());
		portal.currentX++;
		if (portal.currentX > portal._img->getMaxFrameX())portal.currentX = 0;
	}
}