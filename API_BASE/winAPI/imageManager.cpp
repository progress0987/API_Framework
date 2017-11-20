#include "stdafx.h"
#include "imageManager.h"


imageManager::imageManager()
{
}


imageManager::~imageManager()
{
}

HRESULT imageManager::init(void)
{
	return S_OK;
}

void imageManager::release(void)
{
}

//�� ��Ʈ��
image * imageManager::addImage(string key, int width, int height)
{
	image* img = findImage(key);
	//�̹����� ������ �ش� �̹��� ���
	if (img) return img;

	img = new image;
	if (FAILED(img->init(width, height))) {
		SAFE_DELETE(img);
		return NULL;
	}
	ImageList.insert(make_pair(key, img));
	return img;
}

image * imageManager::addImage(string key, const char * fileName, int width, int height, bool trans, COLORREF transCol)
{
	image* img = findImage(key);
	if (img) return img;
	img = new image;
	if (FAILED(img->init(fileName, width, height, trans, transCol))) {
		SAFE_DELETE(img);
		return NULL;
	}
	ImageList.insert(make_pair(key, img));
	return img;
}

image * imageManager::addImage(string key, const char * fileName, float x, float y, int width, int height, bool trans, COLORREF transCol)
{
	image* img = findImage(key);
	if (img) return img;
	img = new image;
	if (FAILED(img->init(fileName,x,y, width, height, trans, transCol))) {
		SAFE_DELETE(img);
		return NULL;
	}
	ImageList.insert(make_pair(key, img));
	return img;
}

image * imageManager::addFrameImage(string key, const char * fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transCol)
{
	image* img = findImage(key);
	if (img) return img;
	img = new image;
	if (FAILED(img->init(fileName, width, height,frameX,frameY, trans, transCol))) {
		SAFE_DELETE(img);
		return NULL;
	}
	ImageList.insert(make_pair(key, img));
	return img;
}

image * imageManager::addFrameImage(string key, const char * fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transCol)
{
	image* img = findImage(key);
	if (img) return img;
	img = new image;
	if (FAILED(img->init(fileName,x,y, width, height,frameX,frameY, trans, transCol))) {
		SAFE_DELETE(img);
		return NULL;
	}
	ImageList.insert(make_pair(key, img));
	return img;
}

image * imageManager::findImage(string key)
{
	mapImagerIter i = ImageList.find(key);

	//Ű ���� ã����� �ش� Ű���ش�Ǵ� ���� ����
	if (i != ImageList.end()) {
		return i->second;
	}
	return NULL;
}

BOOL imageManager::deleteImage(string key)
{
	mapImagerIter i = ImageList.find(key);

	//Ű ���� ã����� �ش� Ű���ش�Ǵ� ���� ����
	if (i != ImageList.end()) {
		i->second->release();
		SAFE_DELETE(i->second);
		ImageList.erase(i);
		return true;
	}
	return false;
}

BOOL imageManager::deleteAll()
{
	mapImagerIter i = ImageList.begin();

	for (; i != ImageList.end();) {
		if (i->second != NULL) {
			i->second->release();
			SAFE_DELETE(i->second);
			i = ImageList.erase(i);
		}
		else
			i++;
	}
	ImageList.clear();
	return TRUE;
}

void imageManager::render(string key, HDC hdc)
{
	image* img = findImage(key);
	if (img) img->render(hdc);
}

void imageManager::render(string key, HDC hdc, int destX, int destY)
{
	image* img = findImage(key);
	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(string key, HDC hdc, int destX, int destY, int sourX, int sourY, int width, int height)
{
	image* img = findImage(key);
	if (img) img->render(hdc, destX, destY,sourX,sourY,width,height);
}

void imageManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY)
{
	image* img = findImage(strKey);
	if (img) img->loopRender(hdc, drawArea, offSetX, offSetY);
}
void imageManager::loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha)
{
	image* img = findImage(strKey);
	if (img) img->loopAlphaRender(hdc, drawArea, offSetX, offSetY, alpha);
}
void imageManager::alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha)
{
	image* img = findImage(strKey);
	if (img) img->alphaRender(hdc, destX, destY, alpha);
}
void imageManager::alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	image* img = findImage(strKey);
	if (img) img->alphaRender(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight, alpha);
}