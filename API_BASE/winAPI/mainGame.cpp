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
//�ʱ�ȭ
HRESULT mainGame::init(void) 
{
	gameNode::init(true);
	IMAGEMANAGER->addImage("test", "sprites/a.bmp", 26, 124, TRUE, RGB(255, 0, 255));

	return S_OK;
}
//����
 void mainGame::release(void)
 {//����� �̹����� �������������
	 gameNode::release();
 }
 //����~
 void mainGame::update(void)
 {
	 gameNode::update();
	 testing++;
	 if (testing > 360)
		 testing = 0;

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

	 //TIMEMANAGER->render(getMemDC());
	 IMAGEMANAGER->findImage("test")->rotatedRender(getMemDC(), 100, 100, (float)testing);
	 IMAGEMANAGER->findImage("test")->rotatedRender(getMemDC(),100,300,10,10,(float)testing);

	 /////////////////////�׷��ִºκ� - �ǵ�������//////////////////
	 this->getBackBuffer()->render(getHDC(), 0, 0);
	 ////////////////////////////////////////////////////////////////
 }