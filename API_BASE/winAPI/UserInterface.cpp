#include "stdafx.h"
#include "UserInterface.h"


HRESULT UserInterface::init(void)
{

	//------------------------------------ImagePrep------------------------------------------
	//�ݱ���� �۾�
	CloseN = IMAGEMANAGER->findImage("�ݱ�");
	CloseO = IMAGEMANAGER->findImage("�ݱ⸶�콺��");
	CloseC = IMAGEMANAGER->findImage("�ݱ�Ŭ��");

	//Ŀ�� �۾�
	finger = IMAGEMANAGER->findImage("Ŀ��");
	finger->setFrameY(0);
	finger->setFrameX(0);

	//����â �۾�
	statWnd = IMAGEMANAGER->findImage("����â");
	UpN = IMAGEMANAGER->findImage("��");
	UpO = IMAGEMANAGER->findImage("�����콺��");
	UpC = IMAGEMANAGER->findImage("��Ŭ��");
	autoDistN = IMAGEMANAGER->findImage("�ڵ���й�ưȰ��ȭ");
	autoDistC = IMAGEMANAGER->findImage("�ڵ���й�ư����");

	statWnd->setX(150);
	statWnd->setY(200);

	//���â �۾�
	equipWnd = IMAGEMANAGER->findImage("���â");

	equipWnd->setX(400);
	equipWnd->setY(200);

	iT = new items;
	iT->init();

	//���â �ʱ�ȭ
	e_cap = e_capes = e_gloves = e_clothes = e_earAcc = e_weapon = e_pants = e_shoes = -1;

	//�κ��丮 �۾�
	invenWnd = IMAGEMANAGER->findImage("�κ��丮â");
	equipTab = IMAGEMANAGER->findImage("�����");
	potionTab = IMAGEMANAGER->findImage("�Һ���");
	etcTab = IMAGEMANAGER->findImage("��Ÿ��");
	shadow = IMAGEMANAGER->findImage("�׸���");

	invenWnd->setX(700);
	invenWnd->setY(200);

	//�÷��̾ �⺻������ �����ϰ� �ִ� �������� �κ��丮�� �־��ش�.
	//ó���� �ʱ�ȭ.

	memset(c_equip, -1, sizeof(c_equip));
	memset(c_consume, -1, sizeof(c_consume));
	memset(c_etc, -1, sizeof(c_etc));


	//�ÿ��̾ �⺻������ ������ �ִ� �������� �κ��丮�� �����´�.
	//-1�� ��������� �ǹ��Ѵ�.

	c_equip[0] = 0; //�� �迭�� ����ִ� ���ڴ� �÷��̾��� ������ ������ �ε����� �ش��ϴ� �������� �ǹ��Ѵ�.
	c_equip[1] = 1;
	c_equip[2] = 2;
	c_equip[3] = 3;
	c_equip[4] = 4;
	c_equip[5] = 5;
	c_equip[6] = 6;

	c_consume[0] = 0;
	c_consume[1] = 1;



	invEq = true, invPo = false, invEtc = false;

	//��� ǥ���ȣ
	sZero = IMAGEMANAGER->findImage("0");
	sOne = IMAGEMANAGER->findImage("1");
	sTwo = IMAGEMANAGER->findImage("2");
	sThree = IMAGEMANAGER->findImage("3");
	sFour = IMAGEMANAGER->findImage("4");
	sFive = IMAGEMANAGER->findImage("5");
	sSix = IMAGEMANAGER->findImage("6");
	sSeven = IMAGEMANAGER->findImage("7");
	sEight = IMAGEMANAGER->findImage("8");
	sNine = IMAGEMANAGER->findImage("9");

	//������ ���̾��۾�
	slotcover1 = IMAGEMANAGER->findImage("�����Կ����׵θ�");
	slotcover2 = IMAGEMANAGER->findImage("������Ŀ��");
	slotbackground = IMAGEMANAGER->findImage("������0");

	//������ ����Ű �۾�
	q1 = IMAGEMANAGER->findImage("��1");
	q2 = IMAGEMANAGER->findImage("��2");
	q3 = IMAGEMANAGER->findImage("��3");
	q4 = IMAGEMANAGER->findImage("��4");
	q5 = IMAGEMANAGER->findImage("��5");
	q6 = IMAGEMANAGER->findImage("��6");
	qq = IMAGEMANAGER->findImage("Q");
	qw = IMAGEMANAGER->findImage("W");
	qe = IMAGEMANAGER->findImage("E");
	qr = IMAGEMANAGER->findImage("R");
	qt = IMAGEMANAGER->findImage("T");
	qa = IMAGEMANAGER->findImage("A");
	_ctrl = IMAGEMANAGER->findImage("ctrl");
	_shift = IMAGEMANAGER->findImage("shift");
	_inst = IMAGEMANAGER->findImage("inst");
	_del = IMAGEMANAGER->findImage("del");
	_hm = IMAGEMANAGER->findImage("hm");
	_end = IMAGEMANAGER->findImage("end");
	_pgup = IMAGEMANAGER->findImage("pgup");
	_pgdn = IMAGEMANAGER->findImage("pgdn");

	//ĳ���� ����â, ����ġ ���̾� �۾�

	_form = IMAGEMANAGER->findImage("�������׵θ�");
	_formBackground = IMAGEMANAGER->findImage("���������");
	mpbar = IMAGEMANAGER->findImage("����");
	hpbar = IMAGEMANAGER->findImage("ü��");
	_shine = IMAGEMANAGER->findImage("Ŀ��");
	_lv = IMAGEMANAGER->findImage("Lv");
	l0 = IMAGEMANAGER->findImage("��������0");
	l1 = IMAGEMANAGER->findImage("��������1");
	l2 = IMAGEMANAGER->findImage("��������2");
	l3 = IMAGEMANAGER->findImage("��������3");
	l4 = IMAGEMANAGER->findImage("��������4");
	l5 = IMAGEMANAGER->findImage("��������5");
	l6 = IMAGEMANAGER->findImage("��������6");
	l7 = IMAGEMANAGER->findImage("��������7");
	l8 = IMAGEMANAGER->findImage("��������8");
	l9 = IMAGEMANAGER->findImage("��������9");
	l00 = IMAGEMANAGER->findImage("��������0");
	l01 = IMAGEMANAGER->findImage("��������1");
	l02 = IMAGEMANAGER->findImage("��������2");
	l03 = IMAGEMANAGER->findImage("��������3");
	l04 = IMAGEMANAGER->findImage("��������4");
	l05 = IMAGEMANAGER->findImage("��������5");
	l06 = IMAGEMANAGER->findImage("��������6");
	l07 = IMAGEMANAGER->findImage("��������7");
	l08 = IMAGEMANAGER->findImage("��������8");
	l09 = IMAGEMANAGER->findImage("��������9");
	l000 = IMAGEMANAGER->findImage("��������0");
	l001 = IMAGEMANAGER->findImage("��������1");
	l002 = IMAGEMANAGER->findImage("��������2");
	l003 = IMAGEMANAGER->findImage("��������3");
	l004 = IMAGEMANAGER->findImage("��������4");
	l005 = IMAGEMANAGER->findImage("��������5");
	l006 = IMAGEMANAGER->findImage("��������6");
	l007 = IMAGEMANAGER->findImage("��������7");
	l008 = IMAGEMANAGER->findImage("��������8");
	l009 = IMAGEMANAGER->findImage("��������9");

	_0 = IMAGEMANAGER->findImage("��0");
	_1 = IMAGEMANAGER->findImage("��1");
	_2 = IMAGEMANAGER->findImage("��2");
	_3 = IMAGEMANAGER->findImage("��3");
	_4 = IMAGEMANAGER->findImage("��4");
	_5 = IMAGEMANAGER->findImage("��5");
	_6 = IMAGEMANAGER->findImage("��6");
	_7 = IMAGEMANAGER->findImage("��7");
	_8 = IMAGEMANAGER->findImage("��8");
	_9 = IMAGEMANAGER->findImage("��9");

	_rs = IMAGEMANAGER->findImage("��������");
	_Lc = IMAGEMANAGER->findImage("[");
	_Rc = IMAGEMANAGER->findImage("]");
	_percent = IMAGEMANAGER->findImage("%");
	_dot = IMAGEMANAGER->findImage("��");

	_form->setX(750);
	_form->setY(690);
	_formBackground->setX(_form->getX() + 3);
	_formBackground->setY(_form->getY() + 25);
	
	hpbar->setX(_formBackground->getX() + 22);
	hpbar->setY(_formBackground->getY() + 3);

	mpbar->setX(_formBackground->getX() + 22);
	mpbar->setY(_formBackground->getY() + 19);

	_lv->setX(_form->getX() + 25);
	_lv->setY(_form->getY() + 7);

	//����ġ��	  
	expBackground = IMAGEMANAGER->findImage("����ġ0");
	expGuage = IMAGEMANAGER->findImage("����ġ2");
	expLayer = IMAGEMANAGER->findImage("����ġ3");
	expEffect = IMAGEMANAGER->findImage("����ġ4");

	expBackground->setX(0);
	expBackground->setY(758);
	expGuage->setX(16);
	expGuage->setY(761);
	expLayer->setX(150);
	expLayer->setY(761);

	Level = pl->getstatus()->Level;
	playerHp = pl->getstatus()->curHP;
	playerMp = pl->getstatus()->curMP;
	MaxHp = pl->getstatus()->maxHP;
	MaxMp = pl->getstatus()->maxMP;
	_str = pl->getstatus()->Str;
	_dex = pl->getstatus()->Dex;
	_int = pl->getstatus()->Int;
	_luk = pl->getstatus()->Luk;
	_ap = pl->getstatus()->ap;
	_exp = pl->getstatus()->Exp;
	LvExp = pl->getstatus()->lvlUpExp;

	//----------------------------------�����̹����ε�-----------------------

	//ó������
	onShop = false;
	onShopEquipTab = true, onShopPortionTab = false, onShopEtcTab = false;

	_me = IMAGEMANAGER->findImage("ĳ����");
	_Azoomma = IMAGEMANAGER->findImage("storenpc");
	shopWnd = IMAGEMANAGER->findImage("����");
	shopQuit = IMAGEMANAGER->findImage("���������⸶�콺");
	shopBuy = IMAGEMANAGER->findImage("�����ۻ�⸶�콺");
	shopSell = IMAGEMANAGER->findImage("�������ȱ⸶�콺");
	shopQuitPushed = IMAGEMANAGER->findImage("���������ⴭ��");
	shopBuyPushed = IMAGEMANAGER->findImage("�����ۻ�ⴭ��");
	shopSellPushed = IMAGEMANAGER->findImage("�������ȱⴭ��");
	shopEquip = IMAGEMANAGER->findImage("�������Ȱ��");
	shopPortion = IMAGEMANAGER->findImage("�����Һ�Ȱ��");
	shopEtc = IMAGEMANAGER->findImage("������ŸȰ��");
	mesoIcon = IMAGEMANAGER->findImage("�޼Ҿ�����");
	selectEffect = IMAGEMANAGER->findImage("����Ʈȿ��");
	selectEffect2 = IMAGEMANAGER->findImage("����Ʈȿ��2");

	_me->setFrameX(0);
	_me->setFrameY(0);
	_Azoomma->setFrameX(0);
	_Azoomma->setFrameY(0);

	_meCount = 0;
	_AzoommaCount = 0;

	Sellings = new items;
	Sellings->init();
	Mines = new items;
	Mines->init();

	shopListClick = -1;

	//-------------------------------�ӽú����� �ʱ� ����---------------------------

	count = fingerCount = 0;

	onClickQuit = onClickBuy = onClickSell = onClickAzoomma = false;

	return S_OK;
}

void UserInterface::release(void)
{
}

void UserInterface::update(void)
{
	//------------------------------�ǽð� UI���μ��� ���ž�!-----------------------------


	//������ ó���� ���� ����
	count++;

	//�ǽð� ĳ�����������ž�
	Level = pl->getstatus()->Level;
	playerHp = pl->getstatus()->curHP;
	playerMp = pl->getstatus()->curMP;
	MaxHp = pl->getstatus()->maxHP;
	MaxMp = pl->getstatus()->maxMP;
	_str = pl->getstatus()->Str + totalEquipstr;
	_dex = pl->getstatus()->Dex + totalEquipdex;
	_int = pl->getstatus()->Int + totalEquipint;
	_luk = pl->getstatus()->Luk + totalEquipluk;
	_ap = pl->getstatus()->ap;
	_exp = pl->getstatus()->Exp;
	LvExp = pl->getstatus()->lvlUpExp;

	totalEquipstr = i_cap.str + i_weapon.str + i_clothes.str + i_earAcc.str + i_pants.str + i_shoes.str + i_gloves.str + i_capes.str;
	totalEquipdex = i_cap.dex + i_weapon.dex + i_clothes.dex + i_earAcc.dex + i_pants.dex + i_shoes.dex + i_gloves.dex + i_capes.dex;
	totalEquipint = i_cap.inteligence + i_weapon.inteligence + i_clothes.inteligence + i_earAcc.inteligence + i_pants.inteligence + i_shoes.inteligence + i_gloves.inteligence + i_capes.inteligence;
	totalEquipluk = i_cap.luk + i_weapon.luk + i_clothes.luk + i_earAcc.luk + i_pants.luk + i_shoes.luk + i_gloves.luk + i_capes.luk;

	//�ǽð� ���������� ���ž�(��Ÿ �������� �����Ƿ� ����)
	
	/*for (int i = 0; i < 24; i++)
	{
		c_equip[i] = 
	}*/

	//ü���� ȸ���ǰ� �ִ°�
	if (HpHillCount != 0)
	{
		HpHillCount--;
		if (pl->getstatus()->curHP + HpHill >= pl->getstatus()->maxHP)
		{
			pl->setCurHP(pl->getstatus()->maxHP);
		}
		else
		{
			pl->setCurHP(pl->getstatus()->curHP + HpHill);
		}
		HpHillMax -= HpHill;
	}
	//������ ȸ���ǰ� �ִ°�
	if (MpHillCount != 0)
	{
		MpHillCount--;
		if (pl->getstatus()->curMP + MpHill >= pl->getstatus()->maxMP)
		{
			pl->setCurMP(pl->getstatus()->maxMP);
		}
		else
		{
			pl->setCurMP(pl->getstatus()->curMP + MpHill);
		}
		MpHillMax -= MpHill;
	}


	////==============================================���콺 �÷������� �ΰž׼�!!!!=========================================


	/*if���� �����ؼ� ó���Ϸ��� �ϸ� �浹�ع����� if else ��Ʈ�� �Ѳ����� ������.*/

	
	if (PtInRect(&equipTabSq, ptMouse) || PtInRect(&potionTabSq, ptMouse) || PtInRect(&etcTabSq, ptMouse))
	{
		finger->setFrameY(2);
		if (count % 30 == 0)
		{
			fingerCount++;
			if (fingerCount > finger->getMaxFrameX()) fingerCount = 0;
		}
	}

	else if (PtInRect(&_myInven[0], ptMouse)  || PtInRect(&_myInven[1], ptMouse) || PtInRect(&_myInven[2], ptMouse) ||
		PtInRect(&_myInven[3], ptMouse) || PtInRect(&_myInven[4], ptMouse) || PtInRect(&_myInven[5], ptMouse) ||
		PtInRect(&_myInven[6], ptMouse) || PtInRect(&_myInven[7], ptMouse) || PtInRect(&_myInven[8], ptMouse) ||
		PtInRect(&_myInven[9], ptMouse) || PtInRect(&_myInven[10], ptMouse) || PtInRect(&_myInven[11], ptMouse) || 
		PtInRect(&_myInven[12], ptMouse) || PtInRect(&_myInven[13], ptMouse) || PtInRect(&_myInven[14], ptMouse) || 
		PtInRect(&_myInven[15], ptMouse) || PtInRect(&_myInven[16], ptMouse) || PtInRect(&_myInven[17], ptMouse) || 
		PtInRect(&_myInven[18], ptMouse) || PtInRect(&_myInven[19], ptMouse) || PtInRect(&_myInven[20], ptMouse) || 
		PtInRect(&_myInven[21], ptMouse) || PtInRect(&_myInven[22], ptMouse) || PtInRect(&_myInven[23], ptMouse))
	{
		finger->setFrameY(3);
		if (count % 30 == 0)
		{
			fingerCount++;
			if (fingerCount > finger->getMaxFrameX()) fingerCount = 0;
		}
	}	

	// 1. ---------------------------Ŀ���� �������ܸ����� ���ٴ����� ��Ÿ���� �ΰž׼�
	else if (pl->openShop() == true) 
	{	
		finger->setFrameY(2);
		if (count % 30 == 0)
		{
			fingerCount++;
			if (fingerCount > finger->getMaxFrameX()) fingerCount = 0;
		}
	}

	// 2. ------------------------------------â�� ��������(���â�� �� �׼��� ���� �����Ƿ� ����)-----------------------
	else if (onShop)
	{
		//â�� ��ư�� �����۸�Ͽ� ���콺�� �÷����� Ŀ���׼�
		if (PtInRect(&shopItem[0], ptMouse) || PtInRect(&shopItem[1], ptMouse) || 
			PtInRect(&shopItem[2], ptMouse) || PtInRect(&shopItem[3], ptMouse) || 
			PtInRect(&shopItem[4], ptMouse) || PtInRect(&shopItem[5], ptMouse) || 
			PtInRect(&shopItem[6], ptMouse) || PtInRect(&shopItem[7], ptMouse) || 
			PtInRect(&shopItem[8], ptMouse) || PtInRect(&buttonQuit, ptMouse) ||
			PtInRect(&buttonBuy, ptMouse) || PtInRect(&buttonSell, ptMouse) ||
			PtInRect(&myItem[0], ptMouse) || PtInRect(&myItem[1], ptMouse) ||
			PtInRect(&myItem[2], ptMouse) || PtInRect(&myItem[3], ptMouse) ||
			PtInRect(&myItem[4], ptMouse) || PtInRect(&myItem[5], ptMouse) ||
			PtInRect(&myItem[6], ptMouse) || PtInRect(&myItem[7], ptMouse) ||
			PtInRect(&myItem[8], ptMouse) || PtInRect(&shopEquipTab, ptMouse) ||
			PtInRect(&shopPortionTab, ptMouse) || PtInRect(&shopEtcTab, ptMouse))
		{
			finger->setFrameY(2);
			if (count % 30 == 0)
			{
				fingerCount++;
				if (fingerCount > finger->getMaxFrameX()) fingerCount = 0;
			}
		}
		//â���ο��� ��ư���� �ִ°� �ƴҶ�
		else
		{
			fingerCount = 0;
			finger->setFrameY(0);
		}
	}

	// 3.-------���â�� �������°�, ���콺���� �������׵� �ø��� �ƴҶ�. �� �����ؾ��Ѵ�. �� ������ ���콺�׼� �� ������ ����. else if�� ���ɽ��� ���ؾ���.---------------
	else
	{
		fingerCount = 0;
		finger->setFrameY(0);
	}
	//====================================================�ΰž׼� ��==============================


	//����â ���� ĳ����, npc�������� ���� ������ ó��.
	if (onShop)
	{
		//����� �̷� �����ӷ����� ���� ī��Ʈ ������ ������ ������Ʈ �κп��� ����� �ߵȴ�.
		//�������κп��� ���ִϱ� �����Ÿ���.

		if (count % 40 == 0)
		{
			_meCount++;
			if (_meCount > _me->getMaxFrameX()) _meCount = 0;
		}

		if (count % 50 == 0)
		{
			_AzoommaCount++;
			if (_AzoommaCount > _Azoomma->getMaxFrameX()) _AzoommaCount = 0;
		}
	}

	if (onShop)
	{
		//�������1 �̾��� ���
		if (PtInRect(&shopItem[0], ptMouse))
		{
			shopList = 0;
		}

		//�������2 �̾��� ���
		else if (PtInRect(&shopItem[1], ptMouse))
		{
			shopList = 1;
		}

		//�������3 �̾��� ���
		else if (PtInRect(&shopItem[2], ptMouse))
		{
			shopList = 2;
		}

		//�������4 �̾��� ���
		else if (PtInRect(&shopItem[3], ptMouse))
		{
			shopList = 3;
		}

		//�������5 �̾��� ���
		else if (PtInRect(&shopItem[4], ptMouse))
		{
			shopList = 4;
		}

		//�������6 �̾��� ���
		else if (PtInRect(&shopItem[5], ptMouse))
		{
			shopList = 5;
		}

		//�������7 �̾��� ���
		else if (PtInRect(&shopItem[6], ptMouse))
		{
			shopList = 6;
		}

		//�������8 �̾��� ���
		else if (PtInRect(&shopItem[7], ptMouse))
		{
			shopList = 7;
		}

		//�������9 �̾��� ���
		else if (PtInRect(&shopItem[8], ptMouse))
		{
			shopList = 8;
		}
		//�׹��� ���������� â�� ����� �ʴ´�.
		else
			shopList = -1;

	}


	///////////////////////////�κ��丮 ���������� �����ֱ�//////////////////////////////////////////

	if (onInven)
	{
		for (int i = 0; i < 24; i++)
		{
	
			if (PtInRect(&_myInven[i], ptMouse))
			{
				if (invEq)
				{
					if (c_equip[i] >= 0)
						invInfo = pl->getEquip().at(c_equip[i]).number;
					else 
						invInfo = -1;
				}

				else if (invPo)
				{
					if (c_consume[i] >= 0)
						invInfo = pl->getConsume().at(c_consume[i]).number;
					else
						invInfo = -1;
				}

				else if (invEtc)
				{
					if (c_etc[i] >= 0)
						invInfo = pl->getEtc().at(c_etc[i]).number;
					else
						invInfo = -1;
				}
			}
		}

		//�̰� �����ָ� ����������â �Ȳ�����.......
		if (!PtInRect(&_myInven[0], ptMouse) && !PtInRect(&_myInven[1], ptMouse) && !PtInRect(&_myInven[2], ptMouse) && !PtInRect(&_myInven[3], ptMouse) &&
			!PtInRect(&_myInven[4], ptMouse) && !PtInRect(&_myInven[5], ptMouse) && !PtInRect(&_myInven[6], ptMouse) && !PtInRect(&_myInven[7], ptMouse) &&
			!PtInRect(&_myInven[8], ptMouse) && !PtInRect(&_myInven[9], ptMouse) && !PtInRect(&_myInven[10], ptMouse) && !PtInRect(&_myInven[11], ptMouse) &&
			!PtInRect(&_myInven[12], ptMouse) && !PtInRect(&_myInven[13], ptMouse) && !PtInRect(&_myInven[14], ptMouse) && !PtInRect(&_myInven[15], ptMouse) &&
			!PtInRect(&_myInven[16], ptMouse) && !PtInRect(&_myInven[17], ptMouse) && !PtInRect(&_myInven[18], ptMouse) && !PtInRect(&_myInven[19], ptMouse) &&
			!PtInRect(&_myInven[20], ptMouse) && !PtInRect(&_myInven[21], ptMouse) && !PtInRect(&_myInven[22], ptMouse) && !PtInRect(&_myInven[23], ptMouse))
		{
			invInfo = -1;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	//---------------------------------------------�Է�ó��-----------------------------------------------
	///////////////////////////////////////////////////////////////////////////////////////////////////////


	//�κ��丮â ����.
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		onInven = !onInven;
	}

	//����â ����
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		onStat = !onStat;
	}


	//���â ����
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		onEquip = !onEquip;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{

		//�κ��丮â�� �����ִ°��
		if (onInven)
		{
			//������̾��� ���
			if (PtInRect(&equipTabSq, ptMouse))
			{
				invEq= true;
				invPo = false;
				invEtc = false;
			}


			//�Һ����̾��� ���
			if (PtInRect(&potionTabSq, ptMouse))
			{
				invEq = false;
				invPo = true;
				invEtc = false;
			}


			//��Ÿ���̾��� ���
			if (PtInRect(&etcTabSq, ptMouse))
			{
				invEq = false;
				invPo = false;
				invEtc = true;
			}
		}

		
		//���� ���ܸ� Ŭ���ϱ⾲
		if (pl->openShop() == true) {
			onClickAzoomma = true;
		}

		//���� ���� �����ִ� ���
		else if (onShop)
		{
			//�������� ������ ��ư���� �־��� ���
			if (PtInRect(&buttonQuit, ptMouse))
			{
				onClickQuit = true;
			}
			//�������� �����ۻ�� ��ư���� �־��� ���
			if (PtInRect(&buttonBuy, ptMouse))
			{
				onClickBuy = true;
			}
			//�������� �������ȱ� ��ư���� �־��� ���
			if (PtInRect(&buttonSell, ptMouse))
			{
				onClickSell = true;
			}
			
			//������̾��� ���
			if (PtInRect(&shopEquipTab, ptMouse))
			{
				onShopEquipTab = true;
				onShopPortionTab = false;
				onShopEtcTab = false;
				//���� �ٲ𶧸��� �����ߴ� �κ��� �ʱ�ȭ.
				myList = -1;

			}


			//�Һ����̾��� ���
			if (PtInRect(&shopPortionTab, ptMouse))
			{
				onShopEquipTab = false;
				onShopPortionTab = true;
				onShopEtcTab = false;
				myList = -1;
			}


			//��Ÿ���̾��� ���
			if (PtInRect(&shopEtcTab, ptMouse))
			{
				onShopEquipTab = false;
				onShopPortionTab = false;
				onShopEtcTab = true;
				myList = -1;
			}


			//�������۸��1 �̾��� ���
			if (PtInRect(&myItem[0], ptMouse))
			{
				myList = 0;
			}

			//�������۸��2 �̾��� ���
			if (PtInRect(&myItem[1], ptMouse))
			{
				myList = 1;
			}

			//�������۸��3 �̾��� ���
			if (PtInRect(&myItem[2], ptMouse))
			{
				myList = 2;
			}

			//�������۸��4 �̾��� ���
			if (PtInRect(&myItem[3], ptMouse))
			{
				myList = 3;
			}

			//�������۸��5 �̾��� ���
			if (PtInRect(&myItem[4], ptMouse))
			{
				myList = 4;
			}

			//�������۸��6 �̾��� ���
			if (PtInRect(&myItem[5], ptMouse))
			{
				myList = 5;
			}

			//�������۸��7 �̾��� ���
			if (PtInRect(&myItem[6], ptMouse))
			{
				myList = 6;
			}

			//�������۸��8 �̾��� ���
			if (PtInRect(&myItem[7], ptMouse))
			{
				myList = 7;
			}

			//�������۸��9 �̾��� ���
			if (PtInRect(&myItem[8], ptMouse))
			{
				myList = 8;
			}

			//�������1 �̾��� ���
			if (PtInRect(&shopItem[0], ptMouse))
			{
				shopListClick = 0;
			}

			//�������2 �̾��� ���
			else if (PtInRect(&shopItem[1], ptMouse))
			{
				shopListClick = 1;
			}

			//�������3 �̾��� ���
			else if (PtInRect(&shopItem[2], ptMouse))
			{
				shopListClick = 2;
			}

			//�������4 �̾��� ���
			else if (PtInRect(&shopItem[3], ptMouse))
			{
				shopListClick = 3;
			}

			//�������5 �̾��� ���
			else if (PtInRect(&shopItem[4], ptMouse))
			{
				shopListClick = 4;
			}

			//�������6 �̾��� ���
			else if (PtInRect(&shopItem[5], ptMouse))
			{
				shopListClick = 5;
			}

			//�������7 �̾��� ���
			else if (PtInRect(&shopItem[6], ptMouse))
			{
				shopListClick = 6;
			}

			//�������8 �̾��� ���
			else if (PtInRect(&shopItem[7], ptMouse))
			{
				shopListClick = 7;
			}

			//�������9 �̾��� ���
			else if (PtInRect(&shopItem[8], ptMouse))
			{
				shopListClick = 8;
			}

			//////////////////////////////������ �����ϱ�//////////////////////////////////
			else if (PtInRect(&buttonBuy, ptMouse))
			{
				switch (shopListClick)
				{
				case 0:
					if (pl->getmeso() >= Sellings->_item.at(0)._price)
					{
						pl->buyConsume(Sellings->_item.at(0));
						pl->spendmeso(Sellings->_item.at(0)._price);
					}
					break;
				case 1: //4
					if (pl->getmeso() >= Sellings->_item.at(4)._price)
					{
						pl->buyConsume(Sellings->_item.at(4));
						pl->spendmeso(Sellings->_item.at(4)._price);
					}
					break;
				case 2://7
					if (pl->getmeso() >= Sellings->_item.at(7)._price)
					{
						pl->buyEquip(Sellings->_item.at(7));
						pl->spendmeso(Sellings->_item.at(7)._price);
					}
					break;
				case 3://9
					if (pl->getmeso() >= Sellings->_item.at(9)._price)
					{
						pl->buyEquip(Sellings->_item.at(9));
						pl->spendmeso(Sellings->_item.at(9)._price);
					}
					break;
				case 4://13
					if (pl->getmeso() >= Sellings->_item.at(13)._price)
					{
						pl->buyEquip(Sellings->_item.at(13));
						pl->spendmeso(Sellings->_item.at(13)._price);
					}
					break;
				case 5://15
					if (pl->getmeso() >= Sellings->_item.at(15)._price)
					{
						pl->buyEquip(Sellings->_item.at(15));
						pl->spendmeso(Sellings->_item.at(15)._price);
					}
					break;
				case 6://19
					if (pl->getmeso() >= Sellings->_item.at(19)._price)
					{
						pl->buyEquip(Sellings->_item.at(19));
						pl->spendmeso(Sellings->_item.at(19)._price);
					}
					break;
				case 7://21
					if (pl->getmeso() >= Sellings->_item.at(21)._price)
					{
						pl->buyEquip(Sellings->_item.at(21));
						pl->spendmeso(Sellings->_item.at(21)._price);
					}
					break;
				case 8://26
					if (pl->getmeso() >= Sellings->_item.at(26)._price)
					{
						pl->buyEquip(Sellings->_item.at(26));
						pl->spendmeso(Sellings->_item.at(26)._price);
					}
					break;

				}

				//������ ����� �κ��丮 ������ �������ش�.
				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if ((i * 4 + j)<pl->getEquip().size())
							c_equip[i * 4 + j] = i * 4 + j;
						if ((i * 4 + j)<pl->getConsume().size())
							c_consume[i * 4 + j] = i * 4 + j;
					}
				}

			}
			////////////////////////������ �Ǹ��ϱ�//////////////////////////////////
			else if (PtInRect(&buttonSell, ptMouse))
			{
				if (onShopEquipTab)
				{
					switch (myList)
					{
					case 0:
						pl->sellEquip(0);
						pl->earnMeso(pl->getEquip().at(0)._price);
						break;
					case 1:
						pl->sellEquip(1);
						pl->earnMeso(pl->getEquip().at(1)._price);
						break;
					case 2:
						pl->sellEquip(2);
						pl->earnMeso(pl->getEquip().at(2)._price);
						break;
					case 3:
						pl->sellEquip(3);
						pl->earnMeso(pl->getEquip().at(3)._price);
						break;
					case 4:
						pl->sellEquip(4);
						pl->earnMeso(pl->getEquip().at(4)._price);
						break;
					case 5:
						pl->sellEquip(5);
						pl->earnMeso(pl->getEquip().at(5)._price);
						break;
					case 6:
						pl->sellEquip(6);
						pl->earnMeso(pl->getEquip().at(6)._price);
						break;
					case 7:
						pl->sellEquip(7);
						pl->earnMeso(pl->getEquip().at(7)._price);
						break;
					case 8:
						pl->sellEquip(8);
						pl->earnMeso(pl->getEquip().at(8)._price);
						break;
					}
				}
				else if (onShopPortionTab)
				{
					switch (myList)
					{
					case 0:
						pl->sellConsume(0);
						pl->earnMeso(pl->getConsume().at(0)._price);
						break;
					case 1:
						pl->sellConsume(1);
						pl->earnMeso(pl->getConsume().at(1)._price);
						break;
					case 2:
						pl->sellConsume(2);
						pl->earnMeso(pl->getConsume().at(2)._price);
						break;
					case 3:
						pl->sellConsume(3);
						pl->earnMeso(pl->getConsume().at(3)._price);
						break;
					case 4:
						pl->sellConsume(4);
						pl->earnMeso(pl->getConsume().at(4)._price);
						break;
					case 5:
						pl->sellConsume(5);
						pl->earnMeso(pl->getConsume().at(5)._price);
						break;
					case 6:
						pl->sellConsume(6);
						pl->earnMeso(pl->getConsume().at(6)._price);
						break;
					case 7:
						pl->sellConsume(7);
						pl->earnMeso(pl->getConsume().at(7)._price);
						break;
					case 8:
						pl->sellConsume(8);
						pl->earnMeso(pl->getConsume().at(8)._price);
						break;
					}
				}

				
				//������ �Ȱ��� �κ��丮 ������ �������ش�.
				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if ((i * 4 + j)<pl->getEquip().size())
							c_equip[i * 4 + j] = i * 4 + j;
						if ((i * 4 + j)<pl->getConsume().size())
							c_consume[i * 4 + j] = i * 4 + j;
					}
				}
			}
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		finger->setFrameY(1);
		//==============���� ���ܸ�Ŭ������ ��ư�׼��� �ߵ���Ų ���¶��=============
		if (pl->openShop() == true && onClickAzoomma) {
			//��ư�׼� ����
			onClickAzoomma = true;
		}
		//�ƴ϶�� ��ư�׼� ����
		else
			onClickAzoomma = false;

		//==================���� ������ ��ư�׼��� �ߵ���Ų���¶��==================
		if (onShop)
		{
			//��ư������ ������������ Ŭ���� ���������ش�.
			if (PtInRect(&buttonQuit, ptMouse) && onClickQuit)
			{
				onClickQuit = true;
			}
			//�������¿��� ��ư�� ����� �׼��� ��ҽ�Ų��.
			else
				onClickQuit = false;

			if (PtInRect(&buttonBuy, ptMouse) && onClickBuy)
			{
				onClickBuy = true;
			}
			else
				onClickBuy = false;

			if (PtInRect(&buttonSell, ptMouse) && onClickSell)
			{
				onClickSell = true;
			}
			else
				onClickSell = false;
		}

	}
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		finger->setFrameY(0);
		//==================�������ܸ��� ������ �ִ� ���===============
		if (pl->openShop() == true && onClickAzoomma) {
			//���콺�� ���� ���ÿ� ������ ���ش�.
			this->onShop = true;
		}

		//==================������ ��ư�� �������ִ� ���===============
		if (onShop)
		{
			//������ ��ư���� �־� ���
			if (PtInRect(&buttonQuit, ptMouse) && onClickQuit)
			{
				//��ưŬ���� ���ְ�, ���� �ݾ��ش�.
				onClickQuit = false;
				onShop = false;
			}
			else
				//�ƴѰ�� ��ư�׼Ǹ� ��ȿȭ��Ų��.
				onClickQuit = false;

			//������ ����ư�� �־��� ���
			if (PtInRect(&buttonBuy, ptMouse) && onClickBuy)
			{
				onClickBuy = false;
			}
			else
				onClickBuy = false;

			//�������ȱ��ư�̾��� ���
			if (PtInRect(&buttonSell, ptMouse) && onClickSell)
			{
				onClickSell = false;
			}
			else
				onClickSell = false;
			
		}
	}

	//��Ŭ�� �̺�Ʈ!!! ������ ���� ����!!!!
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		//�κ��丮â�� �������������θ� �������Ѿ� �Ѵ�.
		if (onInven)
		{
			//����ǿ��� �������Ѿ� ��.
			if (invEq)
			{
				for (int i = 0; i < 24; i++)
				{
					if (PtInRect(&_myInven[i], ptMouse))
					{
						if (c_equip[i] >= 0)
						{
							switch (pl->getEquip().at(c_equip[i]).itemtype)
							{
							case helm:
								//�̹� ������ �ϰ� ������ ������ ���� �ؾ��ϴϱ�;;
								if (e_cap > 0)
								{
									e_cap = -1;
									//�κ��丮�� ����� ���������� ���� �ִ´�.
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_cap.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_cap = i_empty; //�̰� ���� ���� �ö󰬴� ���� �ٽ� ���󺹱ͽ����ش�.
								}
								
								e_cap = pl->getEquip().at(c_equip[i]).number;
								i_cap = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case earacc:
								e_earAcc = pl->getEquip().at(c_equip[i]).number;
								i_earAcc = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case clothes:
								if (e_clothes > 0)
								{
									e_clothes = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_clothes.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_clothes = i_empty;
								}
								e_clothes = pl->getEquip().at(c_equip[i]).number;
								i_clothes = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case pants:
								if (e_pants > 0)
								{
									e_pants = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_pants.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_pants = i_empty;
								}
								e_pants = pl->getEquip().at(c_equip[i]).number;
								i_pants = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case boots:
								if (e_shoes > 0)
								{
									e_shoes = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_shoes.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_shoes = i_empty;
								}
								e_shoes = pl->getEquip().at(c_equip[i]).number;
								i_shoes = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case weapons:
								if (e_weapon > 0)
								{
									e_weapon = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_weapon.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_weapon = i_empty;
								}
								e_weapon = pl->getEquip().at(c_equip[i]).number;
								i_weapon = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case gloves:
								if (e_gloves > 0)
								{
									e_gloves = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_gloves.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_gloves = i_empty;
								}
								e_gloves = pl->getEquip().at(c_equip[i]).number;
								i_gloves = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case cape:
								if (e_capes > 0)
								{
									e_capes = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_capes.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_capes = i_empty;
								}
								e_capes = pl->getEquip().at(c_equip[i]).number;
								i_capes = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							}
						}
					}
				}
			}
		}


		//���â���� ������ ���

		if (onEquip)
		{
			//����
			if (PtInRect(&_cap, ptMouse))
			{
				if (e_cap > 0)
				{
					e_cap = -1;
					//�κ��丮�� ����� ���������� ���� �ִ´�.
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_cap.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_cap = i_empty; //�̰� ���� ���� �ö󰬴� ���� �ٽ� ���󺹱ͽ����ش�.
				}
			}

			//����
			if (PtInRect(&_weapon, ptMouse))
			{
				if (e_weapon > 0)
				{
					e_weapon = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_weapon.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_weapon = i_empty;
				}
			}

			//�Ͱ�
			if (PtInRect(&_earAcc, ptMouse))
			{
				//�Ͱ��� �����ϱ� �ƹ�ó��������.
			}

			//����
			if (PtInRect(&_clothes, ptMouse))
			{
				if (e_clothes > 0)
				{
					e_clothes = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_clothes.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_clothes = i_empty;
				}
			}

			//����
			if (PtInRect(&_pants, ptMouse))
			{
				if (e_pants > 0)
				{
					e_pants = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_pants.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_pants = i_empty;
				}
			}

			//�Ź�
			if (PtInRect(&_shoes, ptMouse))
			{
				if (e_shoes > 0)
				{
					e_shoes = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_shoes.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_shoes = i_empty;
				}
			}

			//�尩
			if (PtInRect(&_gloves, ptMouse))
			{
				if (e_gloves > 0)
				{
					e_gloves = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_gloves.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_gloves = i_empty;
				}
			}

			//����
			if (PtInRect(&_capes, ptMouse))
			{
				if (e_capes > 0)
				{
					e_capes = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_capes.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_capes = i_empty;
				}
			}
		}

	}

	//Ű �۵� Ȯ��.
	//ü������ ó��ó��
	if (KEYMANAGER->isOnceKeyDown(VK_DELETE))
	{
		HpHillMax += 50;
		HpHill = HpHillMax / 10;
		HpHillCount = 10;
	}

	//�������� ó��ó��
	if (KEYMANAGER->isOnceKeyDown(VK_INSERT))
	{
		MpHillMax += 50;
		MpHill = MpHillMax / 10;
		MpHillCount = 10;
		
	}
	Hpwidth = ((float)pl->getstatus()->curHP / (float)pl->getstatus()->maxHP) * (float)hpbar->getWidth();
	Mpwidth = ((float)pl->getstatus()->curMP / (float)pl->getstatus()->maxMP)*(float)mpbar->getWidth();
	Exwidth = ((float)pl->getstatus()->Exp / (float)pl->getstatus()->lvlUpExp)*(float)expGuage->getWidth();
}

void UserInterface::render(void)
{
	//�ؽ�Ʈ �������� �ʿ��� �⺻������
	SetBkMode(getMemDC(), TRANSPARENT); //�̰� ����� ������ ���ش�.
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	//�⺻�������̽� ������
	//����ġ
	expBackground->render(getMemDC());
	expGuage->render(getMemDC(), 16, 761, 0, 0, Exwidth, expLayer->getHeight());
	expLayer->render(getMemDC());

	//ĳ�������� �� ü��, ����������
	_formBackground->render(getMemDC());
	hpbar->render(getMemDC(), _formBackground->getX() + 22, _formBackground->getY() + 3, 0, 0, Hpwidth, mpbar->getHeight());
	mpbar->render(getMemDC(), _formBackground->getX() + 22, _formBackground->getY() + 17, 0, 0, Mpwidth, hpbar->getHeight());
	_form->render(getMemDC());
	_shine->alphaRender(getMemDC(), _form->getX(), _form->getY(), 120);

	//������ ��ġ ǥ��
	showStatement();

	//����, ���̵� ǥ��
	_lv->render(getMemDC());
	showLevel();
	char temp[255];
	sprintf(temp, "�ƹ������Ÿ��");
	TextOut(getMemDC(), _form->getX() + 75, _form->getY() + 5, temp, strlen(temp));

	//������


	slotbackground->alphaRender(getMemDC(), 1019, 688, 180);
	slotcover1->render(getMemDC(), 1009, 686);
	slotcover2->render(getMemDC(), 1017, 685);



	///////////////////////////////////���⿡ ��ų, �������̹���, ����ȣ �ֵ��� �Ͽ���.

	//////////////////////////////////////////////////////////////////////////////////////

	q1 -> render(getMemDC(), 1162, 690);
	q2 -> render(getMemDC(), 1197, 690);
	q3 -> render(getMemDC(), 1232, 690);
	q4 -> render(getMemDC(), 1267, 690);
	q5 -> render(getMemDC(), 1302, 690);
	q6 -> render(getMemDC(), 1337, 690);
	qq->render(getMemDC(), 1162, 725);
	qw->render(getMemDC(), 1197, 725);
	qe->render(getMemDC(), 1232, 725);
	qr->render(getMemDC(), 1267, 725);
	qt->render(getMemDC(), 1302, 725);
	qa->render(getMemDC(), 1337, 725);
	_ctrl->render(getMemDC(), 1022, 725);
	_shift->render(getMemDC(), 1022, 690);
	_inst->render(getMemDC(), 1057, 690);
	_del->render(getMemDC(), 1057, 725);
	_hm -> render(getMemDC(), 1092, 690);
	_end->render(getMemDC(), 1092, 725);
	_pgup->render(getMemDC(), 1127, 690);
	_pgdn->render(getMemDC(), 1127, 725);


	//����â, ���â, �κ��丮, ���� ������
	if (onStat)
		statement();
	if (onEquip)
		equip();
	if (onInven)
		inventory();
	if (onShop)
		shop();

	//���콺 Ŀ�� �����
	SetCursor(NULL);
	ShowCursor(false);

	finger->frameRender(getMemDC(), ptMouse.x, ptMouse.y, fingerCount, finger->getFrameY());
}

void UserInterface::equip(void)
{
	equipWnd->render(getMemDC());
	_cap = RectMake(equipWnd->getX() + 97, equipWnd->getY() + 55, 38, 38);
	_clothes = RectMake(equipWnd->getX() + 97, equipWnd->getY() + 179, 38, 38);
	_weapon = RectMake(equipWnd->getX() + 57, equipWnd->getY() + 179, 38, 38);
	_earAcc = RectMake(equipWnd->getX() + 146, equipWnd->getY() + 134, 38, 38);
	_pants = RectMake(equipWnd->getX() + 97, equipWnd->getY() + 220, 38, 38);
	_shoes = RectMake(equipWnd->getX() + 97, equipWnd->getY() + 260, 38, 38);
	_gloves = RectMake(equipWnd->getX() + 137, equipWnd->getY() + 220, 38, 38);
	_capes = RectMake(equipWnd->getX() + 177, equipWnd->getY() + 220, 38, 38);
	//Rectangle(getMemDC(), _capes.left, _capes.top, _capes.right, _capes.bottom);

	switch (e_cap)
	{
	case 9:
		iT->_item.at(e_cap).itemimg->render(getMemDC(), _cap.left + 3, _cap.top + 3);
		break;
	case 10:
		iT->_item.at(e_cap).itemimg->render(getMemDC(), _cap.left + 3, _cap.top + 3);
		break;
	case 11:
		iT->_item.at(e_cap).itemimg->render(getMemDC(), _cap.left + 3, _cap.top + 3);
		break;
	default:
		break;
	}

	switch (e_weapon)
	{
	case 12:
		iT->_item.at(e_weapon).itemimg->render(getMemDC(), _weapon.left + 3, _weapon.top + 3);
		break;
	case 13:
		iT->_item.at(e_weapon).itemimg->render(getMemDC(), _weapon.left + 3, _weapon.top + 3);
		break;
	case 14:
		iT->_item.at(e_weapon).itemimg->render(getMemDC(), _weapon.left + 3, _weapon.top + 3);
		break;
	default:
		break;
	}

	switch (e_clothes)
	{
	case 18:
		iT->_item.at(e_clothes).itemimg->render(getMemDC(), _clothes.left + 3, _clothes.top + 3);
		break;
	case 19:
		iT->_item.at(e_clothes).itemimg->render(getMemDC(), _clothes.left + 3, _clothes.top + 3);
		break;
	case 20:
		iT->_item.at(e_clothes).itemimg->render(getMemDC(), _clothes.left + 3, _clothes.top + 3);
		break;
	default:
		break;
	}

	switch (e_earAcc)
	{
	//�Ͱ��� ��� ���� ����.
	default:
		break;
	}

	switch (e_pants)
	{
	case 15:
		iT->_item.at(e_pants).itemimg->render(getMemDC(), _pants.left + 3, _pants.top + 3);
		break;
	case 16:
		iT->_item.at(e_pants).itemimg->render(getMemDC(), _pants.left + 3, _pants.top + 3);
		break;
	case 17:
		iT->_item.at(e_pants).itemimg->render(getMemDC(), _pants.left + 3, _pants.top + 3);
		break;
	default:
		break;
	}

	switch (e_shoes)
	{
	case 21:
		iT->_item.at(e_shoes).itemimg->render(getMemDC(), _shoes.left + 3, _shoes.top + 3);
		break;
	case 22:
		iT->_item.at(e_shoes).itemimg->render(getMemDC(), _shoes.left + 3, _shoes.top + 3);
		break;
	case 23:
		iT->_item.at(e_shoes).itemimg->render(getMemDC(), _shoes.left + 3, _shoes.top + 3);
		break;
	default:
		break;
	}

	switch (e_gloves)
	{
	case 24:
		iT->_item.at(e_gloves).itemimg->render(getMemDC(), _gloves.left + 3, _gloves.top + 3);
		break;
	case 25:
		iT->_item.at(e_gloves).itemimg->render(getMemDC(), _gloves.left + 3, _gloves.top + 3);
		break;
	case 26:
		iT->_item.at(e_gloves).itemimg->render(getMemDC(), _gloves.left + 3, _gloves.top + 3);
		break;
	default:
		break;
	}

	switch (e_capes)
	{
	case 6:
		iT->_item.at(e_capes).itemimg->render(getMemDC(), _capes.left + 3, _capes.top + 3);
		break;
	case 7:
		iT->_item.at(e_capes).itemimg->render(getMemDC(), _capes.left + 3, _capes.top + 3);
		break;
	case 8:
		iT->_item.at(e_capes).itemimg->render(getMemDC(), _capes.left + 3, _capes.top + 3);
		break;
	default:
		break;
	}
}

void UserInterface::inventory(void)
{
	//��������� ���� ��Ʈ����
	HFONT font1, oldFont;

	font1 = CreateFont(12, 0, 0, 0, 100, false, 0, false, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("����ü"));
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	SetBkMode(getMemDC(), TRANSPARENT);
	oldFont = (HFONT)SelectObject(getMemDC(), font1);

	invenWnd->render(getMemDC());

	//�� Ŭ���� ���� ����ó��
	equipTabSq = RectMake(invenWnd->getX() + 9, invenWnd->getY() + 26, 30, 19);
	potionTabSq = RectMake(invenWnd->getX() + 41, invenWnd->getY() + 26, 30, 19);
	etcTabSq = RectMake(invenWnd->getX() + 73, invenWnd->getY() + 26, 30, 19);
	//Rectangle(getMemDC(), etcTabSq.left, etcTabSq.top, etcTabSq.right, etcTabSq.bottom);


	//������ ���念���� 24���̰�, �� �Ǹ��� ������� �ʿ� X.
	//�� �Ǹ��� ���������� RectMake�� ��� ������ �����������. ->���߿� ��Ÿ�� ������ �Һ������� ���ư��� ��Ÿ�������� ���ƹ���........
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_myInven[i*4 + j] = RectMake(invenWnd->getX() + 10 +36.2*j, invenWnd->getY() + 50 + 35*i, 32, 32);
		}
	}


	
	//������� �������
	if (invEq)
	{
		equipTab->render(getMemDC(), equipTabSq.left, equipTabSq.top);
		for (int i = 0; i < 24; i++)
		{
			switch (c_equip[i])
			{
			case 0:
				if (pl->getEquip().at(0).stack > 0)
				{
					pl->getEquip().at(0).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 1:
				if (pl->getEquip().at(1).stack > 0)
				{
					pl->getEquip().at(1).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 2:
				if (pl->getEquip().at(2).stack > 0)
				{
					pl->getEquip().at(2).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 3:
				if (pl->getEquip().at(3).stack > 0)
				{
					pl->getEquip().at(3).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 4:
				if (pl->getEquip().at(4).stack > 0)
				{
					pl->getEquip().at(4).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 5:
				if (pl->getEquip().at(5).stack > 0)
				{
					pl->getEquip().at(5).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 6:
				if (pl->getEquip().at(6).stack > 0)
				{
					pl->getEquip().at(6).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 7:
				if (pl->getEquip().at(7).stack > 0)
				{
					pl->getEquip().at(7).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 8:
				if (pl->getEquip().at(8).stack > 0)
				{
					pl->getEquip().at(8).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 9:
				if (pl->getEquip().at(9).stack > 0)
				{
					pl->getEquip().at(9).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 10:
				if (pl->getEquip().at(10).stack > 0)
				{
					pl->getEquip().at(10).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 11:
				if (pl->getEquip().at(11).stack > 0)
				{
					pl->getEquip().at(11).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 12:
				if (pl->getEquip().at(12).stack > 0)
				{
					pl->getEquip().at(12).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
				//�׿ܿ����� �ƹ��͵� �׸��� �ʴ´�.
			default :
				break;
			}
		}
	}

	//�Һ����� �������
	if (invPo)
	{
		potionTab->render(getMemDC(), potionTabSq.left, potionTabSq.top);
		for (int i = 0; i < 24; i++)
		{
			switch (c_consume[i])
			{
			case 0:
				if (pl->getConsume().at(0).stack > 0)
				{
					pl->getConsume().at(0).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
					char itStack1[255];
					sprintf(itStack1, "%d", pl->getConsume().at(0).stack);
					RECT rcTextArea = RectMake(_myInven[i].left, _myInven[i].top + 20, 16, 16);
					DrawText(getMemDC(), itStack1, -1, &rcTextArea, DT_LEFT);
				}
				break;
			case 1:
				if (pl->getConsume().at(1).stack > 0)
				{
					pl->getConsume().at(1).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
					char itStack2[255];
					sprintf(itStack2, "%d", pl->getConsume().at(1).stack);
					RECT rcTextArea = RectMake(_myInven[i].left, _myInven[i].top + 20, 16, 16);
					DrawText(getMemDC(), itStack2, -1, &rcTextArea, DT_LEFT);
				}
				break;
			case 2:
				if (pl->getConsume().at(2).stack > 0)
				{
					pl->getConsume().at(2).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 3:
				if (pl->getConsume().at(3).stack > 0)
				{
					pl->getConsume().at(3).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 4:
				if (pl->getConsume().at(4).stack > 0)
				{
					pl->getConsume().at(4).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 5:
				if (pl->getConsume().at(5).stack > 0)
				{
					pl->getConsume().at(5).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 6:
				if (pl->getConsume().at(6).stack > 0)
				{
					pl->getConsume().at(6).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
				//�׿ܿ����� �ƹ��͵� �׸��� �ʴ´�.
			default:
				break;
			}
		}
	}

	//��Ÿ���� �������
	if (invEtc)
	{
		etcTab->render(getMemDC(), etcTabSq.left, etcTabSq.top);
		for (int i = 0; i < 24; i++)
		{
			switch (c_etc[i])
			{
			case 0:
				if (pl->getEtc().at(0).stack > 0)
				{
					pl->getEtc().at(0).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 1:
				if (pl->getEtc().at(1).stack > 0)
				{
					pl->getEtc().at(1).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 2:
				if (pl->getEtc().at(2).stack > 0)
				{
					pl->getEtc().at(2).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 3:
				if (pl->getEtc().at(3).stack > 0)
				{
					pl->getEtc().at(3).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 4:
				if (pl->getEtc().at(4).stack > 0)
				{
					pl->getEtc().at(4).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 5:
				if (pl->getEtc().at(5).stack > 0)
				{
					pl->getEtc().at(5).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 6:
				if (pl->getEtc().at(6).stack > 0)
				{
					pl->getEtc().at(6).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
				//�׿ܿ����� �ƹ��͵� �׸��� �ʴ´�.
			default:
				break;
			}
		}
	}


	//ĳ���Ͱ� �����ϰ��ִ� �޼� ǥ��

	char tempMeso[255];
	sprintf(tempMeso, "%d", pl->getmeso());
	RECT rcTextArea = RectMake(invenWnd->getX() + 40, invenWnd->getY() + 266, 83, 15);
	DrawText(getMemDC(), tempMeso, -1, &rcTextArea, DT_RIGHT);

	//��Ʈ ���� ����.
	DeleteObject(oldFont);
	DeleteObject(font1);

	switch (invInfo)
	{
	case 0:
		showItemInfo(0);
		break;
	case 1:
		showItemInfo(1);
		break;
	case 2:
		showItemInfo(2);
		break;
	case 3:
		showItemInfo(3);
		break;
	case 4:
		showItemInfo(4);
		break;
	case 5:
		showItemInfo(5);
		break;
	case 6:
		showItemInfo(6);
		break;
	case 7:
		showItemInfo(7);
		break;
	case 8:
		showItemInfo(8);
		break;
	case 9:
		showItemInfo(9);
		break;
	case 10:
		showItemInfo(10);
		break;
	case 11:
		showItemInfo(11);
		break;
	case 12:
		showItemInfo(12);
		break;
	case 13:
		showItemInfo(13);
		break;
	case 14:
		showItemInfo(14);
		break;
	case 15:
		showItemInfo(15);
		break;
	case 16:
		showItemInfo(16);
		break;
	case 17:
		showItemInfo(17);
		break;
	case 18:
		showItemInfo(18);
		break;
	case 19:
		showItemInfo(19);
		break;
	case 20:
		showItemInfo(20);
		break;
	case 21:
		showItemInfo(21);
		break;
	case 22:
		showItemInfo(22);
		break;
	case 23:
		showItemInfo(23);
		break;
	case 24:
		showItemInfo(24);
		break;
	case 25:
		showItemInfo(25);
		break;
	case 26:
		showItemInfo(26);
		break;
	default :
		break;

	}

}

void UserInterface::statement(void)
{
	wndStat = RectMake(statWnd->getX(), statWnd->getY(), statWnd->getWidth(), statWnd->getHeight());
	statWnd->render(getMemDC());

	SetBkMode(getMemDC(), TRANSPARENT); //�̰� ����� ������ ���ش�.
	SetTextColor(getMemDC(), RGB(80, 80, 80));

	char temp[255];
	HFONT oldFont, font1;
	//CreateFont(
	//	40,					//������
	//	0,					//���� ����
	//	40,					//���� ����(����)
	//	0,					//���� ����
	//	600,				//���� ����
	//	0,					//bool ���� ���� true/false
	//	0,					//bool ���� ���� true/false
	//	0,					//bool ���� ��Ҽ� true/false
	//	HANGUL_CHARSET,		//���� ����
	//	0,					//�����Ȯ��(?)
	//	0,					//Ŭ���� ��Ȯ��
	//	0,					//����� ����Ƽ
	//	0,					//�ڰ�
	//	TEXT("�ü�ü")		//���νý�����Ʈ������
	//);
	
	font1 = CreateFont(15, 0, 0, 0, 100, false, 0, false, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("����ü"));
	SetBkMode(getMemDC(), TRANSPARENT);
	oldFont = (HFONT)SelectObject(getMemDC(), font1);
	sprintf(temp, "�ƹ������Ÿ��");
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 30, temp, strlen(temp));

	char temp2[255];
	sprintf(temp2, "���극��Ŀ");
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 49, temp2, strlen(temp2));

	char temp3[255];
	sprintf(temp3, "â���");
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 67, temp3, strlen(temp3));

	char temp4[255];
	sprintf(temp4, "��");
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 85, temp4, strlen(temp4));

	char temp5[255];
	sprintf(temp5, "�������");
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 102, temp5, strlen(temp5));


	//�߰��� ����ũ�� ����!!!!

	DeleteObject(oldFont); //�����Ҷ� ����Ʈ �����ָ� ����������!!!!
	DeleteObject(font1); //��� ���������� ���ָ� ����������......getpixel������ ����.
	font1 = CreateFont(13, 0, 0, 0, 100, false, 0, false, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("����ü"));
	oldFont = (HFONT)SelectObject(getMemDC(), font1);

	char temp6[255];
	sprintf(temp6, "%d / %d", playerHp, MaxHp);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 121, temp6, strlen(temp6));

	char temp7[255];
	sprintf(temp7, "%d / %d", playerMp, MaxMp);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 139, temp7, strlen(temp7));

	char temp8[255];
	sprintf(temp8, "%d", _ap);
	TextOut(getMemDC(), statWnd->getX() + 85, statWnd->getY() + 182, temp8, strlen(temp8));

	char temp9[255];
	sprintf(temp9, "%d(%d+%d)", _str, pl->getstatus()->Str, totalEquipstr);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 209, temp9, strlen(temp9));

	char temp10[255];
	sprintf(temp10, "%d(%d+%d)", _dex, pl->getstatus()->Dex, totalEquipdex);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 227, temp10, strlen(temp10));

	char temp11[255];
	sprintf(temp11, "%d(%d+%d)", _int, pl->getstatus()->Int, totalEquipint);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 245, temp11, strlen(temp11));

	char temp12[255];
	sprintf(temp12, "%d", _luk, pl->getstatus()->Luk, totalEquipluk);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 263, temp12, strlen(temp12));

	//�ٽ����� ��������!!!
	DeleteObject(oldFont);
	DeleteObject(font1);
}

void UserInterface::shop(void)
{
	shopWnd->setX(450);
	shopWnd->setY(100);
	shopWnd->render(getMemDC());
	
	//�����ۻ����� 35x35. ������ ����� ����ǥ�� �±״� 208x35 & 165x35.

	//���� ��ư�׼� �� �̹��� �������� ���� ������Ʈ����
	shopItem[0] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 124, 245, 35);
	shopItem[1] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 166, 245, 35);
	shopItem[2] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 208, 245, 35);
	shopItem[3] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 250, 245, 35);
	shopItem[4] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 292, 245, 35);
	shopItem[5] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 334, 245, 35);
	shopItem[6] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 376, 245, 35);
	shopItem[7] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 418, 245, 35);
	shopItem[8] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 460, 245, 35);
	//Rectangle(getMemDC(), shopItem[0].left, shopItem[0].top, shopItem[0].right, shopItem[0].bottom);
	
	myItem[0] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 124, 200, 35);
	myItem[1] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 166, 200, 35);
	myItem[2] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 208, 200, 35);
	myItem[3] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 250, 200, 35);
	myItem[4] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 292, 200, 35);
	myItem[5] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 334, 200, 35);
	myItem[6] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 376, 200, 35);
	myItem[7] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 418, 200, 35);
	myItem[8] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 460, 200, 35);

	shopEquipTab = RectMake(shopWnd->getX() + 284, shopWnd->getY() + 100, 42, 19);
	shopPortionTab = RectMake(shopWnd->getX() + 327, shopWnd->getY() + 100, 42, 19);
	shopEtcTab = RectMake(shopWnd->getX() + 370, shopWnd->getY() + 100, 42, 19);

	_me->frameRender(getMemDC(), shopWnd->getX() + 280, shopWnd->getY() - 10, _meCount, _me->getFrameY());
	_Azoomma->frameRender(getMemDC(), shopWnd->getX() + 30, shopWnd->getY() + 10, _AzoommaCount, _Azoomma->getFrameY());
	
	buttonQuit = RectMake(shopWnd->getX() + 203, shopWnd->getY() + 54, 64, 16);
	buttonBuy = RectMake(shopWnd->getX() + 203, shopWnd->getY() + 74, 64, 16);
	buttonSell = RectMake(shopWnd->getX() + 433, shopWnd->getY() + 74, 64, 16);

	//������� �������
	if (onShopEquipTab)
	{
		shopEquip->render(getMemDC(), shopEquipTab.left, shopEquipTab.top);
	}

	//�Һ����� �������
	if (onShopPortionTab)
	{
		shopPortion->render(getMemDC(), shopPortionTab.left, shopPortionTab.top);
	}

	//��Ÿ���� �������
	if (onShopEtcTab)
	{
		shopEtc->render(getMemDC(), shopEtcTab.left, shopEtcTab.top);
	}

	//���������� ��ư�� ���콺�� �÷������
	if (PtInRect(&buttonQuit, ptMouse))
	{
		shopQuit->render(getMemDC(), buttonQuit.left, buttonQuit.top);
	}
	//���������
	if (PtInRect(&buttonQuit, ptMouse) && onClickQuit)
	{
		shopQuitPushed->render(getMemDC(), buttonQuit.left, buttonQuit.top);
	}

	//�����ۻ�� ��ư�� ���콺�� �÷��� ���
	if (PtInRect(&buttonBuy, ptMouse))
	{
		shopBuy->render(getMemDC(), buttonBuy.left, buttonBuy.top);
	}
	//���������
	if (PtInRect(&buttonBuy, ptMouse) && onClickBuy)
	{
		shopBuyPushed->render(getMemDC(), buttonBuy.left, buttonBuy.top);
	}

	//�������ȱ� ��ư�� ���콺�� �÷��� ���
	if (PtInRect(&buttonSell, ptMouse))
	{
		shopSell->render(getMemDC(), buttonSell.left, buttonSell.top);
	}
	//���������
	if (PtInRect(&buttonSell, ptMouse) && onClickSell)
	{
		shopSellPushed->render(getMemDC(), buttonSell.left, buttonSell.top);
	}

	//�� ���Ÿ�� Ŭ��ó��
	switch (shopListClick)
	{
	case 0:
		selectEffect2->render(getMemDC(), shopItem[0].left + 36, shopItem[0].top);
		break;
	case 1:
		selectEffect2->render(getMemDC(), shopItem[1].left + 36, shopItem[1].top);
		break;
	case 2:
		selectEffect2->render(getMemDC(), shopItem[2].left + 36, shopItem[2].top);
		break;
	case 3:
		selectEffect2->render(getMemDC(), shopItem[3].left + 36, shopItem[3].top);
		break;
	case 4:
		selectEffect2->render(getMemDC(), shopItem[4].left + 36, shopItem[4].top);
		break;
	case 5:
		selectEffect2->render(getMemDC(), shopItem[5].left + 36, shopItem[5].top);
		break;
	case 6:
		selectEffect2->render(getMemDC(), shopItem[6].left + 36, shopItem[6].top);
		break;
	case 7:
		selectEffect2->render(getMemDC(), shopItem[7].left + 36, shopItem[7].top);
		break;
	case 8:
		selectEffect2->render(getMemDC(), shopItem[8].left + 36, shopItem[8].top);
		break;
	default:
		break;

	}

	switch (myList)
	{
	case 0:
		selectEffect->render(getMemDC(), myItem[0].left + 36, myItem[0].top);
		break;
	case 1:
		selectEffect->render(getMemDC(), myItem[1].left + 36, myItem[1].top);
		break;
	case 2:
		selectEffect->render(getMemDC(), myItem[2].left + 36, myItem[2].top);
		break;
	case 3:
		selectEffect->render(getMemDC(), myItem[3].left + 36, myItem[3].top);
		break;
	case 4:
		selectEffect->render(getMemDC(), myItem[4].left + 36, myItem[4].top);
		break;
	case 5:
		selectEffect->render(getMemDC(), myItem[5].left + 36, myItem[5].top);
		break;
	case 6:
		selectEffect->render(getMemDC(), myItem[6].left + 36, myItem[6].top);
		break;
	case 7:
		selectEffect->render(getMemDC(), myItem[7].left + 36, myItem[7].top);
		break;
	case 8:
		selectEffect->render(getMemDC(), myItem[8].left + 36, myItem[8].top);
		break;
	default:
		break;

	}

	//���� �ǸŸ�Ͽ� �⺻������ ǥ�õǾ��ִ� �޼Ҿ�����
	for (int i = 0; i < 9; i++)
	{
		mesoIcon->render(getMemDC(), shopItem[i].left + 40, shopItem[i].top + 21);
	}

	//-------------------����â �ؽ�Ʈ ������ ���!!!!-------------



	//��������� ���� ��Ʈ����
	HFONT font1, oldFont;

	font1 = CreateFont(13, 0, 0, 0, 100, false, 0, false, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("����ü"));
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	SetBkMode(getMemDC(), TRANSPARENT);
	oldFont = (HFONT)SelectObject(getMemDC(), font1);

	//ĳ���Ͱ� �����ϰ��ִ� �޼� ǥ��

	char tempMeso[255];
	sprintf(tempMeso, "%d", pl->getmeso());
	RECT rcTextArea = RectMake(shopWnd->getX() + 413, shopWnd->getY() + 54, 83, 15);
	DrawText(getMemDC(), tempMeso, -1, &rcTextArea, DT_RIGHT);

	//-------------------�����Ǹž����� �̹��� �� ���� ���-------------


	Sellings->_item.at(0).itemimg->render(getMemDC(), shopItem[0].left + 2, shopItem[0].top + 2);
	char temp[255];
	sprintf(temp, "%d �޼�", Sellings->_item.at(0)._price);
	TextOut(getMemDC(), shopItem[0].left + 55, shopItem[0].top + 21, temp, strlen(temp));
	char temp10[255];
	sprintf(temp10, "%s", Sellings->_item.at(0).itemname);
	TextOut(getMemDC(), shopItem[0].left + 40, shopItem[0].top + 2, temp10, strlen(temp10));



	Sellings->_item.at(4).itemimg->render(getMemDC(), shopItem[1].left + 2, shopItem[1].top + 2);
	char temp2[255];
	sprintf(temp2, "%d �޼�", Sellings->_item.at(4)._price);
	TextOut(getMemDC(), shopItem[1].left + 55, shopItem[1].top + 21, temp2, strlen(temp2));
	char temp11[255];
	sprintf(temp11, "%s", Sellings->_item.at(4).itemname);
	TextOut(getMemDC(), shopItem[1].left + 40, shopItem[1].top + 2, temp11, strlen(temp11));



	Sellings->_item.at(7).itemimg->render(getMemDC(), shopItem[2].left + 2, shopItem[2].top + 2);
	char temp3[255];
	sprintf(temp3, "%d �޼�", Sellings->_item.at(7)._price);
	TextOut(getMemDC(), shopItem[2].left + 55, shopItem[2].top + 21, temp3, strlen(temp3));
	char temp12[255];
	sprintf(temp12, "%s", Sellings->_item.at(7).itemname);
	TextOut(getMemDC(), shopItem[2].left + 40, shopItem[2].top + 2, temp12, strlen(temp12));



	Sellings->_item.at(9).itemimg->render(getMemDC(), shopItem[3].left + 2, shopItem[3].top + 2);
	char temp4[255];
	sprintf(temp4, "%d �޼�", Sellings->_item.at(9)._price);
	TextOut(getMemDC(), shopItem[3].left + 55, shopItem[3].top + 21, temp4, strlen(temp4));
	char temp13[255];
	sprintf(temp13, "%s", Sellings->_item.at(9).itemname);
	TextOut(getMemDC(), shopItem[3].left + 40, shopItem[3].top + 2, temp13, strlen(temp13));



	Sellings->_item.at(13).itemimg->render(getMemDC(), shopItem[4].left + 2, shopItem[4].top + 2);
	char temp5[255];
	sprintf(temp5, "%d �޼�", Sellings->_item.at(13)._price);
	TextOut(getMemDC(), shopItem[4].left + 55, shopItem[4].top + 21, temp5, strlen(temp5));
	char temp14[255];
	sprintf(temp14, "%s", Sellings->_item.at(13).itemname);
	TextOut(getMemDC(), shopItem[4].left + 40, shopItem[4].top + 2, temp14, strlen(temp14));



	Sellings->_item.at(15).itemimg->render(getMemDC(), shopItem[5].left + 2, shopItem[5].top + 2);
	char temp6[255];
	sprintf(temp6, "%d �޼�", Sellings->_item.at(15)._price);
	TextOut(getMemDC(), shopItem[5].left + 55, shopItem[5].top + 21, temp6, strlen(temp6));
	char temp15[255];
	sprintf(temp15, "%s", Sellings->_item.at(15).itemname);
	TextOut(getMemDC(), shopItem[5].left + 40, shopItem[5].top + 2, temp15, strlen(temp15));



	Sellings->_item.at(19).itemimg->render(getMemDC(), shopItem[6].left + 2, shopItem[6].top + 2);
	char temp7[255];
	sprintf(temp7, "%d �޼�", Sellings->_item.at(19)._price);
	TextOut(getMemDC(), shopItem[6].left + 55, shopItem[6].top + 21, temp7, strlen(temp7));
	char temp16[255];
	sprintf(temp16, "%s", Sellings->_item.at(19).itemname);
	TextOut(getMemDC(), shopItem[6].left + 40, shopItem[6].top + 2, temp16, strlen(temp16));



	Sellings->_item.at(21).itemimg->render(getMemDC(), shopItem[7].left + 2, shopItem[7].top + 2);
	char temp8[255];
	sprintf(temp8, "%d �޼�", Sellings->_item.at(21)._price);
	TextOut(getMemDC(), shopItem[7].left + 55, shopItem[7].top + 21, temp8, strlen(temp8));
	char temp17[255];
	sprintf(temp17, "%s", Sellings->_item.at(21).itemname);
	TextOut(getMemDC(), shopItem[7].left + 40, shopItem[7].top + 2, temp17, strlen(temp17));



	Sellings->_item.at(26).itemimg->render(getMemDC(), shopItem[8].left + 2, shopItem[8].top + 2);
	char temp9[255];
	sprintf(temp9, "%d �޼�", Sellings->_item.at(26)._price);
	TextOut(getMemDC(), shopItem[8].left + 55, shopItem[8].top + 21, temp9, strlen(temp9));
	char temp18[255];
	sprintf(temp18, "%s", Sellings->_item.at(26).itemname);
	TextOut(getMemDC(), shopItem[8].left + 40, shopItem[8].top + 2, temp18, strlen(temp18));

	//-------------------------�� ������ �Ǹ� ��ϵ�-------------------------------
	if (onShopEquipTab)
	{
		if (pl->getEquip().size() > 0)
		{
			Mines->_item.at(pl->getEquip().at(0).number).itemimg->render(getMemDC(), myItem[0].left + 2, myItem[0].top + 2);
			char tt[255];
			sprintf(tt, "%d �޼�", Mines->_item.at(pl->getEquip().at(0).number)._price);
			TextOut(getMemDC(), myItem[0].left + 40, myItem[0].top + 21, tt, strlen(tt));
			char tt2[255];
			sprintf(tt2, "%s", Mines->_item.at(pl->getEquip().at(0).number).itemname);
			TextOut(getMemDC(), myItem[0].left + 40, myItem[0].top + 2, tt2, strlen(tt2));
		}


		if (pl->getEquip().size() > 1)
		{
			Mines->_item.at(pl->getEquip().at(1).number).itemimg->render(getMemDC(), myItem[1].left + 2, myItem[1].top + 2);
			char tt3[255];
			sprintf(tt3, "%d �޼�", Mines->_item.at(pl->getEquip().at(1).number)._price);
			TextOut(getMemDC(), myItem[1].left + 40, myItem[1].top + 21, tt3, strlen(tt3));
			char tt4[255];
			sprintf(tt4, "%s", Mines->_item.at(pl->getEquip().at(1).number).itemname);
			TextOut(getMemDC(), myItem[1].left + 40, myItem[1].top + 2, tt4, strlen(tt4));
		}


		if (pl->getEquip().size() > 2)
		{
			Mines->_item.at(pl->getEquip().at(2).number).itemimg->render(getMemDC(), myItem[2].left + 2, myItem[2].top + 2);
			char tt5[255];
			sprintf(tt5, "%d �޼�", Mines->_item.at(pl->getEquip().at(2).number)._price);
			TextOut(getMemDC(), myItem[2].left + 40, myItem[2].top + 21, tt5, strlen(tt5));
			char tt6[255];
			sprintf(tt6, "%s", Mines->_item.at(pl->getEquip().at(2).number).itemname);
			TextOut(getMemDC(), myItem[2].left + 40, myItem[2].top + 2, tt6, strlen(tt6));
		}

		if (pl->getEquip().size() > 3)
		{
			Mines->_item.at(pl->getEquip().at(3).number).itemimg->render(getMemDC(), myItem[3].left + 2, myItem[3].top + 2);
			char tt7[255];
			sprintf(tt7, "%d �޼�", Mines->_item.at(pl->getEquip().at(3).number)._price);
			TextOut(getMemDC(), myItem[3].left + 40, myItem[3].top + 21, tt7, strlen(tt7));
			char tt8[255];
			sprintf(tt8, "%s", Mines->_item.at(pl->getEquip().at(3).number).itemname);
			TextOut(getMemDC(), myItem[3].left + 40, myItem[3].top + 2, tt8, strlen(tt8));
		}

		if (pl->getEquip().size() > 4)
		{
			Mines->_item.at(pl->getEquip().at(4).number).itemimg->render(getMemDC(), myItem[4].left + 2, myItem[4].top + 2);
			char tt9[255];
			sprintf(tt9, "%d �޼�", Mines->_item.at(pl->getEquip().at(4).number)._price);
			TextOut(getMemDC(), myItem[4].left + 40, myItem[4].top + 21, tt9, strlen(tt9));
			char tt10[255];
			sprintf(tt10, "%s", Mines->_item.at(pl->getEquip().at(4).number).itemname);
			TextOut(getMemDC(), myItem[4].left + 40, myItem[4].top + 2, tt10, strlen(tt10));
		}

		if (pl->getEquip().size() > 5)
		{
			Mines->_item.at(pl->getEquip().at(5).number).itemimg->render(getMemDC(), myItem[5].left + 2, myItem[5].top + 2);
			char tt11[255];
			sprintf(tt11, "%d �޼�", Mines->_item.at(pl->getEquip().at(5).number)._price);
			TextOut(getMemDC(), myItem[5].left + 40, myItem[5].top + 21, tt11, strlen(tt11));
			char tt12[255];
			sprintf(tt12, "%s", Mines->_item.at(pl->getEquip().at(5).number).itemname);
			TextOut(getMemDC(), myItem[5].left + 40, myItem[5].top + 2, tt12, strlen(tt12));
		}

		if (pl->getEquip().size() > 6)
		{
			Mines->_item.at(pl->getEquip().at(6).number).itemimg->render(getMemDC(), myItem[6].left + 2, myItem[6].top + 2);
			char tt13[255];
			sprintf(tt13, "%d �޼�", Mines->_item.at(pl->getEquip().at(6).number)._price);
			TextOut(getMemDC(), myItem[6].left + 40, myItem[6].top + 21, tt13, strlen(tt13));
			char tt14[255];
			sprintf(tt14, "%s", Mines->_item.at(pl->getEquip().at(6).number).itemname);
			TextOut(getMemDC(), myItem[6].left + 40, myItem[6].top + 2, tt14, strlen(tt14));
		}

		if (pl->getEquip().size() > 7)
		{
			Mines->_item.at(pl->getEquip().at(7).number).itemimg->render(getMemDC(), myItem[7].left + 2, myItem[7].top + 2);
			char tt15[255];
			sprintf(tt15, "%d �޼�", Mines->_item.at(pl->getEquip().at(7).number)._price);
			TextOut(getMemDC(), myItem[7].left + 40, myItem[7].top + 21, tt15, strlen(tt15));
			char tt16[255];
			sprintf(tt16, "%s", Mines->_item.at(pl->getEquip().at(7).number).itemname);
			TextOut(getMemDC(), myItem[7].left + 40, myItem[7].top + 2, tt16, strlen(tt16));
		}

		if (pl->getEquip().size() > 8)
		{
			Mines->_item.at(pl->getEquip().at(8).number).itemimg->render(getMemDC(), myItem[8].left + 2, myItem[8].top + 2);
			char tt17[255];
			sprintf(tt17, "%d �޼�", Mines->_item.at(pl->getEquip().at(8).number)._price);
			TextOut(getMemDC(), myItem[8].left + 40, myItem[8].top + 21, tt17, strlen(tt17));
			char tt18[255];
			sprintf(tt18, "%s", Mines->_item.at(pl->getEquip().at(8).number).itemname);
			TextOut(getMemDC(), myItem[8].left + 40, myItem[8].top + 2, tt18, strlen(tt18));
		}
	}

	//�Һ����ϰ��
	else if (onShopPortionTab)
	{
		if (pl->getConsume().size() > 0)
		{
			Mines->_item.at(pl->getConsume().at(0).number).itemimg->render(getMemDC(), myItem[0].left + 2, myItem[0].top + 2);
			char tt[255];
			sprintf(tt, "%d �޼�", Mines->_item.at(pl->getConsume().at(0).number)._price);
			TextOut(getMemDC(), myItem[0].left + 40, myItem[0].top + 21, tt, strlen(tt));
			char tt2[255];
			sprintf(tt2, "%s", Mines->_item.at(pl->getConsume().at(0).number).itemname);
			TextOut(getMemDC(), myItem[0].left + 40, myItem[0].top + 2, tt2, strlen(tt2));
			char st[255];
			sprintf(tt2, "%s", Mines->_item.at(pl->getConsume().at(0).number).itemname);
			TextOut(getMemDC(), myItem[0].left + 40, myItem[0].top + 2, tt2, strlen(tt2));
		}


		if (pl->getConsume().size() > 1)
		{
			Mines->_item.at(pl->getConsume().at(1).number).itemimg->render(getMemDC(), myItem[1].left + 2, myItem[1].top + 2);
			char tt3[255];
			sprintf(tt3, "%d �޼�", Mines->_item.at(pl->getConsume().at(1).number)._price);
			TextOut(getMemDC(), myItem[1].left + 40, myItem[1].top + 21, tt3, strlen(tt3));
			char tt4[255];
			sprintf(tt4, "%s", Mines->_item.at(pl->getConsume().at(1).number).itemname);
			TextOut(getMemDC(), myItem[1].left + 40, myItem[1].top + 2, tt4, strlen(tt4));
		}


		if (pl->getConsume().size() > 2)
		{
			Mines->_item.at(pl->getConsume().at(2).number).itemimg->render(getMemDC(), myItem[2].left + 2, myItem[2].top + 2);
			char tt5[255];
			sprintf(tt5, "%d �޼�", Mines->_item.at(pl->getConsume().at(2).number)._price);
			TextOut(getMemDC(), myItem[2].left + 40, myItem[2].top + 21, tt5, strlen(tt5));
			char tt6[255];
			sprintf(tt6, "%s", Mines->_item.at(pl->getConsume().at(2).number).itemname);
			TextOut(getMemDC(), myItem[2].left + 40, myItem[2].top + 2, tt6, strlen(tt6));
		}

		if (pl->getConsume().size() > 3)
		{
			Mines->_item.at(pl->getConsume().at(3).number).itemimg->render(getMemDC(), myItem[3].left + 2, myItem[3].top + 2);
			char tt7[255];
			sprintf(tt7, "%d �޼�", Mines->_item.at(pl->getConsume().at(3).number)._price);
			TextOut(getMemDC(), myItem[3].left + 40, myItem[3].top + 21, tt7, strlen(tt7));
			char tt8[255];
			sprintf(tt8, "%s", Mines->_item.at(pl->getConsume().at(3).number).itemname);
			TextOut(getMemDC(), myItem[3].left + 40, myItem[3].top + 2, tt8, strlen(tt8));
		}

		if (pl->getConsume().size() > 4)
		{
			Mines->_item.at(pl->getConsume().at(4).number).itemimg->render(getMemDC(), myItem[4].left + 2, myItem[4].top + 2);
			char tt9[255];
			sprintf(tt9, "%d �޼�", Mines->_item.at(pl->getConsume().at(4).number)._price);
			TextOut(getMemDC(), myItem[4].left + 40, myItem[4].top + 21, tt9, strlen(tt9));
			char tt10[255];
			sprintf(tt10, "%s", Mines->_item.at(pl->getConsume().at(4).number).itemname);
			TextOut(getMemDC(), myItem[4].left + 40, myItem[4].top + 2, tt10, strlen(tt10));
		}

		if (pl->getConsume().size() > 5)
		{
			Mines->_item.at(pl->getConsume().at(5).number).itemimg->render(getMemDC(), myItem[5].left + 2, myItem[5].top + 2);
			char tt11[255];
			sprintf(tt11, "%d �޼�", Mines->_item.at(pl->getConsume().at(5).number)._price);
			TextOut(getMemDC(), myItem[5].left + 40, myItem[5].top + 21, tt11, strlen(tt11));
			char tt12[255];
			sprintf(tt12, "%s", Mines->_item.at(pl->getConsume().at(5).number).itemname);
			TextOut(getMemDC(), myItem[5].left + 40, myItem[5].top + 2, tt12, strlen(tt12));
		}

		if (pl->getConsume().size() > 6)
		{
			Mines->_item.at(pl->getConsume().at(6).number).itemimg->render(getMemDC(), myItem[6].left + 2, myItem[6].top + 2);
			char tt13[255];
			sprintf(tt13, "%d �޼�", Mines->_item.at(pl->getConsume().at(6).number)._price);
			TextOut(getMemDC(), myItem[6].left + 40, myItem[6].top + 21, tt13, strlen(tt13));
			char tt14[255];
			sprintf(tt14, "%s", Mines->_item.at(pl->getConsume().at(6).number).itemname);
			TextOut(getMemDC(), myItem[6].left + 40, myItem[6].top + 2, tt14, strlen(tt14));
		}

		if (pl->getConsume().size() > 7)
		{
			Mines->_item.at(pl->getConsume().at(7).number).itemimg->render(getMemDC(), myItem[7].left + 2, myItem[7].top + 2);
			char tt15[255];
			sprintf(tt15, "%d �޼�", Mines->_item.at(pl->getConsume().at(7).number)._price);
			TextOut(getMemDC(), myItem[7].left + 40, myItem[7].top + 21, tt15, strlen(tt15));
			char tt16[255];
			sprintf(tt16, "%s", Mines->_item.at(pl->getConsume().at(7).number).itemname);
			TextOut(getMemDC(), myItem[7].left + 40, myItem[7].top + 2, tt16, strlen(tt16));
		}

		if (pl->getConsume().size() > 8)
		{
			Mines->_item.at(pl->getConsume().at(8).number).itemimg->render(getMemDC(), myItem[8].left + 2, myItem[8].top + 2);
			char tt17[255];
			sprintf(tt17, "%d �޼�", Mines->_item.at(pl->getConsume().at(8).number)._price);
			TextOut(getMemDC(), myItem[8].left + 40, myItem[8].top + 21, tt17, strlen(tt17));
			char tt18[255];
			sprintf(tt18, "%s", Mines->_item.at(pl->getConsume().at(8).number).itemname);
			TextOut(getMemDC(), myItem[8].left + 40, myItem[8].top + 2, tt18, strlen(tt18));
		}
	}
	//�ٽ����� ��������!!!
	DeleteObject(oldFont);
	DeleteObject(font1);

	//���� �ǸŸ���Ʈ ������ �ٲ� �����ϱ� ���⿡ ���̷�Ʈ�� ������������ �̵��� �Ѵ�.
	switch (shopList)
	{
	case 0:
		//��������
		showItemInfo(0);
		break;
	case 1:
		//�Ķ�����
		showItemInfo(4);
		break;
	case 2:
		//Ǫ������
		showItemInfo(7);
		break;
	case 3:
		//���� ������
		showItemInfo(9);
		break;
	case 4:
		//���� ������
		showItemInfo(13);
		break;
	case 5:
		//õ����
		showItemInfo(15);
		break;
	case 6:
		//����Ʈ
		showItemInfo(19);
		break;
	case 7:
		//������
		showItemInfo(21);
		break;
	case 8:
		//�����尩
		showItemInfo(26);
		break;
	default:
		break;

	}
}

void UserInterface::showItemInfo(int index)
{
	//����â�� ������ ������ �Ѿ���� ���� ����â�� ���. y�� ��ü������ -301
	if (ptMouse.y > WINSIZEY - 300)
	{
		Sellings->iteminfo->alphaRender(getMemDC(), ptMouse.x, ptMouse.y - 301, 150);

		Sellings->_item.at(index).itemimg->render(getMemDC(), ptMouse.x + 38, ptMouse.y + 98 - 301);
		int i = 0;
		char temp[255];
		sprintf(temp, "%s", Sellings->_item.at(index).itemname);
		SetBkMode(getMemDC(), TRANSPARENT); //�̰� ����� ������ ���ش�.
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), ptMouse.x + 80, ptMouse.y + 40 - 301, temp, strlen(temp));
		char temp2[255];
		sprintf(temp2, "REQ LEV : %d", Sellings->_item.at(index).reqLev);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 75 - 301, temp2, strlen(temp2));
		char temp3[255];
		sprintf(temp3, "REQ STR : %d", Sellings->_item.at(index).reqStr);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 90 - 301, temp3, strlen(temp3));
		char temp4[255];
		sprintf(temp4, "REQ DEX : %d", Sellings->_item.at(index).reqDex);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 105 - 301, temp4, strlen(temp4));
		char temp5[255];
		sprintf(temp5, "REQ INT : %d", Sellings->_item.at(index).reqInt);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 120 - 301, temp5, strlen(temp5));
		char temp6[255];
		sprintf(temp6, "REQ LUK : %d", Sellings->_item.at(index).reqLuk);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 135 - 301, temp6, strlen(temp6));

		char temp7[255];
		if (Sellings->_item.at(index).itemtype == 1)
			sprintf(temp7, "��Ÿ������");
		else if (Sellings->_item.at(index).itemtype == 2)
			sprintf(temp7, "�Һ������");
		else if (Sellings->_item.at(index).itemtype == 3)
			sprintf(temp7, "���з� : ����");
		else if (Sellings->_item.at(index).itemtype == 4)
			sprintf(temp7, "���з� : ����");
		else if (Sellings->_item.at(index).itemtype == 5)
			sprintf(temp7, "���з� : �Ͱ�");
		else if (Sellings->_item.at(index).itemtype == 6)
			sprintf(temp7, "���з� : ����");
		else if (Sellings->_item.at(index).itemtype == 7)
			sprintf(temp7, "���з� : ����");
		else if (Sellings->_item.at(index).itemtype == 8)
			sprintf(temp7, "���з� : �尩");
		else if (Sellings->_item.at(index).itemtype == 9)
			sprintf(temp7, "���з� : �Ź�");
		else if (Sellings->_item.at(index).itemtype == 10)
			sprintf(temp7, "���з� : ����");

		TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 160 - 301, temp7, strlen(temp7));
		if (Sellings->_item.at(index).hp > 0)
		{
			char temp8[255];
			sprintf(temp8, "HP : + %d", Sellings->_item.at(index).hp);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp8, strlen(temp8));
			i++;
		}

		if (Sellings->_item.at(index).mp > 0)
		{
			char temp9[255];
			sprintf(temp9, "MP : + %d", Sellings->_item.at(index).mp);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp9, strlen(temp9));
			i++;
		}

		if (Sellings->_item.at(index).str > 0)
		{
			char temp10[255];
			sprintf(temp10, "STR : + %d", Sellings->_item.at(index).str);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp10, strlen(temp10));
			i++;
		}

		if (Sellings->_item.at(index).dex > 0)
		{
			char temp11[255];
			sprintf(temp11, "DEX : + %d", Sellings->_item.at(index).dex);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp11, strlen(temp11));
			i++;
		}

		if (Sellings->_item.at(index).inteligence > 0)
		{
			char temp12[255];
			sprintf(temp12, "INT : + %d", Sellings->_item.at(index).inteligence);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp12, strlen(temp12));
			i++;
		}

		if (Sellings->_item.at(index).luk > 0)
		{
			char temp13[255];
			sprintf(temp13, "LUK : + %d", Sellings->_item.at(index).luk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp13, strlen(temp13));
			i++;
		}

		if (Sellings->_item.at(index).phyatk > 0)
		{
			char temp14[255];
			sprintf(temp14, "�������ݷ� : + %d", Sellings->_item.at(index).phyatk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp14, strlen(temp14));
			i++;
		}

		if (Sellings->_item.at(index).phyarm > 0)
		{
			char temp15[255];
			sprintf(temp15, "�������� : + %d", Sellings->_item.at(index).phyarm);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp15, strlen(temp15));
			i++;
		}

		if (Sellings->_item.at(index).magatk > 0)
		{
			char temp16[255];
			sprintf(temp16, "�������ݷ� : + %d", Sellings->_item.at(index).magatk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp16, strlen(temp16));
			i++;
		}

		if (Sellings->_item.at(index).magarm > 0)
		{
			char temp17[255];
			sprintf(temp17, "�������� : + %d", Sellings->_item.at(index).magarm);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp17, strlen(temp17));
			i++;
		}

		if (Sellings->_item.at(index).hitrate > 0)
		{
			char temp18[255];
			sprintf(temp18, "���߷� : + %d", Sellings->_item.at(index).hitrate);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp18, strlen(temp18));
			i++;
		}

		if (Sellings->_item.at(index).avoidrate > 0)
		{
			char temp19[255];
			sprintf(temp19, "ȸ���� : + %d", Sellings->_item.at(index).avoidrate);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp19, strlen(temp19));
			i++;
		}

		/*

		<���� ���!!!>

		- RECT rcTextArea = {200, 200, 300, 300};
		-> RECT�� ���� ���� ����

		- DrawText(hdc, szTemp, strlen(szTemp), &rcTextArea, DT_SINGLELINE | DT_VCENTER);
		-> (�ڵ�, ���ڿ�, ���ڿ��� ����, ����ũ��, ��ο��ؽ�Ʈ_��½�Ÿ��);
		-> �ش� �����ȿ� ���ڸ� ��Ÿ�Ͽ� ���� ������ش�. or(|)�������� �ߺ��� ��Ÿ���� �� �� �ִ�.

		// ���� ���� ��Ÿ��//
		DT_LEFT		��������
		DT_CENTER	�߾� ����
		DT_WORDBREAK	���� �Ѿ�� �ܾ� ������ �ٹٲ�
		DT_SINGLELINE	���� ���. ���� �Ѿ�� ©����.
		DT_NOCLIP	�������� ���
		DT_VCENTER	���� ���߾ӿ� �����. (DT_SINGLELINE�� ���� ��ߵȴ�.)


		*/

		char temp20[255];
		sprintf(temp20, "%s", Sellings->_item.at(index).script);
		RECT rcTextArea = { ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301 ,ptMouse.x + 230,  ptMouse.y + 175 + i * 15 + 45 - 301 };
		DrawText(getMemDC(), temp20, -1, &rcTextArea, DT_LEFT | DT_WORDBREAK);
		//���ڿ� ���̺κп� -1 => �ڵ����� ���.
		i += 3; //���ڻ��ڶ����� ������ �Ҵ��ϴ� �ٶ��� ���⼭�� +3!!


				//���׷��̵� ����Ƚ���� ���������� ��쿡�� ����Ѵ�.
		if (!(Sellings->_item.at(index).itemtype == 0) && !(Sellings->_item.at(index).itemtype == 1) && !(Sellings->_item.at(index).itemtype == 2))
		{
			char temp21[255];
			sprintf(temp21, "���׷��̵� ����Ƚ�� : %dȸ", Sellings->_item.at(index).upgrade);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp21, strlen(temp21));
		}
	}
	else
	{
		Sellings->iteminfo->alphaRender(getMemDC(), ptMouse.x, ptMouse.y, 150);

		Sellings->_item.at(index).itemimg->render(getMemDC(), ptMouse.x + 38, ptMouse.y + 98);
		int i = 0;
		char temp[255];
		sprintf(temp, "%s", Sellings->_item.at(index).itemname);
		SetBkMode(getMemDC(), TRANSPARENT); //�̰� ����� ������ ���ش�.
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), ptMouse.x + 80, ptMouse.y + 40, temp, strlen(temp));
		char temp2[255];
		sprintf(temp2, "REQ LEV : %d", Sellings->_item.at(index).reqLev);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 75, temp2, strlen(temp2));
		char temp3[255];
		sprintf(temp3, "REQ STR : %d", Sellings->_item.at(index).reqStr);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 90, temp3, strlen(temp3));
		char temp4[255];
		sprintf(temp4, "REQ DEX : %d", Sellings->_item.at(index).reqDex);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 105, temp4, strlen(temp4));
		char temp5[255];
		sprintf(temp5, "REQ INT : %d", Sellings->_item.at(index).reqInt);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 120, temp5, strlen(temp5));
		char temp6[255];
		sprintf(temp6, "REQ LUK : %d", Sellings->_item.at(index).reqLuk);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 135, temp6, strlen(temp6));

		char temp7[255];
		if (Sellings->_item.at(index).itemtype == 1)
			sprintf(temp7, "��Ÿ������");
		else if (Sellings->_item.at(index).itemtype == 2)
			sprintf(temp7, "�Һ������");
		else if (Sellings->_item.at(index).itemtype == 3)
			sprintf(temp7, "���з� : ����");
		else if (Sellings->_item.at(index).itemtype == 4)
			sprintf(temp7, "���з� : ����");
		else if (Sellings->_item.at(index).itemtype == 5)
			sprintf(temp7, "���з� : �Ͱ�");
		else if (Sellings->_item.at(index).itemtype == 6)
			sprintf(temp7, "���з� : ����");
		else if (Sellings->_item.at(index).itemtype == 7)
			sprintf(temp7, "���з� : ����");
		else if (Sellings->_item.at(index).itemtype == 8)
			sprintf(temp7, "���з� : �尩");
		else if (Sellings->_item.at(index).itemtype == 9)
			sprintf(temp7, "���з� : �Ź�");
		else if (Sellings->_item.at(index).itemtype == 10)
			sprintf(temp7, "���з� : ����");

		TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 160, temp7, strlen(temp7));
		if (Sellings->_item.at(index).hp > 0)
		{
			char temp8[255];
			sprintf(temp8, "HP : + %d", Sellings->_item.at(index).hp);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp8, strlen(temp8));
			i++;
		}

		if (Sellings->_item.at(index).mp > 0)
		{
			char temp9[255];
			sprintf(temp9, "MP : + %d", Sellings->_item.at(index).mp);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp9, strlen(temp9));
			i++;
		}

		if (Sellings->_item.at(index).str > 0)
		{
			char temp10[255];
			sprintf(temp10, "STR : + %d", Sellings->_item.at(index).str);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp10, strlen(temp10));
			i++;
		}

		if (Sellings->_item.at(index).dex > 0)
		{
			char temp11[255];
			sprintf(temp11, "DEX : + %d", Sellings->_item.at(index).dex);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp11, strlen(temp11));
			i++;
		}

		if (Sellings->_item.at(index).inteligence > 0)
		{
			char temp12[255];
			sprintf(temp12, "INT : + %d", Sellings->_item.at(index).inteligence);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp12, strlen(temp12));
			i++;
		}

		if (Sellings->_item.at(index).luk > 0)
		{
			char temp13[255];
			sprintf(temp13, "LUK : + %d", Sellings->_item.at(index).luk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp13, strlen(temp13));
			i++;
		}

		if (Sellings->_item.at(index).phyatk > 0)
		{
			char temp14[255];
			sprintf(temp14, "�������ݷ� : + %d", Sellings->_item.at(index).phyatk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp14, strlen(temp14));
			i++;
		}

		if (Sellings->_item.at(index).phyarm > 0)
		{
			char temp15[255];
			sprintf(temp15, "�������� : + %d", Sellings->_item.at(index).phyarm);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp15, strlen(temp15));
			i++;
		}

		if (Sellings->_item.at(index).magatk > 0)
		{
			char temp16[255];
			sprintf(temp16, "�������ݷ� : + %d", Sellings->_item.at(index).magatk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp16, strlen(temp16));
			i++;
		}

		if (Sellings->_item.at(index).magarm > 0)
		{
			char temp17[255];
			sprintf(temp17, "�������� : + %d", Sellings->_item.at(index).magarm);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp17, strlen(temp17));
			i++;
		}

		if (Sellings->_item.at(index).hitrate > 0)
		{
			char temp18[255];
			sprintf(temp18, "���߷� : + %d", Sellings->_item.at(index).hitrate);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp18, strlen(temp18));
			i++;
		}

		if (Sellings->_item.at(index).avoidrate > 0)
		{
			char temp19[255];
			sprintf(temp19, "ȸ���� : + %d", Sellings->_item.at(index).avoidrate);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp19, strlen(temp19));
			i++;
		}

		/*

		<���� ���!!!>

		- RECT rcTextArea = {200, 200, 300, 300};
		   -> RECT�� ���� ���� ����

		 - DrawText(hdc, szTemp, strlen(szTemp), &rcTextArea, DT_SINGLELINE | DT_VCENTER);
			-> (�ڵ�, ���ڿ�, ���ڿ��� ����, ����ũ��, ��ο��ؽ�Ʈ_��½�Ÿ��);
			-> �ش� �����ȿ� ���ڸ� ��Ÿ�Ͽ� ���� ������ش�. or(|)�������� �ߺ��� ��Ÿ���� �� �� �ִ�.

		// ���� ���� ��Ÿ��//
		DT_LEFT		��������
		DT_CENTER	�߾� ����
		DT_WORDBREAK	���� �Ѿ�� �ܾ� ������ �ٹٲ�
		DT_SINGLELINE	���� ���. ���� �Ѿ�� ©����.
		DT_NOCLIP	�������� ���
		DT_VCENTER	���� ���߾ӿ� �����. (DT_SINGLELINE�� ���� ��ߵȴ�.)


		*/

		char temp20[255];
		sprintf(temp20, "%s", Sellings->_item.at(index).script);
		RECT rcTextArea = { ptMouse.x + 10, ptMouse.y + 175 + i * 15,ptMouse.x + 230,  ptMouse.y + 175 + i * 15 + 45 };
		DrawText(getMemDC(), temp20, -1, &rcTextArea, DT_LEFT | DT_WORDBREAK);
		//���ڿ� ���̺κп� -1 => �ڵ����� ���.
		i += 3; //���ڻ��ڶ����� ������ �Ҵ��ϴ� �ٶ��� ���⼭�� +3!!


		//���׷��̵� ����Ƚ���� ���������� ��쿡�� ����Ѵ�.
		if (!(Sellings->_item.at(index).itemtype == 0) && !(Sellings->_item.at(index).itemtype == 1) && !(Sellings->_item.at(index).itemtype == 2))
		{
			char temp21[255];
			sprintf(temp21, "���׷��̵� ����Ƚ�� : %dȸ", Sellings->_item.at(index).upgrade);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp21, strlen(temp21));
		}
	}
}

UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}

