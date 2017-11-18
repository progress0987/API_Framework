#include "stdafx.h"
#include "image.h"
//���ĺ����� ���� ���̺귯��
#pragma comment (lib,"msimg32.lib")

image::image() :imgInfo(NULL), fileName(NULL), trans(false), transColor(RGB(0, 0, 0))
{
}


image::~image()
{
}

HRESULT image::init(int width, int height)
{
	//�̹��� ������ �����ִٸ� ����
	if (imgInfo != NULL) release();
	HDC hdc = GetDC(_hWnd);

	imgInfo = new IMG_INFO;
	imgInfo->loadType = LOAD_EMPTY;
	imgInfo->resID = 0;
	imgInfo->hMemDC = CreateCompatibleDC(hdc);
	imgInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	imgInfo->hOBit = (HBITMAP)SelectObject(imgInfo->hMemDC, imgInfo->hBit);
	imgInfo->width = width;
	imgInfo->height = height;
	//���ĺ���
	alphaBlendFunc.BlendFlags = 0;
	alphaBlendFunc.AlphaFormat = 0;			//32��Ʈ�� ��� AC_SRC_ALPHA�� �����ϰ� �� �ܿ��� 0���� 
	alphaBlendFunc.BlendOp = AC_SRC_OVER;//���� ������

	alphaBlendImg = new IMG_INFO;
	alphaBlendImg->loadType = LOAD_EMPTY;
	alphaBlendImg->resID = 0;
	alphaBlendImg->hMemDC = CreateCompatibleDC(hdc);
	alphaBlendImg->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, imgInfo->width, imgInfo->height);
	alphaBlendImg->hOBit = (HBITMAP)SelectObject(alphaBlendImg->hMemDC, alphaBlendImg->hBit);
	alphaBlendImg->width = WINSIZEX;
	alphaBlendImg->height = WINSIZEY;


	fileName = NULL;
	trans = FALSE;
	transColor = RGB(0, 0, 0);
	if (imgInfo->hBit = 0) {
		release();
		return E_FAIL;
	}
	ReleaseDC(_hWnd, hdc);
	return S_OK;

}

//���Ϸ� �̹��� ���
HRESULT image::init(const char * fileName, int width, int height, BOOL trans, COLORREF transColor)
{
	if (fileName == NULL)return E_FAIL;
	if (imgInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	imgInfo = new IMG_INFO;
	imgInfo->loadType = LOAD_FILE;
	imgInfo->resID = 0;
	imgInfo->hMemDC = CreateCompatibleDC(hdc);
	imgInfo->hRMemDC = CreateCompatibleDC(hdc);
	imgInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imgInfo->hRBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imgInfo->hOBit = (HBITMAP)SelectObject(imgInfo->hMemDC, imgInfo->hBit);
	imgInfo->width = width;
	imgInfo->height = height;
	//////////////////////////���ĺ���κ�///////////////////////////////
	alphaBlendFunc.BlendFlags = 0;
	alphaBlendFunc.AlphaFormat = 0;			//32��Ʈ�� ��� AC_SRC_ALPHA�� �����ϰ� �� �ܿ��� 0���� 
	alphaBlendFunc.BlendOp = AC_SRC_OVER;//���� ������

	alphaBlendImg = new IMG_INFO;
	alphaBlendImg->loadType = LOAD_EMPTY;
	alphaBlendImg->resID = 0;
	alphaBlendImg->hMemDC = CreateCompatibleDC(hdc);
	alphaBlendImg->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, imgInfo->width, imgInfo->height);
	alphaBlendImg->hOBit = (HBITMAP)SelectObject(alphaBlendImg->hMemDC, alphaBlendImg->hBit);
	alphaBlendImg->width = WINSIZEX;
	alphaBlendImg->height = WINSIZEY;
	//////////////////////////////////////////////////////////

	int len = strlen(fileName);

	this->fileName = new CHAR[len + 1];
	strcpy_s(this->fileName, len + 1, fileName);

	this->trans = trans;
	this->transColor = transColor;

	if (imgInfo->hBit == 0) {
		release();
		return E_FAIL;
	}
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

HRESULT image::init(const char * fileName, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transCol)
{
	if (fileName == NULL)return E_FAIL;
	if (imgInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	imgInfo = new IMG_INFO;
	imgInfo->loadType = LOAD_FILE;
	imgInfo->resID = 0;
	imgInfo->hMemDC = CreateCompatibleDC(hdc);
	imgInfo->hRMemDC = CreateCompatibleDC(hdc);
	imgInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imgInfo->hRBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imgInfo->hOBit = (HBITMAP)SelectObject(imgInfo->hMemDC, imgInfo->hBit);
	imgInfo->width = width;
	imgInfo->height = height;
	imgInfo->currentFrameX = 0;
	imgInfo->currentFrameY = 0;
	imgInfo->frameWidth = width / frameX;
	imgInfo->frameHeight = height / frameY;
	imgInfo->maxFrameX = frameX - 1;
	imgInfo->maxFrameY = frameY - 1;

	//////////////////////////���ĺ���κ�///////////////////////////////
	alphaBlendFunc.BlendFlags = 0;
	alphaBlendFunc.AlphaFormat = 0;			//32��Ʈ�� ��� AC_SRC_ALPHA�� �����ϰ� �� �ܿ��� 0���� 
	alphaBlendFunc.BlendOp = AC_SRC_OVER;//���� ������

	alphaBlendImg = new IMG_INFO;
	alphaBlendImg->loadType = LOAD_EMPTY;
	alphaBlendImg->resID = 0;
	alphaBlendImg->hMemDC = CreateCompatibleDC(hdc);
	alphaBlendImg->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, imgInfo->width, imgInfo->height);
	alphaBlendImg->hOBit = (HBITMAP)SelectObject(alphaBlendImg->hMemDC, alphaBlendImg->hBit);
	alphaBlendImg->width = WINSIZEX;
	alphaBlendImg->height = WINSIZEY;
	//////////////////////////////////////////////////////////
	int len = strlen(fileName);

	this->fileName = new CHAR[len + 1];
	strcpy_s(this->fileName, len + 1, fileName);

	this->trans = trans;
	this->transColor = transCol;

	if (imgInfo->hBit == 0) {
		release();
		return E_FAIL;
	}
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

HRESULT image::init(const char * fileName, float x, float y, int width, int height, BOOL trans, COLORREF transColor)
{
	if (fileName == NULL)return E_FAIL;
	if (imgInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	imgInfo = new IMG_INFO;
	imgInfo->loadType = LOAD_FILE;
	imgInfo->resID = 0;
	imgInfo->hMemDC = CreateCompatibleDC(hdc);
	imgInfo->hRMemDC = CreateCompatibleDC(hdc);
	imgInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imgInfo->hRBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imgInfo->hOBit = (HBITMAP)SelectObject(imgInfo->hMemDC, imgInfo->hBit);
	imgInfo->x = x;
	imgInfo->y = y;
	imgInfo->width = width;
	imgInfo->height = height;

	//////////////////////////���ĺ���κ�///////////////////////////////
	alphaBlendFunc.BlendFlags = 0;
	alphaBlendFunc.AlphaFormat = 0;			//32��Ʈ�� ��� AC_SRC_ALPHA�� �����ϰ� �� �ܿ��� 0���� 
	alphaBlendFunc.BlendOp = AC_SRC_OVER;//���� ������

	alphaBlendImg = new IMG_INFO;
	alphaBlendImg->loadType = LOAD_EMPTY;
	alphaBlendImg->resID = 0;
	alphaBlendImg->hMemDC = CreateCompatibleDC(hdc);
	alphaBlendImg->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, imgInfo->width, imgInfo->height);
	alphaBlendImg->hOBit = (HBITMAP)SelectObject(alphaBlendImg->hMemDC, alphaBlendImg->hBit);
	alphaBlendImg->width = WINSIZEX;
	alphaBlendImg->height = WINSIZEY;
	//////////////////////////////////////////////////////////
	int len = strlen(fileName);

	this->fileName = new CHAR[len + 1];
	strcpy_s(this->fileName, len + 1, fileName);

	this->trans = trans;
	this->transColor = transColor;

	if (imgInfo->hBit == 0) {
		release();
		return E_FAIL;
	}
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

HRESULT image::init(const char * fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transCol)
{
	if (fileName == NULL)return E_FAIL;
	if (imgInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	imgInfo = new IMG_INFO;
	imgInfo->loadType = LOAD_FILE;
	imgInfo->resID = 0;
	imgInfo->hMemDC = CreateCompatibleDC(hdc);
	imgInfo->hRMemDC = CreateCompatibleDC(hdc);
	imgInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imgInfo->hRBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imgInfo->hOBit = (HBITMAP)SelectObject(imgInfo->hMemDC, imgInfo->hBit);
	imgInfo->x = x - (width / 2);
	imgInfo->y = y - (height / 2);
	imgInfo->width = width;
	imgInfo->height = height;
	imgInfo->currentFrameX = 0;
	imgInfo->currentFrameY = 0;
	imgInfo->frameWidth = width / frameX;
	imgInfo->frameHeight = height / frameY;
	imgInfo->maxFrameX = frameX - 1;
	imgInfo->maxFrameY = frameY - 1;

	//////////////////////////���ĺ���κ�///////////////////////////////
	alphaBlendFunc.BlendFlags = 0;
	alphaBlendFunc.AlphaFormat = 0;			//32��Ʈ�� ��� AC_SRC_ALPHA�� �����ϰ� �� �ܿ��� 0���� 
	alphaBlendFunc.BlendOp = AC_SRC_OVER;//���� ������

	alphaBlendImg = new IMG_INFO;
	alphaBlendImg->loadType = LOAD_EMPTY;
	alphaBlendImg->resID = 0;
	alphaBlendImg->hMemDC = CreateCompatibleDC(hdc);
	alphaBlendImg->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, imgInfo->width, imgInfo->height);
	alphaBlendImg->hOBit = (HBITMAP)SelectObject(alphaBlendImg->hMemDC, alphaBlendImg->hBit);
	alphaBlendImg->width = WINSIZEX;
	alphaBlendImg->height = WINSIZEY;
	//////////////////////////////////////////////////////////
	int len = strlen(fileName);

	this->fileName = new CHAR[len + 1];
	strcpy_s(this->fileName, len + 1, fileName);

	this->trans = trans;
	this->transColor = transCol;

	if (imgInfo->hBit == 0) {
		release();
		return E_FAIL;
	}
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}


void image::release()
{
	if (imgInfo) {
		SelectObject(imgInfo->hMemDC, imgInfo->hOBit);
		DeleteObject(imgInfo->hBit);
		DeleteDC(imgInfo->hMemDC);

		////////////////////////���ĺ��� ������//////////////////////
		SelectObject(alphaBlendImg->hMemDC, alphaBlendImg->hOBit);
		DeleteObject(alphaBlendImg->hOBit);
		DeleteObject(alphaBlendImg->hMemDC);
		SAFE_DELETE(imgInfo);
		SAFE_DELETE(fileName);
		SAFE_DELETE(alphaBlendImg);

		trans = false;
		transColor = RGB(0, 0, 0);
	}
}

void image::setTransColor(BOOL trans, COLORREF transColor)
{
	this->trans = trans;
	this->transColor = transColor;
}

void image::render(HDC hdc)
{
	if (trans) {
		GdiTransparentBlt(hdc,
			imgInfo->x,
			imgInfo->y,
			imgInfo->width,
			imgInfo->height,
			imgInfo->hMemDC,
			0, 0,
			imgInfo->width,
			imgInfo->height,
			transColor
		);
	}
	else {
		BitBlt(hdc, imgInfo->x, imgInfo->y,
			imgInfo->width, imgInfo->height,
			imgInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void image::render(HDC hdc, int destX, int destY)
{
	if (trans) {
		GdiTransparentBlt(
			hdc,
			destX,
			destY,
			imgInfo->width,
			imgInfo->height,
			imgInfo->hMemDC,
			0,
			0,
			imgInfo->width,
			imgInfo->height,
			transColor
		);
	}
	else {
		BitBlt(
			hdc,
			destX,
			destY,
			imgInfo->width,
			imgInfo->height,
			imgInfo->hMemDC,
			0,
			0,
			SRCCOPY
		);
	}
}

void image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	if (trans) {
		GdiTransparentBlt(
			hdc,					//����� ������ DC				BackDC
			destX,					//����� ��ǥ X(Left)			BackDC�� ������ǥ
			destY,					//����� ��ǥ Y(Top)			BackDC�� ������ǥ
			sourWidth,				//����� ũ�� ��				BackDC�� ������ǥ�κ����� ��
			sourHeight,				//����� ũ�� ����				BackDC�� ������ǥ�κ����� ����(������)
			imgInfo->hMemDC,		//������ DC						���⼭�� hdc
			sourX,					//������ X��ǥ					�̹����� ��ǥ(�������ϰ���ε�)
			sourY,					//������ Y��ǥ					�̹����� ��ǥ
			sourWidth,				//������ ��						�߶��� �̹����� ��
			sourHeight,				//������ ����					�߶��� �̹����� ����
			transColor				//�������� ����					RGB
		);
	}
	else {
		BitBlt(
			hdc,
			destX,
			destY,
			sourWidth,
			sourHeight,
			imgInfo->hMemDC,
			sourX,
			sourY,
			SRCCOPY
		);
	}
}

void image::frameRender(HDC hdc, int destX, int destY)
{
	if (trans) {
		GdiTransparentBlt(
			hdc,											//����� ����� hdc
			destX,											//����� ��ǥ ������ X
			destY,											//����� ��ǥ ������ Y
			imgInfo->frameWidth,							//����� �̹��� ����ũ��
			imgInfo->frameHeight,							//����� �̹��� ����ũ��
			imgInfo->hMemDC,								//������DC
			imgInfo->currentFrameX*imgInfo->frameWidth,
			imgInfo->currentFrameY*imgInfo->frameHeight,
			imgInfo->frameWidth,							//����� ����ũ��
			imgInfo->frameHeight,							//����� ����ũ��
			transColor										//����ó�� �� ��
		);
	}
	else {
		BitBlt(
			hdc,
			destX,
			destY,
			imgInfo->frameWidth,
			imgInfo->frameHeight,
			imgInfo->hMemDC,
			imgInfo->currentFrameX*imgInfo->frameWidth,
			imgInfo->currentFrameY*imgInfo->frameHeight,
			SRCCOPY
		);
	}
}

void image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	imgInfo->currentFrameX = currentFrameX;
	imgInfo->currentFrameY = currentFrameY;
	if (trans) {
		GdiTransparentBlt(
			hdc,											//����� ����� hdc
			destX,											//����� ��ǥ ������ X
			destY,											//����� ��ǥ ������ Y
			imgInfo->frameWidth,							//����� �̹��� ����ũ��
			imgInfo->frameHeight,							//����� �̹��� ����ũ��
			imgInfo->hMemDC,								//������DC
			imgInfo->currentFrameX*imgInfo->frameWidth,
			imgInfo->currentFrameY*imgInfo->frameHeight,
			imgInfo->frameWidth,							//����� ����ũ��
			imgInfo->frameHeight,							//����� ����ũ��
			transColor										//����ó�� �� ��
		);
	}
	else {
		BitBlt(
			hdc,
			destX,
			destY,
			imgInfo->frameWidth,
			imgInfo->frameHeight,
			imgInfo->hMemDC,
			imgInfo->currentFrameX*imgInfo->frameWidth,
			imgInfo->currentFrameY*imgInfo->frameHeight,
			SRCCOPY
		);
	}
}

void image::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	if (offsetX < 0) offsetX = imgInfo->width + (offsetX % imgInfo->width);
	if (offsetY < 0) offsetY = imgInfo->height + (offsetY % imgInfo->height);

	//������ ���� �޾ƿ� ����
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//�׷��ִ� ����
	RECT rcDest;

	//ȭ�鿡 �׷��ִ� ���� ����

	int drawAreaX = drawArea->left;							//x��ǥ
	int drawAreaY = drawArea->top;							//y��ǥ
	int drawAreaW = drawArea->right - drawArea->left;		//��
	int drawAreaH = drawArea->bottom - drawArea->top;		//����

															//Y Axis

	for (int y = 0; y < drawAreaH; y += sourHeight) {
		rcSour.top = (y + offsetY) % imgInfo->height;
		rcSour.bottom = imgInfo->height;

		sourHeight = rcSour.bottom - rcSour.top;
		//�׷����� ������ ���̰����� ũ��
		if (y + sourHeight > drawAreaH) {
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}
		//�ѷ��ִ� ����
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;


		//X Axis
		for (int x = 0; x < drawAreaW; x += sourWidth) {
			rcSour.left = (x + offsetX) % imgInfo->width;
			rcSour.right = imgInfo->width;

			sourWidth = rcSour.right - rcSour.left;

			if (x + sourWidth > drawAreaH) {
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}
			//�ѷ��ִ¿���
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			render(hdc,
				rcDest.left,				//�Ѹ� X
				rcDest.top,					//�Ѹ� Y
				rcSour.left, rcSour.top,		//�ѷ��� X,Y
				rcSour.right - rcSour.left,	//�ѷ��� �̹��� ���� ũ��
				rcSour.bottom - rcSour.top	//�ѷ��� �̹��� ���� ũ��
			);
		}

	}
}

void image::loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{

	if (offsetX < 0) offsetX = imgInfo->width + (offsetX % imgInfo->width);
	if (offsetY < 0) offsetY = imgInfo->height + (offsetY % imgInfo->height);

	//������ ���� �޾ƿ� ����
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//�׷��ִ� ����
	RECT rcDest;

	//ȭ�鿡 �׷��ִ� ���� ����

	int drawAreaX = drawArea->left;							//x��ǥ
	int drawAreaY = drawArea->top;							//y��ǥ
	int drawAreaW = drawArea->right - drawArea->left;		//��
	int drawAreaH = drawArea->bottom - drawArea->top;		//����

															//Y Axis

	for (int y = 0; y < drawAreaH; y += sourHeight) {
		rcSour.top = (y + offsetY) % imgInfo->height;
		rcSour.bottom = imgInfo->height;

		sourHeight = rcSour.bottom - rcSour.top;
		//�׷����� ������ ���̰����� ũ��
		if (y + sourHeight > drawAreaH) {
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}
		//�ѷ��ִ� ����
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;


		//X Axis
		for (int x = 0; x < drawAreaW; x += sourWidth) {
			rcSour.left = (x + offsetX) % imgInfo->width;
			rcSour.right = imgInfo->width;

			sourWidth = rcSour.right - rcSour.left;

			if (x + sourWidth > drawAreaH) {
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}
			//�ѷ��ִ¿���
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			alphaRender(hdc,
				rcDest.left,				//�Ѹ� X
				rcDest.top,					//�Ѹ� Y
				rcSour.left, rcSour.top,		//�ѷ��� X,Y
				rcSour.right - rcSour.left,	//�ѷ��� �̹��� ���� ũ��
				rcSour.bottom - rcSour.top,	//�ѷ��� �̹��� ���� ũ��
				alpha
			);
		}
	}
}

void image::alphaFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha)
{
	imgInfo->currentFrameX = currentFrameX;
	imgInfo->currentFrameY = currentFrameY;
	alphaBlendFunc.SourceConstantAlpha = alpha;

	if (trans) {

		//����ؾ��� DC�� �׷����ִ� ������ �����̹����� �׷���.
		BitBlt(alphaBlendImg->hMemDC, 0, 0, alphaBlendImg->width, alphaBlendImg->height, hdc, destX, destY, SRCCOPY);
		//����ؾ� �� �̹����� ���忡 �׸�
		GdiTransparentBlt(
			alphaBlendImg->hMemDC,											//����� ����� hdc
			0,											//����� ��ǥ ������ X
			0,											//����� ��ǥ ������ Y
			imgInfo->frameWidth,							//����� �̹��� ����ũ��
			imgInfo->frameHeight,							//����� �̹��� ����ũ��
			imgInfo->hMemDC,								//������DC
			imgInfo->currentFrameX*imgInfo->frameWidth,
			imgInfo->currentFrameY*imgInfo->frameHeight,
			imgInfo->frameWidth,							//����� ����ũ��
			imgInfo->frameHeight,							//����� ����ũ��
			transColor										//����ó�� �� ��
		);
		//���� DC�� ����ؾ��� DC�� �׸�.
		AlphaBlend(hdc, destX, destY, imgInfo->frameWidth, imgInfo->frameHeight, alphaBlendImg->hMemDC, 0, 0, imgInfo->frameWidth, imgInfo->frameHeight, alphaBlendFunc);
	}
	//�����̹��� �״�� ���ĺ���
	else {
		AlphaBlend(hdc, destX, destY, imgInfo->frameWidth, imgInfo->frameHeight, imgInfo->hMemDC, imgInfo->currentFrameX*imgInfo->frameWidth, imgInfo->currentFrameY*imgInfo->frameHeight, imgInfo->frameWidth, imgInfo->frameHeight, alphaBlendFunc);
		//���� DC�� ����ؾ��� DC�� �׸�.
	}
}

void image::alphaRender(HDC hdc, BYTE alpha)
{
	alphaBlendFunc.SourceConstantAlpha = alpha;

	if (trans) {
		//����ؾ��� DC�� �׷����ִ� ������ �����̹����� �׷���.
		BitBlt(alphaBlendImg->hMemDC, 0, 0, alphaBlendImg->width, alphaBlendImg->height, hdc, 0, 0, SRCCOPY);
		//����ؾ� �� �̹����� ���忡 �׸�
		GdiTransparentBlt(alphaBlendImg->hMemDC, 0, 0, imgInfo->width, imgInfo->height, imgInfo->hMemDC, 0, 0, imgInfo->width, imgInfo->height, transColor);
		//���� DC�� ����ؾ��� DC�� �׸�.
		AlphaBlend(hdc, 0, 0, imgInfo->width, imgInfo->height, alphaBlendImg->hMemDC, 0, 0, imgInfo->width, imgInfo->height, alphaBlendFunc);
	}
	//�����̹��� �״�� ���ĺ���
	else {
		//���� DC�� ����ؾ��� DC�� �׸�.
		AlphaBlend(hdc, 0, 0, imgInfo->width, imgInfo->height, imgInfo->hMemDC, 0, 0, imgInfo->width, imgInfo->height, alphaBlendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	alphaBlendFunc.SourceConstantAlpha = alpha;

	if (trans) {

		//����ؾ��� DC�� �׷����ִ� ������ �����̹����� �׷���.
		BitBlt(alphaBlendImg->hMemDC, 0, 0, alphaBlendImg->width, alphaBlendImg->height, hdc, destX, destY, SRCCOPY);
		//����ؾ� �� �̹����� ���忡 �׸�
		GdiTransparentBlt(alphaBlendImg->hMemDC, 0, 0, imgInfo->width, imgInfo->height, imgInfo->hMemDC, 0, 0, imgInfo->width, imgInfo->height, transColor);
		//���� DC�� ����ؾ��� DC�� �׸�.
		AlphaBlend(hdc, destX, destY, imgInfo->width, imgInfo->height, alphaBlendImg->hMemDC, 0, 0, imgInfo->width, imgInfo->height, alphaBlendFunc);
	}
	//�����̹��� �״�� ���ĺ���
	else {
		//���� DC�� ����ؾ��� DC�� �׸�.
		AlphaBlend(hdc, destX, destY, imgInfo->width, imgInfo->height, imgInfo->hMemDC, 0, 0, imgInfo->width, imgInfo->height, alphaBlendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	alphaBlendFunc.SourceConstantAlpha = alpha;

	if (trans) {
		//����ؾ��� DC�� �׷����ִ� ������ �����̹����� �׷���.
		BitBlt(alphaBlendImg->hMemDC, 0, 0, sourWidth, sourHeight, hdc, destX, destY, SRCCOPY);
		//����ؾ� �� �̹����� ���忡 �׸�
		GdiTransparentBlt(alphaBlendImg->hMemDC, 0, 0, sourWidth, sourHeight, imgInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, transColor);
		//���� DC�� ����ؾ��� DC�� �׸�.
		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight, alphaBlendImg->hMemDC, 0, 0, sourWidth, sourHeight, alphaBlendFunc);
	}
	//�����̹��� �״�� ���ĺ���
	else {
		//���� DC�� ����ؾ��� DC�� �׸�.
		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight, imgInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, alphaBlendFunc);
	}
}void image::aniRender(HDC hdc, int destX, int destY, Animation* ani)
{
	render(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight());
}

HBITMAP image::GetRotatedBitmap(HDC hdc, int source_x, int source_y,
	int dest_width, int dest_height, int pivotX, int pivotY, float angle, COLORREF bkColor)
{
	HDC sourceDC = CreateCompatibleDC(hdc); // ȸ���� ��Ʈ�� ������ ������ DC
	HDC destDC = CreateCompatibleDC(hdc); // ȸ���� ��Ʈ���� ��¹��� DC
	HBITMAP hbmResult = CreateCompatibleBitmap(hdc, dest_width*2, dest_height*2); // ȸ���� ��Ʈ���� ��¹��� �޸𸮺�Ʈ�� �ڵ�

	HBITMAP hbmOldSource = (HBITMAP)SelectObject(sourceDC, imgInfo->hRBit); // ȸ���� ��Ʈ�� ������ DC�� ����
	HBITMAP hbmOldDest = (HBITMAP)SelectObject(destDC, hbmResult); // ȸ���� ��Ʈ���� ��¹��� DC��, ȸ���� ��Ʈ���� ��¹��� �޸𸮺�Ʈ�� ����

	HBRUSH hbrBack = CreateSolidBrush(bkColor); // ȸ������ ����, ���鿵���� ĥ�� �귯���ڵ� ����
	HBRUSH hbrOld = (HBRUSH)SelectObject(destDC, hbrBack); // �귯���ڵ� ����
	PatBlt(destDC, 0, 0, dest_width, dest_height, PATCOPY); // ���õ� �귯�÷�, ȸ���� ��Ʈ���� ��¹��� DC��, �̸� ������ ä�� ����
	DeleteObject(SelectObject(destDC, hbrOld)); // �귯�� ����

	angle = (float)(angle * PI / 180); // ȸ���� ����(360�й�)��, ���ȴ����� ������ ����
	float cosine = (float)cos(angle); // ȸ���̵���ȯ ��Ŀ� �� cos��Ÿ ���� ����
	float sine = (float)sin(angle); // ȸ���̵���ȯ ��Ŀ� �� sin��Ÿ ���� ����

	SetGraphicsMode(destDC, GM_ADVANCED); // ������ ��ǥ���� ȸ���� ���Ͽ�, �׷��ȸ�带 Ȯ����� �����մϴ�.(�䱸����:��98,NT�̻�)

										  // ȸ���̵���ȯ ����� ����.
										  // (�������� API���� ������ 2�� Page(1279) ����.)
										  // (���� ���α׷��Ӹ� ���� ���ʼ��а� ���� Page(196) ����.)

	XFORM xform; // �������� ǥ���ϴ� 3��3���� ��� ����
	xform.eM11 = cosine; // 1�� 1�� ���� ���� (ȸ������)
	xform.eM12 = -sine; // 1�� 2�� ���� ���� (ȸ������)
	xform.eM21 = sine; // 2�� 1�� ���� ���� (ȸ������)
	xform.eM22 = cosine; // 2�� 2�� ���� ���� (ȸ������)
	xform.eDx = (FLOAT)pivotX; // 3�� 1�� ���� ���� (X�� �̵� ����)
	xform.eDy = (FLOAT)pivotY; // 3�� 2�� ���� ���� (Y�� �̵� ����)

										   // ������ ��ķ�, �μ�DC�� �������� ��ǥ�踦 ��ȯ.
										   // �μ�DC�� ��´������ �޸𸮺�Ʈ���� �����Ƿ�,
										   // �����ϰ� �ִ� �޸𸮺�Ʈ���� ��ǥü�谡 ȸ���ȴ�.

	SetWorldTransform(destDC, &xform);

	// ȸ���� �޸�DC��, ȸ���� �̹����� ���

	BitBlt(destDC, -pivotX, -pivotY, dest_width, dest_height, sourceDC, source_x, source_y, SRCCOPY);

	// ���� �ڿ� ����

	SelectObject(sourceDC, hbmOldSource);
	SelectObject(destDC, hbmOldDest);
	DeleteObject(sourceDC);
	DeleteObject(destDC);

	// ȸ���� ��Ʈ�� �ڵ� ����

	return hbmResult;
}

void image::rotatedRender(HDC hdc, int destX, int destY, float angle)
{
	//HBITMAP test = (HBITMAP)SelectObject(imgInfo->hMemDC, GetRotatedBitmap(hdc, 0, 0, imgInfo->width, imgInfo->height, angle, transColor));

	//GdiTransparentBlt(hdc, destX, destY, imgInfo->width, imgInfo->height, imgInfo->hMemDC, 0, 0, imgInfo->width, imgInfo->height, transColor);
	//------------------------------------------------------------------------------------------------------------------------------
	HBITMAP oRotBIT = (HBITMAP)SelectObject(imgInfo->hRMemDC, GetRotatedBitmap(hdc,  0, 0, imgInfo->width, imgInfo->height, imgInfo->width/2, imgInfo->height/2, angle, transColor));

	GdiTransparentBlt(hdc, destX, destY, imgInfo->width, imgInfo->height, imgInfo->hRMemDC, 0, 0, imgInfo->width, imgInfo->height, transColor);
	SelectObject(imgInfo->hRMemDC, oRotBIT);
	DeleteObject(oRotBIT);

	/*HDC tmp = CreateCompatibleDC(hdc);
	HBITMAP oBit = (HBITMAP)CreateCompatibleBitmap(hdc, imgInfo->width, imgInfo->height);

	HBITMAP test = (HBITMAP)SelectObject(tmp, GetRotatedBitmap(hdc, 0, 0, imgInfo->width, imgInfo->height, angle, transColor));

	GdiTransparentBlt(hdc, destX, destY, imgInfo->width, imgInfo->height, tmp, 0, 0, imgInfo->width, imgInfo->height, transColor);*/
	//DeleteObject(SelectObject(imgInfo->hMemDC, test));
}
void image::rotatedRender(HDC hdc, int destX, int destY, int pivotX, int pivotY, float angle)
{
	HBITMAP oRotBIT = (HBITMAP)SelectObject(imgInfo->hRMemDC, GetRotatedBitmap(hdc, 0, 0, imgInfo->width, imgInfo->height, pivotX, pivotY, angle, transColor));

	if (trans) {
		GdiTransparentBlt(hdc, destX, destY, imgInfo->width, imgInfo->height, imgInfo->hRMemDC, 0, 0, imgInfo->width, imgInfo->height, transColor);
	}
	else {
		BitBlt(hdc,destX,destY,imgInfo->width,imgInfo->height,imgInfo->hRMemDC,0,0, SRCCOPY);
	}
	SelectObject(imgInfo->hRMemDC, oRotBIT);
	DeleteObject(oRotBIT);
}

// �μ� ���
// HDC hdc : ȭ��DC�� �ڵ�. GetRotatedBitmap()�Լ��� ���ڷ� �����ϰ� �˴ϴ�.
// HDC hOffScreen : ȸ�� �̹����� �����, ������ũ��DC�� �ڵ�.
// int dest_x : ������ũ�� �󿡼�, ȸ�� �̹����� ��µ� x��ǥ.
// int dest_y : ������ũ�� �󿡼�, ȸ�� �̹����� ��µ� y��ǥ.
// int dest_width : ȸ���� ��Ʈ�� �̹����� �� ũ�� == ȸ���� ��Ʈ�� �̹����� ��µ� �� ũ��
// int dest_heigjt : ȸ���� ��Ʈ�� �̹����� ���� ũ�� == ȸ���� ��Ʈ�� �̹����� ��µ� ���� ũ��
// HBITMAP hBit : ȸ�� �̹��� ��Ʈ���ڵ�
// int source_x : ȸ�� �̹��� ��Ʈ�ʿ�����, ����� �簢������ �»��x��ǥ.
// int source_y : ȸ�� �̹��� ��Ʈ�ʿ�����, ����� �簢������ �»��y��ǥ.
// DWORD dFlag : ROP��带 ��Ÿ���� �÷��� ��ũ��
// float angle : ȸ���� ����.
// COLORREF bkColor : ȸ���� ���� ���鿵���� ĥ�� ����. �̹��� �簢���� ȸ���ϸ�, ���鿵���� ����ϴ�. (��)���̾Ƹ�� ���·� ȸ���� �簢�������� �ںκ� ����
//

//
//void RotateBlt(HDC hdc, HDC hOffScreen, int dest_x, int dest_y, int dest_width, int dest_height,
//	HBITMAP hBit, int source_x, int source_y, DWORD dFlag, float angle, COLORREF bkColor)
//{
//	static HDC hTempMemDC; // ȸ���� ��Ʈ���� ������ �޸�DC
//	HBITMAP hTempBitmap, hOldBitmap; // ȸ���� ��Ʈ���� ������, ��Ʈ�� �ڵ�
//
//									 // ���� �ѹ��� ��Ʈ��DC�� �����մϴ�.
//
//	if (!hTempMemDC) hTempMemDC = CreateCompatibleDC(hdc);
//
//	// ��Ʈ���� ȸ���ϴ� �Լ��� ȣ���Ͽ�, ���ϵǴ� ȸ���� ��Ʈ�� �ڵ��� ����
//
//	hTempBitmap = GetRotatedBitmap(hdc, hBit, source_x, source_y, dest_width, dest_height, angle, bkColor);
//
//	// ȸ���� ��Ʈ�� �ڵ��� �����ϰ�,
//
//	hOldBitmap = (HBITMAP)SelectObject(hTempMemDC, hTempBitmap);
//
//	// ������ũ��DC��, ȸ���� ��Ʈ�� �ڵ��� ������, �޸�DC�� �̹����� ����մϴ�.
//	// ���� �ּ��� �����ϸ�, �����ǥ�� �߽����� �ϴ� ȸ���̹����� �˴ϴ�.
//
//	BitBlt(hOffScreen, dest_x
//		// - dest_width/2
//		, dest_y - dest_height / 2, dest_width, dest_height, hTempMemDC, 0, 0, dFlag);
//
//	SelectObject(hTempMemDC, hOldBitmap);
//	DeleteObject(hTempBitmap);
//}
