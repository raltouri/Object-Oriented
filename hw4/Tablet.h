//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once

#include "PeripheralDevice.h"
#include "Computer.h"

class Tablet : public PeripheralDevice,public Computer
{
	int screenSize;

public:
	/// Tablet constructor
	Tablet(int price = 0, string manufacturer = "~", string color = "~" 
		,string cpu = "~", bool isALaptop = true, int screenSize = 0);
	/// Tablet destructor
	~Tablet() {}
	/// casting tablet into string
	operator string() const;
};

