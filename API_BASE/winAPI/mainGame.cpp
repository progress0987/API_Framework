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
	//IMAGEMANAGER->findImage("맵")->render(IMAGEMANAGER->findImage("맵")->getMemDC());
	imgInit();
	cam = new Camera;
	cam->camPoint.x = 0;
	cam->camPoint.y = 0;
	cam->width = WINSIZEX;
	cam->height = WINSIZEY;
	_player = new player;
	em = new enemyManager;

	_player->setCamera(cam);
	em->init(cam);


	Harp* test1;
	POINT test = { 200,100 };
	test1 = new Harp;
	test1->SetCam(cam);
	test1->init(test);
	em->addMonster(test1);

	_village = new VillageMap;
	_village->init();
	_village->setCam(cam);
	curScene = _village;
	_player->init(pointMake(500, 500), curScene);

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

	curScene->update();
	_player->update();
	//em->update();
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

	//IMAGEMANAGER->render("맵", getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, WINSIZEX, WINSIZEY);
	//IMAGEMANAGER->findImage("미니맵")->alphaRender(getMemDC(), 0, 0, 150);
	curScene->render();
	_player->render();
	//em->render();


	IMAGEMANAGER->render("인터페이스", getMemDC(), 0, 0);

	TIMEMANAGER->render(getMemDC());
	/////////////////////그려주는부분 - 건들지말것//////////////////
	this->getBackBuffer()->render(getHDC(), 0, 0);
	////////////////////////////////////////////////////////////////
}

void mainGame::imgInit()
{

	IMAGEMANAGER->addImage("인터페이스", "sprites/인터페이스.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpM", "sprites/monster/HarpM.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpS", "sprites/monster/HarpS.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpD", "sprites/monster/HarpD.bmp", 81, 206, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("캐릭터", "sprites/character.bmp", 400, 1000, 4, 10, true, RGB(255, 0, 255));

	//////////////////////////////포탈 이미지//////////////////////////////////
	IMAGEMANAGER->addFrameImage("portal", "sprites/map/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	///////////////////////////NPC//////////////////////////////
	IMAGEMANAGER->addFrameImage("gujigirl",		"sprites/npc/gujiGirl.bmp", 352, 71, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lina",			"sprites/npc/Lina.bmp", 600, 67, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orange",		"sprites/npc/OrangeHair.bmp", 322, 66, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ming",			"sprites/npc/MingMing.bmp", 432, 276, 9, 4, true, RGB(255, 0, 255));

	/////////////////////////////////////////지도/////////////////////////////////////////////////
	IMAGEMANAGER->addImage("village",			"sprites/map/파괴된 헤네시스(원본).bmp", 3495, 947, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pixelvillage",		"sprites/map/파괴된 헤네시스.bmp", 3495, 947, false, RGB(255, 0, 255));

}
