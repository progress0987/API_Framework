#pragma once
#include"gameNode.h"
//몬스터의 기본 구조 클래스
class monster :public gameNode
{
	int MaxHp;
	int NowHp;
	int Atk;
	int Def;
	RECT body;
	bool dead;
	bool Left;
public:
	
	monster();
	~monster();
	//셋팅
	HRESULT init(int Hp, int Atk, int Def, POINT position, int Width, int height);
	//공격력 가져오기
	int getAtk(void);
	//체력 깍기
	void SubHp(int Atk);
	//체력 0 확인하기
	bool ZeroHp(void);
	//공격당한것 확인
	bool hit(void);
	//몬스터 좌우 움직임
	void MonsterMoving(int move);
	//몬스터 중력값 주기
	void MonsterDown(int Down);
	//왼쪽 오른쪽 설정
	void left(int way);
	//왼쪽인지 오른쪽인지 확인하는 함수
	bool way(void);
	//픽셀충돌에 몬스터 렉트 설정
	void Setbody(int i);
	RECT Base(void);
};
//Harp의 관리 클래스
class Harp :public gameNode
{
	int Timer=0;
	POINT generator;
	monster* harp;
	RECT player;
	int fream = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Harp();
	~Harp();
	//유닛 그림, 체력 등 설정
	HRESULT init(void);
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
	//몬스터 좌표 설정
	void SetPoint(POINT position);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};