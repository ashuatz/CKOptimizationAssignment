#include "Inventory.h"

// 프로그래머라면 인덱스는 0부터 감지 않을까?

void Inventory::AddItem(Item item) {
	if (item._id & 0x80000000) throw IE_InvalidItemID(item._id);

	_ItemList->push_back(item);
}
void Inventory::RemoveItem(int index) {
	if (index < 0 || index >= _ItemList->size())	throw IE_OutOfRange(index);

	_ItemList->at(index)._id = NONE;
}
void Inventory::SwapItem(int lhsindex, int rhsindex) {
	if (lhsindex < 0 || lhsindex >= _ItemList->size())	throw IE_OutOfRange(lhsindex);
	if (rhsindex < 0 || rhsindex >= _ItemList->size())	throw IE_OutOfRange(rhsindex);

	Item temp = _ItemList->at(lhsindex);
	_ItemList->at(lhsindex) = _ItemList->at(rhsindex);
	_ItemList->at(rhsindex) = temp;
}