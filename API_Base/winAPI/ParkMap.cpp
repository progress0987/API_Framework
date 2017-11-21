#include "stdafx.h"
#include "ParkMap.h"


ParkMap::ParkMap()
{
}


ParkMap::~ParkMap()
{
}


HRESULT ParkMap::init()
{
	//���
	IMAGEMANAGER->addImage("park", "image/park/�������(����).bmp", 1951, 1024, false, RGB(255, 0, 255));
	//�ȼ��浹
	IMAGEMANAGER->addImage("pixelpark", "image/park/�������.bmp", 1951, 1024, false, RGB(255, 0, 255));

	////////////////////////////////////////////////////////////////////////////////��Ż
	portal.x = -69;
	portal.y = 489;
	portal.rc = RectMake(portal.x, portal.y, 50, 80);
	portal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	portal.currentX = 0;

	//��� �����̴� ����
	moveX = 100;
	moveY = 140;

	return S_OK;
}
void ParkMap::release()
{
	SAFE_DELETE(portal._img);
}
void ParkMap::update()
{
	portal.rc = RectMake(portal.x, portal.y, 50, 80);

	//Ű�Ŵ���
	Keymanager();

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
void ParkMap::render()
{
	//���
	IMAGEMANAGER->findImage("park")->render(getMemDC(), 0, 0, moveX, moveY, WINSIZEX, WINSIZEY);
	//��Ż
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), portal.rc.left, portal.rc.top, portal.currentX, 0, 150);
}

void ParkMap::Keymanager()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && moveX > 0)
	{
		moveX -= 3;

		//��Ż
		portal.x += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 580)
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
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 255)
	{
		moveY += 3;
		//��Ż
		portal.y -= 3;
	}
}
