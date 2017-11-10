#pragma once
#include "gameNode.h"
#include "enemy.h"
#include "bullets.h"
#include <vector>
class enemyManager :public gameNode
{
private:
	typedef vector<enemy*>EnemyList;
	EnemyList Minions;
public:

	HRESULT init();
	void release();
	void update();
	void render();

	inline vector<enemy*>getMinionVector() { return Minions; }


	enemyManager();
	~enemyManager();
};

