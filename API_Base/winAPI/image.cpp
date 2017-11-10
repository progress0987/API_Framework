#include "stdafx.h"
#include "image.h"
//알파블렌딩을 위한 라이브러리
#pragma comment (lib,"msimg32.lib")

image::image() :imgInfo(NULL), fileName(NULL), trans(false), transColor(RGB(0, 0, 0))
{
}


image::~image()
{
}

HRESULT image::init(int width, int height)
{
	//이미지 정보가 남아있다면 지움
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
	//알파블랜드
	alphaBlendFunc.BlendFlags = 0;
	alphaBlendFunc.AlphaFormat = 0;			//32비트인 경우 AC_SRC_ALPHA를 지정하고 그 외에는 0으로 
	alphaBlendFunc.BlendOp = AC_SRC_OVER;//블랜딩 연산자

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

//파일로 이미지 등록
HRESULT image::init(const char * fileName, int width, int height, BOOL trans, COLORREF transColor)
{
	if (fileName == NULL)return E_FAIL;
	if (imgInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	imgInfo = new IMG_INFO;
	imgInfo->loadType = LOAD_FILE;
	imgInfo->resID = 0;
	imgInfo->hMemDC = CreateCompatibleDC(hdc);
	imgInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imgInfo->hOBit = (HBITMAP)SelectObject(imgInfo->hMemDC, imgInfo->hBit);
	imgInfo->width = width;
	imgInfo->height = height;
	//////////////////////////알파블랜드부분///////////////////////////////
	alphaBlendFunc.BlendFlags = 0;
	alphaBlendFunc.AlphaFormat = 0;			//32비트인 경우 AC_SRC_ALPHA를 지정하고 그 외에는 0으로 
	alphaBlendFunc.BlendOp = AC_SRC_OVER;//블랜딩 연산자

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
	imgInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imgInfo->hOBit = (HBITMAP)SelectObject(imgInfo->hMemDC, imgInfo->hBit);
	imgInfo->width = width;
	imgInfo->height = height;
	imgInfo->currentFrameX = 0;
	imgInfo->currentFrameY = 0;
	imgInfo->frameWidth = width / frameX;
	imgInfo->frameHeight = height / frameY;
	imgInfo->maxFrameX = frameX - 1;
	imgInfo->maxFrameY = frameY - 1;

	//////////////////////////알파블랜드부분///////////////////////////////
	alphaBlendFunc.BlendFlags = 0;
	alphaBlendFunc.AlphaFormat = 0;			//32비트인 경우 AC_SRC_ALPHA를 지정하고 그 외에는 0으로 
	alphaBlendFunc.BlendOp = AC_SRC_OVER;//블랜딩 연산자

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
	imgInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imgInfo->hOBit = (HBITMAP)SelectObject(imgInfo->hMemDC, imgInfo->hBit);
	imgInfo->x = x;
	imgInfo->y = y;
	imgInfo->width = width;
	imgInfo->height = height;

	//////////////////////////알파블랜드부분///////////////////////////////
	alphaBlendFunc.BlendFlags = 0;
	alphaBlendFunc.AlphaFormat = 0;			//32비트인 경우 AC_SRC_ALPHA를 지정하고 그 외에는 0으로 
	alphaBlendFunc.BlendOp = AC_SRC_OVER;//블랜딩 연산자

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
	imgInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
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

	//////////////////////////알파블랜드부분///////////////////////////////
	alphaBlendFunc.BlendFlags = 0;
	alphaBlendFunc.AlphaFormat = 0;			//32비트인 경우 AC_SRC_ALPHA를 지정하고 그 외에는 0으로 
	alphaBlendFunc.BlendOp = AC_SRC_OVER;//블랜딩 연산자

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

		////////////////////////알파블랜드 릴리즈//////////////////////
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
			hdc,					//복사될 영역의 DC				BackDC
			destX,					//복사될 좌표 X(Left)			BackDC의 영역좌표
			destY,					//복사될 좌표 Y(Top)			BackDC의 영역좌표
			sourWidth,				//복사될 크기 폭				BackDC의 영역좌표로부터의 폭
			sourHeight,				//복사될 크기 높이				BackDC의 영역좌표로부터의 높이(밑으로)
			imgInfo->hMemDC,		//복사할 DC						여기서는 hdc
			sourX,					//복사할 X좌표					이미지의 좌표(여러개일경우인듯)
			sourY,					//복사할 Y좌표					이미지의 좌표
			sourWidth,				//복사할 폭						잘라진 이미지의 폭
			sourHeight,				//복사할 높이					잘라진 이미지의 높이
			transColor				//투명잡을 색상					RGB
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
			hdc,											//복사될 장소의 hdc
			destX,											//복사될 좌표 시작점 X
			destY,											//복사될 좌표 시작점 Y
			imgInfo->frameWidth,							//복사될 이미지 가로크기
			imgInfo->frameHeight,							//복사될 이미지 세로크기
			imgInfo->hMemDC,								//복사대상DC
			imgInfo->currentFrameX*imgInfo->frameWidth,
			imgInfo->currentFrameY*imgInfo->frameHeight,
			imgInfo->frameWidth,							//복사될 가로크기
			imgInfo->frameHeight,							//복사될 세로크기
			transColor										//투명처리 할 색
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
			hdc,											//복사될 장소의 hdc
			destX,											//복사될 좌표 시작점 X
			destY,											//복사될 좌표 시작점 Y
			imgInfo->frameWidth,							//복사될 이미지 가로크기
			imgInfo->frameHeight,							//복사될 이미지 세로크기
			imgInfo->hMemDC,								//복사대상DC
			imgInfo->currentFrameX*imgInfo->frameWidth,
			imgInfo->currentFrameY*imgInfo->frameHeight,
			imgInfo->frameWidth,							//복사될 가로크기
			imgInfo->frameHeight,							//복사될 세로크기
			transColor										//투명처리 할 색
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

	//오프셋 영역 받아올 변수
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//그려주는 영역
	RECT rcDest;

	//화면에 그려주는 영역 지정

	int drawAreaX = drawArea->left;							//x좌표
	int drawAreaY = drawArea->top;							//y좌표
	int drawAreaW = drawArea->right - drawArea->left;		//폭
	int drawAreaH = drawArea->bottom - drawArea->top;		//높이

															//Y Axis

	for (int y = 0; y < drawAreaH; y += sourHeight) {
		rcSour.top = (y + offsetY) % imgInfo->height;
		rcSour.bottom = imgInfo->height;

		sourHeight = rcSour.bottom - rcSour.top;
		//그려지는 영역의 높이값보다 크면
		if (y + sourHeight > drawAreaH) {
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}
		//뿌려주는 영역
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
			//뿌려주는영역
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			render(hdc,
				rcDest.left,				//뿌릴 X
				rcDest.top,					//뿌릴 Y
				rcSour.left, rcSour.top,		//뿌려올 X,Y
				rcSour.right - rcSour.left,	//뿌려올 이미지 가로 크기
				rcSour.bottom - rcSour.top	//뿌려올 이미지 세로 크기
			);
		}

	}
}

void image::loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{

	if (offsetX < 0) offsetX = imgInfo->width + (offsetX % imgInfo->width);
	if (offsetY < 0) offsetY = imgInfo->height + (offsetY % imgInfo->height);

	//오프셋 영역 받아올 변수
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//그려주는 영역
	RECT rcDest;

	//화면에 그려주는 영역 지정

	int drawAreaX = drawArea->left;							//x좌표
	int drawAreaY = drawArea->top;							//y좌표
	int drawAreaW = drawArea->right - drawArea->left;		//폭
	int drawAreaH = drawArea->bottom - drawArea->top;		//높이

															//Y Axis

	for (int y = 0; y < drawAreaH; y += sourHeight) {
		rcSour.top = (y + offsetY) % imgInfo->height;
		rcSour.bottom = imgInfo->height;

		sourHeight = rcSour.bottom - rcSour.top;
		//그려지는 영역의 높이값보다 크면
		if (y + sourHeight > drawAreaH) {
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}
		//뿌려주는 영역
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
			//뿌려주는영역
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			alphaRender(hdc,
				rcDest.left,				//뿌릴 X
				rcDest.top,					//뿌릴 Y
				rcSour.left, rcSour.top,		//뿌려올 X,Y
				rcSour.right - rcSour.left,	//뿌려올 이미지 가로 크기
				rcSour.bottom - rcSour.top,	//뿌려올 이미지 세로 크기
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

		//출력해야할 DC에 그려져있는 내용을 블랜드이미지에 그려줌.
		BitBlt(alphaBlendImg->hMemDC, 0, 0, alphaBlendImg->width, alphaBlendImg->height, hdc, destX, destY, SRCCOPY);
		//출력해야 할 이미지를 블랜드에 그림
		GdiTransparentBlt(
			alphaBlendImg->hMemDC,											//복사될 장소의 hdc
			0,											//복사될 좌표 시작점 X
			0,											//복사될 좌표 시작점 Y
			imgInfo->frameWidth,							//복사될 이미지 가로크기
			imgInfo->frameHeight,							//복사될 이미지 세로크기
			imgInfo->hMemDC,								//복사대상DC
			imgInfo->currentFrameX*imgInfo->frameWidth,
			imgInfo->currentFrameY*imgInfo->frameHeight,
			imgInfo->frameWidth,							//복사될 가로크기
			imgInfo->frameHeight,							//복사될 세로크기
			transColor										//투명처리 할 색
		);
		//블랜드 DC를 출력해야할 DC에 그림.
		AlphaBlend(hdc, destX, destY, imgInfo->frameWidth, imgInfo->frameHeight, alphaBlendImg->hMemDC, 0, 0, imgInfo->frameWidth, imgInfo->frameHeight, alphaBlendFunc);
	}
	//원본이미지 그대로 알파블랜딩
	else {
		AlphaBlend(hdc, destX, destY, imgInfo->frameWidth, imgInfo->frameHeight, imgInfo->hMemDC, imgInfo->currentFrameX*imgInfo->frameWidth, imgInfo->currentFrameY*imgInfo->frameHeight, imgInfo->frameWidth, imgInfo->frameHeight, alphaBlendFunc);
		//블랜드 DC를 출력해야할 DC에 그림.
	}
}

void image::alphaRender(HDC hdc, BYTE alpha)
{
	alphaBlendFunc.SourceConstantAlpha = alpha;

	if (trans) {
		//출력해야할 DC에 그려져있는 내용을 블랜드이미지에 그려줌.
		BitBlt(alphaBlendImg->hMemDC, 0, 0, alphaBlendImg->width, alphaBlendImg->height, hdc, 0, 0, SRCCOPY);
		//출력해야 할 이미지를 블랜드에 그림
		GdiTransparentBlt(alphaBlendImg->hMemDC, 0, 0, imgInfo->width, imgInfo->height, imgInfo->hMemDC, 0, 0, imgInfo->width, imgInfo->height, transColor);
		//블랜드 DC를 출력해야할 DC에 그림.
		AlphaBlend(hdc, 0, 0, imgInfo->width, imgInfo->height, alphaBlendImg->hMemDC, 0, 0, imgInfo->width, imgInfo->height, alphaBlendFunc);
	}
	//원본이미지 그대로 알파블랜딩
	else {
		//블랜드 DC를 출력해야할 DC에 그림.
		AlphaBlend(hdc, 0, 0, imgInfo->width, imgInfo->height, imgInfo->hMemDC, 0, 0, imgInfo->width, imgInfo->height, alphaBlendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	alphaBlendFunc.SourceConstantAlpha = alpha;

	if (trans) {

		//출력해야할 DC에 그려져있는 내용을 블랜드이미지에 그려줌.
		BitBlt(alphaBlendImg->hMemDC, 0, 0, alphaBlendImg->width, alphaBlendImg->height, hdc, destX, destY, SRCCOPY);
		//출력해야 할 이미지를 블랜드에 그림
		GdiTransparentBlt(alphaBlendImg->hMemDC, 0, 0, imgInfo->width, imgInfo->height, imgInfo->hMemDC, 0, 0, imgInfo->width, imgInfo->height, transColor);
		//블랜드 DC를 출력해야할 DC에 그림.
		AlphaBlend(hdc, destX, destY, imgInfo->width, imgInfo->height, alphaBlendImg->hMemDC, 0, 0, imgInfo->width, imgInfo->height, alphaBlendFunc);
	}
	//원본이미지 그대로 알파블랜딩
	else {
		//블랜드 DC를 출력해야할 DC에 그림.
		AlphaBlend(hdc, destX, destY, imgInfo->width, imgInfo->height, imgInfo->hMemDC, 0, 0, imgInfo->width, imgInfo->height, alphaBlendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	alphaBlendFunc.SourceConstantAlpha = alpha;

	if (trans) {
		//출력해야할 DC에 그려져있는 내용을 블랜드이미지에 그려줌.
		BitBlt(alphaBlendImg->hMemDC, 0, 0, sourWidth, sourHeight, hdc, destX, destY, SRCCOPY);
		//출력해야 할 이미지를 블랜드에 그림
		GdiTransparentBlt(alphaBlendImg->hMemDC, 0, 0, sourWidth, sourHeight, imgInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, transColor);
		//블랜드 DC를 출력해야할 DC에 그림.
		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight, alphaBlendImg->hMemDC, 0, 0, sourWidth, sourHeight, alphaBlendFunc);
	}
	//원본이미지 그대로 알파블랜딩
	else {
		//블랜드 DC를 출력해야할 DC에 그림.
		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight, imgInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, alphaBlendFunc);
	}
}void image::aniRender(HDC hdc, int destX, int destY, Animation* ani)
{
	render(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight());
}