#pragma once

#include <vector> // Vector class type
#include <iostream> // Input and output to/from terminal
#include <fstream> // Input and output to/from file

class Employee {

public:

	bool sentinel;

	Employee(); // Default constructor

	Employee(std::vector<float>& satisScore, std::string id, std::string name, std::string city, std::string fileName); // 5 Argument constructor

	void setID(); // Sets ID variable
	std::string getID() const; // Returns ID variable

	void setName(); // Sets the name variable
	std::string getName() const; // Returns the name variable

	void setCity(); // Sets the city variable
	std::string getCity() const; // Returns the city variable

	void resetVars();

	void addScores(); // Adds the sum total of all the scores
	void sortScores(); // Sort scores to be displayed least-greatest

	float averageScore() const; // Displays the average score for the employee
	float lowestScore() const; // Displays the lowers reported score
	float highestScore() const; // Displays the highest reported score

	int numScores() const; // Returns vector size

	void printEmployee(); // Prints Employee specific menu

	void writeFile(); // Clears the file and writes the values stored in the variables/vector into the file.
	void openFile(); // Opens an employee file
	void readFile(bool& sentinel); // Reads in values from the file and stores them in their respective variables/vector

	std::ofstream outFile;
	std::ifstream inFile;

private:

	std::string id;
	std::string name;
	std::string city;
	std::string fileName;

	std::vector<float> satisScore;
};