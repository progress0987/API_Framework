#include "stdafx.h"
#include "Animation.h"


Animation::Animation():frameNum(0),frameWidth(0),frameHeight(0),loop(FALSE),frameUpdateSec(0),elapsedSec(0),nowPlayIndex(0),play(FALSE)
{
}


Animation::~Animation()
{
}

HRESULT Animation::init(int totalW, int totalH, int frameW, int frameH)
{
	//������ ���� ����
	frameWidth = frameW;
	int frameNumWidth = totalW / frameWidth;

	//������ ���� ����
	frameHeight = frameH;
	int frameNumHeight = totalH / frameHeight;

	for (int i = 0;i< frameNumHeight; i++) {
		for (int j = 0; j < frameNumWidth; j++) {
			POINT framePos;
			framePos.x = j*frameWidth;
			framePos.y = i*frameHeight;

			frameList.push_back(framePos);
		}

	}
	setDefPlayFrame();

	return S_OK;
}

void Animation::release()
{
}

void Animation::setDefPlayFrame(BOOL reverse, BOOL loop)
{
	//���� ����
	this->loop = loop;

	//�÷��� ����Ʈ �ʱ�ȭ
	playList.clear();

	if (reverse) {
		if (this->loop) {
			for (int i = 0; i < frameNum; i++) {//������
				playList.push_back(i);
			}
			for (int i = frameNum - 1; i > 0; i--) {
				playList.push_back(i);
			}
		}
		else {
			for (int i = 0; i < frameNum; i++) {//������
				playList.push_back(i);
			}
		}
	}
	else {
		if (this->loop) {
			for (int i = 0; i < frameNum; i++) {//������
				playList.push_back(i);
			}
			for (int i = frameNum - 1; i > 0; i--) {
				playList.push_back(i);
			}
		}
		else {
			for (int i = 0; i < frameNum; i++) {//������
				playList.push_back(i);
			}
		}
	}
}
//�迭 �ִϸ��̼�
void Animation::setPlayFrame(int * playArr, int arrLen, BOOL loop)
{

	this->loop = loop;
	playList.clear();
	for (int i = 0; i < arrLen; i++) {
		playList.push_back(playArr[i]);
	}
}
//���� �ִϸ��̼�
void Animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop)
{
	this->loop = loop;
	playList.clear();
	//ù�� == ���� -> 1��¥��
	if (start == end) {
		playList.clear();
		stop();
		return;
	}
	//�ε��� ��ȣ�� ���� ũ�� - ����
	if (start > end) {
		if (reverse) {
			if (this->loop) {
				for (int i = start; i >= end; i++) {
					playList.push_back(i);
				}
				for (int i = end + 1; i < start; i--) {
					playList.push_back(i);
				}
			}
			else {
				for (int i = end + 1; i < start; i--) {
					playList.push_back(i);
				}
			}
		}
		else {
			if (this->loop) {
				for (int i = start; i >= end; i++) {
					playList.push_back(i);
				}
				for (int i = end + 1; i < start; i++) {
					playList.push_back(i);
				}
			}
			else {
				for (int i = start; i >= end; i++) {
					playList.push_back(i);
				}
			}
		}
	}
	else {
		if (reverse) {
			if (this->loop) {
				for (int i = start; i < end; i++) {
					playList.push_back(i);
				}
				for (int i = end - 1; i > start; i--) {
					playList.push_back(i);
				}
			}
			else {
				for (int i = start; i < end; i++) {
					playList.push_back(i);
				}
				for (int i = end - 1; i > start; i--) {
					playList.push_back(i);
				}
			}
		}
		else {
			if (this->loop) {
				for (int i = start; i < end; i++) {
					playList.push_back(i);
				}
				for (int i = end - 1; i > start; i--) {
					playList.push_back(i);
				}
			}
			else {
				for (int i = start; i < end; i++) {
					playList.push_back(i);
				}
				for (int i = end - 1; i > start; i--) {
					playList.push_back(i);
				}
			}
				for (int i = start; i < end; i++) {
					playList.push_back(i);
				}
		}
	}
}

void Animation::setFPS(int framePerSec)
{
	frameUpdateSec = 1.0f/framePerSec;
}

void Animation::frameUpdate(float elapsedTime)
{
	if (play) {
		elapsedSec += elapsedTime;
		//�������� ������Ʈ�ؾ��ϴ°��
		if (elapsedSec >= frameUpdateSec) {
			elapsedSec -= frameUpdateSec;
			nowPlayIndex++;
			//������ ����� ���
			if (nowPlayIndex == playList.size()) {
				if (this->loop) nowPlayIndex = 0;
				else {
					nowPlayIndex--;
					play = FALSE;
				}
			}
		}
	}
}

void Animation::start()
{
	play = TRUE;
	nowPlayIndex = 0;
}

void Animation::stop()
{
	play = FALSE;
	nowPlayIndex = 0;
}

void Animation::pause()
{
	play = FALSE;
}

void Animation::resume()
{
	play = TRUE;
}
