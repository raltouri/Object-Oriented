//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "Computer.h"

/// Computer constructor
Computer::Computer(int price, string manufacturer, string cpu, bool isALaptop) : Item(price,manufacturer)
{
	this->cpu = cpu;
	this->isALaptop = isALaptop;
}

/// cpu getter
string Computer::getCpu() const
{
	return this->cpu;
}

/// IsAlaptop getter: return true if laptop else(desktop) false
bool Computer::getIsALaptop() const
{
	return this->isALaptop;
}

/// cpu setter
void Computer::setCpu(const string& cpu)
{
	this->cpu = cpu;
}

/// IsAlaptop setter
void Computer::setIsALaptop(const bool& isALaptop)
{
	this->isALaptop = isALaptop;
}

/// casting computer into string
Computer::operator string() const
{
	return this->Item::operator std::string() + "," + ((this->isALaptop) ? " Laptop" : " Desktop") + ", " + this->getCpu();
}
