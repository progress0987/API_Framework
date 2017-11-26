#pragma once
#include"gameNode.h"
#include"enemyManager.h"
#include "player.h"
#include"StoreMap.h"
#include"VillageMap.h"
#include"ParkMap.h"
#include"BossMap.h"
#include"ForestMap.h"
#include"HillMap.h"
#include"MarketMap.h"


class mainGame : public gameNode
{
private:
	Camera* cam;
	player *_player;
	enemyManager* em;
	mapFrame* curScene;
	
	StoreMap* _map;//����			���� �ε����� �� ���� �ٰ���.(�ʸ��� ���� �ε��� ��ȣ�� �����־, �� �ε����� ��Ż�ε��� ����� ���� ��°� �˾Ƴ��� ����)
	VillageMap* _village;//����
	ParkMap* _park;//����
	BossMap* _boss;//���� ��
	ForestMap* _forest;//��
	HillMap* _hill;//���
	MarketMap* _market;//����

	bool onSceneChange=false,SceneChanged=false;
	int fadeAlpha = 0, fadeCount=0;
	POINT playerNextPoint;

public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();
	void imgInit();
	void soundInit();
	void SceneChange(mapFrame* next);
	mapFrame* getNextNode();

	mainGame();
	~mainGame();
};

