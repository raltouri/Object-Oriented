//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "Item.h"

/// Item constructor
Item::Item(int price, string manufacturer): price(price),manufacturer(manufacturer)
{
	id = ++nextId;
}

/// Item destructor
Item::~Item()
{
	cout << "Throwing away an item" << endl;
}

/// price getter
int Item::getPrice() const
{
	return this->price;
}

/// manufacturer getter
string Item::getManufacturer() const
{
	return this->manufacturer;
}

/// ID getter
int Item::getId() const
{
	return this->id;
}

/// price setter
void Item::setPrice(const int& price)
{
	this->price = price;
}

/// manufacturer setter
void Item::setManufacturer(const string& manufacturer)
{
	this->manufacturer = manufacturer;
}

/// casting item into string
Item::operator string() const
{
	return "id " + std::to_string(this->getId()) + ": " + this->getManufacturer() + ", " + std::to_string(this->getPrice()) + "$";
}

// compare methods
bool Item::itemCompare(Item* item1, Item* item2)
{
	return (*item1) < (*item2);
}

ComparePtr Item::itemPtrCompare = &(Item::itemCompare);

bool operator<(const Item& item1, const Item& item2) {
	return item1.id < item2.id;
}
bool operator>(const Item& item1, const Item& item2) { /// she5booool
	return item1.id > item2.id;
}
bool operator<=(const Item& item1, const Item& item2) {
	return item1.id <= item2.id;
}
bool operator>=(const Item& item1, const Item& item2) {
	return item1.id >= item2.id;
}
bool operator==(const Item& item1, const Item& item2) {
	return item1.id == item2.id;
}