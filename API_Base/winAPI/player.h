#pragma once
#include "gameNode.h"

//����.
enum Direction
{
	LEFT, RIGHT, UP, DOWN
};

class player:public gameNode
{
private:
	image *_human;
	image *backStage;
	RECT MAN;


	bool left, right, up, down;

	//��� ���º���
	bool staywalk = false; //�ȴ����϶�
	bool onlope = false; //������ �Ŵ޷�������
	bool onladder = false; //��ٸ� ���� ������
	bool onJump = false; //���߿� �ִ���
	bool onLand = false; //������ ������

	float mapx, mapy;

	int count, _index;


	//����ó���� ���� �߷°� ����

	int velocity = 0, gravity = 1, lift = -13;




	//�ȼ������ ���κ�

	//��, ��, ��, ��
	int pl, pr, pb, pu;
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	//ĳ������ ������ �޾� ī�޶� �ǽð����� �������ش�.
	void camera(int dir, image *human);


	player();
	~player();
};

