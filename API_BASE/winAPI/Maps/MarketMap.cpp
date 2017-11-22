#include "../stdafx.h"
#include "MarketMap.h"


MarketMap::MarketMap()
{
}


MarketMap::~MarketMap()
{
}



HRESULT MarketMap::init()
{

	////////////////////////////////////////////////////////////////////////////////포탈
	portal.x = 50;
	portal.y = 485;
	portal.rc = RectMake(portal.x, portal.y, 50, 80);
	portal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	portal.currentX = 0;

	//배경 움직이는 변수
	moveX = 0;
	moveY = 200;
	return S_OK;
}
void MarketMap::release()
{
	SAFE_DELETE(portal._img);
}
void MarketMap::update()
{
	portal.rc = RectMakeCenter(portal.x, portal.y, 5, 20);
	//키매니저
	Keymanager();
	//프레임
	Frame();
}
void MarketMap::render()
{
	IMAGEMANAGER->findImage("market")->render(getMemDC(), 0, 0, moveX, moveY, WINSIZEX, WINSIZEY);
	//포탈
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), portal.x - 50, portal.y - 50, portal.currentX, 0, 150);
}
//키 
void MarketMap::Keymanager()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && moveX > 0)
	{
		moveX -= 3;
		//포탈
		portal.x += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 440)
	{
		moveX += 3;
		//포탈
		portal.x -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && moveY > 0)
	{
		moveY -= 3;
		//포탈
		portal.y += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 200)
	{
		moveY += 3;
		//포탈
		portal.y -= 3;
	}
}
//프레임
void MarketMap::Frame()
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