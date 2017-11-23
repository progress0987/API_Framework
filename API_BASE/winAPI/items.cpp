#include "stdafx.h"
#include "items.h"


HRESULT items::init(void)
{
	
	IMAGEMANAGER->addImage("쭈쭈바", "쭈쭈바.bmp", 31, 31, true, NULL);
	IMAGEMANAGER->addImage("파란포션", "파란포션.bmp", 27, 27, true, NULL);
	IMAGEMANAGER->addImage("팥빙수", "팥빙수.bmp", 26, 30, true, NULL);
	IMAGEMANAGER->addImage("하얀포션", "하얀포션.bmp", 27, 27, true, NULL);


	IMAGEMANAGER->addImage("아이템정보창", "아이템정보창.bmp", 220, 300, false, NULL);
	iteminfo = IMAGEMANAGER->findImage("아이템정보창");


	/*-----------------------------아이템 표기 목록!!!!!-------------------------------*/
	//정보가 많으므로 코딩할때 아래것을 복사해 가져다 쓰시오.

	/*//아이템 이미지.
	image *itemimg;

	//아이템 이름
	char itemname[200];

	//아이템 종류
	int itemtype;

	//아이템 가격
	int _price;


	//체력, 마나, 힘, 민첩, 지혜, 행운
	int hp, mp, str, dex, inteligence, luk;


	//물리공격력, 물리방어, 마법공격, 마법방어, 명중률, 회피력, 업그레이드가능.
	int phyatk, phyarm, magatk, magarm, hitrate, avoidrate, upgrade;

	//필요 스텟

	int reqLev, reqStr, reqDex, reqInt, reqLuk;
	
	//-----------아래는 소비아이템, 잡템에만 해당한다.(잡템은 오직 설명만있음)---------------

	//회복시켜주는 hp, mp
	int healHp = 0, healMp = 0;

	//설명
	char script[500];
	
	*/


	/*-----------------------------------------------------------------------------*/

	/*아이템1 셋팅*/
	t.itemimg = IMAGEMANAGER->addImage("빨간포션", "빨간포션.bmp", 27, 27, true, NULL);
	strcpy(t.itemname, "빨간포션");
	t.itemtype = potion;
	t._price = 50; //가격
	t.healHp = 50;
	strcpy(t.script, "빨간색 포션이다. hp를 50채워준다.");

	_item.push_back(t);




	/*아이템2 셋팅*/
	t.itemimg = IMAGEMANAGER->addImage("주황포션", "주황포션.bmp", 27, 27, true, NULL);
	strcpy(t.itemname, "주황포션");
	t.itemtype = potion;
	t._price = 160; //가격
	t.healHp = 150;
	strcpy(t.itemname, "주황색 포션이다. hp를 150채워준다.");

	_item.push_back(t);



	/*아이템3 셋팅*/
	t.itemimg = IMAGEMANAGER->addImage("하얀포션", "하얀포션.bmp", 27, 27, true, NULL);
	strcpy(t.itemname, "하얀포션");
	t.itemtype = potion;
	t._price = 320; //가격
	t.healHp = 300;
	strcpy(t.itemname, "하얀색 포션이다. hp를 300채워준다.");

	_item.push_back(t);


	/*아이템4 셋팅*/
	t.itemimg = IMAGEMANAGER->addImage("쭈쭈바", "쭈쭈바.bmp", 31, 31, true, NULL);
	strcpy(t.itemname, "쭈쭈바");
	t.itemtype = potion;
	t._price = 2100; //가격
	t.healHp = 2000;
	strcpy(t.itemname, "속까지 시원한 쭈쭈바이다. hp를 2000채워준다.");


	_item.push_back(t);

	/*아이템5 셋팅*/
	t.itemimg = IMAGEMANAGER->addImage("파란포션", "파란포션.bmp", 27, 27, true, NULL);
	strcpy(t.itemname, "파란포션");
	t.itemtype = potion;
	t._price = 200; //가격
	t.healMp = 100;
	strcpy(t.itemname, "파란색 포션이다. mp를 100채워준다.");


	_item.push_back(t);

	/*아이템6 셋팅*/
	t.itemimg = IMAGEMANAGER->addImage("팥빙수", "팥빙수.bmp", 26, 30, true, NULL);
	strcpy(t.itemname, "팥빙수");
	t.itemtype = potion;
	t._price = 2500; //가격
	t.healMp = 1000;
	strcpy(t.itemname, "달콤하고 시원한 팥빙수이다. mp를 1000채워준다.");


	_item.push_back(t);




	//장비템들 셋팅은 아래와같이 해주면댐.
	/*


	//아이템1 셋팅
	t.itemimg = IMAGEMANAGER->findImage("아이템1");
	strcpy(t.itemname, "실버 크루세이더 헬름");
	t.itemtype = 1; //1은 모자!!!
	t._price = 120000; //가격
	t.hp = 0, t.mp = 0, t.str = 2, t.dex = 0, t.inteligence = 0, t.luk = 0;
	t.phyatk = 0, t.phyarm = 54, t.magatk = 0, t.magarm = 0,
		t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

	t.reqLev = 50;
	t.reqStr = 160;
	t.reqDex = 0;
	t.reqInt = 0;
	t.reqLuk = 0;

	_item.push_back(t);




	//아이템2 셋팅
	t.itemimg = IMAGEMANAGER->findImage("아이템2");
	strcpy(t.itemname, "아쿠아 골든서클릿");
	t.itemtype = 1; //1은 모자!!!
	t._price = 120000; //가격
	t.hp = 0, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 2, t.luk = 1;
	t.phyatk = 0, t.phyarm = 24, t.magatk = 0, t.magarm = 0,
		t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

	t.reqLev = 50;
	t.reqStr = 0;
	t.reqDex = 0;
	t.reqInt = 158;
	t.reqLuk = 0;

	_item.push_back(t); 
	*/
	
	return S_OK;
}

items::items()
{
}


items::~items()
{
}
