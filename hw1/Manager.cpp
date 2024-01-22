//Moath Samara, 314630153.
//Rashad Altouri, 209424340.
#include "Manager.h"

// Manager's Class constructor.
// here we check if the input string is longer than 10 letters, if so we notify the user and set a default value.
Manager::Manager(int id , string firstName , string lastName, int birthYear) :id(id), birthYear(birthYear)
{
	if (firstName.length() > 10)
	{
		cout << "Manager first name length is too long" << endl;
		this->firstName = "~";
	}
	else
	{
		this->firstName = firstName;
	}
	if (lastName.length() > 10)
	{
		cout << "Manager last name length is too long" << endl;
		this->lastName = "~";
	}
	else
	{
		this->lastName = lastName;
	}
}
// Manager Id get method.
int Manager::getId() const
{
	return this->id;
}
// Manager FirstName get method.
string Manager::getFirstName() const
{
	return this->firstName;
}
// Manager LastName get method.
string Manager::getLastName() const
{
	return this->lastName;
}
// Manager BirthYear get method.
int Manager::getBirthYear() const
{
	return this->birthYear;
}
// Manager Id set method.
void Manager::setId(const int& newId)
{
	 this->id = newId;
}
// Manager FirstName set method.
void Manager::setFirstName(const string& newFirstName)
{
	if (newFirstName.length() > 10)
	{
		cout << "Manager first name length is too long" << endl;
		this->firstName = "~";
	}
	else 
	{
		this->firstName = newFirstName;
	}
}
// Manager LastName set method.
void Manager::setLastName(const string& newLastName)
{
	if (newLastName.length() > 10)
	{
		cout << "Manager last name length is too long" << endl;
		this->lastName = "~";
	}
	else 
	{
		this->lastName = newLastName;
	}
}
// Manager BirthYear set method.
void Manager::setBirthYear(const int& newBirthYear)
{
	 this->birthYear = newBirthYear;
}
// Manager's print method.
void Manager::print() const
{
	cout << "Printing manager: " << endl;
	cout << "Id : " << this->id << endl;
	cout << "First name : " << this->firstName << endl;
	cout << "Last name : " << this->lastName << endl;
	cout << "Birth year : " << this->birthYear << endl;
}