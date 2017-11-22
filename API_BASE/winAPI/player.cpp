#include "stdafx.h"
#include "player.h"
#include "enemyManager.h"



//hitRC - rcleft + 34 / rcbottom - 7 / rcright - 36 / rctop + 13
HRESULT player::init(Camera *cam)
{
	IMAGEMANAGER->addFrameImage("캐릭터", "sprites/character.bmp", 400, 1000, 4, 10, true, RGB(255, 0, 255));
	_human = IMAGEMANAGER->findImage("캐릭터");
	backStage = IMAGEMANAGER->findImage("지형");
	mycam = cam;
	curStatus = onJump;

	//mycam->camPoint.x = backStage->getWidth() - WINSIZEX;
	//mycam->camPoint.y = backStage->getHeight() - WINSIZEY;

	count = curFrameX = curFrameY = camAccelY = 0;

	//처음 위치는 맵의 가운데 아래서부터 시작한다.

	curPos.x = WINSIZEX - 100;
	curPos.y = WINSIZEY - 200;
	width = _human->getFrameWidth();
	height = _human->getFrameHeight();
	rc = RectMakeCenter(curPos.x, curPos.y, width, height);

	//hitRC - rcleft + 34 / rcbottom - 7 / rcright - 36 / rctop + 13
	hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };

	_human->setFrameX(curFrameX);
	_human->setFrameY(curFrameY);

	return S_OK;
}

void player::release(void)
{
}

void player::update(void)
{
	//중력값
	if (curStatus == onJump) {
		velocity += gravity;
		if (velocity > 10) velocity = 10;
		curPos.y += velocity;
		rc = RectMakeCenter(curPos.x, curPos.y, width, height);
		hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
		if (velocity > 0) {
			for (int i = -10; i < 10; i++) {
				if (GetPixel(backStage->getMemDC(), mycam->camPoint.x + curPos.x, mycam->camPoint.y + hitRC.bottom + i) == RGB(255, 0, 0)) {
					curStatus = onIdle;
					curFrameY = curFrameY % 2;
					velocity = 0;
					curPos.y = rc.bottom + i - (height / 2) + 10;
					rc = RectMakeCenter(curPos.x, curPos.y, width, height);
					break;
				}
			}
		}
	}

	//떨어지는것
	//COLORREF t = GetPixel(backStage->getMemDC(), mycam->camPoint.x + curPos.x, mycam->camPoint.y + hitRC.bottom + 1);
	//int r = GetRValue(t);
	//int g = GetGValue(t);
	//int b = GetBValue(t);
	if (curStatus != Status::onJump/* && GetPixel(backStage->getMemDC(), mycam->camPoint.x + curPos.x, mycam->camPoint.y + hitRC.bottom) != RGB(255, 0, 0)*/) {
		velocity += gravity;
		if (velocity > 10) velocity = 10;
		curPos.y += velocity;
		rc = RectMakeCenter(curPos.x, curPos.y, width, height);
		hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
		//curFrameY = 2 * 3 + curFrameY % 2;
		for (int i = -10; i < 10; i++) {
			if (GetPixel(backStage->getMemDC(), mycam->camPoint.x + curPos.x, mycam->camPoint.y + hitRC.bottom + i) == RGB(255, 0, 0)) {//-7은 rc.bottom과 실제 발바닥과의 차이
																																		//curStatus = onIdle;
																																		//curFrameY = curFrameY % 2;
				velocity = 0;
				curPos.y = rc.bottom - height / 2 + i;
				rc = RectMakeCenter(curPos.x, curPos.y, width, height);
				hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
				break;
			}
		}
		//curStatus = onJump;
		//curFrameY = 2 * 3 + curFrameY % 2;
	}
	//가만히있는경우 속도감속
	if (curStatus == Status::onIdle) {
		count++;
		if (count % 50 == 0) {
			curFrameX++;
			if (curFrameX > _human->getMaxFrameX()) curFrameX = 0;
		}
		if (moveVel > 0.f || moveVel < 0.f) {
			if (moveVel > 0.f) {
				moveVel -= 0.01f;
				if (moveVel < 0.f)moveVel = 0.f;
			}
			else {
				moveVel += 0.01f;
				if (moveVel > 0.f)moveVel = 0.f;
			}
		}
	}
	//////////////////////////////////////////////////////////////왼쪽
	//왼쪽키 처음눌렸을때
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) {
		if (curStatus != Status::onDown) {
			if (curStatus == Status::onIdle) {
				curStatus = Status::onWalk;
				curFrameY = 2;
				count = 0;
			}
		}
	}
	//왼쪽키 계속 눌렀을때
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		switch (curStatus) {
		case Status::onIdle:
			curStatus = onWalk;
			curFrameY = 2;
		case Status::onWalk:
			count++;
			if (count % 30 == 0) {
				curFrameX++;
				if (curFrameX > _human->getMaxFrameX()) curFrameX = 0;
			}
			if (GetPixel(backStage->getMemDC(), mycam->camPoint.x + hitRC.left, mycam->camPoint.y + hitRC.bottom) != RGB(255, 255, 0)) {
				moveVel -= 0.1f;
				if (moveVel < -2.f) moveVel = -2.f;
			}
			else {
				moveVel = 0;
			}
			if (curPos.x >WINSIZEX / 2 - width / 2)
				curPos.x += moveVel;
			else {
				mycam->camPoint.x += moveVel;
				if (mycam->camPoint.x < 0) {
					mycam->camPoint.x = 0;
					curPos.x += moveVel;
					if (curPos.x - width / 2 < 0)curPos.x = width / 2;
				}
			}

			//if(curPos.x>WINSIZEX/2)
			break;
		case Status::onJump:
			moveVel -= 0.1f;
			if (moveVel < -2.f) moveVel = -2.f;
			if (curPos.x >WINSIZEX / 2 - width / 2)
				curPos.x += moveVel;
			else {
				mycam->camPoint.x += moveVel;
				if (mycam->camPoint.x < 0) {
					mycam->camPoint.x = 0;
					curPos.x += moveVel;
					if (curPos.x - width / 2 < 0)curPos.x = width / 2;
				}
			}
			break;
		}

	}
	//왼쪽키 뗐을때
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) {
		if (curStatus == Status::onWalk) {
			curStatus = Status::onIdle;
			curFrameY = 0;
		}
	}

	//////////////////////////////////////////////////////////////오른쪽
	//오른쪽키 처음눌렸을때
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) {
		if (curStatus != Status::onDown) {
			if (curStatus == Status::onIdle) {
				curStatus = Status::onWalk;
				curFrameY = 3;
				count = 0;
			}
		}
	}
	//오른쪽키 계속 눌렀을때
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		if (curStatus != onDown) {
			switch (curStatus) {
			case Status::onIdle:
				curStatus = onWalk;
				curFrameY = 3;
			case Status::onWalk:
				count++;
				if (count % 30 == 0) {
					curFrameX++;
					if (curFrameX > _human->getMaxFrameX()) curFrameX = 0;
				}
				if (GetPixel(backStage->getMemDC(), mycam->camPoint.x + hitRC.right, mycam->camPoint.y + hitRC.bottom) != RGB(255, 255, 0)) {
					moveVel += 0.1f;
					if (moveVel > 2.f) moveVel = 2.f;
				}
				else {
					moveVel = 0;
				}
				if (curPos.x < WINSIZEX / 2 - width / 2)
					curPos.x += moveVel;
				else {
					mycam->camPoint.x += moveVel;
					if (mycam->camPoint.x > backStage->getWidth() - mycam->width) {
						mycam->camPoint.x = backStage->getWidth() - mycam->width;
						curPos.x += moveVel;
						if (curPos.x + width / 2 > WINSIZEX)curPos.x = WINSIZEX - width / 2;
					}
				}
				break;
			case Status::onJump:
				moveVel += 0.1f;
				if (moveVel > 2.f) moveVel = 2.f;
				if (curPos.x < WINSIZEX / 2 - width / 2)
					curPos.x += moveVel;
				else {
					mycam->camPoint.x += moveVel;
					if (mycam->camPoint.x > backStage->getWidth() - mycam->width) {
						mycam->camPoint.x = backStage->getWidth() - mycam->width;
						curPos.x += moveVel;
						if (curPos.x + width / 2 > WINSIZEX)curPos.x = WINSIZEX - width / 2;
					}
				}
				break;
			}

		}
	}
	//오른쪽키 뗐을때
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) {
		if (curStatus == Status::onWalk) {
			curStatus = Status::onIdle;
			curFrameY = 1;
		}
	}
	////////////////////////////////////////////////아래 눌렀을때
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {

		if (curStatus != onJump) {
			curStatus = Status::onDown;
			curFrameY = 2 * 2 + curFrameY % 2;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) {
		curStatus = Status::onIdle;
		curFrameY = curFrameY % 2;
	}
	/////////////////////////////////////////////////////////////점프
	if (KEYMANAGER->isOnceKeyDown('C')) {
		if (curStatus == Status::onDown) {
			curPos.y += height / 3;
			rc = RectMakeCenter(curPos.x, curPos.y, width, height);
			hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
			curStatus = Status::onJump;
			curFrameY = 6 + curFrameY % 2;
		}
		else if (curStatus != onJump) {
			curFrameY = 3 * 2 + curFrameY % 2;
			curStatus = onJump;
			velocity = jumpPow;
		}
		else {
			//점프 후 스킬쓸때
		}
	}
	//카메라 Y축 처리
	//WINSIZEY/2 = 384
	int temp = mycam->camPoint.y + WINSIZEY / 2;
	if (mycam->camPoint.y + WINSIZEY / 2 < curPos.y) {//카메라가 중간보다 아래에있다면(밑으로 내려가야함)
		mycam->camPoint.y += 3.f;
		if (mycam->camPoint.y + WINSIZEY > backStage->getHeight()) {
			mycam->camPoint.y = backStage->getHeight() - WINSIZEY;
		}
	}
	else if (mycam->camPoint.y + WINSIZEY / 4>curPos.y) {
		mycam->camPoint.y -= 3.f;
		if (mycam->camPoint.y < 0) {
			mycam->camPoint.y = 0;
		}
	}

	//모든 연산이 끝난 후 렉트를 생성
	rc = RectMakeCenter(curPos.x, curPos.y, width, height);
	hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
}

void player::render(void)
{
	IMAGEMANAGER->render("지형", getMemDC(), 0, 0, mycam->camPoint.x, mycam->camPoint.y, WINSIZEX, WINSIZEY);
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	_human->frameRender(getMemDC(), rc.left, rc.top, curFrameX, curFrameY);

	char tmp[128];
	sprintf(tmp, "Cam : %d,%d / curPos : %d,%d", mycam->camPoint.x, mycam->camPoint.y, curPos.x, curPos.y);
	TextOut(getMemDC(), 50, 100, tmp, strlen(tmp));
	sprintf(tmp, "curStatus : %d", curStatus);
	TextOut(getMemDC(), 50, 130, tmp, strlen(tmp));
	//Rectangle(getMemDC(), hitRC.left, hitRC.top, hitRC.right, hitRC.bottom);
}


//캐릭터를 비춰주는 카메라 함수. 렌더링은 렌더함수 부분에서 처리.
//진행방향과 캐릭터좌표정보를 받아서 mapx, mapy를 조정해준다.

player::player()
{
}


player::~player()
{
}
