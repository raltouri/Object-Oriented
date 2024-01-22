//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "PeripheralDevice.h"

using std::string;
using std::vector;

class PeripheralDevice;

class Computer : virtual public Item
{
	string cpu;
	bool isALaptop;
	const int numOfPorts;
	int connectedCount;
	vector<PeripheralDevice*> myConnections;
public:
	/// Computer constructor
	Computer( int price = 0, string manufacturer = "~"/*,string cpu = "~"*/,string color = "~", bool isALaptop = true,int numOfPorts=0);
	/// Computer destructor
	~Computer();
	/// cpu getter
	string getCpu() const;
	/// IsAlaptop getter: return true if laptop else(desktop) false
	bool getIsALaptop() const;
	/// cpu setter
	void setCpu(const string& cpu);
	/// IsAlaptop setter
	void setIsALaptop(const bool& isALaptop);
	/// casting computer into string
	operator string() const;
	// NumOfPorts getter
	int getNumOfPorts() const;

	// connected devices info
	int getConnectedCount() const;
	void increaseConnectedCount();
	void decreaseConnectedCount();

	// connect methods
	void connectPer(PeripheralDevice* dev);
	void disConnectPer(int id);
	bool checkExactDev(int id) const;
	bool typeExist(const PeripheralDevice*) const;

	void printConnected();
};

