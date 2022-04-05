#include <iostream>

#include "Inventory.h"
#include "Item.h"

void pause()
{
	std::cout << "Pause and access to container...\n";
}

template <typename Container, typename Index>
decltype(auto) pauseAndAccess(Container&& c, Index i)
{
	pause();
	return std::forward<Container>(c)[i];
}

int main()
{
	Inventory MyInventory = Inventory(100);

	std::cout << "Add some items to MyInventory\n";
	MyInventory.AddItem(EItemType::SomeItem_1);
	MyInventory.AddItem(EItemType::SomeItem_2);
	MyInventory.AddItem(EItemType::SomeItem_4);
	MyInventory.AddItem(EItemType::SomeItem_1);
	MyInventory.AddItem(EItemType::SomeItem_3);

	std::cout << "MyInventory item list\n";
	MyInventory.Print();

	std::cout << "Remove second item in MyInventory\n";
	MyInventory.RemoveItem(2);

	std::cout << "MyInventory item list\n";
	MyInventory.Print();

	std::cout << "Copy MyInventory to CopiedInventroy\n";
	Inventory CopiedInventory = MyInventory;

	std::cout << "CopiedInventory item list\n";
	CopiedInventory.Print();

	std::cout << "Swap item 1 and 3 in CopiedInventory\n";
	CopiedInventory.SwapItem(1, 3);

	std::cout << "CopiedInventory item list\n";
	CopiedInventory.Print();

	std::cout << "Test pauseAndAccess\n";
	auto item = pauseAndAccess(CopiedInventory, 1);
	item.Print(0);

	std::cout << "\nTest initializer list\n";
	Inventory initializerInventory = Inventory{ Item(EItemType::SomeItem_1), Item(EItemType::SomeItem_3) };
	initializerInventory.Print();
}