#include "stdafx.h"
#include "UserInterface.h"


HRESULT UserInterface::init(void)
{
	//------------------------------------공용-----------------------------------------------
	IMAGEMANAGER->addImage("닫기", "닫기.bmp", 13, 13, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("닫기마우스온", "닫기(MouseOn).bmp", 13, 13, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("닫기클릭", "닫기(clicked).bmp", 13, 13, true, RGB(0, 0, 0));

	//-------------------------------------인벤토리------------------------------------------
	IMAGEMANAGER->addImage("인벤토리창", "아이템인벤토리.bmp", 172, 335, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("장비탭", "장비탭.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("소비탭", "소비탭.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("기타탭", "기타탭.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("그림자", "shadow.bmp", 26, 6, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("0", "0.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("1", "1.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("2", "2.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("3", "3.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("4", "4.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("5", "5.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("6", "6.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("7", "7.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("8", "8.bmp", 8, 11, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("9", "9.bmp", 8, 11, true, RGB(0, 0, 0));



	//-----------------------------------장비창-----------------------------------------------
	IMAGEMANAGER->addImage("장비창", "장비인벤토리.bmp", 232, 330, true, RGB(255, 0, 255));

	//-------------------------------------스텟창--------------------------------------------

	IMAGEMANAGER->addImage("스텟창", "스텟창.bmp", 212, 318, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("업", "업.bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("업마우스온", "업(MouseOn).bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("업클릭", "업(clicked).bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("자동배분버튼활성화", "자동배분버튼활성화.bmp", 67, 34, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("자동배분버튼눌림", "자동배분버튼눌림.bmp", 67, 34, true, RGB(255, 0, 255));

	//------------------------------------인터페이스-----------------------------------------

	//체력, 아이디, 레벨 사각형
	IMAGEMANAGER->addImage("게이지테두리", "게이지테두리(비트).bmp", 204, 70, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("마나", "마나바(비트).bmp", 171, 13, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("체력", "체력바(비트).bmp", 171, 13, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Lv", "Lv.bmp", 15, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자0", "레벨숫자0.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자1", "레벨숫자1.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자2", "레벨숫자2.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자3", "레벨숫자3.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자4", "레벨숫자4.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자5", "레벨숫자5.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자6", "레벨숫자6.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자7", "레벨숫자7.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자8", "레벨숫자8.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("레벨숫자9", "레벨숫자9.bmp", 7, 10, true, RGB(255, 255, 255));

	//경험치바
	IMAGEMANAGER->addImage("경험치0", "경험치(0)비트.bmp", 1366, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("경험치2", "경험치(2)비트.bmp", 1350, 7, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("경험치3", "경험치(3)비트.bmp", 1082, 7, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("경험치4", "경험치이펙트(3)비트.bmp", 13, 17, true, RGB(255, 0, 255));

	//퀵슬롯
	IMAGEMANAGER->addImage("퀵슬롯0", "퀵슬롯(0).bmp", 350, 67, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵슬롯왼쪽테두리", "퀵슬롯왼쪽테두리.bmp", 13, 71, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("퀵슬롯커버", "퀵슬롯커버.bmp", 351, 73, true, RGB(255, 255, 255));

	//퀵슬롯단축키
	IMAGEMANAGER->addImage("퀵1", "퀵1.bmp", 7, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵2", "퀵2.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵3", "퀵3.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵4", "퀵4.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵5", "퀵5.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("퀵6", "퀵6.bmp", 10, 9, true, RGB(255, 255, 255));


	IMAGEMANAGER->addImage("pgup", "pgup.bmp", 22, 11, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("pgdn", "pgdn.bmp", 22, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("inst", "insert.bmp", 18, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("hm", "hm.bmp", 19, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("end", "end.bmp", 22, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("del", "delete.bmp", 19, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("ctrl", "ctrl.bmp", 23, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("shift", "Shift.bmp", 28, 9, true, RGB(255, 255, 255));


	IMAGEMANAGER->addImage("Q", "Q.bmp", 10, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("W", "W.bmp", 12, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("E", "E.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("R", "R.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("T", "T.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("A", "A.bmp", 10, 9, true, RGB(255, 255, 255));

	return S_OK;
}

void UserInterface::release(void)
{
}

void UserInterface::update(void)
{


}

void UserInterface::render(void)
{
}

UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
