#include "stdafx.h"
#include "UserInterface.h"


HRESULT UserInterface::init(void)
{
	finger = IMAGEMANAGER->findImage("Ŀ��");
	finger->setFrameY(0);
	finger->setFrameX(0);



	return S_OK;
}

void UserInterface::release(void)
{
}

void UserInterface::update(void)
{
	//�κ��丮â ����.
	if (KEYMANAGER->isOnceKeyDown('I'))
	{

	}

	//����â ����
	if (KEYMANAGER->isOnceKeyDown('S'))
	{

	}


	//���â ����
	if (KEYMANAGER->isOnceKeyDown('E'))
	{

	}

}

void UserInterface::render(void)
{
	//���콺 Ŀ�� �����
	SetCursor(NULL);
	ShowCursor(false);
}

UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
