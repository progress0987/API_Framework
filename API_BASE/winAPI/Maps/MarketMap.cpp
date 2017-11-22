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

	////////////////////////////////////////////////////////////////////////////////��Ż
	portal.x = 50;
	portal.y = 485;
	portal.rc = RectMake(portal.x, portal.y, 50, 80);
	portal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	portal.currentX = 0;

	//��� �����̴� ����
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
	//Ű�Ŵ���
	Keymanager();
	//������
	Frame();
}
void MarketMap::render()
{
	IMAGEMANAGER->findImage("market")->render(getMemDC(), 0, 0, moveX, moveY, WINSIZEX, WINSIZEY);
	//��Ż
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), portal.x - 50, portal.y - 50, portal.currentX, 0, 150);
}
//Ű 
void MarketMap::Keymanager()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && moveX > 0)
	{
		moveX -= 3;
		//��Ż
		portal.x += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 440)
	{
		moveX += 3;
		//��Ż
		portal.x -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && moveY > 0)
	{
		moveY -= 3;
		//��Ż
		portal.y += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 200)
	{
		moveY += 3;
		//��Ż
		portal.y -= 3;
	}
}
//������
void MarketMap::Frame()
{
	//������ ������ ��
	count++;
	//��Ż
	if (count % 15 == 0)
	{
		portal._img->setFrameX(portal._img->getFrameX());
		portal.currentX++;
		if (portal.currentX > portal._img->getMaxFrameX())portal.currentX = 0;
	}
}