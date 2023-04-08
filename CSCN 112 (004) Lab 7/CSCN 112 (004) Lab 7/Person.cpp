#include "Person.h"

Person::Person() { // Basic constructor

	firstName = "";
	lastName = "";
}

Person::Person(std::string f, std::string l) { // 2 Argument constructor

	firstName = f;
	lastName = l;
}

Person::~Person() {} // Destructor

void Person::setFirstName(std::string s) { // Sets first name

	firstName = s;
}

std::string Person::getFirstName() const { // Returns first name

	return firstName;
}

void Person::setLastName(std::string s) { // Sets last name

	lastName = s;
}

std::string Person::getLastName() const { // Returns last name

	return lastName;
}

void Person::setBday(Date b) { // Sets birthday date

	Bday = b;
}

Date Person::getBday() const { // Returns birthday date

	return Bday;
}
