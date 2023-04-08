#pragma once

#include <vector> // Vector class type
#include <iostream> // Input and output to/from terminal
#include <fstream> // Input and output to/from file

std::ofstream outFile;
std::ifstream inFile;

class Employee {

public:

	Employee(); // Default constructor

	Employee(std::vector<float> satisScore, std::string id, std::string name, std::string city, std::string fileName);

	void setID(std::string id); // Sets ID variable
	std::string getID() const; // Returns ID variable

	void setName(std::string name); // Sets the name variable
	std::string getName() const; // Returns the name variable

	void setCity(std::string city); // Sets the city variable
	std::string getCity() const; // Returns the city variable

	void addScores(float inputScore, std::ofstream outFile); // Adds the sum total of all the scores
	void sortScores(); // Sort scores to be displayed least-greatest
	
	float averageScore() const; // Displays the average score for the employee
	float lowestScore() const; // Displays the lowers reported score
	float highestScore() const; // Displays the highest reported score

	int numScores() const; // Returns vector size

	void printMenu(); // Prints main menu
	void printEmployee(); // Prints Employee specific menu

private:
	
	std::string id;
	std::string name;
	std::string city;
	std::string fileName;

	std::vector<float> satisScore;
};