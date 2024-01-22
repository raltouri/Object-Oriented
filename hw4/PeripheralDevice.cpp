//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "PeripheralDevice.h"

/// PeripheralDevice constructor
PeripheralDevice::PeripheralDevice(int price, string manufacturer, string color, bool isWireless) : Item(price,manufacturer)
{
	this->color = color;
	this->isWireless = isWireless;
	this->connectCount = 0;
	this->connectedComputer = NULL;
}

/// PeripheralDevice destructor
PeripheralDevice::~PeripheralDevice() {
	this->disconnect();
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
	return Item::operator std::string() + "," + 
		((this->isWireless) ? " Wireless" : " Wired") + ", " + this->getColor();
}

/// connecting this PeripheralDevice to computer
void PeripheralDevice::connect( Computer& computer) 
{
	/// 1. A peripheral cannot be connected to 2 computers at the same time
	if (this->connectCount == 1)
	{
		throw ConnectError();
	}

	///3. Amount of peripheral devices connected to a computer cannot be higher then his usb port's
	if (computer.getNumOfPorts() == computer.getConnectedCount())
	{
		throw ConnectError();
	}

	if (computer.checkExactDev(this->getId())) {
		return;
	}
	///2. A computer cannot have 2 peripheral devices of the same type connected to him
	const PeripheralDevice* tmp = this;
	if (computer.typeExist(tmp))
	{
		throw ConnectError();
	}
	////SECCESS
	this->connectedComputer = &computer;
	computer.connectPer(this);
}

/// disconnecting this PeripheralDevice from computer
void PeripheralDevice::disconnect()
{
	/// if not connected to any computer do nothing
	if (!this->connectedComputer)
	{
		return;
	}
	////SECCESS
	this->connectedComputer->disConnectPer(this->getId());
	this->connectedComputer = NULL;
}