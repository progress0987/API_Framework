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
	////////////////////////////////////////////////////////////////////////////////��Ż
	//���ʿ� �ִ� ��Ż
	portal.x = 50;
	portal.y = 500;
	portal.rc = RectMake(portal.x, portal.y, 50, 80);
	portal._img = IMAGEMANAGER->findImage("portal");
	portal.currentX = 0;
	portal.pattern = 0;
	//�����ʿ� �ִ� ���� ���������� ��Ż
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



	//������
	Frame();
	

}
void ParkMap::render()
{
	//���
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, WINSIZEX, WINSIZEY);
	//��Ż

	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++) {
		i->_img->alphaFrameRender(getMemDC(), i->x - 50 - cam->camPoint.x, i->y - 50 - cam->camPoint.y, i->currentX, 0, 150);
	}

}


void ParkMap::Frame()
{
	//������ ������ ��
	count++;
	//��Ż
	if (count % 15 == 0)
	{
		for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++) {
			i->currentX++;
			if (i->currentX > IMAGEMANAGER->findImage("portal")->getMaxFrameX())i->currentX = 0;
		}
	}
}
