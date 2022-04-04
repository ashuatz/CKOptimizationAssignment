#include <iostream>
#include <memory>

#include "Inventory.h"

void pause()
{
	std::cout << "Paused" << std::endl;
}

template <typename Container, typename Index>
decltype(auto) pauseAndAccess(Container&& c, Index i)
{
	pause();
	return std::forward<Container>(c)[i];
}

Inventory makeInventory()
{
	return Inventory(10);
}

int main()
{
	Item item{ 1001 };
	Inventory myInven3{ 1001,1002,1003 };

	{
		auto p_Inven = std::make_unique<Inventory>(myInven3);
		auto p_Inven_copied = std::move(p_Inven);

		try
		{
			p_Inven_copied->AddItem(1, 10);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	Inventory myInven2(10);

	auto slot2 = pauseAndAccess(myInven2, 5);
}