#pragma once
#include "gameNode.h"
#include "Skill.h"
#include "inventory.h"
struct bodyPart {
	image* img;
	int x, y;
	int width, height;
	RECT rc;
};

class player:public gameNode
{
private:

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	player();
	~player();
};

