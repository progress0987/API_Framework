#pragma once
#include "gameNode.h"
#include "Minion1.h"
#include "Minion2.h"
#include "bullets.h"
#include <vector>
class enemyManager :public gameNode
{
private:
	typedef vector<enemy*>EnemyList;
	typedef vector<enemy*>::iterator EnemyListIter;
	EnemyList Minions;
	EnemyListIter MinionsIter;
	Bullet* bullet;
public:

	HRESULT init();
	void release();
	void update();
	void render();

	//미니언 세팅
	void setMinion();

	void minionBulFire();

	void removeMinion(int arrnum);

	void collision();
	inline vector<enemy*>getMinionVector() { return Minions; }
	inline vector<enemy*>::iterator getMinionIter() { return MinionsIter; }


	enemyManager();
	~enemyManager();
};

