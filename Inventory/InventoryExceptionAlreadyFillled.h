#pragma once

#include "InventoryException.h"

class InventoryExceptionAlreadyFillled : public InventoryException
{
public : 
	InventoryExceptionAlreadyFillled(int itemIndex) : InventoryException(itemIndex) { }
public :
	virtual const char* what() const noexcept
	{
		return "The inventory index was filled already";
	}
};