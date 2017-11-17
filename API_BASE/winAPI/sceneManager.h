#pragma once
#include "singletonBase.h"
#include <string>
#include <map>

class gameNode;

using namespace std;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*> Scenelists;
	typedef map<string, gameNode*>::iterator SceneIter;

private:
	static gameNode* curScene;
	static gameNode* loadingScene;
	static gameNode* readyScene;
	
	Scenelists sceneLists;
	Scenelists loadingSceneLists;

	DWORD loadingThreadID;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	
	//�� �߰�
	gameNode* addScene(string sceneName, gameNode* scene);
	//�ε��� �߰�
	gameNode* addLoadingScene(string loadingSceneName, gameNode* scene);

	HRESULT changeScene(string sceneName);
	HRESULT changeScene(string sceneName, string loadingSceneName);

	friend DWORD CALLBACK loadingThread(LPVOID lpv);

	sceneManager();
	~sceneManager();
};

