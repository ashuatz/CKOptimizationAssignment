#pragma once

#include <vector>
#include <initializer_list>

#include "InventoryException.h"
#include "Item.h"

class Inventory
{
public:
	// Constructor
	Inventory() = default;
	Inventory(int capacity)
	{
		for (int i = 0; i < capacity; i++)
		{
			mItemList.push_back(Item(EItemType::None));
		}
	}

	// Rule of zero
	virtual ~Inventory() = default;
	Inventory(const Inventory& copy) = default;
	Inventory(Inventory&& src) = default;
	Inventory& operator=(const Inventory& rhs) = default;
	Inventory& operator=(Inventory&& rhs) = default;

	Item& operator[](const int index)
	{
		return mItemList[index];
	}

	void AddItem(EItemType itemType);
	void RemoveItem(int index);
	void SwapItem(int lhsIndex, int rhsIndex);

	void Print();

private:
	std::vector<Item> mItemList;
};