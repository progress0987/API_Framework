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
	//���ʿ� �ִ� ��Ż
	portal.x = 50;
	portal.y = 500;
	portal.rc = RectMake(portal.x, portal.y, 50, 80);
	portal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	portal.currentX = 0;
	//�����ʿ� �ִ� ���� ���������� ��Ż
	rightportal.x = 1880;
	rightportal.y = 610;
	rightportal.rc = RectMake(rightportal.x, rightportal.y, 50, 80);
	rightportal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	rightportal.currentX = 0;

	//��� �����̴� ����
	moveX = 0;
	moveY = 190;

	return S_OK;
}
void ParkMap::release()
{
	SAFE_DELETE(portal._img);
}
void ParkMap::update()
{
	portal.rc = RectMakeCenter(portal.x, portal.y, 5, 20);
	rightportal.rc = RectMakeCenter(rightportal.x, rightportal.y, 5, 20);

	//Ű�Ŵ���
	Keymanager();
	//������
	Frame();
	

}
void ParkMap::render()
{
	//���
	IMAGEMANAGER->findImage("park")->render(getMemDC(), 0, 0, moveX, moveY, WINSIZEX, WINSIZEY);
	//��Ż
	Rectangle(getMemDC(), portal.rc.left, portal.rc.top, portal.rc.right, portal.rc.bottom);
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), portal.x - 50 , portal.y - 50, portal.currentX, 0, 150);
	Rectangle(getMemDC(), rightportal.rc.left, rightportal.rc.top, rightportal.rc.right, rightportal.rc.bottom);
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), rightportal.x - 50, rightportal.y - 50, portal.currentX, 0, 150);
}

void ParkMap::Keymanager()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && moveX > 0)
	{
		moveX -= 3;

		//��Ż
		portal.x += 3;
		rightportal.x += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 580)
	{
		moveX += 3;
		//��Ż
		portal.x -= 3;
		rightportal.x -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && moveY > 0)
	{
		moveY -= 3;
		//��Ż
		portal.y += 3;
		rightportal.y += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 255)
	{
		moveY += 3;
		//��Ż
		portal.y -= 3;
		rightportal.y -= 3;
	}
}

void ParkMap::Frame()
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
