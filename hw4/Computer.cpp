//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "Computer.h"

/// Computer constructor
Computer::Computer(int price, string manufacturer/*, string cpu*/, string color, bool isALaptop,int numOfPorts) : Item(price,manufacturer),numOfPorts(numOfPorts)
{
	this->cpu = cpu;
	this->isALaptop = isALaptop;
	this->color = color;
	this->connectedCount = 0;
}
/// Computer destructor
Computer::~Computer()
{
	///vector<PeripheralDevice*>::iterator itr;
	for(PeripheralDevice* itr : myConnections){	
		itr->disconnect();
	}
}

/// cpu getter
string Computer::getCpu() const
{
	return this->cpu;
}

/// IsAlaptop getter: return true if laptop else(desktop) false
bool Computer::getIsALaptop() const
{
	return this->isALaptop;
}

/// cpu setter
void Computer::setCpu(const string& cpu)
{
	this->cpu = cpu;
}

/// IsAlaptop setter
void Computer::setIsALaptop(const bool& isALaptop)
{
	this->isALaptop = isALaptop;
}

/// casting computer into string
Computer::operator string() const
{
	return this->Item::operator std::string() + "," + ((this->isALaptop) ? " Laptop" : " Desktop") + ", " + this->color;
}

/// connected devices info
int Computer::getNumOfPorts() const{
	return this->numOfPorts;
}
int Computer::getConnectedCount() const
{
	return this->connectedCount;
}
void Computer::increaseConnectedCount()
{
	this->connectedCount++;
}
void Computer::decreaseConnectedCount()
{
	this->connectedCount--;
}
///

/// connect methods
void Computer::connectPer(PeripheralDevice* dev)
{
	this->myConnections.push_back(dev);
	this->connectedCount++;
}

void Computer::disConnectPer(int id) {
	int idx = 0;
	///vector<PeripheralDevice*>::iterator itr;
	for (PeripheralDevice* itr : myConnections) {
		if (itr->getId() == id) {
			myConnections.erase(myConnections.begin()+idx);
			this->connectedCount--;
			return;
		}
		idx++;
	}
	/*vector<PeripheralDevice*>::const_iterator itr;
	for (itr = myConnections.begin(); itr != myConnections.end(); itr++) {
		if ((*itr)->getId() == id) {
			myConnections.erase(itr);
			this->connectedCount--;
			return;
		}
	}*/
}

bool Computer::typeExist(const PeripheralDevice* dev) const{
	///vector<PeripheralDevice*>::iterator itr;
	for (PeripheralDevice* itr : myConnections) {
		if (typeid((*itr)) == typeid(*dev)) {
			return true;
		}
	}
	return false;
	/*vector<PeripheralDevice*>::const_iterator itr;
	for (itr = myConnections.begin(); itr != myConnections.end(); itr++) {
		if (typeid(*(*itr)) == typeid(*dev)) {
			return true;
		}
	}*/
}
bool Computer::checkExactDev(int id) const {
	for (PeripheralDevice* itr : myConnections) {
		if (itr->getId() == id) {
			return true;
		}
	}
	/*vector<PeripheralDevice*>::const_iterator itr;
	for (itr = myConnections.begin(); itr != myConnections.end(); itr++) {
		if ((*itr)->getId() == id) {
			return true;
		}
	}*/
	return false;
}

void Computer::printConnected() {
	std::cout << "There are " << connectedCount << " connections to id " 
		<< this->getId() << ": " << this->getManufacturer()
		<< ", " << this->getPrice() << "$, " 
		<< ((this->isALaptop) ? "Laptop, " : "Desktop, ") << this->color << std::endl;
	
	for (PeripheralDevice* itr : myConnections) {
		std::cout << static_cast<string>(*itr) << std::endl;
	}
	/*vector<PeripheralDevice*>::iterator itr; 
	for (itr = myConnections.begin(); itr != myConnections.end(); itr++) {
		std::cout << static_cast<string>(*(*itr)) << std::endl;
	}*/
}
///