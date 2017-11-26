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
	
	StoreMap* _map;//상점			각각 인덱스를 또 따로 줄거임.(맵마다 고유 인덱스 번호를 갖고있어서, 맵 인덱스의 포탈인덱스 몇번은 뭐다 라는걸 알아내기 위함)
	VillageMap* _village;//마을
	ParkMap* _park;//공원
	BossMap* _boss;//보스 맵
	ForestMap* _forest;//숲
	HillMap* _hill;//언덕
	MarketMap* _market;//시장

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

