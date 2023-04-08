// CSCN 112 (004) Lab 2: Paint Calculator. Calculates the number of gallons of paint necessary based on the dimensions of a cubical room.

/*						Algorithm

	1. Promt user for dimensions of a room, as well as the exit key (-1).
	2.	Input dimensions of the room from the user into temporary variables.
	3.	Error check for letters and negative numbers (except -1, the exit key).
	4.	Neatly output the user input dimension.
	5.	Calculate dimensions of the first set of symmetrical walls.
	6.	Calculate dimensions of the second set of symmetrical walls.
	7.	Based on the dimensions of each set of walls, calculate paint amount by the nearest gallon.
	8.	Unless prompted by the user to exit, begin again with a new room.


*/

#include <iostream> // Cin, cout, etc.
#include "Room.h" // Header file including all functions

using namespace std;

int main () {

	// Make header
	cout << "__________________________________________________________________" << endl << endl;
	cout << "Calculate the number of gallons of paint necessary to paint a room" << endl;
	cout << "__________________________________________________________________" << endl << endl;

	Room room1; // Creates Room object

	do {

		if (room1.setLength() != -1 && room1.setHeight() != -1 && room1.setWidth() != -1) { // Calculates, pauses, clears, and prints results when input does not match the exit condition

			room1.calcVolume();
			room1.calcPaintedArea();
			room1.printResults();

			system("pause");
			system("CLS");
		}

	} while (room1.getLength() != -1 && room1.getWidth() != -1 && room1.getHeight() != -1); // Exits when the get functions return -1

	system("pause");
	return 0;
}