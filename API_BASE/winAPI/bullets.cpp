#include "stdafx.h"
#include "bullets.h"

missile::missile()
{
}


missile::~missile()
{
}
//���⼭ �̻��� �ʱ�ȭ -> �˾Ƽ� �̹����� �ʱ�ȭ�ϱ�
HRESULT missile::init(int bulletMax, float range,image* img)
{
	//�Ѿ��� ��Ÿ�
	this->range = range;
	//�Ѿ��ִ밹����ŭ ����
	for (int i = 0; i < bulletMax; i++) {
		//�Ѿ� �ʱ�ȭ
		Bullet bul;
		ZeroMemory(&bul, sizeof(Bullet));
		bul.bulletImg = new image;
		bul.bulletImg = img;
		//�Ѿ˼ӵ�(�ٲ����
		bul.speed = 5.0f;
		bul.fired = false;
		BulletList.push_back(bul);
	}

	return S_OK;
}

void missile::release()
{
}

void missile::update()
{
	move();
}

void missile::render()
{
	for (BulletListIter = BulletList.begin(); BulletListIter != BulletList.end(); BulletListIter++) {
		if (BulletListIter->fired) {
			BulletListIter->bulletImg->render(getMemDC(), BulletListIter->rc.left, BulletListIter->rc.top, 0, 0, BulletListIter->bulletImg->getWidth(), BulletListIter->bulletImg->getHeight());
		}
	}
}

void missile::fire(float x, float y)
{
	for (BulletListIter = BulletList.begin(); BulletListIter != BulletList.end(); BulletListIter++) {
		if (!BulletListIter->fired) {
			BulletListIter->fired = true;
			BulletListIter->x = BulletListIter->fireX = x;
			BulletListIter->y = BulletListIter->fireY = y;
			BulletListIter->rc = RectMakeCenter(BulletListIter->x, BulletListIter->y, BulletListIter->bulletImg->getWidth(), BulletListIter->bulletImg->getHeight());
			break;
		}
	}
}

void missile::move()
{
	for (BulletListIter = BulletList.begin(); BulletListIter != BulletList.end(); BulletListIter++) {
		if (BulletListIter->fired) {
			//���⼳�����ٰ�
			BulletListIter->y -= BulletListIter->speed;
			BulletListIter->rc = RectMakeCenter(BulletListIter->x, BulletListIter->y, BulletListIter->bulletImg->getWidth(), BulletListIter->bulletImg->getHeight());
		}
		if (range < getDistance(BulletListIter->x, BulletListIter->y, BulletListIter->fireX, BulletListIter->fireY)) {
			BulletListIter->fired = false;
		}
	}
}

instanceMissile::instanceMissile()
{
}

instanceMissile::~instanceMissile()
{
}

HRESULT instanceMissile::init(int bulletMax, float range)
{
	this->bulletMax = bulletMax;
	this->range = range;
	return S_OK;
}

void instanceMissile::release()
{
}

void instanceMissile::update()
{
	move();
}

void instanceMissile::render()
{
	for (BulletListIter = BulletList.begin(); BulletListIter != BulletList.end(); BulletListIter++) {
		if (BulletListIter->fired) {
			//�����Ұ�
			BulletListIter->bulletImg->frameRender(getMemDC(), BulletListIter->rc.left, BulletListIter->rc.top, BulletListIter->bulletImg->getFrameX(), 0);
			//�Ƹ��� �̻��� �ִϸ��̼� �������� ���ϴµ�
			BulletListIter->count++;
			//�����Ӿִϸ��̼�
			if (BulletListIter->count % 5 == 0) {
				BulletListIter->bulletImg->setFrameX(BulletListIter->bulletImg->getFrameX() + 1);
				//�����Ӿִϸ��̼� ����
				if (BulletListIter->bulletImg->getFrameX() > BulletListIter->bulletImg->getMaxFrameX()) {
					BulletListIter->bulletImg->setFrameX(0);
				}
				//�� �ʱ�ȭ�ϴ��� �𸣰���
				BulletListIter->count = 0;
			}
		}
	}
}

void instanceMissile::removeMissile(int arrnum)
{
	//�̹����� ���� ������ ������
	BulletList[arrnum].bulletImg->release();
	BulletList.erase(BulletList.begin() + arrnum);
}

void instanceMissile::fire(float x, float y, image * img)
{
	Bullet bul;
	ZeroMemory(&bul, sizeof(Bullet));
	bul.bulletImg = img;
	//�Ѿ� �ӵ�,��ǥ����
	bul.x = bul.fireX = x;
	bul.y = bul.fireY = y;
	bul.rc = RectMakeCenter(bul.x, bul.y, bul.bulletImg->getFrameWidth(), bul.bulletImg->getFrameHeight());
	BulletList.push_back(bul);
}

void instanceMissile::move()
{
	//���⿡���� �����̴°� �����������
	for (BulletListIter = BulletList.begin(); BulletListIter != BulletList.end();) {
		//�̵��ϴ°� �����ٽ��ؾ���(���⿡����)
		BulletListIter->y = BulletListIter->speed;
		BulletListIter->rc = RectMakeCenter(BulletListIter->x, BulletListIter->y, BulletListIter->bulletImg->getFrameWidth(), BulletListIter->bulletImg->getFrameHeight());
		if (range < getDistance(BulletListIter->x, BulletListIter->y, BulletListIter->fireX, BulletListIter->fireY)) {
			SAFE_DELETE(BulletListIter->bulletImg);
			BulletListIter = BulletList.erase(BulletListIter);
		}
		else BulletListIter++;
	}
}

classBullet::classBullet()
{
}

classBullet::~classBullet()
{
}



HRESULT classBullet::init(const char * imgName, int bulMax, float range)
{
	this->imgName = imgName;
	this->bulletMax = bulMax;
	this->range = range;
	return S_OK;
}

void classBullet::release()
{
}

void classBullet::update()
{
	move();
}

void classBullet::render()
{
	for (BulletListIter = BulletList.begin(); BulletListIter != BulletList.end(); BulletListIter++) {
		BulletListIter->bulletImg->render(getMemDC(), BulletListIter->rc.left, BulletListIter->rc.top);
	}
}

void classBullet::fire(float x, float y, float angle, float speed)
{
	//�ִ밹������ ���Ͱ� Ŀ���� �����Ұ�
	if (bulletMax < BulletList.size())return;
	Bullet bul;
	ZeroMemory(&bul, sizeof(Bullet));
	bul.bulletImg = IMAGEMANAGER->findImage(imgName);
	bul.speed = speed;
	bul.radius = bul.bulletImg->getWidth() / 2;
	bul.x = bul.fireX = x;
	bul.y = bul.fireY = y;
	bul.angle = angle;
	bul.rc = RectMakeCenter(bul.x, bul.y, bul.bulletImg->getWidth(), bul.bulletImg->getHeight());
	BulletList.push_back(bul);
}

void classBullet::move()
{
	for (BulletListIter = BulletList.begin(); BulletListIter != BulletList.end(); ) {
		BulletListIter->x += cosf(BulletListIter->angle)*BulletListIter->speed;
		BulletListIter->y += (-sinf(BulletListIter->angle))*BulletListIter->speed;
		BulletListIter->rc = RectMakeCenter(BulletListIter->x, BulletListIter->y, BulletListIter->bulletImg->getWidth(), BulletListIter->bulletImg->getHeight());

		if (range < getDistance(BulletListIter->fireX, BulletListIter->fireY, BulletListIter->x, BulletListIter->y)) {
			BulletListIter = BulletList.erase(BulletListIter);
		}
		else
			BulletListIter++;
	}
}
