#pragma once
#include "image.h"
static image* backBuffer = IMAGEMANAGER->addImage("backBuffer",WINSIZEX,WINSIZEY);


typedef struct Camera {
	POINT camPoint;
	int width, height;
};

class gameNode
{

private:
	HDC hdc;
	bool managerInit;
public:


	HRESULT init(void);
	HRESULT init(bool managerInit);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	image* getBackBuffer() { return backBuffer; }

	HDC getMemDC() { return backBuffer->getMemDC(); }
	HDC getHDC() { return hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual~gameNode();
};

