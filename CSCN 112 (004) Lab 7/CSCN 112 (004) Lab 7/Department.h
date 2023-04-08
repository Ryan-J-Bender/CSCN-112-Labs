#pragma once

#include "Employee.h"
#include "Manager.h"

class Department {

public:

	Department(); // Basic Constructor
	Department(float, int, std::string, float = 0); // 4 Argument constructor with default argument for profit
	~Department(); // Destructor

	void setProf(float); // Sets profit variable
	float getProf() const; // Returns profit

	void setCap(int); // Sets employee capacity
	int getCap() const; // Returns capacity

	void setCost(float); // Sets product cost
	float getCost() const; // Returns product cost

	void setName(std::string); // Sets dept. name
	std::string getName() const; // Returns dept. name

	void setManager(Manager); // Sets Manager object
	Manager getManager() const; // Returns Manager object

	void setEmployees(std::vector<Employee>); // Sets vector of employees
	std::vector<Employee> getEmployees() const; // Returns vector of employees

	Date inputDate(); // Takes user input for one date
	void tokenizeDate(char*, int&, int&, int&); // Tokenizes user input for one date

	void errorCheck(int); // Error checks an int input
	void errorCheck(float); // Error checks a float input
	void errorCheckJobs(int); // Error checks for valid input (0 or -1) when adding jobs to an employee

	void addManager(); // Takes user input for Manager object
	void addEmployee(); // Takes user input and adds Employee object to vector of employees
	void removeEmployee(int); // Removes an employee from the employee vector based on their id (position in vector)
	
	void calcProf(); // Calculates and sets prof variable to net profit

	void printDeptInfo(Department) const; // Prints dept. info (mamager and employee info as well as capacity and product costs)
	void printFinalInvoice(Department) const; // Prints out a final invoice with all costs and profits

private:

	float prof;
	float cost;

	int capacity;

	std::string name;

	Manager manager;

	std::vector<Employee> employees;

	float calcGross() const; // Returns gross income
	float calcTravelCost() const; // Returns cost due to travel
	float calcLaborCost() const; // Returns cost due to labor
	float calcAvgEmpRating() const; // Returns average employee customer service rating
};