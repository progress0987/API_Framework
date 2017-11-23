#include "stdafx.h"
#include "mainGame.h"

//�����ڶ� �Ҹ��ڴ� ���� �ʴ´�..//
mainGame::mainGame()
{

}
//�����ڶ� �Ҹ��ڴ� ���� �ʴ´�..//
mainGame::~mainGame()
{

}
HRESULT mainGame::init(void)
{
	gameNode::init(true);
	//IMAGEMANAGER->findImage("��")->render(IMAGEMANAGER->findImage("��")->getMemDC());
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
//����
void mainGame::release(void)
{//����� �̹����� �������������
	gameNode::release();
	_player->release();
}
//����~
void mainGame::update(void)
{
	gameNode::update();

	curScene->update();
	_player->update();
	//em->update();
}
//���Ⱑ �׷��ִ� ��
void mainGame::render()
{
	HBRUSH brush;
	HBITMAP hBitmap, OldBitmap;
	/////////////////////////////////////�ǵ��� ����(?)//////////////////////////////////////////////
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//////////////////////////////////////////////////////////////////////////////////////////////
	//getmemdc�� �־���

	//IMAGEMANAGER->render("��", getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, WINSIZEX, WINSIZEY);
	//IMAGEMANAGER->findImage("�̴ϸ�")->alphaRender(getMemDC(), 0, 0, 150);
	curScene->render();
	_player->render();
	//em->render();


	IMAGEMANAGER->render("�������̽�", getMemDC(), 0, 0);

	TIMEMANAGER->render(getMemDC());
	/////////////////////�׷��ִºκ� - �ǵ�������//////////////////
	this->getBackBuffer()->render(getHDC(), 0, 0);
	////////////////////////////////////////////////////////////////
}

void mainGame::imgInit()
{

	IMAGEMANAGER->addImage("�������̽�", "sprites/�������̽�.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpM", "sprites/monster/HarpM.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpS", "sprites/monster/HarpS.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpD", "sprites/monster/HarpD.bmp", 81, 206, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ĳ����", "sprites/character.bmp", 400, 1000, 4, 10, true, RGB(255, 0, 255));

	//////////////////////////////��Ż �̹���//////////////////////////////////
	IMAGEMANAGER->addFrameImage("portal", "sprites/map/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	///////////////////////////NPC//////////////////////////////
	IMAGEMANAGER->addFrameImage("gujigirl",		"sprites/npc/gujiGirl.bmp", 352, 71, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lina",			"sprites/npc/Lina.bmp", 600, 67, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orange",		"sprites/npc/OrangeHair.bmp", 322, 66, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ming",			"sprites/npc/MingMing.bmp", 432, 276, 9, 4, true, RGB(255, 0, 255));

	/////////////////////////////////////////����/////////////////////////////////////////////////
	IMAGEMANAGER->addImage("village",			"sprites/map/�ı��� ��׽ý�(����).bmp", 3495, 947, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pixelvillage",		"sprites/map/�ı��� ��׽ý�.bmp", 3495, 947, false, RGB(255, 0, 255));

}
