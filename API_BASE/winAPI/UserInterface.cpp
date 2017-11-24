#include "stdafx.h"
#include "UserInterface.h"


HRESULT UserInterface::init(void)
{
	finger = IMAGEMANAGER->findImage("커서");
	finger->setFrameY(0);
	finger->setFrameX(0);



	return S_OK;
}

void UserInterface::release(void)
{
}

void UserInterface::update(void)
{
	//인벤토리창 띄우기.
	if (KEYMANAGER->isOnceKeyDown('I'))
	{

	}

	//스텟창 띄우기
	if (KEYMANAGER->isOnceKeyDown('S'))
	{

	}


	//장비창 띄우기
	if (KEYMANAGER->isOnceKeyDown('E'))
	{

	}

}

void UserInterface::render(void)
{
	//마우스 커서 숨기기
	SetCursor(NULL);
	ShowCursor(false);
}

UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
