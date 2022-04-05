#include "Inventory.h"

void Inventory::AddItem(EItemType itemType)
{
	mItemList.push_back(Item(itemType));
}

void Inventory::RemoveItem(int index)
{
	// Check it's valid index
	if (index < 0 || index >= mItemList.size())
	{
		throw OutOfRangeException(index);
	}

	mItemList.erase(mItemList.begin() + index);
}

void Inventory::SwapItem(int lhsindex, int rhsindex)
{
	// Check it's valid index
	if (lhsindex < 0 || lhsindex >= mItemList.size() || rhsindex < 0 || rhsindex >= mItemList.size())
	{
		throw OutOfRangeException(lhsindex);
	}

	// Swap value
	auto temp = mItemList[lhsindex];
	mItemList[lhsindex] = mItemList[rhsindex];
	mItemList[rhsindex] = temp;
}

void Inventory::Print()
{
	int itemCount = 0;

	for (auto i : mItemList)
	{
		i.Print(itemCount);
		itemCount++;
	}
}
