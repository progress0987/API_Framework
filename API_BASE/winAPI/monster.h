#pragma once
#include"gameNode.h"
#include"progressBar.h"
//몬스터의 기본 구조 클래스
class monster :public gameNode
{
protected:
	progressBar* Hpbar;
	int MaxHp;
	int NowHp;
	int Atk;
	int Def;
	RECT body;
	RECT colBody;
	RECT playerBody;
	RECT SkillTwoRect[4];
	POINT pt;
	POINT GenPoint;
	bool dead;
	bool moveDir;//true - 오른쪽
	int bodyW, bodyH;
	int MyIndex;
	int Gentime=50;

	Camera* cam;
public:

	monster();
	~monster();
	//셋팅
	HRESULT init(int Hp, int Atk, int Def, POINT position, int Width, int height);
	virtual void update();
	virtual void render();
	virtual void collRect(RECT player, int demage);
	virtual RECT getbody(void);//몬스터 체크 렉트 가져오기
	bool hit(void);				//공격당한것 확인
	void MonsterMoving(int move);	//몬스터 좌우 움직임
	bool ZeroHp(void);				//체력이 0 이하인지 확인
	void SharePlayer(RECT PlayerBase);

	void MonsterDown(int Down);	//몬스터 중력값 주기

	void left(int way);	//왼쪽 오른쪽 설정

	void Setbody(int i);//픽셀충돌에 몬스터 렉트 설정

	void SetCam(Camera* c) { cam = c; }//카메라 세팅

	int getIndex(void) { return MyIndex; }//인덱스 가져오기

	void HpbarInit(void);//hp바 만들기
	void Hpbarupdate(void);//hp바 업데이트
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
	int alpha = 250;
public:
	Harp();
	~Harp();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};
//Grupin의 관린 클래스
class Grupin :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Grupin();
	~Grupin();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};

class Cellion :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Cellion();
	~Cellion();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};

class Lioner :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Lioner();
	~Lioner();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};

class Lucida :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Lucida();
	~Lucida();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};

class JrYeti :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	JrYeti();
	~JrYeti();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};

class PePe :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	PePe();
	~PePe();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};

class Sheep :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	Sheep();
	~Sheep();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};

class JCellion :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	JCellion();
	~JCellion();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};

class JGrupin :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	JGrupin();
	~JGrupin();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};

class JLioner :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	JLioner();
	~JLioner();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};

class JLucida :public monster
{
	int Timer = 0;
	int frame = 0;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
public:
	JLucida();
	~JLucida();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
};

class Eliza :public monster
{
	int Timer = 0;
	int frame = 0;
	int SkillOneF = 0;
	int SkillTwoF = 0;
	int SkillTwoCount = 0;
	POINT DemagePoint[4];
	bool SkillOne;
	bool SkillTwo;
	bool Stay;
	bool hit;
	int HitTimer;
	int MoveTime = 0;
	int alpha = 250;
	int SkillTime = 0;
	RECT PlayerBase;
	int PlayerDamge;
	JLucida* setJLucida;
	Lucida* setLucida;
public:
	Eliza();
	~Eliza();
	//유닛 그림, 체력 등 설정
	HRESULT init(POINT position);
	//이동하는 함수
	void moving(void);
	//몬스터에게 데미지 주기
	void SubHp(int Atk);
	//죽음
	void dead(void);
	void update(void);
	void render(void);
	//몬스터가 플레이어에게 공격당했는가(공격력도 입력해주셔야 합니다)
	void collRect(RECT player, int demage);
	void skill2(void);
//	void SetCam(Camera* c);
};