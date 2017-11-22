#pragma once
#include"gameNode.h"
#include"StoreMap.h"
#include"VillageMap.h"
#include"ParkMap.h"
#include"BossMap.h"
#include"ForestMap.h"
#include"HillMap.h"
#include"MarketMap.h"
class mainGame :  public gameNode
{

private:

	gameNode* TestScene;

	//gameNode* _map;//»óÁ¡
	//gameNode* _village;//¸¶À»
	//gameNode* _park;//°ø¿ø
	//gameNode* _boss;//º¸½º ¸Ê
	//gameNode* _forest;//½£
	//gameNode* _hill;//¾ð´ö
	//gameNode* _market;//½ÃÀå

	StoreMap* _map;//»óÁ¡
	VillageMap* _village;//¸¶À»
	ParkMap* _park;//°ø¿ø
	BossMap* _boss;//º¸½º ¸Ê
	ForestMap* _forest;//½£
	HillMap* _hill;//¾ð´ö
	MarketMap* _market;//½ÃÀå
	
	tagrect player;



	
public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();
	//Ä³¸¯ ¿òÁ÷ÀÓ
	void Playermove();
	//Æ÷Å»·Î ÀÌµ¿
	void SceneChange();

	mainGame();
	~mainGame();
};

