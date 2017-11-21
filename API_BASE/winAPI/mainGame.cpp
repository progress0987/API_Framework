#include "stdafx.h"
#include "mainGame.h"

RECT rtemp;
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

	_map = new StoreMap;
	_map->init();

	_village = new VillageMap;
	_village->init();

	_park = new ParkMap;
	_park->init();
	return S_OK;
}
//����
 void mainGame::release(void)
 {//����� �̹����� �������������
	 gameNode::release();
	 SAFE_DELETE(_map);
	 SAFE_DELETE(_village);
	 SAFE_DELETE(_park);

 }
 //����~
 void mainGame::update(void)
 {
	 gameNode::update();
	 _map->update();
	 _village->update();
	 _park->update();

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

	// _map->render();
	// _village->render();
	 _park->render();
	 TIMEMANAGER->render(getMemDC());

	 /////////////////////�׷��ִºκ� - �ǵ�������//////////////////
	 this->getBackBuffer()->render(getHDC(), 0, 0);
	 ////////////////////////////////////////////////////////////////
 }