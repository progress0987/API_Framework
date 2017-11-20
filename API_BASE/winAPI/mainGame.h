#pragma once
#include"gameNode.h"
#include"enemyManager.h"
class mainGame : public gameNode
{
private:
	image *_human;
	image *backStage;
	RECT MAN;
	RECT TREE;

	bool left, right, up, down;
	bool staywalk = false;

	float mapx, mapy, x, y;

	int count, _index;
	
public:
	//void collision();
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
	
	mainGame();
	~mainGame();
	
};

