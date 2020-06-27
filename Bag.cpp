#include "Bag.h"

template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{} // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
} // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	if (itemCount == 0)
		return true;
	else
		return false;
} // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	} // end if
	return hasRoomToAdd;
} // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		items[locatedIndex] = items[itemCount - 1];
		itemCount--;
		return true;
	} // end if
	else
		return false;
} //end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{

} //end clear

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
} //end contains

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
	int result = -1;
	int searchIndex = 0;
	while (!found && (searchIndex < itemCount))
	{
		if (items[searchIndex] == target)
		{
			found = true;
			result = searchIndex;
		}
		else
		{
			searchIndex++;
		} // end if
	} // end while
	return result;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int curIndex = 0;
	while (curIndex < itemCount)
	{
		if (items[curIndex] == anEntry)
		{
			frequency++;
		} // end if
		curIndex++;
	} // end while
	return frequency;
} // end getFrequencyOf

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);

	return bagContents;
	
} // end toVector

