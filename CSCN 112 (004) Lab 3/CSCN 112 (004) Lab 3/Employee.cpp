#include <iostream> // Input and output to/from terminal
#include "Employee.h" // Header file
#include <vector> // Vector class type
#include <string> // String data type
#include <fstream> // Input and output to/from file
#include <algorithm> // Sort function
#include <iomanip> // Getline

// Constructors: default & 5 argument
Employee::Employee() {

	id = "";
	name = "";
	city = "";
	fileName = "";

	sentinel == false;

	std::vector<float> satisScore;
}

Employee::Employee(std::vector<float>& satisScore, std::string id, std::string name, std::string city, std::string fileName) {

	id = "";
	name = "";
	city = "";
	fileName = "";
}

// Input variables from file: id, name, city, and fills vector
void Employee::openFile() {

	std::string tempName = "";
	std::cin.ignore(1);
	std::cout << "Please enter the name of the user whose file you'd like to open: ";
	getline(std::cin, tempName);
	//std::cin >> tempName;

	fileName = tempName.append(".txt");

	inFile.open(fileName);

	while (inFile.fail()) { // Error Checking

		std::cout << "Error reading file name. Please try again: ";
		inFile.clear();
		inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(std::cin, tempName);

		fileName = tempName.append(".txt");

		inFile.open(fileName);
	}
}

void Employee::readFile(bool& sentinel) {

	float score = 0;
	int i = 0;
	std::string varType = "";

	getline(inFile, name);
	getline(inFile, city);
	getline(inFile, id);

	while (!inFile.eof() || inFile.fail()) {

		inFile >> score;

		if (score > 5 || score < 1) {

			inFile.clear();   // Clear the error state of the cin stream 
			inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clears any and all leftover characters

			sentinel = true;
		}
		else {

			satisScore.push_back(score);
		}

		i++;
	}

	if (sentinel == true) {

		std::cout << "ERROR. File is corrupted. Exiting Program." << std::endl;
	}
}

void Employee::writeFile() {

	std::string tempName;
	tempName = name;
	int x = 0;

	fileName = name.append(".txt");

	name = tempName;

	if (!(outFile.is_open())) {

		outFile.open(fileName);
	}
	else {

		outFile.open(fileName);
		outFile.open(fileName, std::ofstream::out | std::ofstream::trunc);
	}

	outFile << name << std::endl;
	outFile << city << std::endl;
	outFile << id;

	x = (satisScore.size() - 1);

	for (int i = 0; i < satisScore.size(); i++) {

		outFile << std::endl << satisScore.at(i);
	}

	std::cout << "Input was successfully written to " << fileName << std::endl << std::endl;
	outFile.close();
}

// Set functions: employee id, employee name, store city
void Employee::setID() {

	std::string temp;

	std::cout << "Please enter the employee's ID: ";

	while (getline(std::cin, temp).fail()) {

		getline(std::cin, temp).clear();
		getline(std::cin, temp).ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Error collecting input. Please try again: ";
		getline(std::cin, temp);

	}

	id = temp;
}


void Employee::setName() {

	std::string temp;

	std::cout << "Please enter the employee's name: ";
	getline(std::cin, temp);

	while (getline(std::cin, temp).fail()) {

		getline(std::cin, temp).clear();
		getline(std::cin, temp).ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Error collecting input. Please try again: ";
		getline(std::cin, temp);

	}

	name = temp;
}

void Employee::setCity() {

	std::string temp;

	std::cout << "Please enter the city in which the store is located: ";

	while (getline(std::cin, temp).fail()) {

		getline(std::cin, temp).clear();
		getline(std::cin, temp).ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Error collecting input. Please try again: ";
		getline(std::cin, temp);

	}
	city = temp;
}

// Function to reset variables
void Employee::resetVars() {

	name = "";
	city = "";
	id = "";
	fileName = "";

	satisScore.clear();
}



// Add new customer satisfaction scores to the respective vector
void Employee::addScores() {

	float inputScore = 0;
	float x = 0;

	std::cout << "Please enter a customer satisfaction score (1-5): ";
	std::cin >> x;

	while (!(x >= 1 && x <= 5)) { // Error Checking

		std::cout << "You must enter a positive number between 1 and 5. Please try again: ";  // Re-prompt 
		std::cin.clear();   // Clear the error state of the cin stream 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clears any and all leftover characters

		std::cin >> x;
	}

	inputScore = x;
	satisScore.push_back(inputScore);
}


// Vector calculations: avg, min, max, total numbers, sort
void Employee::sortScores() {

	std::sort(satisScore.begin(), satisScore.end());
}

float Employee::averageScore() const {

	float avg = 0;
	float add = 0;

	for (int i = 0; i < satisScore.size(); i++) {

		add += satisScore.at(i);
	}

	if (satisScore.size() == 0) {

		avg = 0;
	}
	else {

		avg = add / satisScore.size();
	}
	return avg;
}

float Employee::lowestScore() const {

	float min = 5;

	if (satisScore.size() == 0) {

		min = 0;
	}
	else {

		for (auto i : satisScore) {

			if (min > i)
				min = i;
		}
	}
	return min;
}

float Employee::highestScore() const {

	float max = 0;



	for (auto i : satisScore) {

		if (max < i)
			max = i;
	}

	return max;
}

int Employee::numScores() const {

	int x = 0;
	x = satisScore.size();

	return x;
}


// Print functions for the individual employee

void Employee::printEmployee() {

	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "               Employee Info               " << std::endl << std::endl;
	std::cout << "Employee Name: " << getName() << "." << std::endl;
	std::cout << "Employee City: " << getCity() << "." << std::endl;
	std::cout << "Employee ID: " << getID() << "." << std::endl << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "        Customer Satisfaction Info         " << std::endl << std::endl;
	std::cout << "Average score: " << averageScore() << std::endl;
	std::cout << "Lowest Score: " << lowestScore() << std::endl;
	std::cout << "Highest Score: " << highestScore() << std::endl;
	std::cout << "List of all recorded scores:" << std::endl;

	for (int i = 0; i < satisScore.size(); i++) {

		std::cout << satisScore.at(i) << std::endl;
	}

	std::cout << "-------------------------------------------" << std::endl << std::endl;
}


// Get functions: returns respective value
std::string Employee::getCity() const {

	return city;
}

std::string Employee::getName() const {

	return name;
}

std::string Employee::getID() const {

	return id;
}