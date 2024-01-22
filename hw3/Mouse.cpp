//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "Mouse.h"

/// Mouse constructor
Mouse::Mouse(int price, string manufacturer, string color, bool isWireless, int dpi) : PeripheralDevice(price,manufacturer,color,isWireless)
{
	this->dpi = dpi;
}

/// dpi getter
int Mouse::getDpi() const
{
	return this->dpi;
}

/// dpi setter
void Mouse::setDpi(const int& dpi)
{
	this->dpi = dpi;
}

/// casting Mouse into string
Mouse::operator string() const
{
	return PeripheralDevice::operator std::string() + ", Mouse with dpi : " + std::to_string(this->getDpi());
}

/// connecting this Mouse to computer (print string that says connected)
void Mouse::connect(const Computer& computer) const
{
	cout << "Connecting a mouse " << endl;
	PeripheralDevice::connect(computer);
}