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
	int reqMP;
	vector<RECT> dmgRCList;
	Camera* cam;
public:
	bool onCast;
	HRESULT init(char* skillImg,int dPf,int dmg,int range,int reqMP);
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

	void setSkillDMG(int dmg) { this->dmg = dmg; }
	int getReqMP() { return reqMP; }
	void setCam(Camera* glcam) { cam = glcam; }
	int getDmg() {return dmg;}
};

struct status
{
	int Level = 1;
	int maxHP = 200;	//�ִ� ü��
	int curHP = 200;    //���� ü��
	int maxMP = 50;		//�ִ� ����
	int curMP = 50;    //���� ����
	int Str = 5;      //��
	int Dex = 5;      //��ø
	int Int = 5;      //����
	int Luk = 5;      //��
	int Att = Str*4 + Dex*2;      //���ݷ�
	int Def = Str * 3 + Dex * 3;
	int Like = 0;     //�α⵵
	int Exp = 0;      //����ġ
	int lvlUpExp = 300;
	int ap = 0;	//���� ����Ʈ
};

class player :public gameNode
{
private:
	mapFrame* curScene;
	image *_human;
	image* attackMotion;
	items* ItemList;

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

	status* stat = new status;

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
	bool showHit;
	bool onShop;


	bool onLvlUP;
	int levelUPCount,lvlUPFrame;
	POINT lvlupIMGpt;


	bool hitDir;
	int hitmoveX;
	int hitcount,hitalpha;

	int attFrame;
	int attX;

	int meso = 1000;

	vector<item> equip;
	vector<item> consume;
	vector<item> etc;

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
	void BeingHit(int amount = 20);
	//����ġ ȹ��
	void GainExp(int exp);

	vector<item> getEquip() { return equip; }
	vector<item> getConsume() { return consume; }
	vector<item> getEtc() { return etc; }
	status* getstatus() { return stat; }
	
	void setMaxHP(int hp) { stat->maxHP = hp; }
	void setCurHP(int hp) {		stat->curHP = hp; }
	void setMaxMP(int mp) { stat->maxMP = mp; }
	void setCurMP(int mp) {		stat->curMP = mp; }
	void setStr(int str) {	stat->Str = str; }
	void setDex(int dex) {	stat->Dex = dex; }
	void setInt(int intt) {	stat->Int = intt; }
	void setLuk(int luk) {	stat->Luk = luk; }
	void setAtt(int att) {	stat->Att = att; }
	void setLike(int like) { stat->Like = like; }
	void setExp(int exp) {	stat->Exp = exp; }
	void setLvupExp(int exp) { stat->lvlUpExp = exp; }
	int getmeso() { return meso; }
	bool spendmeso(int amount) {
		if (meso - amount >= 0) { meso -= amount; return true; }
		else { return false; }
	}

	item getItem(char itemName[]);

	void showShop(bool val) { onShop = val; }
	bool openShop();

	player();
	~player();
};

