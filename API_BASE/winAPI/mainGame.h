#pragma once
#include"gameNode.h"
#include"monster.h"
class mainGame :  public gameNode
{
	//�׽�Ʈ ����
	Harp* test1;
private:
public:
	//�÷��̾��Դϴ�
	RECT player;
	int demage = 100;
	//���� �׽�Ʈ ��ǥ
	POINT base;
	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

