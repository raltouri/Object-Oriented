//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#include <iostream>
#include <string>
#include "Item.h"
#include "Computer.h"
#include "HWExceptions.h"
using std::string;

class Computer;

class PeripheralDevice : virtual public Item
{
	///string color;
	bool isWireless;
	int connectCount;
	Computer* connectedComputer;
public:
	/// PeripheralDevice constructor
	PeripheralDevice(int price =0, string manufacturer="~", string color="~", bool isWireless = true);

	/// PeripheralDevice constructor
	virtual ~PeripheralDevice();

	/// device color getter
	string getColor() const;
	
	/// isWireless getter: return true if wireless else(wired) false
	bool getisWireless() const;
	
	/// device color setter
	void setColor(const string& color);
	
	/// isWireless setter
	void setIsWireless(const bool& isWireless);
	
	/// casting PeripheralDevice into string
	virtual operator string() const;
	
	/// connecting this PeripheralDevice to computer
	virtual void connect( Computer& computer);
	/// disconnecting this PeripheralDevice from computer
	virtual void disconnect();
};

