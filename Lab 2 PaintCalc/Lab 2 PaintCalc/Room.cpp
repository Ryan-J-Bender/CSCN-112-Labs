#include <iostream>
#include "Room.h"


Room::Room() { // Default constructor

	float length = 0;
	float height = 0;
	float width = 0;
	float area = 0;
	float volume = 0;
	float paintGal = 0;

}

void Room::calcVolume() {

	volume = length * height * width; // The surface area of the walls in sq ft divided by the number of sq ft per gallon of paint

}

void Room::calcPaintedArea() { // Calculates the total surface are to be painted
	
	// Local Temp Variables
	float wallSet1;
	float wallSet2;
	float totalArea;
	float tempGal;

	wallSet1 = length * height * 2;
	wallSet2 = width * height * 2;

	totalArea = wallSet1 + wallSet2;
	area = totalArea;

	tempGal = ceil(area / 400);
	paintGal = tempGal;


}

void Room::printResults() const { // Prints results for the given variables

	system("CLS");

	std::cout << std::endl << "Length: " << length << " sq ft." << std::endl << "Height: " << height << " sq ft." << std::endl;
	std::cout << "Width: " << width << " sq ft." << std::endl << "Volume: " << volume << " cu ft." << std::endl << std::endl;
	std::cout << "Gallons of paint necessary: " << paintGal << "." << std::endl;

}

float Room::setLength() { // Prompts user and retrieves the room's length

	// Local Temp Variable
	float x;

	std::cout << "Please enter the room's length in feet: " << std::endl;
	std::cin >> x;

	while (!(x >= -1) || x == 0 || x < -1) { // Error Checking

		std::cout << "You must enter a positive number. Please try again. (-1 to exit)" << std::endl;  // Re-prompt 
		std::cin.clear();   // Clear the error state of the cin stream 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clears any and all leftover characters
		
		std::cin >> x;

	}

	length = x;
	return length;

}

float Room::setHeight() { // Prompts user and retrieves the room's height
	
	// Local Temp Variable
	float x;

	std::cout << "Please enter the room's height in feet: " << std::endl;
	std::cin >> x;

	while (!(x >= -1) || x == 0 || x < -1) { // Error Checking

		std::cout << "You must enter a positive number. Please try again. (-1 to exit)" << std::endl;  // Re-prompt 
		std::cin.clear();   // Clear the error state of the cin stream 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clears any and all leftover characters

		std::cin >> x;

	}

	height = x;
	return height;
}

float Room::setWidth() { // Prompts user and retrieves the room's width

	// Local Temp Variable
	float x;

	std::cout << "Please enter the room's width in feet: " << std::endl;
	std::cin >> x;

	while (!(x >= -1) || x == 0 || x < -1) { // Error Checking

		std::cout << "You must enter a positive number. Please try again. (-1 to exit)" << std::endl;  // Re-prompt 
		std::cin.clear();   // Clear the error state of the cin stream 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clears any and all leftover characters

		std::cin >> x;

	}

	width = x;
	return width;
}


float Room::getLength() const { // Returns the room's length

	return length;
}

float Room::getHeight() const { // Returns the room's height

	return height;
}

float Room::getWidth() const { // Returns the room's width

	return width;
}
