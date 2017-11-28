#pragma once
#include"gameNode.h"
#include"items.h"
#include "player.h"

class UserInterface :public gameNode
{
private:
	player* curPlayer;
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
	int Level = 249, playerHp = 34689, playerMp = 12570, MaxHp = 500000, MaxMp = 500000, _str, _dex, _int, _luk, _ap;


	//z Order
	int Zstat;
	//true false;
	bool onStat = false;

	//----------------장비창 데이터----------------

	//플레이어의 장비데이터
	image *equipWnd;
	RECT wndEquip; //장비창사각형
	RECT _cap, _clothes, _pants, _earAcc, _weapon, _shoes, _gloves, _capes;





	//z Order
	int Zequip;
	//true false;
	bool onEquip = false;

	//-------------인벤토리창 데이터------------

	//플레이어의 인벤토리 데이터
	image *invenWnd, *equipTab, *potionTab, *etcTab, *shadow;
	//인벤토리 재고량 표기번호
	image *sZero, *sOne, *sTwo, *sThree, *sFour, *sFive, *sSix, *sSeven, *sEight, *sNine;
	// 왼쪽상단부터 1234, 밑으로 5678순....24까지.
	RECT wndInven, _equip[24], _potion[24], _etc[24];
	//재고, 돈.
	int stack, money;



	//z Order
	int Zinven;
	//true false;
	bool onInven = false; //인벤토리창 온오프
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
	image *hpbar, *mpbar, *_form, *_formBackground, *_shine;
	//레벨표시에 필요한 이미지
	//세자리수까지 있다보니 각 자리수마다 필요한 변수들 모두 선언해줌.
	image *_lv, *l0, *l1, *l2, *l3, *l4, *l5, *l6, *l7, *l8, *l9,
		*l00, *l01, *l02, *l03, *l04, *l05, *l06, *l07, *l08, *l09,
		*l000, *l001, *l002, *l003, *l004, *l005, *l006, *l007, *l008, *l009;
	//경험치
	image *expBackground, *expGuage, *expLayer, *expEffect;
	int _exp = 794234;
	double LvExp = 4912340; //퍼센트출력때문에 얘는 더블로 처리했어.
	int jeongsu, sosu;



	//------------------------------------캐릭터 상태표시 숫자들----------------------------
	image *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_rs, *_Lc, *_Rc, *_percent, *_dot;
	//숫자, 역슬래쉬, 왼쪽커버, 오른쪽커버, 퍼센트, 점.

public:
	virtual HRESULT init(void);
	virtual void release(void);

	virtual void update(void);

	virtual void render(void);


	//덩어리로 작업해야 하기 때문에 함수로 묶어줬다.
	virtual void equip(void);
	virtual void inventory(void);
	virtual void statement(void);
	virtual void showLevel(void);
	virtual void showStatement(void);
	void setPlayer(player *pl) { curPlayer = pl; }

	UserInterface();
	~UserInterface();
};