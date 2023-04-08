#pragma once

class Room {

public:

	// Function Prototypes
	Room(); // Default constructor

	void calcVolume(); // Calculates Volume
	void calcPaintedArea(); // Calculates surface area of the four walls
	
	float setLength(); // Takes user input for the room length
	float setHeight(); // Takes user input for the room height
	float setWidth(); // Takes user input for the room width

	void printResults() const; // Prints length, height, width, surface area, and necessary amount of paint for the four walls

	float getLength() const; // Returns length
	float getHeight() const; // Returns height
	float getWidth() const; // Returns width

private:
		
	// Class Variables
	float length;
	float height;
	float width;
	float area;
	float paintGal;
	float volume;

};