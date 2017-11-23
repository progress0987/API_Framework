#pragma once
#include "gameNode.h"
#include "mapFrame.h"

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
	mapFrame* curScene;
	image *_human;
	image *backStage;
	Camera* mycam;
	RECT rc;
	RECT hitRC;
	bool curDir;//���� ���� - true:������, false:����


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
	virtual HRESULT init(POINT position,mapFrame* Scene);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
	void setBackStage(image* backstage) { this->backStage = backstage; }
	void setCamera(Camera* cam) { this->mycam = cam; }

	//ĳ������ ������ �޾� ī�޶� �ǽð����� �������ش�.


	player();
	~player();
};

