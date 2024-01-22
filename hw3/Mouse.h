//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#include <iostream>
#include <string>
#include "PeripheralDevice.h"
#include "Computer.h"
using std::string;

class Mouse : public PeripheralDevice
{
	int dpi;
public:
	/// Mouse constructor
	Mouse(int price = 0, string manufacturer = "~", string color = "~", bool isWireless = true, int dpi=0);
	
	/// dpi getter
	int getDpi() const;
	
	/// dpi setter
	void setDpi(const int& dpi);

	/// casting Mouse into string
	operator string() const;

	/// connecting this Mouse to computer (print string that says connected)
	void connect(const Computer& computer) const;
};

