#include "stdafx.h"
#include "player.h"
#include "enemyManager.h"


HRESULT player::init(void)
{
	IMAGEMANAGER->addImage("미니맵", "파괴된 헤네시스.bmp", 1951 / 10, 1024 / 10, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("맵", "파헤공원(원본).bmp", 1951, 1024, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지형", "파헤공원.bmp", 1951, 1024, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("인터페이스", "인터페이스.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("캐릭터", "character.bmp", 400, 1000, 4, 10, true, RGB(255, 0, 255));
	_human = IMAGEMANAGER->findImage("캐릭터");
	backStage = IMAGEMANAGER->findImage("맵");

	count = 0;
	_index = 0;

	MAN = RectMake(_human->getX(), _human->getY(), _human->getFrameWidth(), _human->getFrameHeight());

	//처음 위치는 맵의 가운데 아래서부터 시작한다.

	mapx = backStage->getWidth() / 2 - 450;
	mapy = backStage->getHeight() - WINSIZEY;

	_human->setFrameX(0);
	_human->setX(WINSIZEX / 2);
	_human->setY(WINSIZEY / 2);

	//처음에 아래에서 시작하니까.......
	left = false, right = false, up = false, down = true;

	//프로브 설정
	pl = _human->getCenterX() - _human->getFrameWidth() / 2;
	pr = _human->getCenterX() + _human->getFrameWidth() / 2;

	//이미지상 보기 좋으라고 -10을 추가로 보정해줌.
	pb = _human->getY() + _human->getFrameHeight() - 10;
	pu = _human->getY();

	return S_OK;
}

void player::release(void)
{
}

void player::update(void)
{
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
			left = true; //Left지점에 부딪혔다!!!!!!

		if (left)
		{
			mapx = 0; //카메라가 맵 밖으로 벗어나기 시작하면 다시 조정해준다.

			_human->setX(_human->getX() - 2);
			if (_human->getX() < 0)
				_human->setX(_human->getX() + 2); //팩맨이 맵밖으로 도망가려고 하면 조정!!!
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

		if (_human->getFrameY() == 0 || _human->getFrameY() == 2) //만약 캐릭터가 왼쪽을 바라보고 있었다면
			_human->setFrameY(4);
		else if (_human->getFrameY() == 1 || _human->getFrameY() == 3) // 만약 캐릭터가 오른쪽을 바라보고 있었다면
			_human->setFrameY(5);
	}

	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		if (_human->getFrameY() == 4) //만약 캐릭터가 왼쪽을 바라보고 있었다면
			_human->setFrameY(0);
		else if (_human->getFrameY() == 5) // 만약 캐릭터가 오른쪽을 바라보고 있었다면
			_human->setFrameY(1);
	}


	if (KEYMANAGER->isStayKeyDown(VK_MENU))
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

	if (KEYMANAGER->isOnceKeyUp(VK_MENU))
	{

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



	//프로브 실시간 보정
	pl = _human->getCenterX() - _human->getFrameWidth() / 2;
	pr = _human->getCenterX() + _human->getFrameWidth() / 2;
	//이미지상 보기 좋으라고 -10을 추가로 보정해줌.
	pb = _human->getY() + _human->getFrameHeight() - 10;
	pu = _human->getY();

	//바닥검출 범위는 아래와 같이 
	for (int i = pb; i < pb + 10; ++i)
	{
		//픽셀 정보값을 가져와서 컬러 레퍼런스에 담자

		COLORREF color = GetPixel(IMAGEMANAGER->findImage("지형")->getMemDC(), mapx + _human->getCenterX(), mapy + i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 255 && b == 255))
		{
			//-1을 해줘야 덜덜거리지않는다. -2부터 덜덜거린다.
			_human->setY(i - _human->getFrameHeight() - 1);
			break;
			//참고로 -1 안해주면 발이 빨간색지형에 파고들어서 못빠져나온다. 
			//점점 지형속으로 쑤욱 들어가버려.
		}
	}

}

void player::render(void)
{

	//IMAGEMANAGER->render("맵", getMemDc(), 0, 0, mapx, mapy, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->render("지형", getMemDC(), 0, 0, mapx, mapy, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->alphaRender("미니맵", getMemDC(), 0, 0, 150);
	IMAGEMANAGER->render("인터페이스", getMemDC(), 0, 0);
	EllipseMakeCenter(getMemDC(), _human->getCenterX(), pb, 10, 10);
	_human->frameRender(getMemDC(), _human->getX(), _human->getY() + 10, _human->getFrameX(), _human->getFrameY());
}


//캐릭터를 비춰주는 카메라 함수. 렌더링은 렌더함수 부분에서 처리.
//진행방향과 캐릭터좌표정보를 받아서 mapx, mapy를 조정해준다.
void camera(int dir, image *character)
{

}

player::player()
{
}


player::~player()
{
}
