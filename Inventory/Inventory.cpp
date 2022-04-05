#include "Inventory.h"

Inventory::Inventory(int capacity)
{
	// Initialize all property
	mCapacity = capacity;
	mItemCount = 0;

	// Allocate item list
	mItemList = new(std::nothrow) Item[mCapacity];
}

Inventory::Inventory(const Inventory& copy)
{
	// Check it's same object itself
	if (this == &copy)
	{
		return;
	}

	// Release memory
	if (mItemList)
	{
		delete[] mItemList;
	}

	// Copy all elements in array
	mItemCount = copy.mItemCount;
	mItemList = new(std::nothrow) Item[mItemCount];

	for (int i = 0; i < mItemCount; i++)
	{
		mItemList[i] = copy.mItemList[i];
	}
}

Inventory::Inventory(const std::initializer_list<Item> itemList)
{
	mItemCount = itemList.size();
	mItemList = new(std::nothrow) Item[mItemCount * 2];

	int currentItemIndex = 0;

	for (auto item : itemList)
	{
		mItemList[currentItemIndex] = item;

		currentItemIndex++;
	}
}

void Inventory::Resize(int capacity)
{
	// Check it's valid capacity
	if (mCapacity >= capacity)
	{
		return;
	}

	// Reallocate list
	mCapacity = capacity;
	Item* newItemList = new Item[mCapacity];

	// Copy previous values
	for (int i = 0; i < mItemCount; i++)
	{
		newItemList[i] = mItemList[mItemCount];
	}

	// Free memory
	delete[] mItemList;
	mItemList = newItemList;
}

void Inventory::AddItem(EItemType itemType)
{
	// Check it's valid item type
	if (itemType == EItemType::None)
	{
		throw InvalidItemTypeException();
	}

	// Check it's full
	if (mItemCount == mCapacity)
	{
		throw InventoryIsFullException();
	}

	// Assign item
	mItemList[mItemCount].Type = itemType;
	
	// Increase item count
	mItemCount++;
}

void Inventory::RemoveItem(int index)
{
	// Check it's valid index
	if (index < 0 || index >= mItemCount)
	{
		throw OutOfRangeException(index);
	}

	// Remove item, Shift all items forward by 1
	for (int i = index; i < mItemCount - 1; i++)
	{
		mItemList[i] = mItemList[i + 1];
	}

	// Discount item count
	mItemCount--;
}

void Inventory::SwapItem(int lhsindex, int rhsindex)
{
	// Check it's valid index
	if (lhsindex < 0 || lhsindex >= mItemCount || rhsindex < 0 || rhsindex >= mItemCount)
	{
		throw OutOfRangeException(lhsindex);
	}

	// Swap value
	Item temp = mItemList[lhsindex];
	mItemList[lhsindex] = mItemList[rhsindex];
	mItemList[rhsindex] = temp;
}

void Inventory::Print()
{
	for (int i = 0; i < mItemCount; i++)
	{
		mItemList[i].Print(i);
	}
}
