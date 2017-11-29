#include "stdafx.h"
#include "player.h"
#include "enemyManager.h"



//hitRC - rcleft + 34 / rcbottom - 7 / rcright - 36 / rctop + 13

//curPos = 절대좌표
//cam - 맵에서의 절대좌표
HRESULT player::init(POINT pos,mapFrame* Scene)
{
	curScene = Scene;
	_human = IMAGEMANAGER->findImage("캐릭터");
	attackMotion = IMAGEMANAGER->findImage("캐릭터공격");
	backStage = curScene->getBack();
	curStatus = onJump;
	sceneChange = false;
	curDir = false;
	curPos = pos;

	onAttack = false;
	onHit = false;
	onLvlUP = false;
	levelUPCount = lvlUPFrame= 0;

	hitcount = 0;
	hitalpha = 255;

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

	hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };

	_human->setFrameX(curFrameX);
	_human->setFrameY(curFrameY);

	stat = new status;
	meso = 1000;


	//////////////////////////////////////////스킬 초기화
	skill* sk1;
	sk1 = new skill;
	sk1->init("skill1", 3, 200,300);
	sk1->setCam(mycam);
	skillList.push_back(sk1);


	skill* sk2;
	sk2 = new skill;
	sk2->init("skill2", 10, 150, 300);
	sk2->setCam(mycam);
	skillList.push_back(sk2);


	//수정 - 레벨업 이펙트 추가


	ASkill = skillList[0];
	SSkill = skillList[1];
	return S_OK;
}

void player::release(void)
{
	ASkill = nullptr;
	SSkill = nullptr;
	DSkill = nullptr;
	curCast = nullptr;
	SAFE_DELETE(stat);
	em = nullptr;
}

void player::update(void)
{
	//중력값//카메라 처리
	//WINSIZEY/2 = 384
	//int temp = mycam->camPoint.y + WINSIZEY / 2;		//테스트용
	if (curPos.y - mycam->camPoint.y - height / 2>WINSIZEY / 2) {//카메라가 중간보다 아래에있다면(밑으로 내려가야함)
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
	if (curPos.x - mycam->camPoint.x + width / 2 < WINSIZEX / 2) {//왼쪽이라면
		mycam->camPoint.x -= 3.f;
		if (mycam->camPoint.x < 0.f) mycam->camPoint.x = 0.f;
	}
	else if (curPos.x - mycam->camPoint.x - width / 2 > WINSIZEX / 2) {//오른쪽이라면
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

	//떨어지는것
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
	//가만히있는경우 속도감속
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
	//////////////////////////////////////////////////////////////왼쪽,오른쪽
	if (!sceneChange&&!onAttack) {
		//왼쪽키 처음눌렸을때
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
				if (GetPixel(backStage->getMemDC(), hitRC.left, hitRC.bottom) != RGB(255, 255, 0)) {
					moveVel -= 0.1f;
					if (moveVel < -2.f) moveVel = -2.f;
				}
				else {
					moveVel = 0;
				}
				///////////화면이동부분
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
			curDir = true;
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

			}
		}
		//오른쪽키 뗐을때
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) {
			if (curStatus == Status::onWalk) {
				curStatus = Status::onIdle;
				curFrameY = 1;
			}
		}
	}
	////////////////////////////////////////////////아래 눌렀을때
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {

		if (curStatus != onJump) {
			if (curStatus != Status::onRope&&curStatus != Status::onLadder) {	//아래로 내려갈때
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
				if (count % 150) {
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
				moveVel = 0;
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
	/////////////////////////////////////////////////위로 눌렀을때
	if (KEYMANAGER->isOnceKeyDown(VK_UP)) {
		for (int i = 0; i <curScene->getPortals().size(); i++) {
			if (IntersectRect(&RECT(), &curScene->getPortals()[i].rc, &hitRC)) {
				sceneChange = true;
				break;
			}
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		if (curStatus != Status::onLadder && curStatus != Status::onRope) {
			for (int i = hitRC.left; i < hitRC.right; i++) {
				COLORREF t = GetPixel(backStage->getMemDC(),i, hitRC.top);
				if (t == RGB(0, 255, 0)) {//로프일때
					curPos.x = i;
					curPos.y -= 4;
					curStatus = Status::onRope;
					moveVel = 0;
					curFrameY = 9;
					rc = RectMakeCenter(curPos.x, curPos.y, width, height);
					hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
					break;
				}
				if (t == RGB(0, 0, 255)) {//사다리일때
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
	/////////////////////////////////////////////////////////////점프
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
			//점프 후 스킬쓸때
		}
	}
	///////////////////////////////////////////////////////공격
	if (curStatus != Status::onLadder&&curStatus != Status::onRope) {
		//////////////////기본공격
		if (KEYMANAGER->isOnceKeyDown('X')) {
			if (!onAttack) {
				attFrame = 0;
				attX = 0;
				playAttMotion();
				onAttack = true;
			}
		}
		//////////////////////////////////////////////////////스킬공격
		if (KEYMANAGER->isOnceKeyDown('A')) {
			if (!onAttack) {
				attFrame = 0;
				attX = 0;
				playAttMotion();

				RECT skillRange = RectMakeCenter(curPos.x, curPos.y, ASkill->getRange(), 10);
				RECT hit;
				if (curDir) {//오른쪽
					skillRange.left += ASkill->getRange() / 2;
					skillRange.right += ASkill->getRange() / 2;
				}
				else {//왼쪽
					skillRange.left -= ASkill->getRange() / 2;
					skillRange.right -= ASkill->getRange() / 2;

				}
				em->colling(skillRange, ASkill->getDmg(), curScene->getIndex());

				vector<monster*> monincurmap = em->getbody(curScene->getIndex());
				for (int i = 0; i < monincurmap.size(); i++) {
					if (IntersectRect(&hit, &skillRange, &monincurmap[i]->getbody())) {
						curCast = ASkill;
						curCast->fire(pointMake((curDir ? hit.left : hit.right), curPos.y));
						//break;
					}
				}
			}
		}
		if (KEYMANAGER->isOnceKeyDown('S')) {
			if (!onAttack) {
				attFrame = 0;
				attX = 0;
				playAttMotion();

				RECT skillRange = RectMakeCenter(curPos.x, curPos.y, SSkill->getRange(), 10);
				RECT hit;
				if (curDir) {//오른쪽
					skillRange.left += SSkill->getRange() / 2;
					skillRange.right += SSkill->getRange() / 2;
				}
				else {//왼쪽
					skillRange.left -= SSkill->getRange() / 2;
					skillRange.right -= SSkill->getRange() / 2;

				}
				em->colling(skillRange, SSkill->getDmg(), curScene->getIndex());

				vector<monster*> monincurmap = em->getbody(curScene->getIndex());
				for (int i = 0; i < monincurmap.size(); i++) {
					if (IntersectRect(&hit, &skillRange, &monincurmap[i]->getbody())) {
						curCast = SSkill;
						curCast->fire(pointMake((curDir ? hit.left : hit.right), curPos.y));
						//break;
					}
				}
			}
		}
		if (KEYMANAGER->isOnceKeyDown('D')) {
			if (!onAttack) {
				attFrame = 0;
				attX = 0;
				playAttMotion();
			}
		}
	}
	///////////////////////////////////////////////////테스트
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
		GainExp(100);
	}
	

	//레벨업중
	if (onLvlUP) {
		levelUPCount++;
		if (levelUPCount % 5 == 0) {
			lvlUPFrame++;
			if (lvlUPFrame > IMAGEMANAGER->findImage("레벨업")->getMaxFrameX()) {
				levelUPCount = lvlUPFrame = 0;
				onLvlUP = false;
			}
		}
	}
	
	//공격모션중
	if (onAttack) {//공격 일때는 프레임을 다르게 잡아줘야함
		attFrame++;
		if (attFrame % 12 == 0) {
			attX++;
			if (attX == 2) {
				dmgRC = RectMakeCenter(curPos.x + (curDir ? 20 : -20), curPos.y + 10, 30, 30);
			}
			if (attX == 5) {
				dmgRC = RectMakeCenter(0, 0, 0, 0);
			}
			if (attX > attackMotion->getMaxFrameX()) {
				attX = 0;
				attFrame = 0;
				onAttack = false;
			}
		}
	}

	//맞는중
	if (onHit) {
		hitcount++;
		if (hitmoveX != 0) {
			hitmoveX += (hitmoveX > 0 ? -5 : 5);
		}
		if (curStatus != Status::onLadder&&curStatus != Status::onRope) {
			curPos.x += hitmoveX;
		}
		if (hitcount % 10==0) {
			hitalpha = rand() % 200+55;
			if (hitcount % 50 == 0) {
				hitalpha = 255;
			}
		}
		if (hitcount >= 300) {
			onHit = false;
		}
	}

	//몬스터와 충돌체크
	if (!onHit) {
		vector<monster*> tmp = em->getbody(curScene->getIndex());
		for (int i = 0; i < tmp.size(); i++) {
			if (IntersectRect(&RECT(), &hitRC, &tmp[i]->getbody())) {
				BeingHit();
				break;
			}
		}
	}

	if (curPos.x - (width / 2 - (hitRC.left - rc.left)) < 0) {
		curPos.x = width / 2 - (hitRC.left - rc.left);
		moveVel = 0;
	}
	if (curPos.x + (width / 2 - (rc.right - hitRC.right)) > curScene->getBack()->getWidth()) {
		curPos.x = curScene->getBack()->getWidth() - (width / 2 - (rc.right - hitRC.right));
		moveVel = 0;
	}

	//기술사용
	if (curCast != nullptr) {
		curCast->update();
		//현재 사용하는 기술의 대미지 렉트를 그려줌
		hitRC = curCast->getCurSkillRC();
		if (curCast->onCast == false) {
			curCast = nullptr;
		}
	}
	//모든 연산이 끝난 후 렉트를 생성
	rc = RectMakeCenter(curPos.x, curPos.y, width, height);
	hitRC = { rc.left + 34,rc.top + 13, rc.right - 36, rc.bottom - 7 };
}

void player::render(void)
{
	if (onLvlUP) {
		IMAGEMANAGER->findImage("레벨업")->alphaFrameRender(getMemDC(), lvlupIMGpt.x-mycam->camPoint.x, lvlupIMGpt.y - mycam->camPoint.y, lvlUPFrame, 0, 200);
	}
	if (!onAttack) {
		if (onHit) {
			_human->alphaFrameRender(getMemDC(), rc.left - mycam->camPoint.x, rc.top - mycam->camPoint.y, curFrameX, curFrameY, hitalpha);
		}
		else {
			_human->frameRender(getMemDC(), rc.left - mycam->camPoint.x, rc.top - mycam->camPoint.y, curFrameX, curFrameY);
		}
	}
	else {
		attackMotion->frameRender(getMemDC(), rc.left - mycam->camPoint.x, rc.top - mycam->camPoint.y, attX, curDir);
	}
	
	if (curCast != nullptr) {
		curCast->render();
	}
}

void player::playAttMotion()
{
	if (!onAttack) {
		onAttack = true;
	}
}
//맞을때 불러올 것
void player::BeingHit(int amount)
{
	hitcount = 0;
	stat->curHP -= amount;
	onHit = true;
	bool dir = rand() % 2;//랜덤 방향으로 튀김
	if (dir) {
		hitmoveX = 25;
	}
	else {
		hitmoveX = -25;
	}
}
//경험치 획득
void player::GainExp(int exp)
{
	stat->Exp += exp;
	if (stat->Exp >= stat->lvlUpExp) {
		stat->Exp %= stat->lvlUpExp;
		stat->lvlUpExp *= (4 / 3);
		stat->Level++;
		stat->ap += 5;
		onLvlUP = true;
		levelUPCount = lvlUPFrame = 0;
		lvlupIMGpt = pointMake(curPos.x - 904 / 2, curPos.y - 904 + 200);
	}
}



//캐릭터를 비춰주는 카메라 함수. 렌더링은 렌더함수 부분에서 처리.
//진행방향과 캐릭터좌표정보를 받아서 mapx, mapy를 조정해준다.

bool player::openShop()
{
	for (int i = 0; i < curScene->getNPCs().size(); i++) {
		if (PtInRect(&curScene->getNPCs()[i].rc, ptMouse) && curScene->getIndex() == MapIndex::MStore) {
			return true;
		}
	}
	return false;
}

//////////////////////////////////////////////////////////스킬
player::player()
{
}


player::~player()
{
}

HRESULT skill::init(char * skillImg, int dPf, int dmg,int range)
{
	img = IMAGEMANAGER->findImage(skillImg);
	rc = { 0,0,img->getFrameWidth(),img->getFrameHeight() };
	delayPerFrames = dPf;
	this->range = range;
	this->dmg = dmg;
	for (int i = 0; i <= img->getMaxFrameX(); i++) {
		dmgRCList.push_back(RECT());
	}
	return S_OK;
}

void skill::release(void)
{
}

void skill::update(void)
{
	if (onCast) {
		frame++;
		if (frame%delayPerFrames == 0) {
			frameX++;
			if (frameX > img->getMaxFrameX()) {
				onCast = false;
				frameX = 0;
			}
			dmgRC = dmgRCList[frameX];
		}
	}
}

void skill::render(void)
{
	if (onCast) {
		if(frameX<img->getMaxFrameX())
		img->frameRender(getMemDC(), rc.left-cam->camPoint.x, rc.top-cam->camPoint.y, frameX, 0);
		//Rectangle(getMemDC(), rc.left - cam->camPoint.x, rc.top - cam->camPoint.y, rc.right - cam->camPoint.x, rc.bottom - cam->camPoint.y);
	}
}

void skill::setSkillRect(RECT skillRC)
{
	dmgRC = skillRC;
}

void skill::fire(POINT pos)
{
	rc = RectMakeCenter(pos.x, pos.y, img->getFrameWidth(), img->getFrameHeight());
	onCast = true;
}
