#pragma once
#include "gameNode.h"
#include "mapFrame.h"
#include "UserInterface.h"
#include "enemyManager.h"

class enemyManager;

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



class skill :public gameNode{
protected:
	RECT rc;	//플레이어 좌표 갖고 생성시킴
	RECT dmgRC;//rc와 비례해서 생성,(rc의 왼쪽위를 0,0이라고 생각하고 추가)
	image* img;
	int dmg;
	int range;
	int skillIndex;//스킬인덱스(enum으로 하던가 할 것)
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
	int maxHP = 200;	//최대 체력
	int curHP = 200;    //현재 체력
	int maxMP = 50;		//최대 마나
	int curMP = 50;    //현재 마나
	int Str = 5;      //힘
	int Dex = 5;      //민첩
	int Int = 5;      //지력
	int Luk = 5;      //운
	int Att = Str*4 + Dex*2;      //공격력
	int Def = Str * 3 + Dex * 3;
	int Like = 0;     //인기도
	int Exp = 0;      //경험치
	int lvlUpExp = 300;
	int ap = 0;	//스텟 포인트
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
	bool curDir;//현재 방향 - true:오른쪽, false:왼쪽


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
	//경험치 획득
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

