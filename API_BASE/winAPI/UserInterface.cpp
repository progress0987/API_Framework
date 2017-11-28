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


	

	return S_OK;
}

void UserInterface::release(void)
{
}

void UserInterface::update(void)
{
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
}

UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
