//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#ifndef _SHOP_H_
#define _SHOP_H_

#include "Manager.h"

enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

class Shop
{
	Manager manager;
	string name;
	Day closedDay;
	bool isOnline;

public:
	// Constructor.
	Shop(Manager manager = (0, "~", Sunday, 0), string name = "~", Day closedDay = Sunday, bool isOnline = false);
	
	// Shop Manager get method.
	Manager getManager() const;

	// Shop Name get method.
	string getName() const;

	// Shop ClosedDay get method.
	Day getClosedDay() const;

	// Shop IsOnline get method.
	bool getIsOnline() const;

	// Shop Manager set method.
	void setManager(const Manager& newManager);

	// Shop Name set method.
	// here we check if the newName is longer than 10 letters we notify the user and set a default value.
	void setName(const string& newName);

	// Shop ClosedDay set method.
	void setClosedDay(const Day& newClosedDay);

	// Shop IsOnline set method.
	void setIsOnline(const bool& newIsOnline);

	// Shop print method.
	void print() const;


};

#endif