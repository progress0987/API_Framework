#pragma once

//������ ���� Ŭ����!!!!!
//�ۺ����� ��� ���ٰ����ϰ� ��������ϴ�.

/*������ ���Ƕ�, if�����Ἥ ���������ΰ��, �Һ������(potion)�ΰ��, ��Ÿ���ΰ��(etc)�� �����ؼ� ����ϼ���.*/
enum itemType {
	empty, //������x
	etc, //����
	potion, //����
	weapons, //����
	helm, //���
	earacc, //�Ͱ�
	clothes, //����
	pants, //����
	gloves, //�尩
	boots, //����
	cape//����
};
enum rarity {
	common,
	uncommon,
	magic,
	rare,
	unique,
	legandary,
	epic,
};

//������ �Ӽ� ����.
//���� �ʱ�ȭ�� ����!!!!

struct item {
	//������ �̹���.
	image *itemimg;

	//������ �̸�
	char itemname[200];

	//������ ����
	int itemtype = -1;

	//������ ����
	int _price = 0;


	//������ �����Ǵ� ü��, ����, ��, ��ø, ����, ���
	int hp = 0, mp = 0, str = 0, dex = 0, inteligence = 0, luk = 0;


	//�������ݷ�, �������, ��������, �������, ���߷�, ȸ�Ƿ�, ���׷��̵尡��.
	int phyatk = 0, phyarm = 0, magatk = 0, magarm = 0, hitrate = 0, avoidrate = 0, upgrade = 0;

	//�ʿ� ����
	int reqLev = 0, reqStr = 0, reqDex = 0, reqInt = 0, reqLuk = 0;

	//-----------�Ʒ��� �Һ������, ���ۿ��� �ش��Ѵ�.(������ ���� ��������)---------------

	//ȸ�������ִ� hp, mp
	int healHp = 0, healMp = 0;

	//����
	char script[500];
};

class items
{
public:

	image *iteminfo;
	item t;
	vector<item> _item;

	HRESULT init(void);

	items();
	~items();
};

