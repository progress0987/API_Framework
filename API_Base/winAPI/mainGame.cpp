#include "stdafx.h"
#include "mainGame.h"

RECT rtemp;
//�±� �׽�Ʈ
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
	_player = new player;
	_inventory = new inventory;

	_player->init();

	return S_OK;
}
//����
 void mainGame::release(void)
 {//����� �̹����� �������������
	 gameNode::release();
	 _player->release();
	 _inventory->release();
 }
 //����~
 void mainGame::update(void)
 {
	 gameNode::update();

	 _player->update();
	 _inventory->update();
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

	 _player->render();
	 _inventory->render();

	 /////////////////////�׷��ִºκ� - �ǵ�������//////////////////
	 this->getBackBuffer()->render(getHDC(), 0, 0);
	 ////////////////////////////////////////////////////////////////
 }