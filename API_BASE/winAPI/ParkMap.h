#pragma once
#include"mapFrame.h"
#include"VillageMap.h"

class ParkMap:public mapFrame
{
	//��Ż
	tagrect portal;
	//������ ���������� ��Ż
	tagrect rightportal;

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
	//������
	void Frame();

	tagrect getleftportal() { return portal; }
	tagrect getrightportal() { return rightportal; }
};

