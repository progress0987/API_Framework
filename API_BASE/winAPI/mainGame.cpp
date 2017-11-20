#include "stdafx.h"
#include "mainGame.h"

//생성자랑 소멸자는 쓰지 않는당..//
mainGame::mainGame()
{

}
//생성자랑 소멸자는 쓰지 않는당..//
mainGame::~mainGame()
{

}
HRESULT mainGame::init(void)	
{
	gameNode::init(true);
	
	IMAGEMANAGER->addImage("미니맵", "sprites/파괴된 헤네시스.bmp", 2788/10, 1110/10, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("맵", "sprites/파괴된 헤네시스.bmp", 2788, 1110, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("인터페이스", "sprites/인터페이스.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("캐릭터", "sprites/character.bmp", 400, 400, 4, 4, true, RGB(255,0,255));
	_human = IMAGEMANAGER->findImage("캐릭터");
	backStage = IMAGEMANAGER->findImage("맵");

	count = 0;
	_index = 0;

	MAN = RectMake(_human->getX(), _human->getY(), _human->getFrameWidth(), _human->getFrameHeight());

	//처음 위치는 맵의 가운데 아래서부터 시작한다.
	
	x = mapx = backStage->getWidth()/2 - 450;
	y = mapy = backStage->getHeight() - WINSIZEY;

	_human->setFrameX(0); 
	_human->setX(WINSIZEX / 2);
	_human->setY(WINSIZEY / 2);

	//처음에 아래에서 시작하니까.......
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
			left = true; //Left지점에 부딪혔다!!!!!!

		if (left)
		{
			mapx = 0; //카메라가 맵 밖으로 벗어나기 시작하면 다시 조정해준다.

			_human->setX(_human->getX() - 2);
			if (_human->getX() < 0)
				_human->setX(_human->getX() + 2); 
		}

		else if (right) //오른쪽벽에 부딪힌 시점이면
		{
			_human->setX(_human->getX() - 2);
			if (_human->getX() < WINSIZEX / 2) //화면의 가운데서 왼쪽으로 더 이동하기 시작하면 오른쪽 지점 탈출.
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
			right = true; //Right지점에 부딪혔다!!!!!!

		if (right)
		{
			mapx = backStage->getWidth() - WINSIZEX; //카메라가 맵 밖으로 벗어나기 시작하면 다시 조정해준다.

			_human->setX(_human->getX() + 2);
			if (_human->getX() > WINSIZEX - _human->getFrameWidth())
				_human->setX(_human->getX() - 2); //팩맨이 맵밖으로 도망가려고 하면 조정!!!
		}

		else if (left) //왼쪽벽에 부딪힌 시점이면
		{
			_human->setX(_human->getX() + 2);
			if (_human->getX() > WINSIZEX / 2) //화면의 가운데서 오른쪽으로 더 이동하기 시작하면 왼쪽 지점 탈출.
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
			up = true; //Up지점에 부딪혔다!!!!!!

		if (up)
		{
			mapy = 0; //카메라가 맵 밖으로 벗어나기 시작하면 다시 조정해준다.

			_human->setY(_human->getY() - 2);
			if (_human->getY() < 0)
				_human->setY(_human->getY() + 2); //팩맨이 맵밖으로 도망가려고 하면 조정!!!
		}

		else if (down) //아래쪽벽에 부딪힌 시점이면
		{
			_human->setY(_human->getY() - 2);
			if (_human->getY() < WINSIZEY / 2) //화면의 가운데서 위쪽으로 더 이동하기 시작하면 아래쪽 지점 탈출.
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
			down = true; //Down지점에 부딪혔다!!!!!!

		if (down)
		{
			mapy = backStage->getHeight() - WINSIZEY; //카메라가 맵 밖으로 벗어나기 시작하면 다시 조정해준다.

			_human->setY(_human->getY() + 2);
			if (_human->getY() > WINSIZEY - _human->getFrameHeight())
				_human->setY(_human->getY() - 2); //팩맨이 맵밖으로 도망가려고 하면 조정!!!
		}

		else if (up) //위쪽벽에 부딪힌 시점이면
		{
			_human->setY(_human->getY() + 2);
			if (_human->getY() > WINSIZEY / 2) //화면의 가운데서 아래쪽으로 더 이동하기 시작하면 위쪽 지점 탈출.
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
	//건들지 말것
	//==================================================//
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================================================//
	//위에 건들지 마라 경고한다~~~//
	
	IMAGEMANAGER->findImage("맵")->render(getMemDC(), 0, 0, mapx, mapy, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->findImage("미니맵")->alphaRender(getMemDC(), 0, 0, 150);
	IMAGEMANAGER->render("인터페이스", getMemDC(), 0, 0);
	_human->frameRender(getMemDC(), _human->getX(), _human->getY(), _human->getFrameX(), _human->getFrameY());
	//얘도 건들지 말것
	//==================================================//
	this->getBackBuffer()->render(getHDC(), 0, 0);
	//==================================================//
	//위에 건들지 마라 경고한다~~~//
}
