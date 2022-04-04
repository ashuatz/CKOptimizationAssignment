#pragma once

#include <initializer_list>

#include "InventoryException.h"

enum ITEMID : long {ERROR = -1, NONE, Etc1, Etc2} ;

struct Item{
	Item(int index = ERROR) : _id(index) {}

	int _id;
};

class Inventory{
public:
	// ctor Group
	Inventory() = default;
	Inventory(int itemNum) : _ItemNum(itemNum){
		_ItemList = new(std::nothrow) Item[itemNum];
		for (int i = 0; i < _ItemNum; i++) _ItemList[i] = static_cast<Item>(NONE);
	}
	Inventory(const Inventory& copy) {
		// 1
		if (this == &copy) return;
		if (_ItemList) delete[] _ItemList;

		_ItemNum = copy._ItemNum;
		_ItemList = new(std::nothrow) Item[_ItemNum];

		for (int i = 0; i < _ItemNum; i++) _ItemList[i] = copy._ItemList[i];
		// 2
		// this.operator=(copy);
	}
	template<typename T>
	Inventory(const std::initializer_list<T> itemindexlist) {
		_ItemNum = itemindexlist.size();
		_ItemList = new(std::nothrow) Item[_ItemNum];

		int i = 0;
		for (auto ItemIndex : itemindexlist) _ItemList[i++] = Item(ItemIndex);
	}

	// dtor
	~Inventory() {
		delete[] _ItemList;
	}

	// Operator Overroding Group
	const Inventory& operator=(const Inventory& rhs) {
		if (this == &rhs) return *this;
		if (_ItemList) delete[] _ItemList;

		_ItemNum = rhs._ItemNum;
		_ItemList = new(std::nothrow) Item[_ItemNum];

		for (int i = 0; i < _ItemNum; i++) _ItemList[i] = rhs._ItemList[i];

		return *this;
	}
	Item& operator[](const int index) {
		return _ItemList[index];
	}

	// Class Method Group
	void AddItem(int, int);
	void RemoveItem(int);
	void SwapItem(int, int);

private:
	int _ItemNum = 0;

	Item* _ItemList = nullptr;
};