#pragma once
#include"gameNode.h"
#include"VillageMap.h"

class ParkMap:public gameNode
{
	//��Ż
	tagrect portal;

	//��� �����̴� ����
	int moveX, moveY;
	//������ ������ ����
	int count = 0;
public:
	ParkMap();
	~ParkMap();

	HRESULT init();
	void release();
	void update();
	void render();
	//Ű 
	void Keymanager();
};

