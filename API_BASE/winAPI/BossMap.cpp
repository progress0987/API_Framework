 #include "stdafx.h"
#include "BossMap.h"


BossMap::BossMap()
{
}


BossMap::~BossMap()
{
}


HRESULT BossMap::init()
{

	////////////////////////////////////////////////////////////////////////////////Æ÷Å»
	front = IMAGEMANAGER->findImage("boss");
	back = IMAGEMANAGER->findImage("pixelboss");

	portal.x = 343;
	portal.y = 651;
	portal.rc = RectMakeCenter(portal.x, portal.y, 5, 10);
	portal.pattern = 0;
	portal.currentX = 0;
	portal._img = IMAGEMANAGER->findImage("portal");

	PORTAL.push_back(portal);


	return S_OK;
}
void BossMap::release()
{
	SAFE_DELETE(portal._img);
}
void BossMap::update()
{

	//Å°¸Å´ÏÀú
	//Keymanager();
	//ÇÁ·¹ÀÓ
	Frame();
}
void BossMap::render()
{
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, cam->width, cam->height);

	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++)
	{
		i->_img->alphaFrameRender(getMemDC(), i->x - 50 - cam->camPoint.x, i->y - 50 - cam->camPoint.y, i->currentX, 0, 150);
	}
	Rectangle(getMemDC(), portal.rc.left - cam->camPoint.x, portal.rc.top - cam->camPoint.y,
		portal.rc.right - cam->camPoint.x, portal.rc.bottom - cam->camPoint.y);

}
//Å° 
void BossMap::Keymanager()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && moveX > 0)
	{
		moveX -= 3;
		//Æ÷Å»
		portal.x += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 315)
	{
		moveX += 3;
		//Æ÷Å»
		portal.x -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && moveY > 0)
	{
		moveY -= 3;
		//Æ÷Å»
		portal.y += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 130)
	{
		moveY += 3;
		//Æ÷Å»
		portal.y -= 3;
	}
}

void BossMap::Frame()
{
	//ÇÁ·¹ÀÓ µ¹¸®´Â °Å
	count++;
	//Æ÷Å»
	if (count % 15 == 0)
	{
		for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++)
		{
			i->currentX++;
			if (i->currentX > i->_img->getMaxFrameX())i->currentX = 0;
		}
	}
}
