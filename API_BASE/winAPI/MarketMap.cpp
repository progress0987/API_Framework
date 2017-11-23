#include "stdafx.h"
#include "MarketMap.h"


MarketMap::MarketMap()
{
}


MarketMap::~MarketMap()
{
}



HRESULT MarketMap::init()
{
	front = IMAGEMANAGER->findImage("market");
	back = IMAGEMANAGER->findImage("pixelmarket");
	////////////////////////////////////////////////////////////////////////////////포탈
	leftportal.x = 71;
	leftportal.y = 680;
	leftportal.rc = RectMake(leftportal.x, leftportal.y, 2, 10);
	leftportal._img = IMAGEMANAGER->findImage("portal");
	leftportal.currentX = 0;
	leftportal.pattern = 0;

	

	PORTAL.push_back(leftportal);

	
	return S_OK;
}
void MarketMap::release()
{
	SAFE_DELETE(leftportal._img);
}
void MarketMap::update()
{
	//키매니저
	Keymanager();
	//프레임
	Frame();
}
void MarketMap::render()
{
	//배경
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, cam->width, cam->height);
	//포탈
	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++)
	{
		i->_img->alphaFrameRender(getMemDC(), i->x - 50 - cam->camPoint.x, i->y - 50 - cam->camPoint.y, i->currentX, 0, 150);
	}
	//포탈충돌렉트
	Rectangle(getMemDC(), leftportal.rc.left - cam->camPoint.x, leftportal.rc.top - cam->camPoint.y,
		leftportal.rc.right - cam->camPoint.x, leftportal.rc.bottom - cam->camPoint.y);
	

}
//키 
void MarketMap::Keymanager()
{
	
}
//프레임
void MarketMap::Frame()
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