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
	t.number = 0;
	strcpy(t.itemname, "��������");
	t.itemtype = potion;
	t._price = 50; //����
	t.healHp = 50;
	strcpy(t.script, "������ �����̴�. hp�� 50ä���ش�.");

	_item.push_back(t);




	/*������2 ����*/
	t.itemimg = IMAGEMANAGER->findImage("��Ȳ����");
	t.number = 1;
	strcpy(t.itemname, "��Ȳ����");
	t.itemtype = potion;
	t._price = 160; //����
	t.healHp = 150;
	strcpy(t.script, "��Ȳ�� �����̴�. hp�� 150ä���ش�.");

	_item.push_back(t);



	/*������3 ����*/
	t.itemimg = IMAGEMANAGER->findImage("�Ͼ�����");
	t.number = 2;
	strcpy(t.itemname, "�Ͼ�����");
	t.itemtype = potion;
	t._price = 320; //����
	t.healHp = 300;
	strcpy(t.script, "�Ͼ�� �����̴�. hp�� 300ä���ش�.");

	_item.push_back(t);


	/*������4 ����*/
	t.itemimg = IMAGEMANAGER->findImage("���޹�");
	t.number = 3;
	strcpy(t.itemname, "���޹�");
	t.itemtype = potion;
	t._price = 2100; //����
	t.healHp = 2000;
	strcpy(t.script, "�ӱ��� �ÿ��� ���޹��̴�. hp�� 2000ä���ش�.");


	_item.push_back(t);

	/*������5 ����*/
	t.itemimg = IMAGEMANAGER->findImage("�Ķ�����");
	t.number = 4;
	strcpy(t.itemname, "�Ķ�����");
	t.itemtype = potion;
	t._price = 200; //����
	t.healMp = 100;
	strcpy(t.script, "�Ķ��� �����̴�. mp�� 100ä���ش�.");


	_item.push_back(t);

	/*������6 ����*/
	t.itemimg = IMAGEMANAGER->findImage("�Ϻ���");
	t.number = 5;
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
		//������ 7 ��������
		t.itemimg = IMAGEMANAGER->findImage("����1");
		t.number = 6;
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


		//������ 8 Ǫ������
		t.itemimg = IMAGEMANAGER->findImage("����2");
		t.number = 7;
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


		//������ 9 �Ͼ����
		t.itemimg = IMAGEMANAGER->findImage("����3");
		t.number = 8;
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
		//������ 10 ���� ������
		t.itemimg = IMAGEMANAGER->findImage("����1");
		t.number = 9;
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

		//������ 11 ����� ��

		t.itemimg = IMAGEMANAGER->findImage("����2");
		t.number = 10;
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

		//������ 12 ���������

		t.itemimg = IMAGEMANAGER->findImage("����3");
		t.number = 11;
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
		//������ 13 �⺻�� ESP ������
		t.itemimg = IMAGEMANAGER->findImage("����1");
		t.number = 12;
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


		//������ 14 ����������
		t.itemimg = IMAGEMANAGER->findImage("����2");
		t.number = 13;
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


		//������ 15 �ڷγ� ������
		t.itemimg = IMAGEMANAGER->findImage("����3");
		t.number = 14;
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

		//������ 16 õ����
		t.itemimg = IMAGEMANAGER->findImage("����1");
		t.number = 15;
		strcpy(t.itemname, "õ����");
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


		//������ 17 ����ġ��
		t.itemimg = IMAGEMANAGER->findImage("����2");
		t.number = 16;
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


		//������ 18 �Ͼ�ġ��
		t.itemimg = IMAGEMANAGER->findImage("����3");
		t.number = 17;
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

	//����
	{

		//������ 19 Ƽ����
		t.itemimg = IMAGEMANAGER->findImage("����1");
		t.number = 18;
		strcpy(t.itemname, "Ƽ����");
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

		strcpy(t.script, "���� ȸ�� Ƽ����.");

		_item.push_back(t);


		//������ 20 ����Ʈ
		t.itemimg = IMAGEMANAGER->findImage("����2");
		t.number = 19;
		strcpy(t.itemname, "����Ʈ");
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

		strcpy(t.script, "���� �����ϴ� ����Ʈ��Ÿ��");

		_item.push_back(t);


		//������ 21 ���� ����
		t.itemimg = IMAGEMANAGER->findImage("����3");
		t.number = 20;
		strcpy(t.itemname, "���� ����");
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

		strcpy(t.script, "ưư�غ��̴� �������� �����̴�.");

		_item.push_back(t);
	}

	//�Ź�
	{

		//������ 22 ������
		t.itemimg = IMAGEMANAGER->findImage("�Ź�1");
		t.number = 21;
		strcpy(t.itemname, "������");
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

		strcpy(t.script, "��¦��¦ ������.");

		_item.push_back(t);


		//������ 23 ���׽Ź�
		t.itemimg = IMAGEMANAGER->findImage("�Ź�2");
		t.number = 22;
		strcpy(t.itemname, "���׽Ź�");
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

		strcpy(t.script, "ưư�� ���׽Ź��̴�.");

		_item.push_back(t);


		//������ 24 �к���
		t.itemimg = IMAGEMANAGER->findImage("�Ź�3");
		t.number = 23;
		strcpy(t.itemname, "�к���");
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

		strcpy(t.script, "������ ���� �޸� ����.");

		_item.push_back(t);
	}

	//�尩
	{

		//������ 25 �Ͼ��尩
		t.itemimg = IMAGEMANAGER->findImage("�尩1");
		t.number = 24;
		strcpy(t.itemname, "�Ͼ� �尩");
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

		strcpy(t.script, "���Ŀ� �Ͼ� �尩.");

		_item.push_back(t);


		//������ 26 ������ �尩
		t.itemimg = IMAGEMANAGER->findImage("�尩2");
		t.number = 25;
		strcpy(t.itemname, "������ �尩");
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

		strcpy(t.script, "�۷��� ������� ������ ������ �尩.");

		_item.push_back(t);


		//������ 27 �����尩
		t.itemimg = IMAGEMANAGER->findImage("�尩3");
		t.number = 26;
		strcpy(t.itemname, "�����尩");
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

		strcpy(t.script, "�ǿ����� �������� �������� �尩.");

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
