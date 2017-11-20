#include "stdafx.h"
#include "mainGame.h"

RECT rtemp;
//ȫ�� �׽�Ʈ
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
	srand(time(NULL));
	base = { 0,0 };
	POINT test = { base.x+200,base.y+100 };
	test1 = new Harp;
	test1->SetPoint(test);
	test1->init();
	//�׽�Ʈ�� ��
	IMAGEMANAGER->addImage("map","image/�ı��� ��׽ý�.bmp", 3495, 947,false,RGB(255,0,255));
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
 //���Ⱑ �׷��ִ� ��
 void mainGame::render() 
 {
	 HBRUSH brush;
	 HBITMAP hBitmap, OldBitmap;
	 /////////////////////////////////////�ǵ��� ����(?)//////////////////////////////////////////////
	 PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	 //////////////////////////////////////////////////////////////////////////////////////////////
	 //getmemdc�� �־���
	 IMAGEMANAGER->findImage("map")->render(getMemDC(),base.x,base.y);
	 test1->render();
	 TIMEMANAGER->render(getMemDC());

	 /////////////////////�׷��ִºκ� - �ǵ�������//////////////////
	 this->getBackBuffer()->render(getHDC(), 0, 0);
	 ////////////////////////////////////////////////////////////////
 }