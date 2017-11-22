#pragma once
#include"../gameNode.h"
struct tagrect
{
	image* _img;
	RECT rc;
	int currentX;//������ ����
	int x;
	int y;
	int pattern;//���� �ٲٴ� ����

};
class VillageMap:public gameNode
{
	//��Ż
	tagrect _lefeportal;//���� ���ʿ� �ִ� ��Ż
	tagrect rightportal;//���� �����ʿ� �ִ� ��Ż
	tagrect storeportal;//���� ��Ż
	tagrect parkportal;//�������� ��Ż
	tagrect marketportal;//���尡�� ��Ż

	//NPC
	tagrect gujiGirl;//����
	tagrect Lina;//�̻۾�
	tagrect OrangeHair;//��Ȳ�Ӹ�
	tagrect mingming;

	//��� �����̴� ����
	int moveX, moveY;
	//������ ������ ����
	int count = 0;
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
	
	tagrect getlefeportal() { return _lefeportal; }
	tagrect getrightportal() { return rightportal; }
	tagrect getstoreportal() { return storeportal; }
	tagrect getparkportal() { return parkportal; }
	tagrect getmarketportal() { return marketportal; }


};

