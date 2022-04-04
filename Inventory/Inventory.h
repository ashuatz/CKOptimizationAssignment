#pragma once
#include<initializer_list>

struct Item
{
	Item() : id(-999) { }
	Item(std::initializer_list<int> li) {
		id = *li.begin();
	}
	int id;
};

class Inventory
{
public:
	Inventory(int itemNum);
	Inventory(const Inventory& copy);

	template<typename T>
	Inventory(std::initializer_list<T> list) {
		mItemNum = list.size();
		mItems = new Item[list.size()];

		int i = 0;
		for (auto it : list)
		{
			mItems[i++] = Item{ it };
		}
	}
	~Inventory();

public:
	Inventory& operator=(const Inventory& rhs);
	Item& operator[](const int index);

public:
	void AddItem(int index, int itemID);
	void RemoveItem(int index);
	void SwapItem(int target1, int target2);

private:
	Item* mItems = nullptr;
	int mItemNum;
};