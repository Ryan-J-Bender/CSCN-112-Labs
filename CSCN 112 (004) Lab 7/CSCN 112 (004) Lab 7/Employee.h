#pragma once

#include "Person.h"
#include <vector>
#include <iomanip>
#include <algorithm>

class Employee : public Person {

	friend std::ostream& operator<<(std::ostream&, const Employee&);

public:

	Employee(); // Basic constructor
	Employee(int, int, float); // 3 Argument constructor
	~Employee(); // Destructor

	bool operator<(const Employee&);

	void setID(int); // Sets ID
	int getID() const; // Returns ID

	void setMilesTraveled(int); // Sets miles traveled 
	int getMilesTraveled() const; // Returns miles traveled

	void setRating(float); // Sets rating
	float getRating() const; // Returns rating

	void setJobs(float); // Sets jobs
	std::vector<float> getJobs() const; // returns jobs

	void setHireDate(Date); // Sets date hired
	Date getHireDate() const; // Returns date hired

private:

	int ID;
	int milesTraveled;

	float rating;

	std::vector<float> jobs; // Vector of dollar amounts profited from individual jobs


	Date hireDate;

};