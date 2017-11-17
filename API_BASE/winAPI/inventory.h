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
	int type = -1;//enum itemType, -1은 에러
	char* itemName;
	int stack; // only for potion

	int dmg = 0;//힐일때는 체력회복
	int def = 0;//물방 표현용
	int mr = 0;//마방 표현용

	float maxDuration = 1.0f;//최대내구도(-1 -> 내구도 무제한)
	float curDuration = 1.0f;//현재내구도

	int intelligent = 0;
	int dexterity = 0;
	int strength = 0;
	int luck = 0;

	int price;

	bool equipped = false;

	char* description;
	int itemIndexX, itemIndexY;
	image* smImage;		//인벤토리에서의 형태
	image* lgImage;		//착용시의 형태
	//테스트용
	int smSize;			//폭(정사각형이라는 가정)
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
	int x, y;										//인벤토리 표현 좌상단 좌표
	vector<item> Items;								//아이템들의 정보들
	vector<nodes> itemRects;						//아이템 렉트들
	RECT inventoryFrame;							//인벤토리 렉트
	image* invFrame;								//인벤 그림정보
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

