//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#include <iostream>
#include <string>
#include "Item.h"
#define BRANCH_SIZE 10
using std::string;

class Branch
{
	Item* catalog[BRANCH_SIZE];
	string location;
	int itemsNumber = 0;
	int oldestItem = 0;
public:
	/// Branch constructor
	Branch(string location = "~");
	/// Branch destructor
	~Branch();
	/// catalog getter
	Item** getCatalog(int& num);
	/// Location getter
	string getLocation() const;
	/// Location setter
	void setLocation(const string& location);
	/// add item to the catalog
	void addItem(Item* item);       
};

