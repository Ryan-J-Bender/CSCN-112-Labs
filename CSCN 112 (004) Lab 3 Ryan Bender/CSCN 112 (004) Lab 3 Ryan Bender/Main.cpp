// CSCN 112 (004) Lab 3 Customer Satisfaction Survey Tracker -- Ryan Bender. Creates an interactive menu that displays and inputs employee information with customer ratings.

/*											General Algorithm
	1. Create user interactive switch menu.
	2. Use switch cases to call respective functions, pause, clear, and return to the menu
	3. Use final switch case to exit the program
	4. Write Set functions to input and error check
	5. Write Get functions to return input variable values
	6. Make menu and display for Employee info
	7. Make function to read in variables/vector from the file
	8. Make function to clear the file, then write variables/vector back into the file
	9. File error checking
	10.	Test program
	11. Check rubric and address/add anything missing or incorrect

*/

/*									Option 1 Algorithm: Open/Switch Employee
*	1. Check to see if a file is open. If so, close it
*	2. Else, open the specified file
*	3. Clear the screen
*	4. Run the menu again
*/

/*									Option 2 Algorithm: Add New Employee
*	3. Prompt for name, city, and id
*	2. Take name input from the user, append with '.txt'
*	3. Output to a file of the appended name: name, city, id.
*/

/*									Option 3 Algorithm: Add Score to Current Employee
*	1. Prompt user for a score
*	2. Error check input
*	3. Add the score to a new spot in the score vector
*/

/*									Option 4 Algorithm: Save Current Employee into File
*	1. Clear the current employee file
*	2. Output on separate lines: name, city, id
*	3. Cycle and print line by line the values stored in the score vector
*/

/*									Option 5 Algorithm: Display Employee Info
*	1. Output the values stored in each variable for name, city, and id
*	2. Display average, high, and low scores, as stored in the vector
*	3. Sort vector and print
*/


#include <iostream> // Input/Output from/to terminal
#include <fstream> // Input/Output from/to file
#include "Employee.h" // Header file with class functions and private variables

using namespace std;

//Employee Class
Employee emp;

// Main Variables
int menuChoice = 0;
bool sentinel = false;

// Function Prototypes
void printMenu();

int main() {

	while (sentinel == false) {

		printMenu();

		switch (menuChoice) {

		case 1:

			std::system("CLS");

			if (emp.inFile.is_open() || emp.outFile.is_open()) {

				emp.inFile.close();
				emp.outFile.close();
			}

			emp.resetVars();
			emp.openFile();
			emp.readFile(sentinel);

			std::system("pause");
			std::system("CLS");

			break;

		case 2:

			std::system("CLS");
			
			if (emp.inFile.is_open()) {

				emp.inFile.close();
			}

			emp.resetVars();
			emp.setName();
			emp.setCity();
			emp.setID();

			std::system("pause");
			std::system("CLS");
			
			break;

		case 3:

			std::system("CLS");

			emp.addScores();

			std::system("Pause");
			std::system("CLS");

			break;

		case 4:

			std::system("CLS");

			emp.writeFile();

			std::system("pause");
			std::system("CLS");

			break;

		case 5:

			std::system("CLS");

			emp.sortScores();
			emp.printEmployee();

			std::system("pause");
			std::system("CLS");

			break;
		case 6:

			emp.outFile.close();
			emp.inFile.close();
			sentinel = true;

			break;
		}
	}

	std::system("pause");
	return 0;
}

// Function Definitions
void printMenu() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "                   Menu                   " << std::endl << std::endl;
	std::cout << " Current Employee: " << emp.getName() << std::endl;
	std::cout << " 1 -	Switch/Open Employee File" << std::endl;
	std::cout << " 2 -	Creat New Employee" << std::endl;
	std::cout << " 3 -	Add Score to Current Employee" << std::endl;
	std::cout << " 4 -	Save Current Employee Info to File" << std::endl;
	std::cout << " 5 -	Print Current Employee Info" << std::endl;
	std::cout << " 6 -	Quit" << std::endl;
	std::cout << "------------------------------------------" << std::endl << std::endl;
	std::cout << "Please enter your menu choice: ";

	cin >> menuChoice;

	while (cin.fail() || menuChoice < 0) {

		// continues as long as the cin stream is in a fail state or the num entered is less than 0 
		cout << "You must enter a positive number between 1 and 6. Please try again. " << endl;  // Re-prompt user
		cin.clear();  // Clear cin error state
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores any and all extra characters
		cin >> menuChoice;  // brings in a new value then tests the while condition again} 
	}
}