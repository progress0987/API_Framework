#pragma once
#include"gameNode.h"
class mainGame :  public gameNode
{

private:
public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};
