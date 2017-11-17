#include "stdafx.h"
#include "soundTest.h"


soundTest::soundTest()
{
}


soundTest::~soundTest()
{

}
HRESULT soundTest::init(void)
{
	SOUNDMANAGER->addSound("������ġ", "Sounds/�����.mp3", true, true);
	//SOUNDMANAGER->play("������ġ");

	return S_OK;
}
void soundTest::release(void)
{

}
void soundTest::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		SOUNDMANAGER->play("������ġ", 1.0f);
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		SOUNDMANAGER->stop("������ġ");
	}
}
