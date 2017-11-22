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

	//gameNode* _map;//����
	//gameNode* _village;//����
	//gameNode* _park;//����
	//gameNode* _boss;//���� ��
	//gameNode* _forest;//��
	//gameNode* _hill;//���
	//gameNode* _market;//����

	StoreMap* _map;//����
	VillageMap* _village;//����
	ParkMap* _park;//����
	BossMap* _boss;//���� ��
	ForestMap* _forest;//��
	HillMap* _hill;//���
	MarketMap* _market;//����
	
	tagrect player;



	
public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();
	//ĳ�� ������
	void Playermove();
	//��Ż�� �̵�
	void SceneChange();

	mainGame();
	~mainGame();
};

