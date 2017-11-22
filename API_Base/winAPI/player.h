#pragma once
#include "gameNode.h"

//방향.
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


	//모션 상태변수
	int curStatus = onIdle;

	POINT curPos;

	int count, curFrameX, curFrameY;
	int width, height;
	float camAccelY;
	//이동속도
	float moveVel = 0.f;


	//점프처리를 위한 중력값 설정

	float velocity = 0.f, gravity = 0.4f, jumpPow = -10.f;




public:
	virtual HRESULT init(Camera* cam);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	//캐릭터의 정보를 받아 카메라를 실시간으로 움직여준다.


	player();
	~player();
};

