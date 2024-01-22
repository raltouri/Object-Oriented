//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "PeripheralDevice.h"

/// PeripheralDevice constructor
PeripheralDevice::PeripheralDevice(int price, string manufacturer, string color, bool isWireless) : Item(price,manufacturer)
{
	this->color = color;
	this->isWireless = isWireless;
}

/// PeripheralDevice destructor
PeripheralDevice::~PeripheralDevice() {
}

/// device color getter
string PeripheralDevice::getColor() const
{
	return this->color;
}

/// isWireless getter: return true if wireless else(wired) false
bool PeripheralDevice::getisWireless() const
{
	return this->isWireless;
}

/// device color setter
void PeripheralDevice::setColor(const string& color)
{
	this->color = color;
}

/// isWireless setter
void PeripheralDevice::setIsWireless(const bool& isWireless)
{
	this->isWireless = isWireless;
}

/// casting item into string
PeripheralDevice::operator string() const
{
	return Item::operator std::string() + "," + ((this->isWireless) ? " Wireless" : " Wired") + ", " + this->getColor();
}

/// connecting this PeripheralDevice to computer (print string that says connected)
void PeripheralDevice::connect(const Computer& computer) const
{
	cout << this->operator std::string() << " is connecting to computer: "<<computer.operator std::string() << endl;
}