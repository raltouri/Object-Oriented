//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#ifndef _COMPANY_H_
#define _COMPANY_H_

#include "Shop.h"
#define MAX_SHOPS_NUMBER 10

class Company
{
	string name;
	Shop shops[MAX_SHOPS_NUMBER];
	int shopsNumber;

public:
	// Constructor.
	Company(string name = "~", int shopsNumber = 0);

	// Company Name get method.
	string getName() const;

	// Company ShopsNumber get method.
	int getShopsNumber() const;

	// Company Name set method.
	void setName(const string& newName);

	// Company addShop method.
	void addShop(const Shop& newShop);

	// Company printShopsByName method.
	// here we print the shops in order based on their name.
	void printShopsByName();

	// Company printShopsByDay method.
	// here we print the shops in order based on the Day(closedDay).
	void printShopsByDay();

};

#endif