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
	//�����ǵ� ����ִ°� - ����
}

void enemyManager::removeMinion(int arrnum)
{
}


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
