#pragma once
#include"mapFrame.h"
class BossMap:public mapFrame
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

