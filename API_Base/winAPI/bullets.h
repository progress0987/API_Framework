#pragma once
#include "gameNode.h"
#include <vector>

struct Bullet {
	image* bulletImg;
	RECT rc;
	float x, y;
	float angle;
	float speed;
	float radius;
	float fireX, fireY;
	bool fired;
	int count;
};
//공용 총알 클래스
class classBullet :public gameNode{
private:
	vector<Bullet> BulletList;
	vector<Bullet>::iterator BulletListIter;

	float range;
	const char* imgName;
	int bulletMax;
public:
	classBullet();
	~classBullet();

	HRESULT init(const char* imgName, int bulMax,float range);
	void release();
	void update();
	void render();

	void fire(float x, float y,float angle,float speed);
	void move();
	vector<Bullet> getBulList() { return BulletList; }
	vector<Bullet>::iterator getBulIter() { return BulletListIter; }

};

//소지이후 발사하는 총알들의 클래스
class missile : public gameNode
{
private:
	vector<Bullet> BulletList;
	vector<Bullet>::iterator BulletListIter;

	float range;
public:
	missile();
	~missile();


	HRESULT init(int bulletMax, float range,image* img);
	void release();
	void update();
	void render();

	void fire(float x, float y);
	void move();
};
//발사할때 만드는미사일
class instanceMissile :public gameNode {

private:
	vector<Bullet> BulletList;
	vector<Bullet>::iterator BulletListIter;

	float range;
	float bulletMax;
public:
	instanceMissile();
	~instanceMissile();
	vector<Bullet>getbullet() { return BulletList; }
	vector<Bullet>::iterator getbulletIter() { return BulletListIter; }

	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();
	void removeMissile(int arrnum);

	void fire(float x, float y, image* img);
	void move();
};