//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "Tablet.h"

// c'tor
Tablet::Tablet(int price, string manufacturer, string color, string cpu, bool isALaptop, int screenSize)
	:Item(price, manufacturer), Computer(price, manufacturer , color,isALaptop)
{
	this->screenSize = screenSize;
	this->setCpu(cpu);
}
/// casting tablet into string
Tablet::operator string() const
{
	return this->Item::operator std::string() + ", " + this->color + ", " + this->getCpu() + ", Tablet with screen size: "+std::to_string(screenSize);
}
