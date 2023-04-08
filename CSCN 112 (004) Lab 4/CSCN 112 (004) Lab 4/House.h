#pragma once

#include <vector> // Adds vector object type
#include "Room.h" // Includes Room header file

class House {

public:
	House(); // Default constructor
	House(std::vector<Room>); // 1 argument constructor

	void showRooms(std::string n, int m, float d) const; // Prints length, height, width, surface area, and necessary amount of paint for the four walls
	int totalCoats() const; // Calculates the total coat number
	void addRoom(float, float, float, int); // Adds a room object to the vector
	void printInvoice(std::string) const; // Prints out an invoice for the house with cost by room and for travel
	void printInvoiceToFile(std::string) const; // Prints an invoice into a file

private:

	std::vector<Room> houseRooms;

	float ppg = 70.35; // Price per gallon of paint
	float hrRate = 18.50; // Price per hour of work

};