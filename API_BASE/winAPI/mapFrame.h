#pragma once
#include "gameNode.h"
struct tagrect
{
	image* _img;
	RECT rc;
	int currentX;//프레임 변수
	int x;
	int y;
	int pattern=-1;//방향 바꾸는 변수/포탈 인덱스

};

enum MapIndex {
	MVillage,
	MStore,
	MPark,
	MMarket,
	MHill,
	MForest,
	MBoss,
};

class mapFrame:public gameNode
{
protected:
	vector<tagrect> NPC;
	vector<tagrect> PORTAL;
	image* front;
	image* back;
	int count = 0;
	int myIndex;//맵 스스로의 enum값을 저장할 것(게임맵들에만 해당함.)
	Camera* cam;

	char* bgm;

public:
	mapFrame();
	~mapFrame();
	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	image* getFront() { return front; }
	image* getBack() { return back; }
	void setCam(Camera* camera) { cam = camera; }
	vector<tagrect> getPortals() { return PORTAL; }
	int getIndex() { return myIndex; }

	void soundplay(mapFrame* map);
	void soundoff(mapFrame* map);
};