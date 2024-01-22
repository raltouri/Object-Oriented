//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "Branch.h"

/// c'tor
Branch::Branch(string location,int capacity) :capacity(capacity)
{
	this->location = location;
	this->itemsNumber = 0;
	this->oldestItem = 0;
}

/// copy c'tor
Branch::Branch(const Branch& other) :location(other.location),capacity(other.capacity){
}

/// d'tor
Branch::~Branch()
{
	for (Item* item : catalog)
	{
		item->~Item();
	}
}

/// catalog getter
vector<Item*> Branch::getCatalog() const
{
	return catalog;
}

/// Location getter
string Branch::getLocation() const
{
	return this->location;
}


/// add item to the catalog
void Branch::addItem(Item* item)
{
		if (this->itemsNumber == this->capacity) {
			throw FullCatalogError();
		}
		vector<Item*>::iterator	itr;
		for (itr = catalog.begin(); itr != catalog.end(); itr++) {
			if ((*itr)->getId() == item->getId()) {
					throw ExistingItemError();
			}
		}
		catalog.push_back(item);
		this->itemsNumber++;
		this->totalPrices += item->getPrice();
}

/// remove item from the catalog
Item* Branch::removeItem(const int id)
{
	Item* tmp = NULL;
	vector<Item*>::iterator	itr;
	for (itr = catalog.begin(); itr != catalog.end(); itr++) 
	{
		if ((*itr)->getId() == id) 
		{
			tmp = *itr;
			this->totalPrices -= (*itr)->getPrice();
			catalog.erase(itr);
			this->itemsNumber--;
			return tmp;
		}
	}
	throw NonExistingItemError();
}
// get size of catalog
int Branch::getItemsNumber() const
{
	return this->itemsNumber;
}
// get total items price in catalog
int Branch::getTotalPrices() const
{
	return this->totalPrices;
}

