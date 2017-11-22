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
	IMAGEMANAGER->addImage("pixelvillage", "image/village/파괴된 헤네시스.bmp", 3495, 947, false, RGB(255, 0, 255));
	////////////////////////////////////////////////////////////////////////////////포탈
	//왼쪽 포탈
	_lefeportal.x = -420;
	_lefeportal.y = 530;
	_lefeportal.rc = RectMakeCenter(_lefeportal.x, _lefeportal.y, 50, 80);
	_lefeportal._img = IMAGEMANAGER->addFrameImage("portal", "image/store/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	_lefeportal.currentX = 0;
	//오른쪽 포탈
	rightportal.x = 2880;
	rightportal.y = 650;
	rightportal.rc = RectMakeCenter(rightportal.x, rightportal.y, 50, 80);
	//상점 포탈
	storeportal.x = 1490;
	storeportal.y = 650;
	storeportal.rc = RectMakeCenter(storeportal.x, storeportal.y, 50, 80);
	//공원 포탈
	parkportal.x = 1270;
	parkportal.y = 320;
	parkportal.rc = RectMakeCenter(parkportal.x, parkportal.y, 50, 80);
	//시장 포탈
	marketportal.x = 430;
	marketportal.y = 530;
	marketportal.rc = RectMakeCenter(marketportal.x, marketportal.y, 50, 80);
	////////////////////////////////////////////////////////////////////////////////NPC
	//거지걸 
	gujiGirl.x = 1200;
	gujiGirl.y = 660;
	gujiGirl.rc = RectMake(gujiGirl.x, gujiGirl.y, 50, 80);
	gujiGirl._img = IMAGEMANAGER->addFrameImage("gujigirl", "image/npc/gujiGirl.bmp", 352, 71, 8, 1, true, RGB(255, 0, 255));
	gujiGirl.currentX = 0;
	//리나 
	Lina.x = 2600;
	Lina.y = 660;
	Lina.rc = RectMake(Lina.x, Lina.y, 50, 80);
	Lina._img = IMAGEMANAGER->addFrameImage("lina", "image/npc/Lina.bmp", 600, 67, 12, 1, true, RGB(255, 0, 255));
	Lina.currentX = 0;
	//주황 머리
	OrangeHair.x = 2000;
	OrangeHair.y = 155;
	OrangeHair.rc = RectMake(OrangeHair.x, OrangeHair.y, 50, 80);
	OrangeHair._img = IMAGEMANAGER->addFrameImage("orange", "image/npc/OrangeHair.bmp", 322, 66, 7, 1, true, RGB(255, 0, 255));
	OrangeHair.currentX = 0;
	//밍밍부인
	mingming.x = 1000;
	mingming.y = 330;
	mingming.rc = RectMake(mingming.x, mingming.y, 50, 80);
	mingming._img = IMAGEMANAGER->addFrameImage("ming", "image/npc/MingMing.bmp", 432, 276, 9, 4, true, RGB(255, 0, 255));
	mingming.currentX = 0;
	mingming.pattern = rand() % 4;

	//배경 움직이는 변수
	moveX = 500;
	moveY = 140;

	return S_OK;
}
void VillageMap::release()
{
	SAFE_DELETE(_lefeportal._img);
	SAFE_DELETE(gujiGirl._img);
	SAFE_DELETE(Lina._img);
	SAFE_DELETE(OrangeHair._img);
	SAFE_DELETE(mingming._img);
}
void VillageMap::update()
{
	
	_lefeportal.rc = RectMakeCenter(_lefeportal.x, _lefeportal.y, 5, 20);
	rightportal.rc = RectMakeCenter(rightportal.x, rightportal.y, 5, 20);
	storeportal.rc = RectMakeCenter(storeportal.x, storeportal.y, 5, 20);
	parkportal.rc = RectMakeCenter(parkportal.x, parkportal.y, 5, 20);
	marketportal.rc = RectMakeCenter(marketportal.x, marketportal.y, 5, 20);

	gujiGirl.rc = RectMake(gujiGirl.x, gujiGirl.y, 50, 80);
	Lina.rc = RectMake(Lina.x, Lina.y, 50, 80);
	OrangeHair.rc = RectMake(OrangeHair.x, OrangeHair.y, 50, 80);
	mingming.rc = RectMake(mingming.x, mingming.y, 50, 80);

	//프레임 돌리는거
	Frame();
	//키매니저들
	Keymanager();
	//밍밍움직임
	MingmingMove();
}
void VillageMap::render()
{
	//배경 
	IMAGEMANAGER->findImage("village")->render(getMemDC(), 0, 0, moveX, moveY, WINSIZEX, WINSIZEY);
	//포탈 그리기
	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), _lefeportal.x - 50, _lefeportal.y - 50, _lefeportal.currentX, 0, 150);
	Rectangle(getMemDC(), _lefeportal.rc.left, _lefeportal.rc.top, _lefeportal.rc.right, _lefeportal.rc.bottom);

	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), rightportal.x - 50, rightportal.y - 50, _lefeportal.currentX, 0, 150);
	Rectangle(getMemDC(), rightportal.rc.left, rightportal.rc.top, rightportal.rc.right, rightportal.rc.bottom);

	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), storeportal.x - 50, storeportal.y - 50, _lefeportal.currentX, 0, 150);
	Rectangle(getMemDC(), storeportal.rc.left, storeportal.rc.top, storeportal.rc.right, storeportal.rc.bottom);

	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), parkportal.x - 50, parkportal.y - 50, _lefeportal.currentX, 0, 150);
	Rectangle(getMemDC(), parkportal.rc.left, parkportal.rc.top, parkportal.rc.right, parkportal.rc.bottom);

	IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), marketportal.x - 50, marketportal.y - 50, _lefeportal.currentX, 0, 150);
	Rectangle(getMemDC(), marketportal.rc.left, marketportal.rc.top, marketportal.rc.right, marketportal.rc.bottom);
	//npc
	IMAGEMANAGER->findImage("gujigirl")->frameRender(getMemDC(), gujiGirl.rc.left, gujiGirl.rc.top, gujiGirl.currentX, 0);
	IMAGEMANAGER->findImage("lina")->frameRender(getMemDC(), Lina.rc.left, Lina.rc.top, Lina.currentX, 0);
	IMAGEMANAGER->findImage("orange")->frameRender(getMemDC(), OrangeHair.rc.left, OrangeHair.rc.top, OrangeHair.currentX, 0);
	if (mingming.pattern == 0)
	{
		IMAGEMANAGER->findImage("ming")->frameRender(getMemDC(), mingming.rc.left, mingming.rc.top, mingming.currentX, 3);
	}
	else if (mingming.pattern == 1)
	{
		IMAGEMANAGER->findImage("ming")->frameRender(getMemDC(), mingming.rc.left, mingming.rc.top, mingming.currentX, 1);
	}
	else if (mingming.pattern == 2)
	{
		IMAGEMANAGER->findImage("ming")->frameRender(getMemDC(), mingming.rc.left, mingming.rc.top, mingming.currentX, 0);
	}
	else if (mingming.pattern == 3)
	{
		IMAGEMANAGER->findImage("ming")->frameRender(getMemDC(), mingming.rc.left, mingming.rc.top, mingming.currentX, 2);
	}
	//Rectangle(getMemDC(), mingming.rc.left, mingming.rc.top, mingming.rc.right, mingming.rc.bottom);

}





void VillageMap::Keymanager()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && moveX > 0)//사진크기를 못넘어가게 막아준거
	{
		moveX -= 3;
		//포탈 고정
		_lefeportal.x += 3;
		rightportal.x += 3;
		storeportal.x += 3;
		parkportal.x += 3;
		marketportal.x += 3;
		//npc 고정
		gujiGirl.x += 3;
		Lina.x += 3;
		OrangeHair.x += 3;
		mingming.x += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 2100)//사진크기를 못넘어가게 막아준거
	{
		moveX += 3;
		//포탈 고정
		_lefeportal.x -= 3;
		rightportal.x -= 3;
		storeportal.x -= 3;
		parkportal.x -= 3;
		marketportal.x -= 3;
		//npc 고정
		gujiGirl.x -= 3;
		Lina.x -= 3;
		OrangeHair.x -= 3;
		mingming.x -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && moveY > 0)//사진크기를 못넘어가게 막아준거
	{
		moveY -= 3;
		//포탈 고정
		_lefeportal.y += 3;
		rightportal.y += 3;
		storeportal.y += 3;
		parkportal.y += 3;
		marketportal.y += 3;
		//npc 고정
		gujiGirl.y += 3;
		Lina.y += 3;
		OrangeHair.y += 3;
		mingming.y += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 180)//사진크기를 못넘어가게 막아준거
	{
		moveY += 3;
		//포탈 고정
		_lefeportal.y -= 3;
		rightportal.y -= 3;
		storeportal.y -= 3;
		parkportal.y -= 3;
		marketportal.y -= 3;
		//npc 고정
		gujiGirl.y -= 3;
		Lina.y -= 3;
		OrangeHair.y -= 3;
		mingming.y -= 3;
	}
}

void VillageMap::Frame()
{
	count++;
	//포탈들
	if (count % 15 == 0)
	{
		_lefeportal._img->setFrameX(_lefeportal._img->getFrameX());
		_lefeportal.currentX++;
		if (_lefeportal.currentX > _lefeportal._img->getMaxFrameX())_lefeportal.currentX = 0;
	}
	//거지 걸
	if (count % 50 == 0)
	{
		gujiGirl._img->setFrameX(gujiGirl._img->getFrameX());
		gujiGirl.currentX++;
		if (gujiGirl.currentX > gujiGirl._img->getMaxFrameX())gujiGirl.currentX = 0;
	}
	//리나
	if (count % 50 == 0)
	{
		Lina._img->setFrameX(Lina._img->getFrameX());
		Lina.currentX++;
		if (Lina.currentX > Lina._img->getMaxFrameX())Lina.currentX = 0;
	}
	//주황머리
	if (count % 50 == 0)
	{
		OrangeHair._img->setFrameX(OrangeHair._img->getFrameX());
		OrangeHair.currentX++;
		if (OrangeHair.currentX > OrangeHair._img->getMaxFrameX())OrangeHair.currentX = 0;
	}
	//밍밍부인
	if (count % 50 == 0)
	{
		mingming._img->setFrameX(mingming._img->getFrameX());
		mingming.currentX++;
		if (mingming.currentX > mingming._img->getMaxFrameX())mingming.currentX = 0;
	}
}

void VillageMap::MingmingMove()
{
	if (mingming.pattern == 0)
	{
		mingming.x ++;
		if (count % 100 == 0)
		{
			mingming.pattern = rand() % 4;
		}
	}
	else if (mingming.pattern == 1)
	{
		mingming.x --;
		if (count % 100 == 0)
		{
			mingming.pattern = rand() % 4;
		}
	}
	else if (mingming.pattern == 2)
	{
		
		if (count % 500 == 0)
		{
			mingming.pattern = rand() % 4;
		}
	}
	else if (mingming.pattern == 3)
	{

		if (count % 500 == 0)
		{
			mingming.pattern = rand() % 4;
		}
	}
}
