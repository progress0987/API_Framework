#include "stdafx.h"
#include "UserInterface.h"


HRESULT UserInterface::init(void)
{

	//------------------------------------ImagePrep------------------------------------------
	//닫기단추 작업
	CloseN = IMAGEMANAGER->findImage("닫기");
	CloseO = IMAGEMANAGER->findImage("닫기마우스온");
	CloseC = IMAGEMANAGER->findImage("닫기클릭");

	//커서 작업
	finger = IMAGEMANAGER->findImage("커서");
	finger->setFrameY(0);
	finger->setFrameX(0);

	//스텟창 작업
	statWnd = IMAGEMANAGER->findImage("스텟창");
	UpN = IMAGEMANAGER->findImage("업");
	UpO = IMAGEMANAGER->findImage("업마우스온");
	UpC = IMAGEMANAGER->findImage("업클릭");
	autoDistN = IMAGEMANAGER->findImage("자동배분버튼활성화");
	autoDistC = IMAGEMANAGER->findImage("자동배분버튼눌림");

	statWnd->setX(150);
	statWnd->setY(200);

	//장비창 작업
	equipWnd = IMAGEMANAGER->findImage("장비창");

	equipWnd->setX(400);
	equipWnd->setY(200);

	//인벤토리 작업
	invenWnd = IMAGEMANAGER->findImage("인벤토리창");
	equipTab = IMAGEMANAGER->findImage("장비탭");
	potionTab = IMAGEMANAGER->findImage("소비탭");
	etcTab = IMAGEMANAGER->findImage("기타탭");
	shadow = IMAGEMANAGER->findImage("그림자");

	invenWnd->setX(700);
	invenWnd->setY(200);

	//재고량 표기번호
	sZero = IMAGEMANAGER->findImage("0");
	sOne = IMAGEMANAGER->findImage("1");
	sTwo = IMAGEMANAGER->findImage("2");
	sThree = IMAGEMANAGER->findImage("3");
	sFour = IMAGEMANAGER->findImage("4");
	sFive = IMAGEMANAGER->findImage("5");
	sSix = IMAGEMANAGER->findImage("6");
	sSeven = IMAGEMANAGER->findImage("7");
	sEight = IMAGEMANAGER->findImage("8");
	sNine = IMAGEMANAGER->findImage("9");

	//퀵슬롯 레이어작업
	slotcover1 = IMAGEMANAGER->findImage("퀵슬롯왼쪽테두리");
	slotcover2 = IMAGEMANAGER->findImage("퀵슬롯커버");
	slotbackground = IMAGEMANAGER->findImage("퀵슬롯0");

	//퀵슬롯 단축키 작업
	q1 = IMAGEMANAGER->findImage("퀵1");
	q2 = IMAGEMANAGER->findImage("퀵2");
	q3 = IMAGEMANAGER->findImage("퀵3");
	q4 = IMAGEMANAGER->findImage("퀵4");
	q5 = IMAGEMANAGER->findImage("퀵5");
	q6 = IMAGEMANAGER->findImage("퀵6");
	qq = IMAGEMANAGER->findImage("Q");
	qw = IMAGEMANAGER->findImage("W");
	qe = IMAGEMANAGER->findImage("E");
	qr = IMAGEMANAGER->findImage("R");
	qt = IMAGEMANAGER->findImage("T");
	qa = IMAGEMANAGER->findImage("A");
	_ctrl = IMAGEMANAGER->findImage("ctrl");
	_shift = IMAGEMANAGER->findImage("shift");
	_inst = IMAGEMANAGER->findImage("inst");
	_del = IMAGEMANAGER->findImage("del");
	_hm = IMAGEMANAGER->findImage("hm");
	_end = IMAGEMANAGER->findImage("end");
	_pgup = IMAGEMANAGER->findImage("pgup");
	_pgdn = IMAGEMANAGER->findImage("pgdn");

	//캐릭터 정보창, 경험치 레이어 작업

	_form = IMAGEMANAGER->findImage("게이지테두리");
	_formBackground = IMAGEMANAGER->findImage("게이지배경");
	mpbar = IMAGEMANAGER->findImage("마나");
	hpbar = IMAGEMANAGER->findImage("체력");
	_shine = IMAGEMANAGER->findImage("커버");
	_lv = IMAGEMANAGER->findImage("Lv");
	l0 = IMAGEMANAGER->findImage("레벨숫자0");
	l1 = IMAGEMANAGER->findImage("레벨숫자1");
	l2 = IMAGEMANAGER->findImage("레벨숫자2");
	l3 = IMAGEMANAGER->findImage("레벨숫자3");
	l4 = IMAGEMANAGER->findImage("레벨숫자4");
	l5 = IMAGEMANAGER->findImage("레벨숫자5");
	l6 = IMAGEMANAGER->findImage("레벨숫자6");
	l7 = IMAGEMANAGER->findImage("레벨숫자7");
	l8 = IMAGEMANAGER->findImage("레벨숫자8");
	l9 = IMAGEMANAGER->findImage("레벨숫자9");
	l00 = IMAGEMANAGER->findImage("레벨숫자0");
	l01 = IMAGEMANAGER->findImage("레벨숫자1");
	l02 = IMAGEMANAGER->findImage("레벨숫자2");
	l03 = IMAGEMANAGER->findImage("레벨숫자3");
	l04 = IMAGEMANAGER->findImage("레벨숫자4");
	l05 = IMAGEMANAGER->findImage("레벨숫자5");
	l06 = IMAGEMANAGER->findImage("레벨숫자6");
	l07 = IMAGEMANAGER->findImage("레벨숫자7");
	l08 = IMAGEMANAGER->findImage("레벨숫자8");
	l09 = IMAGEMANAGER->findImage("레벨숫자9");
	l000 = IMAGEMANAGER->findImage("레벨숫자0");
	l001 = IMAGEMANAGER->findImage("레벨숫자1");
	l002 = IMAGEMANAGER->findImage("레벨숫자2");
	l003 = IMAGEMANAGER->findImage("레벨숫자3");
	l004 = IMAGEMANAGER->findImage("레벨숫자4");
	l005 = IMAGEMANAGER->findImage("레벨숫자5");
	l006 = IMAGEMANAGER->findImage("레벨숫자6");
	l007 = IMAGEMANAGER->findImage("레벨숫자7");
	l008 = IMAGEMANAGER->findImage("레벨숫자8");
	l009 = IMAGEMANAGER->findImage("레벨숫자9");

	_0 = IMAGEMANAGER->findImage("작0");
	_1 = IMAGEMANAGER->findImage("작1");
	_2 = IMAGEMANAGER->findImage("작2");
	_3 = IMAGEMANAGER->findImage("작3");
	_4 = IMAGEMANAGER->findImage("작4");
	_5 = IMAGEMANAGER->findImage("작5");
	_6 = IMAGEMANAGER->findImage("작6");
	_7 = IMAGEMANAGER->findImage("작7");
	_8 = IMAGEMANAGER->findImage("작8");
	_9 = IMAGEMANAGER->findImage("작9");

	_rs = IMAGEMANAGER->findImage("역슬래쉬");
	_Lc = IMAGEMANAGER->findImage("[");
	_Rc = IMAGEMANAGER->findImage("]");
	_percent = IMAGEMANAGER->findImage("%");
	_dot = IMAGEMANAGER->findImage("점");

	_form->setX(750);
	_form->setY(690);
	_formBackground->setX(_form->getX() + 3);
	_formBackground->setY(_form->getY() + 25);
	hpbar->setX(_formBackground->getX());
	hpbar->setY(_formBackground->getY());
	hpbar->setX(_formBackground->getX() + 22);
	hpbar->setY(_formBackground->getY() + 3);

	mpbar->setX(_formBackground->getX() + 22);
	mpbar->setY(_formBackground->getY() + 19);

	_lv->setX(_form->getX() + 25);
	_lv->setY(_form->getY() + 7);

	//경험치바	  
	expBackground = IMAGEMANAGER->findImage("경험치0");
	expGuage = IMAGEMANAGER->findImage("경험치2");
	expLayer = IMAGEMANAGER->findImage("경험치3");
	expEffect = IMAGEMANAGER->findImage("경험치4");

	expBackground->setX(0);
	expBackground->setY(758);
	expGuage->setX(16);
	expGuage->setY(761);
	expLayer->setX(150);
	expLayer->setY(761);

	Level = pl->getstatus()->Level;
	playerHp = pl->getstatus()->curHP;
	playerMp = pl->getstatus()->curMP;
	MaxHp = pl->getstatus()->maxHP;
	MaxMp = pl->getstatus()->maxMP;
	_str = pl->getstatus()->Str;
	_dex = pl->getstatus()->Dex;
	_int = pl->getstatus()->Int;
	_luk = pl->getstatus()->Luk;
	//_ap;


	

	return S_OK;
}

void UserInterface::release(void)
{
}

void UserInterface::update(void)
{
		playerHp = pl->getstatus()->curHP;
		playerMp = pl->getstatus()->curMP;
	if (onStat) {
		Level = pl->getstatus()->Level;
		MaxHp = pl->getstatus()->maxHP;
		MaxMp = pl->getstatus()->maxMP;
	}
	//인벤토리창 띄우기.
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		onInven = !onInven;
	}

	//스텟창 띄우기
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		onStat = !onStat;
	}


	//장비창 띄우기
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		onEquip = !onEquip;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		//장비창이 켜져있는경우

		//스텟창이 켜져있는경우

		//인벤토리창이 켜져있는경우


	}

	//키 작동 확인.
	//체력포션 처먹처먹
	if (KEYMANAGER->isOnceKeyDown(VK_DELETE))
	{
		

	}

	//마나포션 처먹처먹
	if (KEYMANAGER->isOnceKeyDown(VK_END))
	{

		
	}


	//실시간 캐릭터 스텟 갱신쓰
}

void UserInterface::render(void)
{
	//텍스트 렌더링에 필요한 기본설정쓰
	SetBkMode(getMemDC(), TRANSPARENT); //이거 해줘야 흰색배경 없앤다.
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	//기본인터페이스 렌더링
	//경험치
	expBackground->render(getMemDC());
	expGuage->render(getMemDC());
	expLayer->render(getMemDC());

	//캐릭터정보 및 체력, 마나게이지
	_formBackground->render(getMemDC());
	hpbar->render(getMemDC());
	mpbar->render(getMemDC());
	_form->render(getMemDC());
	_shine->alphaRender(getMemDC(), _form->getX(), _form->getY(), 120);

	//게이지 수치 표기
	showStatement();

	//레벨, 아이디 표기
	_lv->render(getMemDC());
	showLevel();
	char temp[255];
	sprintf(temp, "아무고토모타조");
	TextOut(getMemDC(), _form->getX() + 75, _form->getY() + 5, temp, strlen(temp));

	//퀵슬롯


	slotbackground->alphaRender(getMemDC(), 1019, 688, 180);
	slotcover1->render(getMemDC(), 1009, 686);
	slotcover2->render(getMemDC(), 1017, 685);



	///////////////////////////////////여기에 스킬, 아이템이미지, 재고번호 넣도록 하여라.

	//////////////////////////////////////////////////////////////////////////////////////

	q1 -> render(getMemDC(), 1162, 690);
	q2 -> render(getMemDC(), 1197, 690);
	q3 -> render(getMemDC(), 1232, 690);
	q4 -> render(getMemDC(), 1267, 690);
	q5 -> render(getMemDC(), 1302, 690);
	q6 -> render(getMemDC(), 1337, 690);
	qq->render(getMemDC(), 1162, 725);
	qw->render(getMemDC(), 1197, 725);
	qe->render(getMemDC(), 1232, 725);
	qr->render(getMemDC(), 1267, 725);
	qt->render(getMemDC(), 1302, 725);
	qa->render(getMemDC(), 1337, 725);
	_ctrl->render(getMemDC(), 1022, 725);
	_shift->render(getMemDC(), 1022, 690);
	_inst->render(getMemDC(), 1057, 690);
	_del->render(getMemDC(), 1057, 725);
	_hm -> render(getMemDC(), 1092, 690);
	_end->render(getMemDC(), 1092, 725);
	_pgup->render(getMemDC(), 1127, 690);
	_pgdn->render(getMemDC(), 1127, 725);


	//스텟창, 장비창, 인벤토리 렌더링
	if (onStat)
		statement();
	if (onEquip)
		equip();
	if (onInven)
		inventory();

	//마우스 커서 숨기기
	SetCursor(NULL);
	ShowCursor(false);

	finger->frameRender(getMemDC(), ptMouse.x, ptMouse.y);
}

void UserInterface::equip(void)
{
	wndEquip = RectMake(equipWnd->getX(), equipWnd->getY(), equipWnd->getWidth(), equipWnd->getHeight());
	equipWnd->render(getMemDC());
}

void UserInterface::inventory(void)
{
	wndInven = RectMake(invenWnd->getX(), invenWnd->getY(), invenWnd->getWidth(), invenWnd->getHeight());
	invenWnd->render(getMemDC());
}

void UserInterface::statement(void)
{
	wndStat = RectMake(statWnd->getX(), statWnd->getY(), statWnd->getWidth(), statWnd->getHeight());
	statWnd->render(getMemDC());

	SetBkMode(getMemDC(), TRANSPARENT); //이거 해줘야 흰색배경 없앤다.
	SetTextColor(getMemDC(), RGB(80, 80, 80));

	char temp[255];
	HFONT oldFont, font1;
	//CreateFont(
	//	40,					//문자폭
	//	0,					//문자 넓이
	//	40,					//문자 기울기(각도)
	//	0,					//문자 방향
	//	600,				//문자 굵기
	//	0,					//bool 문자 기울기 true/false
	//	0,					//bool 문자 밑줄 true/false
	//	0,					//bool 문자 취소선 true/false
	//	HANGUL_CHARSET,		//문자 세팅
	//	0,					//출력정확도(?)
	//	0,					//클리핑 정확도
	//	0,					//출력의 퀄리티
	//	0,					//자간
	//	TEXT("궁서체")		//내부시스템폰트가져옴
	//);
	
	font1 = CreateFont(15, 0, 0, 0, 100, false, 0, false, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("돋움체"));
	SetBkMode(getMemDC(), TRANSPARENT);
	oldFont = (HFONT)SelectObject(getMemDC(), font1);
	sprintf(temp, "아무고토모타조");
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 30, temp, strlen(temp));

	char temp2[255];
	sprintf(temp2, "등골브레이커");
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 49, temp2, strlen(temp2));

	char temp3[255];
	sprintf(temp3, "창희네");
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 67, temp3, strlen(temp3));

	char temp4[255];
	sprintf(temp4, "ㅡ");
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 85, temp4, strlen(temp4));

	char temp5[255];
	sprintf(temp5, "샤방샤방");
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 102, temp5, strlen(temp5));


	//중간에 글자크기 변경!!!!

	DeleteObject(oldFont); //변경할때 딜리트 안해주면 터져버린다!!!!
	DeleteObject(font1); //계속 생성생성만 해주면 터져버리지......getpixel맛탱이 간다.
	font1 = CreateFont(13, 0, 0, 0, 100, false, 0, false, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("돋움체"));
	oldFont = (HFONT)SelectObject(getMemDC(), font1);

	char temp6[255];
	sprintf(temp6, "%d / %d", playerHp, MaxHp);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 121, temp6, strlen(temp6));

	char temp7[255];
	sprintf(temp7, "%d / %d", playerMp, MaxMp);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 139, temp7, strlen(temp7));

	char temp8[255];
	sprintf(temp8, "%d", _ap);
	TextOut(getMemDC(), statWnd->getX() + 85, statWnd->getY() + 182, temp8, strlen(temp8));

	char temp9[255];
	sprintf(temp9, "%d(%d+%d)", _str, _basicStr, totalEquipstr);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 209, temp9, strlen(temp9));

	char temp10[255];
	sprintf(temp10, "%d(%d+%d)", _dex, _basicDex, totalEquipdex);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 227, temp10, strlen(temp10));

	char temp11[255];
	sprintf(temp11, "%d(%d+%d)", _int, _basicInt, totalEquipint);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 245, temp11, strlen(temp11));

	char temp12[255];
	sprintf(temp12, "%d(%d+%d)", _luk, _basicLuk, totalEquipluk);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 263, temp12, strlen(temp12));

	//다썼으면 지워주자!!!
	DeleteObject(oldFont);
	DeleteObject(font1);
}

UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
