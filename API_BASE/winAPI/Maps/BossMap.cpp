#include "../stdafx.h"
#include "BossMap.h"


BossMap::BossMap()
{
}


BossMap::~BossMap()
{
}


HRESULT BossMap::init()
{

	////////////////////////////////////////////////////////////////////////////////��Ż
	frontMap = IMAGEMANAGER->findImage("boss");
	backMap = IMAGEMANAGER->findImage("pixelboss");
	portal.x = 50;
	portal.y = 520;
	portal.rc = RectMake(portal.x, portal.y, 50, 80);
	portal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	portal.currentX = 0;

	//��� �����̴� ����
	moveX = 0;
	moveY = 130;
	return S_OK;
}
void BossMap::release()
{
	SAFE_DELETE(portal._img);
}
void BossMap::update()
{
	portal.rc = RectMakeCenter(portal.x, portal.y, 5, 20);

	//Ű�Ŵ���
	Keymanager();
	//������
	Frame();
}
void BossMap::render()
{
	frontMap->render(getMemDC(), 0, 0, moveX, moveY, WINSIZEX, WINSIZEY);

	Rectangle(getMemDC(), portal.rc.left, portal.rc.top, portal.rc.right, portal.rc.bottom);
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), portal.x - 50, portal.y - 50, portal.currentX, 0, 150);
}
//Ű 
void BossMap::Keymanager()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && moveX > 0)
	{
		moveX -= 3;
		//��Ż
		portal.x += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 315)
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
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 130)
	{
		moveY += 3;
		//��Ż
		portal.y -= 3;
	}
}

void BossMap::Frame()
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
