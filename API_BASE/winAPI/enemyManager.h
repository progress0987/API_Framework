#pragma once
#include "gameNode.h"
#include "enemy.h"
#include "monster.h"
#include <vector>
class enemyManager :public gameNode
{
private:
	typedef vector<enemy*>EnemyList;
	EnemyList Minions;
	vector<monster*> Monsters;
	Camera *playerCam;
public:

	HRESULT init(Camera* plCam);
	void release();
	void update();
	void render();
	void addMonster(monster* monster);

	inline vector<enemy*>getMinionVector() { return Minions; }
	inline vector<monster*>getMonsters() { return Monsters; }


	enemyManager();
	~enemyManager();
};

