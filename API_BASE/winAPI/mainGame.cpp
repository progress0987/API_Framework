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
	
	AddFontResourceA("Maplestory Light.ttf");
		
	_map = new StoreMap;
	_map->init();

	_village = new VillageMap;
	_village->init();

	_park = new ParkMap;
	_park->init();

	_boss = new BossMap;
	_boss->init();

	_forest = new ForestMap;
	_forest->init();

	_hill = new HillMap;
	_hill->init();

	_market = new MarketMap;
	_market->init();

	TestScene = _village;
	
	player.rc = RectMakeCenter(500, 500, 30, 80);

	return S_OK;
}
//����
 void mainGame::release(void)
 {//����� �̹����� �������������
	 gameNode::release();
	 SAFE_DELETE(_map);
	 SAFE_DELETE(_village);
	 SAFE_DELETE(_park);
	 SAFE_DELETE(_boss);
	 SAFE_DELETE(_forest);
	 SAFE_DELETE(_hill);
	 SAFE_DELETE(_market);

 }
 //����~
 void mainGame::update(void)
 {
	 gameNode::update();
	 /*_map->update();
	 _village->update();
	 _park->update();
	 _boss->update();
	 _forest->update();
	 _hill->update();
	 _market->update();*/

	 //ĳ���� ������
	 Playermove();
	 //��Ż
	 SceneChange();
	 TestScene->update();
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

	
	 TestScene->render();
	// TIMEMANAGER->render(getMemDC());

	


	 Rectangle(getMemDC(), player.rc.left, player.rc.top, player.rc.right, player.rc.bottom);
	

	 /////////////////////�׷��ִºκ� - �ǵ�������//////////////////
	 this->getBackBuffer()->render(getHDC(), 0, 0);
	 ////////////////////////////////////////////////////////////////
 }

 void mainGame::Playermove()
 {

	 if (KEYMANAGER->isStayKeyDown('A'))
	 {
		 player.rc.left -= 3;
		 player.rc.right -= 3;
	 }
	 if (KEYMANAGER->isStayKeyDown('D'))
	 {
		 player.rc.left += 3;
		 player.rc.right += 3;
	 }
	 if (KEYMANAGER->isStayKeyDown('S'))
	 {
		 player.rc.top += 3;
		 player.rc.bottom += 3;
	 }
	 if (KEYMANAGER->isStayKeyDown('W'))
	 {
		 player.rc.top -= 3;
		 player.rc.bottom -= 3;
	 }
 }

 void mainGame::SceneChange()
 {
	 RECT temp;
	 //�������� ������Ż Ÿ�� ��� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_village->getlefeportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _hill;
		 TestScene->init();
	 }
	 //������� ��Ż Ÿ�� ���� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_hill->getportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _village;
		 TestScene->init();
	 }
	 //�������� ��������Ż Ÿ�� �� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_village->getrightportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _forest;
		 TestScene->init();
	 }
	 //������ ��Ż Ÿ�� ���� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_forest->getportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _village;
		 TestScene->init();
	 }
	 //�������� ���� ��Ż Ÿ�� ���� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_village->getstoreportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _map;
		 TestScene->init();
	 }
	 //��������  ��Ż Ÿ�� ���� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_map->getportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _village;
		 TestScene->init();
	 }
	 //�������� ���� ��Ż Ÿ�� ���� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_village->getmarketportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _market;
		 TestScene->init();
	 }
	 //���忡�� ��Ż Ÿ�� ���� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_market->getportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _village;
		 TestScene->init();
	 }
	 //�������� ���� ��Ż Ÿ�� ���� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_village->getparkportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _park;
		 TestScene->init();
	 }
	
	 //��������  ���� ��Ż Ÿ�� ���� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_park->getleftportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _village;
		 TestScene->init();
	 }
	 //��������  ������ ��Ż Ÿ�� ���� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_park->getrightportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _boss;
		 TestScene->init();
	 }
	 //�����ʿ��� ��Ż Ÿ�� ���� ������ �̵�
	 if (IntersectRect(&temp, &player.rc, &_boss->getportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _park;
		 TestScene->init();
	 }
	 
 }
