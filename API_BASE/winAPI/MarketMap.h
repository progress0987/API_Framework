#pragma once
#include"mapFrame.h"

class MarketMap:public mapFrame
{
	tagrect leftportal;


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
	
};

