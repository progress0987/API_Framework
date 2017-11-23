#include "stdafx.h"
#include "player.h"
#include "enemyManager.h"



//hitRC - rcleft + 34 / rcbottom - 7 / rcright - 36 / rctop + 13

//curPos = ������ǥ
//cam - �ʿ����� ������ǥ
HRESULT player::init(POINT pos,mapFrame* Scene)
{
	curScene = Scene;
	_human = IMAGEMANAGER->findImage("ĳ����");
	backStage = curScene->getBack();
	curStatus = onJump;
	curDir = false;
	curPos = pos;

	mycam->camPoint.x = pos.x-mycam->width/2;
	mycam->camPoint.y = pos.y-mycam->height/2;
	if (mycam->camPoint.x < 0) mycam->camPoint.x = 0;
	if (mycam->camPoint.x + mycam->width > curScene->getBack()->getWidth()) mycam->camPoint.x = curScene->getBack()->getWidth() - mycam->width;
	if (mycam->camPoint.y < 0) mycam->camPoint.y = 0;
	if (mycam->camPoint.y + mycam->height > curScene->getBack()->getHeight()) mycam->camPoint.y = curScene->getBack()->getHeight() - mycam->height;

	count = curFrameX = curFrameY = camAccelY = 0;

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
	//�߷°�//ī�޶� ó��
	//WINSIZEY/2 = 384
	//int temp = mycam->camPoint.y + WINSIZEY / 2;		//�׽�Ʈ��
	if (curPos.y - mycam->camPoint.y - height / 2>WINSIZEY / 2) {//ī�޶� �߰����� �Ʒ����ִٸ�(������ ����������)
		mycam->camPoint.y += 3.f;
		if (mycam->camPoint.y + WINSIZEY > backStage->getHeight()) {
			mycam->camPoint.y = backStage->getHeight() - WINSIZEY;
		}
	}
	else if (curPos.y - mycam->camPoint.y<WINSIZEY / 4) {
		mycam->camPoint.y -= 3.f;
		if (mycam->camPoint.y < 0) {
			mycam->camPoint.y = 0;
		}
	}
	if (curPos.x - mycam->camPoint.x + width / 2 < WINSIZEX / 2) {//�����̶��
		mycam->camPoint.x -= 3.f;
		if (mycam->camPoint.x < 0.f) mycam->camPoint.x = 0.f;
	}
	else if (curPos.x - mycam->camPoint.x - width / 2 > WINSIZEX / 2) {//�������̶��
		mycam->camPoint.x += 3.f;
		if (mycam->camPoint.x + mycam->width > backStage->getWidth()) {
			mycam->camPoint.x = backStage->getWidth() - mycam->width;
		}
	}
	if (curStatus == onJump) {
		velocity += gravity;
		if (velocity > 10) velocity = 10;
		curPos.y += velocity;
		rc = RectMakeCenter(curPos.x, curPos.y, width, height);
		hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
		if (velocity > 0) {
			for (int i = -10; i < 10; i++) {
				if (GetPixel(backStage->getMemDC(), curPos.x,hitRC.bottom + i) == RGB(255, 0, 0)) {
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

	//�������°�
	//COLORREF t = GetPixel(backStage->getMemDC(), mycam->camPoint.x + curPos.x, mycam->camPoint.y + hitRC.bottom + 1);
	//int r = GetRValue(t);
	//int g = GetGValue(t);
	//int b = GetBValue(t);
	if (curStatus != Status::onJump&&(curStatus!=Status::onLadder&&curStatus!=Status::onRope) /* && GetPixel(backStage->getMemDC(), mycam->camPoint.x + curPos.x, mycam->camPoint.y + hitRC.bottom) != RGB(255, 0, 0)*/) {
		velocity += gravity;
		if (velocity > 10) velocity = 10;
		curPos.y += velocity;
		rc = RectMakeCenter(curPos.x, curPos.y, width, height);
		hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
		//curFrameY = 2 * 3 + curFrameY % 2;
		for (int i = -10; i < 10; i++) {
			if (GetPixel(backStage->getMemDC(), curPos.x, hitRC.bottom + i) == RGB(255, 0, 0)) {
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
	//�������ִ°�� �ӵ�����
	if (curStatus == Status::onIdle) {
		count++;
		if (count % 50 == 0) {
			curFrameX++;
			if (curFrameX > _human->getMaxFrameX()) curFrameX = 0;
		}
		if (moveVel > 0.f || moveVel < 0.f) {
			if (moveVel > 0.f) {
				moveVel -= 0.1f;
				if (moveVel < 0.f)moveVel = 0.f;
			}
			else {
				moveVel += 0.1f;
				if (moveVel > 0.f)moveVel = 0.f;
			}
		}
	}
	//////////////////////////////////////////////////////////////����
	//����Ű ó����������
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) {
		curDir = false;
		if (curStatus != Status::onDown) {
			if (curStatus == Status::onIdle) {
				curStatus = Status::onWalk;
				curFrameY = 2;
				count = 0;
			}
		}
	}
	//����Ű ��� ��������
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
			if (GetPixel(backStage->getMemDC(), hitRC.left, hitRC.bottom) != RGB(255, 255, 0)) {
				moveVel -= 0.1f;
				if (moveVel < -2.f) moveVel = -2.f;
			}
			else {
				moveVel = 0;
			}
			///////////ȭ���̵��κ�
			//if (curPos.x + >0)
			//	curPos.x += moveVel;
			//else {
			//	mycam->camPoint.x += moveVel;
			//	if (mycam->camPoint.x < 0) {
			//		mycam->camPoint.x = 0;
			//		curPos.x += moveVel;
			//		if (curPos.x - width / 2 < 0)curPos.x = width / 2;
			//	}
			//}
			break;
		case Status::onJump:
			moveVel -= 0.1f;
			if (moveVel < -2.f) moveVel = -2.f;
			//if (curPos.x >WINSIZEX / 2 - width / 2)
			//	curPos.x += moveVel;
			//else {
			//	mycam->camPoint.x += moveVel;
			//	if (mycam->camPoint.x < 0) {
			//		mycam->camPoint.x = 0;
			//		curPos.x += moveVel;
			//		if (curPos.x - width / 2 < 0)curPos.x = width / 2;
			//	}
			//}
			break;
		}
		curPos.x += moveVel;
		if (curPos.x - (width / 2 - (hitRC.left - rc.left)) < 0) {
			curPos.x = width / 2 - (hitRC.left - rc.left);
			moveVel = 0;
		}
	}
	//����Ű ������
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) {
		if (curStatus == Status::onWalk) {
			curStatus = Status::onIdle;
			curFrameY = 0;
		}
	}

	//////////////////////////////////////////////////////////////������
	//������Ű ó����������
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) {
		curDir = true;
		if (curStatus != Status::onDown) {
			if (curStatus == Status::onIdle) {
				curStatus = Status::onWalk;
				curFrameY = 3;
				count = 0;
			}
		}
	}
	//������Ű ��� ��������
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
				if (GetPixel(backStage->getMemDC(), hitRC.right, hitRC.bottom) != RGB(255, 255, 0)) {
					moveVel += 0.1f;
					if (moveVel > 2.f) moveVel = 2.f;
				}
				else {
					moveVel = 0;
				}
				//if (curPos.x < WINSIZEX / 2 - width / 2)
				//	curPos.x += moveVel;
				//else {
				//	mycam->camPoint.x += moveVel;
				//	if (mycam->camPoint.x > backStage->getWidth() - mycam->width) {
				//		mycam->camPoint.x = backStage->getWidth() - mycam->width;
				//		curPos.x += moveVel;
				//		if (curPos.x + width / 2 > WINSIZEX)curPos.x = WINSIZEX - width / 2;
				//	}
				//}
				break;
			case Status::onJump:
				moveVel += 0.1f;
				if (moveVel > 2.f) moveVel = 2.f;
				//if (curPos.x < WINSIZEX / 2 - width / 2)
				//	curPos.x += moveVel;
				//else {
				//	mycam->camPoint.x += moveVel;
				//	if (mycam->camPoint.x > backStage->getWidth() - mycam->width) {
				//		mycam->camPoint.x = backStage->getWidth() - mycam->width;
				//		curPos.x += moveVel;
				//		if (curPos.x + width / 2 > WINSIZEX)curPos.x = WINSIZEX - width / 2;
				//	}
				//}
				break;
			}
			curPos.x += moveVel;
			if (curPos.x + (width / 2 - (rc.right - hitRC.right)) > curScene->getBack()->getWidth()) {
				curPos.x = curScene->getBack()->getWidth() - (width / 2 - (rc.right - hitRC.right));
				moveVel = 0;
			}
		}
	}
	//������Ű ������
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) {
		if (curStatus == Status::onWalk) {
			curStatus = Status::onIdle;
			curFrameY = 1;
		}
	}
	////////////////////////////////////////////////�Ʒ� ��������
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {

		if (curStatus != onJump) {
			if (curStatus != Status::onRope&&curStatus != Status::onLadder) {	//�Ʒ��� ��������
				for (int i = hitRC.left; i < hitRC.right; i++) {
					COLORREF t = GetPixel(backStage->getMemDC(),i, hitRC.bottom + 10);
					if (t == RGB(0, 255, 0)) {
						curPos.x = i;
						curStatus = Status::onRope;
						moveVel = 0;
						curFrameY = 9;
						break;
					}
					if (t == RGB(0, 0, 255)) {
						curPos.x = i;
						curStatus = Status::onLadder;
						moveVel = 0;
						curFrameY = 8;
						break;
					}
				}
			}
			if (curStatus == Status::onRope || curStatus == Status::onLadder) {
				count++;
				curPos.y += 1;
				if (count % 1500) {
					curFrameX++;
					if (curFrameX > _human->getMaxFrameX())curFrameX = 0;
				}
				COLORREF t = GetPixel(backStage->getMemDC(), curPos.x, hitRC.bottom+10);
				if (t != RGB(0, 255, 0) && t != RGB(0, 0, 255)) {
					curStatus = onJump;
					if (curDir) {
						curFrameY = 6;
					}
					else {
						curFrameY = 7;
					}
				}
			}
			else {
				curStatus = Status::onDown;
				curFrameY = 2 * 2 + curDir;
			}
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) {
		if (curStatus == onDown) {
			curStatus = Status::onIdle;
			curFrameY = curDir;
		}
	}
	/////////////////////////////////////////////////���� ��������
	if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		if (curStatus != Status::onLadder && curStatus != Status::onRope) {
			for (int i = hitRC.left; i < hitRC.right; i++) {
				COLORREF t = GetPixel(backStage->getMemDC(),i, hitRC.top);
				if (t == RGB(0, 255, 0)) {//�����϶�
					curPos.x = i;
					curPos.y -= 4;
					curStatus = Status::onRope;
					moveVel = 0;
					curFrameY = 9;
					rc = RectMakeCenter(curPos.x, curPos.y, width, height);
					hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
					break;
				}
				if (t == RGB(0, 0, 255)) {//��ٸ��϶�
					curPos.x = i;
					curPos.y -= 4;
					curStatus = Status::onLadder;
					moveVel = 0;
					curFrameY = 8;
					rc = RectMakeCenter(curPos.x, curPos.y, width, height);
					hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
					break;
				}
			}
		}
		if (curStatus == Status::onRope || curStatus == Status::onLadder) {
			curPos.y -= 1;
			for (int i = -2; i < 3; i++) {
				COLORREF t = GetPixel(backStage->getMemDC(), curPos.x, hitRC.bottom+i);
				if (t == RGB(255, 0, 0)) {
					curStatus = Status::onJump;
					curFrameY = curDir;
					break;
				}
			}
		}
	}
	/////////////////////////////////////////////////////////////����
	if (KEYMANAGER->isOnceKeyDown('C')) {
		if (curStatus == Status::onDown) {
			curPos.y += height / 3;
			rc = RectMakeCenter(curPos.x, curPos.y, width, height);
			hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
			curStatus = Status::onJump;
			curFrameY = 6 + curDir;
		}
		else if (curStatus != onJump) {
			curFrameY = 3 * 2 + curDir;
			curStatus = onJump;
			velocity = jumpPow;
		}
		else {
			//���� �� ��ų����
		}
	}
	

	//��� ������ ���� �� ��Ʈ�� ����
	rc = RectMakeCenter(curPos.x, curPos.y, width, height);
	hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
}

void player::render(void)
{
	//IMAGEMANAGER->render("����", getMemDC(), 0, 0, mycam->camPoint.x, mycam->camPoint.y, WINSIZEX, WINSIZEY);
	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	//curScene->getFront()->render(getMemDC(), 0, 0, mycam->camPoint.x, mycam->camPoint.y, mycam->width, mycam->height);
	//curScene->getBack()->render(getMemDC(), 0, 0, mycam->camPoint.x, mycam->camPoint.y, mycam->width, mycam->height);
	_human->frameRender(getMemDC(), rc.left - mycam->camPoint.x, rc.top - mycam->camPoint.y, curFrameX, curFrameY);

	char tmp[128];
	sprintf(tmp, "Cam : %d,%d / curPos : %d,%d", mycam->camPoint.x, mycam->camPoint.y, curPos.x, curPos.y);
	TextOut(getMemDC(), 50, 100, tmp, strlen(tmp));
	EllipseMakeCenter(getMemDC(), curPos.x-mycam->camPoint.x, hitRC.bottom + 10 - mycam->camPoint.y, 35, 35);
	Rectangle(getMemDC(), hitRC.left- mycam->camPoint.x, hitRC.top - mycam->camPoint.y, hitRC.right - mycam->camPoint.x, hitRC.bottom - mycam->camPoint.y);
}


//ĳ���͸� �����ִ� ī�޶� �Լ�. �������� �����Լ� �κп��� ó��.
//�������� ĳ������ǥ������ �޾Ƽ� mapx, mapy�� �������ش�.

player::player()
{
}


player::~player()
{
}
