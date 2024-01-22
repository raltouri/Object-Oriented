//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once

#define ID 209424340

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

static int nextId = 0;

class Item;
typedef bool (*ComparePtr)(Item* item1,Item* item2);
class Item
{
	int price;
	string manufacturer;
	int id;

protected:
	string color;
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
	
	// comparing methods
	static bool itemCompare(Item* item1, Item* item2);
	static ComparePtr itemPtrCompare;

	friend bool operator<(const Item& item1, const Item& item2);
	friend bool operator>(const Item& item1, const Item& item2);
	friend bool operator<=(const Item& item1, const Item& item2);
	friend bool operator>=(const Item& item1, const Item& item2);
	friend bool operator==(const Item& item1, const Item& item2);

};
