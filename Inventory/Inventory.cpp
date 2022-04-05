#include "Inventory.h"
#include "InventoryException.h"
#include <utility>

Inventory::Inventory(int itemNum) : mItemNum(itemNum)
{
	mItems = new Item[itemNum];
}

Inventory::Inventory(const Inventory& copy)
{
	operator=(copy);
}

Inventory& Inventory::operator=(const Inventory& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	if (this->mItems)
	{
		delete[] mItems;
	}

	mItems = new Item[rhs.mItemNum];
	mItemNum = rhs.mItemNum;

	for (int i = 0; i < mItemNum; i++)
	{
		mItems[i] = rhs.mItems[i];
	}

	return *this;
}
Item& Inventory::operator[](const int index)
{
	if (index < 0 || index >= mItemNum)
	{
		throw InventoryOutOfRangeException(index);
	}

	return mItems[index];
}

Inventory::~Inventory()
{
	delete[] mItems;
}

void Inventory::AddItem(int index, int itemID)
{
	if (index < 0 || index >= mItemNum)
	{
		throw InventoryOutOfRangeException(index);
	}
	if (mItems[index].id != -999)
	{
		throw InventoryAreadyFilledItemException(index);
	}
	mItems[index].id = itemID;
}

void Inventory::RemoveItem(int index)
{
	if (index < 0 || index >= mItemNum)
	{
		throw InventoryOutOfRangeException(index);
	}
	if (mItems[index].id == -999)
	{
		throw InventoryInvalidItemIndexException(index);
	}

	mItems[index].id = -999;
}

void Inventory::SwapItem(int target1, int target2)
{
	if ((target1 < 0 || target1 >= mItemNum))
	{
		throw InventoryOutOfRangeException(target1);
	}
	if ((target2 < 0 || target2 >= mItemNum))
	{
		throw InventoryOutOfRangeException(target2);
	}
	if (mItems[target1].id == -999)
	{
		throw InventoryInvalidItemIndexException(target1);
	}
	if (mItems[target2].id == -999)
	{
		throw InventoryInvalidItemIndexException(target2);
	}
	
	std::swap(mItems[target1], mItems[target2]);
	
	//int temp = mItems[target1].id;
	//mItems[target1].id = mItems[target2].id;
	//mItems[target2].id = temp;
}