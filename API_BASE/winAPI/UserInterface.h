#pragma once
#include"gameNode.h"
#include"items.h"

class UserInterface :public gameNode
{
private:
	//--------------손가락커서--------------
	image *finger;

	//-------------모든 창에 공용으로 있는 닫기아이콘----------
	//N은 일반상태, O는 마우스를 올렸을때, C는 클릭했을때의 버튼 이미지.
	image *CloseN, *CloseO, *CloseC;

	//----------------스텟창 데이터---------------

	//플레이어 체력, 마나, 최대체력, 최대마력, 공격, 민첩, 지혜, 행운, 경험치, 어빌리티포인트
	image *statWnd, *UpN, *UpO, *UpC, *autoDistN, *autoDistC;
	//스텟창사각형
	RECT wndStat;
	//스텟창에 들어가는 정보들
	int playerHp, playerMp, MaxHp, MaxMp, _str, _dex, _int, _luk, _ap;



	//z Order
	int Zstat;
	//true false;
	bool onStat;

	//----------------장비창 데이터----------------

	//플레이어의 장비데이터
	image *equipWnd;
	RECT wndEquip; //장비창사각형
	RECT _cap, _clothes, _pants, _earAcc, _weapon, _shoes, _gloves, _capes;





	//z Order
	int Zequip;
	//true false;
	bool onEquip;

	//-------------인벤토리창 데이터------------

	//플레이어의 인벤토리 데이터
	image *invenWnd, *equipTab, *potionTab, *etcTab;
	// 왼쪽상단부터 1234, 밑으로 5678순....24까지.
	RECT _equip[24], _potion[24], _etc[24];
	//재고, 돈.
	int stack, money;



	//z Order
	int Zinven;
	//true false;
	bool onInven; //인벤토리창 온오프
	bool invEq, invPo, invEtc; //장비탭, 소비탭, 기타탭 온오프 처리 불변수.


							   //------------------------------------최하단 UI레이어-----------------------------------------------

							   //-------------퀵슬롯창 데이터-------------
							   //퀵슬롯레이어
	image *slotcover1, *slotcover2, *slotbackground;
	//퀵슬롯단축키레이어
	image *q1, *q2, *q3, *q4, *q5, *q6;
	image *_ctrl, *_shift, *_inst, *_del, *_hm, *_pgup, *_pgdn, *_end;
	image *qq, *qw, *qe, *qr, *qt, *qa;


	//-------------캐릭터 정보창----------------
	//레이어이미지
	image *hpbar, *mpbar, *_form;
	//레벨표시에 필요한 이미지
	image *_lv, *l0, *l1, *l2, *l3, *l4, *l5, *l6, *l7, *l8, *l9;
	//경험치
	image *expBackground, *expGuage, *expLayer, *expEffect;
	int _exp, LvExp;


public:
	virtual HRESULT init(void);
	virtual void release(void);

	virtual void update(void);

	virtual void render(void);

	UserInterface();
	~UserInterface();
};