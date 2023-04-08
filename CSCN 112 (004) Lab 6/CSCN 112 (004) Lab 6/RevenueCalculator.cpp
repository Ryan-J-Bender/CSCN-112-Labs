// CSCN 112 (004) Lab 5: Monthly Revenue Calculator -- Ryan Bender

/*								Algorithm
	
	1.	Dynamically create an array of pointers to objects
	2.	Set each variable with user input
	3.	Error check user input
	4.	Loop through each object in the dynamic array
	5.	Print header for revenue invoice
	6.	Print each invoice for the given object
	7.	Delete all objects in dynamic array and delete array
	8.	Exit message
	9.	Clean up formatting, comments
	10.	Check rubric and edit

*/

// Include Statements
#include "CompletedJob.h" // Includes the Completed Job class header file (includes iostream, string)

// Function Prototypes
void printHead(std::string); // Pritns revenue header
double totalCost(CompletedJob**, int); // Calculates total cost from jobs
void errorCheck(int); // Error checks an int
void errorCheck(double); // Error checks a double

using namespace std;

int main() {

	// Local Variables
	int numJobs = 0;
	int paintedRooms = 0;
	int cans = 0;

	float miles = 0;

	string month = "";
	string clientName = "";


	cout << "Welcome to the WePaintHousesLLC Monthly Revenue Calculator!" << endl << endl;

	cout << "Please enter the month of the invoice: ";
	getline(cin, month);
	cout << endl;

	cout << "Please enter the number of jobs completed this month: ";
	cin >> numJobs;
	errorCheck(numJobs);
	cout << endl;

	CompletedJob** jobs = new CompletedJob * [numJobs]; // Creates a pointer to a dynamically created array of object pointers

	for (int i = 0; i < numJobs; i++) { // Loop through dynamic array, fill the variables in each object


		// For each instance, fill a slot of the dynamically created array with an object
		jobs[i] = new CompletedJob;


		// Input Client Name
		cout << "Please enter the name of the client: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline (cin, clientName);
		jobs[i]->setClientName(clientName);
		cout << endl;

		// Input number of rooms
		cout << "Please enter the number of rooms painted: ";
		cin >> paintedRooms;
		errorCheck(paintedRooms);
		jobs[i]->setRoomsPainted(paintedRooms);
		cout << endl;

		// Input number of paint cans
		cout << "Please enter the number of paint cans used: ";
		cin >> cans;
		errorCheck(cans);
		jobs[i]->setCanNum(cans);
		cout << endl;

		// Input mileage
		cout << "Please enter the number of miles traveled: ";
		cin >> miles;
		errorCheck(miles);
		jobs[i]->setMileage(miles);
		cout << endl;
		
		system("CLS");
		cout << "Welcome to the WePaintHousesLLC Monthly Revenue Calculator!" << endl << endl;
	}

	printHead(month); // Prints header

	// Prints each job's invoice
	for (int i = 0; i < numJobs; i++) {

		jobs[i]->printInvoice();
	}

	// Output total revenue from the jobs on the month's invoice
	cout << "Total Monthly Revenue" << setw(32) << right << setprecision(2) << totalCost(jobs, numJobs) << endl; 
	cout << "_____________________________________________________" << endl;


	for (int i = 0; i < numJobs; i++) { // Cycles through the dynamically created array and deallocates each element
								
		jobs[i] = NULL;
		delete[] jobs[i];
	}
	delete[] jobs; // Deletes final pointer

	system("pause");
	return 0;
}

void printHead(string m) { // Prints header for revenue invoice

	std::cout << "_____________________________________________________" << std::endl;
	std::cout << std::right << std::setw(35) << "WePaintHousesLLC" << std::endl;
	std::cout << std::right << std::setw(27 + (m.length() / 2)) << "Revenue for " << m << std::endl;
	std::cout << "_____________________________________________________" << std::endl << std::endl;

	std::cout << std::endl << "WePaintHousesLLC" << std::endl;
	std::cout << "1971 University Blvd" << std::endl;
	std::cout << "Lynchburg, VA 24502" << std::endl;
	std::cout << "(434) - 455 - 4545" << std::endl;
	std::cout << "wepainthousesllc.com" << std::endl << std::endl;

	std::cout << "_____________________________________________________" << std::endl << std::endl;
}

double totalCost(CompletedJob **t, int size) { // Calculates total revenue from jobs

	double total = 0;

	for (int i = 0; i < size; i++) { // Iterate through jobs and add totals to total variable

		total += t[i]->calculateTotal();
	}

	return total;
}

void errorCheck(int x) { // Error Checks int

	while (cin.fail() || x < 0) {
		// continues as long as the cin stream is in a fail state or the num entered is less than 0 
		cout << "You must enter a positive integer. Please try again. " << endl;  // re-prompt 
		cin.clear();   // clear out the error state of the cin stream 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clears any leftover characters 
		cin >> x;  // brings in a new value then tests the while condition again
	}
}

void errorCheck(double x) { // Error Checks double

	while (cin.fail() || x < 0) {
		// continues as long as the cin stream is in a fail state or the num entered is less than 0 
		cout << "You must enter a positive number. Please try again. " << endl;  // re-prompt 
		cin.clear();   // clear out the error state of the cin stream 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clears any leftover characters 
		cin >> x;  // brings in a new value then tests the while condition again
	}
}
