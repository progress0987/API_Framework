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
	_player->init(pointMake(1660, 400), curScene);

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
	if (_player->sceneChange) {
		onSceneChange = true;
	}
	//em->update();


	if (onSceneChange) {
		fadeAlpha+=10;
		if (fadeAlpha >= 255) {
			fadeAlpha = 255;
			onSceneChange = false;
		_player->sceneChange = false;//�� ü���� �޾����� ���̻� �ٲ��� �ʿ䰡 ����
			//�� ü����
			SceneChange(getNextNode());
			SceneChanged = true;
		}
	}
	if (SceneChanged) {
		fadeAlpha-=10;
		if (fadeAlpha <= 0) {
			fadeAlpha = 0;
			SceneChanged = false;
			
		}
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

	//IMAGEMANAGER->render("��", getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, WINSIZEX, WINSIZEY);
	//IMAGEMANAGER->findImage("�̴ϸ�")->alphaRender(getMemDC(), 0, 0, 150);
	curScene->render();
	_player->render();
	//em->render();`
	if (onSceneChange) {
		IMAGEMANAGER->findImage("fade")->alphaRender(getMemDC(), fadeAlpha);
	}
	if (SceneChanged) {
		IMAGEMANAGER->findImage("fade")->alphaRender(getMemDC(), fadeAlpha);
	}


	IMAGEMANAGER->render("�������̽�", getMemDC(), 0, 0);

	TIMEMANAGER->render(getMemDC());
	/////////////////////�׷��ִºκ� - �ǵ�������//////////////////
	this->getBackBuffer()->render(getHDC(), 0, 0);
	////////////////////////////////////////////////////////////////
}

void mainGame::imgInit()
{

	IMAGEMANAGER->addFrameImage("ĳ����", "sprites/character.bmp", 400, 1000, 4, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ĳ���Ͱ���", "sprites/attack.bmp", 700, 200, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������̽�", "sprites/UI/�������̽�.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fade", "sprites/fade.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	/////////////////////////////////////////////////////////����//////////////////////////////////////////////////
	IMAGEMANAGER->addFrameImage("harpM", "sprites/monster/HarpM.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpS", "sprites/monster/HarpS.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpD", "sprites/monster/HarpD.bmp", 81, 206, 1, 2, true, RGB(255, 0, 255));

	//////////////////////////////��Ż �̹���//////////////////////////////////
	IMAGEMANAGER->addFrameImage("portal",		"sprites/map/Portal.bmp", 728, 138, 7, 1, true, RGB(255, 0, 255));
	///////////////////////////NPC//////////////////////////////
	IMAGEMANAGER->addFrameImage("gujigirl",		"sprites/npc/gujiGirl.bmp", 352, 71, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lina",			"sprites/npc/Lina.bmp", 600, 67, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("orange",		"sprites/npc/OrangeHair.bmp", 322, 66, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ming",			"sprites/npc/MingMing.bmp", 432, 276, 9, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("storenpc", "sprites/npc/storeNPC.bmp", 457, 71, 8, 1, true, RGB(255, 0, 255));

	/////////////////////////////////////////����/////////////////////////////////////////////////
	IMAGEMANAGER->addImage("village",			"sprites/map/�ı��� ��׽ý�(����).bmp", 3495, 947, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pixelvillage",		"sprites/map/�ı��� ��׽ý�.bmp", 3495, 947, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("store",				"sprites/map/��ȭ����(����).bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pixelstore",		"sprites/map/��ȭ����.bmp", WINSIZEX, WINSIZEY, true, (255, 0, 0));
	IMAGEMANAGER->addImage("park",				"sprites/map/�������(����).bmp", 1951, 1024, false, RGB(255, 0, 255));	//���
	IMAGEMANAGER->addImage("pixelpark",			"sprites/map/�������.bmp", 1951, 1024, false, RGB(255, 0, 255));//�ȼ��浹
	IMAGEMANAGER->addImage("market",			"sprites/map/MarketMap(����).bmp", 1807, 986, false, RGB(255, 0, 255));//���
	IMAGEMANAGER->addImage("pixelmarket",		"sprites/map/MarketMap.bmp", 1807, 986, false, RGB(255, 0, 255));//�ȼ�
	IMAGEMANAGER->addImage("hill",				"sprites/map/HillMap(����).bmp", 2075, 1047, false, RGB(255, 0, 255));	//���
	IMAGEMANAGER->addImage("pixelhill",			"sprites/map/HillMap.bmp", 2075, 1047, false, RGB(255, 0, 255));	//�ȼ�
	IMAGEMANAGER->addImage("forest",			"sprites/map/ForestMap(����).bmp", 1365, 1034, false, RGB(255, 0, 255));	//���
	IMAGEMANAGER->addImage("pixelforest",		"sprites/map/ForestMap.bmp", 1365, 1034, false, RGB(255, 0, 255));	//�ȼ�
	IMAGEMANAGER->addImage("boss",				"sprites/map/BossMap(����).bmp", 1684, 903, false, RGB(255, 0, 255));	//���
	IMAGEMANAGER->addImage("pixelboss",			"sprites/map/BossMap.bmp", 1684, 903, false, RGB(255, 0, 255));	//�ȼ�
	////////////////////////////////////////////��ų//////////////////////////////////////////////////
	IMAGEMANAGER->addFrameImage("skill1",		"sprites/skill/skill1.bmp", 5320, 278, 20, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("skill2",		"sprites/skill/skill2.bmp", 1080, 226, 6, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("skill3",		"sprites/skill/skill3.bmp", 2375, 83, 5, 1, true, RGB(255, 0, 255));


	////////////////////////////////////////////////������//////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("���޹�", "���޹�.bmp", 31, 31, true, NULL);
	IMAGEMANAGER->addImage("�Ķ�����", "�Ķ�����.bmp", 27, 27, true, NULL);
	IMAGEMANAGER->addImage("�Ϻ���", "�Ϻ���.bmp", 26, 30, true, NULL);
	IMAGEMANAGER->addImage("�Ͼ�����", "�Ͼ�����.bmp", 27, 27, true, NULL);


	//////////////////////////////////////////////UI//////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("����������â",	"sprites/UI/����������â.bmp", 220, 300, false, NULL);
	//------------------------------------����-----------------------------------------------
	IMAGEMANAGER->addImage("�ݱ�",			"sprites/UI/�ݱ�.bmp", 13, 13, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("�ݱ⸶�콺��",	"sprites/UI/�ݱ�(MouseOn).bmp", 13, 13, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("�ݱ�Ŭ��",		"sprites/UI/�ݱ�(clicked).bmp", 13, 13, true, RGB(0, 0, 0));

	//-------------------------------------�κ��丮------------------------------------------
	IMAGEMANAGER->addImage("�κ��丮â",		"sprites/UI/�������κ��丮.bmp", 172, 335, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����",			"sprites/UI/�����.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Һ���",			"sprites/UI/�Һ���.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ÿ��",			"sprites/UI/��Ÿ��.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�׸���",			"sprites/UI/shadow.bmp", 26, 6, true, RGB(255, 255, 255));
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



	//-----------------------------------���â-----------------------------------------------
	IMAGEMANAGER->addImage("���â",			"sprites/UI/����κ��丮.bmp", 232, 330, true, RGB(255, 0, 255));

	//-------------------------------------����â--------------------------------------------

	IMAGEMANAGER->addImage("����â",			"sprites/UI/����â.bmp", 212, 318, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��",				"sprites/UI/��.bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����콺��",		"sprites/UI/��(MouseOn).bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ŭ��",			"sprites/UI/��(clicked).bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ڵ���й�ưȰ��ȭ","sprites/UI/�ڵ���й�ưȰ��ȭ.bmp", 67, 34, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ڵ���й�ư����",	"sprites/UI/�ڵ���й�ư����.bmp", 67, 34, true, RGB(255, 0, 255));

	//------------------------------------�������̽�-----------------------------------------

	//ü��, ���̵�, ���� �簢��
	IMAGEMANAGER->addImage("�������׵θ�",		"sprites/UI/�������׵θ�(��Ʈ).bmp", 204, 70, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("����",				"sprites/UI/������(��Ʈ).bmp", 171, 13, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ü��",				"sprites/UI/ü�¹�(��Ʈ).bmp", 171, 13, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Lv",				"sprites/UI/Lv.bmp", 15, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������0",			"sprites/UI/��������0.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������1",			"sprites/UI/��������1.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������2",			"sprites/UI/��������2.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������3",			"sprites/UI/��������3.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������4",			"sprites/UI/��������4.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������5",			"sprites/UI/��������5.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������6",			"sprites/UI/��������6.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������7",			"sprites/UI/��������7.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������8",			"sprites/UI/��������8.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������9",			"sprites/UI/��������9.bmp", 7, 10, true, RGB(255, 255, 255));

	//����ġ��
	IMAGEMANAGER->addImage("����ġ0",			"sprites/UI/����ġ(0)��Ʈ.bmp", 1366, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����ġ2",			"sprites/UI/����ġ(2)��Ʈ.bmp", 1350, 7, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����ġ3",			"sprites/UI/����ġ(3)��Ʈ.bmp", 1082, 7, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("����ġ4",			"sprites/UI/����ġ����Ʈ(3)��Ʈ.bmp", 13, 17, true, RGB(255, 0, 255));

	//������
	IMAGEMANAGER->addImage("������0",			"sprites/UI/������(0).bmp", 350, 67, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("�����Կ����׵θ�",	"sprites/UI/�����Կ����׵θ�.bmp", 13, 71, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ŀ��",		"sprites/UI/������Ŀ��.bmp", 351, 73, true, RGB(255, 255, 255));

	//�����Դ���Ű
	IMAGEMANAGER->addImage("��1",				"sprites/UI/��1.bmp", 7, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��2",				"sprites/UI/��2.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��3",				"sprites/UI/��3.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��4",				"sprites/UI/��4.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��5",				"sprites/UI/��5.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��6",				"sprites/UI/��6.bmp", 10, 9, true, RGB(255, 255, 255));


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

void mainGame::SceneChange(mapFrame * next)
{
	//�߸��� ��ǥ��� �׳� ����
	if (next == nullptr)return;
	//���� �� ��Ż ��ǥ���ʿ� ��ǥ �����ְ� ���� �ٲٸ� init�� ����
	_player->init(playerNextPoint, next);
}

//���� �ִ� ���� ��ǥ�� ã���ְ� ���� ������ ���� ������ �޾ƿ�
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
	if(mapindex<0||portalindex<0){//���̳� ��Ż �ϳ��� ������ ������ ���� ���
		return nullptr;
	}
	//���� �÷��̾ �ִ� ��ǥ���� �� ���� ���� ã�´� - PlayerNextPoint�� ��ǥ ��������
	switch (mapindex) {
	case MapIndex::MVillage:																			//����
		switch (portalindex) {
		case 0:																							//������Ż - Hill
			//�������� �ڸ� �����ֱ�
			playerNextPoint.x = _hill->getPortals()[0].x;
			playerNextPoint.y = _hill->getPortals()[0].y-50;
			nextMap =curScene = _hill;
			break;
		case 1:																							//��������Ż - Forest
			playerNextPoint.x = _forest->getPortals()[0].x;
			playerNextPoint.y = _forest->getPortals()[0].y-50;
			nextMap =curScene = _forest;
			break;
		case 2:																							//������Ż
			playerNextPoint.x = _map->getPortals()[0].x;
			playerNextPoint.y = _map->getPortals()[0].y-50;
			nextMap = curScene = _map;
			break;
		case 3:																							//������Ż
			playerNextPoint.x =  _park->getPortals()[0].x;
			playerNextPoint.y =  _park->getPortals()[0].y-50;
			nextMap = curScene = _park;
			break;
		case 4:																							//������Ż
			playerNextPoint.x =  _market->getPortals()[0].x;
			playerNextPoint.y =  _market->getPortals()[0].y-50;
			nextMap = curScene = _market;
			break;
		}
		break;
	case MapIndex::MStore:																				//����
		switch (portalindex) {
		case 0:																							//������
			playerNextPoint.x =  _village->getPortals()[2].x;
			playerNextPoint.y =  _village->getPortals()[2].y-50;
			nextMap = curScene = _village;
			break;
		}
		break;
	case MapIndex::MPark:																				//����
		switch (portalindex) {
		case 0:																							//������
			playerNextPoint.x = _village->getPortals()[3].x;
			playerNextPoint.y = _village->getPortals()[3].y - 50;
			nextMap = curScene = _village;
			break;
		case 1:																							//������Ż
			playerNextPoint.x =  _boss->getPortals()[0].x;
			playerNextPoint.y =  _boss->getPortals()[0].y - 50;
			nextMap = curScene = _boss;
			break;
		}
		break;
	case MapIndex::MMarket:																				//����
		switch (portalindex) {
		case 0:																							//����
			playerNextPoint.x = _village->getPortals()[4].x;
			playerNextPoint.y = _village->getPortals()[4].y - 50;
			nextMap = curScene = _village;
			break;
		}
		break;
	case MapIndex::MHill:																				//���
		switch (portalindex) {
		case 0:																							//����
			playerNextPoint.x = _village->getPortals()[0].x;
			playerNextPoint.y = _village->getPortals()[0].y - 50;
			nextMap = curScene = _village;
			break;
		}
		break;
	case MapIndex::MForest:																				//��
		switch (portalindex) {
		case 0:																							//����
			playerNextPoint.x = _village->getPortals()[1].x;
			playerNextPoint.y = _village->getPortals()[1].y - 50;
			nextMap = curScene = _village;
			break;
		}
		break;
	case MapIndex::MBoss:																				//����
		switch (portalindex) {
		case 0:																							//����
			playerNextPoint.x = _park->getPortals()[1].x;
			playerNextPoint.y = _park->getPortals()[1].y - 50;
			nextMap = curScene = _park;
			break;
		}
		break;
	}
	return nextMap;
}
