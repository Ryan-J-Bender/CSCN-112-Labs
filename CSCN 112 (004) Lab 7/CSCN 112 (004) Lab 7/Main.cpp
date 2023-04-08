// CSCN 112 (004) Lab 7 -- Ryan Bender -- Profit Calculator: output info for a branch of WePaintHousesLLC (manager, employees, and generated cost)

/*							Algorithm

	1.	Switch Case menu 
			add manager 
			add employee 
			remove employee
			list department info
			final invoice
	
	2. Person Class
			First Name
			Last Name
			Birthday (Date class object)
			Sets & gets

	3.	Manager Class (inherits from Person)
			Overloaded extraction operator (to print nicely)
			Salary
			Title
			ID (random number larger than possible employee IDs)
			Date Hired (Date class object)
			Promotion Date (Date class object)
			Sets and Gets

	4.	Employee Class (inherits from Person)
			Overloaded extraction operator (to print nicely)
			Overloaded less than operator (to properly sort by last name)
			ID
			Miles traveled for work
			Customer satisfaction rating
			Date Hired (Date class object)
			Jobs (vector of floats: each element is the dollar amount profited from a job)
			Sets & Gets

	5.	Date Class 
			Overloaded extraction operator (to print nicely)
			Initializes a date object with day, month, & year)
	
	6.	Department Class
			Net Profit
			Total Cost
			Capacity of Employees
			One Manager object
			Vector of Employee objects
			Functions for adding, removing employees
			Sort employees by last name
			Functions to calculate gross profit, travel costs, labor costs, product costs, net profit, and avg employee rating
			Print functions (list department info and final invoice)
			Functions to tokenize date object inputs
			Sets & gets

	7.	Main
			Switch case menu
			Function to print main menu
			Functions to error check character input (for switch case)
	
	8.	Review code, format nicely
	9.	Review rubric and make necessary changes

*/


// Includes
#include <iostream>
#include "Department.h"


using namespace std;

// Function Prototypes
void errorCheck(char); // Error checking for one character variable
void errorCheckCap(int); // Error checks capacity input
void printMenu(); // Prints main menu


int main() {

	// Local Variables

	bool sentinel = false;

	int id = 0;
	int cap = 0;

	float deptcost = 0;

	char menuChoice = {};

	std::string deptname = "";

	Department dept;

	// Department initialization questions and user input error checking

	cout << "Welcome to the WePaintHousesLLC Department Profit Calculator!" << endl << endl;

	cout << "Please enter the department's name: "; // User input and set department name
	getline(cin, deptname);
	cout << endl;
	dept.setName(deptname);

	cout << "Please enter the maximum # of employees in this dept. (Max of 50): "; // User input and set capacity
	cin >> cap;
	cout << endl;
	errorCheckCap(cap);
	dept.setCap(cap);

	cout << "Please enter the dollar amount of products this dept. has used: $"; // User input and set department product cost
	cin >> deptcost;
	cout << endl;
	dept.errorCheck(deptcost);
	dept.setCost(deptcost);

	while (sentinel == false) { // Menu While loop determined by boolean sentinel value

		system("pause");
		system("CLS");

		printMenu();
		cin >> menuChoice;
		cout << endl;
		errorCheck(menuChoice);


		switch (menuChoice) { // Menu Switch Case

		case 'M': case 'm': // Add manager Option

			if (dept.getManager().getFirstName() != "") { // Only adds a manager if there is not already a manager

				cout << "There is already a manager: " << dept.getManager().getFirstName() << " " << dept.getManager().getLastName() << endl;
			}
			else {
			
				dept.addManager();
			}

			break;

		case 'E': case 'e': // Add employee

			if (dept.getEmployees().size() < dept.getCap()) { // Adds an employee only if the maximum capacity is not met
				
				dept.addEmployee();
			}
			else {

				cout << "This department has reached capacity (" << dept.getCap() << "). No more can be added at this time." << endl;
			}

			break;

		case 'R': case 'r': // Remove employee

			cout << "Please enter the ID of the employee you'd like to remove: ";
			cin >> id;
			cout << endl;
			dept.errorCheck(id);

			if (id > dept.getEmployees().size()) { // Removes an employee based on their ID only if it is an element in vector, shifts all vector elements accordingly

				cout << "This employee does not exist." << endl;
			}
			else {
			
				dept.removeEmployee(id);
			}
			
			break;

		case 'L': case 'l': // List Dept info

			system("CLS");
			dept.printDeptInfo(dept);

			break;

		case 'P': case 'p': // Final Invoice

			system("CLS");

			dept.calcProf(); // Calculates the final net profit
			dept.printFinalInvoice(dept);
			sentinel = true; // Sets sentinel value to true to exit menu loop
			break;

		default: // If for some reason, an invalid input passes through to the switch case, an error message is displayed before looping the menu again

			cout << "Error reading input. Please try again." << endl;
			break;
		}
	}


	system("pause");
	return 0;
}

// Function Definitions

void errorCheck(char x) { // Error checking for whether the character input is one of the menu options

	char choices[] = {'M', 'E', 'R', 'L', 'P'}; // Valid choices

	bool choice = false;

	x = toupper(x); // Ensures input is uppercase

	for (int i = 0; i < sizeof choices; i++) { // Checks for if the input is one of the choices, returns true if so

		if (x == choices[i]) {

			choice = true;
		}
	}

	while (cin.fail() || choice == false) { // Loop to get valid input

		cout << "ERROR: Unacceptable input. Please enter one of the menu choices: "; // Re-prompt user
		cin.clear(); // Clear error stream
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover characters
		cin >> x; // Re-input menu choice
		cout << endl;

		x = toupper(x);

		for (int i = 0; i < sizeof choices; i++) { // Check menu choice for validity

			if (x == choices[i]) {

				choice = true;
			}
		}
	}
}

void errorCheckCap(int x) { // Error Checking for valid employee capacity (must not be >= 50)

	while (cin.fail() || x > 50) {

		cout << "ERROR: Unacceptable input. Please enter an integer (must be <= 50): ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> x;
		cout << endl;
	}
}

void printMenu() { // Prints main menu

	cout << "______________________________" << endl
		<< setw(18) << right << "Main Menu" << endl
		<< "     M -- Add a Manager" << endl
		<< "     E -- Add an Employee" << endl
		<< "     R -- Remove an Employee" << endl
		<< "     L -- List Dept. Info" << endl
		<< "     P -- Print Final Invoice" << endl
		<< "______________________________" << endl << endl
		<< "Menu Choice: ";
}
