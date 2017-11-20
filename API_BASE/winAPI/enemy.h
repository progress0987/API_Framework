#pragma once
#include "gameNode.h"



class enemy :public gameNode
{
protected:
	image* bodyImg;
	RECT RC;
	RECT hitRC;
	
	bool onHit;

	int x, y;
	int width, height;

	int curFrameX;
	int curFrameY;

public:
	bool hitable=false;

	HRESULT init(void);
	HRESULT init(const char* img, POINT position,RECT hitbox);
	void release(void);
	void update(void);
	void render();

	void move();
	void draw();

	RECT getRC() { return RC; }
	RECT gethitRC() { return hitRC; }

	enemy();
	~enemy();
};