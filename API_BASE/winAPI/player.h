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

class skill :public gameNode{
	RECT rc;	//�÷��̾� ��ǥ ���� ������Ŵ
	RECT dmgRC;//rc�� ����ؼ� ����,(rc�� �������� 0,0�̶�� �����ϰ� �߰�)
	image* img;
	int dmg;
	int skillIndex;//��ų�ε���(enum���� �ϴ��� �� ��)
	int frameX=0;
	int frame=0;
	int range;
	bool onAttack;
	int delayPerFrames;
	vector<RECT> dmgRCList;
public:
	HRESULT init(char* skillImg,int dPf,int dmg, int range);
	void release(void);
	void update(void);
	void render(void);
	void setSkillRect(int index, RECT skillRC);
	void fire(POINT pos, bool dir);
};



class player :public gameNode
{
private:
	mapFrame* curScene;
	image *_human;
	image* attackMotion;

	image *backStage;
	Camera* mycam;
	RECT rc;
	RECT hitRC;
	RECT dmgRC;
	skill* ASkill;
	skill* SSkill;
	skill* DSkill;
	vector<skill*> skillList;

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

	bool onAttack;
	int attFrame;
	int attX;
public:
	bool sceneChange=false;
	HRESULT init(POINT position,mapFrame* Scene);
	void release(void);
	void update(void);
	void render(void);
	void setBackStage(image* backstage) { this->backStage = backstage; }
	void setCamera(Camera* cam) { this->mycam = cam; }
	void playAttMotion();
	RECT getHitRC() { return hitRC; }
	RECT getDmgRC() { return dmgRC; }


	//ĳ������ ������ �޾� ī�޶� �ǽð����� �������ش�.


	player();
	~player();
};

