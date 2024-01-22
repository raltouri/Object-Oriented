//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "MainOffice.h"

// d'tor
MainOffice::~MainOffice()
{
	map<string, Branch*>::iterator itr;
	for (itr = branches.begin(); itr != branches.end(); itr++) {
		if ((*itr).second)
			(*itr).second->~Branch();
	}
}

// Singleton getIntance method 
MainOffice& MainOffice::getInstance()
{
	static MainOffice mo;
	return mo;
}

// add branch to branches map
void MainOffice::addBranch(const string& location, int capacity)
{
	if (branches.find(location) != branches.end())
	{
		throw ExistingBranchInsertError();
	}
	branches[location] = new Branch(location, capacity);
}

// add branch from branches map
void MainOffice::removeBranch(const string& location)
{
	map<string, Branch*>::iterator itr;
	for (itr = branches.begin(); itr != branches.end(); itr++) {
		if ((*itr).first == location)
		{
			(*itr).second->~Branch();
			branches.erase(location);
			return;
		}
	}
	throw NonExistingBranchRemoveError();
}

// get specefic branch by its location if exists
Branch& MainOffice::getBranch(const string& location)
{
	map<string, Branch*>::iterator itr;
	for (itr = branches.begin(); itr != branches.end(); itr++) {
		if ((*itr).first == location)
		{
			return *(*itr).second;
		}
	}
	throw NonExistingBranchRetrieveError();
}

// compare between two branches by their locations
int compareLocations(const Branch* b1, const Branch* b2) {
	return (*b1).getLocation() < (*b2).getLocation();
}

// compare between two branches by their values
int compareValues(const Branch* b1, const Branch* b2) {
	if ((*b1).getTotalPrices() == (*b2).getTotalPrices()) {
		return (*b1).getLocation() < (*b2).getLocation();
	}
	return (*b1).getTotalPrices() < (*b2).getTotalPrices();
}

// print ordered Branches by location 
void MainOffice::printBranchesByLocation(void (func)(const Branch&)) {
	printBranches(func, compareLocations);
}

// print ordered Branches by value
void MainOffice::printBranchesByValue(void (func)(const Branch&)) {
	printBranches(func, compareValues);
}

// printing help method
void MainOffice::printBranches(void (func)(const Branch&),int (compareFunc)(const Branch*, const Branch*)) {
	cout << "There are " << branches.size() << " branches in Main Office: " << endl;
	vector<Branch*> branchesCpy;

	map<string, Branch*>::iterator it;
	for (it = branches.begin(); it != branches.end(); it++) {
		branchesCpy.push_back((*it).second);
	}
	std::sort(branchesCpy.begin(), branchesCpy.end(), compareFunc);

	vector<Branch*>::iterator itr;
	for (itr = branchesCpy.begin(); itr != branchesCpy.end(); itr++) {
		cout << (**itr).getLocation() << " : Item count: " << (**itr).getItemsNumber() <<
			", Total Value: " << (**itr).getTotalPrices() << endl;
		func(**itr);
	}
}
