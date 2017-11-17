// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
// C++ ��Ÿ�� ��� �����Դϴ�.
//#include<iostream>


//���� ���� STL
#include<string>
#include<vector>
#include<list>
#include<map>

#include"commonMacroFunction.h"
#include"randomFuction.h"
#include"KeyManager.h"
#include"utils.h"
#include"imageManager.h"
#include "timeManager.h"
#include "txtData.h"
#include "soundManager.h"

using namespace std;
using namespace Util;
//====================================
// ##���� ���� ������� ��⿡ �߰�!!
//====================================

//====================================
//    ##�̱��� �߰�
//====================================


//====================================
//   ##������ �� ##(������ �ʱ�ȭ ����)
//====================================

#define WINNAME (LPTSTR)(TEXT("API BASE"))
#define WINSTARTX 100
#define WINSTARTY 50
#define WINSIZEX  1280
#define WINSIZEY  720
#define WINSTYLE  WS_CAPTION|WS_SYSMENU



//�����Լ� ������
#define RND randomFunction::getSingleton()
//Ű�Ŵ���
#define KEYMANAGER KeyManager::getSingleton()

#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()

#define SOUNDMANAGER soundManager::getSingleton()
#define TXTDATA    txtData::getSingleton()
//===============================================
//   ##��ũ�� �Լ� ##(���ΰ��� ������ �κп��� ���)
//===============================================

#define SAFE_DELETE(p)  {if(p) {delete(p); (p)=nullptr;}}
#define SAFE_DELETE_ARRAY(p)  {if(p) {delete[] (p); (p)=nullptr;}}
#define SAFE_RELEASE(p) {if(p){(p)->release();(p)=nullptr;}}

//=================================================
//   ##�������� ## (�ν��Ͻ�, ������ �ڵ�, ���콺 ��ǥ)
//=================================================

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT ptMouse;


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
