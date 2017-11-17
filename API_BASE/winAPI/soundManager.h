#pragma once
#include "singletonBase.h"
#include <map>
//fmod.hpp �߰�
#include "inc/fmod.hpp"
//���̺귯�� ��ũ
#pragma comment(lib,"lib/fmodex_vc.lib")

using namespace FMOD;

//�������� ä�� ���� ����(����)
#define SOUNDBUFFER 10
#define EXTRACHANNELBUFFER 5

//�� ���� ����
#define TOTALSOUNDBUFFER SOUNDBUFFER+EXTRACHANNELBUFFER

class soundManager:public singletonBase<soundManager>
{
private:
	typedef map<string, Sound**>Sounds;
	typedef map<string, Sound**>::iterator SoundsIter;
	typedef map<string, Sound**>Channels;
	typedef map<string, Sound**>::iterator ChannelsIter;

	System* system;
	Sound** sound;
	Channel** channel;
	Sounds totalSounds;
public:
	HRESULT init(void);
	void release(void);
	void update(void);

	void addSound(string keyName, string soundName, bool bgm, bool loop);
	void play(string keyName, float volume = 1.0f);//������ 0~1.0
	void stop(string keyNBame);
	void pause(string keyName);
	void resume(string keyName);

	bool isPlaySound(string keyName);
	bool isPauseSound(string keyName);


	soundManager();
	~soundManager();
};

