#pragma once
#include"mapFrame.h"

class VillageMap:public mapFrame
{
	//��Ż
	tagrect _lefeportal;//���� ���ʿ� �ִ� ��Ż				0
	tagrect rightportal;//���� �����ʿ� �ִ� ��Ż			1
	tagrect storeportal;//���� ��Ż							2
	tagrect parkportal;//�������� ��Ż						3
	tagrect marketportal;//���尡�� ��Ż					4

	//NPC
	tagrect gujiGirl;//����
	tagrect Lina;//�̻۾�
	tagrect OrangeHair;//��Ȳ�Ӹ�
	tagrect mingming;

public:
	VillageMap();
	~VillageMap();

	HRESULT init();
	void release();
	void update();
	void render();
	//Ű 
	void Keymanager();
	//������
	void Frame();
	//�ֹֺ��� �����̴�
	void MingmingMove();

};

