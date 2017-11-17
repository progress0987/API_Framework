#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"


//private�� public���� ������ �� �ְ� ������ִ°��� friend �� ����Ѵ�.
DWORD CALLBACK loadingThread(LPVOID lpv)
{
	sceneManager::readyScene->init();

	sceneManager::curScene = sceneManager::readyScene;
	sceneManager::loadingScene = sceneManager::readyScene = NULL;

	return 0;
}

gameNode* sceneManager::curScene = NULL;
gameNode* sceneManager::loadingScene = NULL;
gameNode* sceneManager::readyScene = NULL;
HRESULT sceneManager::init(void)
{
	curScene = NULL;
	loadingScene = NULL;
	readyScene = NULL;
	return S_OK;
}

void sceneManager::release(void)
{
	SceneIter i = sceneLists.begin();
	for (; i != sceneLists.end();) {
		if (i->second != NULL) {
			if (i->second == curScene) {
				i->second->release();
			}
			SAFE_DELETE(i->second);
			i = sceneLists.erase(i);
		}
		else {
			i++;
		}
	}
}

void sceneManager::update(void)
{
	if (curScene) curScene->update();
}

void sceneManager::render()
{
	if (curScene) curScene->render();
}

gameNode * sceneManager::addScene(string sceneName, gameNode * scene)
{
	if (!scene) return NULL;
	sceneLists.insert(make_pair(sceneName, scene));
	return scene;
}

gameNode * sceneManager::addLoadingScene(string loadingSceneName, gameNode * scene)
{
	if (!scene) return NULL;
	sceneLists.insert(make_pair(loadingSceneName, scene));
	return scene;
}

HRESULT sceneManager::changeScene(string sceneName)
{
	SceneIter i = sceneLists.find(sceneName);
	//���� �������������� E_FAIL ����
	if (i == sceneLists.end())return E_FAIL;
	//���� ���̸� OK����
	if (i->second == curScene) return S_OK;
	//�� ��ȯ�� �����ϸ�
	if (SUCCEEDED(i->second->init())) {
		if (curScene) curScene->release();

		curScene = i->second;
		return S_OK;
	}
}

HRESULT sceneManager::changeScene(string sceneName, string loadingSceneName)
{
	SceneIter i = sceneLists.find(sceneName);
	SceneIter l = loadingSceneLists.find(loadingSceneName);
	//���� �������������� E_FAIL ����
	if (i == sceneLists.end())return E_FAIL;
	//���� ���̸� OK����
	if (i->second == curScene) return S_OK;
	if (i == loadingSceneLists.end())return changeScene(loadingSceneName);

	//�� ��ȯ�� �����ϸ�
	if (SUCCEEDED(i->second->init())) {
		loadingScene = l->second;
		readyScene = i->second;

		CloseHandle(CreateThread(NULL, 0, loadingThread, NULL, 0, &loadingThreadID));
		return S_OK;
	}
}

sceneManager::sceneManager()
{
}


sceneManager::~sceneManager()
{
}

