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
	//배경
	IMAGEMANAGER->addImage("park", "image/park/파헤공원(원본).bmp", 1951, 1024, false, RGB(255, 0, 255));
	//픽셀충돌
	IMAGEMANAGER->addImage("pixelpark", "image/park/파헤공원.bmp", 1951, 1024, false, RGB(255, 0, 255));

	////////////////////////////////////////////////////////////////////////////////포탈
	//왼쪽에 있는 포탈
	portal.x = 50;
	portal.y = 500;
	portal.rc = RectMake(portal.x, portal.y, 50, 80);
	portal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	portal.currentX = 0;
	//오른쪽에 있는 보스 만나러가는 포탈
	rightportal.x = 1880;
	rightportal.y = 610;
	rightportal.rc = RectMake(rightportal.x, rightportal.y, 50, 80);
	rightportal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	rightportal.currentX = 0;

	//배경 움직이는 변수
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

	//키매니저
	Keymanager();
	//프레임
	Frame();
	

}
void ParkMap::render()
{
	//배경
	IMAGEMANAGER->findImage("park")->render(getMemDC(), 0, 0, moveX, moveY, WINSIZEX, WINSIZEY);
	//포탈
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

		//포탈
		portal.x += 3;
		rightportal.x += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 580)
	{
		moveX += 3;
		//포탈
		portal.x -= 3;
		rightportal.x -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && moveY > 0)
	{
		moveY -= 3;
		//포탈
		portal.y += 3;
		rightportal.y += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 255)
	{
		moveY += 3;
		//포탈
		portal.y -= 3;
		rightportal.y -= 3;
	}
}

void ParkMap::Frame()
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
