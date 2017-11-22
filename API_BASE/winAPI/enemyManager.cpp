#include "stdafx.h"
#include "enemyManager.h"
#include "bullets.h"


HRESULT enemyManager::init(Camera* plCam)
{
	playerCam = plCam;
	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (vector<monster*>::iterator i = Monsters.begin(); i != Monsters.end(); i++) {
		(*i)->update();
	}
}

void enemyManager::render()
{
	for (vector<monster*>::iterator i = Monsters.begin(); i != Monsters.end(); i++) {
		(*i)->render();
	}
}

void enemyManager::addMonster(monster * monster)
{
	Monsters.push_back(monster);
}


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
