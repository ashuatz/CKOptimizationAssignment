#include <iostream>

#include "Inventory.h"

void pause();
template <typename Container, typename Index>
decltype(auto) pauseAndAccess(Container&& c, Index i) {
	pause();
	return std::forward<Container>(c)[i];
}

int main(){
	Inventory i;

	i.AddItem(Item(1));
}

void pause() {
	std::cout << "³»°¡ Àá±ñ ¸ØÃß¾îº¼²², ¾å!\n";
}
