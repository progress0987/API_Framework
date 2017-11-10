#include "stdafx.h"
#include "enemyManager.h"
#include "bullets.h"


HRESULT enemyManager::init()
{
	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (MinionsIter = Minions.begin(); MinionsIter != Minions.end(); MinionsIter++) {

		(*MinionsIter)->update();
		minionBulFire();
	}
}

void enemyManager::render()
{
	for (MinionsIter = Minions.begin(); MinionsIter != Minions.end(); MinionsIter++) {

		(*MinionsIter)->render();
	}
}

void enemyManager::setMinion()
{
	//포지션들 잡아주는것 - 수정
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			enemy* ufo;
			ufo = new Minion1;
			ufo->init("ufo", pointMake(80 + j * 80, 80 + i * 100));
			Minions.push_back(ufo);
		}
	}
}

void enemyManager::minionBulFire()
{
	for (MinionsIter = Minions.begin(); MinionsIter != Minions.end(); MinionsIter++) {
		RECT rc = (*MinionsIter)->getRect();
		//bullet->fire(rc.left+(rc.right-rc.left)/2, rc.top+(rc.bottom - rc.top)/2 +30,-(PI/2), (*MinionsIter)->speed);
	}
}

void enemyManager::removeMinion(int arrnum)
{
	SAFE_DELETE(Minions[arrnum]);
	Minions.erase(Minions.begin() + arrnum);
}

void enemyManager::collision()
{
}

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
