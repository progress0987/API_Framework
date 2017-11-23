#pragma once
#include"mapFrame.h"
#include"VillageMap.h"

class ParkMap:public mapFrame
{
	//포탈
	tagrect portal;
	//보스를 만나러가는 포탈
	tagrect rightportal;

	//배경 움직이는 변수
	int moveX, moveY;
	//프레임 돌리는 변수
	int count = 0;
public:
	ParkMap();
	~ParkMap();

	HRESULT init();
	void release();
	void update();
	void render();
	//키 
	void Keymanager();
	//프레임
	void Frame();

	tagrect getleftportal() { return portal; }
	tagrect getrightportal() { return rightportal; }
};

