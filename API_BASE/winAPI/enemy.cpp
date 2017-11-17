#include "stdafx.h"
#include "enemy.h"


HRESULT enemy::init(void)
{
	return S_OK;
}

HRESULT enemy::init(const char * img, POINT position, RECT hitbox = { 0,0,0,0 })
{
	curFrameX = curFrameY = 0;
	x = position.x;
	y = position.y;
	bodyImg = IMAGEMANAGER->findImage(img);
	width = bodyImg->getFrameWidth();
	height = bodyImg->getFrameHeight();
	RC = RectMakeCenter(x, y, width, height);
	if (!(hitbox.left == hitbox.right&&hitbox.top == hitbox.bottom)) {
		hitRC = hitbox;
	}

	return S_OK;
}


void enemy::release(void)
{
}

void enemy::update(void)
{
	move();
}

void enemy::render()
{
	draw();
}

void enemy::move()
{
}

void enemy::draw()
{
	bodyImg->frameRender(getMemDC(), RC.left, RC.top, curFrameX, curFrameY);
	//몸이 여러개일경우 더 그려줌
}

enemy::enemy()
{
}


enemy::~enemy()
{
}
