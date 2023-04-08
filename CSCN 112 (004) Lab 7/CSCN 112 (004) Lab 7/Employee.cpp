#include "Employee.h"

std::ostream& operator<<(std::ostream& out, const Employee& e) { // Overloaded extraction operator for neat printing

	out << "____________________________________________________________________" << std::endl << std::endl
		<< "Name:" << std::setw(46) << std::fixed << std::left << "" << e.getFirstName() << " " << e.getLastName() << std::endl
		<< "Employee ID:" << std::setw(39) << std::left << "" << "#" << e.getID() << std::endl
		<< "Birth Date:" << std::setw(40) << std::left << "" << e.getBday() << std::endl
		<< "Date Hired:" << std::setw(40) << std::left << "" << e.getHireDate() << std::endl
		<< "Miles Traveled:" << std::setw(36) << std::left << "" << e.getMilesTraveled() << std::endl
		<< "Employee Rating:" << std::setw(35) << std::left << "" << e.getRating() << std::endl
		<< "Completed Job Revenue:" << std::endl;

	for (int i = 0; i < e.getJobs().size(); i++) {

		out << std::setw(51) << std::left << "" << e.getJobs()[i] << std::endl;
	}

	return out;
}

Employee::Employee() { // Basic constructor 

	ID = 0;
	milesTraveled = 0;
	rating = 0;
}

Employee::Employee(int id, int m, float r) { // 3 Argument constructor {

	ID = id;
	milesTraveled = m;
	rating = r;
}

Employee::~Employee() {} // Destructor

bool Employee::operator<(const Employee& e) { // Overloaded less-than operator to be check which name is first alphabetically to use object in sort function
	
	bool lt = false;

	std::string a = getLastName();
	std::string b = e.getLastName();

	std::transform(a.begin(), a.end(), a.begin(), ::toupper); // To-uppers a string
	std::transform(b.begin(), b.end(), b.begin(), ::toupper);

	if (a.compare(b) >= 0) { // False if a is not first alphabetically

		lt = false;
	}
	else if (getLastName().compare(e.getLastName()) < 0) { // True if a is first alphabetically

		lt = true;
	}

	return lt;
}

void Employee::setID(int id) { // Sets ID 

	ID = id;
}

int Employee::getID() const { // Returns ID 

	return ID;
}

void Employee::setMilesTraveled(int m) { // Sets miles traveled

	milesTraveled = m;
}

int Employee::getMilesTraveled() const { // Returns miles traveled

	return milesTraveled;
}

void Employee::setRating(float r) { // Sets employee rating

	rating = r;
}

float Employee::getRating() const { // Returns employee rating

	return rating;
}

void Employee::setJobs(float x) { // Sets vector of jobs

	jobs.push_back(x);
}

std::vector<float> Employee::getJobs() const { // Returns vector of jobs

	return jobs;
}

void Employee::setHireDate(Date h) { // Sets date hired

	hireDate = h;
}

Date Employee::getHireDate() const { // Returns date hired

	return hireDate;
}