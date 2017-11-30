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
	bgm = "Park";

	front = IMAGEMANAGER->findImage("park");
	back = IMAGEMANAGER->findImage("pixelpark");

	////////////////////////////////////////////////////////////////////////////////포탈
	//왼쪽에 있는 포탈
	leftportal.x = 86;
	leftportal.y = 680;
	leftportal.rc = RectMake(leftportal.x, leftportal.y, 2, 10);
	leftportal._img = IMAGEMANAGER->findImage("portal");
	leftportal.currentX = 0;
	leftportal.pattern = 0;

	//오른쪽에 있는 보스 만나러가는 포탈
	rightportal.x = 1863;
	rightportal.y = 806;
	rightportal.rc = RectMake(rightportal.x, rightportal.y, 2, 10);
	rightportal._img = IMAGEMANAGER->findImage("portal");
	rightportal.currentX = 0;
	rightportal.pattern = 1;

	PORTAL.push_back(leftportal);
	PORTAL.push_back(rightportal);
	myIndex = MapIndex::MPark;

	

	return S_OK;
}
void ParkMap::release()
{
	SAFE_DELETE(leftportal._img);
	SAFE_DELETE(rightportal._img);
}
void ParkMap::update()
{
	//키매니저
	Keymanager();
	//프레임
	Frame();
	

}
void ParkMap::render()
{
	//배경
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, cam->width, cam->height);
	//포탈그리기
	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++)
	{
		i->_img->alphaFrameRender(getMemDC(), i->x - 50 - cam->camPoint.x, i->y - 50 - cam->camPoint.y, i->currentX, 0, 150);
	}
	//포탈 충돌렉트
	//Rectangle(getMemDC(), leftportal.rc.left - cam->camPoint.x, leftportal.rc.top - cam->camPoint.y,
		//leftportal.rc.right - cam->camPoint.x, leftportal.rc.bottom - cam->camPoint.y);

	//Rectangle(getMemDC(), rightportal.rc.left - cam->camPoint.x, rightportal.rc.top - cam->camPoint.y,
		//rightportal.rc.right - cam->camPoint.x, rightportal.rc.bottom - cam->camPoint.y);
}

void ParkMap::Keymanager()
{
	
}

void ParkMap::Frame()
{
	//프레임 돌리는 거
	count++;
	//포탈
	if (count % 15 == 0)
	{
		for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++)
		{
			i->currentX++;
			if (i->currentX > i->_img->getMaxFrameX())i->currentX = 0;
		}
	}
}
