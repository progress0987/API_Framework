#include "stdafx.h"
#include "items.h"


HRESULT items::init(void)
{


	iteminfo = IMAGEMANAGER->findImage("����������â");


	/*-----------------------------������ ǥ�� ���!!!!!-------------------------------*/
	//������ �����Ƿ� �ڵ��Ҷ� �Ʒ����� ������ ������ ���ÿ�.

	/*//������ �̹���.
	image *itemimg;

	//������ �̸�
	char itemname[200];

	//������ ����
	int itemtype;

	//������ ����
	int _price;


	//ü��, ����, ��, ��ø, ����, ���
	int hp, mp, str, dex, inteligence, luk;


	//�������ݷ�, �������, ��������, �������, ���߷�, ȸ�Ƿ�, ���׷��̵尡��.
	int phyatk, phyarm, magatk, magarm, hitrate, avoidrate, upgrade;

	//�ʿ� ����

	int reqLev, reqStr, reqDex, reqInt, reqLuk;

	//-----------�Ʒ��� �Һ������, ���ۿ��� �ش��Ѵ�.(������ ���� ��������)---------------

	//ȸ�������ִ� hp, mp
	int healHp = 0, healMp = 0;

	//����
	char script[500];

	*/


	/*-----------------------------------------------------------------------------*/

	/*������1 ����*/
	t.itemimg = IMAGEMANAGER->findImage("��������");
	strcpy(t.itemname, "��������");
	t.itemtype = potion;
	t._price = 50; //����
	t.healHp = 50;
	strcpy(t.script, "������ �����̴�. hp�� 50ä���ش�.");

	_item.push_back(t);




	/*������2 ����*/
	t.itemimg = IMAGEMANAGER->findImage("��Ȳ����");
	strcpy(t.itemname, "��Ȳ����");
	t.itemtype = potion;
	t._price = 160; //����
	t.healHp = 150;
	strcpy(t.script, "��Ȳ�� �����̴�. hp�� 150ä���ش�.");

	_item.push_back(t);



	/*������3 ����*/
	t.itemimg = IMAGEMANAGER->findImage("�Ͼ�����");
	strcpy(t.itemname, "�Ͼ�����");
	t.itemtype = potion;
	t._price = 320; //����
	t.healHp = 300;
	strcpy(t.script, "�Ͼ�� �����̴�. hp�� 300ä���ش�.");

	_item.push_back(t);


	/*������4 ����*/
	t.itemimg = IMAGEMANAGER->findImage("���޹�");
	strcpy(t.itemname, "���޹�");
	t.itemtype = potion;
	t._price = 2100; //����
	t.healHp = 2000;
	strcpy(t.script, "�ӱ��� �ÿ��� ���޹��̴�. hp�� 2000ä���ش�.");


	_item.push_back(t);

	/*������5 ����*/
	t.itemimg = IMAGEMANAGER->findImage("�Ķ�����");
	strcpy(t.itemname, "�Ķ�����");
	t.itemtype = potion;
	t._price = 200; //����
	t.healMp = 100;
	strcpy(t.script, "�Ķ��� �����̴�. mp�� 100ä���ش�.");


	_item.push_back(t);

	/*������6 ����*/
	t.itemimg = IMAGEMANAGER->findImage("�Ϻ���");
	strcpy(t.itemname, "�Ϻ���");
	t.itemtype = potion;
	t._price = 2500; //����
	t.healMp = 1000;
	strcpy(t.script, "�����ϰ� �ÿ��� �Ϻ����̴�. mp�� 1000ä���ش�.");


	_item.push_back(t);




	//����۵� ������ �Ʒ��Ͱ��� ���ָ��.
	/*


	//������1 ����
	t.itemimg = IMAGEMANAGER->findImage("������1");
	strcpy(t.itemname, "�ǹ� ũ�缼�̴� �︧");
	t.itemtype = 1; //1�� ����!!!
	t._price = 120000; //����
	t.hp = 0, t.mp = 0, t.str = 2, t.dex = 0, t.inteligence = 0, t.luk = 0;
	t.phyatk = 0, t.phyarm = 54, t.magatk = 0, t.magarm = 0,
	t.hitrate = 0, t.avoidrate = 0, t.upgrade = 7;

	t.reqLev = 50;
	t.reqStr = 160;
	t.reqDex = 0;
	t.reqInt = 0;
	t.reqLuk = 0;

	_item.push_back(t);




	//������2 ����
	t.itemimg = IMAGEMANAGER->findImage("������2");
	strcpy(t.itemname, "����� ��缭Ŭ��");
	t.itemtype = 1; //1�� ����!!!
	t._price = 120000; //����
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

	//����
	{
		t.itemimg = IMAGEMANAGER->findImage("����1");
		strcpy(t.itemname, "���� ����");
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

		strcpy(t.script, "������ �������� ����.");

		_item.push_back(t);

		t.itemimg = IMAGEMANAGER->findImage("����2");
		strcpy(t.itemname, "Ǫ�� ����");
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

		strcpy(t.script, "������ ���� ���� Ǫ���� ����.");

		_item.push_back(t);

		t.itemimg = IMAGEMANAGER->findImage("����3");
		strcpy(t.itemname, "�Ͼ� ����");
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

		strcpy(t.script, "�������� �Ͼ���� ����.");

		_item.push_back(t);
	}

	//����
	{
		t.itemimg = IMAGEMANAGER->findImage("����1");
		strcpy(t.itemname, "���� ������");
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

		strcpy(t.script, "���۳��� �ٶ����� ���ڴ�.");

		_item.push_back(t);

		t.itemimg = IMAGEMANAGER->findImage("����2");
		strcpy(t.itemname, "����� ��");
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

		strcpy(t.script, "��������� ������ ��.");

		_item.push_back(t);

		t.itemimg = IMAGEMANAGER->findImage("����3");
		strcpy(t.itemname, "������ ����");
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

		strcpy(t.script, "�������� �Ͼ���� ����.");

		_item.push_back(t);
	}

	//����
	{
		t.itemimg = IMAGEMANAGER->findImage("����1");
		strcpy(t.itemname, "�⺻�� ESP ������");
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

		strcpy(t.script, "�⺻�� ������.");

		_item.push_back(t);

		t.itemimg = IMAGEMANAGER->findImage("����2");
		strcpy(t.itemname, "���� ������");
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

		strcpy(t.script, "�ñ��� ���� ���� ������.");

		_item.push_back(t);

		t.itemimg = IMAGEMANAGER->findImage("����3");
		strcpy(t.itemname, "�ڷγ� ������");
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

		strcpy(t.script, "�¾��� ���� ��� ������.");

		_item.push_back(t);
	}

	//����
	{
		t.itemimg = IMAGEMANAGER->findImage("����1");
		strcpy(t.itemname, "õ ����");
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

		strcpy(t.script, "ȭ���� õ����.");

		_item.push_back(t);

		t.itemimg = IMAGEMANAGER->findImage("����2");
		strcpy(t.itemname, "���� ġ��");
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

		strcpy(t.script, "���� �������� ���� ġ��.");

		_item.push_back(t);

		t.itemimg = IMAGEMANAGER->findImage("����3");
		strcpy(t.itemname, "�Ͼ� ġ��");
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
		
		strcpy(t.script, "������ ġ���̴�.");

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
