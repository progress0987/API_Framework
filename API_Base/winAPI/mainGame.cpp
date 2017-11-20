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
	 test1->update();
	 if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	 {
		 base.x += 3;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	 {
		 base.x -= 3;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_UP))
	 {
		 base.y += 3;
	 }
	 if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	 {
		 base.y -= 3;
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
	 test1->render();
	 TIMEMANAGER->render(getMemDC());

	 /////////////////////그려주는부분 - 건들지말것//////////////////
	 this->getBackBuffer()->render(getHDC(), 0, 0);
	 ////////////////////////////////////////////////////////////////
 }