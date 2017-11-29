#pragma once
#include"gameNode.h"
#include"items.h"
#include "player.h"

class player;
class UserInterface :public gameNode
{
private:
	player *pl;
	//--------------�հ���Ŀ��--------------
	image *finger;

	//-------------��� â�� �������� �ִ� �ݱ������----------
	//N�� �Ϲݻ���, O�� ���콺�� �÷�����, C�� Ŭ���������� ��ư �̹���.
	image *CloseN, *CloseO, *CloseC;

	//----------------����â ������---------------

	//�÷��̾� ü��, ����, �ִ�ü��, �ִ븶��, ����, ��ø, ����, ���, ����ġ, �����Ƽ����Ʈ
	image *statWnd, *UpN, *UpO, *UpC, *autoDistN, *autoDistC;
	//����â�簢��
	RECT wndStat;
	//����â�� ���� ������
	int Level = 249, playerHp = 34689, playerMp = 12570, MaxHp = 500000, MaxMp = 500000, _str, _dex, _int, _luk, _ap = 0;
	int totalEquipstr = 10, totalEquipdex = 20, totalEquipint = 400, totalEquipluk = 3;
	int _basicStr = 4, _basicDex = 4, _basicInt = 13, _basicLuk = 4;


	//z Order
	int Zstat;
	//true false;
	bool onStat = false;

	//----------------���â ������----------------

	//�÷��̾��� �������
	image *equipWnd;
	RECT wndEquip; //���â�簢��
	RECT _cap, _clothes, _pants, _earAcc, _weapon, _shoes, _gloves, _capes;





	//z Order
	int Zequip;
	//true false;
	bool onEquip = false;

	//-------------�κ��丮â ������------------

	//�÷��̾��� �κ��丮 ������
	image *invenWnd, *equipTab, *potionTab, *etcTab, *shadow;
	//�κ��丮 ��� ǥ���ȣ
	image *sZero, *sOne, *sTwo, *sThree, *sFour, *sFive, *sSix, *sSeven, *sEight, *sNine;
	// ���ʻ�ܺ��� 1234, ������ 5678��....24����.
	RECT wndInven, _equip[24], _potion[24], _etc[24];
	//���, ��.
	int stack, money;
	//���α׷����ٸ� ���� width
	float Hpwidth, Mpwidth,Exwidth;
	//ȸ�� ī��Ʈ
	int HpHillCount = 0;
	int MpHillCount = 0;
	//ȸ�� ��
	float HpHillMax = 0;
	float HpHill = 0;
	float MpHillMax = 0;
	float MpHill = 0;

	//z Order
	int Zinven;
	//true false;
	bool onInven = false; //�κ��丮â �¿���
	bool invEq, invPo, invEtc; //�����, �Һ���, ��Ÿ�� �¿��� ó�� �Һ���.

    //------------------------------------����������---------------------------------------------

	bool onShop; //�� �¿���
	image *_me, *_Azoomma;
	image *shopWnd, *shopQuit, *shopBuy, *shopSell, *shopQuitPushed, *shopBuyPushed, *shopSellPushed, *shopEquip, *shopPortion, *shopEtc, *mesoIcon, *selectEffect;
	RECT shopItem[9], myItem[9];
	RECT buttonQuit, buttonBuy, buttonSell;
	//����ư��, �������ܸ������� ������������ on, ������ off
	bool onClickQuit, onClickBuy, onClickSell, onClickAzoomma;

   
    //------------------------------------���ϴ� UI���̾�-----------------------------------------------
   
    //-------------������â ������-------------
    //�����Է��̾�
	image *slotcover1, *slotcover2, *slotbackground;
	//�����Դ���Ű���̾�
	image *q1, *q2, *q3, *q4, *q5, *q6;
	image *_ctrl, *_shift, *_inst, *_del, *_hm, *_pgup, *_pgdn, *_end;
	image *qq, *qw, *qe, *qr, *qt, *qa;

	
	//-------------ĳ���� ����â----------------
	//���̾��̹���
	image *hpbar, *mpbar, *_form, *_formBackground, *_shine;
	//����ǥ�ÿ� �ʿ��� �̹���
	//���ڸ������� �ִٺ��� �� �ڸ������� �ʿ��� ������ ��� ��������.
	image *_lv, *l0, *l1, *l2, *l3, *l4, *l5, *l6, *l7, *l8, *l9,
		*l00, *l01, *l02, *l03, *l04, *l05, *l06, *l07, *l08, *l09,
		*l000, *l001, *l002, *l003, *l004, *l005, *l006, *l007, *l008, *l009;
	//����ġ
	image *expBackground, *expGuage, *expLayer, *expEffect;
	int _exp = 794234;
	double LvExp = 4912340; //�ۼ�Ʈ��¶����� ��� ����� ó���߾�.
	int jeongsu, sosu;



	//------------------------------------ĳ���� ����ǥ�� ���ڵ�----------------------------
	image *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_rs, *_Lc, *_Rc, *_percent, *_dot;
	//����, ��������, ����Ŀ��, ������Ŀ��, �ۼ�Ʈ, ��.
	
	//-----------------------------------UI���μ����� ���� ������---------------------------

	//�հ��� �������� ���� ����
	int count, fingerCount;

	//������ �� ĳ���� �������ܸ� �������� ���� ����
	int _meCount, _AzoommaCount;
	



public:
	virtual HRESULT init(void);
	virtual void release(void);

	virtual void update(void);

	virtual void render(void);


	//����� �۾��ؾ� �ϱ� ������ �Լ��� �������.
	//������ �Լ���!!!!!
	virtual void equip(void);
	virtual void inventory(void);
	virtual void statement(void);
	virtual void shop(void);
	virtual void showLevel(void);
	virtual void showStatement(void);
	void setPlayer(player *pl) { this->pl = pl; }

	UserInterface();
	~UserInterface();
};