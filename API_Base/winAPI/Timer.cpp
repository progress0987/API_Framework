#include "stdafx.h"
#include "Timer.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

//timeGettime�Լ��� ����ϱ����� ���̺귯�� �߰�
//�����찡 ���۵ǰ� �� ���� �ð��� ����


HRESULT Timer::init()
{
	//���� Ÿ�̸� �������θ� üũ
	//���� Ÿ�̸Ӹ� �����ϸ� �ʴ� ����ũ�μ�������� ���� ó������.(1/1000000)
	//
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&periodFreqency)) {
		//64��Ʈ ������ ����� �� �ֵ��� ������ ������ ����ũ�� ����������� �����Ͽ� ���� �� ��Ȯ�� �ð����� �����ϱ� ����.
		isHardware = true;
		QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);

		//�ʴ� �ð� ��� ����
		timeScale = 1.0f / periodFreqency;
	}
	else {
		isHardware = false;
		//�и������� ������ �ð����� ó�� , 1/1000��
		lastTime = timeGetTime();
		timeScale = 0.001f;

	}
	frameRate = FPSFrameCount = 0;
	FPStimeElapsed = worldTime = 0.0f;

	return S_OK;
}

void Timer::tick(float lockFPS)
{
	//���� Ÿ�̸�����
	if (isHardware) {
		//����ũ�μ����� ������ ��� - 1/1000000 ��
		QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
	}
	else {
		//�Ϲ� �и������� ������ ��� - 1/1000 ��
		curTime = timeGetTime();
	}
	//������ �ð��� ����ð��� �����
	timeElapsed = (curTime - lastTime)*timeScale;

	if (lockFPS > 0.0f) {
		//���������� �ð��� �����Ҷ����� ����
		while (timeElapsed < (1.0f / lockFPS)) {
			if (isHardware) QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
			else curTime = timeGetTime();

			//�������ð��� ����ð��� �����
			timeElapsed = (curTime - lastTime)*timeScale;
		}
		
	}
	//������ �ð��� ���
	lastTime = curTime;
	//�ڵ����� ������ī��Ʈ ����
	FPSFrameCount++;
	//�ʴ� ������ �ð� ����� ����
	FPStimeElapsed += timeElapsed;
	//��ü �ð� ����� ����
	worldTime += timeElapsed;

	//������ �ʱ�ȭ�� 1�ʸ��� ����
	if (FPStimeElapsed > 1.0f) {
		frameRate = FPSFrameCount;
		FPSFrameCount = 0;
		FPStimeElapsed = 0.0f;
	}
}

//���� fps ��������
unsigned long Timer::getFrameRate(char * str) const
{
	if (str != nullptr) {
		wsprintf(str, "FPS : %d", frameRate);
	}
	return frameRate;
}

Timer::Timer()
{
}


Timer::~Timer()
{
}
