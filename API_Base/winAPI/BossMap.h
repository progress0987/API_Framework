#pragma once
#include"gameNode.h"
#include"VillageMap.h"
class BossMap:public gameNode
{
	tagrect portal;

	//��� �����̴� ����
	int moveX, moveY;
	//������ ������ ����
	int count = 0;


public:
	BossMap();
	~BossMap();

	HRESULT init();
	void release();
	void update();
	void render();
	//Ű 
	void Keymanager();
	//������
	void Frame();

	tagrect getportal() { return portal; }
};

