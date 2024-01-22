//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#ifndef _MANAGER_H_
#define _MANAGER_H_

#include <stdio.h>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Manager
{
	int id;
	string firstName;
	string lastName;
	int birthYear;

public:
	// Constructor.
	Manager(int id = 0, string firstName = "~", string lastName = "~", int birthYear = 0);

	// Manager Id get method.
	int getId() const;
	// Manager FirstName get method.
	string getFirstName() const;
	// Manager LastName get method.
	string getLastName() const;
	// Manager BirthYear get method.
	int getBirthYear() const;

	// Manager Id set method.
	void setId(const int& newId);
	// Manager FirstName set method.
	void setFirstName(const string& newFirstName);
	// Manager LastName set method.
	void setLastName(const string& newLastName);
	// Manager BirthYear set method.
	void setBirthYear(const int& newBirthYear);

	// The Class print method.
	void print() const;


};

#endif