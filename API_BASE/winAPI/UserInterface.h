#pragma once
#include"gameNode.h"

class UserInterface :public gameNode
{
public:
	virtual HRESULT init(void);
	virtual void release(void);

	virtual void update(void);

	virtual void render(void);

	UserInterface();
	~UserInterface();
};