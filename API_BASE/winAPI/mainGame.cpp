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
	player = { 100,0,160,100 };
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
	 Rectangle(getMemDC(), player.left, player.top, player.right, player.bottom);
	 test1->render();
	 TIMEMANAGER->render(getMemDC());

	 /////////////////////�׷��ִºκ� - �ǵ�������//////////////////
	 this->getBackBuffer()->render(getHDC(), 0, 0);
	 ////////////////////////////////////////////////////////////////
 }