#include "stdafx.h"
#include "mainGame.h"

//생성자랑 소멸자는 쓰지 않는당..//
mainGame::mainGame()
{

}
//생성자랑 소멸자는 쓰지 않는당..//
mainGame::~mainGame()
{

}
HRESULT mainGame::init(void)
{
	gameNode::init(true);
	IMAGEMANAGER->addImage("미니맵", "sprites/map/파괴된 헤네시스.bmp", 1951 / 10, 1024 / 10, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("맵", "sprites/map/파헤공원(원본).bmp", 1951, 1024, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지형", "sprites/map/파헤공원.bmp", 1951, 1024, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("인터페이스", "sprites/인터페이스.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("맵")->render(IMAGEMANAGER->findImage("맵")->getMemDC());
	cam = new Camera;
	cam->camPoint.x = 0;
	cam->camPoint.y = 0;
	cam->width = WINSIZEX;
	cam->height = WINSIZEY;
	_player = new player;

	_player->init(cam);

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

	IMAGEMANAGER->render("맵", getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->findImage("미니맵")->alphaRender(getMemDC(), 0, 0, 150);

	_player->render();


	IMAGEMANAGER->render("인터페이스", getMemDC(), 0, 0);

	TIMEMANAGER->render(getMemDC());
	/////////////////////그려주는부분 - 건들지말것//////////////////
	this->getBackBuffer()->render(getHDC(), 0, 0);
	////////////////////////////////////////////////////////////////
}