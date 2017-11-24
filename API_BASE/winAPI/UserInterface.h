#pragma once
#include"gameNode.h"
#include"items.h"

class UserInterface :public gameNode
{
private:
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
	int playerHp, playerMp, MaxHp, MaxMp, _str, _dex, _int, _luk, _ap;



	//z Order
	int Zstat;
	//true false;
	bool onStat;

	//----------------���â ������----------------

	//�÷��̾��� �������
	image *equipWnd;
	RECT wndEquip; //���â�簢��
	RECT _cap, _clothes, _pants, _earAcc, _weapon, _shoes, _gloves, _capes;





	//z Order
	int Zequip;
	//true false;
	bool onEquip;

	//-------------�κ��丮â ������------------

	//�÷��̾��� �κ��丮 ������
	image *invenWnd, *equipTab, *potionTab, *etcTab;
	// ���ʻ�ܺ��� 1234, ������ 5678��....24����.
	RECT _equip[24], _potion[24], _etc[24];
	//���, ��.
	int stack, money;



	//z Order
	int Zinven;
	//true false;
	bool onInven; //�κ��丮â �¿���
	bool invEq, invPo, invEtc; //�����, �Һ���, ��Ÿ�� �¿��� ó�� �Һ���.


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
	image *hpbar, *mpbar, *_form;
	//����ǥ�ÿ� �ʿ��� �̹���
	image *_lv, *l0, *l1, *l2, *l3, *l4, *l5, *l6, *l7, *l8, *l9;
	//����ġ
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