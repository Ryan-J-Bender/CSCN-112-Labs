#include "Department.h"

Department::Department() { // Basic construcot

	prof = 0;
	cost = 0;
	capacity = 0;
	name = "";
}

Department::Department(float c, int cap, std::string n, float p) { // 4 Argument constructor with default argument for profit 

	prof = p;
	cost = c;
	capacity = cap;
	name = n;
}

Department::~Department() {} // Destructor

void Department::setProf(float p) { // Sets profit

	prof = p;
}

float Department::getProf() const { // Returns profit

	return prof;
}

void Department::setCap(int c) { // Sets employee capacity

	capacity = c;
}

int Department::getCap() const { // Returns employee capacity

	return capacity;
}

void Department::setCost(float x) { // Sets product costs

	cost = x;
}

float Department::getCost() const { // Returns product costs

	return cost;
}

void Department::setName(std::string n) { // Sets dept. name

	name = n;
}

std::string Department::getName() const { // Returns dept. name

	return name;
}

void Department::setManager(Manager m) { // Sets variables for the Manager object

	manager.setSalary(m.getSalary());
	manager.setTitle(m.getTitle());
}

Manager Department::getManager() const { // Returns Manager object

	return manager;
}

void Department::setEmployees(std::vector<Employee> e) { // Sets employee vector

	employees = e;
}

std::vector<Employee> Department::getEmployees() const { // Returns employee vector

	return employees;
}

Date Department::inputDate() { // Function for user input for one date object

	int m, d, y;
	char charDate[20]; //holds date in char array 
	Date realDate;  // holds date after tokenization 

	std::cout << "date (mm/dd/yyy): ";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.getline(charDate, 10);

	//separates month, day, year 
	tokenizeDate(charDate, m, d, y);

	realDate.setDate(d, m, y); //sets the date  
	return realDate;
}

void Department::tokenizeDate(char* c, int& mon, int& day, int& year) { // Tokenizes user input into usable variables for date object

	char seps[] = "/-,:.";
	char* token = NULL;
	char* next_token = NULL;
	token = NULL;
	next_token = NULL;

	// Establish string and get the tokens:   
	token = strtok_s(c, seps, &next_token);
	mon = std::atoi(token);
	token = strtok_s(NULL, seps, &next_token);
	day = std::atoi(token);
	token = strtok_s(NULL, seps, &next_token);
	year = std::atoi(token);
}

void Department::errorCheck(int x) { // Error checks an int input

	while (std::cin.fail() || x < 0) {

		std::cout << "ERROR: Unacceptable input. Please enter a positive integer: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> x;
		std::cout << std::endl;
	}
}

void Department::errorCheck(float x) { // Error checks a float input

	while (std::cin.fail() || x < 0) {

		std::cout << "ERROR: Unacceptable input. Please enter a dollar ammount: $";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> x;
		std::cout << std::endl;
	}
}

void Department::errorCheckJobs(int x) { // Error checks menu input when adding jobs to an employee

	while (std::cin.fail() || (x != 0 && x != -1)) {

		std::cout << "ERROR: Unacceptable input. (0 to add jobs or -1 to exit): " << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> x;
	}
}

void Department::addManager() { // Takes user input, error checks, and sets all variables in the dept.'s Manager object

	int id = 0;
	float salary = 0;

	float profit = 0;

	std::string title = "";
	std::string fname = "";
	std::string lname = "";

	std::cout << "Please enter the manager's first name:  "; // Input first name
	std::cin >> fname;
	std::cout << std::endl;
	manager.setFirstName(fname);

	std::cout << "Please enter the manager's last name:   "; // Input last name
	std::cin >> lname;
	std::cout << std::endl;
	manager.setLastName(lname);

	std::cout << "Please enter the manager's birth "; // User input into birthday
	manager.setBday(inputDate());
	std::cout << std::endl;

	std::cout << "Please enter the manager's hire "; // User input into hire date
	manager.setHireDate(inputDate());
	std::cout << std::endl;

	std::cout << "Please enter the manager's promotion "; // User input into promotion date
	manager.setPromoDate(inputDate());
	std::cout << std::endl;

	// The functions for creating date objects with user input are a bit finnicky, so to avoid input stream errors, clear and ignore
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Please enter the manager's title: "; // Input Manager's title
	std::getline(std::cin, title);
	std::cout << std::endl;
	manager.setTitle(title);

	std::cout << "Please enter the manager's salary: $"; // Input Manager's salary
	std::cin >> salary;
	errorCheck(salary);
	manager.setSalary(salary);

}

void Department::addEmployee() { // Takes user input, error checks, and sets all variables in an Employee object, adds object to vector of employees

	int miles = 0;
	int id = 0;

	float rate = 0;

	int jobChoice = 0;

	float profit = 0;

	std::string fname = "";
	std::string lname = "";

	Employee e;

	std::cout << "Please enter the employee's first name:  "; // Input first name
	std::cin >> fname;
	std::cout << std::endl;
	e.setFirstName(fname);

	std::cout << "Please enter the employee's last name:  "; // Input last name
	std::cin >> lname;
	std::cout << std::endl;
	e.setLastName(lname);

	std::cout << "Please enter the employee's birth"; // User input into birthday
	e.setBday(inputDate());
	std::cout << std::endl;

	std::cout << "Please enter the employee's hire "; // User input into hire date
	e.setHireDate(inputDate());
	std::cout << std::endl;

	// The functions for creating date objects with user input are a bit finnicky, so to avoid input stream errors, clear and ignore
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Please enter the number of miles the employee has traveled for work: "; // Input miles traveled by employee for work
	std::cin >> miles;
	errorCheck(miles);
	std::cout << std::endl;
	e.setMilesTraveled(miles);

	std::cout << "Please enter the employee's customer service rating: "; // Input employee's customer service rating
	std::cin >> rate;
	errorCheck(rate);
	e.setRating(rate);
	std::cout << std::endl;


	while (jobChoice == 0) { // Adds jobs to employee object's vector of jobs and error checks
	
		std::cout << "Please enter 0 to add a job to the employee or -1 to quit: ";
		std::cin >> jobChoice;
		std::cout << std::endl;
		errorCheckJobs(jobChoice);
		
		if (jobChoice == 0) {

			std::cout << "Please enter a dollar ammount profit for the job: $";
			std::cin >> profit;
			errorCheck(profit);
			e.setJobs(profit);
			std::cout << std::endl;
		}
	}

	employees.push_back(e); // Adds employee to vector

	std::sort(employees.begin(), employees.end()); // Sorts employees in vector

	// Sets IDs to position in vector
	for (int i = 0; i < employees.size(); i++) { // This is likely not the most efficient way to set employee IDs, but there is a low max number of employees, so it should not greatly affect runtime.

		employees[i].setID(i);
	}
}

void Department::removeEmployee(int x) { // Removes one employee from the vector based on ID
	 
	employees.erase(employees.begin() + x);

	for (int i = 0; i < employees.size(); i++) {

		employees[i].setID(i);
	}
}

float Department::calcTravelCost() const { // Calculates travel costs

	float miles = 0;

	for(int i = 0; i < employees.size(); i++) { // Loops through employees, adds miles
		
		miles += employees[i].getMilesTraveled();
	}

	return miles * 0.87;
}

float Department::calcGross() const { // Calculates gross income
	
	float gross = 0;

	for (int i = 0; i < employees.size(); i++) { // Loops through employees jobs, adds income

		for (int j = 0; j < employees[i].getJobs().size(); j++) {

			gross += employees[i].getJobs().at(j);
		}
	}
	
	return gross;
}

float Department::calcLaborCost() const { // Calculates labor cost based on number of employees

	float laborcost = 0;

	laborcost = employees.size() * 18.50;

	return laborcost;
}

float Department::calcAvgEmpRating() const  { // Calculates average employee rating

	float avg = 0;

	for (int i = 0; i < employees.size(); i++) { // Loops through employees, adds ratings together, and divides by number of employees

		avg += employees[i].getRating();
	}

	avg = avg / employees.size();

	return avg;
}

void Department::calcProf() { // Sets profit equal to the net profit

	prof = calcGross() - calcTravelCost() - calcLaborCost() - cost;
}

void Department::printDeptInfo(Department d) const { // Lists the department name, capacity, product costs, manager, and employees

	std::cout << "___________________________________" << std::endl << std::endl
		<< "Department Info for " << d.getName() << std::endl
		<< "___________________________________" << std::endl << std::endl;

	std::cout << "Capacity: " << d.getCap() << std::endl;
	std::cout << "Product costs: $" << std::setprecision(2) << std::fixed << d.getCost() << std::endl << std::endl;

	if (manager.getFirstName() != "") { // If there is a manager, print manager
	
		std::cout << manager << std::endl << std::endl;
	}

	if (employees.size() > 0) { // If any employees exist, print message
	
		std::cout << "Current Employees:" << std::endl;
	}

	for (int i = 0; i < employees.size(); i++) { // Loops through employee vector, prints all elements

		std::cout << employees[i];
	}

	std::cout << "____________________________________________________________________" << std::endl << std::endl;
}

void Department::printFinalInvoice(Department d) const { // Prints final invoice neatly with individual costs, gross income, avg employee rating, and final net profit

	std::cout << "____________________________________________________________________" << std::endl << std::endl
		<< std::setw(43) << std::right << "WePaintHousesLLC" << std::endl
		<< "Department Profit Calculation for the " << d.getName() << " Department" << std::endl;

	if (d.getManager().getFirstName() != "") {
	
		std::cout << std::setw(37) << std::right << "Manager:     " << d.getManager().getFirstName() << " " << d.getManager().getLastName() << std::endl;
	}

	std::cout << std::setw(37) << std::right << "Total Income:     " << "$" << std::setw(12) << std::right << std::setprecision(2) << std::fixed << d.calcGross() << std::endl;
	std::cout << std::setw(37) << std::right << "Cost of Products:     " << "$" << std::setw(12) << std::right << std::setprecision(2) << std::fixed << d.getCost() << std::endl;
	std::cout << std::setw(37) << std::right << "Cost of Labor:     " << "$" << std::setw(12) << std::right << std::setprecision(2) << std::fixed << d.calcLaborCost() << std::endl;
	std::cout << std::setw(37) << std::right << "Cost of Travel:     " << "$" << std::setw(12) << std::right << std::setprecision(2) << std::fixed << d.calcTravelCost() << std::endl;
	std::cout << std::setw(37) << std::right << "Average Employee Rating:     " << " " << std::setw(12) << std::right << std::setprecision(1) << std::fixed << d.calcAvgEmpRating() << std::endl;
	std::cout << std::setw(37) << std::right << "Final Profit:     " << "$" << std::setw(12) << std::right << std::setprecision(2) << std::fixed << d.getProf() << std::endl;

	std::cout << "____________________________________________________________________" << std::endl;

}