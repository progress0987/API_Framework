#pragma once
#include"mapFrame.h"

class StoreMap :public mapFrame
{
	tagrect portal;
	tagrect storenpc;

	RECT _pt;

	//프레임 카운트 변수
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

