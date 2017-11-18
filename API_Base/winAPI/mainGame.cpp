#include "stdafx.h"
#include "mainGame.h"

RECT rtemp;
int testing = 0;
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
	IMAGEMANAGER->addImage("test", "sprites/a.bmp", 26, 124, TRUE, RGB(255, 0, 255));

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
	 testing++;
	 if (testing > 360)
		 testing = 0;

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

	 //TIMEMANAGER->render(getMemDC());
	 IMAGEMANAGER->findImage("test")->rotatedRender(getMemDC(), 100, 100, (float)testing);
	 IMAGEMANAGER->findImage("test")->rotatedRender(getMemDC(),100,300,10,10,(float)testing);

	 /////////////////////그려주는부분 - 건들지말것//////////////////
	 this->getBackBuffer()->render(getHDC(), 0, 0);
	 ////////////////////////////////////////////////////////////////
 }