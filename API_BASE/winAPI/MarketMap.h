#pragma once
#include"mapFrame.h"

class MarketMap:public mapFrame
{
	tagrect leftportal;


	//������ ������ ����
	int count = 0;

public:
	MarketMap();
	~MarketMap();


	HRESULT init();
	void release();
	void update();
	void render();
	//Ű 
	void Keymanager();
	//������
	void Frame();
	
};

