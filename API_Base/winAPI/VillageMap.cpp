#include "stdafx.h"
#include "VillageMap.h"


VillageMap::VillageMap()
{
}


VillageMap::~VillageMap()
{
}


HRESULT VillageMap::init()
{
	//배경
	IMAGEMANAGER->addImage("village", "image/village/파괴된 헤네시스(원본).bmp", 3495, 947, false, RGB(255, 0, 255));
	//포탈
	_portal.rc = RectMake(0, 529, 50, 80);
	_portal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	_portal.currentX = 0;

	//배경 움직이는 변수
	moveX = 500;
	moveY = 140;

	return S_OK;
}
void VillageMap::release()
{
	SAFE_DELETE(_portal._img);
}
void VillageMap::update()
{
	_portal.rc = RectMake(0, 480, 50, 80);

	//프레임을 돌리자
	count++;
	if (count % 15 == 0)
	{
		_portal._img->setFrameX(_portal._img->getFrameX());
		_portal.currentX++;
		if (_portal.currentX > _portal._img->getMaxFrameX())_portal.currentX = 0;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && moveX > 0)//사진크기를 못넘어가게 막아준거
	{
		moveX -= 3;
		_portal.rc.left += 100;
		_portal.rc.right += 100;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 2100)//사진크기를 못넘어가게 막아준거
	{
		moveX += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && moveY > 0)//사진크기를 못넘어가게 막아준거
	{
		moveY -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 180)//사진크기를 못넘어가게 막아준거
	{
		moveY += 3;
	}
}
void VillageMap::render()
{
	IMAGEMANAGER->findImage("village")->render(getMemDC(),0,0,moveX, moveY,WINSIZEX,WINSIZEY);
	//Rectangle(getMemDC(), _portal.rc.left, _portal.rc.top, _portal.rc.right, _portal.rc.bottom);
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), _portal.rc.left, _portal.rc.top, _portal.currentX, 0, 100);
}