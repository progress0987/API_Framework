#include "stdafx.h"
#include "ForestMap.h"


ForestMap::ForestMap()
{
}


ForestMap::~ForestMap()
{
}


HRESULT ForestMap::init()
{
	front = IMAGEMANAGER->findImage("forest");
	back = IMAGEMANAGER->findImage("pixelforest");
	////////////////////////////////////////////////////////////////////////////////��Ż
	portal.x = 67;
	portal.y = 830;
	portal.rc = RectMakeCenter(portal.x, portal.y, 2, 10);
	portal._img = IMAGEMANAGER->findImage("portal");
	portal.currentX = 0;
	portal.pattern = 0;

	PORTAL.push_back(portal);

	

	return S_OK;
}
void ForestMap::release()
{
	SAFE_DELETE(portal._img);
}
void ForestMap::update()
{
	//Ű�Ŵ���
	Keymanager();
	//������
	Frame();
}
void ForestMap::render()
{
	//���
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, cam->width, cam->height);
	//��Ż
	
	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++)
	{
		i->_img->alphaFrameRender(getMemDC(), i->rc.left - 50 - cam->camPoint.x, i->rc.top - 50 - cam->camPoint.y, i->currentX, 0, 150);
		//��Ż�浹��Ʈ
		Rectangle(getMemDC(), portal.rc.left - cam->camPoint.x, portal.rc.top - cam->camPoint.y, 
			portal.rc.right - cam->camPoint.x, portal.rc.bottom - cam->camPoint.y);
	}
	
	
}
//Ű 
void ForestMap::Keymanager()
{
}
//������
void ForestMap::Frame()
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