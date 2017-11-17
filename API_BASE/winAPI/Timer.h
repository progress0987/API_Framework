#pragma once
class Timer
{
private:
	bool isHardware;				//���� Ÿ�̸Ӹ� �����ϴ��� Ȯ�ο�
	float timeScale;				//�ð� �����
	float timeElapsed;				//�����Ӵ� �ð����
	__int64 curTime;				//������ �ð�
	__int64 lastTime;				//������ �ð�
	__int64 periodFreqency;			//�ð� �ֱ�


	unsigned long frameRate;		//Frame Per Second
	unsigned long FPSFrameCount;	//FPS count
	float FPStimeElapsed;			//FPS ������ �ð��� ����ð��� ����
	float worldTime;				//��ü �ð������
public:
	HRESULT init();
	//���� �ð� ���
	void tick(float lockFPS = 0.0f);

	//���� FPS ��������
	unsigned long getFrameRate(char* str = nullptr)const;

	//�� �����Ӵ� ����ð�
	float getElapsedTime()const { return timeElapsed; }

	//��ü ��� �ð�
	float getWorldTime() const { return worldTime; }


	Timer();
	~Timer();
};

