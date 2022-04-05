#pragma once

#include <vector>
#include <memory>

#include "InventoryException.h"

enum ITEMID : long {ERROR = -1, NONE, Etc1, Etc2} ;

struct Item{
	Item(int index = ERROR) : _id(index) {}

	int _id;
};

class Inventory{
public:
	using ItemList = std::vector<Item>;

// Rule Of 0 Group Start
// use std::unique_ptr -> deleted 1 ctor , operator= 
	// ctor Group
	Inventory() = default;
	Inventory(const Inventory&) = delete;
	Inventory(Inventory&&) = default;

	// dtor
	~Inventory() = default;

	// Operator Overroding Group
	Inventory& operator=(const Inventory&) = delete;
// Rule Of 0 Group End 
	Item& operator[](const int index) {
		if (index < 0 || index >= _ItemList->size())	throw IE_OutOfRange(index);

		return _ItemList->at(index);
	}

	// Class Method Group
	void AddItem(Item);
	void RemoveItem(int);
	void SwapItem(int, int);

private:
	int _ItemNum = 0;

	 std::unique_ptr<ItemList> _ItemList = std::make_unique<ItemList>();
};