#pragma once
#include"gameNode.h"
#include"VillageMap.h"
class ForestMap:public gameNode
{
	//��Ż
	tagrect portal;


	//��� �����̴� ����
	int moveX, moveY;
	//������ ������ ����
	int count = 0;


public:
	ForestMap();
	~ForestMap();

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

