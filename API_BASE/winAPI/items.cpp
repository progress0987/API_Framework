#include "stdafx.h"
#include "items.h"


HRESULT items::init(void)
{


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
	t.itemimg = IMAGEMANAGER->findImage("빨간포션");
	t.number = 0;
	strcpy(t.itemname, "빨간포션");
	t.itemtype = potion;
	t._price = 50; //가격
	t.healHp = 50;
	strcpy(t.script, "빨간색 포션이다. hp를 50채워준다.");

	_item.push_back(t);




	/*아이템2 셋팅*/
	t.itemimg = IMAGEMANAGER->findImage("주황포션");
	t.number = 1;
	strcpy(t.itemname, "주황포션");
	t.itemtype = potion;
	t._price = 160; //가격
	t.healHp = 150;
	strcpy(t.script, "주황색 포션이다. hp를 150채워준다.");

	_item.push_back(t);



	/*아이템3 셋팅*/
	t.itemimg = IMAGEMANAGER->findImage("하얀포션");
	t.number = 2;
	strcpy(t.itemname, "하얀포션");
	t.itemtype = potion;
	t._price = 320; //가격
	t.healHp = 300;
	strcpy(t.script, "하얀색 포션이다. hp를 300채워준다.");

	_item.push_back(t);


	/*아이템4 셋팅*/
	t.itemimg = IMAGEMANAGER->findImage("쭈쭈바");
	t.number = 3;
	strcpy(t.itemname, "쭈쭈바");
	t.itemtype = potion;
	t._price = 2100; //가격
	t.healHp = 2000;
	strcpy(t.script, "속까지 시원한 쭈쭈바이다. hp를 2000채워준다.");


	_item.push_back(t);

	/*아이템5 셋팅*/
	t.itemimg = IMAGEMANAGER->findImage("파란포션");
	t.number = 4;
	strcpy(t.itemname, "파란포션");
	t.itemtype = potion;
	t._price = 200; //가격
	t.healMp = 100;
	strcpy(t.script, "파란색 포션이다. mp를 100채워준다.");


	_item.push_back(t);

	/*아이템6 셋팅*/
	t.itemimg = IMAGEMANAGER->findImage("팥빙수");
	t.number = 5;
	strcpy(t.itemname, "팥빙수");
	t.itemtype = potion;
	t._price = 2500; //가격
	t.healMp = 1000;
	strcpy(t.script, "달콤하고 시원한 팥빙수이다. mp를 1000채워준다.");


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

	//망토
	{
		//아이템 7 붉은망토
		t.itemimg = IMAGEMANAGER->findImage("망토1");
		t.number = 6;
		strcpy(t.itemname, "붉은 망토");
		t.itemtype = itemType::cape;
		t._price = 500;
		t.hp = 0, t.mp = 0, t.str = 2, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 10, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 1;
		t.reqStr = 1;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "가벼운 붉은색의 망토.");

		_item.push_back(t);


		//아이템 8 푸른망토
		t.itemimg = IMAGEMANAGER->findImage("망토2");
		t.number = 7;
		strcpy(t.itemname, "푸른 망토");
		t.itemtype = itemType::cape;
		t._price = 1000;
		t.hp = 50, t.mp = 30, t.str = 0, t.dex = 0, t.inteligence = 3, t.luk = 0;
		t.phyatk = 0, t.phyarm = 20, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 3;
		t.reqStr = 5;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "마법의 힘이 서린 푸른색 망토.");

		_item.push_back(t);


		//아이템 9 하얀망토
		t.itemimg = IMAGEMANAGER->findImage("망토3");
		t.number = 8;
		strcpy(t.itemname, "하얀 망토");
		t.itemtype = itemType::cape;
		t._price = 1500;
		t.hp = 150, t.mp = 130, t.str = 0, t.dex = 0, t.inteligence = 10, t.luk = 0;
		t.phyatk = 0, t.phyarm = 35, t.magatk = 0, t.magarm = 15,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 5;
		t.reqStr = 5;
		t.reqDex = 0;
		t.reqInt = 15;
		t.reqLuk = 0;

		strcpy(t.script, "성스러운 하얀색의 망토.");

		_item.push_back(t);
	}

	//모자
	{
		//아이템 10 낡은 고깔모자
		t.itemimg = IMAGEMANAGER->findImage("모자1");
		t.number = 9;
		strcpy(t.itemname, "낡은 고깔모자");
		t.itemtype = itemType::helm;
		t._price = 300;
		t.hp = 0, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 5, t.luk = 0;
		t.phyatk = 0, t.phyarm = 10, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 1;
		t.reqStr = 1;
		t.reqDex = 0;
		t.reqInt = 1;
		t.reqLuk = 0;

		strcpy(t.script, "구멍나서 바람새는 모자다.");

		_item.push_back(t);

		//아이템 11 여행용 삿갓

		t.itemimg = IMAGEMANAGER->findImage("모자2");
		t.number = 10;
		strcpy(t.itemname, "여행용 삿갓");
		t.itemtype = itemType::helm;
		t._price = 600;
		t.hp = 30, t.mp = 0, t.str = 0, t.dex = 5, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 20, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 3;
		t.reqStr = 5;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "여행용으로 개량한 삿갓.");

		_item.push_back(t);

		//아이템 12 마법사모자

		t.itemimg = IMAGEMANAGER->findImage("망토3");
		t.number = 11;
		strcpy(t.itemname, "마법사 모자");
		t.itemtype = itemType::helm;
		t._price = 1000;
		t.hp = 150, t.mp = 130, t.str = 0, t.dex = 0, t.inteligence = 10, t.luk = 0;
		t.phyatk = 0, t.phyarm = 35, t.magatk = 0, t.magarm = 15,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 5;
		t.reqStr = 5;
		t.reqDex = 0;
		t.reqInt = 15;
		t.reqLuk = 0;

		strcpy(t.script, "성스러운 하얀색의 망토.");

		_item.push_back(t);
	}

	//무기
	{
		//아이템 13 기본형 ESP 증폭기
		t.itemimg = IMAGEMANAGER->findImage("무기1");
		t.number = 12;
		strcpy(t.itemname, "기본형 ESP 증폭기");
		t.itemtype = itemType::weapons;
		t._price = 150;
		t.hp = 0, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 15, t.luk = 0;
		t.phyatk = 0, t.phyarm = 0, t.magatk = 20, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 1;
		t.reqStr = 0;
		t.reqDex = 0;
		t.reqInt = 1;
		t.reqLuk = 0;

		strcpy(t.script, "기본형 증폭기.");

		_item.push_back(t);


		//아이템 14 서리증폭기
		t.itemimg = IMAGEMANAGER->findImage("무기2");
		t.number = 13;
		strcpy(t.itemname, "서리 증폭기");
		t.itemtype = itemType::weapons;
		t._price = 500;
		t.hp = 0, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 25, t.luk = 0;
		t.phyatk = 0, t.phyarm = 0, t.magatk = 35, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 3;
		t.reqStr = 0;
		t.reqDex = 0;
		t.reqInt = 5;
		t.reqLuk = 0;

		strcpy(t.script, "냉기의 힘이 서린 증폭기.");

		_item.push_back(t);


		//아이템 15 코로나 증폭기
		t.itemimg = IMAGEMANAGER->findImage("무기3");
		t.number = 14;
		strcpy(t.itemname, "코로나 증폭기");
		t.itemtype = itemType::weapons;
		t._price = 1000;
		t.hp = 50, t.mp = 50, t.str = 0, t.dex = 0, t.inteligence = 30, t.luk = 0;
		t.phyatk = 0, t.phyarm = 5, t.magatk = 50, t.magarm = 5,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 5;
		t.reqStr = 0;
		t.reqDex = 0;
		t.reqInt = 20;
		t.reqLuk = 0;

		strcpy(t.script, "태양의 힘이 깃든 증폭기.");

		_item.push_back(t);
	}

	//바지
	{

		//아이템 16 천바지
		t.itemimg = IMAGEMANAGER->findImage("바지1");
		t.number = 15;
		strcpy(t.itemname, "천바지");
		t.itemtype = itemType::pants;
		t._price = 150;
		t.hp = 50, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 5, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 1;
		t.reqStr = 1;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "화려한 천바지.");

		_item.push_back(t);


		//아이템 17 가죽치마
		t.itemimg = IMAGEMANAGER->findImage("바지2");
		t.number = 16;
		strcpy(t.itemname, "가죽 치마");
		t.itemtype = itemType::pants;
		t._price = 300;
		t.hp = 100, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 15, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 3;
		t.reqStr = 2;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "검은 가죽으로 만든 치마.");

		_item.push_back(t);


		//아이템 18 하얀치마
		t.itemimg = IMAGEMANAGER->findImage("바지3");
		t.number = 17;
		strcpy(t.itemname, "하얀 치마");
		t.itemtype = itemType::pants;
		t._price = 500;
		t.hp = 150, t.mp = 50, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 25, t.magatk = 0, t.magarm = 25,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 5;
		t.reqStr = 5;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;
		
		strcpy(t.script, "순백의 치마이다.");

		_item.push_back(t);
	}

	//상의
	{

		//아이템 19 티셔츠
		t.itemimg = IMAGEMANAGER->findImage("상의1");
		t.number = 18;
		strcpy(t.itemname, "티셔츠");
		t.itemtype = itemType::clothes;
		t._price = 150;
		t.hp = 50, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 5, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 1;
		t.reqStr = 1;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "편한 회색 티셔츠.");

		_item.push_back(t);


		//아이템 20 롱코트
		t.itemimg = IMAGEMANAGER->findImage("상의2");
		t.number = 19;
		strcpy(t.itemname, "롱코트");
		t.itemtype = itemType::clothes;
		t._price = 300;
		t.hp = 100, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 15, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 3;
		t.reqStr = 2;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "요즘 유행하는 롱코트스타일");

		_item.push_back(t);


		//아이템 21 검은 갑옷
		t.itemimg = IMAGEMANAGER->findImage("상의3");
		t.number = 20;
		strcpy(t.itemname, "검은 갑옷");
		t.itemtype = itemType::clothes;
		t._price = 500;
		t.hp = 150, t.mp = 50, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 25, t.magatk = 0, t.magarm = 25,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 5;
		t.reqStr = 5;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "튼튼해보이는 검은색의 갑옷이다.");

		_item.push_back(t);
	}

	//신발
	{

		//아이템 22 빽구두
		t.itemimg = IMAGEMANAGER->findImage("신발1");
		t.number = 21;
		strcpy(t.itemname, "빽구두");
		t.itemtype = itemType::boots;
		t._price = 150;
		t.hp = 50, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 5, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 1;
		t.reqStr = 1;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "반짝반짝 빽구두.");

		_item.push_back(t);


		//아이템 23 가죽신발
		t.itemimg = IMAGEMANAGER->findImage("신발2");
		t.number = 22;
		strcpy(t.itemname, "가죽신발");
		t.itemtype = itemType::boots;
		t._price = 300;
		t.hp = 100, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 15, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 3;
		t.reqStr = 2;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "튼튼한 가죽신발이다.");

		_item.push_back(t);


		//아이템 24 털부츠
		t.itemimg = IMAGEMANAGER->findImage("신발3");
		t.number = 23;
		strcpy(t.itemname, "털부츠");
		t.itemtype = itemType::boots;
		t._price = 500;
		t.hp = 150, t.mp = 50, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 25, t.magatk = 0, t.magarm = 25,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 5;
		t.reqStr = 5;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "따뜻한 털이 달린 부츠.");

		_item.push_back(t);
	}

	//장갑
	{

		//아이템 25 하얀장갑
		t.itemimg = IMAGEMANAGER->findImage("장갑1");
		t.number = 24;
		strcpy(t.itemname, "하얀 장갑");
		t.itemtype = itemType::gloves;
		t._price = 150;
		t.hp = 50, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 5, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 1;
		t.reqStr = 1;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "예식용 하얀 장갑.");

		_item.push_back(t);


		//아이템 26 두툼한 장갑
		t.itemimg = IMAGEMANAGER->findImage("장갑2");
		t.number = 25;
		strcpy(t.itemname, "두툼한 장갑");
		t.itemtype = itemType::gloves;
		t._price = 300;
		t.hp = 100, t.mp = 0, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 15, t.magatk = 0, t.magarm = 0,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 3;
		t.reqStr = 2;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "글러브 대용으로 쓸만한 두툼한 장갑.");

		_item.push_back(t);


		//아이템 27 가죽장갑
		t.itemimg = IMAGEMANAGER->findImage("장갑3");
		t.number = 26;
		strcpy(t.itemname, "가죽장갑");
		t.itemtype = itemType::gloves;
		t._price = 500;
		t.hp = 150, t.mp = 50, t.str = 0, t.dex = 0, t.inteligence = 0, t.luk = 0;
		t.phyatk = 0, t.phyarm = 25, t.magatk = 0, t.magarm = 25,
			t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

		t.reqLev = 5;
		t.reqStr = 5;
		t.reqDex = 0;
		t.reqInt = 0;
		t.reqLuk = 0;

		strcpy(t.script, "실용적인 디자인의 가죽재질 장갑.");

		_item.push_back(t);
	}


	return S_OK;
}

items::items()
{
}


items::~items()
{
}
