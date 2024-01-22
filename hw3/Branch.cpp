//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "Branch.h"

/// Branch constructor
Branch::Branch(string location)
{
	this->location = location;
	this->itemsNumber = 0;
	this->oldestItem = 0;
}

/// Branch destructor
Branch::~Branch()
{
	for (int i = 0;i < itemsNumber;i++)
	{
		delete(catalog[i]);
	}
}

/// catalog getter
Item** Branch::getCatalog(int& num)
{
	num = itemsNumber;
	return catalog;
}

/// Location getter
string Branch::getLocation() const
{
	return this->location;
}

/// Location setter
void Branch::setLocation(const string& location)
{
	this->location = location;
}

/// add item to the catalog
void Branch::addItem(Item* item)
{
	if (this->itemsNumber < BRANCH_SIZE) // if there is a space to add the item
	{
		catalog[itemsNumber] = item;
		itemsNumber++;
	}
	else // no space in catalog so we throw old item and insert new one
	{
		catalog[oldestItem % BRANCH_SIZE]->~Item();
		catalog[oldestItem % BRANCH_SIZE] = item;
		oldestItem++;
	}
}
