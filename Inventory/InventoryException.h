#pragma once

#include <exception>

class InventoryException : public std::exception
{
public:
	InventoryException(const char* str, int index) : std::exception(str, index) {}

	virtual ~InventoryException() {}
protected:
};

class InventoryOutOfRangeException : public InventoryException
{
public:
	InventoryOutOfRangeException(int index) : InventoryException("InventoryOutOfRangeException", index) {}
};

class InventoryInvalidItemIndexException : public InventoryException
{
public:
	InventoryInvalidItemIndexException(int index) : InventoryException("InventoryInvalidItemIndexException", index) {}
};

class InventoryAreadyFilledItemException : public InventoryException
{
public:
	InventoryAreadyFilledItemException(int index) : InventoryException("InventoryAreadyFilledItemException", index) {}
};