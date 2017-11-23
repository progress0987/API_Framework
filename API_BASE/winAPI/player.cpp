#include "stdafx.h"
#include "player.h"
#include "enemyManager.h"


HRESULT player::init(void)
{
	IMAGEMANAGER->addImage("�̴ϸ�", "�ı��� ��׽ý�.bmp", 1951 / 10, 1024 / 10, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "�������(����).bmp", 1951, 1024, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "�������.bmp", 1951, 1024, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������̽�", "�������̽�.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ĳ����", "character.bmp", 400, 1000, 4, 10, true, RGB(255, 0, 255));
	_human = IMAGEMANAGER->findImage("ĳ����");
	backStage = IMAGEMANAGER->findImage("��");

	count = 0;
	_index = 0;

	//ó�� ��ġ�� ���� ��� �Ʒ������� �����Ѵ�.

	mapx = backStage->getWidth() / 2 - 450;
	mapy = backStage->getHeight() - WINSIZEY;

	_human->setFrameX(0);
	_human->setX(WINSIZEX / 2);
	_human->setY(WINSIZEY / 2);

	//ó���� �Ʒ����� �����ϴϱ�.......
	left = false, right = false, up = false, down = true;

	//���κ� ����
	pl = _human->getCenterX() - _human->getFrameWidth() / 2;
	pr = _human->getCenterX() + _human->getFrameWidth() / 2;

	//�̹����� ���� ������� -10�� �߰��� ��������.
	pb = _human->getY() + _human->getFrameHeight() - 10;
	pu = _human->getY();

	return S_OK;
}

void player::release(void)
{
}

void player::update(void)
{

	//���� ó�� �߷°����� ó�����ش�.
	//�߷°��� �ƹ��͵� �Է����� �ʾƵ� �⺻������ �ۿ��ϱ� ����.
	//�߷��� ���� ������ ���¿����� �ۿ����� �ʵ��� �Ѵ�.

	if (!onLand)
	{
		if (velocity > 20)
			velocity = 20;
		else
			velocity += gravity;

		_human->setY(_human->getY() + velocity);
	}


	//�� ���Ŀ� ���ۿ� ���� ��� ó��.
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		onlope = false;
		onladder = false;
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
				_human->setX(_human->getX() + 2); //�Ѹ��� �ʹ����� ���������� �ϸ� ����!!!
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
		onlope = false;
		onladder = false;
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

		if (_human->getFrameY() == 0 || _human->getFrameY() == 2) //���� ĳ���Ͱ� ������ �ٶ󺸰� �־��ٸ�
			_human->setFrameY(4);
		else if (_human->getFrameY() == 1 || _human->getFrameY() == 3) // ���� ĳ���Ͱ� �������� �ٶ󺸰� �־��ٸ�
			_human->setFrameY(5);
	}

	//�Ʒ� Ű�� ������. ->���� ����ȴٰ� �Ͼ�� ��ǿ��� �ۿ�.
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		//�Ͼ�� ���ó��.
		//��, ��ٸ��� �Ŵ޷� �ְų�, �����߿��� �� Ŀ�ǵ带 ó���ϸ� �ȵȴ�.
		if (!onlope && !onladder && !onJump)
			if (_human->getFrameY() == 4) //���� ĳ���Ͱ� ������ �ٶ󺸰� �־��ٸ�
				_human->setFrameY(0);
			else if (_human->getFrameY() == 5) // ���� ĳ���Ͱ� �������� �ٶ󺸰� �־��ٸ�
				_human->setFrameY(1);

	}

	

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		onLand = false;
		onJump = true;
	}

	if (onJump)
	{
		velocity = 0;
		velocity += lift;

		onJump = false;
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



	//���κ� �ǽð� ����
	pl = _human->getCenterX() - _human->getFrameWidth() / 2;
	pr = _human->getCenterX() + _human->getFrameWidth() / 2;
	//�̹����� ���� ������� -10�� �߰��� ��������.
	pb = _human->getY() + _human->getFrameHeight() - 10;
	pu = _human->getY();


	//�ٴڰ��� ������ �Ʒ��� ���� 
	if (!onLand)
	{
		for (int i = pb; i < pb + 1; ++i)
		{
			//�ȼ� �������� �����ͼ� �÷� ���۷����� ����

			COLORREF color = GetPixel(IMAGEMANAGER->findImage("����")->getMemDC(), mapx + _human->getCenterX(), mapy + i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//���߿� �ִ°� �ƴѰ��. �Ŵ޸��ų� ������ ���.
			if ((r == 255 && g == 0 && b == 0))
			{
				//-1�� ����� �����Ÿ����ʴ´�. -2���� �����Ÿ���.
				_human->setY(i - _human->getFrameHeight() - 1);
				velocity = 0;
				onJump = false;
				onLand = true;
				break;
				//����� -1 �����ָ� ���� ������������ �İ�� ���������´�. 
				//���� ���������� ���� ������.
			}
		}
	}

}

void player::render(void)
{

	//IMAGEMANAGER->render("��", getMemDc(), 0, 0, mapx, mapy, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->render("����", getMemDC(), 0, 0, mapx, mapy, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->alphaRender("�̴ϸ�", getMemDC(), 0, 0, 150);
	IMAGEMANAGER->render("�������̽�", getMemDC(), 0, 0);
	EllipseMakeCenter(getMemDC(), _human->getCenterX(), pb, 10, 10);
	_human->frameRender(getMemDC(), _human->getX(), _human->getY() + 10, _human->getFrameX(), _human->getFrameY());
}


//ĳ���͸� �����ִ� ī�޶� �Լ�. �������� �����Լ� �κп��� ó��.
//�������� ĳ������ǥ������ �޾Ƽ� mapx, mapy�� �������ش�.
void player::camera(int dir, image *character)
{

}

player::player()
{
}


player::~player()
{
}
