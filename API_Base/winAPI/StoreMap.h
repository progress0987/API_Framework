#pragma once
#include"gameNode.h"
#include"VillageMap.h"

class StoreMap :public gameNode
{
	tagrect portal;

	image* _npc;
	RECT _pt;

	//������ ī��Ʈ ����
	int count = 0;
	int currentX = 0;
	int storecurrentX = 0;
public:
	StoreMap();
	~StoreMap();


	HRESULT init();
	void release();
	void update();
	void render();

	tagrect getportal() { return portal; }
};

