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
	for (int i = 0; i < 4; i++)
	{
		SkillTwoRect[i] = { 0,0,0,0 };
	}
	return S_OK;
}

void monster::update()
{
}

void monster::render()
{
}

void monster::collRect(RECT player, int demage)
{
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
	if (MyIndex == 2)
	{
		if (pt.x - bodyW / 2 < 0) pt.x = bodyW / 2;
		//현재 맵 지정 - 나중에 바꿔줘야함
		if (pt.x + bodyW / 2 > IMAGEMANAGER->findImage("pixelpark")->getWidth()) pt.x = IMAGEMANAGER->findImage("pixelpark")->getWidth() - bodyW / 2;
	}
	if (MyIndex == 3)
	{
		if (pt.x - bodyW / 2 < 0) pt.x = bodyW / 2;
		//현재 맵 지정 - 나중에 바꿔줘야함
		if (pt.x + bodyW / 2 > IMAGEMANAGER->findImage("pixelmarket")->getWidth()) pt.x = IMAGEMANAGER->findImage("pixelmarket")->getWidth() - bodyW / 2;
	}
	if (MyIndex == 4)
	{
		if (pt.x - bodyW / 2 < 0) pt.x = bodyW / 2;
		//현재 맵 지정 - 나중에 바꿔줘야함
		if (pt.x + bodyW / 2 > IMAGEMANAGER->findImage("pixelhill")->getWidth()) pt.x = IMAGEMANAGER->findImage("pixelhill")->getWidth() - bodyW / 2;
	}
	if (MyIndex == 5)
	{
		if (pt.x - bodyW / 2 < 0) pt.x = bodyW / 2;
		//현재 맵 지정 - 나중에 바꿔줘야함
		if (pt.x + bodyW / 2 > IMAGEMANAGER->findImage("pixelforest")->getWidth()) pt.x = IMAGEMANAGER->findImage("pixelforest")->getWidth() - bodyW / 2;
	}
	if (MyIndex == 6)
	{
		if (pt.x - bodyW / 2 < 0) pt.x = bodyW / 2;
		//현재 맵 지정 - 나중에 바꿔줘야함
		if (pt.x + bodyW / 2 > IMAGEMANAGER->findImage("pixelboss")->getWidth()) pt.x = IMAGEMANAGER->findImage("pixelboss")->getWidth() - bodyW / 2;
	}
}
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
void monster::SharePlayer(RECT PlayerBase)
{
	playerBody = PlayerBase;
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
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("harpM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 81, 103);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 2;
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
					if (IMAGEMANAGER->findImage("harpS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("harpM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x - 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x - 12, i - 3);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x + 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x + 12, i - 3);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}
void Harp::SubHp(int Atk)
{
	NowHp -= Atk;
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
	if (ZeroHp() == true)
	{
		if (Timer % 10 == 0)
		{
			Gentime--;
			if (Gentime == 0)
			{
				pt = GenPoint;
				NowHp = MaxHp;
				Gentime = 50;
				alpha = 250;
				hit = false;
			}
		}
	}
}
void Harp::update(void)
{
	moving();
	dead();
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
	//	Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
//	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
//	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
//	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
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


Grupin::Grupin()
{
}
Grupin::~Grupin()
{
}
HRESULT Grupin::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("GrupinM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 60, 63);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 4;
	return S_OK;
}
void Grupin::moving(void)
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
					if (IMAGEMANAGER->findImage("GrupinS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("GrupinM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("GrupinD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("GrupinD")->getMaxFrameX())
				{
				frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x - 12, i + 5);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x - 12, i - 5);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x + 12, i + 5);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x + 12, i - 5);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}
void Grupin::SubHp(int Atk)
{
	NowHp -= Atk;
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
void Grupin::dead(void)
{

}
void Grupin::update(void)
{
	moving();
}
void Grupin::render(void)
{
//	Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("GrupinD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("GrupinD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("GrupinM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("GrupinS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("GrupinD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("GrupinD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("GrupinM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("GrupinS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void Grupin::collRect(RECT player, int demage)
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


Cellion::Cellion()
{
}
Cellion::~Cellion()
{
}
HRESULT Cellion::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("CellionM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 60, 63);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 4;
	return S_OK;
}
void Cellion::moving(void)
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
					if (IMAGEMANAGER->findImage("CellionS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("CellionM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("CellionD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("CellionD")->getMaxFrameX())
				{
					frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x - 12, i + 5);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x - 12, i - 5);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x + 12, i + 5);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x + 12, i - 5);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}
void Cellion::SubHp(int Atk)
{
	NowHp -= Atk;
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
void Cellion::dead(void)
{

}
void Cellion::update(void)
{
	moving();
}
void Cellion::render(void)
{
//	Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("CellionD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("CellionD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("CellionM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("CellionS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("CellionD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("CellionD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("CellionM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("CellionS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void Cellion::collRect(RECT player, int demage)
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


Lioner::Lioner()
{
}
Lioner::~Lioner()
{
}
HRESULT Lioner::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("LionerM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 60, 63);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 4;
	return S_OK;
}
void Lioner::moving(void)
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
					if (IMAGEMANAGER->findImage("LionerS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("LionerM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("LionerD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("LionerD")->getMaxFrameX())
				{
					frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x - 12, i + 5);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x - 12, i - 5);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x + 12, i + 5);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelhill")->getMemDC(), pt.x + 12, i - 5);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}
void Lioner::SubHp(int Atk)
{
	NowHp -= Atk;
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
void Lioner::dead(void)
{

}
void Lioner::update(void)
{
	moving();
}
void Lioner::render(void)
{
//	Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("LionerD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("LionerD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("LionerM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("LionerS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("LionerD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("LionerD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("LionerM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("LionerS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void Lioner::collRect(RECT player, int demage)
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


Lucida::Lucida()
{
}
Lucida::~Lucida()
{
}
HRESULT Lucida::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("LucidaM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 62, 84);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 6;
	return S_OK;
}
void Lucida::moving(void)
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
					if (IMAGEMANAGER->findImage("LucidaS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("LucidaM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("LucidaD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("LucidaD")->getMaxFrameX())
				{
					frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x - 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x - 12, i - 3);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x + 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x + 12, i - 3);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}
void Lucida::SubHp(int Atk)
{
	NowHp -= Atk;
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
void Lucida::dead(void)
{

}
void Lucida::update(void)
{
	moving();
}
void Lucida::render(void)
{
	//Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("LucidaD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("LucidaD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("LucidaM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("LucidaS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("LucidaD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("LucidaD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("LucidaM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("LucidaS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void Lucida::collRect(RECT player, int demage)
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


JrYeti::JrYeti()
{
}
JrYeti::~JrYeti()
{
}
HRESULT JrYeti::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("Jr YetiM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 39, 40);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 3;
	return S_OK;
}
void JrYeti::moving(void)
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
					if (IMAGEMANAGER->findImage("Jr YetiS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("Jr YetiM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("Jr YetiD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("Jr YetiD")->getMaxFrameX())
				{
					frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x - 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x - 12, i - 3);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x + 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x + 12, i - 3);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	if (moveDir)
	{
		colBody = RectMakeCenter(pt.x - cam->camPoint.x - 25, pt.y - cam->camPoint.y, bodyW, bodyH);
	}
	else
	{
		colBody = RectMakeCenter(pt.x - cam->camPoint.x+50, pt.y - cam->camPoint.y, bodyW, bodyH);
	}
}
void JrYeti::SubHp(int Atk)
{
	NowHp -= Atk;
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
void JrYeti::dead(void)
{

}
void JrYeti::update(void)
{
	moving();
}
void JrYeti::render(void)
{
//	Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("Jr YetiD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x-25, body.top - cam->camPoint.y-23, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("Jr YetiD")->frameRender(getMemDC(), body.left - cam->camPoint.x-25, body.top - cam->camPoint.y-23, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("Jr YetiM")->frameRender(getMemDC(), body.left - cam->camPoint.x-25, body.top - cam->camPoint.y-23, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("Jr YetiS")->frameRender(getMemDC(), body.left - cam->camPoint.x-25, body.top - cam->camPoint.y-23, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("Jr YetiD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x+25, body.top - cam->camPoint.y-23, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("Jr YetiD")->frameRender(getMemDC(), body.left - cam->camPoint.x+25, body.top - cam->camPoint.y-23, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("Jr YetiM")->frameRender(getMemDC(), body.left - cam->camPoint.x+25, body.top - cam->camPoint.y-23, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("Jr YetiS")->frameRender(getMemDC(), body.left - cam->camPoint.x+25, body.top - cam->camPoint.y-23, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void JrYeti::collRect(RECT player, int demage)
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


PePe::PePe()
{
}
PePe::~PePe()
{
}
HRESULT PePe::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("PePeM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 73, 63);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 3;
	return S_OK;
}
void PePe::moving(void)
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
					if (IMAGEMANAGER->findImage("PePeS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("PePeM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("PePeD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("PePeD")->getMaxFrameX())
				{
					frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x - 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x - 12, i - 3);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x + 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelmarket")->getMemDC(), pt.x + 12, i - 3);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
		colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}
void PePe::SubHp(int Atk)
{
	NowHp -= Atk;
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
void PePe::dead(void)
{

}
void PePe::update(void)
{
	moving();
}
void PePe::render(void)
{
//	Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("PePeD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x , body.top - cam->camPoint.y-20 , frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("PePeD")->frameRender(getMemDC(), body.left - cam->camPoint.x , body.top - cam->camPoint.y-20 , 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("PePeM")->frameRender(getMemDC(), body.left - cam->camPoint.x , body.top - cam->camPoint.y-20 , frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("PePeS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y-20, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("PePeD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x , body.top - cam->camPoint.y-20 , frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("PePeD")->frameRender(getMemDC(), body.left - cam->camPoint.x , body.top - cam->camPoint.y-20 , 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("PePeM")->frameRender(getMemDC(), body.left - cam->camPoint.x , body.top - cam->camPoint.y-20, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("PePeS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y-20, frame, 0);
		}
	}
//	Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void PePe::collRect(RECT player, int demage)
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

Sheep::Sheep()
{
}
Sheep::~Sheep()
{
}
HRESULT Sheep::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("SheepM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 92, 61);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 2;
	return S_OK;
}
void Sheep::moving(void)
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
					if (IMAGEMANAGER->findImage("SheepS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("SheepM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("SheepD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("SheepD")->getMaxFrameX())
				{
					frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x - 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x - 12, i - 3);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x + 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelpark")->getMemDC(), pt.x + 12, i - 3);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}
void Sheep::SubHp(int Atk)
{
	NowHp -= Atk;
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
void Sheep::dead(void)
{

}
void Sheep::update(void)
{
	moving();
}
void Sheep::render(void)
{
	//Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("SheepD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("SheepD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("SheepM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("SheepS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("SheepD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("SheepD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("SheepM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("SheepS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void Sheep::collRect(RECT player, int demage)
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

JCellion::JCellion()
{
}
JCellion::~JCellion()
{
}
HRESULT JCellion::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("JCellionM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 43, 47);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 5;
	return S_OK;
}
void JCellion::moving(void)
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
					if (IMAGEMANAGER->findImage("JCellionS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("JCellionM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("JCellionD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("JCellionD")->getMaxFrameX())
				{
					frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x - 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x - 12, i - 3);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x + 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x + 12, i - 3);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}
void JCellion::SubHp(int Atk)
{
	NowHp -= Atk;
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
void JCellion::dead(void)
{

}
void JCellion::update(void)
{
	moving();
}
void JCellion::render(void)
{
	//Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("JCellionD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("JCellionD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("JCellionM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("JCellionS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("JCellionD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("JCellionD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("JCellionM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("JCellionS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void JCellion::collRect(RECT player, int demage)
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


JGrupin::JGrupin()
{
}
JGrupin::~JGrupin()
{
}
HRESULT JGrupin::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("JGrupinM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 43, 47);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 5;
	return S_OK;
}
void JGrupin::moving(void)
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
					if (IMAGEMANAGER->findImage("JGrupinS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("JGrupinM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("JGrupinD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("JGrupinD")->getMaxFrameX())
				{
					frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x - 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x - 12, i - 3);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x + 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x + 12, i - 3);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}
void JGrupin::SubHp(int Atk)
{
	NowHp -= Atk;
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
void JGrupin::dead(void)
{

}
void JGrupin::update(void)
{
	moving();
}
void JGrupin::render(void)
{
	//Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("JGrupinD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("JGrupinD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("JGrupinM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("JGrupinS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("JGrupinD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("JGrupinD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("JGrupinM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("JGrupinS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void JGrupin::collRect(RECT player, int demage)
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


JLioner::JLioner()
{
}
JLioner::~JLioner()
{
}
HRESULT JLioner::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("JLionerM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 43, 47);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 5;
	return S_OK;
}
void JLioner::moving(void)
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
					if (IMAGEMANAGER->findImage("JLionerS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("JLionerM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("JLionerD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("JLionerD")->getMaxFrameX())
				{
					frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x - 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x - 12, i - 3);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x + 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelforest")->getMemDC(), pt.x + 12, i - 3);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}
void JLioner::SubHp(int Atk)
{
	NowHp -= Atk;
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
void JLioner::dead(void)
{

}
void JLioner::update(void)
{
	moving();
}
void JLioner::render(void)
{
	//Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("JLionerD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("JLionerD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("JLionerM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("JLionerS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("JLionerD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("JLionerD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("JLionerM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("JLionerS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void JLioner::collRect(RECT player, int demage)
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


JLucida::JLucida()
{
}
JLucida::~JLucida()
{
}
HRESULT JLucida::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("JLucidaM")->getHeight() / 4;
	monster::init(500, 30, 10, GenPoint, 45, 57);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	MyIndex = 6;
	return S_OK;
}
void JLucida::moving(void)
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
					if (IMAGEMANAGER->findImage("JLucidaS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("JLucidaM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("JLucidaD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("JLucidaD")->getMaxFrameX())
				{
					frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-1);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x - 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x - 12, i - 3);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(1);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x + 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x + 12, i - 3);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
					}
					break;
				}
				else if (color != RGB(255, 0, 0) && i == pixel + 4)
				{
					MonsterDown(1);
				}
			}
		}
	}

	body = RectMakeCenter(pt.x, pt.y, bodyW, bodyH);
	colBody = RectMakeCenter(pt.x - cam->camPoint.x, pt.y - cam->camPoint.y, bodyW, bodyH);
}
void JLucida::SubHp(int Atk)
{
	NowHp -= Atk;
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
void JLucida::dead(void)
{

}
void JLucida::update(void)
{
	moving();
}
void JLucida::render(void)
{
	//Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("JLucidaD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("JLucidaD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("JLucidaM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("JLucidaS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("JLucidaD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("JLucidaD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("JLucidaM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("JLucidaS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void JLucida::collRect(RECT player, int demage)
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

Eliza::Eliza()
{
}
Eliza::~Eliza()
{
}
HRESULT Eliza::init(POINT pos)
{
	GenPoint.x = pos.x;
	GenPoint.y = pos.y - IMAGEMANAGER->findImage("ElizaM")->getHeight() / 4;
	monster::init(3000, 30, 10, GenPoint, 200, 161);
	int way = rand() % 2;
	left(way);
	Stay = true;
	MoveTime = rand() % 3 + 2;
	hit = false;
	HitTimer = 0;
	SkillOne = false;
	SkillTwo = false;
	MyIndex = 6;
	return S_OK;
}
void Eliza::moving(void)
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
					if (IMAGEMANAGER->findImage("ElizaS")->getMaxFrameX() < frame)
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
					if (IMAGEMANAGER->findImage("ElizaM")->getMaxFrameX() < frame)
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
							else
							{
								MoveTime = rand() % 2 + 1;
								if (playerBody.right < body.left&&playerBody.left > body.right)
								{
									int way = rand() % 2;
									left(way);
								}
								else if (playerBody.right < body.right)
								{
									left(1);
								}
								else if (playerBody.left > body.left)
								{
									left(0);
								}
							}
						}
						frame = 0;
					}
				}
			}
			else
			{
				if (IMAGEMANAGER->findImage("ElizaD")->getMaxFrameX() < frame)
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
				if (frame != IMAGEMANAGER->findImage("ElizaD")->getMaxFrameX())
				{
					frame++;
				}
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x, i);
				if (color == RGB(255, 0, 0))
				{
					MonsterMoving(-3);
					Setbody(i);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x - 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x - 12, i - 3);
					if ((color1 != RGB(255, 0, 0)) && (color2 != RGB(255, 0, 0)))
					{
						left(0);
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
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x, i);

				if (color == RGB(255, 0, 0))
				{
					Setbody(i);
					MonsterMoving(3);
					COLORREF color1 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x + 12, i + 3);
					COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("pixelboss")->getMemDC(), pt.x + 12, i - 3);
					if (color1 != RGB(255, 0, 0) && color2 != RGB(255, 0, 0))
					{
						left(1);
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
void Eliza::SubHp(int Atk)
{
	hit = true;
	HitTimer = 6;
	frame = 0;
	SkillTwoCount++;
	if (SkillTwoCount % 4 == 0 && SkillTwo == false)
	{
		skill2();
	}
	if (SkillOne == false)
	{
		SkillOne = true;
		skill1();
	}
	NowHp -= Atk;
	if (moveDir == true)
	{
		MonsterMoving(5);
	}
	else
	{
		MonsterMoving(-5);
	}
}
void Eliza::dead(void)
{

}
void Eliza::update(void)
{
	moving();
	if (SkillTwo == true)
	{
		if (Timer % 15 == 0)
		{

			SkillTwoF++;
			if (SkillTwoF > IMAGEMANAGER->findImage("ElizaSkill2")->getMaxFrameX())
			{
				SkillTwoF = 0;
				SkillTwo = false;
				for (int i = 0; i < 4; i++)
				{
					SkillTwoRect[i] = { 0,0,0,0 };
				}
			}
		}
	}
	if (SkillOne == true)
	{
		int count = 0;
		for (int i = 0; i < 6; i++)
		{
			Sarbant[i]->SetCam(cam);
			Sarbant[i]->update();
			Sarbant[i]->collRect(PlayerBase, PlayerDamge);
			if (Sarbant[i]->ZeroHp() == true)
			{
				count++;
			}
		}
		if (count == 6)
		{
			SkillOne = false;
		}
	}
	if (SkillTwoF >= 9)
	{
		for (int i = 0; i < 4; i++)
		{
			SkillTwoRect[i] = RectMake(DemagePoint[i].x - cam->camPoint.x, DemagePoint[i].y - cam->camPoint.y, IMAGEMANAGER->findImage("ElizaSkill2")->getWidth() / 15, IMAGEMANAGER->findImage("ElizaSkill2")->getHeight());
		}
	}
}
void Eliza::render(void)
{
	//Rectangle(getMemDC(), colBody.left, colBody.top, colBody.right, colBody.bottom);
	if (SkillOne == true)
	{
		for (int i = 0; i < 6; i++)
		{
			Sarbant[i]->render();
		}
	}
	if (SkillTwo == true)
	{
		for (int i = 0; i < 4; i++)
		{
			Rectangle(getMemDC(), SkillTwoRect[i].left, SkillTwoRect[i].top, SkillTwoRect[i].right, SkillTwoRect[i].bottom);
			IMAGEMANAGER->findImage("ElizaSkill2")->frameRender(getMemDC(), DemagePoint[i].x- cam->camPoint.x, DemagePoint[i].y- cam->camPoint.y, SkillTwoF, 0);
		}
	}
	if (moveDir)
	{
		//		int pixel = harp->Base().top + (harp->Base().bottom - harp->Base().top) / 2;
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("ElizaD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1, alpha);
		}
		else if (NowHp>0 && hit == true)
		{
			IMAGEMANAGER->findImage("ElizaD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 1);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("ElizaM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("ElizaS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 1);
		}
	}
	else
	{
		if (NowHp <= 0)
		{
			IMAGEMANAGER->findImage("ElizaD")->alphaFrameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0, alpha);
		}
		else if (hit == true)
		{
			IMAGEMANAGER->findImage("ElizaD")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, 0, 0);
		}
		else if (Stay == false)
		{
			IMAGEMANAGER->findImage("ElizaM")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
		else if (Stay == true)
		{
			IMAGEMANAGER->findImage("ElizaS")->frameRender(getMemDC(), body.left - cam->camPoint.x, body.top - cam->camPoint.y, frame, 0);
		}
	}
	//Rectangle(getMemDC(), body.left, body.top, body.right, body.bottom);
	char tmp[128];
	//sprintf(tmp,"몬스터좌표 : x-%d y-%d", harp->GetPos().x, harp->GetPos().y);
	sprintf(tmp, "몬스터좌표 : x-%d y-%d", body.left, body.top);
	TextOut(getMemDC(), 50, 150, tmp, strlen(tmp));
}
void Eliza::collRect(RECT player, int demage)
{
	RECT rc;
	PlayerBase = player;
	PlayerDamge = demage;
	if (hit == false)
	{
		if (IntersectRect(&rc, &player, &body))
		{
			SubHp(demage);
		}
	}
}

void Eliza::skill1(void)
{
	int Num;
	int setX;
	POINT position;
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
		{
			setX = 740;
		}
		else if (i == 1)
		{
			setX = 950;
		}
		else if (i == 2)
		{
			setX = 1430;
		}
		else if (i == 3)
		{
			setX = 78;
		}
		else if (i == 4)
		{
			setX = 680;
		}
		else if (i == 5)
		{
			setX = 1180;
		}
		Num = rand() % 2;
		if (Num == 0)
		{
			setJLucida = new JLucida;
			position = { setX,787 - IMAGEMANAGER->findImage("JLucidaD")->getWidth() / 4 };
			setJLucida->init(position);
			Sarbant[i] = setJLucida;
		}
		else
		{
			setLucida = new Lucida;
			position = { setX,787 - IMAGEMANAGER->findImage("LucidaD")->getWidth() / 4 };
			setLucida->init(position);
			Sarbant[i] = setLucida;
		}
			Sarbant[i]->SetCam(cam);
	}
}

void Eliza::skill2(void)
{
	for (int i = 0; i < 4; i++)
	{
		DemagePoint[i] = { rand() % IMAGEMANAGER->findImage("pixelboss")->getWidth(),835-IMAGEMANAGER->findImage("ElizaSkill2")->getHeight() };
	}
	SkillTwo = true;
}
