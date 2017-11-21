#pragma once
#include"gameNode.h"
#include"StoreMap.h"
#include"VillageMap.h"
#include"ParkMap.h"
class mainGame :  public gameNode
{

private:
	StoreMap* _map;//상점
	VillageMap* _village;//마을
	ParkMap* _park;//공원

	

public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

