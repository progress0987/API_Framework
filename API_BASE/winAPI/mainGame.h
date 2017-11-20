#pragma once
#include"gameNode.h"
#include"monster.h"
class mainGame :  public gameNode
{
	//테스트 몬스터
	Harp* test1;
private:
public:
	//플레이어입니다
	RECT player;
	int demage = 100;
	//몬스터 테스트 좌표
	POINT base;
	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

