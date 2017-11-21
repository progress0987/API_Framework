#pragma once
#include "gameNode.h"

//방향.
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
	bool onJump = false; //공중에 있느냐

	float mapx, mapy;

	int count, _index;


	//점프처리를 위한 중력값 설정

	int velocity = 0, gravity = 1, lift = -13;




	//픽셀검출용 프로브

	//좌, 우, 밑, 위
	int pl, pr, pb, pu;
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	//캐릭터의 정보를 받아 카메라를 실시간으로 움직여준다.
	void camera(int dir, image *human);


	player();
	~player();
};

