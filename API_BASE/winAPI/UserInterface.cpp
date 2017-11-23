#include "stdafx.h"
#include "UserInterface.h"


HRESULT UserInterface::init(void)
{
	//------------------------------------����-----------------------------------------------
	IMAGEMANAGER->addImage("�ݱ�", "�ݱ�.bmp", 13, 13, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("�ݱ⸶�콺��", "�ݱ�(MouseOn).bmp", 13, 13, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("�ݱ�Ŭ��", "�ݱ�(clicked).bmp", 13, 13, true, RGB(0, 0, 0));

	//-------------------------------------�κ��丮------------------------------------------
	IMAGEMANAGER->addImage("�κ��丮â", "�������κ��丮.bmp", 172, 335, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����", "�����.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Һ���", "�Һ���.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ÿ��", "��Ÿ��.bmp", 30, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�׸���", "shadow.bmp", 26, 6, true, RGB(255, 255, 255));
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



	//-----------------------------------���â-----------------------------------------------
	IMAGEMANAGER->addImage("���â", "����κ��丮.bmp", 232, 330, true, RGB(255, 0, 255));

	//-------------------------------------����â--------------------------------------------

	IMAGEMANAGER->addImage("����â", "����â.bmp", 212, 318, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "��.bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����콺��", "��(MouseOn).bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ŭ��", "��(clicked).bmp", 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ڵ���й�ưȰ��ȭ", "�ڵ���й�ưȰ��ȭ.bmp", 67, 34, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ڵ���й�ư����", "�ڵ���й�ư����.bmp", 67, 34, true, RGB(255, 0, 255));

	//------------------------------------�������̽�-----------------------------------------

	//ü��, ���̵�, ���� �簢��
	IMAGEMANAGER->addImage("�������׵θ�", "�������׵θ�(��Ʈ).bmp", 204, 70, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("����", "������(��Ʈ).bmp", 171, 13, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ü��", "ü�¹�(��Ʈ).bmp", 171, 13, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Lv", "Lv.bmp", 15, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������0", "��������0.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������1", "��������1.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������2", "��������2.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������3", "��������3.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������4", "��������4.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������5", "��������5.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������6", "��������6.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������7", "��������7.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������8", "��������8.bmp", 7, 10, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��������9", "��������9.bmp", 7, 10, true, RGB(255, 255, 255));

	//����ġ��
	IMAGEMANAGER->addImage("����ġ0", "����ġ(0)��Ʈ.bmp", 1366, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����ġ2", "����ġ(2)��Ʈ.bmp", 1350, 7, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����ġ3", "����ġ(3)��Ʈ.bmp", 1082, 7, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("����ġ4", "����ġ����Ʈ(3)��Ʈ.bmp", 13, 17, true, RGB(255, 0, 255));

	//������
	IMAGEMANAGER->addImage("������0", "������(0).bmp", 350, 67, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("�����Կ����׵θ�", "�����Կ����׵θ�.bmp", 13, 71, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ŀ��", "������Ŀ��.bmp", 351, 73, true, RGB(255, 255, 255));

	//�����Դ���Ű
	IMAGEMANAGER->addImage("��1", "��1.bmp", 7, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��2", "��2.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��3", "��3.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��4", "��4.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��5", "��5.bmp", 10, 9, true, RGB(255, 255, 255));
	IMAGEMANAGER->addImage("��6", "��6.bmp", 10, 9, true, RGB(255, 255, 255));


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
