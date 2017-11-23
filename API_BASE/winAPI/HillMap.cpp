#include "stdafx.h"
#include "HillMap.h"


HillMap::HillMap()
{
}


HillMap::~HillMap()
{
}



HRESULT HillMap::init()
{

	////////////////////////////////////////////////////////////////////////////////��Ż
	portal.x = 1300;
	portal.y = 635;
	portal.rc = RectMake(portal.x, portal.y, 50, 80);
	portal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	portal.currentX = 0;

	//��� �����̴� ����
	moveX = 710;
	moveY = 200;

	return S_OK;
}
void HillMap::release()
{
	SAFE_DELETE(portal._img);
}
void HillMap::update()
{
	portal.rc = RectMakeCenter(portal.x, portal.y, 5, 20);
	//Ű�Ŵ���
	Keymanager();
	//������
	Frame();
}
void HillMap::render()
{
	IMAGEMANAGER->findImage("hill")->render(getMemDC(), 0, 0, moveX, moveY, WINSIZEX, WINSIZEY);
	//��Ż
	Rectangle(getMemDC(), portal.rc.left, portal.rc.top, portal.rc.right, portal.rc.bottom);
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), portal.x - 50, portal.y - 50, portal.currentX, 0, 150);
}
//Ű 
void HillMap::Keymanager()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && moveX > 0)
	{
		moveX -= 3;
		//��Ż
		portal.x += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 710)
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
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 230)
	{
		moveY += 3;
		//��Ż
		portal.y -= 3;
	}
}
//������
void HillMap::Frame()
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