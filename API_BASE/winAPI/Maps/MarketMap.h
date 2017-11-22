#pragma once
#include"../gameNode.h"
#include"VillageMap.h"
class MarketMap:public gameNode
{
	tagrect portal;

	//배경 움직이는 변수
	int moveX, moveY;
	//프레임 돌리는 변수
	int count = 0;

public:
	MarketMap();
	~MarketMap();


	HRESULT init();
	void release();
	void update();
	void render();
	//키 
	void Keymanager();
	//프레임
	void Frame();
	
	tagrect getportal() { return portal; }
};

