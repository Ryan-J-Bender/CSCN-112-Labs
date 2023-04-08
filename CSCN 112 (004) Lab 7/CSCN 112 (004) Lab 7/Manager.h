#pragma once

#include "Person.h"
#include <iomanip>

class Manager : public Person {

	friend std::ostream& operator<<(std::ostream&, const Manager&); // Overloaded extraction operator for neat printing

public:

	Manager(); // Basic constructor
	Manager(float, std::string); // 3 Argument construcot
	~Manager(); // Destructor

	int getID() const; // Returns ID

	void setSalary(float); // Sets yearly salary
	float getSalary() const; // Returns salary

	void setTitle(std::string); // Sets job title
	std::string getTitle() const; // Returns job title

	void setHireDate(Date); // Sets date hired
	Date getHireDate() const; // Returns date hired

	void setPromoDate(Date); // Sets date for promotion
	Date getPromoDate() const; // Returns promotion date

private:

	const int ID = rand() + 100; // Random ID greater than 50 so as to not be confused with employee IDs

	float salary;

	std::string title;

	Date hireDate;
	Date promoDate;

};