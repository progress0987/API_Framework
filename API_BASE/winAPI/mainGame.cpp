#include "stdafx.h"
#include "mainGame.h"

RECT rtemp;
//홍기 테스트
mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
//초기화
HRESULT mainGame::init(void) 
{
	gameNode::init(true);
	srand(time(NULL));
	player = { 100,0,160,100 };
	base = { 0,0 };
	POINT test = { base.x+200,base.y+100 };
	test1 = new Harp;
	test1->SetPoint(test);
	test1->init();
	//테스트용 맵
	IMAGEMANAGER->addImage("map","image/파괴된 헤네시스.bmp", 3495, 947,false,RGB(255,0,255));
	return S_OK;
}
//해제
 void mainGame::release(void)
 {//사용한 이미지도 릴리즈해줘야함
	 gameNode::release();
 }
 //연산~
 void mainGame::update(void)
 {
	 gameNode::update();
	 test1->collRect(player, demage);
	 test1->update();
	 if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	 {
		 player.left -= 3;
		 player.right -= 3;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	 {
		 player.left += 3;
		 player.right += 3;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_UP))
	 {
		 player.top -= 3;
		 player.bottom -= 3;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	 {
		 player.bottom += 3;
		 player.top += 3;
	 }
 }
 //여기가 그려주는 곳
 void mainGame::render() 
 {
	 HBRUSH brush;
	 HBITMAP hBitmap, OldBitmap;
	 /////////////////////////////////////건들지 말것(?)//////////////////////////////////////////////
	 PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	 //////////////////////////////////////////////////////////////////////////////////////////////
	 //getmemdc에 넣어줌
	 IMAGEMANAGER->findImage("map")->render(getMemDC(),base.x,base.y);
	 Rectangle(getMemDC(), player.left, player.top, player.right, player.bottom);
	 test1->render();
	 TIMEMANAGER->render(getMemDC());

	 /////////////////////그려주는부분 - 건들지말것//////////////////
	 this->getBackBuffer()->render(getHDC(), 0, 0);
	 ////////////////////////////////////////////////////////////////
 }