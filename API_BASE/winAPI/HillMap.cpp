#include "stdafx.h"
#include "HillMap.h"


HillMap::HillMap()
{
}


HillMap::~HillMap()
{
}



HRESULT HillMap::init()
{
	bgm = "Hill";

	front = IMAGEMANAGER->findImage("hill");
	back = IMAGEMANAGER->findImage("pixelhill");

	////////////////////////////////////////////////////////////////////////////////Æ÷Å»
	portal.x = 1941;
	portal.y = 840;
	portal.rc = RectMake(portal.x, portal.y, 2, 10);
	portal.currentX = 0;
	portal.pattern = 0;
	portal._img = IMAGEMANAGER->findImage("portal");


	PORTAL.push_back(portal);

	myIndex = MapIndex::MHill;

	return S_OK;
}
void HillMap::release()
{
	SAFE_DELETE(portal._img);
}
void HillMap::update()
{
	//Å°¸Å´ÏÀú
	//Keymanager();
	//ÇÁ·¹ÀÓ
	Frame();
}
void HillMap::render()
{
	//¹è°æ 
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, cam->width, cam->height);
	//Æ÷Å»±×¸®±â
	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++)
	{
		i->_img->alphaFrameRender(getMemDC(), i->x - 50 - cam->camPoint.x, i->y - 50 - cam->camPoint.y, i->currentX, 0, 150);
		//Rectangle(getMemDC(), portal.rc.left - cam->camPoint.x, portal.rc.top - cam->camPoint.y,
			//portal.rc.right - cam->camPoint.x, portal.rc.bottom - cam->camPoint.y);
	}
	
}
//Å° 
void HillMap::Keymanager()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && moveX > 0)
	{
		moveX -= 3;
		//Æ÷Å»
		portal.x += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 710)
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
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 230)
	{
		moveY += 3;
		//Æ÷Å»
		portal.y -= 3;
	}
}
//ÇÁ·¹ÀÓ
void HillMap::Frame()
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