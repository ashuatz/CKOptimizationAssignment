#include "Inventory.h"

// 프로그래머라면 인덱스는 0부터 감지 않을까?

void Inventory::AddItem(int index, int itemID) {
	if (index < 0 || index >= _ItemNum)	throw IE_OutOfRange(index);
	if (_ItemList[index]._id != NONE)	throw IE_AreadyFilledItem(index);
	if (itemID & 0x80000000)			throw IE_InvalidItemIndex(itemID);

	_ItemList[index]._id = itemID;
}
void Inventory::RemoveItem(int index) {
	if (index < 0 || index >= _ItemNum)	throw IE_OutOfRange(index);

	_ItemList[index]._id = NONE;
}
void Inventory::SwapItem(int lhsindex, int rhsindex) {
	if (lhsindex < 0 || lhsindex >= _ItemNum)	throw IE_OutOfRange(lhsindex);
	if (rhsindex < 0 || rhsindex >= _ItemNum)	throw IE_OutOfRange(rhsindex);

	Item temp = _ItemList[lhsindex];
	_ItemList[lhsindex] = _ItemList[rhsindex];
	_ItemList[lhsindex] = temp;
}
