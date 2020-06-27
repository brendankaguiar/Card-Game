#ifndef _BagInterface_h
#define _BagInterface_h

#include <vector>
#include <string>
#include <iostream>
template<class ItemType>
class BagInterface 
{
public:
	virtual int getCurrentSize() const = 0; // Get #ofItems in bag
	virtual bool isEmpty() const = 0; // Checks if bag is empty
	virtual bool add(const ItemType& newEntry) = 0; // Add if not full
	virtual bool remove(const ItemType& anEntry) = 0; // Delete if not full
	virtual void clear() = 0; // Delete all
	virtual bool contains(const ItemType& anEntry) const = 0; // Check to see if item is present in list
	virtual int getFrequencyOf(const ItemType& anEntry) const = 0; // Get # of Occurrences of an item
	virtual std::vector<ItemType> toVector() const = 0;
	virtual ~BagInterface() {}
};
#endif // !_BagInterface_h
