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
HRESULT monster::init(int Hp, int Atk, int Def,POINT position, int Width, int height)
{
	MaxHp = Hp;
	NowHp = MaxHp;
	this->Atk = Atk;
	this->Def = Def;
	body = RectMakeCenter(position.x, position.y, Width, height);
	return S_OK;
}
//각각 몬스터에서 공격력 가져오기
int monster::getAtk(void)
{
	return Atk;
}
//각각 몬스터에서 몬스터 데미지
void monster::SubHp(int atk)
{
	NowHp -= atk - Def;
}
//체력이 0인지 확인
bool monster::ZeroHp(void)
{
	if (NowHp > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
//공격을 받았는지 확인
bool monster::hit(void)
{
	if (NowHp != MaxHp)
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
	body.left += move;
	body.right += move;
}
void monster::MonsterDown(int Down)
{
	body.top -= Down;
	body.bottom -= Down;
}
//왼쪽 오른쪽 설정
void monster::left(int way)
{
	if (way == 0)
	{
		Left = true;
	}
	else
	{
		Left = false;
	}
}
//왼쪽으로 가는지 확인하기
bool monster::way(void)
{
	if (Left == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void monster::Setbody(int i)
{
	int Num;
	Num = body.bottom - body.top;
	body.bottom = i;
	body.top = body.bottom - Num;
}
RECT monster::Base(void)
{
	return body;
}
//Harp의 관리 클래스
Harp::Harp()
{
}

Harp::~Harp()
{
}

HRESULT Harp::init(void)
{
	IMAGEMANAGER->addFrameImage("harpM", "image/HarpM.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpS", "image/HarpS.bmp", 486, 206, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harpD", "image/HarpD.bmp", 81, 206, 1, 2, true, RGB(255, 0, 255));
	harp = new monster;
	harp->init(500, 30, 10, generator, 81, 103);
	int way = rand() % 2;
	harp->left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	return S_OK;
}

void Harp::moving(void)
{
	//왼쪽으로 가는 몬스터
	Timer++;
	if (Timer % 10 == 0)
	{
		if (hit == false)
		{
			fream++;
			if (harp->ZeroHp() == false)
			{
				if (Stay == true)
				{
					if (IMAGEMANAGER->findImage("harpS")->getMaxFrameX() == fream)
					{
						MoveTime--;
						if (MoveTime == 0)
						{
							MoveTime = rand() % 4 + 2;
							Stay = false;
							int way = rand() % 2;
							harp->left(way);
						}
						fream = 0;
					}
				}
				else if (Stay == false)
				{
					if (IMAGEMANAGER->findImage("harpM")->getMaxFrameX() == fream)
					{
						MoveTime--;
						if (MoveTime == 0)
						{
							MoveTime = rand() % 3 + 2;
							Stay = true;
							int way = rand() % 2;
							harp->left(way);
						}
						fream = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("harpD")->getMaxFrameX() < fream)
				{
					fream--;
				}
			}
		}
		else if (hit == true)
		{
			HitTimer--;
			if (HitTimer == 0)
			{
				hit = false;
			}
		}
	}
	if (harp->way() == true)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (Stay == false)
		{
			int pixel = harp->Base().bottom;
			for (int i = pixel - 5; i < pixel + 5; i++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("map")->getMemDC(), harp->Base().left + (harp->Base().right - harp->Base().left) / 2, i);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if ((r == 255 & g == 0 && b == 0))
				{
					harp->MonsterMoving(-3);
					harp->Setbody(i);
					break;
				}
				else if (!(r == 255 & g == 0 && b == 0) && i == pixel + 4)
				{
					harp->MonsterDown(-3);
					if (harp->way() == true)
					{
						COLORREF color = GetPixel(IMAGEMANAGER->findImage("map")->getMemDC(), harp->Base().left + (harp->Base().right - harp->Base().left) / 2 - 20, i);
						int r1 = GetRValue(color);
						int g1 = GetGValue(color);
						int b1 = GetBValue(color);
						if (!(r1 == 255 && g1 == 0 && b1 == 0))
						{
							harp->left(1);
						}
					}
				}
			}
		}
	}
	else
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (Stay == false)
		{
			int pixel = harp->Base().bottom;
			for (int i = pixel - 5; i < pixel + 5; i++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("map")->getMemDC(), harp->Base().left + (harp->Base().right - harp->Base().left) / 2, i);
				
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if ((r == 255 & g == 0 && b == 0))
				{
					harp->Setbody(i);
					harp->MonsterMoving(3);
					break;
				}
				else if (!(r == 255 & g == 0 && b == 0) && i == pixel + 4)
				{
					harp->MonsterDown(-3);
					if (harp->way() == false)
					{
						COLORREF color = GetPixel(IMAGEMANAGER->findImage("map")->getMemDC(), harp->Base().left + (harp->Base().right - harp->Base().left) / 2 + 20, i);
						int r1 = GetRValue(color);
						int g1 = GetGValue(color);
						int b1 = GetBValue(color);
						if (!(r1 == 255 && g1 == 0 && b1 == 0))
						{
							harp->left(0);
						}
					}
				}
			}
		}
	}
}

int Harp::getAtk(void)
{
	return harp->getAtk();
}

void Harp::SubHp(int Atk)
{
	harp->SubHp(Atk);
	hit = true;
	HitTimer = 6;
	fream = 0;
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
	if (harp->way() == true)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (hit == true)
		{
			IMAGEMANAGER->findImage("harpD")->frameRender(getMemDC(), harp->Base().left, harp->Base().top, 0, 0);
		}
		if (harp->ZeroHp() == true)
		{
			IMAGEMANAGER->findImage("harpD")->frameRender(getMemDC(), harp->Base().left, harp->Base().top, fream, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("harpM")->frameRender(getMemDC(), harp->Base().left, harp->Base().top, fream, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("harpS")->frameRender(getMemDC(), harp->Base().left, harp->Base().top, fream, 0);
		}
	}
	else if(harp->way()==false)
	{
		if (hit == true)
		{
			IMAGEMANAGER->findImage("harpD")->frameRender(getMemDC(), harp->Base().left, harp->Base().top, 0, 1);
		}
		if (harp->ZeroHp() == true)
		{
			IMAGEMANAGER->findImage("harpD")->frameRender(getMemDC(), harp->Base().left, harp->Base().top, fream, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("harpM")->frameRender(getMemDC(), harp->Base().left, harp->Base().top, fream, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("harpS")->frameRender(getMemDC(), harp->Base().left, harp->Base().top, fream, 1);
		}
	}
}

void Harp::SetPoint(POINT position)
{
	generator = position;
}
