#pragma once

#include <vector> // Vector object type

class Room {

public:

	Room(); // Default Constructor
	Room(float, float, float, int); // 4 argument constructor
	~Room(); // Destructor

	float volume(); // Calculates Volume
	float area() const; // Calculates surface area of the four walls
	float paintGallons() const; // Returns the number of gallons of paint necessary to paint the room
	float totalGallons(std::vector<Room>) const;

	void setLength(float); // Sets the room length
	void setHeight(float); // Sets the room height
	void setWidth(float); // Sets the width of the room
	void setCoats(int); // Sets the number of coats

	float getLength() const; // Returns length
	float getHeight() const; // Returns height
	float getWidth() const; // Returns width
	int getCoats() const;

private:

	float length;
	float width;
	float height;
	int coats;

};