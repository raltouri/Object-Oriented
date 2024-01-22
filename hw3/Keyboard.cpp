//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "Keyboard.h"

/// Keyboard constructor
Keyboard::Keyboard(int price, string manufacturer, string color, bool isWireless, int numberOfKeys) : PeripheralDevice(price,manufacturer,color,isWireless)
{
	this->numberOfKeys = numberOfKeys;
}

/// Number of keys getter
int Keyboard::getNumberOfKeys() const
{
	return this->numberOfKeys;
}

/// Number of keys setter
void Keyboard::setNumberOfKeys(const int& numberOfKeys)
{
	this->numberOfKeys = numberOfKeys;
}

/// casting Keyboard into string
Keyboard::operator string() const
{
	return PeripheralDevice::operator std::string() + ", Keyboard with " + std::to_string(this->getNumberOfKeys()) + " keys";
}

/// connecting this Keyboard to computer (print string that says connected)
void Keyboard::connect(const Computer& computer) const
{
	cout << "Connecting a keyboard " << endl;
	PeripheralDevice::connect(computer);
}