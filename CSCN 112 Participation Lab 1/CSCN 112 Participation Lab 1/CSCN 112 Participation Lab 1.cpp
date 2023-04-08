// CSCN 112 Participation Lab 1 Football


/*						
						Algorithm
		
		1. Enter Name of team
		2. Enter name of opposing team
		3. Enter Opponent's score w/ error check
		4. Enter user score w/ error check
		5. Compare score and print who wins

*/

#include <iostream> // Used for cout and cin
#include <string> // Used for Getline
#include "footBall.h" // Access footBall library (header file)
#include <fstream> // Used for file inputs and outputs



footBall fileGame(ifstream& input);

using namespace std;

int main()
{
	cout << "CSCN 112 Participation lab 1: Football." << endl << endl;

	// Local Variables
	footBall game1; // Creates an object of the football game struct type
	footBall game2;

	// Game 1
	cout << "Please enter the name of your team: " << std::endl;
	string temp;
	getline(cin, temp);

	game1.setTeam1Name(temp);
	game1.setTeam2Name();
	game1.setTeam1Score();
	game1.setTeam2Score();
	game1.printResults();

	system("pause");
	system("CLS");
	cin.ignore();

	// Game 2
	game2.setTeam1Name(temp);
	game2.setTeam2Name();
	game2.setTeam1Score();
	game2.setTeam2Score();
	game2.printResults();

	system("pause");
	system("CLS");
	cin.ignore();

	// Game 3
	
	footBall game3("LU", "Georgia", 28, 34);
	game3.printResults();

	//// Need to open file
	//ifstream inFile;
	//inFile.open("Teams.txt");
	//string errorFileName = "";


	// Make sure file is open
	//while (!inFile) {

	//	cout << "Error opening file. Please try again. " << endl;
	//	inFile.clear();
	//	inFile.ignore(100000, '\n');
	//	cout << "Please enter the name of the file: " << endl;
	//	getline(cin, errorFileName);
	//	inFile.open(errorFileName);

	//}

	//// Create an array to hold game objects (max 3)
	//footBall footBallArray[3];

	//// Loop through array and set each element equal to the value returned by the function
	//for (int i = 0; i < 3; i++) {

	//	footBallArray[i] = fileGame(inFile);

	//}

	//// Close file at end
	//inFile.close();

	//// Loop through array and print
	//for (int i = 0; i < 3; i++) {

	//	footBallArray[i].printResults();

	//}








	system("pause");
	return 0;
}

footBall fileGame(ifstream& input) {
	// Bring in an ifstream value - bring in a file input
	// Assume the file is already open
	
	
	// Return the game to set equal to a game in main

	string input1 = "";
	string input2 = "";

	// Need to bring in two strings from that file
	getline(input, input1); // Brings in first name
	getline(input, input2); // Brings in first name

	// Create a football game object
	footBall tempGame(input1, input2, 0, 0);

	return tempGame;
	
}