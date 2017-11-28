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
	int HP = 200;    //체력
	int MP = 50;    //마나
	int Str = 5;      //힘
	int Dex = 5;      //민첩
	int Int = 5;      //지력
	int Luk = 5;      //운
	int Att = Str*4 + Dex*2;      //공격력
	int Def = Str * 3 + Dex * 3;
	int Like = 0;     //인기도
	int Exp = 0;      //경험치
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

	//캐릭터의 정보를 받아 카메라를 실시간으로 움직여준다.


	player();
	~player();
};

