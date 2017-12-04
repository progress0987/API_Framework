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

	iT = new items;
	iT->init();

	//장비창 초기화
	e_cap = e_capes = e_gloves = e_clothes = e_earAcc = e_weapon = e_pants = e_shoes = -1;

	//인벤토리 작업
	invenWnd = IMAGEMANAGER->findImage("인벤토리창");
	equipTab = IMAGEMANAGER->findImage("장비탭");
	potionTab = IMAGEMANAGER->findImage("소비탭");
	etcTab = IMAGEMANAGER->findImage("기타탭");
	shadow = IMAGEMANAGER->findImage("그림자");

	invenWnd->setX(700);
	invenWnd->setY(200);

	//플레이어가 기본적으로 소지하고 있는 아이템을 인벤토리에 넣어준다.
	//처음에 초기화.

	memset(c_equip, -1, sizeof(c_equip));
	memset(c_consume, -1, sizeof(c_consume));
	memset(c_etc, -1, sizeof(c_etc));


	//플에이어가 기본적으로 가지고 있는 아이템을 인벤토리로 가져온다.
	//-1은 비어있음을 의미한다.

	c_equip[0] = 0; //각 배열에 들어있는 숫자는 플레이어의 아이템 벡터의 인덱스에 해당하는 아이템을 의미한다.
	c_equip[1] = 1;
	c_equip[2] = 2;
	c_equip[3] = 3;
	c_equip[4] = 4;
	c_equip[5] = 5;
	c_equip[6] = 6;

	c_consume[0] = 0;
	c_consume[1] = 1;



	invEq = true, invPo = false, invEtc = false;

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
	_ap = pl->getstatus()->ap;
	_exp = pl->getstatus()->Exp;
	LvExp = pl->getstatus()->lvlUpExp;

	//----------------------------------상점이미지로드-----------------------

	//처음셋팅
	onShop = false;
	onShopEquipTab = true, onShopPortionTab = false, onShopEtcTab = false;

	_me = IMAGEMANAGER->findImage("캐릭터");
	_Azoomma = IMAGEMANAGER->findImage("storenpc");
	shopWnd = IMAGEMANAGER->findImage("상점");
	shopQuit = IMAGEMANAGER->findImage("상점나가기마우스");
	shopBuy = IMAGEMANAGER->findImage("아이템사기마우스");
	shopSell = IMAGEMANAGER->findImage("아이템팔기마우스");
	shopQuitPushed = IMAGEMANAGER->findImage("상점나가기눌림");
	shopBuyPushed = IMAGEMANAGER->findImage("아이템사기눌림");
	shopSellPushed = IMAGEMANAGER->findImage("아이템팔기눌림");
	shopEquip = IMAGEMANAGER->findImage("상점장비활성");
	shopPortion = IMAGEMANAGER->findImage("상점소비활성");
	shopEtc = IMAGEMANAGER->findImage("상점기타활성");
	mesoIcon = IMAGEMANAGER->findImage("메소아이콘");
	selectEffect = IMAGEMANAGER->findImage("셀렉트효과");
	selectEffect2 = IMAGEMANAGER->findImage("셀렉트효과2");

	_me->setFrameX(0);
	_me->setFrameY(0);
	_Azoomma->setFrameX(0);
	_Azoomma->setFrameY(0);

	_meCount = 0;
	_AzoommaCount = 0;

	Sellings = new items;
	Sellings->init();
	Mines = new items;
	Mines->init();

	shopListClick = -1;

	//-------------------------------임시변수들 초기 설정---------------------------

	count = fingerCount = 0;

	onClickQuit = onClickBuy = onClickSell = onClickAzoomma = false;

	return S_OK;
}

void UserInterface::release(void)
{
}

void UserInterface::update(void)
{
	//------------------------------실시간 UI프로세스 갱신쓰!-----------------------------


	//프레임 처리를 위한 변수
	count++;

	//실시간 캐릭터정보갱신쓰
	Level = pl->getstatus()->Level;
	playerHp = pl->getstatus()->curHP;
	playerMp = pl->getstatus()->curMP;
	MaxHp = pl->getstatus()->maxHP;
	MaxMp = pl->getstatus()->maxMP;
	_str = pl->getstatus()->Str + totalEquipstr;
	_dex = pl->getstatus()->Dex + totalEquipdex;
	_int = pl->getstatus()->Int + totalEquipint;
	_luk = pl->getstatus()->Luk + totalEquipluk;
	_ap = pl->getstatus()->ap;
	_exp = pl->getstatus()->Exp;
	LvExp = pl->getstatus()->lvlUpExp;

	totalEquipstr = i_cap.str + i_weapon.str + i_clothes.str + i_earAcc.str + i_pants.str + i_shoes.str + i_gloves.str + i_capes.str;
	totalEquipdex = i_cap.dex + i_weapon.dex + i_clothes.dex + i_earAcc.dex + i_pants.dex + i_shoes.dex + i_gloves.dex + i_capes.dex;
	totalEquipint = i_cap.inteligence + i_weapon.inteligence + i_clothes.inteligence + i_earAcc.inteligence + i_pants.inteligence + i_shoes.inteligence + i_gloves.inteligence + i_capes.inteligence;
	totalEquipluk = i_cap.luk + i_weapon.luk + i_clothes.luk + i_earAcc.luk + i_pants.luk + i_shoes.luk + i_gloves.luk + i_capes.luk;

	//실시간 보유아이템 갱신쓰(기타 아이템은 없으므로 제외)
	
	/*for (int i = 0; i < 24; i++)
	{
		c_equip[i] = 
	}*/

	//체력이 회복되고 있는가
	if (HpHillCount != 0)
	{
		HpHillCount--;
		if (pl->getstatus()->curHP + HpHill >= pl->getstatus()->maxHP)
		{
			pl->setCurHP(pl->getstatus()->maxHP);
		}
		else
		{
			pl->setCurHP(pl->getstatus()->curHP + HpHill);
		}
		HpHillMax -= HpHill;
	}
	//마나가 회복되고 있는가
	if (MpHillCount != 0)
	{
		MpHillCount--;
		if (pl->getstatus()->curMP + MpHill >= pl->getstatus()->maxMP)
		{
			pl->setCurMP(pl->getstatus()->maxMP);
		}
		else
		{
			pl->setCurMP(pl->getstatus()->curMP + MpHill);
		}
		MpHillMax -= MpHill;
	}


	////==============================================마우스 올렸을때의 핑거액션!!!!=========================================


	/*if문을 분할해서 처리하려고 하면 충돌해버려서 if else 세트로 한꺼번에 묶었음.*/

	
	if (PtInRect(&equipTabSq, ptMouse) || PtInRect(&potionTabSq, ptMouse) || PtInRect(&etcTabSq, ptMouse))
	{
		finger->setFrameY(2);
		if (count % 30 == 0)
		{
			fingerCount++;
			if (fingerCount > finger->getMaxFrameX()) fingerCount = 0;
		}
	}

	else if (PtInRect(&_myInven[0], ptMouse)  || PtInRect(&_myInven[1], ptMouse) || PtInRect(&_myInven[2], ptMouse) ||
		PtInRect(&_myInven[3], ptMouse) || PtInRect(&_myInven[4], ptMouse) || PtInRect(&_myInven[5], ptMouse) ||
		PtInRect(&_myInven[6], ptMouse) || PtInRect(&_myInven[7], ptMouse) || PtInRect(&_myInven[8], ptMouse) ||
		PtInRect(&_myInven[9], ptMouse) || PtInRect(&_myInven[10], ptMouse) || PtInRect(&_myInven[11], ptMouse) || 
		PtInRect(&_myInven[12], ptMouse) || PtInRect(&_myInven[13], ptMouse) || PtInRect(&_myInven[14], ptMouse) || 
		PtInRect(&_myInven[15], ptMouse) || PtInRect(&_myInven[16], ptMouse) || PtInRect(&_myInven[17], ptMouse) || 
		PtInRect(&_myInven[18], ptMouse) || PtInRect(&_myInven[19], ptMouse) || PtInRect(&_myInven[20], ptMouse) || 
		PtInRect(&_myInven[21], ptMouse) || PtInRect(&_myInven[22], ptMouse) || PtInRect(&_myInven[23], ptMouse))
	{
		finger->setFrameY(3);
		if (count % 30 == 0)
		{
			fingerCount++;
			if (fingerCount > finger->getMaxFrameX()) fingerCount = 0;
		}
	}	

	// 1. ---------------------------커서를 상점아줌마에게 갖다댔을때 나타나는 핑거액션
	else if (pl->openShop() == true) 
	{	
		finger->setFrameY(2);
		if (count % 30 == 0)
		{
			fingerCount++;
			if (fingerCount > finger->getMaxFrameX()) fingerCount = 0;
		}
	}

	// 2. ------------------------------------창이 켜졌을때(장비창은 이 액션을 쓰지 않으므로 제외)-----------------------
	else if (onShop)
	{
		//창내 버튼과 아이템목록에 마우스를 올렸을때 커서액션
		if (PtInRect(&shopItem[0], ptMouse) || PtInRect(&shopItem[1], ptMouse) || 
			PtInRect(&shopItem[2], ptMouse) || PtInRect(&shopItem[3], ptMouse) || 
			PtInRect(&shopItem[4], ptMouse) || PtInRect(&shopItem[5], ptMouse) || 
			PtInRect(&shopItem[6], ptMouse) || PtInRect(&shopItem[7], ptMouse) || 
			PtInRect(&shopItem[8], ptMouse) || PtInRect(&buttonQuit, ptMouse) ||
			PtInRect(&buttonBuy, ptMouse) || PtInRect(&buttonSell, ptMouse) ||
			PtInRect(&myItem[0], ptMouse) || PtInRect(&myItem[1], ptMouse) ||
			PtInRect(&myItem[2], ptMouse) || PtInRect(&myItem[3], ptMouse) ||
			PtInRect(&myItem[4], ptMouse) || PtInRect(&myItem[5], ptMouse) ||
			PtInRect(&myItem[6], ptMouse) || PtInRect(&myItem[7], ptMouse) ||
			PtInRect(&myItem[8], ptMouse) || PtInRect(&shopEquipTab, ptMouse) ||
			PtInRect(&shopPortionTab, ptMouse) || PtInRect(&shopEtcTab, ptMouse))
		{
			finger->setFrameY(2);
			if (count % 30 == 0)
			{
				fingerCount++;
				if (fingerCount > finger->getMaxFrameX()) fingerCount = 0;
			}
		}
		//창내부에서 버튼위에 있는게 아닐때
		else
		{
			fingerCount = 0;
			finger->setFrameY(0);
		}
	}

	// 3.-------모든창이 꺼진상태고, 마우스위에 누구한테도 올린게 아닐때. 얘 조심해야한다. 얘 때문에 마우스액션 다 씹힐수 있음. else if로 조심스레 피해야함.---------------
	else
	{
		fingerCount = 0;
		finger->setFrameY(0);
	}
	//====================================================핑거액션 끝==============================


	//상점창 내부 캐릭터, npc움직임을 위한 프레임 처리.
	if (onShop)
	{
		//참고로 이런 프레임렌더를 위한 카운트 변수들 증감은 업데이트 부분에서 해줘야 잘된다.
		//렌더링부분에서 해주니깐 버벅거린다.

		if (count % 40 == 0)
		{
			_meCount++;
			if (_meCount > _me->getMaxFrameX()) _meCount = 0;
		}

		if (count % 50 == 0)
		{
			_AzoommaCount++;
			if (_AzoommaCount > _Azoomma->getMaxFrameX()) _AzoommaCount = 0;
		}
	}

	if (onShop)
	{
		//상점목록1 이었던 경우
		if (PtInRect(&shopItem[0], ptMouse))
		{
			shopList = 0;
		}

		//상점목록2 이었던 경우
		else if (PtInRect(&shopItem[1], ptMouse))
		{
			shopList = 1;
		}

		//상점목록3 이었던 경우
		else if (PtInRect(&shopItem[2], ptMouse))
		{
			shopList = 2;
		}

		//상점목록4 이었던 경우
		else if (PtInRect(&shopItem[3], ptMouse))
		{
			shopList = 3;
		}

		//상점목록5 이었던 경우
		else if (PtInRect(&shopItem[4], ptMouse))
		{
			shopList = 4;
		}

		//상점목록6 이었던 경우
		else if (PtInRect(&shopItem[5], ptMouse))
		{
			shopList = 5;
		}

		//상점목록7 이었던 경우
		else if (PtInRect(&shopItem[6], ptMouse))
		{
			shopList = 6;
		}

		//상점목록8 이었던 경우
		else if (PtInRect(&shopItem[7], ptMouse))
		{
			shopList = 7;
		}

		//상점목록9 이었던 경우
		else if (PtInRect(&shopItem[8], ptMouse))
		{
			shopList = 8;
		}
		//그밖의 영역에서는 창을 띄우지 않는다.
		else
			shopList = -1;

	}


	///////////////////////////인벤토리 아이템정보 보여주기//////////////////////////////////////////

	if (onInven)
	{
		for (int i = 0; i < 24; i++)
		{
	
			if (PtInRect(&_myInven[i], ptMouse))
			{
				if (invEq)
				{
					if (c_equip[i] >= 0)
						invInfo = pl->getEquip().at(c_equip[i]).number;
					else 
						invInfo = -1;
				}

				else if (invPo)
				{
					if (c_consume[i] >= 0)
						invInfo = pl->getConsume().at(c_consume[i]).number;
					else
						invInfo = -1;
				}

				else if (invEtc)
				{
					if (c_etc[i] >= 0)
						invInfo = pl->getEtc().at(c_etc[i]).number;
					else
						invInfo = -1;
				}
			}
		}

		//이거 안해주면 아이템정보창 안꺼진다.......
		if (!PtInRect(&_myInven[0], ptMouse) && !PtInRect(&_myInven[1], ptMouse) && !PtInRect(&_myInven[2], ptMouse) && !PtInRect(&_myInven[3], ptMouse) &&
			!PtInRect(&_myInven[4], ptMouse) && !PtInRect(&_myInven[5], ptMouse) && !PtInRect(&_myInven[6], ptMouse) && !PtInRect(&_myInven[7], ptMouse) &&
			!PtInRect(&_myInven[8], ptMouse) && !PtInRect(&_myInven[9], ptMouse) && !PtInRect(&_myInven[10], ptMouse) && !PtInRect(&_myInven[11], ptMouse) &&
			!PtInRect(&_myInven[12], ptMouse) && !PtInRect(&_myInven[13], ptMouse) && !PtInRect(&_myInven[14], ptMouse) && !PtInRect(&_myInven[15], ptMouse) &&
			!PtInRect(&_myInven[16], ptMouse) && !PtInRect(&_myInven[17], ptMouse) && !PtInRect(&_myInven[18], ptMouse) && !PtInRect(&_myInven[19], ptMouse) &&
			!PtInRect(&_myInven[20], ptMouse) && !PtInRect(&_myInven[21], ptMouse) && !PtInRect(&_myInven[22], ptMouse) && !PtInRect(&_myInven[23], ptMouse))
		{
			invInfo = -1;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	//---------------------------------------------입력처리-----------------------------------------------
	///////////////////////////////////////////////////////////////////////////////////////////////////////


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

		//인벤토리창이 켜져있는경우
		if (onInven)
		{
			//장비탭이었던 경우
			if (PtInRect(&equipTabSq, ptMouse))
			{
				invEq= true;
				invPo = false;
				invEtc = false;
			}


			//소비탭이었던 경우
			if (PtInRect(&potionTabSq, ptMouse))
			{
				invEq = false;
				invPo = true;
				invEtc = false;
			}


			//기타탭이었던 경우
			if (PtInRect(&etcTabSq, ptMouse))
			{
				invEq = false;
				invPo = false;
				invEtc = true;
			}
		}

		
		//상점 아줌마 클릭하기쓰
		if (pl->openShop() == true) {
			onClickAzoomma = true;
		}

		//만일 샵이 켜져있는 경우
		else if (onShop)
		{
			//눌렀을때 나가기 버튼위에 있었던 경우
			if (PtInRect(&buttonQuit, ptMouse))
			{
				onClickQuit = true;
			}
			//눌렀을때 아이템사기 버튼위에 있었던 경우
			if (PtInRect(&buttonBuy, ptMouse))
			{
				onClickBuy = true;
			}
			//눌렀을때 아이템팔기 버튼위에 있었던 경우
			if (PtInRect(&buttonSell, ptMouse))
			{
				onClickSell = true;
			}
			
			//장비탭이었던 경우
			if (PtInRect(&shopEquipTab, ptMouse))
			{
				onShopEquipTab = true;
				onShopPortionTab = false;
				onShopEtcTab = false;
				//탭이 바뀔때마다 선택했던 부분은 초기화.
				myList = -1;

			}


			//소비탭이었던 경우
			if (PtInRect(&shopPortionTab, ptMouse))
			{
				onShopEquipTab = false;
				onShopPortionTab = true;
				onShopEtcTab = false;
				myList = -1;
			}


			//기타탭이었던 경우
			if (PtInRect(&shopEtcTab, ptMouse))
			{
				onShopEquipTab = false;
				onShopPortionTab = false;
				onShopEtcTab = true;
				myList = -1;
			}


			//내아이템목록1 이었던 경우
			if (PtInRect(&myItem[0], ptMouse))
			{
				myList = 0;
			}

			//내아이템목록2 이었던 경우
			if (PtInRect(&myItem[1], ptMouse))
			{
				myList = 1;
			}

			//내아이템목록3 이었던 경우
			if (PtInRect(&myItem[2], ptMouse))
			{
				myList = 2;
			}

			//내아이템목록4 이었던 경우
			if (PtInRect(&myItem[3], ptMouse))
			{
				myList = 3;
			}

			//내아이템목록5 이었던 경우
			if (PtInRect(&myItem[4], ptMouse))
			{
				myList = 4;
			}

			//내아이템목록6 이었던 경우
			if (PtInRect(&myItem[5], ptMouse))
			{
				myList = 5;
			}

			//내아이템목록7 이었던 경우
			if (PtInRect(&myItem[6], ptMouse))
			{
				myList = 6;
			}

			//내아이템목록8 이었던 경우
			if (PtInRect(&myItem[7], ptMouse))
			{
				myList = 7;
			}

			//내아이템목록9 이었던 경우
			if (PtInRect(&myItem[8], ptMouse))
			{
				myList = 8;
			}

			//상점목록1 이었던 경우
			if (PtInRect(&shopItem[0], ptMouse))
			{
				shopListClick = 0;
			}

			//상점목록2 이었던 경우
			else if (PtInRect(&shopItem[1], ptMouse))
			{
				shopListClick = 1;
			}

			//상점목록3 이었던 경우
			else if (PtInRect(&shopItem[2], ptMouse))
			{
				shopListClick = 2;
			}

			//상점목록4 이었던 경우
			else if (PtInRect(&shopItem[3], ptMouse))
			{
				shopListClick = 3;
			}

			//상점목록5 이었던 경우
			else if (PtInRect(&shopItem[4], ptMouse))
			{
				shopListClick = 4;
			}

			//상점목록6 이었던 경우
			else if (PtInRect(&shopItem[5], ptMouse))
			{
				shopListClick = 5;
			}

			//상점목록7 이었던 경우
			else if (PtInRect(&shopItem[6], ptMouse))
			{
				shopListClick = 6;
			}

			//상점목록8 이었던 경우
			else if (PtInRect(&shopItem[7], ptMouse))
			{
				shopListClick = 7;
			}

			//상점목록9 이었던 경우
			else if (PtInRect(&shopItem[8], ptMouse))
			{
				shopListClick = 8;
			}

			//////////////////////////////아이템 구매하기//////////////////////////////////
			else if (PtInRect(&buttonBuy, ptMouse))
			{
				switch (shopListClick)
				{
				case 0:
					if (pl->getmeso() >= Sellings->_item.at(0)._price)
					{
						pl->buyConsume(Sellings->_item.at(0));
						pl->spendmeso(Sellings->_item.at(0)._price);
					}
					break;
				case 1: //4
					if (pl->getmeso() >= Sellings->_item.at(4)._price)
					{
						pl->buyConsume(Sellings->_item.at(4));
						pl->spendmeso(Sellings->_item.at(4)._price);
					}
					break;
				case 2://7
					if (pl->getmeso() >= Sellings->_item.at(7)._price)
					{
						pl->buyEquip(Sellings->_item.at(7));
						pl->spendmeso(Sellings->_item.at(7)._price);
					}
					break;
				case 3://9
					if (pl->getmeso() >= Sellings->_item.at(9)._price)
					{
						pl->buyEquip(Sellings->_item.at(9));
						pl->spendmeso(Sellings->_item.at(9)._price);
					}
					break;
				case 4://13
					if (pl->getmeso() >= Sellings->_item.at(13)._price)
					{
						pl->buyEquip(Sellings->_item.at(13));
						pl->spendmeso(Sellings->_item.at(13)._price);
					}
					break;
				case 5://15
					if (pl->getmeso() >= Sellings->_item.at(15)._price)
					{
						pl->buyEquip(Sellings->_item.at(15));
						pl->spendmeso(Sellings->_item.at(15)._price);
					}
					break;
				case 6://19
					if (pl->getmeso() >= Sellings->_item.at(19)._price)
					{
						pl->buyEquip(Sellings->_item.at(19));
						pl->spendmeso(Sellings->_item.at(19)._price);
					}
					break;
				case 7://21
					if (pl->getmeso() >= Sellings->_item.at(21)._price)
					{
						pl->buyEquip(Sellings->_item.at(21));
						pl->spendmeso(Sellings->_item.at(21)._price);
					}
					break;
				case 8://26
					if (pl->getmeso() >= Sellings->_item.at(26)._price)
					{
						pl->buyEquip(Sellings->_item.at(26));
						pl->spendmeso(Sellings->_item.at(26)._price);
					}
					break;

				}

				//물건을 사고나면 인벤토리 정보를 갱신해준다.
				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if ((i * 4 + j)<pl->getEquip().size())
							c_equip[i * 4 + j] = i * 4 + j;
						if ((i * 4 + j)<pl->getConsume().size())
							c_consume[i * 4 + j] = i * 4 + j;
					}
				}

			}
			////////////////////////아이템 판매하기//////////////////////////////////
			else if (PtInRect(&buttonSell, ptMouse))
			{
				if (onShopEquipTab)
				{
					switch (myList)
					{
					case 0:
						pl->sellEquip(0);
						pl->earnMeso(pl->getEquip().at(0)._price);
						break;
					case 1:
						pl->sellEquip(1);
						pl->earnMeso(pl->getEquip().at(1)._price);
						break;
					case 2:
						pl->sellEquip(2);
						pl->earnMeso(pl->getEquip().at(2)._price);
						break;
					case 3:
						pl->sellEquip(3);
						pl->earnMeso(pl->getEquip().at(3)._price);
						break;
					case 4:
						pl->sellEquip(4);
						pl->earnMeso(pl->getEquip().at(4)._price);
						break;
					case 5:
						pl->sellEquip(5);
						pl->earnMeso(pl->getEquip().at(5)._price);
						break;
					case 6:
						pl->sellEquip(6);
						pl->earnMeso(pl->getEquip().at(6)._price);
						break;
					case 7:
						pl->sellEquip(7);
						pl->earnMeso(pl->getEquip().at(7)._price);
						break;
					case 8:
						pl->sellEquip(8);
						pl->earnMeso(pl->getEquip().at(8)._price);
						break;
					}
				}
				else if (onShopPortionTab)
				{
					switch (myList)
					{
					case 0:
						pl->sellConsume(0);
						pl->earnMeso(pl->getConsume().at(0)._price);
						break;
					case 1:
						pl->sellConsume(1);
						pl->earnMeso(pl->getConsume().at(1)._price);
						break;
					case 2:
						pl->sellConsume(2);
						pl->earnMeso(pl->getConsume().at(2)._price);
						break;
					case 3:
						pl->sellConsume(3);
						pl->earnMeso(pl->getConsume().at(3)._price);
						break;
					case 4:
						pl->sellConsume(4);
						pl->earnMeso(pl->getConsume().at(4)._price);
						break;
					case 5:
						pl->sellConsume(5);
						pl->earnMeso(pl->getConsume().at(5)._price);
						break;
					case 6:
						pl->sellConsume(6);
						pl->earnMeso(pl->getConsume().at(6)._price);
						break;
					case 7:
						pl->sellConsume(7);
						pl->earnMeso(pl->getConsume().at(7)._price);
						break;
					case 8:
						pl->sellConsume(8);
						pl->earnMeso(pl->getConsume().at(8)._price);
						break;
					}
				}

				
				//물건을 팔고나면 인벤토리 정보를 갱신해준다.
				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if ((i * 4 + j)<pl->getEquip().size())
							c_equip[i * 4 + j] = i * 4 + j;
						if ((i * 4 + j)<pl->getConsume().size())
							c_consume[i * 4 + j] = i * 4 + j;
					}
				}
			}
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		finger->setFrameY(1);
		//==============만일 아줌마클릭에서 버튼액션을 발동시킨 상태라면=============
		if (pl->openShop() == true && onClickAzoomma) {
			//버튼액션 유지
			onClickAzoomma = true;
		}
		//아니라면 버튼액션 종료
		else
			onClickAzoomma = false;

		//==================만일 샵에서 버튼액션을 발동시킨상태라면==================
		if (onShop)
		{
			//버튼위에서 누르고있으면 클릭을 유지시켜준다.
			if (PtInRect(&buttonQuit, ptMouse) && onClickQuit)
			{
				onClickQuit = true;
			}
			//누른상태에서 버튼을 벗어나면 액션을 취소시킨다.
			else
				onClickQuit = false;

			if (PtInRect(&buttonBuy, ptMouse) && onClickBuy)
			{
				onClickBuy = true;
			}
			else
				onClickBuy = false;

			if (PtInRect(&buttonSell, ptMouse) && onClickSell)
			{
				onClickSell = true;
			}
			else
				onClickSell = false;
		}

	}
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		finger->setFrameY(0);
		//==================상점아줌마를 누르고 있던 경우===============
		if (pl->openShop() == true && onClickAzoomma) {
			//마우스를 뗌과 동시에 상점을 켜준다.
			this->onShop = true;
		}

		//==================샵에서 버튼을 누르고있는 경우===============
		if (onShop)
		{
			//뗐을때 버튼위에 있었 경우
			if (PtInRect(&buttonQuit, ptMouse) && onClickQuit)
			{
				//버튼클릭을 꺼주고, 샵을 닫아준다.
				onClickQuit = false;
				onShop = false;
			}
			else
				//아닌경우 버튼액션만 무효화시킨다.
				onClickQuit = false;

			//아이템 사기버튼에 있었던 경우
			if (PtInRect(&buttonBuy, ptMouse) && onClickBuy)
			{
				onClickBuy = false;
			}
			else
				onClickBuy = false;

			//아이템팔기버튼이었던 경우
			if (PtInRect(&buttonSell, ptMouse) && onClickSell)
			{
				onClickSell = false;
			}
			else
				onClickSell = false;
			
		}
	}

	//우클릭 이벤트!!! 아이템 장착 해제!!!!
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		//인벤토리창이 켜져있을때에로만 한정시켜야 한다.
		if (onInven)
		{
			//장비탭에만 한정시켜야 함.
			if (invEq)
			{
				for (int i = 0; i < 24; i++)
				{
					if (PtInRect(&_myInven[i], ptMouse))
					{
						if (c_equip[i] >= 0)
						{
							switch (pl->getEquip().at(c_equip[i]).itemtype)
							{
							case helm:
								//이미 장착을 하고 있으면 해제를 먼저 해야하니까;;
								if (e_cap > 0)
								{
									e_cap = -1;
									//인벤토리의 빈곳에 순차적으로 도로 넣는다.
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_cap.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_cap = i_empty; //이게 장비로 인해 올라갔던 스텟 다시 원상복귀시켜준다.
								}
								
								e_cap = pl->getEquip().at(c_equip[i]).number;
								i_cap = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case earacc:
								e_earAcc = pl->getEquip().at(c_equip[i]).number;
								i_earAcc = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case clothes:
								if (e_clothes > 0)
								{
									e_clothes = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_clothes.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_clothes = i_empty;
								}
								e_clothes = pl->getEquip().at(c_equip[i]).number;
								i_clothes = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case pants:
								if (e_pants > 0)
								{
									e_pants = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_pants.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_pants = i_empty;
								}
								e_pants = pl->getEquip().at(c_equip[i]).number;
								i_pants = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case boots:
								if (e_shoes > 0)
								{
									e_shoes = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_shoes.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_shoes = i_empty;
								}
								e_shoes = pl->getEquip().at(c_equip[i]).number;
								i_shoes = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case weapons:
								if (e_weapon > 0)
								{
									e_weapon = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_weapon.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_weapon = i_empty;
								}
								e_weapon = pl->getEquip().at(c_equip[i]).number;
								i_weapon = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case gloves:
								if (e_gloves > 0)
								{
									e_gloves = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_gloves.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_gloves = i_empty;
								}
								e_gloves = pl->getEquip().at(c_equip[i]).number;
								i_gloves = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							case cape:
								if (e_capes > 0)
								{
									e_capes = -1;
									for (int i = 0; i < 24; i++)
									{
										if (c_equip[i] == -1)
										{
											int k = 0;
											for (int j = 0; j < pl->getEquip().size(); j++) {
												if (strcmp(i_capes.itemname, pl->getEquip().at(j).itemname) == 0) {
													break;
												}
												k++;
											}
											c_equip[i] = k;
											break;
										}
									}
									i_capes = i_empty;
								}
								e_capes = pl->getEquip().at(c_equip[i]).number;
								i_capes = pl->getEquip().at(c_equip[i]);
								c_equip[i] = -1;
								break;
							}
						}
					}
				}
			}
		}


		//장비창에서 해제할 경우

		if (onEquip)
		{
			//모자
			if (PtInRect(&_cap, ptMouse))
			{
				if (e_cap > 0)
				{
					e_cap = -1;
					//인벤토리의 빈곳에 순차적으로 도로 넣는다.
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_cap.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_cap = i_empty; //이게 장비로 인해 올라갔던 스텟 다시 원상복귀시켜준다.
				}
			}

			//무기
			if (PtInRect(&_weapon, ptMouse))
			{
				if (e_weapon > 0)
				{
					e_weapon = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_weapon.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_weapon = i_empty;
				}
			}

			//귀고리
			if (PtInRect(&_earAcc, ptMouse))
			{
				//귀고리는 없으니깐 아무처리도안함.
			}

			//상의
			if (PtInRect(&_clothes, ptMouse))
			{
				if (e_clothes > 0)
				{
					e_clothes = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_clothes.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_clothes = i_empty;
				}
			}

			//하의
			if (PtInRect(&_pants, ptMouse))
			{
				if (e_pants > 0)
				{
					e_pants = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_pants.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_pants = i_empty;
				}
			}

			//신발
			if (PtInRect(&_shoes, ptMouse))
			{
				if (e_shoes > 0)
				{
					e_shoes = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_shoes.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_shoes = i_empty;
				}
			}

			//장갑
			if (PtInRect(&_gloves, ptMouse))
			{
				if (e_gloves > 0)
				{
					e_gloves = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_gloves.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_gloves = i_empty;
				}
			}

			//망토
			if (PtInRect(&_capes, ptMouse))
			{
				if (e_capes > 0)
				{
					e_capes = -1;
					for (int i = 0; i < 24; i++)
					{
						if (c_equip[i] == -1)
						{
							int k = 0;
							for (int j = 0; j < pl->getEquip().size(); j++) {
								if (strcmp(i_capes.itemname, pl->getEquip().at(j).itemname) == 0) {
									break;
								}
								k++;
							}
							c_equip[i] = k;
							break;
						}
					}
					i_capes = i_empty;
				}
			}
		}

	}

	//키 작동 확인.
	//체력포션 처먹처먹
	if (KEYMANAGER->isOnceKeyDown(VK_DELETE))
	{
		HpHillMax += 50;
		HpHill = HpHillMax / 10;
		HpHillCount = 10;
	}

	//마나포션 처먹처먹
	if (KEYMANAGER->isOnceKeyDown(VK_INSERT))
	{
		MpHillMax += 50;
		MpHill = MpHillMax / 10;
		MpHillCount = 10;
		
	}
	Hpwidth = ((float)pl->getstatus()->curHP / (float)pl->getstatus()->maxHP) * (float)hpbar->getWidth();
	Mpwidth = ((float)pl->getstatus()->curMP / (float)pl->getstatus()->maxMP)*(float)mpbar->getWidth();
	Exwidth = ((float)pl->getstatus()->Exp / (float)pl->getstatus()->lvlUpExp)*(float)expGuage->getWidth();
}

void UserInterface::render(void)
{
	//텍스트 렌더링에 필요한 기본설정쓰
	SetBkMode(getMemDC(), TRANSPARENT); //이거 해줘야 흰색배경 없앤다.
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	//기본인터페이스 렌더링
	//경험치
	expBackground->render(getMemDC());
	expGuage->render(getMemDC(), 16, 761, 0, 0, Exwidth, expLayer->getHeight());
	expLayer->render(getMemDC());

	//캐릭터정보 및 체력, 마나게이지
	_formBackground->render(getMemDC());
	hpbar->render(getMemDC(), _formBackground->getX() + 22, _formBackground->getY() + 3, 0, 0, Hpwidth, mpbar->getHeight());
	mpbar->render(getMemDC(), _formBackground->getX() + 22, _formBackground->getY() + 17, 0, 0, Mpwidth, hpbar->getHeight());
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


	//스텟창, 장비창, 인벤토리, 상점 렌더링
	if (onStat)
		statement();
	if (onEquip)
		equip();
	if (onInven)
		inventory();
	if (onShop)
		shop();

	//마우스 커서 숨기기
	SetCursor(NULL);
	ShowCursor(false);

	finger->frameRender(getMemDC(), ptMouse.x, ptMouse.y, fingerCount, finger->getFrameY());
}

void UserInterface::equip(void)
{
	equipWnd->render(getMemDC());
	_cap = RectMake(equipWnd->getX() + 97, equipWnd->getY() + 55, 38, 38);
	_clothes = RectMake(equipWnd->getX() + 97, equipWnd->getY() + 179, 38, 38);
	_weapon = RectMake(equipWnd->getX() + 57, equipWnd->getY() + 179, 38, 38);
	_earAcc = RectMake(equipWnd->getX() + 146, equipWnd->getY() + 134, 38, 38);
	_pants = RectMake(equipWnd->getX() + 97, equipWnd->getY() + 220, 38, 38);
	_shoes = RectMake(equipWnd->getX() + 97, equipWnd->getY() + 260, 38, 38);
	_gloves = RectMake(equipWnd->getX() + 137, equipWnd->getY() + 220, 38, 38);
	_capes = RectMake(equipWnd->getX() + 177, equipWnd->getY() + 220, 38, 38);
	//Rectangle(getMemDC(), _capes.left, _capes.top, _capes.right, _capes.bottom);

	switch (e_cap)
	{
	case 9:
		iT->_item.at(e_cap).itemimg->render(getMemDC(), _cap.left + 3, _cap.top + 3);
		break;
	case 10:
		iT->_item.at(e_cap).itemimg->render(getMemDC(), _cap.left + 3, _cap.top + 3);
		break;
	case 11:
		iT->_item.at(e_cap).itemimg->render(getMemDC(), _cap.left + 3, _cap.top + 3);
		break;
	default:
		break;
	}

	switch (e_weapon)
	{
	case 12:
		iT->_item.at(e_weapon).itemimg->render(getMemDC(), _weapon.left + 3, _weapon.top + 3);
		break;
	case 13:
		iT->_item.at(e_weapon).itemimg->render(getMemDC(), _weapon.left + 3, _weapon.top + 3);
		break;
	case 14:
		iT->_item.at(e_weapon).itemimg->render(getMemDC(), _weapon.left + 3, _weapon.top + 3);
		break;
	default:
		break;
	}

	switch (e_clothes)
	{
	case 18:
		iT->_item.at(e_clothes).itemimg->render(getMemDC(), _clothes.left + 3, _clothes.top + 3);
		break;
	case 19:
		iT->_item.at(e_clothes).itemimg->render(getMemDC(), _clothes.left + 3, _clothes.top + 3);
		break;
	case 20:
		iT->_item.at(e_clothes).itemimg->render(getMemDC(), _clothes.left + 3, _clothes.top + 3);
		break;
	default:
		break;
	}

	switch (e_earAcc)
	{
	//귀고리는 없어서 정의 안함.
	default:
		break;
	}

	switch (e_pants)
	{
	case 15:
		iT->_item.at(e_pants).itemimg->render(getMemDC(), _pants.left + 3, _pants.top + 3);
		break;
	case 16:
		iT->_item.at(e_pants).itemimg->render(getMemDC(), _pants.left + 3, _pants.top + 3);
		break;
	case 17:
		iT->_item.at(e_pants).itemimg->render(getMemDC(), _pants.left + 3, _pants.top + 3);
		break;
	default:
		break;
	}

	switch (e_shoes)
	{
	case 21:
		iT->_item.at(e_shoes).itemimg->render(getMemDC(), _shoes.left + 3, _shoes.top + 3);
		break;
	case 22:
		iT->_item.at(e_shoes).itemimg->render(getMemDC(), _shoes.left + 3, _shoes.top + 3);
		break;
	case 23:
		iT->_item.at(e_shoes).itemimg->render(getMemDC(), _shoes.left + 3, _shoes.top + 3);
		break;
	default:
		break;
	}

	switch (e_gloves)
	{
	case 24:
		iT->_item.at(e_gloves).itemimg->render(getMemDC(), _gloves.left + 3, _gloves.top + 3);
		break;
	case 25:
		iT->_item.at(e_gloves).itemimg->render(getMemDC(), _gloves.left + 3, _gloves.top + 3);
		break;
	case 26:
		iT->_item.at(e_gloves).itemimg->render(getMemDC(), _gloves.left + 3, _gloves.top + 3);
		break;
	default:
		break;
	}

	switch (e_capes)
	{
	case 6:
		iT->_item.at(e_capes).itemimg->render(getMemDC(), _capes.left + 3, _capes.top + 3);
		break;
	case 7:
		iT->_item.at(e_capes).itemimg->render(getMemDC(), _capes.left + 3, _capes.top + 3);
		break;
	case 8:
		iT->_item.at(e_capes).itemimg->render(getMemDC(), _capes.left + 3, _capes.top + 3);
		break;
	default:
		break;
	}
}

void UserInterface::inventory(void)
{
	//글자출력을 위한 폰트설정
	HFONT font1, oldFont;

	font1 = CreateFont(12, 0, 0, 0, 100, false, 0, false, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("돋움체"));
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	SetBkMode(getMemDC(), TRANSPARENT);
	oldFont = (HFONT)SelectObject(getMemDC(), font1);

	invenWnd->render(getMemDC());

	//탭 클릭을 위한 영역처리
	equipTabSq = RectMake(invenWnd->getX() + 9, invenWnd->getY() + 26, 30, 19);
	potionTabSq = RectMake(invenWnd->getX() + 41, invenWnd->getY() + 26, 30, 19);
	etcTabSq = RectMake(invenWnd->getX() + 73, invenWnd->getY() + 26, 30, 19);
	//Rectangle(getMemDC(), etcTabSq.left, etcTabSq.top, etcTabSq.right, etcTabSq.bottom);


	//아이템 저장영역은 24개이고, 각 탭마다 만들어줄 필요 X.
	//각 탭마다 만들어버리면 RectMake가 계속 위에다 덮어씌워버린다. ->나중에 기타탭 누르고 소비탭으로 돌아가면 기타탭정보가 남아버림........
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_myInven[i*4 + j] = RectMake(invenWnd->getX() + 10 +36.2*j, invenWnd->getY() + 50 + 35*i, 32, 32);
		}
	}


	
	//장비탭이 켜진경우
	if (invEq)
	{
		equipTab->render(getMemDC(), equipTabSq.left, equipTabSq.top);
		for (int i = 0; i < 24; i++)
		{
			switch (c_equip[i])
			{
			case 0:
				if (pl->getEquip().at(0).stack > 0)
				{
					pl->getEquip().at(0).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 1:
				if (pl->getEquip().at(1).stack > 0)
				{
					pl->getEquip().at(1).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 2:
				if (pl->getEquip().at(2).stack > 0)
				{
					pl->getEquip().at(2).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 3:
				if (pl->getEquip().at(3).stack > 0)
				{
					pl->getEquip().at(3).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 4:
				if (pl->getEquip().at(4).stack > 0)
				{
					pl->getEquip().at(4).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 5:
				if (pl->getEquip().at(5).stack > 0)
				{
					pl->getEquip().at(5).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 6:
				if (pl->getEquip().at(6).stack > 0)
				{
					pl->getEquip().at(6).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 7:
				if (pl->getEquip().at(7).stack > 0)
				{
					pl->getEquip().at(7).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 8:
				if (pl->getEquip().at(8).stack > 0)
				{
					pl->getEquip().at(8).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 9:
				if (pl->getEquip().at(9).stack > 0)
				{
					pl->getEquip().at(9).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 10:
				if (pl->getEquip().at(10).stack > 0)
				{
					pl->getEquip().at(10).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 11:
				if (pl->getEquip().at(11).stack > 0)
				{
					pl->getEquip().at(11).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 12:
				if (pl->getEquip().at(12).stack > 0)
				{
					pl->getEquip().at(12).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
				//그외에것은 아무것도 그리지 않는다.
			default :
				break;
			}
		}
	}

	//소비탭이 켜진경우
	if (invPo)
	{
		potionTab->render(getMemDC(), potionTabSq.left, potionTabSq.top);
		for (int i = 0; i < 24; i++)
		{
			switch (c_consume[i])
			{
			case 0:
				if (pl->getConsume().at(0).stack > 0)
				{
					pl->getConsume().at(0).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
					char itStack1[255];
					sprintf(itStack1, "%d", pl->getConsume().at(0).stack);
					RECT rcTextArea = RectMake(_myInven[i].left, _myInven[i].top + 20, 16, 16);
					DrawText(getMemDC(), itStack1, -1, &rcTextArea, DT_LEFT);
				}
				break;
			case 1:
				if (pl->getConsume().at(1).stack > 0)
				{
					pl->getConsume().at(1).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
					char itStack2[255];
					sprintf(itStack2, "%d", pl->getConsume().at(1).stack);
					RECT rcTextArea = RectMake(_myInven[i].left, _myInven[i].top + 20, 16, 16);
					DrawText(getMemDC(), itStack2, -1, &rcTextArea, DT_LEFT);
				}
				break;
			case 2:
				if (pl->getConsume().at(2).stack > 0)
				{
					pl->getConsume().at(2).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 3:
				if (pl->getConsume().at(3).stack > 0)
				{
					pl->getConsume().at(3).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 4:
				if (pl->getConsume().at(4).stack > 0)
				{
					pl->getConsume().at(4).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 5:
				if (pl->getConsume().at(5).stack > 0)
				{
					pl->getConsume().at(5).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 6:
				if (pl->getConsume().at(6).stack > 0)
				{
					pl->getConsume().at(6).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
				//그외에것은 아무것도 그리지 않는다.
			default:
				break;
			}
		}
	}

	//기타탭이 켜진경우
	if (invEtc)
	{
		etcTab->render(getMemDC(), etcTabSq.left, etcTabSq.top);
		for (int i = 0; i < 24; i++)
		{
			switch (c_etc[i])
			{
			case 0:
				if (pl->getEtc().at(0).stack > 0)
				{
					pl->getEtc().at(0).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 1:
				if (pl->getEtc().at(1).stack > 0)
				{
					pl->getEtc().at(1).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 2:
				if (pl->getEtc().at(2).stack > 0)
				{
					pl->getEtc().at(2).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 3:
				if (pl->getEtc().at(3).stack > 0)
				{
					pl->getEtc().at(3).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 4:
				if (pl->getEtc().at(4).stack > 0)
				{
					pl->getEtc().at(4).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 5:
				if (pl->getEtc().at(5).stack > 0)
				{
					pl->getEtc().at(5).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
			case 6:
				if (pl->getEtc().at(6).stack > 0)
				{
					pl->getEtc().at(6).itemimg->render(getMemDC(), _myInven[i].left, _myInven[i].top);
				}
				break;
				//그외에것은 아무것도 그리지 않는다.
			default:
				break;
			}
		}
	}


	//캐릭터가 보유하고있는 메소 표기

	char tempMeso[255];
	sprintf(tempMeso, "%d", pl->getmeso());
	RECT rcTextArea = RectMake(invenWnd->getX() + 40, invenWnd->getY() + 266, 83, 15);
	DrawText(getMemDC(), tempMeso, -1, &rcTextArea, DT_RIGHT);

	//폰트 설정 제거.
	DeleteObject(oldFont);
	DeleteObject(font1);

	switch (invInfo)
	{
	case 0:
		showItemInfo(0);
		break;
	case 1:
		showItemInfo(1);
		break;
	case 2:
		showItemInfo(2);
		break;
	case 3:
		showItemInfo(3);
		break;
	case 4:
		showItemInfo(4);
		break;
	case 5:
		showItemInfo(5);
		break;
	case 6:
		showItemInfo(6);
		break;
	case 7:
		showItemInfo(7);
		break;
	case 8:
		showItemInfo(8);
		break;
	case 9:
		showItemInfo(9);
		break;
	case 10:
		showItemInfo(10);
		break;
	case 11:
		showItemInfo(11);
		break;
	case 12:
		showItemInfo(12);
		break;
	case 13:
		showItemInfo(13);
		break;
	case 14:
		showItemInfo(14);
		break;
	case 15:
		showItemInfo(15);
		break;
	case 16:
		showItemInfo(16);
		break;
	case 17:
		showItemInfo(17);
		break;
	case 18:
		showItemInfo(18);
		break;
	case 19:
		showItemInfo(19);
		break;
	case 20:
		showItemInfo(20);
		break;
	case 21:
		showItemInfo(21);
		break;
	case 22:
		showItemInfo(22);
		break;
	case 23:
		showItemInfo(23);
		break;
	case 24:
		showItemInfo(24);
		break;
	case 25:
		showItemInfo(25);
		break;
	case 26:
		showItemInfo(26);
		break;
	default :
		break;

	}

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
	sprintf(temp9, "%d(%d+%d)", _str, pl->getstatus()->Str, totalEquipstr);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 209, temp9, strlen(temp9));

	char temp10[255];
	sprintf(temp10, "%d(%d+%d)", _dex, pl->getstatus()->Dex, totalEquipdex);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 227, temp10, strlen(temp10));

	char temp11[255];
	sprintf(temp11, "%d(%d+%d)", _int, pl->getstatus()->Int, totalEquipint);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 245, temp11, strlen(temp11));

	char temp12[255];
	sprintf(temp12, "%d", _luk, pl->getstatus()->Luk, totalEquipluk);
	TextOut(getMemDC(), statWnd->getX() + 75, statWnd->getY() + 263, temp12, strlen(temp12));

	//다썼으면 지워주자!!!
	DeleteObject(oldFont);
	DeleteObject(font1);
}

void UserInterface::shop(void)
{
	shopWnd->setX(450);
	shopWnd->setY(100);
	shopWnd->render(getMemDC());
	
	//아이템사진은 35x35. 아이템 설명및 가격표기 태그는 208x35 & 165x35.

	//상점 버튼액션 및 이미지 렌더링을 위한 구역렉트설정
	shopItem[0] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 124, 245, 35);
	shopItem[1] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 166, 245, 35);
	shopItem[2] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 208, 245, 35);
	shopItem[3] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 250, 245, 35);
	shopItem[4] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 292, 245, 35);
	shopItem[5] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 334, 245, 35);
	shopItem[6] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 376, 245, 35);
	shopItem[7] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 418, 245, 35);
	shopItem[8] = RectMake(shopWnd->getX() + 10, shopWnd->getY() + 460, 245, 35);
	//Rectangle(getMemDC(), shopItem[0].left, shopItem[0].top, shopItem[0].right, shopItem[0].bottom);
	
	myItem[0] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 124, 200, 35);
	myItem[1] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 166, 200, 35);
	myItem[2] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 208, 200, 35);
	myItem[3] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 250, 200, 35);
	myItem[4] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 292, 200, 35);
	myItem[5] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 334, 200, 35);
	myItem[6] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 376, 200, 35);
	myItem[7] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 418, 200, 35);
	myItem[8] = RectMake(shopWnd->getX() + 285, shopWnd->getY() + 460, 200, 35);

	shopEquipTab = RectMake(shopWnd->getX() + 284, shopWnd->getY() + 100, 42, 19);
	shopPortionTab = RectMake(shopWnd->getX() + 327, shopWnd->getY() + 100, 42, 19);
	shopEtcTab = RectMake(shopWnd->getX() + 370, shopWnd->getY() + 100, 42, 19);

	_me->frameRender(getMemDC(), shopWnd->getX() + 280, shopWnd->getY() - 10, _meCount, _me->getFrameY());
	_Azoomma->frameRender(getMemDC(), shopWnd->getX() + 30, shopWnd->getY() + 10, _AzoommaCount, _Azoomma->getFrameY());
	
	buttonQuit = RectMake(shopWnd->getX() + 203, shopWnd->getY() + 54, 64, 16);
	buttonBuy = RectMake(shopWnd->getX() + 203, shopWnd->getY() + 74, 64, 16);
	buttonSell = RectMake(shopWnd->getX() + 433, shopWnd->getY() + 74, 64, 16);

	//장비탭이 켜진경우
	if (onShopEquipTab)
	{
		shopEquip->render(getMemDC(), shopEquipTab.left, shopEquipTab.top);
	}

	//소비탭이 켜진경우
	if (onShopPortionTab)
	{
		shopPortion->render(getMemDC(), shopPortionTab.left, shopPortionTab.top);
	}

	//기타탭이 켜진경우
	if (onShopEtcTab)
	{
		shopEtc->render(getMemDC(), shopEtcTab.left, shopEtcTab.top);
	}

	//상점나가기 버튼에 마우스를 올렸을경우
	if (PtInRect(&buttonQuit, ptMouse))
	{
		shopQuit->render(getMemDC(), buttonQuit.left, buttonQuit.top);
	}
	//눌렀을경우
	if (PtInRect(&buttonQuit, ptMouse) && onClickQuit)
	{
		shopQuitPushed->render(getMemDC(), buttonQuit.left, buttonQuit.top);
	}

	//아이템사기 버튼에 마우스를 올렸을 경우
	if (PtInRect(&buttonBuy, ptMouse))
	{
		shopBuy->render(getMemDC(), buttonBuy.left, buttonBuy.top);
	}
	//눌렀을경우
	if (PtInRect(&buttonBuy, ptMouse) && onClickBuy)
	{
		shopBuyPushed->render(getMemDC(), buttonBuy.left, buttonBuy.top);
	}

	//아이템팔기 버튼에 마우스를 올렸을 경우
	if (PtInRect(&buttonSell, ptMouse))
	{
		shopSell->render(getMemDC(), buttonSell.left, buttonSell.top);
	}
	//눌렀을경우
	if (PtInRect(&buttonSell, ptMouse) && onClickSell)
	{
		shopSellPushed->render(getMemDC(), buttonSell.left, buttonSell.top);
	}

	//샵 구매목록 클릭처리
	switch (shopListClick)
	{
	case 0:
		selectEffect2->render(getMemDC(), shopItem[0].left + 36, shopItem[0].top);
		break;
	case 1:
		selectEffect2->render(getMemDC(), shopItem[1].left + 36, shopItem[1].top);
		break;
	case 2:
		selectEffect2->render(getMemDC(), shopItem[2].left + 36, shopItem[2].top);
		break;
	case 3:
		selectEffect2->render(getMemDC(), shopItem[3].left + 36, shopItem[3].top);
		break;
	case 4:
		selectEffect2->render(getMemDC(), shopItem[4].left + 36, shopItem[4].top);
		break;
	case 5:
		selectEffect2->render(getMemDC(), shopItem[5].left + 36, shopItem[5].top);
		break;
	case 6:
		selectEffect2->render(getMemDC(), shopItem[6].left + 36, shopItem[6].top);
		break;
	case 7:
		selectEffect2->render(getMemDC(), shopItem[7].left + 36, shopItem[7].top);
		break;
	case 8:
		selectEffect2->render(getMemDC(), shopItem[8].left + 36, shopItem[8].top);
		break;
	default:
		break;

	}

	switch (myList)
	{
	case 0:
		selectEffect->render(getMemDC(), myItem[0].left + 36, myItem[0].top);
		break;
	case 1:
		selectEffect->render(getMemDC(), myItem[1].left + 36, myItem[1].top);
		break;
	case 2:
		selectEffect->render(getMemDC(), myItem[2].left + 36, myItem[2].top);
		break;
	case 3:
		selectEffect->render(getMemDC(), myItem[3].left + 36, myItem[3].top);
		break;
	case 4:
		selectEffect->render(getMemDC(), myItem[4].left + 36, myItem[4].top);
		break;
	case 5:
		selectEffect->render(getMemDC(), myItem[5].left + 36, myItem[5].top);
		break;
	case 6:
		selectEffect->render(getMemDC(), myItem[6].left + 36, myItem[6].top);
		break;
	case 7:
		selectEffect->render(getMemDC(), myItem[7].left + 36, myItem[7].top);
		break;
	case 8:
		selectEffect->render(getMemDC(), myItem[8].left + 36, myItem[8].top);
		break;
	default:
		break;

	}

	//상점 판매목록에 기본적으로 표시되어있는 메소아이콘
	for (int i = 0; i < 9; i++)
	{
		mesoIcon->render(getMemDC(), shopItem[i].left + 40, shopItem[i].top + 21);
	}

	//-------------------상점창 텍스트 정보들 출력!!!!-------------



	//글자출력을 위한 폰트설정
	HFONT font1, oldFont;

	font1 = CreateFont(13, 0, 0, 0, 100, false, 0, false, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("돋움체"));
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	SetBkMode(getMemDC(), TRANSPARENT);
	oldFont = (HFONT)SelectObject(getMemDC(), font1);

	//캐릭터가 보유하고있는 메소 표기

	char tempMeso[255];
	sprintf(tempMeso, "%d", pl->getmeso());
	RECT rcTextArea = RectMake(shopWnd->getX() + 413, shopWnd->getY() + 54, 83, 15);
	DrawText(getMemDC(), tempMeso, -1, &rcTextArea, DT_RIGHT);

	//-------------------상점판매아이템 이미지 및 가격 출력-------------


	Sellings->_item.at(0).itemimg->render(getMemDC(), shopItem[0].left + 2, shopItem[0].top + 2);
	char temp[255];
	sprintf(temp, "%d 메소", Sellings->_item.at(0)._price);
	TextOut(getMemDC(), shopItem[0].left + 55, shopItem[0].top + 21, temp, strlen(temp));
	char temp10[255];
	sprintf(temp10, "%s", Sellings->_item.at(0).itemname);
	TextOut(getMemDC(), shopItem[0].left + 40, shopItem[0].top + 2, temp10, strlen(temp10));



	Sellings->_item.at(4).itemimg->render(getMemDC(), shopItem[1].left + 2, shopItem[1].top + 2);
	char temp2[255];
	sprintf(temp2, "%d 메소", Sellings->_item.at(4)._price);
	TextOut(getMemDC(), shopItem[1].left + 55, shopItem[1].top + 21, temp2, strlen(temp2));
	char temp11[255];
	sprintf(temp11, "%s", Sellings->_item.at(4).itemname);
	TextOut(getMemDC(), shopItem[1].left + 40, shopItem[1].top + 2, temp11, strlen(temp11));



	Sellings->_item.at(7).itemimg->render(getMemDC(), shopItem[2].left + 2, shopItem[2].top + 2);
	char temp3[255];
	sprintf(temp3, "%d 메소", Sellings->_item.at(7)._price);
	TextOut(getMemDC(), shopItem[2].left + 55, shopItem[2].top + 21, temp3, strlen(temp3));
	char temp12[255];
	sprintf(temp12, "%s", Sellings->_item.at(7).itemname);
	TextOut(getMemDC(), shopItem[2].left + 40, shopItem[2].top + 2, temp12, strlen(temp12));



	Sellings->_item.at(9).itemimg->render(getMemDC(), shopItem[3].left + 2, shopItem[3].top + 2);
	char temp4[255];
	sprintf(temp4, "%d 메소", Sellings->_item.at(9)._price);
	TextOut(getMemDC(), shopItem[3].left + 55, shopItem[3].top + 21, temp4, strlen(temp4));
	char temp13[255];
	sprintf(temp13, "%s", Sellings->_item.at(9).itemname);
	TextOut(getMemDC(), shopItem[3].left + 40, shopItem[3].top + 2, temp13, strlen(temp13));



	Sellings->_item.at(13).itemimg->render(getMemDC(), shopItem[4].left + 2, shopItem[4].top + 2);
	char temp5[255];
	sprintf(temp5, "%d 메소", Sellings->_item.at(13)._price);
	TextOut(getMemDC(), shopItem[4].left + 55, shopItem[4].top + 21, temp5, strlen(temp5));
	char temp14[255];
	sprintf(temp14, "%s", Sellings->_item.at(13).itemname);
	TextOut(getMemDC(), shopItem[4].left + 40, shopItem[4].top + 2, temp14, strlen(temp14));



	Sellings->_item.at(15).itemimg->render(getMemDC(), shopItem[5].left + 2, shopItem[5].top + 2);
	char temp6[255];
	sprintf(temp6, "%d 메소", Sellings->_item.at(15)._price);
	TextOut(getMemDC(), shopItem[5].left + 55, shopItem[5].top + 21, temp6, strlen(temp6));
	char temp15[255];
	sprintf(temp15, "%s", Sellings->_item.at(15).itemname);
	TextOut(getMemDC(), shopItem[5].left + 40, shopItem[5].top + 2, temp15, strlen(temp15));



	Sellings->_item.at(19).itemimg->render(getMemDC(), shopItem[6].left + 2, shopItem[6].top + 2);
	char temp7[255];
	sprintf(temp7, "%d 메소", Sellings->_item.at(19)._price);
	TextOut(getMemDC(), shopItem[6].left + 55, shopItem[6].top + 21, temp7, strlen(temp7));
	char temp16[255];
	sprintf(temp16, "%s", Sellings->_item.at(19).itemname);
	TextOut(getMemDC(), shopItem[6].left + 40, shopItem[6].top + 2, temp16, strlen(temp16));



	Sellings->_item.at(21).itemimg->render(getMemDC(), shopItem[7].left + 2, shopItem[7].top + 2);
	char temp8[255];
	sprintf(temp8, "%d 메소", Sellings->_item.at(21)._price);
	TextOut(getMemDC(), shopItem[7].left + 55, shopItem[7].top + 21, temp8, strlen(temp8));
	char temp17[255];
	sprintf(temp17, "%s", Sellings->_item.at(21).itemname);
	TextOut(getMemDC(), shopItem[7].left + 40, shopItem[7].top + 2, temp17, strlen(temp17));



	Sellings->_item.at(26).itemimg->render(getMemDC(), shopItem[8].left + 2, shopItem[8].top + 2);
	char temp9[255];
	sprintf(temp9, "%d 메소", Sellings->_item.at(26)._price);
	TextOut(getMemDC(), shopItem[8].left + 55, shopItem[8].top + 21, temp9, strlen(temp9));
	char temp18[255];
	sprintf(temp18, "%s", Sellings->_item.at(26).itemname);
	TextOut(getMemDC(), shopItem[8].left + 40, shopItem[8].top + 2, temp18, strlen(temp18));

	//-------------------------내 아이템 판매 목록들-------------------------------
	if (onShopEquipTab)
	{
		if (pl->getEquip().size() > 0)
		{
			Mines->_item.at(pl->getEquip().at(0).number).itemimg->render(getMemDC(), myItem[0].left + 2, myItem[0].top + 2);
			char tt[255];
			sprintf(tt, "%d 메소", Mines->_item.at(pl->getEquip().at(0).number)._price);
			TextOut(getMemDC(), myItem[0].left + 40, myItem[0].top + 21, tt, strlen(tt));
			char tt2[255];
			sprintf(tt2, "%s", Mines->_item.at(pl->getEquip().at(0).number).itemname);
			TextOut(getMemDC(), myItem[0].left + 40, myItem[0].top + 2, tt2, strlen(tt2));
		}


		if (pl->getEquip().size() > 1)
		{
			Mines->_item.at(pl->getEquip().at(1).number).itemimg->render(getMemDC(), myItem[1].left + 2, myItem[1].top + 2);
			char tt3[255];
			sprintf(tt3, "%d 메소", Mines->_item.at(pl->getEquip().at(1).number)._price);
			TextOut(getMemDC(), myItem[1].left + 40, myItem[1].top + 21, tt3, strlen(tt3));
			char tt4[255];
			sprintf(tt4, "%s", Mines->_item.at(pl->getEquip().at(1).number).itemname);
			TextOut(getMemDC(), myItem[1].left + 40, myItem[1].top + 2, tt4, strlen(tt4));
		}


		if (pl->getEquip().size() > 2)
		{
			Mines->_item.at(pl->getEquip().at(2).number).itemimg->render(getMemDC(), myItem[2].left + 2, myItem[2].top + 2);
			char tt5[255];
			sprintf(tt5, "%d 메소", Mines->_item.at(pl->getEquip().at(2).number)._price);
			TextOut(getMemDC(), myItem[2].left + 40, myItem[2].top + 21, tt5, strlen(tt5));
			char tt6[255];
			sprintf(tt6, "%s", Mines->_item.at(pl->getEquip().at(2).number).itemname);
			TextOut(getMemDC(), myItem[2].left + 40, myItem[2].top + 2, tt6, strlen(tt6));
		}

		if (pl->getEquip().size() > 3)
		{
			Mines->_item.at(pl->getEquip().at(3).number).itemimg->render(getMemDC(), myItem[3].left + 2, myItem[3].top + 2);
			char tt7[255];
			sprintf(tt7, "%d 메소", Mines->_item.at(pl->getEquip().at(3).number)._price);
			TextOut(getMemDC(), myItem[3].left + 40, myItem[3].top + 21, tt7, strlen(tt7));
			char tt8[255];
			sprintf(tt8, "%s", Mines->_item.at(pl->getEquip().at(3).number).itemname);
			TextOut(getMemDC(), myItem[3].left + 40, myItem[3].top + 2, tt8, strlen(tt8));
		}

		if (pl->getEquip().size() > 4)
		{
			Mines->_item.at(pl->getEquip().at(4).number).itemimg->render(getMemDC(), myItem[4].left + 2, myItem[4].top + 2);
			char tt9[255];
			sprintf(tt9, "%d 메소", Mines->_item.at(pl->getEquip().at(4).number)._price);
			TextOut(getMemDC(), myItem[4].left + 40, myItem[4].top + 21, tt9, strlen(tt9));
			char tt10[255];
			sprintf(tt10, "%s", Mines->_item.at(pl->getEquip().at(4).number).itemname);
			TextOut(getMemDC(), myItem[4].left + 40, myItem[4].top + 2, tt10, strlen(tt10));
		}

		if (pl->getEquip().size() > 5)
		{
			Mines->_item.at(pl->getEquip().at(5).number).itemimg->render(getMemDC(), myItem[5].left + 2, myItem[5].top + 2);
			char tt11[255];
			sprintf(tt11, "%d 메소", Mines->_item.at(pl->getEquip().at(5).number)._price);
			TextOut(getMemDC(), myItem[5].left + 40, myItem[5].top + 21, tt11, strlen(tt11));
			char tt12[255];
			sprintf(tt12, "%s", Mines->_item.at(pl->getEquip().at(5).number).itemname);
			TextOut(getMemDC(), myItem[5].left + 40, myItem[5].top + 2, tt12, strlen(tt12));
		}

		if (pl->getEquip().size() > 6)
		{
			Mines->_item.at(pl->getEquip().at(6).number).itemimg->render(getMemDC(), myItem[6].left + 2, myItem[6].top + 2);
			char tt13[255];
			sprintf(tt13, "%d 메소", Mines->_item.at(pl->getEquip().at(6).number)._price);
			TextOut(getMemDC(), myItem[6].left + 40, myItem[6].top + 21, tt13, strlen(tt13));
			char tt14[255];
			sprintf(tt14, "%s", Mines->_item.at(pl->getEquip().at(6).number).itemname);
			TextOut(getMemDC(), myItem[6].left + 40, myItem[6].top + 2, tt14, strlen(tt14));
		}

		if (pl->getEquip().size() > 7)
		{
			Mines->_item.at(pl->getEquip().at(7).number).itemimg->render(getMemDC(), myItem[7].left + 2, myItem[7].top + 2);
			char tt15[255];
			sprintf(tt15, "%d 메소", Mines->_item.at(pl->getEquip().at(7).number)._price);
			TextOut(getMemDC(), myItem[7].left + 40, myItem[7].top + 21, tt15, strlen(tt15));
			char tt16[255];
			sprintf(tt16, "%s", Mines->_item.at(pl->getEquip().at(7).number).itemname);
			TextOut(getMemDC(), myItem[7].left + 40, myItem[7].top + 2, tt16, strlen(tt16));
		}

		if (pl->getEquip().size() > 8)
		{
			Mines->_item.at(pl->getEquip().at(8).number).itemimg->render(getMemDC(), myItem[8].left + 2, myItem[8].top + 2);
			char tt17[255];
			sprintf(tt17, "%d 메소", Mines->_item.at(pl->getEquip().at(8).number)._price);
			TextOut(getMemDC(), myItem[8].left + 40, myItem[8].top + 21, tt17, strlen(tt17));
			char tt18[255];
			sprintf(tt18, "%s", Mines->_item.at(pl->getEquip().at(8).number).itemname);
			TextOut(getMemDC(), myItem[8].left + 40, myItem[8].top + 2, tt18, strlen(tt18));
		}
	}

	//소비탭일경우
	else if (onShopPortionTab)
	{
		if (pl->getConsume().size() > 0)
		{
			Mines->_item.at(pl->getConsume().at(0).number).itemimg->render(getMemDC(), myItem[0].left + 2, myItem[0].top + 2);
			char tt[255];
			sprintf(tt, "%d 메소", Mines->_item.at(pl->getConsume().at(0).number)._price);
			TextOut(getMemDC(), myItem[0].left + 40, myItem[0].top + 21, tt, strlen(tt));
			char tt2[255];
			sprintf(tt2, "%s", Mines->_item.at(pl->getConsume().at(0).number).itemname);
			TextOut(getMemDC(), myItem[0].left + 40, myItem[0].top + 2, tt2, strlen(tt2));
			char st[255];
			sprintf(tt2, "%s", Mines->_item.at(pl->getConsume().at(0).number).itemname);
			TextOut(getMemDC(), myItem[0].left + 40, myItem[0].top + 2, tt2, strlen(tt2));
		}


		if (pl->getConsume().size() > 1)
		{
			Mines->_item.at(pl->getConsume().at(1).number).itemimg->render(getMemDC(), myItem[1].left + 2, myItem[1].top + 2);
			char tt3[255];
			sprintf(tt3, "%d 메소", Mines->_item.at(pl->getConsume().at(1).number)._price);
			TextOut(getMemDC(), myItem[1].left + 40, myItem[1].top + 21, tt3, strlen(tt3));
			char tt4[255];
			sprintf(tt4, "%s", Mines->_item.at(pl->getConsume().at(1).number).itemname);
			TextOut(getMemDC(), myItem[1].left + 40, myItem[1].top + 2, tt4, strlen(tt4));
		}


		if (pl->getConsume().size() > 2)
		{
			Mines->_item.at(pl->getConsume().at(2).number).itemimg->render(getMemDC(), myItem[2].left + 2, myItem[2].top + 2);
			char tt5[255];
			sprintf(tt5, "%d 메소", Mines->_item.at(pl->getConsume().at(2).number)._price);
			TextOut(getMemDC(), myItem[2].left + 40, myItem[2].top + 21, tt5, strlen(tt5));
			char tt6[255];
			sprintf(tt6, "%s", Mines->_item.at(pl->getConsume().at(2).number).itemname);
			TextOut(getMemDC(), myItem[2].left + 40, myItem[2].top + 2, tt6, strlen(tt6));
		}

		if (pl->getConsume().size() > 3)
		{
			Mines->_item.at(pl->getConsume().at(3).number).itemimg->render(getMemDC(), myItem[3].left + 2, myItem[3].top + 2);
			char tt7[255];
			sprintf(tt7, "%d 메소", Mines->_item.at(pl->getConsume().at(3).number)._price);
			TextOut(getMemDC(), myItem[3].left + 40, myItem[3].top + 21, tt7, strlen(tt7));
			char tt8[255];
			sprintf(tt8, "%s", Mines->_item.at(pl->getConsume().at(3).number).itemname);
			TextOut(getMemDC(), myItem[3].left + 40, myItem[3].top + 2, tt8, strlen(tt8));
		}

		if (pl->getConsume().size() > 4)
		{
			Mines->_item.at(pl->getConsume().at(4).number).itemimg->render(getMemDC(), myItem[4].left + 2, myItem[4].top + 2);
			char tt9[255];
			sprintf(tt9, "%d 메소", Mines->_item.at(pl->getConsume().at(4).number)._price);
			TextOut(getMemDC(), myItem[4].left + 40, myItem[4].top + 21, tt9, strlen(tt9));
			char tt10[255];
			sprintf(tt10, "%s", Mines->_item.at(pl->getConsume().at(4).number).itemname);
			TextOut(getMemDC(), myItem[4].left + 40, myItem[4].top + 2, tt10, strlen(tt10));
		}

		if (pl->getConsume().size() > 5)
		{
			Mines->_item.at(pl->getConsume().at(5).number).itemimg->render(getMemDC(), myItem[5].left + 2, myItem[5].top + 2);
			char tt11[255];
			sprintf(tt11, "%d 메소", Mines->_item.at(pl->getConsume().at(5).number)._price);
			TextOut(getMemDC(), myItem[5].left + 40, myItem[5].top + 21, tt11, strlen(tt11));
			char tt12[255];
			sprintf(tt12, "%s", Mines->_item.at(pl->getConsume().at(5).number).itemname);
			TextOut(getMemDC(), myItem[5].left + 40, myItem[5].top + 2, tt12, strlen(tt12));
		}

		if (pl->getConsume().size() > 6)
		{
			Mines->_item.at(pl->getConsume().at(6).number).itemimg->render(getMemDC(), myItem[6].left + 2, myItem[6].top + 2);
			char tt13[255];
			sprintf(tt13, "%d 메소", Mines->_item.at(pl->getConsume().at(6).number)._price);
			TextOut(getMemDC(), myItem[6].left + 40, myItem[6].top + 21, tt13, strlen(tt13));
			char tt14[255];
			sprintf(tt14, "%s", Mines->_item.at(pl->getConsume().at(6).number).itemname);
			TextOut(getMemDC(), myItem[6].left + 40, myItem[6].top + 2, tt14, strlen(tt14));
		}

		if (pl->getConsume().size() > 7)
		{
			Mines->_item.at(pl->getConsume().at(7).number).itemimg->render(getMemDC(), myItem[7].left + 2, myItem[7].top + 2);
			char tt15[255];
			sprintf(tt15, "%d 메소", Mines->_item.at(pl->getConsume().at(7).number)._price);
			TextOut(getMemDC(), myItem[7].left + 40, myItem[7].top + 21, tt15, strlen(tt15));
			char tt16[255];
			sprintf(tt16, "%s", Mines->_item.at(pl->getConsume().at(7).number).itemname);
			TextOut(getMemDC(), myItem[7].left + 40, myItem[7].top + 2, tt16, strlen(tt16));
		}

		if (pl->getConsume().size() > 8)
		{
			Mines->_item.at(pl->getConsume().at(8).number).itemimg->render(getMemDC(), myItem[8].left + 2, myItem[8].top + 2);
			char tt17[255];
			sprintf(tt17, "%d 메소", Mines->_item.at(pl->getConsume().at(8).number)._price);
			TextOut(getMemDC(), myItem[8].left + 40, myItem[8].top + 21, tt17, strlen(tt17));
			char tt18[255];
			sprintf(tt18, "%s", Mines->_item.at(pl->getConsume().at(8).number).itemname);
			TextOut(getMemDC(), myItem[8].left + 40, myItem[8].top + 2, tt18, strlen(tt18));
		}
	}
	//다썼으면 지워주자!!!
	DeleteObject(oldFont);
	DeleteObject(font1);

	//샵이 판매리스트 순서가 바뀔리 없으니까 여기에 다이렉트로 아이템정보를 뽑도록 한다.
	switch (shopList)
	{
	case 0:
		//빨간포션
		showItemInfo(0);
		break;
	case 1:
		//파란포션
		showItemInfo(4);
		break;
	case 2:
		//푸른망토
		showItemInfo(7);
		break;
	case 3:
		//낡은 고깔모자
		showItemInfo(9);
		break;
	case 4:
		//서리 증폭기
		showItemInfo(13);
		break;
	case 5:
		//천바지
		showItemInfo(15);
		break;
	case 6:
		//롱코트
		showItemInfo(19);
		break;
	case 7:
		//빽구두
		showItemInfo(21);
		break;
	case 8:
		//가죽장갑
		showItemInfo(26);
		break;
	default:
		break;

	}
}

void UserInterface::showItemInfo(int index)
{
	//정보창이 윈도우 밖으로 넘어갈때는 위로 정보창이 뜬다. y축 전체적으로 -301
	if (ptMouse.y > WINSIZEY - 300)
	{
		Sellings->iteminfo->alphaRender(getMemDC(), ptMouse.x, ptMouse.y - 301, 150);

		Sellings->_item.at(index).itemimg->render(getMemDC(), ptMouse.x + 38, ptMouse.y + 98 - 301);
		int i = 0;
		char temp[255];
		sprintf(temp, "%s", Sellings->_item.at(index).itemname);
		SetBkMode(getMemDC(), TRANSPARENT); //이거 해줘야 흰색배경 없앤다.
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), ptMouse.x + 80, ptMouse.y + 40 - 301, temp, strlen(temp));
		char temp2[255];
		sprintf(temp2, "REQ LEV : %d", Sellings->_item.at(index).reqLev);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 75 - 301, temp2, strlen(temp2));
		char temp3[255];
		sprintf(temp3, "REQ STR : %d", Sellings->_item.at(index).reqStr);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 90 - 301, temp3, strlen(temp3));
		char temp4[255];
		sprintf(temp4, "REQ DEX : %d", Sellings->_item.at(index).reqDex);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 105 - 301, temp4, strlen(temp4));
		char temp5[255];
		sprintf(temp5, "REQ INT : %d", Sellings->_item.at(index).reqInt);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 120 - 301, temp5, strlen(temp5));
		char temp6[255];
		sprintf(temp6, "REQ LUK : %d", Sellings->_item.at(index).reqLuk);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 135 - 301, temp6, strlen(temp6));

		char temp7[255];
		if (Sellings->_item.at(index).itemtype == 1)
			sprintf(temp7, "기타아이템");
		else if (Sellings->_item.at(index).itemtype == 2)
			sprintf(temp7, "소비아이템");
		else if (Sellings->_item.at(index).itemtype == 3)
			sprintf(temp7, "장비분류 : 무기");
		else if (Sellings->_item.at(index).itemtype == 4)
			sprintf(temp7, "장비분류 : 모자");
		else if (Sellings->_item.at(index).itemtype == 5)
			sprintf(temp7, "장비분류 : 귀고리");
		else if (Sellings->_item.at(index).itemtype == 6)
			sprintf(temp7, "장비분류 : 상의");
		else if (Sellings->_item.at(index).itemtype == 7)
			sprintf(temp7, "장비분류 : 하의");
		else if (Sellings->_item.at(index).itemtype == 8)
			sprintf(temp7, "장비분류 : 장갑");
		else if (Sellings->_item.at(index).itemtype == 9)
			sprintf(temp7, "장비분류 : 신발");
		else if (Sellings->_item.at(index).itemtype == 10)
			sprintf(temp7, "장비분류 : 망토");

		TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 160 - 301, temp7, strlen(temp7));
		if (Sellings->_item.at(index).hp > 0)
		{
			char temp8[255];
			sprintf(temp8, "HP : + %d", Sellings->_item.at(index).hp);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp8, strlen(temp8));
			i++;
		}

		if (Sellings->_item.at(index).mp > 0)
		{
			char temp9[255];
			sprintf(temp9, "MP : + %d", Sellings->_item.at(index).mp);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp9, strlen(temp9));
			i++;
		}

		if (Sellings->_item.at(index).str > 0)
		{
			char temp10[255];
			sprintf(temp10, "STR : + %d", Sellings->_item.at(index).str);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp10, strlen(temp10));
			i++;
		}

		if (Sellings->_item.at(index).dex > 0)
		{
			char temp11[255];
			sprintf(temp11, "DEX : + %d", Sellings->_item.at(index).dex);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp11, strlen(temp11));
			i++;
		}

		if (Sellings->_item.at(index).inteligence > 0)
		{
			char temp12[255];
			sprintf(temp12, "INT : + %d", Sellings->_item.at(index).inteligence);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp12, strlen(temp12));
			i++;
		}

		if (Sellings->_item.at(index).luk > 0)
		{
			char temp13[255];
			sprintf(temp13, "LUK : + %d", Sellings->_item.at(index).luk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp13, strlen(temp13));
			i++;
		}

		if (Sellings->_item.at(index).phyatk > 0)
		{
			char temp14[255];
			sprintf(temp14, "물리공격력 : + %d", Sellings->_item.at(index).phyatk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp14, strlen(temp14));
			i++;
		}

		if (Sellings->_item.at(index).phyarm > 0)
		{
			char temp15[255];
			sprintf(temp15, "물리방어력 : + %d", Sellings->_item.at(index).phyarm);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp15, strlen(temp15));
			i++;
		}

		if (Sellings->_item.at(index).magatk > 0)
		{
			char temp16[255];
			sprintf(temp16, "마법공격력 : + %d", Sellings->_item.at(index).magatk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp16, strlen(temp16));
			i++;
		}

		if (Sellings->_item.at(index).magarm > 0)
		{
			char temp17[255];
			sprintf(temp17, "마법방어력 : + %d", Sellings->_item.at(index).magarm);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp17, strlen(temp17));
			i++;
		}

		if (Sellings->_item.at(index).hitrate > 0)
		{
			char temp18[255];
			sprintf(temp18, "명중률 : + %d", Sellings->_item.at(index).hitrate);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp18, strlen(temp18));
			i++;
		}

		if (Sellings->_item.at(index).avoidrate > 0)
		{
			char temp19[255];
			sprintf(temp19, "회피율 : + %d", Sellings->_item.at(index).avoidrate);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp19, strlen(temp19));
			i++;
		}

		/*

		<영역 출력!!!>

		- RECT rcTextArea = {200, 200, 300, 300};
		-> RECT로 영역 범위 설정

		- DrawText(hdc, szTemp, strlen(szTemp), &rcTextArea, DT_SINGLELINE | DT_VCENTER);
		-> (핸들, 문자열, 문자열의 길이, 영역크기, 드로우텍스트_출력스타일);
		-> 해당 영역안에 글자를 스타일에 따라 출력해준다. or(|)연산으로 중복된 스타일을 쓸 수 있다.

		// 자주 쓰는 스타일//
		DT_LEFT		좌측정렬
		DT_CENTER	중앙 정렬
		DT_WORDBREAK	영역 넘어갈시 단어 단위로 줄바꿈
		DT_SINGLELINE	한줄 사용. 영역 넘어갈시 짤린다.
		DT_NOCLIP	영역무시 출력
		DT_VCENTER	수직 정중앙에 맞춰라. (DT_SINGLELINE랑 같이 써야된다.)


		*/

		char temp20[255];
		sprintf(temp20, "%s", Sellings->_item.at(index).script);
		RECT rcTextArea = { ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301 ,ptMouse.x + 230,  ptMouse.y + 175 + i * 15 + 45 - 301 };
		DrawText(getMemDC(), temp20, -1, &rcTextArea, DT_LEFT | DT_WORDBREAK);
		//문자열 길이부분에 -1 => 자동으로 계산.
		i += 3; //글자상자때문에 세줄을 할당하는 바람에 여기서는 +3!!


				//업그레이드 가능횟수는 장비아이템인 경우에만 출력한다.
		if (!(Sellings->_item.at(index).itemtype == 0) && !(Sellings->_item.at(index).itemtype == 1) && !(Sellings->_item.at(index).itemtype == 2))
		{
			char temp21[255];
			sprintf(temp21, "업그레이드 가능횟수 : %d회", Sellings->_item.at(index).upgrade);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15 - 301, temp21, strlen(temp21));
		}
	}
	else
	{
		Sellings->iteminfo->alphaRender(getMemDC(), ptMouse.x, ptMouse.y, 150);

		Sellings->_item.at(index).itemimg->render(getMemDC(), ptMouse.x + 38, ptMouse.y + 98);
		int i = 0;
		char temp[255];
		sprintf(temp, "%s", Sellings->_item.at(index).itemname);
		SetBkMode(getMemDC(), TRANSPARENT); //이거 해줘야 흰색배경 없앤다.
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), ptMouse.x + 80, ptMouse.y + 40, temp, strlen(temp));
		char temp2[255];
		sprintf(temp2, "REQ LEV : %d", Sellings->_item.at(index).reqLev);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 75, temp2, strlen(temp2));
		char temp3[255];
		sprintf(temp3, "REQ STR : %d", Sellings->_item.at(index).reqStr);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 90, temp3, strlen(temp3));
		char temp4[255];
		sprintf(temp4, "REQ DEX : %d", Sellings->_item.at(index).reqDex);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 105, temp4, strlen(temp4));
		char temp5[255];
		sprintf(temp5, "REQ INT : %d", Sellings->_item.at(index).reqInt);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 120, temp5, strlen(temp5));
		char temp6[255];
		sprintf(temp6, "REQ LUK : %d", Sellings->_item.at(index).reqLuk);
		TextOut(getMemDC(), ptMouse.x + 110, ptMouse.y + 135, temp6, strlen(temp6));

		char temp7[255];
		if (Sellings->_item.at(index).itemtype == 1)
			sprintf(temp7, "기타아이템");
		else if (Sellings->_item.at(index).itemtype == 2)
			sprintf(temp7, "소비아이템");
		else if (Sellings->_item.at(index).itemtype == 3)
			sprintf(temp7, "장비분류 : 무기");
		else if (Sellings->_item.at(index).itemtype == 4)
			sprintf(temp7, "장비분류 : 모자");
		else if (Sellings->_item.at(index).itemtype == 5)
			sprintf(temp7, "장비분류 : 귀고리");
		else if (Sellings->_item.at(index).itemtype == 6)
			sprintf(temp7, "장비분류 : 상의");
		else if (Sellings->_item.at(index).itemtype == 7)
			sprintf(temp7, "장비분류 : 하의");
		else if (Sellings->_item.at(index).itemtype == 8)
			sprintf(temp7, "장비분류 : 장갑");
		else if (Sellings->_item.at(index).itemtype == 9)
			sprintf(temp7, "장비분류 : 신발");
		else if (Sellings->_item.at(index).itemtype == 10)
			sprintf(temp7, "장비분류 : 망토");

		TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 160, temp7, strlen(temp7));
		if (Sellings->_item.at(index).hp > 0)
		{
			char temp8[255];
			sprintf(temp8, "HP : + %d", Sellings->_item.at(index).hp);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp8, strlen(temp8));
			i++;
		}

		if (Sellings->_item.at(index).mp > 0)
		{
			char temp9[255];
			sprintf(temp9, "MP : + %d", Sellings->_item.at(index).mp);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp9, strlen(temp9));
			i++;
		}

		if (Sellings->_item.at(index).str > 0)
		{
			char temp10[255];
			sprintf(temp10, "STR : + %d", Sellings->_item.at(index).str);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp10, strlen(temp10));
			i++;
		}

		if (Sellings->_item.at(index).dex > 0)
		{
			char temp11[255];
			sprintf(temp11, "DEX : + %d", Sellings->_item.at(index).dex);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp11, strlen(temp11));
			i++;
		}

		if (Sellings->_item.at(index).inteligence > 0)
		{
			char temp12[255];
			sprintf(temp12, "INT : + %d", Sellings->_item.at(index).inteligence);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp12, strlen(temp12));
			i++;
		}

		if (Sellings->_item.at(index).luk > 0)
		{
			char temp13[255];
			sprintf(temp13, "LUK : + %d", Sellings->_item.at(index).luk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp13, strlen(temp13));
			i++;
		}

		if (Sellings->_item.at(index).phyatk > 0)
		{
			char temp14[255];
			sprintf(temp14, "물리공격력 : + %d", Sellings->_item.at(index).phyatk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp14, strlen(temp14));
			i++;
		}

		if (Sellings->_item.at(index).phyarm > 0)
		{
			char temp15[255];
			sprintf(temp15, "물리방어력 : + %d", Sellings->_item.at(index).phyarm);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp15, strlen(temp15));
			i++;
		}

		if (Sellings->_item.at(index).magatk > 0)
		{
			char temp16[255];
			sprintf(temp16, "마법공격력 : + %d", Sellings->_item.at(index).magatk);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp16, strlen(temp16));
			i++;
		}

		if (Sellings->_item.at(index).magarm > 0)
		{
			char temp17[255];
			sprintf(temp17, "마법방어력 : + %d", Sellings->_item.at(index).magarm);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp17, strlen(temp17));
			i++;
		}

		if (Sellings->_item.at(index).hitrate > 0)
		{
			char temp18[255];
			sprintf(temp18, "명중률 : + %d", Sellings->_item.at(index).hitrate);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp18, strlen(temp18));
			i++;
		}

		if (Sellings->_item.at(index).avoidrate > 0)
		{
			char temp19[255];
			sprintf(temp19, "회피율 : + %d", Sellings->_item.at(index).avoidrate);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp19, strlen(temp19));
			i++;
		}

		/*

		<영역 출력!!!>

		- RECT rcTextArea = {200, 200, 300, 300};
		   -> RECT로 영역 범위 설정

		 - DrawText(hdc, szTemp, strlen(szTemp), &rcTextArea, DT_SINGLELINE | DT_VCENTER);
			-> (핸들, 문자열, 문자열의 길이, 영역크기, 드로우텍스트_출력스타일);
			-> 해당 영역안에 글자를 스타일에 따라 출력해준다. or(|)연산으로 중복된 스타일을 쓸 수 있다.

		// 자주 쓰는 스타일//
		DT_LEFT		좌측정렬
		DT_CENTER	중앙 정렬
		DT_WORDBREAK	영역 넘어갈시 단어 단위로 줄바꿈
		DT_SINGLELINE	한줄 사용. 영역 넘어갈시 짤린다.
		DT_NOCLIP	영역무시 출력
		DT_VCENTER	수직 정중앙에 맞춰라. (DT_SINGLELINE랑 같이 써야된다.)


		*/

		char temp20[255];
		sprintf(temp20, "%s", Sellings->_item.at(index).script);
		RECT rcTextArea = { ptMouse.x + 10, ptMouse.y + 175 + i * 15,ptMouse.x + 230,  ptMouse.y + 175 + i * 15 + 45 };
		DrawText(getMemDC(), temp20, -1, &rcTextArea, DT_LEFT | DT_WORDBREAK);
		//문자열 길이부분에 -1 => 자동으로 계산.
		i += 3; //글자상자때문에 세줄을 할당하는 바람에 여기서는 +3!!


		//업그레이드 가능횟수는 장비아이템인 경우에만 출력한다.
		if (!(Sellings->_item.at(index).itemtype == 0) && !(Sellings->_item.at(index).itemtype == 1) && !(Sellings->_item.at(index).itemtype == 2))
		{
			char temp21[255];
			sprintf(temp21, "업그레이드 가능횟수 : %d회", Sellings->_item.at(index).upgrade);
			TextOut(getMemDC(), ptMouse.x + 10, ptMouse.y + 175 + i * 15, temp21, strlen(temp21));
		}
	}
}

UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}

