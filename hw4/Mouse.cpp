//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "Mouse.h"

/// Mouse constructor
Mouse::Mouse(int price, string manufacturer, string color, bool isWireless, int dpi)
	: Item(price, manufacturer), PeripheralDevice(price, manufacturer, color, isWireless), dpi(dpi)
{
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

/// connecting this Mouse to computer
void Mouse::connect(Computer& computer)
{
	cout << "Connecting a mouse" << endl;
	cout << this->operator std::string() << " is connecting to computer: " 
		<< computer.operator std::string() << endl;

	PeripheralDevice::connect(computer);
}