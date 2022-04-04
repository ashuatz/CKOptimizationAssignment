#pragma once

#include "InventoryException.h"

class InventoryExceptionEmptyIndex : public InventoryException
{
public:
	InventoryExceptionEmptyIndex(int itemIndex) : InventoryException(itemIndex) { }
public:
	virtual const char* what() const noexcept
	{
		return "The inventory index is empty";
	}
};