#include "Manager.h"

std::ostream& operator<<(std::ostream& out, const Manager& m) { // Overloaded extraction operator for neat printing

	out << std::setw(35) << std::right << "Manager" << std::endl
		<< "____________________________________________________________________" << std::endl << std::endl
		<< "Name: " << std::setw(40) << std::left << "" << m.getFirstName() << " " << m.getLastName() << std::endl
		<< "Title:" << std::setw(40) << std::left << "" << m.getTitle() << std::endl
		<< "Manager ID:" << std::setw(35) << std::left  << "" << m.getID() << std::endl
		<< "Birth date:" << std::setw(35) << std::left << "" << m.getBday() << std::endl
		<< "Date Hired:" << std::setw(35) << std::left << "" << m.getHireDate() << std::endl
		<< "Promotion Date:" << std::setw(31) << std::left << "" << m.getPromoDate() << std::endl
		<< "Salary:" << std::setw(39) << std::left << std::setprecision(2) << std::fixed << "$" << m.getSalary() << std::endl;

	return out;
}

Manager::Manager() : Person() { // Basic Constructor

	salary = 0;
	title = "";
}

Manager::Manager(float s, std::string t) : Person() { // 3 Argument constructor

	salary = s;
	title = t;
}

Manager::~Manager() {} // Destructor

int Manager::getID() const { // Returns ID

	return ID;
}

void Manager::setSalary(float s) { // Sets yearly salary

	salary = s;
}

float Manager::getSalary() const { // Returns salary

	return salary;
}

void Manager::setTitle(std::string t) { // Sets job title

	title = t;
}

std::string Manager::getTitle() const { // Returns job title

	return title;
}

void Manager::setHireDate(Date h) { // Sets date hired

	hireDate = h;
}

Date Manager::getHireDate() const { // Returns date hired

	return hireDate;
}

void Manager::setPromoDate(Date p) { // Sets date for promotion

	promoDate = p;
}

Date Manager::getPromoDate() const { // Returns date for promotion

	return promoDate;
}