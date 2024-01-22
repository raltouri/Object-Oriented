//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

static int nextId = 0;

class Item
{
	int price;
	string manufacturer;
	int id;
public:
	/// Item constructor
	Item(int price = 0, string manufacturer = "~");
	/// Item destructor
	virtual ~Item();
	/// price getter
	int getPrice() const;
	/// manufacturer getter
	string getManufacturer() const;
	/// ID getter
	int getId() const;
	/// price setter
	void setPrice(const int& price);
	/// manufacturer setter
	void setManufacturer(const string& manufacturer);
	/// casting item into string
	virtual operator string() const = 0;
};

