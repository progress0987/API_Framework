#include "stdafx.h"
#include "mainGame.h"

RECT rtemp;
mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
//초기화
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
//해제
 void mainGame::release(void)
 {//사용한 이미지도 릴리즈해줘야함
	 gameNode::release();
	 SAFE_DELETE(_map);
	 SAFE_DELETE(_village);
	 SAFE_DELETE(_park);
	 SAFE_DELETE(_boss);
	 SAFE_DELETE(_forest);
	 SAFE_DELETE(_hill);
	 SAFE_DELETE(_market);

 }
 //연산~
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

	 //캐릭터 움직임
	 Playermove();
	 //포탈
	 SceneChange();
	 TestScene->update();
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

	
	 TestScene->render();
	// TIMEMANAGER->render(getMemDC());

	


	 Rectangle(getMemDC(), player.rc.left, player.rc.top, player.rc.right, player.rc.bottom);
	

	 /////////////////////그려주는부분 - 건들지말것//////////////////
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
	 //마을에서 왼쪽포탈 타면 언덕 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_village->getlefeportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _hill;
		 TestScene->init();
	 }
	 //언덕에서 포탈 타면 마을 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_hill->getportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _village;
		 TestScene->init();
	 }
	 //마을에서 오른쪽포탈 타면 숲 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_village->getrightportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _forest;
		 TestScene->init();
	 }
	 //숲에서 포탈 타면 마을 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_forest->getportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _village;
		 TestScene->init();
	 }
	 //마을에서 상점 포탈 타면 상점 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_village->getstoreportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _map;
		 TestScene->init();
	 }
	 //상점에서  포탈 타면 마을 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_map->getportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _village;
		 TestScene->init();
	 }
	 //마을에서 시장 포탈 타면 시장 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_village->getmarketportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _market;
		 TestScene->init();
	 }
	 //시장에서 포탈 타면 마을 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_market->getportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _village;
		 TestScene->init();
	 }
	 //마을에서 공원 포탈 타면 공원 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_village->getparkportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _park;
		 TestScene->init();
	 }
	
	 //공원에서  왼쪽 포탈 타면 마을 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_park->getleftportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _village;
		 TestScene->init();
	 }
	 //공원에서  오른쪽 포탈 타면 보스 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_park->getrightportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _boss;
		 TestScene->init();
	 }
	 //보스맵에서 포탈 타면 공원 맵으로 이동
	 if (IntersectRect(&temp, &player.rc, &_boss->getportal().rc) && KEYMANAGER->isStayKeyDown('W'))
	 {
		 TestScene = _park;
		 TestScene->init();
	 }
	 
 }
