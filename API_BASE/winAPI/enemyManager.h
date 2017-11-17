#pragma once
#include "gameNode.h"
#include "enemy.h"
#include <vector>
class enemyManager :public gameNode
{
private:
	typedef vector<enemy*>EnemyList;
	typedef vector<enemy*>::iterator EnemyListIter;
	EnemyList Minions;
	EnemyListIter MinionsIter;
public:

	HRESULT init();
	void release();
	void update();
	void render();

	//미니언 세팅
	void setMinion();

	void removeMinion(int arrnum);

	inline vector<enemy*>getMinionVector() { return Minions; }
	inline vector<enemy*>::iterator getMinionIter() { return MinionsIter; }


	enemyManager();
	~enemyManager();
};

