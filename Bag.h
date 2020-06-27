#ifndef _Bag_h
#define _Bag_h
#include "BagInterface.h" // Conceptually a list of defined size

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 7;
	ItemType items[DEFAULT_CAPACITY]; // Array List
	int itemCount;
	int maxItems;
	int getIndexOf(const ItemType& target) const;
public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
}; // end ArrayBag aka List

#endif