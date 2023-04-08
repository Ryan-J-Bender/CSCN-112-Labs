#include <iostream> // Input and output to/from terminal
#include "Employee.h" // Header file
#include <vector> // Vector class type
#include <string> // String data type
#include <fstream> // Input and output to/from file
#include <algorithm> // Sort function

std::ofstream outFile;
std::ifstream inFile;

// Constructors: default & 5 argument
Employee::Employee() {

	id = "";
	name = "";
	city = "";
	fileName = "";

	std::vector<float> satisScore;
}

Employee::Employee(std::vector<float> satisScore, std::string id, std::string name, std::string city, std::string fileName) {
	
	id = "";
	name = "";
	city = "";
	fileName = "";
	
	std::vector<float> satisScore;
}


// Set functions: employee id, employee name, store city
void Employee::setID(std::string id) {
	
	std::string temp;
	std::cout << "Please enter the employee's ID: ";
	std::cin >> temp;

	id = temp;
}


void Employee::setName(std::string name) {

	std::string temp;

	std::cout << "Please enter the employee's name: ";
	std::cin >> temp;

	name = temp;
}

void Employee::setCity(std::string city) {

	std::string temp;

	std::cout << "Please enter the city in which the store is located: ";
	std::cin >> temp;

	city = temp;
}


// Add new customer satisfaction scores to the respective vector
void Employee::addScores(float inputScore, std::ofstream outFile) {

	float inputScore = 0;
	float x = 0;

	std::cout << "Please enter a customer satisfaction score (1-5): ";
	std::cin >> x;

	while (!(x >= 1) && x <= 5) { // Error Checking

		std::cout << "You must enter a positive number between 1 and 5. Please try again." << std::endl;  // Re-prompt 
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

	int avg = 0;
	int add = 0;
	
	for (auto& i : satisScore) {

		add += satisScore.at(i);
	}

	avg = add / satisScore.size();

	return avg;
}

float Employee::lowestScore() const {

	float min = 0;
	
	for (auto& i : satisScore) {

		if (min > i)
			min = i;
	}

	return min;
}

float Employee::highestScore() const {

	float max = 0;

	for (auto& i : satisScore) {

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


// Print functions: one for the main menu, one for the individual employee
void Employee::printMenu() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "                   Menu                   " << std::endl << std::endl;
	std::cout << " Current Employee: " << name << std::endl;
	std::cout << " 1 -	Switch/Open Employee File" << std::endl;
	std::cout << " 2 -	Creat New Employee" << std::endl;
	std::cout << " 3 -	Add Score to Current Employee" << std::endl;
	std::cout << " 4 -	Save Current Employee Info to File" << std::endl;
	std::cout << " 5 -	Print Current Employee Info" << std::endl;
	std::cout << " 6 -	Quit" << std::endl;
	std::cout << "------------------------------------------" << std::endl << std::endl;
	std::cout << "Please enter your menu choice: ";
}

void Employee::printEmployee() {

	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "               Employee Info               " << std::endl << std::endl;
	std::cout << "Employee Name: " << name << "." << std::endl;
	std::cout << "Lowest Score: " << lowestScore() << std::endl;
	std::cout << "Highest Score: " << highestScore() << std::endl;
	std::cout << "List of all recorded scores:" << std::endl;
	
	for (auto& i : satisScore) {
		
		std::cout << satisScore.at(i) << std::endl;
	}

	std::cout << "-------------------------------------------" << std::endl << std::endl;
	std::cout << "Please enter your menu choice: ";
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
