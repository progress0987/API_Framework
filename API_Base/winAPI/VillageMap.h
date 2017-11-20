#pragma once
#include"gameNode.h"
struct tagrect
{
	image* _img;
	RECT rc;
	int currentX;
	int x;
	int y;

};
class VillageMap:public gameNode
{
	//포탈
	tagrect _portal;

	//배경 움직이는 변수
	int moveX, moveY;
	//프레임 돌리는 변수
	int count = 0;
public:
	VillageMap();
	~VillageMap();

	HRESULT init();
	void release();
	void update();
	void render();

};

