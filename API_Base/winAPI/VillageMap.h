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
	//��Ż
	tagrect _portal;

	//��� �����̴� ����
	int moveX, moveY;
	//������ ������ ����
	int count = 0;
public:
	VillageMap();
	~VillageMap();

	HRESULT init();
	void release();
	void update();
	void render();

};

