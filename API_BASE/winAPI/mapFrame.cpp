#include "stdafx.h"
#include "mapFrame.h"


mapFrame::mapFrame()
{
}


mapFrame::~mapFrame()
{
}

HRESULT mapFrame::init()
{
	return S_OK;
}

void mapFrame::release()
{
}

void mapFrame::update()
{
}

void mapFrame::render()
{
}

void mapFrame::soundplay(mapFrame * map)
{
	SOUNDMANAGER->play(bgm);
}

void mapFrame::soundoff(mapFrame * map)
{
	SOUNDMANAGER->stop(bgm);
}
