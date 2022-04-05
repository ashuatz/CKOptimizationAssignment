#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

enum class EItemType
{
	None = 0,
	SomeItem_1 = 1,
	SomeItem_2 = 2,
	SomeItem_3 = 3,
	SomeItem_4 = 4,
};

static std::unordered_map<EItemType, std::string> itemStringTable =
{
	{ EItemType::None, "None" },
	{ EItemType::SomeItem_1, "SomeItem_1" },
	{ EItemType::SomeItem_2, "SomeItem_2" },
	{ EItemType::SomeItem_3, "SomeItem_3" },
	{ EItemType::SomeItem_4, "SomeItem_4" },
};

struct Item
{
	Item() : Type(EItemType::None) {}
	Item(EItemType item) : Type(item) {}
	EItemType Type;

public:
	void Print(int index)
	{
		std::cout << "Item [" << index << "] : " << itemStringTable[Type] << "\n";
	}
};
