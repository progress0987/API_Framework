#pragma once
#include"../gameNode.h"
struct tagrect
{
	image* _img;
	RECT rc;
	int currentX;//프레임 변수
	int x;
	int y;
	int pattern;//방향 바꾸는 변수

};
class VillageMap:public gameNode
{
	//포탈
	tagrect _lefeportal;//제일 왼쪽에 있는 포탈
	tagrect rightportal;//제일 오른쪽에 있는 포탈
	tagrect storeportal;//상점 포탈
	tagrect parkportal;//공원가는 포탈
	tagrect marketportal;//시장가는 포탈

	//NPC
	tagrect gujiGirl;//그지
	tagrect Lina;//이쁜애
	tagrect OrangeHair;//주황머리
	tagrect mingming;

	//배경 움직이는 변수
	int moveX, moveY;
	//프레임 돌리는 변수
	int count = 0;
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
	
	tagrect getlefeportal() { return _lefeportal; }
	tagrect getrightportal() { return rightportal; }
	tagrect getstoreportal() { return storeportal; }
	tagrect getparkportal() { return parkportal; }
	tagrect getmarketportal() { return marketportal; }


};

