//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once

#include <map>
#include <string>
#include <algorithm>
#include "Branch.h"

using std::map;
using std::string;

//	SingletonMainOffice
class MainOffice
{
private:
	map<string, Branch*> branches;

	MainOffice()=default;
	~MainOffice();
public:

	// Singleton getIntance method 
	static MainOffice& getInstance();
	
	// methods to modify branches Map
	void addBranch(const string& location, int capacity);
	void removeBranch(const string& location);
	Branch& getBranch(const string& location);

	// methods to print branches
	void printBranches(void (func)(const Branch&), int (compareFunc)(const Branch*, const Branch*));
	void printBranchesByLocation(void (func)(const Branch&));
	void printBranchesByValue(void (func)(const Branch&));
};

