#pragma once
#include"gameNode.h"
//몬스터의 기본 구조 클래스
class monster :public gameNode
{
protected:
	int MaxHp;
	int NowHp;
	int Atk;
	int Def;
	RECT body;
	RECT colBody;
	POINT pt;
	bool dead;
	bool moveDir;//true - 오른쪽
	int bodyW, bodyH;


	Camera* cam;
public:

	monster();
	~monster();
	//셋팅
	HRESULT init(int Hp, int Atk, int Def, POINT position, int Width, int height);

	bool hit(void);				//공격당한것 확인
	void MonsterMoving(int move);	//몬스터 좌우 움직임


	void MonsterDown(int Down);	//몬스터 중력값 주기

	void left(int way);	//왼쪽 오른쪽 설정

	void Setbody(int i);//픽셀충돌에 몬스터 렉트 설정

	void SetCam(Camera* c) { cam = c; }//카메라 세팅

};
//Harp의 관리 클래스
class Harp :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 255;
public:
	Harp();
	~Harp();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//공격력 가져오기
	int getAtk(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};