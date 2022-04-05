#pragma once

#include <initializer_list>

#include "InventoryException.h"
#include "Item.h"

class Inventory
{
public:
	// Destructor
	~Inventory() { delete[] mItemList; }

	// Constructor
	Inventory() = default;
	Inventory(int capacity);
	Inventory(const Inventory& copy); // Copy constructor
	Inventory(const std::initializer_list<Item> itemList);

	void Resize(int capacity);

	const Inventory& operator=(const Inventory& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		if (mItemList != nullptr)
		{
			delete[] mItemList;
		}

		mItemCount = rhs.mItemCount;
		mItemList = new Item[mItemCount];

		for (int i = 0; i < mItemCount; i++)
		{
			mItemList[i] = rhs.mItemList[i];
		}

		return *this;
	}

	Item& operator[](const int index)
	{
		return mItemList[index];
	}

	void AddItem(EItemType itemType);
	void RemoveItem(int index);
	void SwapItem(int lhsIndex, int rhsIndex);

	void Print();

private:
	Item* mItemList = nullptr;
	int mItemCount = 0;
	int mCapacity = 0;
};