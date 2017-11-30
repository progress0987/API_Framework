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

	////////////////////////////////////////////////////////////////////////////////��Ż
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
	//Ű�Ŵ���
	//Keymanager();
	//������
	Frame();
}
void HillMap::render()
{
	//��� 
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, cam->width, cam->height);
	//��Ż�׸���
	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++)
	{
		i->_img->alphaFrameRender(getMemDC(), i->x - 50 - cam->camPoint.x, i->y - 50 - cam->camPoint.y, i->currentX, 0, 150);
		//Rectangle(getMemDC(), portal.rc.left - cam->camPoint.x, portal.rc.top - cam->camPoint.y,
			//portal.rc.right - cam->camPoint.x, portal.rc.bottom - cam->camPoint.y);
	}
	
}
//Ű 
void HillMap::Keymanager()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && moveX > 0)
	{
		moveX -= 3;
		//��Ż
		portal.x += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && moveX < 710)
	{
		moveX += 3;
		//��Ż
		portal.x -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && moveY > 0)
	{
		moveY -= 3;
		//��Ż
		portal.y += 3;

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && moveY < 230)
	{
		moveY += 3;
		//��Ż
		portal.y -= 3;
	}
}
//������
void HillMap::Frame()
{
	//������ ������ ��
	count++;
	//��Ż
	if (count % 15 == 0)
	{
		for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++)
		{
			i->currentX++;
			if (i->currentX > i->_img->getMaxFrameX())i->currentX = 0;
		}
	}
}