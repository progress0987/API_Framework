#include "stdafx.h"
#include "enemyManager.h"
#include "bullets.h"


HRESULT enemyManager::init(Camera* plCam)
{
	playerCam = plCam;
	for(int i=0;i<5;i++)
	{
		for (int j = 0; j < 11; j++)
		{
			setmonster[i][j] = { 0,0 };
		}
	}
	setmonster[4][0] = { 1340,787 };
	setmonster[4][1] = { 740,787 };
	setmonster[4][2] = { 950,787 };
	setmonster[4][3] = { 1430,787 };
	setmonster[4][4] = { 78,787 };
	setmonster[4][5] = { 680,787 };
	setmonster[4][6] = { 1180,787 };
	setmonster[3][0]={450,423};
	setmonster[3][1]={610,423};
	setmonster[3][2]={800,423};
	setmonster[3][3]={1020,663};
	setmonster[3][4]={850,663};
	setmonster[3][5]={660,663};
	setmonster[3][6]={210,663};
	setmonster[3][7]={400,902};
	setmonster[3][8]={700,902};
	setmonster[3][9]={1160,902};
	setmonster[3][10]={1000,902};
	setmonster[2][0]={1150,350};
	setmonster[2][1]={700,350};
	setmonster[2][2]={1260,350};
	setmonster[2][3]={1000,350};
	setmonster[2][4]={1760,463};
	setmonster[2][5]={1600,463};
	setmonster[2][6]={180,463};
	setmonster[2][7]={450,463};
	setmonster[2][8]={1050,762};
	setmonster[2][9]={820,762};
	setmonster[2][10]={1210,762};
	setmonster[1][0]={120,429};
	setmonster[1][1]={270,429};
	setmonster[1][2]={520,429};
	setmonster[1][3]={964,548};
	setmonster[1][4]={1220,548};
	setmonster[1][5]={1480,548};
	setmonster[1][6]={1680,548};
	setmonster[1][7]={830,819};
	setmonster[1][8]={1160,819};
	setmonster[1][9]={1420,819};
	setmonster[1][10]={1690,819};
	setmonster[0][0]={210,313};
	setmonster[0][1]={660,313};
	setmonster[0][2]={670,673};
	setmonster[0][3]={100,673};
	setmonster[0][4]={1240,493};
	setmonster[0][5]={1470,493};
	setmonster[0][6]={1700,493};
	setmonster[0][7]={1430,882};
	setmonster[0][8]={1770,882};
	setmonster[0][9]={840,882};
	setmonster[0][10]={390,882};
	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update(int Index)
{
	for (vector<monster*>::iterator i = Monsters.begin(); i != Monsters.end(); i++)
	{
		if ((*i)->getIndex() == Index)
		{
			(*i)->update();
		}
	}
}

void enemyManager::render(int Index)
{
	for (vector<monster*>::iterator i = Monsters.begin(); i != Monsters.end(); i++) {
		if ((*i)->getIndex() == Index)
		{
			(*i)->render();
		}
	}
}

void enemyManager::addMonster(void)
{
	int RandomMonster = 0;
	for (int i = 0; i < 11; i++)
	{
		RandomMonster = rand() % 2;
		if (RandomMonster == 0)
		{
			Harp* monster;
			monster = new Harp;
			monster->SetCam(playerCam);
			monster->init(setmonster[0][i]);
			Monsters.push_back(monster);
		}
		else
		{
			Sheep* monster;
			monster = new Sheep;
			monster->SetCam(playerCam);
			monster->init(setmonster[0][i]);
			Monsters.push_back(monster);
		}
		//Park몬스터 셋팅
		RandomMonster = rand() % 2;
		if (RandomMonster == 0)
		{
			JrYeti* monster;
			monster = new JrYeti;
			monster->SetCam(playerCam);
			monster->init(setmonster[1][i]);
			Monsters.push_back(monster);
		}
		else
		{
			PePe* monster;
			monster = new PePe;
			monster->SetCam(playerCam);
			monster->init(setmonster[1][i]);
			Monsters.push_back(monster);
		}
		//Market 몬스터 셋팅
		RandomMonster = rand() % 3;
		if (RandomMonster == 0)
		{
			Grupin* monster;
			monster = new Grupin;
			monster->SetCam(playerCam);
			monster->init(setmonster[2][i]);
			Monsters.push_back(monster);
		}
		else if (RandomMonster == 1)
		{
			Cellion* monster;
			monster = new Cellion;
			monster->SetCam(playerCam);
			monster->init(setmonster[2][i]);
			Monsters.push_back(monster);
		}
		else
		{
			Lioner* monster;
			monster = new Lioner;
			monster->SetCam(playerCam);
			monster->init(setmonster[2][i]);
			Monsters.push_back(monster);
		}
		//forest 몬스터 셋팅
		RandomMonster = rand() % 3;
		if (RandomMonster == 0)
		{
			JCellion* monster;
			monster = new JCellion;
			monster->SetCam(playerCam);
			monster->init(setmonster[3][i]);
			Monsters.push_back(monster);
		}
		else if (RandomMonster == 1)
		{
			JGrupin* monster;
			monster = new JGrupin;
			monster->SetCam(playerCam);
			monster->init(setmonster[3][i]);
			Monsters.push_back(monster);
		}
		else
		{
			JLioner* monster;
			monster = new JLioner;
			monster->SetCam(playerCam);
			monster->init(setmonster[3][i]);
			Monsters.push_back(monster);
		}
		//hill 몬스터 셋팅
		if (i >= 1 && i <= 6)
		{
		RandomMonster = rand() % 2;
			if (RandomMonster == 1)
			{
				JLucida* monster;
				monster = new JLucida;
				monster->SetCam(playerCam);
				monster->init(setmonster[4][i]);
				Monsters.push_back(monster);
//				position = { setX,787 - IMAGEMANAGER->findImage("JLucidaD")->getWidth() / 4 };
//				setJLucida->init(position);
//				Sarbant[i] = setJLucida;
			}
			else
			{
				Lucida* monster;
				monster = new Lucida;
				monster->SetCam(playerCam);
				monster->init(setmonster[4][i]);
				Monsters.push_back(monster);
//				position = { setX,787 - IMAGEMANAGER->findImage("LucidaD")->getWidth() / 4 };
//				setLucida->init(position);
//				Sarbant[i] = setLucida;
			}
		}
	}
	Eliza* monster;
	monster = new Eliza;
	monster->SetCam(playerCam);
	monster->init(setmonster[4][0]);
	Monsters.push_back(monster);
}

void enemyManager::colling(RECT DamgeRect, int Demage, int Index)
{
	for (vector<monster*>::iterator i = Monsters.begin(); i != Monsters.end(); i++)
	{
		if ((*i)->getIndex() == Index)
		{
			(*i)->collRect(DamgeRect, Demage);
		}
	}
}

void enemyManager::SharePlayer(RECT PlayerBase, int Index)
{
	for (vector<monster*>::iterator i = Monsters.begin(); i != Monsters.end(); i++) {
		if ((*i)->getIndex() == Index)
		{
			(*i)->SharePlayer(PlayerBase);
		}
	}
}

vector<monster*> enemyManager::getbody(int Index)
{
	vector<monster*> monInCurMap;
	for (vector<monster*>::iterator i = Monsters.begin(); i != Monsters.end(); i++) {
		if ((*i)->getIndex() == Index)
		{
			monInCurMap.push_back(*i);
		}
	}
	return monInCurMap;
}


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
