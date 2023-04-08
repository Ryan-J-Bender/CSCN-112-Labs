#pragma once
#include <iostream> // cin, cout
#include <string>

// footBall game class definition

// Struct
class footBall
{
public:
	// Constructors
	footBall(); // Default constructor
	footBall(std::string, std::string, int, int); // Four argument constructor

	// Function Prototypes
	void setTeam1Name(std::string);
	std::string getTeam1Name() const;

	void setTeam2Name();
	std::string getTeam2Name() const;

	void setTeam1Score();
	int getTeam1Score() const;

	void setTeam2Score();
	int getTeam2Score() const;

	void printResults() const;

private:
	// Global variables
	std::string team1 = "";
	std::string team2 = "";

	int score1 = 0;
	int score2 = 0;

};

