#include "stdafx.h"
#include "SaveLoadTest.h"


void SaveLoadTest::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) save();
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON)) load();

}

void SaveLoadTest::save()
{
	/*
	���� �����
	C - FILE*
	c++ - ifstream,ofstream
	WIN - createFile
	*/
	//////////////////////�׽�Ʈ�κ� - ����///////////////////////

	HANDLE file;
	char str[128] = "�׽�Ʈ��";
	DWORD write;

	file = CreateFile("Test1.txt", GENERIC_WRITE, 0, NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);

	WriteFile(file, str, strlen(str), &write, NULL);
	CloseHandle(file);


	/////////////////////////////////////////////////////////////
}

void SaveLoadTest::load()
{
	///////////////////////////�׽�Ʈ��/////////////////////////////
	HANDLE file;
	char str[128];
	DWORD read;
	file = CreateFile("Test1.txt", GENERIC_READ, 0, NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);

	ReadFile(file, str, strlen(str), &read, NULL);
	CloseHandle(file);
	//�޽����ڽ�
	MessageBox(_hWnd, str, "�ε��Ϸ�", MB_OK);
	//////////////////////////////////////////////////////////////////
}

SaveLoadTest::SaveLoadTest()
{
}


SaveLoadTest::~SaveLoadTest()
{
}
