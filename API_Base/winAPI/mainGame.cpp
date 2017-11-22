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


	_player->init(cam);
	em->init(cam);


	Harp* test1;
	POINT test = { 200,100 };
	test1 = new Harp;
	test1->SetCam(cam);
	test1->init(test);
	em->addMonster(test1);

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

	_player->update();
	em->update();
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

	IMAGEMANAGER->render("��", getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->findImage("�̴ϸ�")->alphaRender(getMemDC(), 0, 0, 150);

	_player->render();
	em->render();


	IMAGEMANAGER->render("�������̽�", getMemDC(), 0, 0);

	TIMEMANAGER->render(getMemDC());
	/////////////////////�׷��ִºκ� - �ǵ�������//////////////////
	this->getBackBuffer()->render(getHDC(), 0, 0);
	////////////////////////////////////////////////////////////////
}

void mainGame::imgInit()
{
	IMAGEMANAGER->addImage("�̴ϸ�", "sprites/map/�������(����).bmp", 1951 / 10, 1024 / 10, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "sprites/map/�������(����).bmp", 1951, 1024, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "sprites/map/�������.bmp", 1951, 1024, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������̽�", "sprites/�������̽�.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpM", "sprites/monster/HarpM.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpS", "sprites/monster/HarpS.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpD", "sprites/monster/HarpD.bmp", 81, 206, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ĳ����", "sprites/character.bmp", 400, 1000, 4, 10, true, RGB(255, 0, 255));
}
