#pragma once
#include "Animation.h"



/***********************************************************************
						170927
						IMG MANAGER

***********************************************************************/
class image
{
public:
	enum IMAGE_LOAD_KIND {
		LOAD_RESOURCE,		//���ҽ��κ���
		LOAD_FILE,			//���Ϸκ���
		LOAD_EMPTY,
		LOAD_END
	};
	typedef struct imgInfo {

		//Dword�� ȣȯ�� �ƿ� �Ұ���. 4byte �� �Ѱ�
		//LONG �� 32��Ʈ���� ȣȯ�� ������ 4byte
		//int�� 64��Ʈ���� ȣȯ�� ������ 4byte
		//�翬������ ȣȯ�� �����ϴٸ� �Ҿ������⶧���� ��ǻ�ʹ� ȣȯ�����ʴ� DWORD�� ��ȣ�Ѵ�.
		DWORD resID;			//���ҽ� ID
		HDC hMemDC;				//�޸� DC
		HDC hRMemDC;			//ȸ�� �޸� DC
		HBITMAP hBit;			//���ο� ��Ʈ�� �ڵ�
		HBITMAP hRBit;			//ȸ���� ��Ʈ�� �ڵ�
		HBITMAP hOBit;			//���� ��Ʈ�� �ڵ�
		float x;
		float y;
		int width;
		int height;
		int currentFrameX;		//������ �̹��� ��ȣ(����)
		int currentFrameY;		//������ �̹��� ��ȣ(����)
		int maxFrameX;			//������ ����ȣ(����)
		int maxFrameY;			//������ ����ȣ(����)
		int frameWidth;			//������ �̹��� ����� ���� ũ��
		int frameHeight;		//������ �̹��� ����� ���� ũ��

		BYTE loadType;			//�ε��ϴ� Ÿ��(���� IMAGE_LOAD_KIND�� ����)

		imgInfo() {
			resID =			0;
			hMemDC =		NULL;
			hBit =			NULL;
			hOBit =			NULL;
			x =				0;
			y =				0;
			width =			0;
			height =		0;

			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX =		0;
			maxFrameY =		0;
			frameWidth =	0;
			frameHeight =	0;

			loadType =		LOAD_RESOURCE;
		}
	}IMG_INFO, *LPIMG_INFO ;//*LPIMG_INFO �� �̹����� �������� �Ҵ����� �� �ְ� �ϱ�����.(�����̹��� ���߻��)
private:
		LPIMG_INFO		imgInfo;		//�̹��� ����ü
		CHAR*			fileName;		//���� �̸�
		BOOL			trans;			//���� ������ �ִ���
		COLORREF		transColor;		//� ������ ������(RGB������)
		BLENDFUNCTION	alphaBlendFunc;	//���ĺ��带 ���� ����
		LPIMG_INFO		alphaBlendImg;	//���ĺ��带 ���� �̹��� ����

public:
	image();
	~image();
	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height, BOOL trans = FALSE, COLORREF transColor=FALSE);							//���Ϸ� �̹��� ���
	HRESULT init(const char* fileName,float x, float y, int width, int height, BOOL trans = FALSE, COLORREF transColor=FALSE);			//�ڸ��κ����� �̹��� ���
	HRESULT	init(const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans, COLORREF tranCol);	//���������� �ڸ���
	HRESULT init(const char* fileName, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transCol);					//��ü�� ���������� �ڸ���

	void release();
	void setTransColor(BOOL trans, COLORREF transColor);

	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY,int sourX, int sourY, int sourWidth, int sourHeight);
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);
	void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(HDC hdc, const LPRECT drawArea, int offSetX, int offsetY,BYTE alpha);//alpha - 0-255

	void alphaFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY,BYTE alpha);
	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc,int destX, int destY,int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);
	void aniRender(HDC hdc, int destX, int destY, Animation* ani);

	//void rotateRender(HDC hdc, int destX, int destY, float angle);
private:
	HBITMAP GetRotatedBitmap(HDC hdc, int source_x, int source_y,
		int dest_width, int dest_height,int pivotX, int pivotY, float angle, COLORREF bkColor);
public:
	//������ 0~360�� ����
	void rotatedRender(HDC hdc, int destX, int destY, float angle);
	//������ 0~360�� ����
	void rotatedRender(HDC hdc, int destX, int destY, int pivotX, int pivotY, float angle);

	inline HDC getMemDC(void) { return imgInfo->hMemDC; }
	/*****************************************************************************/
	//�̹��� ������ ���ϰ� �ϱ����� getter, setter
	/*****************************************************************************/
	inline void setX(float x) { imgInfo->x = x; }
	inline float getX() { return imgInfo->x; }

	inline void setY(float y) { imgInfo->y = y; }
	inline float getY() { return imgInfo->y; }

	inline void setCenter(float x, float y) { imgInfo->x = x-(imgInfo->width/2); imgInfo->y = y-(imgInfo->height/2); }
	
	inline float getCenterX() { return imgInfo->maxFrameX <= 0 ? imgInfo->x + (imgInfo->width / 2) : imgInfo->x + (imgInfo->frameWidth / 2); }
	inline float getCenterY() { return imgInfo->maxFrameY <= 0 ? imgInfo->y + (imgInfo->height / 2) : imgInfo->y + (imgInfo->frameHeight / 2); }

	inline void setFrameX(int frameX) { imgInfo->currentFrameX = frameX; if (frameX > imgInfo->maxFrameX)imgInfo->currentFrameX = imgInfo->maxFrameX; }
	inline void setFrameY(int frameY) { imgInfo->currentFrameY = frameY; if (frameY > imgInfo->maxFrameY)imgInfo->currentFrameY = imgInfo->maxFrameY; }

	inline int getMaxFrameX() { return imgInfo->maxFrameX; }
	inline int getMaxFrameY() { return imgInfo->maxFrameY; }

	inline int getFrameX() { return imgInfo->currentFrameX; }
	inline int getFrameY() { return imgInfo->currentFrameY; }
	
	inline int getFrameWidth() { return imgInfo->frameWidth; }
	inline int getFrameHeight() { return imgInfo->frameHeight; }

	inline int getWidth() { return imgInfo->width; }
	inline int getHeight() { return imgInfo->height; }

};

