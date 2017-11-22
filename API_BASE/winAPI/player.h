#pragma once
#include "gameNode.h"

//����.
enum Direction
{
	LEFT, RIGHT, UP, DOWN
};
enum Status {
	onIdle,
	onWalk,
	onJump,
	onDown,
	onLand,
	onLadder,
	onRope,
	onDead,
};

class player :public gameNode
{
private:
	image *_human;
	image *backStage;
	Camera* mycam;
	RECT rc;
	RECT hitRC;


	//��� ���º���
	int curStatus = onIdle;

	POINT curPos;

	int count, curFrameX, curFrameY;
	int width, height;
	float camAccelY;
	//�̵��ӵ�
	float moveVel = 0.f;


	//����ó���� ���� �߷°� ����

	float velocity = 0.f, gravity = 0.4f, jumpPow = -10.f;




public:
	virtual HRESULT init(Camera* cam);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	//ĳ������ ������ �޾� ī�޶� �ǽð����� �������ش�.


	player();
	~player();
};

