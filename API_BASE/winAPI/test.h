#pragma once
/*
	#include <windows.h>
	#include <math.h>

	#define PI 3.141592654

	// �μ����
	// HDC hdc :
	// HBITMAP hBitmap :
	// int source_x : ȸ�� �̹��� ��Ʈ�ʿ�����, ����� �簢������ �»��x��ǥ.
	// int source_y : ȸ�� �̹��� ��Ʈ�ʿ�����, ����� �簢������ �»��y��ǥ.
	// int dest_width : ȸ���� ��Ʈ�� �̹����� �� ũ�� == ȸ���� ��Ʈ�� �̹����� ��µ� �� ũ��
	// int dest_heigjt : ȸ���� ��Ʈ�� �̹����� ���� ũ�� == ȸ���� ��Ʈ�� �̹����� ��µ� ���� ũ��
	// float angle : ȸ���� ����.
	// COLORREF bkColor : ȸ���� ���� ���鿵���� ĥ�� ����. �̹��� �簢���� ȸ���ϸ�, ���鿵���� ����ϴ�. (��)���̾Ƹ�� ���·� ȸ���� �簢�������� �ںκ� ����
	// �� ���鿵���� �̸� ä�� ������ �����մϴ�.

	HBITMAP GetRotatedBitmap( HDC hdc, HBITMAP hBitmap, int source_x, int source_y,
	int dest_width, int dest_height, float angle, COLORREF bkColor )
	{
	HDC sourceDC = CreateCompatibleDC(hdc); // ȸ���� ��Ʈ�� ������ ������ DC
	HDC destDC = CreateCompatibleDC(hdc); // ȸ���� ��Ʈ���� ��¹��� DC
	HBITMAP hbmResult = CreateCompatibleBitmap( hdc, dest_width, dest_height ); // ȸ���� ��Ʈ���� ��¹��� �޸𸮺�Ʈ�� �ڵ�

	HBITMAP hbmOldSource= (HBITMAP)SelectObject( sourceDC, hBitmap ); // ȸ���� ��Ʈ�� ������ DC�� ����
	HBITMAP hbmOldDest = (HBITMAP)SelectObject( destDC, hbmResult ); // ȸ���� ��Ʈ���� ��¹��� DC��, ȸ���� ��Ʈ���� ��¹��� �޸𸮺�Ʈ�� ����

	HBRUSH hbrBack = CreateSolidBrush( bkColor ); // ȸ������ ����, ���鿵���� ĥ�� �귯���ڵ� ����
	HBRUSH hbrOld = (HBRUSH)SelectObject( destDC, hbrBack ); // �귯���ڵ� ����
	PatBlt( destDC, 0, 0, dest_width, dest_height, PATCOPY ); // ���õ� �귯�÷�, ȸ���� ��Ʈ���� ��¹��� DC��, �̸� ������ ä�� ����
	DeleteObject( SelectObject( destDC, hbrOld ) ); // �귯�� ����

	angle = (float)( angle * PI / 180 ); // ȸ���� ����(360�й�)��, ���ȴ����� ������ ����
	float cosine = (float)cos( angle ); // ȸ���̵���ȯ ��Ŀ� �� cos��Ÿ ���� ����
	float sine = (float)sin( angle ); // ȸ���̵���ȯ ��Ŀ� �� sin��Ÿ ���� ����

	SetGraphicsMode(destDC, GM_ADVANCED); // ������ ��ǥ���� ȸ���� ���Ͽ�, �׷��ȸ�带 Ȯ����� �����մϴ�.(�䱸����:��98,NT�̻�)

	// ȸ���̵���ȯ ����� ����.
	// (�������� API���� ������ 2�� Page(1279) ����.)
	// (���� ���α׷��Ӹ� ���� ���ʼ��а� ���� Page(196) ����.)

	XFORM xform; // �������� ǥ���ϴ� 3��3���� ��� ����
	xform.eM11 = cosine; // 1�� 1�� ���� ���� (ȸ������)
	xform.eM12 = sine; // 1�� 2�� ���� ���� (ȸ������)
	xform.eM21 = -sine; // 2�� 1�� ���� ���� (ȸ������)
	xform.eM22 = cosine; // 2�� 2�� ���� ���� (ȸ������)
	xform.eDx = (FLOAT)dest_width / 2.0f; // 3�� 1�� ���� ���� (X�� �̵� ����)
	xform.eDy = (FLOAT)dest_height / 2.0f; // 3�� 2�� ���� ���� (Y�� �̵� ����)

	// ������ ��ķ�, �μ�DC�� �������� ��ǥ�踦 ��ȯ.
	// �μ�DC�� ��´������ �޸𸮺�Ʈ���� �����Ƿ�,
	// �����ϰ� �ִ� �޸𸮺�Ʈ���� ��ǥü�谡 ȸ���ȴ�.

	SetWorldTransform( destDC, &xform );

	// ȸ���� �޸�DC��, ȸ���� �̹����� ���

	BitBlt(destDC, -(dest_width/2),-(dest_height/2), dest_width, dest_height, sourceDC, source_x, source_y, SRCCOPY );

	// ���� �ڿ� ����

	SelectObject( sourceDC, hbmOldSource );
	SelectObject( destDC, hbmOldDest );
	DeleteObject(sourceDC);
	DeleteObject(destDC);

	// ȸ���� ��Ʈ�� �ڵ� ����

	return hbmResult;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	void RotateBlt( HDC hdc, HDC hOffScreen, int dest_x, int dest_y, int dest_width, int dest_height,
	HBITMAP hBit, int source_x, int source_y, DWORD dFlag, float angle, COLORREF bkColor )
	{
	static HDC hTempMemDC; // ȸ���� ��Ʈ���� ������ �޸�DC
	HBITMAP hTempBitmap, hOldBitmap; // ȸ���� ��Ʈ���� ������, ��Ʈ�� �ڵ�

	// ���� �ѹ��� ��Ʈ��DC�� �����մϴ�.

	if( !hTempMemDC ) hTempMemDC = CreateCompatibleDC( hdc );

	// ��Ʈ���� ȸ���ϴ� �Լ��� ȣ���Ͽ�, ���ϵǴ� ȸ���� ��Ʈ�� �ڵ��� ����

	hTempBitmap = GetRotatedBitmap( hdc, hBit, source_x, source_y, dest_width, dest_height, angle, bkColor );

	// ȸ���� ��Ʈ�� �ڵ��� �����ϰ�,

	hOldBitmap = (HBITMAP)SelectObject( hTempMemDC, hTempBitmap );

	// ������ũ��DC��, ȸ���� ��Ʈ�� �ڵ��� ������, �޸�DC�� �̹����� ����մϴ�.
	// ���� �ּ��� �����ϸ�, �����ǥ�� �߽����� �ϴ� ȸ���̹����� �˴ϴ�.

	BitBlt( hOffScreen, dest_x
	// - dest_width/2
	, dest_y - dest_height/2, dest_width, dest_height,hTempMemDC, 0, 0, dFlag );

	SelectObject(hTempMemDC, hOldBitmap);
	DeleteObject(hTempBitmap);
	}

	HWND hWndMain; // ������ �ڵ�
	HDC hdc; // ȭ�� DC �ڵ�
	HDC hOffScreenDC; // ������ũ�� DC �ڵ�
	HBITMAP hOffScreenBitmap; // ������ũ�� DC �� �����ϴ�, �޸� ��Ʈ�� �ڵ�
	HBITMAP hMemBitmap; // �̹����� ����, �޸� ��Ʈ�� �ڵ�

	void OnTimer(); // WM_TIMER�޼�����, �ڵ鷯 �Լ�

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
	switch (message)
		{
		case WM_CREATE:
			hWndMain = hWnd;
			// ȭ��DC, ������ũ��DC, ������ũ���� �޸𸮺�Ʈ���� �̸� �����մϴ�.
			
			hdc = GetDC(hWnd);
			hOffScreenDC = CreateCompatibleDC(hdc);
			hOffScreenBitmap = CreateCompatibleBitmap(hdc, 800, 600);
			SelectObject(hOffScreenDC, hOffScreenBitmap);
			PatBlt(hOffScreenDC, 0, 0, 800, 600, WHITENESS);
		
				// �̹����� ��Ʈ�ʿ� �ε��մϴ�.
			
				hMemBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL),
					TEXT("player_walk.bmp"),
					IMAGE_BITMAP,
					0,
					0,
					LR_DEFAULTSIZE | LR_LOADFROMFILE);
		
				// Ÿ�̸� ����
			
				SetTimer(hWnd, 1, 20, NULL);
			break;
		
				case WM_TIMER:
					OnTimer();
					break;
				
						case WM_DESTROY:
							// ���� �޸� ��Ʈ�ʰ�, ������ũ�� DC, Ÿ�̸Ӹ� �����մϴ�.
						DeleteObject(hMemBitmap);
						DeleteObject(hOffScreenBitmap);
						DeleteDC(hOffScreenDC);
							KillTimer(hWnd, 1);
							PostQuitMessage(0);
							break;
							}

	return DefWindowProc(hWnd, message, wParam, lParam);
	}

	void OnTimer()
	{
	// ��Ʈ���� ȸ����ų ����(360�й�) ����
	
		static FLOAT angle = 0.0f;
	static BOOL bRotate = FALSE;

		if (GetKeyState(VK_LBUTTON) & 0x8000) { bRotate = TRUE; }

		if (bRotate)
		{
		angle += 5.0f;
		if (angle >= 360.0f)
			{
			bRotate = FALSE;
			angle = 0.0f;
			}
		}

		// ������ũ��DC�� �̹�����, �Ͼ������ ä��, ���� �����ӿ����� �̹����� �����մϴ�.
	
		PatBlt(hOffScreenDC, 0, 0, 800, 600, WHITENESS);

		// ������ũ��DC��, �̹����� ����ũ�� ����մϴ�.
	
		RECT Rt;
	GetClientRect(hWndMain, &Rt);
	RotateBlt(hdc, hOffScreenDC, Rt.right / 2, Rt.bottom / 2, 59, 59,
	hMemBitmap, 0, 0, SRCAND, angle, RGB(255, 255, 255));

		// ������ũ��DC��, �̹����� ����մϴ�.
	
		RotateBlt(hdc, hOffScreenDC, Rt.right / 2, Rt.bottom / 2, 59, 59,
		hMemBitmap, 60, 0, SRCPAINT, angle, RGB(0, 0, 0));

		// ȭ��DC��, ������ũ���� �̹����� ����մϴ�.
	
		BitBlt(hdc, 0, 0, 800, 600, hOffScreenDC, 0, 0, SRCCOPY);
	}
	*/

