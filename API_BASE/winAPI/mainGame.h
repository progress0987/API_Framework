#pragma once
#include"gameNode.h"
#include"enemyManager.h"
#include "player.h"

class mainGame : public gameNode
{
private:
	Camera* cam;
	player *_player;
	enemyManager* em;
	
public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

