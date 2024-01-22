//Moath Samara, 314630153.
// Rashad Altouri, 209424340.
#include "Shop.h"

// Shops's Class constructor.
// here we check if the input string is longer than 10 letters, if so we notify the user and set a default value.
Shop::Shop(Manager manager, string name , Day closedDay, bool isOnline) : manager(manager), closedDay(closedDay), isOnline(isOnline)
{
	if (name.length() > 10)
	{
		cout << "Shop name length is too long" << endl;
		this->name = "~";
	}
	else
	{
		this->name = name;
	}
}
// Shop Manager get method.
Manager Shop::getManager() const
{
	return this->manager;
}
// Shop Name get method.
string Shop::getName() const 
{
	return this->name;
}
// Shop ClosedDay get method.
  Day Shop::getClosedDay() const
{
	return this->closedDay;
}
// Shop IsOnline get method.
bool Shop::getIsOnline() const 
{
	return this->isOnline;
}
// Shop Manager set method.
void Shop::setManager(const Manager& newManager)
{
	this->manager = newManager;
}
// Shop Name set method.
// here we check if the newName is longer than 10 letters we notify the user and set a default value.
void Shop::setName(const string& newName)
{
	if (newName.length() > 10)
	{
		cout << "Shop name length is too long" << endl;
		this->name = "~";
	}
	else 
	{
		this->name = newName;
	}
}
// Shop ClosedDay set method.
void Shop::setClosedDay(const Day& newClosedDay)
{
	this->closedDay = newClosedDay;
}
// Shop IsOnline set method.
void Shop::setIsOnline(const bool& newIsOnline)
{
	this->isOnline = newIsOnline;
}
// Shop print method.
void Shop::print() const
{
	cout << "Printing shop: " << endl;
	this->manager.print();
	cout << "Name : " << this->name << endl;
	cout << "Closed day : ";
	switch (this->closedDay)
	{
	case Sunday:
		cout << "Sunday" << endl;
		break;
	case Monday:
		cout << "Monday" << endl;
		break;
	case Tuesday:
		cout << "Tuesday" << endl;
		break;
	case Wednesday:
		cout << "Wednesday" << endl;
		break;
	case Thursday:
		cout << "Thursday" << endl;
		break;
	case Friday:
		cout << "Friday" << endl;
		break;
	case Saturday:
		cout << "Saturday" << endl;
		break;
	}
	cout << "Is Online : ";
	if (this->isOnline == 0)
	{
		cout << "False" << endl;
	}
	else
	{
		cout << "True" << endl;
	}
	
}