#pragma once

#include "singletonBase.h"
#include "image.h"
#include <map>




class imageManager : public singletonBase<imageManager>
{
private:
	typedef map<string, image*>mapImageList;
	typedef map<string, image*>::iterator mapImagerIter;

	mapImageList ImageList;

public:

	HRESULT init(void);
	void release(void);
	//�� ��Ʈ��
	image* addImage(string key, int width, int height);

	//���� �̹���
	image* addImage(string key, const char* fileName, int width, int height,bool trans, COLORREF transCol);
	image* addImage(string key, const char* fileName, float x, float y, int width, int height, bool trans, COLORREF transCol);

	//������ �̹���
	image* addFrameImage(string key, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transCol);
	image* addFrameImage(string key, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transCol);

	//Ű ������ �̹��� ã�ƿ��� �Լ�
	image* findImage(string key);

	//�̹��� �����ִ� �Լ�
	BOOL deleteImage(string key);

	//��� �̹��� ����
	BOOL deleteAll();
	void render(string key, HDC hdc);
	void render(string key, HDC hdc, int destX, int destY);
	void render(string key, HDC hdc, int destX, int destY,int sourX, int sourY, int width, int height);


	imageManager();
	~imageManager();
};

