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
	////////////////////////////////////////////////////////////////////////////////포탈
	/*

	tagrect _lefeportal;//제일 왼쪽에 있는 포탈				0
	tagrect rightportal;//제일 오른쪽에 있는 포탈			1
	tagrect storeportal;//상점 포탈							2
	tagrect parkportal;//공원가는 포탈						3
	tagrect marketportal;//시장가는 포탈					4
	*/

	bgm = "Village";

	//왼쪽 포탈
	_lefeportal.x = 159;
	_lefeportal.y = 670;
	_lefeportal.rc = RectMake(_lefeportal.x, _lefeportal.y, 54, 88);
	_lefeportal._img = IMAGEMANAGER->findImage("portal");
	_lefeportal.currentX = 0;
	_lefeportal.pattern = 0;

	//오른쪽 포탈
	rightportal.x = 3273;
	rightportal.y = 736+50;
	rightportal._img = IMAGEMANAGER->findImage("portal");
	rightportal.rc = RectMakeCenter(rightportal.x, rightportal.y, 54, 88);
	rightportal.currentX = 0;
	rightportal.pattern = 1;

	//상점 포탈
	storeportal.x = 1969;
	storeportal.y = 740+50;
	storeportal._img = IMAGEMANAGER->findImage("portal");
	storeportal.rc = RectMakeCenter(storeportal.x, storeportal.y, 54, 88);
	storeportal.currentX = 0;
	storeportal.pattern = 2;
	//공원 포탈
	parkportal.x = 1733;
	parkportal.y = 408+50;
	parkportal._img = IMAGEMANAGER->findImage("portal");
	parkportal.rc = RectMakeCenter(parkportal.x, parkportal.y, 54, 88);
	parkportal.currentX = 0;
	parkportal.pattern = 3;
	//시장 포탈
	marketportal.x = 900;
	marketportal.y = 618+50;
	marketportal._img = IMAGEMANAGER->findImage("portal");
	marketportal.rc = RectMakeCenter(marketportal.x, marketportal.y, 50, 80);
	marketportal.currentX = 0;
	marketportal.pattern = 4;

	PORTAL.push_back(_lefeportal);
	PORTAL.push_back(rightportal);
	PORTAL.push_back(storeportal);
	PORTAL.push_back(parkportal);
	PORTAL.push_back(marketportal);
	////////////////////////////////////////////////////////////////////////////////NPC
	//거지걸 
	gujiGirl.x = 1693;
	gujiGirl.y = 803;
	gujiGirl.rc = RectMake(gujiGirl.x, gujiGirl.y, 44, 71);
	gujiGirl._img = IMAGEMANAGER->findImage("gujigirl");
	gujiGirl.currentX = 0;
	//리나 
	Lina.x = 3113;
	Lina.y = 803;
	Lina.rc = RectMake(Lina.x, Lina.y, 50, 67);
	Lina._img = IMAGEMANAGER->findImage("lina");
	Lina.currentX = 0;
	//주황 머리
	OrangeHair.x = 2587;
	OrangeHair.y = 293;
	OrangeHair.rc = RectMake(OrangeHair.x, OrangeHair.y, 46, 66);
	OrangeHair._img = IMAGEMANAGER->findImage("orange");
	OrangeHair.currentX = 0;
	//밍밍부인
	mingming.x = 1361;
	mingming.y = 472;
	mingming.rc = RectMake(mingming.x, mingming.y, 47, 69);
	mingming._img = IMAGEMANAGER->findImage("ming");
	mingming.currentX = 0;
	mingming.pattern = rand() % 4;

	NPC.push_back(gujiGirl);
	NPC.push_back(Lina);
	NPC.push_back(OrangeHair);
	NPC.push_back(mingming);
	front = IMAGEMANAGER->findImage("village");
	back = IMAGEMANAGER->findImage("pixelvillage");

	myIndex = MapIndex::MVillage;
	
	return S_OK;
}
void VillageMap::release()
{
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
	//밍밍움직임
	MingmingMove();
}
void VillageMap::render()
{
	//배경 
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, cam->width, cam->height);
	//포탈 그리기
	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++) 
	{
		i->_img->alphaFrameRender(getMemDC(), i->x - 25-cam->camPoint.x, i->y - 50 - cam->camPoint.y, i->currentX, 0, 150);
		
	}

	//npc
	for (vector<tagrect>::iterator i = NPC.begin(); i != NPC.end(); i++) {
		if (i->pattern == -1) {
			i->_img->frameRender(getMemDC(), i->rc.left-cam->camPoint.x, i->rc.top - cam->camPoint.y, i->currentX, 0);
		}
		else {
			int Ypos;
			switch (i->pattern) {
			case 0:
				Ypos = 3;
				break;
			case 1:
				Ypos = 1;
				break;
			case 2:
				Ypos = 0;
				break;
			case 3:
				Ypos = 2;
				break;
			}
			i->_img->frameRender(getMemDC(), i->rc.left - cam->camPoint.x, i->rc.top - cam->camPoint.y, i->currentX, Ypos);
		}
	}
	

}






void VillageMap::Frame()
{
	count++;
	//포탈들
	if (count % 15 == 0)
	{
		for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++) {
			i->currentX++;
			if (i->currentX > i->_img->getMaxFrameX())i->currentX = 0;
		}
	}
	//NPC
	if (count % 50 == 0)
	{
		for (vector<tagrect>::iterator i = NPC.begin(); i != NPC.end(); i++) {
			i->currentX++;
			if (i->currentX > i->_img->getMaxFrameX())i->currentX = 0;
		}
	}
}

void VillageMap::MingmingMove()//이동거리 정해져있게 할 것
{
	if (NPC.back().pattern == 0)
	{
		NPC.back().x++;
		NPC.back().rc = RectMake(NPC.back().x, NPC.back().y, 47, 69);
		if (count % 100 == 0 || NPC.back().x > 1390)
		{
			NPC.back().pattern = rand() % 4;
		}
	}
	else if (NPC.back().pattern == 1)
	{
		NPC.back().x --;
		NPC.back().rc = RectMake(NPC.back().x, NPC.back().y, 47, 69);
		if (count % 100 == 0 || NPC.back().x < 1190)
		{
			NPC.back().pattern = rand() % 4;
		}
	}
	else if (NPC.back().pattern == 2)
	{
		
		if (count % 500 == 0)
		{
			NPC.back().pattern = rand() % 4;
		}
	}
	else if (NPC.back().pattern == 3)
	{

		if (count % 500 == 0)
		{
			NPC.back().pattern = rand() % 4;
		}
	}
}
