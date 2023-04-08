#pragma once

#include "Date.h"
#include <string>

class Person {

public:

	Person(); // Basic Constructor
	Person(std::string, std::string); // 2 Argument constructor
	~Person(); // Destructor

	void setFirstName(std::string); // Sets first name 
	std::string getFirstName() const; // Returns first name
	
	void setLastName(std::string); // Sets last name
	std::string getLastName() const; // Returns last name

	void setBday(Date); // Sets birthday date
	Date getBday() const; // Returns birthday date

private:

	std::string firstName;
	std::string lastName;

	Date Bday;

};