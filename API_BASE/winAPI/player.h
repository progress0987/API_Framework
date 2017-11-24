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

struct status
{
	int HP = 2000;    //ü��
	int MP = 1000;    //����
	int Str = 0;      //��
	int Dex = 0;      //��ø
	int Int = 0;      //����
	int Luk = 0;      //��
	int Att = 0;      //���ݷ�
	int Like = 0;     //�α⵵
	int Exp = 0;      //����ġ
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

	status stat;

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
	RECT getRc() { return rc; }


	status getstatus() { return stat; }
	
	int setHP(int hp) { stat.HP = hp; }
	int setMP(int mp) { stat.MP = mp; }
	int setStr(int str) { stat.Str = str; }
	int setDex(int dex) { stat.Dex = dex; }
	int setInt(int intt) { stat.Int = intt; }
	int setLuk(int luk) { stat.Luk = luk; }
	int setAtt(int att) { stat.Att = att; }
	int setLike(int like) { stat.Like = like; }
	int setExp(int exp) { stat.Exp = exp; }

	//ĳ������ ������ �޾� ī�޶� �ǽð����� �������ش�.


	player();
	~player();
};

