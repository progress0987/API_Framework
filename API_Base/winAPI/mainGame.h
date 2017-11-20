#pragma once
#include"gameNode.h"
#include"monster.h"
class mainGame :  public gameNode
{
	Harp* test1;
private:
public:
	POINT base;
	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

