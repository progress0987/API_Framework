#pragma once
#include "gameNode.h"
//��ȣ ������
class player:public gameNode
{
private:

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	player();
	~player();
};

