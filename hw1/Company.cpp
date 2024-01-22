//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#include "Company.h"

// Company's Class constructor.
// we check if the name length is more than 10 letters if so we notify the user and set default value.
Company::Company(string name, int shopsNumber) : shopsNumber(shopsNumber)
{
	if (name.length() > 10)
	{
		cout << "Company name length is too long" << endl;
		this->name = "~";
	}
	else
	{
		this->name = name;
	}
}
// Company Name get method.
string Company::getName() const
{
	return this->name;
}
// Company ShopsNumber get method.
int Company::getShopsNumber() const
{
	return this->shopsNumber;
}
// Company Name set method.
// we check if the new name is longer than 10 letters, if so we notify the user and set a default value.
void Company::setName(const string& newName)
{
	if (newName.length() > 10)
	{
		cout << "Company name length is too long" << endl;
		this->name = "~";
	}
	else
	{
		this->name = newName;
	}
}
// Company addShop method.
// here we check if we reached the max number of shops, if so we notify the user and we do not add a shop.
void Company::addShop(const Shop& newShop)
{
	if (this->shopsNumber >= MAX_SHOPS_NUMBER)
	{
		cout << "There is no place for new shops!" << endl;
	}
	else
	{
		this->shops[this->shopsNumber] = newShop;
		this->shopsNumber++;
	}
}
// Company printShopsByName method.
// here we print the shops in order based on their name.
void Company::printShopsByName()
{
	string tmp;
	string string1;
	string string2;
	int i;
	int j;
	Shop tmp1;
	Shop tmp2;
	Shop tmpShops[MAX_SHOPS_NUMBER];
	if (this->shopsNumber == 0)  // here we check if there are no shops in the company.
	{
		cout << "There are no shops in this company." << endl;
		return;
	}
	else
	{
		cout << "There are " << this->shopsNumber << " shops in this company. The shops details are : " << endl;
	}
	// here we copy the actual shop to a temporary shop so we dont change the actual one.
	for (i = 0; i < this->shopsNumber; i++)
	{
		tmpShops[i] = this->shops[i];
	}
	// here we bubble sort the temporary shop based on the name of the shops.
	for (i = (this->shopsNumber - 1);i >= 0;i--)
	{
		for (j = 0; j < (this->shopsNumber - 1);j++)
		{
			tmp1 = tmpShops[j];
			tmp2 = tmpShops[j + 1];
			string1 = tmp1.getName();
			string2 = tmp2.getName();
			if (string1.compare(string2) > 0) // here we used compare method to compare between two strings.
			{
				tmpShops[j] = tmp2;
				tmpShops[j + 1] = tmp1;
			}
		}
	}
	// here we print the shops by name in order.
	for (i = 0;i < this->shopsNumber;i++)
	{
		cout << "Shop #" << i + 1 << " :" << endl;
		tmpShops[i].print();
		cout << endl;
	}
}
// Company printShopsByDay method.
// here we print the shops in order based on the Day(closedDay).
void Company::printShopsByDay()
{
	string tmp;
	int i;
	int j;
	Shop tmp1;
	Shop tmp2;
	Shop tmpShops[MAX_SHOPS_NUMBER];

	if (this->shopsNumber == 0) // here we check if there are no shops in the company.
	{
		cout << "There are no shops in this company." << endl;
		return;
	}
	else
	{
		cout << "There are " << this->shopsNumber << " shops in this company. The shops details are : " << endl;
	}
	// here we copy the actual shop to a temporary shop so we dont change the actual one.
	for (i = 0; i < this->shopsNumber; i++)
	{
		tmpShops[i] = this->shops[i];
	}
	// here we bubble sort the temporary shop based on the Day(closedDay) of the shops.
	for (i = (this->shopsNumber - 1);i >= 0;i--)
	{
		for (j = 0; j < (this->shopsNumber - 1);j++)
		{
			tmp1 = tmpShops[j];
			tmp2 = tmpShops[j + 1];
			if (tmp1.getClosedDay() > tmp2.getClosedDay()) // here we used compare method to compare between two strings.
			{
				tmpShops[j] = tmp2;
				tmpShops[j + 1] = tmp1;
			}
		}
	}
	// here we print the shops by Day(closedDay) in order.
	for (i = 0;i < this->shopsNumber;i++)
	{
		cout << "Shop #" << i + 1 << " :" << endl;
		tmpShops[i].print();
		cout << endl;
	}

}