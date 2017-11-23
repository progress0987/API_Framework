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
	////////////////////////////////////////////////////////////////////////////////��Ż
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
	//Ű�Ŵ���
	Keymanager();
	//������
	Frame();
}
void MarketMap::render()
{
	//���
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, cam->width, cam->height);
	//��Ż
	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++)
	{
		i->_img->alphaFrameRender(getMemDC(), i->x - 50 - cam->camPoint.x, i->y - 50 - cam->camPoint.y, i->currentX, 0, 150);
	}
	//��Ż�浹��Ʈ
	Rectangle(getMemDC(), leftportal.rc.left - cam->camPoint.x, leftportal.rc.top - cam->camPoint.y,
		leftportal.rc.right - cam->camPoint.x, leftportal.rc.bottom - cam->camPoint.y);
	

}
//Ű 
void MarketMap::Keymanager()
{
	
}
//������
void MarketMap::Frame()
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