#pragma once
#include"mapFrame.h"

class ParkMap:public mapFrame
{
	//��Ż
	tagrect leftportal;
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
};

