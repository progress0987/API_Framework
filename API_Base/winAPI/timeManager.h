#pragma once
#include "singletonBase.h"
#include "Timer.h"


class timeManager:public singletonBase<timeManager>
{
private:
	Timer * timer;
public:
	HRESULT init(void);
	void release(void);
	void update(float lock = 0.0f);
	void render(HDC hdc);

	//�� �����Ӵ� ����ð� �������� (1/60)
	float getElapsedTime() const { return timer->getElapsedTime(); }
	//�� ����ð� ��������
	float getWorldTime() const { return timer->getWorldTime(); }

	timeManager();
	~timeManager();
};

