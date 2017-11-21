#include "stdafx.h"
#include "mainGame.h"

RECT rtemp;
//태규 테스트
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
	_player = new player;

	_player->init();

	return S_OK;
}
//해제
 void mainGame::release(void)
 {//사용한 이미지도 릴리즈해줘야함
	 gameNode::release();
	 _player->release();
 }
 //연산~
 void mainGame::update(void)
 {
	 gameNode::update();

	 _player->update();
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

	 _player->render();

	 /////////////////////그려주는부분 - 건들지말것//////////////////
	 this->getBackBuffer()->render(getHDC(), 0, 0);
	 ////////////////////////////////////////////////////////////////
 }