#pragma once

#include <exception>
#include "Item.h"

class InventoryException : public std::exception
{
public:
	InventoryException(const char* message) : std::exception(message) {}
	virtual ~InventoryException() {}
};

class OutOfRangeException : public InventoryException
{
public:
	OutOfRangeException(int index) : InventoryException("[Error] Inventory out of range! Index : " + index) {}
};

class InvalidItemTypeException : public InventoryException
{
public:
	InvalidItemTypeException() : InventoryException("[Error] Inventory invlid item type!") {}
};

class InventoryIsFullException : public InventoryException
{
public:
	InventoryIsFullException() : InventoryException("[Error] Inventory is currently full") {}
};