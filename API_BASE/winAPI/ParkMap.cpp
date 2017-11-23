#include "stdafx.h"
#include "ParkMap.h"


ParkMap::ParkMap()
{
}


ParkMap::~ParkMap()
{
}


HRESULT ParkMap::init()
{

	front = IMAGEMANAGER->findImage("park");
	back = IMAGEMANAGER->findImage("pixelpark");
	////////////////////////////////////////////////////////////////////////////////포탈
	//왼쪽에 있는 포탈
	portal.x = 50;
	portal.y = 500;
	portal.rc = RectMake(portal.x, portal.y, 50, 80);
	portal._img = IMAGEMANAGER->findImage("portal");
	portal.currentX = 0;
	portal.pattern = 0;
	//오른쪽에 있는 보스 만나러가는 포탈
	rightportal.x = 1880;
	rightportal.y = 610;
	rightportal.rc = RectMake(rightportal.x, rightportal.y, 50, 80);
	rightportal._img = IMAGEMANAGER->findImage("portal");
	rightportal.currentX = 0;
	rightportal.pattern = 1;

	PORTAL.push_back(portal);
	PORTAL.push_back(rightportal);


	return S_OK;
}
void ParkMap::release()
{
	SAFE_DELETE(portal._img);
}
void ParkMap::update()
{



	//프레임
	Frame();
	

}
void ParkMap::render()
{
	//배경
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, WINSIZEX, WINSIZEY);
	//포탈

	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++) {
		i->_img->alphaFrameRender(getMemDC(), i->x - 50 - cam->camPoint.x, i->y - 50 - cam->camPoint.y, i->currentX, 0, 150);
	}

}


void ParkMap::Frame()
{
	//프레임 돌리는 거
	count++;
	//포탈
	if (count % 15 == 0)
	{
		for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++) {
			i->currentX++;
			if (i->currentX > IMAGEMANAGER->findImage("portal")->getMaxFrameX())i->currentX = 0;
		}
	}
}
