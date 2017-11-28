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

	//�κ��丮 �۾�
	invenWnd = IMAGEMANAGER->findImage("�κ��丮â");
	equipTab = IMAGEMANAGER->findImage("�����");
	potionTab = IMAGEMANAGER->findImage("�Һ���");
	etcTab = IMAGEMANAGER->findImage("��Ÿ��");
	shadow = IMAGEMANAGER->findImage("�׸���");

	invenWnd->setX(700);
	invenWnd->setY(200);

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
	hpbar->setX(_formBackground->getX());
	hpbar->setY(_formBackground->getY());
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
	//_ap;


	

	return S_OK;
}

void UserInterface::release(void)
{
}

void UserInterface::update(void)
{
		playerHp = pl->getstatus()->curHP;
		playerMp = pl->getstatus()->curMP;
	if (onStat) {
		Level = pl->getstatus()->Level;
		MaxHp = pl->getstatus()->maxHP;
		MaxMp = pl->getstatus()->maxMP;
	}
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
		//���â�� �����ִ°��

		//����â�� �����ִ°��

		//�κ��丮â�� �����ִ°��


	}

	//Ű �۵� Ȯ��.
	//ü������ ó��ó��
	if (KEYMANAGER->isOnceKeyDown(VK_DELETE))
	{
		

	}

	//�������� ó��ó��
	if (KEYMANAGER->isOnceKeyDown(VK_END))
	{

		
	}


	//�ǽð� ĳ���� ���� ���ž�
}

void UserInterface::render(void)
{
	//�ؽ�Ʈ �������� �ʿ��� �⺻������
	SetBkMode(getMemDC(), TRANSPARENT); //�̰� ����� ������ ���ش�.
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	//�⺻�������̽� ������
	//����ġ
	expBackground->render(getMemDC());
	expGuage->render(getMemDC());
	expLayer->render(getMemDC());

	//ĳ�������� �� ü��, ����������
	_formBackground->render(getMemDC());
	hpbar->render(getMemDC());
	mpbar->render(getMemDC());
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


	//����â, ���â, �κ��丮 ������
	if (onStat)
		statement();
	if (onEquip)
		equip();
	if (onInven)
		inventory();

	//���콺 Ŀ�� �����
	SetCursor(NULL);
	ShowCursor(false);

	finger->frameRender(getMemDC(), ptMouse.x, ptMouse.y);
}

void UserInterface::equip(void)
{
	wndEquip = RectMake(equipWnd->getX(), equipWnd->getY(), equipWnd->getWidth(), equipWnd->getHeight());
	equipWnd->render(getMemDC());
}

void UserInterface::inventory(void)
{
	wndInven = RectMake(invenWnd->getX(), invenWnd->getY(), invenWnd->getWidth(), invenWnd->getHeight());
	invenWnd->render(getMemDC());
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
	sprintf(temp9, "%d(%d+%d)", _str, _basicStr, totalEquipstr);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 209, temp9, strlen(temp9));

	char temp10[255];
	sprintf(temp10, "%d(%d+%d)", _dex, _basicDex, totalEquipdex);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 227, temp10, strlen(temp10));

	char temp11[255];
	sprintf(temp11, "%d(%d+%d)", _int, _basicInt, totalEquipint);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 245, temp11, strlen(temp11));

	char temp12[255];
	sprintf(temp12, "%d(%d+%d)", _luk, _basicLuk, totalEquipluk);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 263, temp12, strlen(temp12));

	//�ٽ����� ��������!!!
	DeleteObject(oldFont);
	DeleteObject(font1);
}

UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
