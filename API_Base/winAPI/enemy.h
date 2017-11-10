#pragma once
#include "gameNode.h"


//�̵� ����
struct MoveSet {
	BezierPoint destList[4];//3��������� �ϴ°ɷ�. ������ ������� ������� ������ ����ϴ°ɷ� �ذ�
	vector<BezierPoint> moveList;
};
//

class enemy :public gameNode
{
protected:
	image* bodyImg;
	vector<image*> bodyParts;
	RECT rc;


	int curFrameX;
	int curFrameY;

	int count;
	int fireCount;
	int rndFireCount;
	vector<MoveSet> phase;
	int HP;
public:

	HRESULT init(void);
	HRESULT init(const char* img, POINT position);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	void move();
	void draw();
	void setPhase(int index, BezierPoint* movepoints, int frames);

	bool bulletCountFire();

	inline RECT getRect() { return rc; }

	BezierPoint POnCubicBezier(BezierPoint* cp, float t);
	void computeBezier(BezierPoint* cp, int numOfPoints, int index);


	enemy();
	~enemy();
};