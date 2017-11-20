#pragma once
#include"gameNode.h"
#include"StoreMap.h"
#include"VillageMap.h"
class mainGame :  public gameNode
{

private:
	StoreMap* _map;
	VillageMap* _village;
	

public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

