#pragma once
#include "gameNode.h"
#include "mapFrame.h"
#include "UserInterface.h"
#include "enemyManager.h"

class enemyManager;

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
protected:
	RECT rc;	//�÷��̾� ��ǥ ���� ������Ŵ
	RECT dmgRC;//rc�� ����ؼ� ����,(rc�� �������� 0,0�̶�� �����ϰ� �߰�)
	image* img;
	int dmg;
	int range;
	int skillIndex;//��ų�ε���(enum���� �ϴ��� �� ��)
	int frameX=0;
	int frame=0;
	int delayPerFrames;
	vector<RECT> dmgRCList;
	Camera* cam;
public:
	bool onCast;
	HRESULT init(char* skillImg,int dPf,int dmg,int range);
	void release(void);
	void update(void);
	void render(void);
	void setSkillRect(RECT skillRC);
	void fire(POINT pos);
	int getRange() { return range; }
	RECT getCurSkillRC() {
		RECT tmpRC=dmgRC;
		tmpRC.left += rc.left;
		tmpRC.right += rc.left;
		tmpRC.top += rc.top;
		tmpRC.bottom += rc.top;
		return tmpRC;
	}
	void setCam(Camera* glcam) { cam = glcam; }
	int getDmg() {return dmg;}
};

struct status
{
	int Level = 1;
	int HP = 200;    //ü��
	int MP = 50;    //����
	int Str = 5;      //��
	int Dex = 5;      //��ø
	int Int = 5;      //����
	int Luk = 5;      //��
	int Att = Str*4 + Dex*2;      //���ݷ�
	int Def = Str * 3 + Dex * 3;
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
	skill* ASkill = nullptr;
	skill* SSkill = nullptr;
	skill* DSkill = nullptr;
	skill* curCast=nullptr;
	vector<skill*> skillList;

	status* stat;
//	UserInterface* UI;
	enemyManager* em;
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
	bool onHit;
	bool hitDir;
	int hitmoveX, hitmoveY;
	int hitcount,hitalpha;

	int attFrame;
	int attX;
public:
	bool sceneChange=false;
	bool sceneChangeFinished = false;
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
	void linkEnemyManager(enemyManager* em) { this->em = em; }
	void BeingHit(int amount = 50);


	status* getstatus() { return stat; }
	
	int setHP(int hp) {		stat->HP = hp; }
	int setMP(int mp) {		stat->MP = mp; }
	int setStr(int str) {	stat->Str = str; }
	int setDex(int dex) {	stat->Dex = dex; }
	int setInt(int intt) {	stat->Int = intt; }
	int setLuk(int luk) {	stat->Luk = luk; }
	int setAtt(int att) {	stat->Att = att; }
	int setLike(int like) { stat->Like = like; }
	int setExp(int exp) {	stat->Exp = exp; }

	//ĳ������ ������ �޾� ī�޶� �ǽð����� �������ش�.


	player();
	~player();
};

