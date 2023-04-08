// Implementation file for the functions of the footBall class

#include "footBall.h"

footBall::footBall() {

	team1 = "";
	team2 = "";

	score1 = 0;
	score2 = 0;
}

footBall::footBall(std::string t1, std::string t2, int s1, int s2) { // Four argument constructer
	 // Set the private data member team1 to the string that was passed into the constructor
	//team1 = t1;

	// Set the private data member team2 to the string that was passed into the constructor
	team2 = t2;

	// Set the private data member score1 to the int that was passed into the constructor
	score1 = s1;

	// Set the private data member score2 to the int that was passed into the constructor
	score2 = s2;


}


// Function Definition
void footBall::setTeam1Name(std::string name) {

	team1 = name;

}

std::string footBall::getTeam1Name() const
{
	return team1;
}

void footBall::setTeam2Name() {

	std::cout << std::endl << "Please enter the name of the opponent: " << std::endl;
	getline(std::cin, team2);

}

std::string footBall::getTeam2Name() const
{
	return team2;
}

void footBall::setTeam1Score() {

	std::cout << std::endl << "Please enter " << team1 << "'s score: " << std::endl;
	std::cin >> score1;

	while (std::cin.fail() || score1 < 0 || score1 > 200) {

		std::cin.clear(); // Clears input error state
		std::cin.ignore(100000, '\n'); // Ignores anything left in excess

		std::cout << "Error bringing in score. Please try again: " << std::endl;
		std::cin >> score1;
	}
}

int footBall::getTeam1Score() const
{
	return score1;
}

void footBall::setTeam2Score() {

	std::cout << std::endl << "Please enter " << team2 << "'s score: " << std::endl;
	std::cin >> score2;

	while (std::cin.fail() || score2 < 0 || score2 > 200) {

		std::cin.clear(); // Clears input error state
		std::cin.ignore(100000, '\n'); // Ignores anything left in excess

		std::cout << "Error bringing in score. Please try again: " << std::endl;
		std::cin >> score2;
	}
}

int footBall::getTeam2Score() const
{
	return score2;
}

void footBall::printResults() const {

	// Print out results

	std::cout << team1 << ": " << score1 << std::endl;
	std::cout << team2 << ": " << score2 << std::endl;
	if (score1 == score2)
		std::cout << "Tiebreaker is needed. " << std::endl << std::endl;

	else if (score1 > score2)
		std::cout << "We win!" << std::endl << std::endl;

	else
		std::cout << team2 << " won." << std::endl << std::endl;

}
