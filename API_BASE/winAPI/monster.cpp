#include "stdafx.h"
#include "monster.h"

//몬스터의 기본 구조 클래스
monster::monster()
{
}


monster::~monster()
{
}
//각각 몬스터에서 설정하기
HRESULT monster::init(int Hp, int Atk, int Def, POINT position, int Width, int height)
{
	MaxHp = Hp;
	NowHp = MaxHp;
	this->Atk = Atk;
	this->Def = Def;
	pt = position;
	bodyW = Width;
	bodyH = height;
	body = RectMakeCenter(position.x, position.y, Width, height);
	return S_OK;
}

//공격을 받았는지 확인
bool monster::hit(void)
{
	if (NowHp >= MaxHp)
	{
		return false;
	}
	else
	{
		return true;
	}
}
//몬스터 움직이는거(렉트를 움직입니다)
void monster::MonsterMoving(int move)
{
	pt.x += move;
	if (pt.x - bodyW / 2 < 0) pt.x = bodyW / 2;
	//현재 맵 지정 - 나중에 바꿔줘야함
	if (pt.x + bodyW / 2 > IMAGEMANAGER->findImage("map")->getWidth()) pt.x = IMAGEMANAGER->findImage("map")->getWidth() - bodyW / 2;
}
void monster::MonsterDown(int Down)
{
	pt.y += Down;
	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
}
//왼쪽 오른쪽 설정(0 = 오른쪽)
void monster::left(int way)
{
	if (way == 0)
	{
		moveDir = true;
	}
	else
	{
		moveDir = false;
	}
}

void monster::Setbody(int i)
{
	int Num;
	Num = body.bottom - body.top;
	body.bottom = i;
	body.top = body.bottom - Num;
}
Harp::Harp()
{
}

Harp::~Harp()
{
}

HRESULT Harp::init(POINT pos)
{
	IMAGEMANAGER->addFrameImage("harpM", "sprites/monster/HarpM.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpS", "sprites/monster/HarpS.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpD", "sprites/monster/HarpD.bmp", 81, 206, 1, 2, true, RGB(255, 0, 255));
	monster::init(500, 30, 10, pos, 81, 103);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	return S_OK;
}

void Harp::moving(void)
{
	Timer++;

	if (Timer % 10 == 0)
	{
		if (hit == false)
		{
			frame++;
			if (NowHp>0)
			{
				if (Stay == true)
				{
					if (IMAGEMANAGER->findImage("harpS")->getMaxFrameX() == frame)
					{
						MoveTime--;
						if (MoveTime == 0)
						{
							MoveTime = rand() % 4 + 2;
							Stay = false;
							int way = rand() % 2;
							left(way);
						}
						frame = 0;
					}
				}
				else if (Stay == false)
				{
					if (IMAGEMANAGER->findImage("harpM")->getMaxFrameX() == frame)
					{
						MoveTime--;
						if (MoveTime == 0)
						{
							if (NowHp >= MaxHp)
							{
								MoveTime = rand() % 3 + 2;
								Stay = true;
								int way = rand() % 2;
								left(way);
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("harpD")->getMaxFrameX() < frame)
				{
					frame--;
				}
			}
		}
		else if (hit == true)
		{

			if (NowHp>0)
			{
				HitTimer--;
			}
			else if (NowHp <= 0)
			{
				if (alpha != 0)
				{
					alpha -= 50;
				}
			}
			if (HitTimer == 0)
			{
				hit = false;
			}
		}
	}
	//왼쪽으로 가는 몬스터
	if (moveDir == false)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp>0 && Stay == false)
		{
			int pixel = body.bottom;
			for (int i = pixel - 5; i < pixel + 5; i++)
			{
				if (hit == true)
				{
					break;
				}
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("맵")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-3);
					Setbody(i);
					if (moveDir == true)
					{
						COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("맵")->getMemDC(), pt.x - 10, i + 30);
						COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("맵")->getMemDC(), pt.x - 10, i - 30);
						if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
						{
							left(1);
						}
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(3);
				}
			}
		}
	}
	//오른쪽으로 가는 몬스터
	else
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp>0 && Stay == false)
		{

			int pixel = body.bottom;
			for (int i = pixel - 5; i < pixel + 5; i++)
			{
				if (hit == true)
				{
					break;
				}
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("맵")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(3);
					if (moveDir == false)
					{
						COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("맵")->getMemDC(), pt.x, i + 30);
						COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("맵")->getMemDC(), pt.x, i - 30);
						if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
						{
							left(0);
						}
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(3);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}

void Harp::SubHp(int Atk)
{
	SubHp(Atk);
	hit = true;
	HitTimer = 6;
	frame = 0;
	if (moveDir == true)
	{
		MonsterMoving(5);
	}
	else
	{
		MonsterMoving(-5);
	}
}

void Harp::dead(void)
{

}

void Harp::update(void)
{
	moving();
}

void Harp::render(void)
{
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("harpD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("harpD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("harpM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("harpS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("harpD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("harpD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("harpM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("harpS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}



void Harp::collRect(RECT player, int demage)
{
	RECT rc;
	if (hit == false)
	{
		if (IntersectRect(&rc, &player, &body))
		{
			SubHp(demage);
		}
	}
}
