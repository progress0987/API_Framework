#include "stdafx.h"
#include "VillageMap.h"


VillageMap::VillageMap()
{
}


VillageMap::~VillageMap()
{
}


HRESULT VillageMap::init()
{
	////////////////////////////////////////////////////////////////////////////////��Ż
	/*

	tagrect _lefeportal;//���� ���ʿ� �ִ� ��Ż				0
	tagrect rightportal;//���� �����ʿ� �ִ� ��Ż			1
	tagrect storeportal;//���� ��Ż							2
	tagrect parkportal;//�������� ��Ż						3
	tagrect marketportal;//���尡�� ��Ż					4
	*/
	//���� ��Ż
	_lefeportal.x = 159;
	_lefeportal.y = 670;
	_lefeportal.rc = RectMake(_lefeportal.x, _lefeportal.y, 54, 88);
	_lefeportal._img = IMAGEMANAGER->findImage("portal");
	_lefeportal.currentX = 0;
	_lefeportal.pattern = 0;

	//������ ��Ż
	rightportal.x = 2880;
	rightportal.y = 650;
	rightportal._img = IMAGEMANAGER->findImage("portal");
	rightportal.rc = RectMakeCenter(rightportal.x, rightportal.y, 50, 80);
	rightportal.pattern = 1;
	//���� ��Ż
	storeportal.x = 1490;
	storeportal.y = 650;
	storeportal._img = IMAGEMANAGER->findImage("portal");
	storeportal.rc = RectMakeCenter(storeportal.x, storeportal.y, 50, 80);
	storeportal.pattern = 2;
	//���� ��Ż
	parkportal.x = 1270;
	parkportal.y = 320;
	parkportal._img = IMAGEMANAGER->findImage("portal");
	parkportal.rc = RectMakeCenter(parkportal.x, parkportal.y, 50, 80);
	parkportal.pattern = 3;
	//���� ��Ż
	marketportal.x = 430;
	marketportal.y = 530;
	marketportal._img = IMAGEMANAGER->findImage("portal");
	marketportal.rc = RectMakeCenter(marketportal.x, marketportal.y, 50, 80);
	marketportal.pattern = 4;
	PORTAL.push_back(_lefeportal);
	PORTAL.push_back(rightportal);
	PORTAL.push_back(storeportal);
	PORTAL.push_back(parkportal);
	PORTAL.push_back(marketportal);
	////////////////////////////////////////////////////////////////////////////////NPC
	//������ 
	gujiGirl.x = 1200;
	gujiGirl.y = 660;
	gujiGirl.rc = RectMake(gujiGirl.x, gujiGirl.y, 50, 80);
	gujiGirl._img = IMAGEMANAGER->findImage("gujigirl");
	gujiGirl.currentX = 0;
	//���� 
	Lina.x = 2600;
	Lina.y = 660;
	Lina.rc = RectMake(Lina.x, Lina.y, 50, 80);
	Lina._img = IMAGEMANAGER->findImage("lina");
	Lina.currentX = 0;
	//��Ȳ �Ӹ�
	OrangeHair.x = 2000;
	OrangeHair.y = 155;
	OrangeHair.rc = RectMake(OrangeHair.x, OrangeHair.y, 50, 80);
	OrangeHair._img = IMAGEMANAGER->findImage("orange");
	OrangeHair.currentX = 0;
	//�ֹֺ���
	mingming.x = 1000;
	mingming.y = 330;
	mingming.rc = RectMake(mingming.x, mingming.y, 50, 80);
	mingming._img = IMAGEMANAGER->findImage("ming");
	mingming.currentX = 0;
	mingming.pattern = rand() % 4;

	NPC.push_back(gujiGirl);
	NPC.push_back(Lina);
	NPC.push_back(OrangeHair);
	NPC.push_back(mingming);
	front = IMAGEMANAGER->findImage("village");
	back = IMAGEMANAGER->findImage("pixelvillage");
	return S_OK;
}
void VillageMap::release()
{
}
void VillageMap::update()
{
	
	_lefeportal.rc = RectMakeCenter(_lefeportal.x, _lefeportal.y, 5, 20);
	rightportal.rc = RectMakeCenter(rightportal.x, rightportal.y, 5, 20);
	storeportal.rc = RectMakeCenter(storeportal.x, storeportal.y, 5, 20);
	parkportal.rc = RectMakeCenter(parkportal.x, parkportal.y, 5, 20);
	marketportal.rc = RectMakeCenter(marketportal.x, marketportal.y, 5, 20);

	gujiGirl.rc = RectMake(gujiGirl.x, gujiGirl.y, 50, 80);
	Lina.rc = RectMake(Lina.x, Lina.y, 50, 80);
	OrangeHair.rc = RectMake(OrangeHair.x, OrangeHair.y, 50, 80);
	mingming.rc = RectMake(mingming.x, mingming.y, 50, 80);

	//������ �����°�
	Frame();
	//�ֹֿ�����
	MingmingMove();
}
void VillageMap::render()
{
	//��� 
	front->render(getMemDC(), 0, 0, cam->camPoint.x, cam->camPoint.y, cam->width, cam->height);
	//��Ż �׸���
	for (vector<tagrect>::iterator i = PORTAL.begin(); i != PORTAL.end(); i++) {
		i->_img->alphaFrameRender(front->getMemDC(), i->x - 25, i->y - 50, i->currentX, 0, 150);
	}

	//IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), _lefeportal.x - 50, _lefeportal.y - 50, _lefeportal.currentX, 0, 150);
	//Rectangle(getMemDC(), _lefeportal.rc.left, _lefeportal.rc.top, _lefeportal.rc.right, _lefeportal.rc.bottom);

	//IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), rightportal.x - 50, rightportal.y - 50, _lefeportal.currentX, 0, 150);
	//Rectangle(getMemDC(), rightportal.rc.left, rightportal.rc.top, rightportal.rc.right, rightportal.rc.bottom);

	//IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), storeportal.x - 50, storeportal.y - 50, _lefeportal.currentX, 0, 150);
	//Rectangle(getMemDC(), storeportal.rc.left, storeportal.rc.top, storeportal.rc.right, storeportal.rc.bottom);

	//IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), parkportal.x - 50, parkportal.y - 50, _lefeportal.currentX, 0, 150);
	//Rectangle(getMemDC(), parkportal.rc.left, parkportal.rc.top, parkportal.rc.right, parkportal.rc.bottom);

	//IMAGEMANAGER->findImage("portal")->alphaFrameRender(getMemDC(), marketportal.x - 50, marketportal.y - 50, _lefeportal.currentX, 0, 150);
	//Rectangle(getMemDC(), marketportal.rc.left, marketportal.rc.top, marketportal.rc.right, marketportal.rc.bottom);
	//npc
	for (vector<tagrect>::iterator i = NPC.begin(); i != NPC.end(); i++) {
		if (i->pattern == -1) {
			i->_img->frameRender(getMemDC(), i->rc.left, i->rc.top, i->currentX, 0);
		}
		else {
			int Ypos;
			switch (i->pattern) {
			case 0:
				Ypos = 3;
				break;
			case 1:
				Ypos = 1;
				break;
			case 2:
				Ypos = 0;
				break;
			case 3:
				Ypos = 2;
				break;
			}
			i->_img->frameRender(front->getMemDC(), i->rc.left, i->rc.top, i->currentX, Ypos);
		}
	}
	//IMAGEMANAGER->findImage("gujigirl")->frameRender(getMemDC(), gujiGirl.rc.left, gujiGirl.rc.top, gujiGirl.currentX, 0);
	//IMAGEMANAGER->findImage("lina")->frameRender(getMemDC(), Lina.rc.left, Lina.rc.top, Lina.currentX, 0);
	//IMAGEMANAGER->findImage("orange")->frameRender(getMemDC(), OrangeHair.rc.left, OrangeHair.rc.top, OrangeHair.currentX, 0);
	//if (mingming.pattern == 0)
	//{
	//	IMAGEMANAGER->findImage("ming")->frameRender(getMemDC(), mingming.rc.left, mingming.rc.top, mingming.currentX, 3);
	//}
	//else if (mingming.pattern == 1)
	//{
	//	IMAGEMANAGER->findImage("ming")->frameRender(getMemDC(), mingming.rc.left, mingming.rc.top, mingming.currentX, 1);
	//}
	//else if (mingming.pattern == 2)
	//{
	//	IMAGEMANAGER->findImage("ming")->frameRender(getMemDC(), mingming.rc.left, mingming.rc.top, mingming.currentX, 0);
	//}
	//else if (mingming.pattern == 3)
	//{
	//	IMAGEMANAGER->findImage("ming")->frameRender(getMemDC(), mingming.rc.left, mingming.rc.top, mingming.currentX, 2);
	//}
	//Rectangle(getMemDC(), mingming.rc.left, mingming.rc.top, mingming.rc.right, mingming.rc.bottom);

}






void VillageMap::Frame()
{
	count++;
	//��Ż��
	if (count % 15 == 0)
	{
		_lefeportal._img->setFrameX(_lefeportal._img->getFrameX());
		_lefeportal.currentX++;
		if (_lefeportal.currentX > _lefeportal._img->getMaxFrameX())_lefeportal.currentX = 0;
	}
	//���� ��
	if (count % 50 == 0)
	{
		gujiGirl._img->setFrameX(gujiGirl._img->getFrameX());
		gujiGirl.currentX++;
		if (gujiGirl.currentX > gujiGirl._img->getMaxFrameX())gujiGirl.currentX = 0;
	}
	//����
	if (count % 50 == 0)
	{
		Lina._img->setFrameX(Lina._img->getFrameX());
		Lina.currentX++;
		if (Lina.currentX > Lina._img->getMaxFrameX())Lina.currentX = 0;
	}
	//��Ȳ�Ӹ�
	if (count % 50 == 0)
	{
		OrangeHair._img->setFrameX(OrangeHair._img->getFrameX());
		OrangeHair.currentX++;
		if (OrangeHair.currentX > OrangeHair._img->getMaxFrameX())OrangeHair.currentX = 0;
	}
	//�ֹֺ���
	if (count % 50 == 0)
	{
		mingming._img->setFrameX(mingming._img->getFrameX());
		mingming.currentX++;
		if (mingming.currentX > mingming._img->getMaxFrameX())mingming.currentX = 0;
	}
}

void VillageMap::MingmingMove()
{
	if (mingming.pattern == 0)
	{
		mingming.x ++;
		if (count % 100 == 0)
		{
			mingming.pattern = rand() % 4;
		}
	}
	else if (mingming.pattern == 1)
	{
		mingming.x --;
		if (count % 100 == 0)
		{
			mingming.pattern = rand() % 4;
		}
	}
	else if (mingming.pattern == 2)
	{
		
		if (count % 500 == 0)
		{
			mingming.pattern = rand() % 4;
		}
	}
	else if (mingming.pattern == 3)
	{

		if (count % 500 == 0)
		{
			mingming.pattern = rand() % 4;
		}
	}
}
