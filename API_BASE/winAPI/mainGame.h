#pragma once
#include"gameNode.h"
#include"StoreMap.h"
#include"VillageMap.h"
#include"ParkMap.h"
class mainGame :  public gameNode
{

private:
	StoreMap* _map;//����
	VillageMap* _village;//����
	ParkMap* _park;//����

	

public:

	HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

