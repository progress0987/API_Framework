#pragma once
#include"mapFrame.h"
class ForestMap:public mapFrame
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

