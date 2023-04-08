// CSCN (004) Lab 8 -- Paint Inventory Manager -- Ryan Bender

/*										Algorithm

	1. Create base class with correct virtuality
	2. Create derived classes
	3. Implement inheritence and define virtual functions
	4. Develop Switch case menus
	5. Define functions for menu operations
	6. Implement error checking for user inputs
	7. Review and document
	8. Format
	9. Check Rubric
	10. Make any necessary changes

*/



// Includes
#include <iostream> // Cin, cout, etc.
#include <fstream> // File input and output
#include <iomanip> // Setw, setprecision, etc.
#include "HighGloss.h" // High Gloss Paint class header file
#include "Eggshell.h" // Eggshell Paint class header file
#include "Flat.h" // Flat Paint class header file
#include "SemiGloss.h" // Semi-Gloss Paint class header file
#include "Satin.h" // Satin Paint class header file

using namespace std;

// Function Prototypes

void printFirstMenu(bool); // Prints the menu through which the user adds paints to the array. (boolean to tell whether or not the user should be able to input from a file)
void printMainMenu(); // Prints main menu options
void errorCheck(int, bool); // Error checks menu input with boolean to check for the possible menu options (6 unless file entry is unavailable)
void errorCheck(float); // Error checking for paint can ammounts
void errorCheck(int);
void currentInventory(Paint*[7]); // Prints out the current inventory stored in the array of paints
void printToFile(string, Paint*[7]); // Prints out inventory into usable file
bool inputFromFile(Paint*[7]); // Takes input from a given file, creates the correct Paint objects and stores them in the Paint array



int main() {

	// Local Variables
	
	bool sentinel = false; // Tells whether or not the program should remain in a given menu loop (true to exit loop)

	bool menuHasRun = false; // If the first menu has run, the number of menu options should be 5. If it has not, there is a 6th option

	bool exit = false; // Allows for pre-emptive program exitting

	int menuChoice = 0; // Variable to store all menu inputs from user

	Paint *paints[7]; // Array of Paint objects

	string colorname = ""; // User input for color
	string filename = ""; // Input from user for file name

	float canNum = 0; // Number of paint cans input by user

	while (sentinel == false) {

		int i = 0; // Iterator

		printFirstMenu(menuHasRun); // Prints the first menu with paint options (6th option the first time the menu is run)

		cin >> menuChoice; // Input menu choice
		cout << endl; 
		errorCheck(menuChoice, menuHasRun); // Error check user menu input

		switch (menuChoice) {

		case 1: // Menu option to create a Flat paint object

			cout << "Please enter the color of the paint: ";

			cin >> colorname;
			cout << endl;

			cout << "Please enter the number of paint cans in stock: ";

			cin >> canNum;
			cout << endl;
			errorCheck(canNum);

			paints[i] = new Flat(colorname, canNum);

			i++;

			system("pause");
			system("CLS");
			break;

		case 2: // Menu option to create an Eggshell paint object

			cout << "Please enter the color of the paint: ";

			cin >> colorname;
			cout << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please enter the number of paint cans in stock: ";

			cin >> canNum;
			cout << endl;
			errorCheck(canNum);

			paints[i] = new Eggshell(colorname, canNum);

			i++;

			system("pause");
			system("CLS");
			break;

		case 3: // Menu option to create a Satin paint object

			cout << "Please enter the color of the paint: ";

			cin >> colorname;
			cout << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Please enter the number of paint cans in stock: ";

			cin >> canNum;
			cout << endl;
			errorCheck(canNum);

			paints[i] = new Satin(colorname, canNum);

			i++;

			system("pause");
			system("CLS");
			break;

		case 4:  // Menu option to create a Semi-Gloss paint object

			cout << "Please enter the color of the paint: ";

			cin >> colorname;
			cout << endl;

			cout << "Please enter the number of paint cans in stock: ";

			cin >> canNum;
			cout << endl;
			errorCheck(canNum);

			paints[i] = new SemiGloss(colorname, canNum);

			i++;

			system("pause");
			system("CLS");
			break;

		case 5:  // Menu option to create a High Gloss paint object

			cout << "Please enter the color of the paint: ";

			cin >> colorname;
			cout << endl;

			cout << "Please enter the number of paint cans in stock: ";

			cin >> canNum;
			cout << endl;
			errorCheck(canNum);

			paints[i] = new HighGloss(colorname, canNum);

			i++;

			system("pause");
			system("CLS");
			break;

		case 6: // Inputs indices from a file into the array

			if (inputFromFile(paints)) { // If input ran successfully, carry on to main menu, else exit program
			
				exit = false;
			}
			else {

				exit = true;
			}

			sentinel = true;

			system("pause");
			system("CLS");
			break;

		default: // Catches any other, unexpected input

			cout << "Error. Invalid Input. Please try again: ";

			system("pause");
			system("CLS");
			break;

		}

		if (i > 0) { // If the menu has run, set bool to true

			menuHasRun = true;
		}

		if (i >= 7) { // Exit menu loop if array has been filled

			sentinel = true;
		}

	}

	sentinel = false; // Resets sentinel value between menus

	while (sentinel == false && exit == false) {

		printMainMenu();

		cin >> menuChoice; // Input from user
		cout << endl;
		errorCheck(menuChoice, menuHasRun); // Error checking user input menu choice

		switch (menuChoice) {

		case 1: // Adjusts paint inventory

			menuChoice = 0;

			cout << "Please enter the number for the paint you'd like to edit: ";
			cin >> menuChoice;
			cout << endl;
			errorCheck(menuChoice);

			cout << "How many cans of this paint are in stock? ";
			cin >> canNum;
			cout << endl;
			errorCheck(canNum);

			paints[menuChoice - 1]->setNumberOfCans(canNum);

			system("pause");
			system("CLS");
			break;                          

		case 2: // View help for selection

			menuChoice = 0;

			cout << "Please enter the number for the Paint you'd like to review: ";
			cin >> menuChoice;
			errorCheck(menuChoice);

			paints[menuChoice]->help();

			system("pause");
			system("CLS");
			break;
		
		case 3: // Displays current inventory
		
			currentInventory(paints);

			system("pause");
			system("CLS");
			break;
		
		case 4: // Prints inventory into file usable by the program

			cout << "In what file would you like your inventory printed? ";
			getline(cin, filename);
		
			printToFile(filename, paints);

			system("pause");
			system("CLS");
			break;
		
		case 5: // Exits the program
		
			sentinel = true;
			system("pause");
			system("CLS");
			break;

		default: // Catches any unexpected input

			cout << "Invalid input. Please try again." << endl;

			system("pause");
			system("CLS");
			break;

		}
	}

//	delete[] paints;  NOTICE: COMMENTED OUT DEALLOCATION DUE TO THROWN EXCEPTION. I researched this exception online, and spoke to multiple of my classmates regarding the issue. All of this was to no avail.

	system("pause");
	return 0;
}

// Function Definitions

void printFirstMenu(bool can) { // Prints menu with paint options (6th paint option only if the user has not manually entered any paint)

	cout << "Please choose from the following options: " << endl << endl;

	cout << "   (1) Flat Paint " << endl
		<< "   (2) Eggshell Paint" << endl
		<< "   (3) Satin Paint" << endl
		<< "   (4) Semi-Gloss Paint" << endl
		<< "   (5) High-Gloss Paint" << endl;

	if (can == false) {

		cout << "   (6) Read from File" << endl << endl;
	}
	else {
		cout << endl;
	}

	cout << "Menu Choice: ";
}

void printMainMenu() { // Prints main menu

	cout << "Please choose from the following options: " << endl << endl;

	cout << "   (1) Adjust Inventory " << endl
		<< "   (2) View Help for Selection" << endl
		<< "   (3) View Current Inventory" << endl
		<< "   (4) Print Inventory to a File" << endl
		<< "   (5) Quit" << endl << endl;

	cout << "Menu Choice: ";
}

void errorCheck(int x, bool b) { // Error Checks menu choices for 5 option and 6 option menus, depending on the boolean variable

	if (b == false) { // 6 option menu
		
		while (cin.fail() || x < 1 || x > 6) {
			cout << "ERROR: Unacceptable input. Please enter one of the menu choices: "; // Re-prompt user
			cin.clear(); // Clear error stream
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover characters
			cin >> x; // Re-input menu choice
			cout << endl;
		}
	}
	else { // 5 option menu

		while (cin.fail() || x < 1 || x > 5) {
			cout << "ERROR: Unacceptable input. Please enter one of the menu choices: "; // Re-prompt user
			cin.clear(); // Clear error stream
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover characters
			cin >> x; // Re-input menu choice
			cout << endl;
		}
	}
}

void errorCheck(float x) { // Error checking for number of cans

	while (cin.fail() || x < 0) {
		cout << "ERROR: Unacceptable input. Please enter a positive number: "; // Re-prompt user
		cin.clear(); // Clear error stream
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover characters
		cin >> x; // Re-input menu choice
		cout << endl;
	}
}

void errorCheck(int x) { // Error checking for option to choose a paint ID

	while (cin.fail() || x < 0 || x > 7) {
		cout << "ERROR: Unacceptable input. Please enter a positive integer: "; // Re-prompt user
		cin.clear(); // Clear error stream
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover characters
		cin >> x; // Re-input menu choice
		cout << endl;
	}
}

void currentInventory(Paint * paint[7]) { // Prints current paint inventory

	cout << "Now printing current inventory..." << endl << endl;
	cout << "#:" << setw(13) << "Paint Color" << setw(17) << "Number of Cans" << setw(17) << "Gloss Level(%)" << endl;
	cout << "1" << right << setw(14) << paint[0]->getColor() << setw(17) << paint[0]->getNumberOfCans() << setw(17) << setprecision(4) << paint[0]->getGlossLevel() << endl;
	cout << "2" << right << setw(14) << paint[1]->getColor() << setw(17) << paint[1]->getNumberOfCans() << setw(17) << setprecision(4) << paint[1]->getGlossLevel() << endl;
	cout << "3" << right << setw(14) << paint[2]->getColor() << setw(17) << paint[2]->getNumberOfCans() << setw(17) << setprecision(4) << paint[2]->getGlossLevel() << endl;
	cout << "4" << right << setw(14) << paint[3]->getColor() << setw(17) << paint[3]->getNumberOfCans() << setw(17) << setprecision(4) << paint[3]->getGlossLevel() << endl;
	cout << "5" << right << setw(14) << paint[4]->getColor() << setw(17) << paint[4]->getNumberOfCans() << setw(17) << setprecision(4) << paint[4]->getGlossLevel() << endl;
	cout << "6" << right << setw(14) << paint[5]->getColor() << setw(17) << paint[5]->getNumberOfCans() << setw(17) << setprecision(4) << paint[5]->getGlossLevel() << endl;
	cout << "7" << right << setw(14) << paint[6]->getColor() << setw(17) << paint[6]->getNumberOfCans() << setw(17) << setprecision(4) << paint[6]->getGlossLevel() << endl;

}

void printToFile(string fn, Paint * paint[7]) { // Prints indices of array to file in a format that the input from file can read
	
	ofstream out; // ofstream object

	out.open(fn.append(".txt")); // Opens user-specified file
	
	int i = 0; // Interator for follow while loop

	while (i < 7) { // Prints each index into file
	
		out << paint[i]->getColor() << endl
			<< paint[i]->getNumberOfCans() << endl
			<< paint[i]->getGlossLevel() << endl << endl;
		i++;
	}

	out.close(); // Closes file
}

bool inputFromFile(Paint* paint[7]) { // Takes in information from file, creates proper paint derived objects, and stores them into the array. If bad information or file formatting is encountered, the program terminates

	ifstream in; // In stream from file variable

	string color = ""; // Name of color taken from file
	string filename = "";

	float canNum = 0;
	float glossLevel = 0;

	int i = 0;
	int emptyLine = 0;

	bool sent = false;
	bool success = true;

	cin.clear(); // Clear error stream
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover characters

	cout << "Please enter the name of the file from which you'd like to read: ";
	getline(cin, filename); // User input for filename

	in.open(filename.append(".txt")); // Opens txt file with user specified name

	while (!(in.is_open())) { // Error checking for successful file opening

		in.close();

		cout << "File not found. Please try again: ";
		cin.clear();

		getline(cin, filename);
		in.open(filename.append(".txt"));
	}

	while (!(in.eof()) && (i < 7) && (sent == false)) { // Reads in information and terminates after reaching EOF, after filling all indices, or if interrupted by sentinel

		in >> color; // Reads in the paint's color

		if (in.fail() || color.empty()) { // Enter fail state if string is empty or if input is in fail state

			cout << "Error reading color in from file. Exiting.." << endl;
			sent = true;
			success = false;
		}

		in >> canNum; // Input number of paint cans

		if (in.fail() || canNum < 0) { // Enter fail state if number of cans is negative or if input is in fail state

			cout << "Error reading in from file. Invalid number of paint cans. Exiting..." << endl;
			sent = true;
			success = false;
		}

		in >> glossLevel; // Input gloss level

		if (in.fail() || glossLevel < 0) { // Enter fail state if gloss level is negative or if input is in fail state

			cout << "Error reading in from file. Invalid gloss level. Exiting..." << endl;
			sent = true;
			success = false;
		}

		// Checks gloss level range, creates the proper object, and stores it in the array

		if (glossLevel < 5.0 && glossLevel > 0.1) { 
			paint[i] = new Flat(color, glossLevel, canNum);
		}

		else if (glossLevel < 25 && glossLevel > 10.5) {
			paint[i] = new Eggshell(color, glossLevel, canNum);
		}

		else if (glossLevel < 35 && glossLevel > 25.5) {
			paint[i] = new Satin(color, glossLevel, canNum);
		}

		else if (glossLevel < 70 && glossLevel > 35.5) {
			paint[i] = new SemiGloss(color, glossLevel, canNum);
		}

		else if (glossLevel < 90 && glossLevel > 85) {
			paint[i] = new HighGloss(color, glossLevel, canNum);
		}

		else { // If gloss level is invalid, print error message and exit

			cout << "Error reading file. Invalid gloss level. Exiting..." << endl;
			sent = true;
			success = false;
		}

		i++; // Iterate to store objects in their peoper position in the array
	}
	
	in.close(); // Closes the file

	return success; // Returns whether or not the function ended in a fail or success state
}
