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
}

void enemyManager::addMonster(monster * monster)
{
	Harp* test1;
	POINT test = { 200,100 };
	test1 = new Harp;
	test1->SetCam(playerCam);
	test1->init(test);
	Monsters.push_back(test1);
}


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
