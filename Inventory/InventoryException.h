#pragma once

#include <exception>

class InventoryException : public std::exception{
public : 
	// ctor
	InventoryException(const char* str, int index) : std::exception(str), _ErrorIndex(index){}
	// dtor
	virtual ~InventoryException() {}

	// method
	__forceinline int getErrorIndex() noexcept {
		return _ErrorIndex;
	}
protected :
	int _ErrorIndex;
};

class IE_OutOfRange : public InventoryException {
public:
	// ctor
	IE_OutOfRange(int index) : InventoryException("InventoryException - OutOfRange", index) {}
};

class IE_InvalidItemID : public InventoryException {
public:
	// ctor
	IE_InvalidItemID(int index) : InventoryException("InventoryException - InvalidItemID", index) {}
};

class IE_AreadyFilledItem : public InventoryException {
public:
	// ctor
	IE_AreadyFilledItem(int index) : InventoryException("InventoryException - AreadyFilledItem", index) {}
};