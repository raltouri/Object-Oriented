//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#include <iostream>
#include <string>
#include "Item.h"
using std::string;


class Computer : public Item
{
	string cpu;
	bool isALaptop;
public:
	/// Computer constructor
	Computer( int price = 0, string manufacturer = "~",string cpu = "~", bool isALaptop = true);
	/// cpu getter
	string getCpu() const;
	/// IsAlaptop getter: return true if laptop else(desktop) false
	bool getIsALaptop() const;
	/// cpu setter
	void setCpu(const string& cpu);
	/// IsAlaptop setter
	void setIsALaptop(const bool& isALaptop);
	/// casting computer into string
	operator string() const;
};

