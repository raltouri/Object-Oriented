//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "HWExceptions.h"

#define BRANCH_SIZE 10
using std::string;
using std::vector;

class Branch
{
	///Item* catalog[BRANCH_SIZE];
	vector<Item*> catalog;
	const int capacity;
	string location;
	int itemsNumber = 0;
	int oldestItem = 0;
	int totalPrices = 0;
public:
	/// Branch constructor
	Branch(string location = "~",int capacity = 0);
	Branch(const Branch& other);
	/// Branch destructor
	~Branch();

	/// add item to the catalog
	void addItem(Item* item);
	/// remove item from the catalog
	Item* removeItem(const int id);
	
	/// getters
	vector<Item*> getCatalog() const;
	string getLocation() const;
	int getItemsNumber()const;
	
	/// get finest item in catalog
	template<class T>
	T* giveMeFinest(const T* item) const
	{
		bool found = false;
		T* finest = nullptr;
		const std::type_info& ti1 = typeid(*item);
		///first loop finds first instance of the item of same class type
		for (int i = 0; i < catalog.size(); i++) {
			const std::type_info& ti2 = typeid(*catalog[i]);
			if (ti1 == ti2) {
				found = true;
				finest = dynamic_cast<T*>(catalog[i]);
				break;
			}
		}
		///throw non-exist exception if we didnt find an item with same type
		if (!found)
			throw NoneExistingItemTypeError();

		///loop 2 finds the finest which has the highest price
		for (int i = 0; i < catalog.size(); i++) {
			const std::type_info& ti3 = typeid(*catalog[i]);
			if (ti1 == ti3 && catalog[i]->getPrice() > finest->getPrice()) {
				finest = dynamic_cast<T*>(catalog[i]);
			}
		}
		return dynamic_cast<T*>(finest);
	}
	int getTotalPrices() const;
};

