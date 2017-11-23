#include "stdafx.h"
#include "inventory.h"


void inventory::init(int showposx)
{
}

void inventory::update()
{
	if (!KEYMANAGER->isStayKeyDown(VK_LBUTTON)) {
		onDrag = false;
	}

	for (int i = 0; i < Items.size(); i++) {
		if (PtInRect(&itemRects[i].spot, ptMouse)) {
			tooltipShow = true;
			tooltipPos.x = ptMouse.x;
			tooltipPos.y = ptMouse.y;
			tooltipIndex = i;
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && !onDrag) {
				onDrag = true;
				dragIndex = i;
			}
			break;
		}
		else {
			tooltipShow = false;
		}
	}
}

void inventory::render()//아이템 정보 출력도 해줘야함(툴팁)
{
	show();
}

void inventory::addItem(item it)
{
	for (vector<item>::iterator i = Items.begin(); i != Items.end(); i++) {
		if (i->itemName == it.itemName && i->type == itemType::potion) {
			i->stack++;
			return;
		}
	}
	Items.push_back(it);
	return;
}


bool inventory::useItem(int index)
{
	if (Items[index].type == itemType::potion) {
		Items[index].stack--;
		//if (Items[index].stack <= 0) {
		//	Items.erase(Items.begin + index);
		//	return true;
		//}
	}
	else if (Items[index].type == itemType::weapons || Items[index].type == itemType::accessory || Items[index].type == itemType::armors || Items[index].type == itemType::shield) {
		Items[index].equipped = !Items[index].equipped;
		return true;
	}
	else {
		return false;
	}
}

void inventory::show()
{
	//Rectangle(getMemDC(), inventoryFrame.left, inventoryFrame.top, inventoryFrame.right, inventoryFrame.bottom);
	invFrame->alphaRender(getMemDC(), x, y, 0xE0);
	//int count;
	//for (int i = 0; i < 7; i++) {
	//	for (int j = 0; j < 10; j++) {
	//		RectangleMake(getMemDC(), x + 50 * i + 50, y + 50 * j + 50, 48, 48);//여기에 아이템들 그려주면 됨.
	//	}
	//}
	for (int i = 0; i < 70; i++) {
		Rectangle(getMemDC(), itemRects[i].spot.left, itemRects[i].spot.top, itemRects[i].spot.right, itemRects[i].spot.bottom);
		if (i < Items.size()) {
			if (i == dragIndex&&onDrag)continue;
			Items[i].smImage->frameRender(getMemDC(), x + 50 * (i % 7) + 50, y + 50 * (i / 7) + 100, Items[i].itemIndexX, Items[i].itemIndexY);

		}
	}
}
item inventory::getItemOnPoint(POINT pt, bool del)
{
	for (int i = 0; i < Items.size(); i++) {
		if (PtInRect(&itemRects[i].spot, pt)) {
			item tmp = Items[i];
			if (del) {
				Items.erase(Items.begin() + i);
			}
			return tmp;
		}
	}
	return item();
}
int inventory::getIndexOnPoint(POINT pt)
{
	for (int i = 0; i < Items.size(); i++) {
		if (PtInRect(&itemRects[i].spot, pt)) {
			return i;
		}
	}
	return -1;
}
inventory::inventory()
{
}


inventory::~inventory()
{
}
