// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
// C++ 런타임 헤더 파일입니다.
//#include<iostream>


//자주 쓰는 STL
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
// ##내가 만든 헤더파일 요기에 추가!!
//====================================

//====================================
//    ##싱글톤 추가
//====================================


//====================================
//   ##디파인 문 ##(윈도우 초기화 셋팅)
//====================================

#define WINNAME (LPTSTR)(TEXT("API BASE"))
#define WINSTARTX 100
#define WINSTARTY 20
#define WINSIZEX  1366
#define WINSIZEY  768
#define WINSTYLE  WS_CAPTION|WS_SYSMENU



//랜덤함수 디파인
#define RND randomFunction::getSingleton()
//키매니저
#define KEYMANAGER KeyManager::getSingleton()

#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()

#define SOUNDMANAGER soundManager::getSingleton()
#define TXTDATA    txtData::getSingleton()
//===============================================
//   ##매크로 함수 ##(메인게임 릴리즈 부분에서 사용)
//===============================================

#define SAFE_DELETE(p)  {if(p) {delete(p); (p)=nullptr;}}
#define SAFE_DELETE_ARRAY(p)  {if(p) {delete[] (p); (p)=nullptr;}}
#define SAFE_RELEASE(p) {if(p){(p)->release();(p)=nullptr;}}

//=================================================
//   ##전역변수 ## (인스턴스, 윈도우 핸들, 마우스 좌표)
//=================================================

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT ptMouse;


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
