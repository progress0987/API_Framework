#pragma once
#include"gameNode.h"
#include"player.h"

class mainGame :  public gameNode
{
private:

	player *_player;
public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

