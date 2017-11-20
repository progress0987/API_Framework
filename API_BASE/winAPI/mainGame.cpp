#include "stdafx.h"
#include "mainGame.h"

//�����ڶ� �Ҹ��ڴ� ���� �ʴ´�..//
mainGame::mainGame()
{

}
//�����ڶ� �Ҹ��ڴ� ���� �ʴ´�..//
mainGame::~mainGame()
{

}
HRESULT mainGame::init(void)	
{
	gameNode::init(true);
	
	IMAGEMANAGER->addImage("�̴ϸ�", "sprites/�ı��� ��׽ý�.bmp", 2788/10, 1110/10, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "sprites/�ı��� ��׽ý�.bmp", 2788, 1110, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������̽�", "sprites/�������̽�.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ĳ����", "sprites/character.bmp", 400, 400, 4, 4, true, RGB(255,0,255));
	_human = IMAGEMANAGER->findImage("ĳ����");
	backStage = IMAGEMANAGER->findImage("��");

	count = 0;
	_index = 0;

	MAN = RectMake(_human->getX(), _human->getY(), _human->getFrameWidth(), _human->getFrameHeight());

	//ó�� ��ġ�� ���� ��� �Ʒ������� �����Ѵ�.
	
	x = mapx = backStage->getWidth()/2 - 450;
	y = mapy = backStage->getHeight() - WINSIZEY;

	_human->setFrameX(0); 
	_human->setX(WINSIZEX / 2);
	_human->setY(WINSIZEY / 2);

	//ó���� �Ʒ����� �����ϴϱ�.......
	left = false, right = false, up = false, down = true;


	return S_OK;
}
void mainGame::release(void)	
{
	gameNode::release();
}
void mainGame::update(void)	
{
	gameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		staywalk = true;
		if (right)
		{
			mapx = backStage->getWidth() - WINSIZEX;
		}
		else
			mapx -= 2;

		if (mapx < 0)
			left = true; //Left������ �ε�����!!!!!!

		if (left)
		{
			mapx = 0; //ī�޶� �� ������ ����� �����ϸ� �ٽ� �������ش�.

			_human->setX(_human->getX() - 2);
			if (_human->getX() < 0)
				_human->setX(_human->getX() + 2); 
		}

		else if (right) //�����ʺ��� �ε��� �����̸�
		{
			_human->setX(_human->getX() - 2);
			if (_human->getX() < WINSIZEX / 2) //ȭ���� ����� �������� �� �̵��ϱ� �����ϸ� ������ ���� Ż��.
				right = false;
		}
		_human->setFrameY(2);

	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		staywalk = false;
		_human->setFrameY(0);

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		staywalk = true;
		if (left)
		{
			mapx = 0;
		}
		else
			mapx += 2;
		
		if (mapx > backStage->getWidth() - WINSIZEX)
			right = true; //Right������ �ε�����!!!!!!

		if (right)
		{
			mapx = backStage->getWidth() - WINSIZEX; //ī�޶� �� ������ ����� �����ϸ� �ٽ� �������ش�.

			_human->setX(_human->getX() + 2);
			if (_human->getX() > WINSIZEX - _human->getFrameWidth())
				_human->setX(_human->getX() - 2); //�Ѹ��� �ʹ����� ���������� �ϸ� ����!!!
		}

		else if (left) //���ʺ��� �ε��� �����̸�
		{
			_human->setX(_human->getX() + 2);
			if (_human->getX() > WINSIZEX / 2) //ȭ���� ����� ���������� �� �̵��ϱ� �����ϸ� ���� ���� Ż��.
				left = false;
		}

		_human->setFrameY(3);
	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		staywalk = false;
		_human->setFrameY(1);
	}


	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (down)
		{
			mapy = backStage->getHeight() - WINSIZEY;
		}
		else
			mapy -= 2;


		if (mapy < 0)
			up = true; //Up������ �ε�����!!!!!!

		if (up)
		{
			mapy = 0; //ī�޶� �� ������ ����� �����ϸ� �ٽ� �������ش�.

			_human->setY(_human->getY() - 2);
			if (_human->getY() < 0)
				_human->setY(_human->getY() + 2); //�Ѹ��� �ʹ����� ���������� �ϸ� ����!!!
		}

		else if (down) //�Ʒ��ʺ��� �ε��� �����̸�
		{
			_human->setY(_human->getY() - 2);
			if (_human->getY() < WINSIZEY / 2) //ȭ���� ����� �������� �� �̵��ϱ� �����ϸ� �Ʒ��� ���� Ż��.
				down = false;

		}
		_human->setFrameY(2);
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (up)
		{
			mapy = 0;
		}
		else
			mapy += 2;

		if (mapy > backStage->getHeight() - WINSIZEY)
			down = true; //Down������ �ε�����!!!!!!

		if (down)
		{
			mapy = backStage->getHeight() - WINSIZEY; //ī�޶� �� ������ ����� �����ϸ� �ٽ� �������ش�.

			_human->setY(_human->getY() + 2);
			if (_human->getY() > WINSIZEY - _human->getFrameHeight())
				_human->setY(_human->getY() - 2); //�Ѹ��� �ʹ����� ���������� �ϸ� ����!!!
		}

		else if (up) //���ʺ��� �ε��� �����̸�
		{
			_human->setY(_human->getY() + 2);
			if (_human->getY() > WINSIZEY / 2) //ȭ���� ����� �Ʒ������� �� �̵��ϱ� �����ϸ� ���� ���� Ż��.
				up = false;
		}
		_human->setFrameY(3);
	}

	count++;

	if (!staywalk)
	{
		if (count % 60 == 0)
		{
			if (_index > _human->getMaxFrameX())_index = 0;
			_human->setFrameX(_index);
			_index++;
		}
	}
	else
		if (count % 25 == 0)
		{
			if (_index > _human->getMaxFrameX())_index = 0;
			_human->setFrameX(_index);
			_index++;
		}
		




}
void mainGame::render(void)
{
	//�ǵ��� ����
	//==================================================//
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================================================//
	//���� �ǵ��� ���� ����Ѵ�~~~//
	
	IMAGEMANAGER->findImage("��")->render(getMemDC(), 0, 0, mapx, mapy, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->findImage("�̴ϸ�")->alphaRender(getMemDC(), 0, 0, 150);
	IMAGEMANAGER->render("�������̽�", getMemDC(), 0, 0);
	_human->frameRender(getMemDC(), _human->getX(), _human->getY(), _human->getFrameX(), _human->getFrameY());
	//�굵 �ǵ��� ����
	//==================================================//
	this->getBackBuffer()->render(getHDC(), 0, 0);
	//==================================================//
	//���� �ǵ��� ���� ����Ѵ�~~~//
}
