#pragma once
#include "gameNode.h"
#include <string>
#include <vector>

enum itemType {
	empty,
	general,
	weapons,
	helm,
	armors,
	pants,
	gloves,
	boots,
	shield,
	potion,
	accessory,
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
struct item {
	int type = -1;//enum itemType, -1�� ����
	char* itemName;
	int stack; // only for potion

	int dmg = 0;//���϶��� ü��ȸ��
	int def = 0;//���� ǥ����
	int mr = 0;//���� ǥ����

	float maxDuration = 1.0f;//�ִ볻����(-1 -> ������ ������)
	float curDuration = 1.0f;//���系����

	int intelligent = 0;
	int dexterity = 0;
	int strength = 0;
	int luck = 0;

	int price;

	bool equipped = false;

	char* description;
	int itemIndexX, itemIndexY;
	image* smImage;		//�κ��丮������ ����
	image* lgImage;		//������� ����
	//�׽�Ʈ��
	int smSize;			//��(���簢���̶�� ����)
	int lgSize;
	void printItemInfo(image* info, int x, int y);
};

struct nodes {
	RECT spot;
	int x, y;
	int size;
};
class inventory :public gameNode
{
private:
	int x, y;										//�κ��丮 ǥ�� �»�� ��ǥ
	vector<item> Items;								//�����۵��� ������
	vector<nodes> itemRects;						//������ ��Ʈ��
	RECT inventoryFrame;							//�κ��丮 ��Ʈ
	image* invFrame;								//�κ� �׸�����
	POINT tooltipPos;
	bool tooltipShow;
	int tooltipIndex;

	int dragIndex = -1;
	bool onDrag = false;

public:
	void init(int showposx);
	void update();
	void render();
	void addItem(item);
	bool useItem(int index);
	void show();
	vector<item> getItems() { return Items; }
	item getItemOnPoint(POINT pt, bool del);
	//item& getItemOnIndex(int index) { return Items[index]; }
	int getIndexOnPoint(POINT pt);
	RECT getInvRC() { return inventoryFrame; }
	item* equip(int i) { Items[i].equipped = true; return &Items[i]; }
	void unequip(int i) { Items[i].equipped = false; }
	inventory();
	~inventory();
};

