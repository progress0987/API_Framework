#pragma once

//아이템 도감 클래스!!!!!
//퍼블릭으로 모두 접근가능하게 만들었습니다.

/*가져다 쓰실때, if문을써서 장비아이템인경우, 소비아이템(potion)인경우, 기타템인경우(etc)를 구분해서 사용하세용.*/
enum itemType {
	empty, //아이템x
	etc, //잡템
	potion, //포션
	weapons, //무기
	helm, //헬멧
	earacc, //귀고리
	clothes, //상의
	pants, //하의
	gloves, //장갑
	boots, //부츠
	cape//망토
};
enum rarity {
	common,
	uncommon,
	magic,
	rare,
	unique,
	legandary,
	epic,
};

//아이템 속성 정의.
//전부 초기화된 상태!!!!

struct item {
	//아이템 이미지.
	image *itemimg;

	//아이템 이름
	char itemname[200];

	//아이템 종류
	int itemtype = -1;

	//아이템 가격
	int _price = 0;


	//장착시 증가되는 체력, 마나, 힘, 민첩, 지혜, 행운
	int hp = 0, mp = 0, str = 0, dex = 0, inteligence = 0, luk = 0;


	//물리공격력, 물리방어, 마법공격, 마법방어, 명중률, 회피력, 업그레이드가능.
	int phyatk = 0, phyarm = 0, magatk = 0, magarm = 0, hitrate = 0, avoidrate = 0, upgrade = 0;

	//필요 스텟
	int reqLev = 0, reqStr = 0, reqDex = 0, reqInt = 0, reqLuk = 0;

	//-----------아래는 소비아이템, 잡템에만 해당한다.(잡템은 오직 설명만있음)---------------

	//회복시켜주는 hp, mp
	int healHp = 0, healMp = 0;

	//설명
	char script[500];
};

class items
{
public:

	image *iteminfo;
	item t;
	vector<item> _item;

	HRESULT init(void);

	items();
	~items();
};

