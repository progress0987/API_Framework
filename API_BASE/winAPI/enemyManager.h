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
	POINT setmonster[5][11];
public:

	HRESULT init(Camera* plCam);
	void release();
	void update(int Index);
	void render(int Index);
	void addMonster(void);
	void colling(RECT DamgeRect, int Demage, int Index);
	void SharePlayer(RECT PlayerBase, int Index);
	int getexp(int Index);
	vector<monster*> getbody(int Index);

	inline vector<enemy*>getMinionVector() { return Minions; }
	inline vector<monster*>getMonsters() { return Monsters; }


	enemyManager();
	~enemyManager();
};

