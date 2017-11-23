#pragma once
#include"mapFrame.h"

class VillageMap:public mapFrame
{
	//포탈
	tagrect _lefeportal;//제일 왼쪽에 있는 포탈				0
	tagrect rightportal;//제일 오른쪽에 있는 포탈			1
	tagrect storeportal;//상점 포탈							2
	tagrect parkportal;//공원가는 포탈						3
	tagrect marketportal;//시장가는 포탈					4

	//NPC
	tagrect gujiGirl;//그지
	tagrect Lina;//이쁜애
	tagrect OrangeHair;//주황머리
	tagrect mingming;

public:
	VillageMap();
	~VillageMap();

	HRESULT init();
	void release();
	void update();
	void render();
	//키 
	void Keymanager();
	//프레임
	void Frame();
	//밍밍부인 움직이는
	void MingmingMove();

};

