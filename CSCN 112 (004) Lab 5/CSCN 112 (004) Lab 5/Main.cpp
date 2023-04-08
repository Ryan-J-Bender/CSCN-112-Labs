// CSCN 112 (004) Lab 5 -- Ryan Bender -- Messaging System


/*									Algorithm

	1.	Make menu
	2.	Create menu while loop with sentinel exit variable
	3.	Vigenere class gets, sets, encrypt, and decrypt
	4.	Message class gets, sets, encrypt word, and decrypt word
	5.	File in and tokenization,
	6.	Push words into vector
	7.	Display encrypted/decrypted words from vector to cout
	8.	User choice to output to file
	9.	Clean up code (make it pretty: formatting, whitespace, etc.)
	10.	Add/Delete comments
	11.	Check rubric and make additional changes

*/


#include "Message.h" // Message header file
#include <iomanip> // Setw, setprecision, etc.


using namespace std;

// Fstream operator definitions
ifstream infile;
ofstream outfile;

//Function Prototypes
void mainMenu(); // Prints menu
void katze();	// ;) *wink*
void quit();	// Closes files, exits program
void choiceCheck(int);	// Checks user menu choice
int typeCheck(string);	// Returns value to determine string vs int type
bool stringCheck(string, bool);	// Checks the contents of a string
void choiceOne();
void choiceTwo();


int main() {

	// Local Variables
	bool sentinel = false;
	bool katzeRan = false;
	
	int menuChoice = 0;

	string strChoice = "";

	// Menu Loop
	while (sentinel == false) {

		// Intro Header
		cout << "Welcome to the pattented WePaintHousesLLC Message Encryption Secure System for You (MESSY)" << endl << endl;

		mainMenu();

		cin >> strChoice;

		typeCheck(strChoice);

		if (typeCheck(strChoice) == 0) {

			if (stringCheck(strChoice, katzeRan) != false) {
				katzeRan = true;
			}
		}
		else if (typeCheck(strChoice) == 1) {

			menuChoice = stoi(strChoice);
		}

		cout << endl;

		choiceCheck(menuChoice);

		switch (menuChoice) {

		case 1:		// Choice to encrypt file: takes user input for input file name, encrypts, prompts for output file name, prints to file
				
			if (katzeRan == false) {
				choiceOne();
			}
			else {
				sentinel = true;
			}
			break;
		
		case 2:		// Choice to decrypt file: takes user input for input file name, decrypts, prompts for output file name, prints to file

			if (katzeRan == false) {
				choiceTwo();
			}
			else {
				sentinel = true;
			}
			break;
		
		case 3:		// Choice to quit: ensures that all files are closed and prints exit message
		{
			sentinel = true;
			quit();
		}
			break;
			
		default: // Case for when any input other than the menu options is given
		{
			if (katzeRan == false) { // Checks to see if cheeky little function ran

				cout << "ERROR. Invalid input. You must enter a positive number (within the menu choices). Please try again default." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else { // If cat function ran, exit program
				sentinel = true;
			}
			system("pause");
			system("CLS");
		}
			break;
		}
	}

	system("pause");
	return 0;
}

// Function Definitions

void mainMenu() { // Prints menu

	cout << right << setw(25) << "Vigenere Cypher" << endl
		<< right << setw(26) << "  Main Menu   " << endl << endl
		<< right << setw(26) << "1 - Encrypt File" << endl
		<< right << setw(26) << "2 - Decrypt File" << endl
		<< right << setw(18) << "3 - Quit" << endl << endl
		<< right << setw(26) << "Your selection:  ";
}

void quit() { // Closes files and presents exit message

	if (infile.is_open() || outfile.is_open()) {
		infile.close();
		outfile.close();
	}
	cout << "Thank you for using the pattented WePaintHousesLLC Message Encryption Secure System for You (MESSY)" << endl << endl;
}

int typeCheck(string str) {	// Checks whether a string contains only integer values

	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false) {
			return 0;
		}
		else {
			return 1;
		}
}

void choiceCheck(int x) { // Error checking for menu item inputs

	while (cin.fail() || x < 0 || x > 3) {

		// Continues as long as the cin stream is in a fail state or the num entered is less than 0 
		cout << "You must enter a positive number (within the menu choices). Please try again choicecheck: ";  // Re-prompt 
		cin.clear();   // Clear out the error state of the cin stream 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clears any leftover characters 
		cin >> x;  // Brings in a new value then tests the while condition again
		cout << endl;
	}
}

bool stringCheck(string str, bool k) { // Checks the input given at the menu. If it is not a valid input, error check. If cat, run katze

	bool exitLoop = false;

	while ((cin.fail() || str != "1" || str != "2" || str != "3") && exitLoop == false) {

		if (str == "cat" || str == "Cat" || str == "cAt" || str == "caT" || str == "CAt" || str == "cAT" || str == "CaT" || str == "CAT") {

			katze();
			k = true;
			exitLoop = true;
		}
		else {

			cin.clear();	// Clear out the error state of the cin stream
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Clears any leftover characters 
			cout << "You must enter a positive number (within the menu choice). Please try again stringcheck: ";	// Re-prompt 
			cin >> str;		// Brings in a new value then tests the while condition again
			cout << endl;
		}
	}
	return k;
}

void katze() { // Lovely little secret function that prints out a nice short story in either English or German :)

	vector<string> katze; // Vector to store lines of text

	string line;		// Stores the line of text as a string
	string choice = ""; // Stores user input choice for Ger vs Eng

	int i = 0; // Iterates in while loops

	cout << endl << "Would you like to read the tale of 'Der Katzenprinz' in English or the original Deutsch? (E/D): "; // Prompt user
	cin >> choice;
	cout << endl;

	while (!(choice == "E" || choice == "D" || choice == "e" || choice == "d")) { // Error check input

		cout << "Error. Invalid input. Please enter one of the choices. (E/D): ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}

	if (choice == "E" || choice == "e") { // Choice for English file

		infile.open("KatzE.txt");
		while (getline(infile, line)) {

			katze.push_back(line);
			cout << katze.at(i) << endl;
			i++;
		}
		infile.close();
	}
	else if (choice == "D" || choice == "d") { // Choice for German file

		infile.open("KatzD.txt");
		while (getline(infile, line)) {

			katze.push_back(line);
			cout << katze.at(i) << endl;
			i++;
		}
	}
}

void choiceOne() {

	{
		string key = "";
		string upperKey = "";
		string file = "";
		string fileName = "";
		string yORn = "";

		bool katzeRan = false;

		char wordArray[1000];

		char seperators[] = " ,\t\n";
		char* token = NULL;
		char* next_token = NULL;

		Message emsg; // Creates an object to be used during the case


		//										Key handling
		// Applies uppercase to each letter in the key string, spits the uppercase key back to the user
		cout << "Enter your secure key (Only characters A-Z are allowed within the key): ";
		cin >> key;
		cout << endl;
		emsg.setKey(key);
		upperKey = emsg.getKey();
		cout << "Your key is: " << upperKey << endl << endl;






		//										Input from file
		// Prompts user, opens a .txt file with the name given, and reads the first line into the char array
		cout << "Please enter the name of the file you'd like to encrypt: ";
		cin >> file;
		cout << endl;

		fileName = file.append(".txt");

		infile.open(fileName);

		while (!(infile.is_open())) { // Only allows user to open valid files

			cout << "ERROR. File not found. Please enter a valid file name: ";
			cin >> file;
			fileName = file.append(".txt");
			infile.open(fileName);
		}

		infile.getline(wordArray, 1000); // Brings in Decrypted text to char array

		// Tokenization
		token = strtok_s(wordArray, seperators, &next_token);
		while (token != NULL) {

			// Tokenizes the array of characters into words, and for each word, pushes the Encrypted word into the vector
			emsg.setWords(emsg.encryptWord(token));
			token = strtok_s(NULL, seperators, &next_token);
		}

		cout << "Encrypted Message: " << endl << endl;
		cout << emsg.outputString();		// Prints what is stored in the vector to console
		cout << endl << endl;







		//										Output to file
		cout << "Would you like to save your output to a file? (Y/N)  ";
		cin >> yORn;
		cout << endl;

		// Error checking for yes/no
		while (cin.fail() || !(yORn == "y" || yORn == "Y" || yORn == "n" || yORn == "N")) {

			cin.clear(); // Clears out error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clears any leftover characters 
			cout << "ERROR. Invalid input. Please try again. (Y/N) ";
			cin >> yORn;
			cout << endl;
		}
		if (yORn == "y" || yORn == "Y") {

			cout << "Please enter the name of the file where you'd like your Encrypted message: ";
			cin >> file;
			cout << endl;
		}

		// Output text to file
		fileName = file.append(".txt");

		outfile.open(fileName);

		outfile << emsg.outputString(); // Prints vector items to output file

		if (infile.is_open() || outfile.is_open()) { // Checks for open files, closes them
			infile.close();
			outfile.close();
		}
		system("pause");
		system("CLS");
	}
}

void choiceTwo() {
	{
		string key = "";
		string upperKey = "";
		string file = "";
		string fileName = "";
		string yORn = "";

		bool katzeRan = false;

		char wordArray[1000];

		char seperators[] = " ,\t\n";
		char* token = NULL;
		char* next_token = NULL;

		Message dmsg; // Creates an object to be used during the case


		//										Key handling
		// Applies uppercase to each letter in the key string, spits the uppercase key back to the user
		cout << "Enter your secure key (Only characters A-Z are allowed within the key): ";
		cin >> key;
		cout << endl;
		dmsg.setKey(key);
		upperKey = dmsg.getKey();
		cout << "Your key is: " << upperKey << endl << endl;






		//										Input from file
		// Prompts user, opens a .txt file with the name given, and reads the first line into the char array
		cout << "Please enter the name of the file you'd like to Decrypt: ";
		cin >> file;
		cout << endl;

		fileName = file.append(".txt");

		infile.open(fileName);

		while (!(infile.is_open())) { // Only allows user to open valid files

			cout << "ERROR. File not found. Please enter a valid file name: ";
			cin >> file;
			fileName = file.append(".txt");
			infile.open(fileName);
		}

		infile.getline(wordArray, 1000); // Brings in encrypted text to char array

		// Tokenization
		token = strtok_s(wordArray, seperators, &next_token);
		while (token != NULL) {

			// Tokenizes the array of characters into words, and for each word, pushes the decrypted word into the vector
			dmsg.setWords(dmsg.decryptWord(token));
			token = strtok_s(NULL, seperators, &next_token);
		}

		cout << "Decrypted Message: " << endl << endl;
		cout << dmsg.outputString();		// Prints what is stored in the vector to console
		cout << endl << endl;







		//										Output to file
		cout << "Would you like to save your output to a file? (Y/N)  ";
		cin >> yORn;
		cout << endl;

		// Error checking for yes/no
		while (cin.fail() || !(yORn == "y" || yORn == "Y" || yORn == "n" || yORn == "N")) {

			cin.clear(); // Clears out error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clears any leftover characters 
			cout << "ERROR. Invalid input. Please try again. (Y/N) ";
			cin >> yORn;
			cout << endl;
		}
		if (yORn == "y" || yORn == "Y") {

			cout << "Please enter the name of the file where you'd like your Decrypted message: ";
			cin >> file;
			cout << endl;
		}

		// Output text to file
		fileName = file.append(".txt");

		outfile.open(fileName);

		outfile << dmsg.outputString(); // Prints vector items to output file

		if (infile.is_open() || outfile.is_open()) { // Checks for open files, closes them
			infile.close();
			outfile.close();
		}
		system("pause");
		system("CLS");
	}
}