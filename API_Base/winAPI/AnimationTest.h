#pragma once
#include "gameNode.h"
#include "Animation.h"

//�޾Ƽ� �׽�Ʈ�غ���.
class AnimationTest
{
	image* test;

	Animation* ani1, *ani2, *ani3;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render();


	AnimationTest();
	~AnimationTest();
};

