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
	srand(time(NULL));
	imgInit();
	soundInit();
	cam = new Camera;
	cam->camPoint.x = 0;
	cam->camPoint.y = 0;
	cam->width = WINSIZEX;
	cam->height = WINSIZEY;
	_player = new player;
	em = new enemyManager;

	_player->setCamera(cam);
	_player->linkEnemyManager(em);
	em->init(cam);
	em->addMonster();

	_village = new VillageMap;
	_village->init();
	_village->setCam(cam);

	_map = new StoreMap;
	_map->init();
	_map->setCam(cam);

	_park = new ParkMap;
	_park->init();
	_park->setCam(cam);

	_hill = new HillMap;
	_hill->init();
	_hill->setCam(cam);

	_market = new MarketMap;
	_market->init();
	_market->setCam(cam);

	_forest = new ForestMap;
	_forest->init();
	_forest->setCam(cam);

	_boss = new BossMap;
	_boss->init();
	_boss->setCam(cam);

	curScene = _village;
	curScene->soundplay();

	_player->init(pointMake(1660, 400), curScene);
	
	//UI = new UserInterface;

	//UI->init();

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
	em->SharePlayer(_player->getRc(), curScene->getIndex());
	em->colling(_player->getDmgRC(), 100, curScene->getIndex());
	em->update(curScene->getIndex());
	curScene->update();
	_player->update();
	if (_player->sceneChange) {
		onSceneChange = true;
	}

	if (onSceneChange) {
		fadeAlpha+=10;
		if (fadeAlpha >= 255) {
			fadeAlpha = 255;
			onSceneChange = false;
			curScene->soundoff();
			//씬 체인지
			_player->sceneChange = false;//씬 체인지 받았으니 더이상 바꿔줄 필요가 없음
			SceneChange(getNextNode());
			SceneChanged = true;
		}
	}
	if (SceneChanged) {
		fadeAlpha-=10;
		if (fadeAlpha <= 0) {
			fadeAlpha = 0;
			SceneChanged = false;
			_player->sceneChangeFinished = true;
			curScene->soundplay();
			
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_TAB)) {
		debug = !debug;
	}

	//UI->update();

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
	if (debug) {
		curScene->getBack()->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y,cam->width,cam->height);
	}
	em->render(curScene->getIndex());
	_player->render();
	if (onSceneChange) {
		IMAGEMANAGER->findImage("fade")->alphaRender(getMemDC(), fadeAlpha);
	}
	if (SceneChanged) {
		IMAGEMANAGER->findImage("fade")->alphaRender(getMemDC(), fadeAlpha);
	}

	//IMAGEMANAGER->render("인터페이스", getMemDC(), 0, 0);

	//UI->render();

	TIMEMANAGER->render(getMemDC());
	/////////////////////////////
	////이하 테스트중
	////////////////////////////

	//CString strImgPath = _T("sprites/portal.png");
	//CString strHP = _T("sprites/hp.bmp");

	//CImage Image,hp;
	//HRESULT hResult = Image.Load(strImgPath);
	////HRESULT res1 = hp.Load(strHP);

	//if (FAILED(hResult)) {
	//	return;
	//}
	////if (FAILED(res1))return;
	////hp.SetTransparentColor(RGB(255,0,255));
	////hp.Draw(getMemDC(), 225, 228);
	////Image.Draw(getMemDC(), 200, 200);
	//Image.AlphaBlend(getMemDC(), 200, 200, 150);
	//


	/////////////////////그려주는부분 - 건들지말것//////////////////
	this->getBackBuffer()->render(getHDC(), 0, 0);
	////////////////////////////////////////////////////////////////
}

void mainGame::imgInit()
{

	IMAGEMANAGER->addFrameImage("캐릭터", "sprites/character.bmp", 400, 1000, 4, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("캐릭터공격", "sprites/attack.bmp", 700, 200, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("인터페이스", "sprites/UI/인터페이스.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fade", "sprites/fade.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	/////////////////////////////////////////////////////////몬스터//////////////////////////////////////////////////
	IMAGEMANAGER->addFrameImage("harpM", "sprites/monster/HarpM.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpS", "sprites/monster/HarpS.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpD", "sprites/monster/HarpD.bmp", 81, 206, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("GrupinM", "sprites/monster/GrupinM.bmp", 180, 126, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("GrupinS", "sprites/monster/GrupinS.bmp", 240, 126, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("GrupinD", "sprites/monster/GrupinD.bmp", 180, 126, 3, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("CellionM", "sprites/monster/CellionM.bmp", 180, 126, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("CellionS", "sprites/monster/CellionS.bmp", 240, 126, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("CellionD", "sprites/monster/CellionD.bmp", 180, 126, 3, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("LionerM", "sprites/monster/LionerM.bmp", 180, 126, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("LionerS", "sprites/monster/LionerS.bmp", 240, 126, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("LionerD", "sprites/monster/LionerD.bmp", 180, 126, 3, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("LucidaM", "sprites/monster/LucidaM.bmp", 186, 168, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("LucidaS", "sprites/monster/LucidaS.bmp", 248, 168, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("LucidaD", "sprites/monster/LucidaD.bmp", 186, 168, 3, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("Jr YetiM", "sprites/monster/LeattyM.bmp", 156, 80, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Jr YetiS", "sprites/monster/LeattyS.bmp", 312, 80, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Jr YetiD", "sprites/monster/LeattyD.bmp", 39, 80, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("PePeM", "sprites/monster/PePeM.bmp", 219, 166, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PePeS", "sprites/monster/PePeS.bmp", 438, 166, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("PePeD", "sprites/monster/PePeD.bmp", 146, 166, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("SheepM", "sprites/monster/SheepM.bmp", 368, 122, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SheepS", "sprites/monster/SheepS.bmp", 368, 122, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SheepD", "sprites/monster/SheepD.bmp", 276, 122, 3, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("JCellionM", "sprites/monster/JCellionM.bmp", 172, 94, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("JCellionS", "sprites/monster/JCellionS.bmp", 172, 94, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("JCellionD", "sprites/monster/JCellionD.bmp", 86, 94, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("JGrupinM", "sprites/monster/JGrupinM.bmp", 172, 94, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("JGrupinS", "sprites/monster/JGrupinS.bmp", 172, 94, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("JGrupinD", "sprites/monster/JGrupinD.bmp", 86, 94, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("JLionerM", "sprites/monster/JLionerM.bmp", 172, 94, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("JLionerS", "sprites/monster/JLionerS.bmp", 172, 94, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("JLionerD", "sprites/monster/JLionerD.bmp", 86, 94, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("JLucidaM", "sprites/monster/JLucidaM.bmp", 180, 114, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("JLucidaS", "sprites/monster/JLucidaS.bmp", 180, 114, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("JLucidaD", "sprites/monster/JLucidaD.bmp", 90, 114, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("ElizaM", "sprites/monster/ElizaM.bmp", 1200, 322, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ElizaS", "sprites/monster/ElizaS.bmp", 1200, 322, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ElizaD", "sprites/monster/ElizaD.bmp", 200, 322, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ElizaSkill1", "sprites/monster/skill1.bmp", 1488, 222, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("ElizaSkill2", "sprites/monster/skill2.bmp", 5115, 286, 15, 1, true, RGB(0, 0, 0));

	//////////////////////////////포탈 이미지//////////////////////////////////
	IMAGEMANAGER->addFrameImage("portal",		"sprites/map/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	///////////////////////////NPC//////////////////////////////
	IMAGEMANAGER->addFrameImage("gujigirl",		"sprites/npc/gujiGirl.bmp", 352, 71, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lina",			"sprites/npc/Lina.bmp", 600, 67, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orange",		"sprites/npc/OrangeHair.bmp", 322, 66, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ming",			"sprites/npc/MingMing.bmp", 432, 276, 9, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("storenpc", "sprites/npc/storeNPC.bmp", 457, 71, 8, 1, true, RGB(255, 0, 255));

	/////////////////////////////////////////지도/////////////////////////////////////////////////
	IMAGEMANAGER->addImage("village",			"sprites/map/파괴된 헤네시스(원본).bmp", 3495, 947, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pixelvillage",		"sprites/map/파괴된 헤네시스.bmp", 3495, 947, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("store",				"sprites/map/잡화상점(원본).bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pixelstore",		"sprites/map/잡화상점.bmp", WINSIZEX, WINSIZEY, true, (255, 0, 0));
	IMAGEMANAGER->addImage("park",				"sprites/map/파헤공원(원본).bmp", 1951, 1024, false, RGB(255, 0, 255));	//배경
	IMAGEMANAGER->addImage("pixelpark",			"sprites/map/파헤공원.bmp", 1951, 1024, false, RGB(255, 0, 255));//픽셀충돌
	IMAGEMANAGER->addImage("market",			"sprites/map/MarketMap(원본).bmp", 1807, 986, false, RGB(255, 0, 255));//배경
	IMAGEMANAGER->addImage("pixelmarket",		"sprites/map/MarketMap.bmp", 1807, 986, false, RGB(255, 0, 255));//픽셀
	IMAGEMANAGER->addImage("hill",				"sprites/map/HillMap(원본).bmp", 2075, 1047, false, RGB(255, 0, 255));	//배경
	IMAGEMANAGER->addImage("pixelhill",			"sprites/map/HillMap.bmp", 2075, 1047, false, RGB(255, 0, 255));	//픽셀
	IMAGEMANAGER->addImage("forest",			"sprites/map/ForestMap(원본).bmp", 1365, 1034, false, RGB(255, 0, 255));	//배경
	IMAGEMANAGER->addImage("pixelforest",		"sprites/map/ForestMap.bmp", 1365, 1034, false, RGB(255, 0, 255));	//픽셀
	IMAGEMANAGER->addImage("boss",				"sprites/map/BossMap(원본).bmp", 1684, 903, false, RGB(255, 0, 255));	//배경
	IMAGEMANAGER->addImage("pixelboss",			"sprites/map/BossMap.bmp", 1684, 903, false, RGB(255, 0, 255));	//픽셀
	////////////////////////////////////////////스킬//////////////////////////////////////////////////
	IMAGEMANAGER->addFrameImage("skill1",		"sprites/skill/skill1.bmp", 5320, 278, 20, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("skill2",		"sprites/skill/skill2.bmp", 1080, 226, 6, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("skill3",		"sprites/skill/skill3.bmp", 2375, 83, 5, 1, true, RGB(255, 0, 255));


	////////////////////////////////////////////////아이템//////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("쭈쭈바", "쭈쭈바.bmp", 31, 31, true, NULL);
	IMAGEMANAGER->addImage("파란포션", "파란포션.bmp", 27, 27, true, NULL);
	IMAGEMANAGER->addImage("팥빙수", "팥빙수.bmp", 26, 30, true, NULL);
	IMAGEMANAGER->addImage("하얀포션", "하얀포션.bmp", 27, 27, true, NULL);


	//////////////////////////////////////////////UI//////////////////////////////////////////////////////
	//------------------------------------커서----------------------------------------------
	IMAGEMANAGER->addFrameImage("커서", "sprites/UI/Cursor.bmp", 120, 120, 4, 4, true, RGB(255, 255, 255));


	IMAGEMANAGER->addImage("아이템정보창",	"sprites/UI/아이템정보창.bmp", 220, 300, false, NULL);
	//------------------------------------공용-----------------------------------------------
	IMAGEMANAGER->addImage("닫기",			"sprites/UI/닫기.bmp", 13, 13, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("닫기마우스온",	"sprites/UI/닫기(MouseOn).bmp", 13, 13, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("닫기클릭",		"sprites/UI/닫기(clicked).bmp", 13, 13, true, RGB(0, 0, 0));

	//-------------------------------------인벤토리------------------------------------------
	IMAGEMANAGER->addImage("인벤토리창",		"sprites/UI/아이템인벤토리.bmp", 172, 335, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("장비탭",			"sprites/UI/장비탭.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("소비탭",			"sprites/UI/소비탭.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("기타탭",			"sprites/UI/기타탭.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("그림자",			"sprites/UI/shadow.bmp", 26, 6, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("0",					"sprites/UI/0.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("1",					"sprites/UI/1.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("2",					"sprites/UI/2.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("3",					"sprites/UI/3.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("4",					"sprites/UI/4.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("5",					"sprites/UI/5.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("6",					"sprites/UI/6.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("7",					"sprites/UI/7.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("8",					"sprites/UI/8.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("9",					"sprites/UI/9.bmp", 8, 11, true, RGB(0, 0, 0));



	//-----------------------------------장비창-----------------------------------------------
	IMAGEMANAGER->addImage("장비창",			"sprites/UI/장비인벤토리.bmp", 232, 330, true, RGB(255, 0, 255));

	//-------------------------------------스텟창--------------------------------------------

	IMAGEMANAGER->addImage("스텟창",			"sprites/UI/스텟창.bmp", 212, 318, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("업",				"sprites/UI/업.bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("업마우스온",		"sprites/UI/업(MouseOn).bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("업클릭",			"sprites/UI/업(clicked).bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("자동배분버튼활성화","sprites/UI/자동배분버튼활성화.bmp", 67, 34, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("자동배분버튼눌림",	"sprites/UI/자동배분버튼눌림.bmp", 67, 34, true, RGB(255, 0, 255));

	//------------------------------------인터페이스-----------------------------------------

	//체력, 아이디, 레벨 사각형
	IMAGEMANAGER->addImage("게이지테두리",		"sprites/UI/게이지테두리(비트).bmp", 204, 70, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("마나",				"sprites/UI/마나바(비트).bmp", 171, 13, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("체력",				"sprites/UI/체력바(비트).bmp", 171, 13, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Lv",				"sprites/UI/Lv.bmp", 15, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자0",			"sprites/UI/레벨숫자0.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자1",			"sprites/UI/레벨숫자1.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자2",			"sprites/UI/레벨숫자2.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자3",			"sprites/UI/레벨숫자3.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자4",			"sprites/UI/레벨숫자4.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자5",			"sprites/UI/레벨숫자5.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자6",			"sprites/UI/레벨숫자6.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자7",			"sprites/UI/레벨숫자7.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자8",			"sprites/UI/레벨숫자8.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자9",			"sprites/UI/레벨숫자9.bmp", 7, 10, true, RGB(255, 255, 255));

	//경험치바
	IMAGEMANAGER->addImage("경험치0",			"sprites/UI/경험치(0)비트.bmp", 1366, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("경험치2",			"sprites/UI/경험치(2)비트.bmp", 1350, 7, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("경험치3",			"sprites/UI/경험치(3)비트.bmp", 1082, 7, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("경험치4",			"sprites/UI/경험치이펙트(3)비트.bmp", 13, 17, true, RGB(255, 0, 255));

	//퀵슬롯
	IMAGEMANAGER->addImage("퀵슬롯0",			"sprites/UI/퀵슬롯(0).bmp", 350, 67, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵슬롯왼쪽테두리",	"sprites/UI/퀵슬롯왼쪽테두리.bmp", 13, 71, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("퀵슬롯커버",		"sprites/UI/퀵슬롯커버.bmp", 351, 73, true, RGB(255, 255, 255));

	//퀵슬롯단축키
	IMAGEMANAGER->addImage("퀵1",				"sprites/UI/퀵1.bmp", 7, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵2",				"sprites/UI/퀵2.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵3",				"sprites/UI/퀵3.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵4",				"sprites/UI/퀵4.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵5",				"sprites/UI/퀵5.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵6",				"sprites/UI/퀵6.bmp", 10, 9, true, RGB(255, 255, 255));


	IMAGEMANAGER->addImage("pgup",				"sprites/UI/pgup.bmp", 22, 11, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("pgdn",				"sprites/UI/pgdn.bmp", 22, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("inst",				"sprites/UI/insert.bmp", 18, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("hm",				"sprites/UI/hm.bmp", 19, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("end",				"sprites/UI/end.bmp", 22, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("del",				"sprites/UI/delete.bmp", 19, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("ctrl",				"sprites/UI/ctrl.bmp", 23, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("shift",				"sprites/UI/Shift.bmp", 28, 9, true, RGB(255, 255, 255));


	IMAGEMANAGER->addImage("Q",					"sprites?UI/Q.bmp", 10, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("W",					"sprites?UI/W.bmp", 12, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("E",					"sprites?UI/E.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("R",					"sprites?UI/R.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("T",					"sprites?UI/T.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("A",					"sprites?UI/A.bmp", 10, 9, true, RGB(255, 255, 255));
}

void mainGame::soundInit()
{
	//맵 사운드
	SOUNDMANAGER->addSound("Boss", "sound/BossBgm.mp3", true, true);
	SOUNDMANAGER->addSound("Hill", "sound/HillBgm.mp3", true, true);
	SOUNDMANAGER->addSound("Forest", "sound/ForestBgm.mp3", true, true);
	SOUNDMANAGER->addSound("Store", "sound/StoreBgm.mp3", true, true);
	SOUNDMANAGER->addSound("Market", "sound/MarketBgm.mp3", true, true);
	SOUNDMANAGER->addSound("Park", "sound/ParkBgm.mp3", true, true);
	SOUNDMANAGER->addSound("Village", "sound/VillageBgm.mp3", true, true);
}



void mainGame::SceneChange(mapFrame * next)
{

	//잘못된 좌표라면 그냥 나옴
	if (next == nullptr)return;
	curScene->soundoff();
	//다음 갈 포탈 좌표위쪽에 좌표 정해주고 씬을 바꾸며 init을 해줌
	_player->init(playerNextPoint, next);

}

//현재 있는 곳의 좌표를 찾아주고 다음 움직일 맵의 정보를 받아옴
mapFrame * mainGame::getNextNode()
{
	mapFrame* nextMap;
	int mapindex=-1, portalindex=-1;
	for (int i = 0; i < curScene->getPortals().size(); i++) {
		if (IntersectRect(&RECT(), &curScene->getPortals()[i].rc, &_player->getHitRC())) {
			mapindex = curScene->getIndex();
			portalindex = curScene->getPortals()[i].pattern;
			break;
		}
	}
	if(mapindex<0||portalindex<0){//맵이나 포탈 하나라도 에러가 있으면 에러 출력
		return nullptr;
	}
	//현재 플레이어가 있는 좌표에서 갈 다음 맵을 찾는다 - PlayerNextPoint에 좌표 저장해줌
	switch (mapindex) {
	case MapIndex::MVillage:																			//마을
		switch (portalindex) {
		case 0:																							//왼쪽포탈 - Hill
			//리스폰될 자리 맞춰주기
			playerNextPoint.x = _hill->getPortals()[0].x;
			playerNextPoint.y = _hill->getPortals()[0].y-50;
			nextMap =curScene = _hill;
			break;
		case 1:																							//오른쪽포탈 - Forest
			playerNextPoint.x = _forest->getPortals()[0].x;
			playerNextPoint.y = _forest->getPortals()[0].y-50;
			nextMap =curScene = _forest;
			break;
		case 2:																							//상점포탈
			playerNextPoint.x = _map->getPortals()[0].x;
			playerNextPoint.y = _map->getPortals()[0].y-50;
			nextMap = curScene = _map;
			break;
		case 3:																							//공원포탈
			playerNextPoint.x =  _park->getPortals()[0].x;
			playerNextPoint.y =  _park->getPortals()[0].y-50;
			nextMap = curScene = _park;
			break;
		case 4:																							//시장포탈
			playerNextPoint.x =  _market->getPortals()[0].x;
			playerNextPoint.y =  _market->getPortals()[0].y-50;
			nextMap = curScene = _market;
			break;
		}
		break;
	case MapIndex::MStore:																				//상점
		switch (portalindex) {
		case 0:																							//마을로
			playerNextPoint.x =  _village->getPortals()[2].x;
			playerNextPoint.y =  _village->getPortals()[2].y-50;
			nextMap = curScene = _village;
			break;
		}
		break;
	case MapIndex::MPark:																				//공원
		switch (portalindex) {
		case 0:																							//마을로
			playerNextPoint.x = _village->getPortals()[3].x;
			playerNextPoint.y = _village->getPortals()[3].y - 50;
			nextMap = curScene = _village;
			break;
		case 1:																							//보스포탈
			playerNextPoint.x =  _boss->getPortals()[0].x;
			playerNextPoint.y =  _boss->getPortals()[0].y - 50;
			nextMap = curScene = _boss;
			break;
		}
		break;
	case MapIndex::MMarket:																				//시장
		switch (portalindex) {
		case 0:																							//마을
			playerNextPoint.x = _village->getPortals()[4].x;
			playerNextPoint.y = _village->getPortals()[4].y - 50;
			nextMap = curScene = _village;
			break;
		}
		break;
	case MapIndex::MHill:																				//언덕
		switch (portalindex) {
		case 0:																							//마을
			playerNextPoint.x = _village->getPortals()[0].x;
			playerNextPoint.y = _village->getPortals()[0].y - 50;
			nextMap = curScene = _village;
			break;
		}
		break;
	case MapIndex::MForest:																				//숲
		switch (portalindex) {
		case 0:																							//마을
			playerNextPoint.x = _village->getPortals()[1].x;
			playerNextPoint.y = _village->getPortals()[1].y - 50;
			nextMap = curScene = _village;
			break;
		}
		break;
	case MapIndex::MBoss:																				//보스
		switch (portalindex) {
		case 0:																							//공원
			playerNextPoint.x = _park->getPortals()[1].x;
			playerNextPoint.y = _park->getPortals()[1].y - 50;
			nextMap = curScene = _park;
			break;
		}
		break;
	}
	return nextMap;
}
