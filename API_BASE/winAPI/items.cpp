#include "stdafx.h"
#include "items.h"


HRESULT items::init(void)
{
	
	IMAGEMANAGER->addImage("���޹�", "���޹�.bmp", 31, 31, true, NULL);
	IMAGEMANAGER->addImage("�Ķ�����", "�Ķ�����.bmp", 27, 27, true, NULL);
	IMAGEMANAGER->addImage("�Ϻ���", "�Ϻ���.bmp", 26, 30, true, NULL);
	IMAGEMANAGER->addImage("�Ͼ�����", "�Ͼ�����.bmp", 27, 27, true, NULL);


	IMAGEMANAGER->addImage("����������â", "����������â.bmp", 220, 300, false, NULL);
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
	t.itemimg = IMAGEMANAGER->addImage("��������", "��������.bmp", 27, 27, true, NULL);
	strcpy(t.itemname, "��������");
	t.itemtype = potion;
	t._price = 50; //����
	t.healHp = 50;
	strcpy(t.script, "������ �����̴�. hp�� 50ä���ش�.");

	_item.push_back(t);




	/*������2 ����*/
	t.itemimg = IMAGEMANAGER->addImage("��Ȳ����", "��Ȳ����.bmp", 27, 27, true, NULL);
	strcpy(t.itemname, "��Ȳ����");
	t.itemtype = potion;
	t._price = 160; //����
	t.healHp = 150;
	strcpy(t.itemname, "��Ȳ�� �����̴�. hp�� 150ä���ش�.");

	_item.push_back(t);



	/*������3 ����*/
	t.itemimg = IMAGEMANAGER->addImage("�Ͼ�����", "�Ͼ�����.bmp", 27, 27, true, NULL);
	strcpy(t.itemname, "�Ͼ�����");
	t.itemtype = potion;
	t._price = 320; //����
	t.healHp = 300;
	strcpy(t.itemname, "�Ͼ�� �����̴�. hp�� 300ä���ش�.");

	_item.push_back(t);


	/*������4 ����*/
	t.itemimg = IMAGEMANAGER->addImage("���޹�", "���޹�.bmp", 31, 31, true, NULL);
	strcpy(t.itemname, "���޹�");
	t.itemtype = potion;
	t._price = 2100; //����
	t.healHp = 2000;
	strcpy(t.itemname, "�ӱ��� �ÿ��� ���޹��̴�. hp�� 2000ä���ش�.");


	_item.push_back(t);

	/*������5 ����*/
	t.itemimg = IMAGEMANAGER->addImage("�Ķ�����", "�Ķ�����.bmp", 27, 27, true, NULL);
	strcpy(t.itemname, "�Ķ�����");
	t.itemtype = potion;
	t._price = 200; //����
	t.healMp = 100;
	strcpy(t.itemname, "�Ķ��� �����̴�. mp�� 100ä���ش�.");


	_item.push_back(t);

	/*������6 ����*/
	t.itemimg = IMAGEMANAGER->addImage("�Ϻ���", "�Ϻ���.bmp", 26, 30, true, NULL);
	strcpy(t.itemname, "�Ϻ���");
	t.itemtype = potion;
	t._price = 2500; //����
	t.healMp = 1000;
	strcpy(t.itemname, "�����ϰ� �ÿ��� �Ϻ����̴�. mp�� 1000ä���ش�.");


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
	
	return S_OK;
}

items::items()
{
}


items::~items()
{
}
