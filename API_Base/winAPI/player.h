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
	bool staywalk = false;
	bool onlope = false;
	bool onladder = false;

	float mapx, mapy;

	int count, _index;


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

