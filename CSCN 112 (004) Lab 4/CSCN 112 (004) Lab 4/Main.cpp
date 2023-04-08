// CSCN 112 (004) Invoice 

/*									Algorithm

	1.	Create header files and define classes
	2.	Add data members and function prototypes to classes
	3.	Use composition for House.h to make a vector using Room class objects
	4.	Define functions in implementation files for setting/getting
	5.	Make functions in House to print invoice and rooms in the vector
	6.	Make function to add rooms to room vector
	7.	Use switch case with a menu in main, error check user inputs
	8.	Review Code (fix errors, make pretty)
	9.	Check rubric and make appropriate edits

*/

#include <iostream> // Cout, Cin
#include <string> // Getline
#include "House.h" // Includes House class and Room class
#include <vector> // Create and manipulate vectors
#include <fstream> // Input and output to files

using namespace std;

// Function Prototypes
int error_Check_Int(int);
float error_Check_Num(float);
void printMenu();

int main() {

	// Output to file
	ofstream outFile;

	// Local variables
	float distance = 0;
	float l = 0;
	float w = 0;
	float h = 0;
	
	int c = 0;
	int maxRooms = 0;
	int size = 0;

	string name = "";
	string fileName = "";

	char input = 'z';
	char fileInput = 'z';

	bool sentinel = false;
	bool exitCon = false;

	// Prints out header, gathers general info with some error checking

	cout << "CSIS 112 (003) Lab 4: Invoice Generator -- Ryan Bender" << endl << endl;
	cout << "Please enter the name of the client for which you'd like to generate an invoice: ";
	getline(cin, name);
	cout << endl << "Please enter the  maximum number of rooms to be painted: ";
	cin >> maxRooms;
	error_Check_Int(maxRooms);
	vector<Room> hausRaum;
	House haus(hausRaum);

	cout << endl << "Please enter how far (in miles) the client is from the store: ";
	cin >> distance;
	error_Check_Num(distance);


	// While loop runs menu, exits when given proper conditions
	while (sentinel == false) {

		system("CLS");
		printMenu();
		cin >> input;

		system("CLS");
		switch (input) {

		case 'z': case 'Z': // Gives error message if no new value is passed into the input

			cout << "Input not recorded. Please try again." << endl;
			system("pause");

			break;

		case 'a': case 'A': // Takes user input for a room, error checks it, and adds a room to the vector

			if (size == maxRooms) {

				cout << "The maximum number of rooms has been reached. No further rooms are available." << endl;
			}
			else {

				cout << "Please enter the room's length in feet: ";
				cin >> l;
				error_Check_Num(l);

				cout << "Please enter the room's width in feet: ";
				cin >> w;
				error_Check_Num(w);
				cout << "Please enter the room's height in feet: ";
				cin >> h;
				error_Check_Num(h);
				cout << "Please enter the number of coats required for the room: ";
				cin >> c;
				error_Check_Int(c);

				haus.addRoom(l, w, h, c);

				size++;
			}

		
			system("pause");

			break;

		case 'l': case 'L': // Lists all rooms in the vector with their pertinent data

			haus.showRooms(name, maxRooms, distance);

			system("pause");

			break;

		case 'q': case 'Q': // Prints out invoice, gives the option for the invoice to be printed to file, exits

			haus.printInvoice(name);

			cout << endl << "Would you like to save your invoice to a file? (Y/N)	";
			cin >> fileInput;
			cout << endl;

			while (exitCon == false) {

				// Check for  applicaple response, print error

				if (fileInput == 'y' || fileInput == 'Y') {

					haus.printInvoiceToFile(name);

					exitCon = true;
					sentinel = true;
				}
				else if (fileInput == 'n' || fileInput == 'N') {

					exitCon = true;
					sentinel = true;
				}
				else {

					cout << "Inappropriate input. Please try again: ";
					cin >> fileInput;
				}
			}
			
			sentinel == true;
			
			break;

		default: // If none of the menu choices are passed into the user input variable, error message is displayed.

			cout << "Invalid input. Please try again." << endl;
			system("pause");

			break;
		}
	}
	
	cout << "___________________________________________________________" << endl;
	cout << "  Thank you for using the official WPH invoice generator!" << endl;
	cout << "___________________________________________________________" << endl;

	system("pause");
	return 0;
}

// Function Definitions

int error_Check_Int(int x) {

	while (cin.fail() || x < 0) {
		// continues as long as the cin stream is in a fail state or the num entered is less than 0 
		cout << "You must enter a positive number. Please try again. " << endl;  // re-prompt 
		cin.clear();   // clear out the error state of the cin stream 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clears any leftover characters 
		cin >> x;  // brings in a new value then tests the while condition again
	}
}

float error_Check_Num(float x) {

	while (cin.fail() || x < 0) {
		// continues as long as the cin stream is in a fail state or the num entered is less than 0 
		cout << "You must enter a positive number. Please try again. " << endl;  // re-prompt 
		cin.clear();   // clear out the error state of the cin stream 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clears any leftover characters 
		cin >> x;  // brings in a new value then tests the while condition again
	}
}

void printMenu() { // Prints out basic menu

	cout << "Please select from the following: " << endl << endl;
	cout << "A - Add a room to the house" << endl << endl;
	cout << "L - List all rooms currently in the house" << endl << endl;
	cout << "Q - Quit and prepare invoice" << endl << endl;
}