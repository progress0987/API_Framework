#pragma once
#include "gameNode.h"
struct tagrect
{
	image* _img;
	RECT rc;
	int currentX;//������ ����
	int x;
	int y;
	int pattern=-1;//���� �ٲٴ� ����/��Ż �ε���

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
	int myIndex;//�� �������� enum���� ������ ��(���Ӹʵ鿡�� �ش���.)
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