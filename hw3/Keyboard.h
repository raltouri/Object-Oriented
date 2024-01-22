//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#include <iostream>
#include <string>
#include "PeripheralDevice.h"
#include "Computer.h"
using std::string;


class Keyboard : public PeripheralDevice
{
	int numberOfKeys;
public:
	/// Keyboard constructor
	Keyboard(int price=0,string manufacturer="~",string color="~",bool isWireless= true, int numberOfKeys = 0);
	
	/// Number of keys getter
	int getNumberOfKeys() const;

	/// Number of keys setter
	void setNumberOfKeys(const int& numberOfKeys);
	
	/// casting Keyboard into string
	operator string() const;

	/// connecting this Keyboard to computer (print string that says connected)
	void connect(const Computer& computer) const;
};

