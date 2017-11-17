#include "stdafx.h"
#include "Effect.h"


HRESULT Effect::init(image * effectImage, int frameW, int frameH, int fps, float elapsedTime)
{
	if (!effectImage) return E_FAIL;

	isRunning = false;
	this->effectImage = effectImage;
	this->elapsedTime = elapsedTime;

	if (!effectAnimation) effectAnimation = new Animation;

	effectAnimation->init(effectImage->getWidth(), effectImage->getHeight(), frameW, frameH);
	effectAnimation->setDefPlayFrame(false, false);
	effectAnimation->setFPS(fps);
	effectAnimation->stop();
}

void Effect::release(void)
{
	effectImage = NULL;
	SAFE_DELETE(effectAnimation);
}

void Effect::update(void)
{

	//���������� �ʴٸ� ����������
	if (!isRunning) return;

	//�ִϸ��̼� ������ ������Ʈ
	effectAnimation->frameUpdate(elapsedTime);

	//�÷��� ���°� �ƴϸ� ���ش�
	if (!effectAnimation->isPlay()) killEffect();
}

void Effect::render(void)
{
	if (!isRunning) return;

	effectImage->aniRender(getMemDC(), x, y, effectAnimation);
}

void Effect::startEffect(int x, int y)
{
	//�̹����� �ִϸ��̼� ���� �ϳ��� ������ �����Ű������
	if (!effectImage || !effectAnimation) return;

	this->x = x - (effectAnimation->getFrameWidth() / 2);
	this->y = y - (effectAnimation->getFrameHeight() / 2);

	isRunning = true;
	effectAnimation->start();
}

void Effect::killEffect(void)
{
	isRunning = false;
}

Effect::Effect()
	: effectImage(NULL),
	effectAnimation(NULL),
	isRunning(false),
	x(0), y(0)
{
}


Effect::~Effect()
{
}
