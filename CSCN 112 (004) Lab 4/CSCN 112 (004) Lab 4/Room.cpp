#include "Room.h"
#include <iostream>
#include <vector>

Room::Room() { // Default constructor

	length = 0;
	width = 0;
	height = 0;
	coats = 0;
}

Room::Room(float l, float w, float h, int c) { // 4 argument constructor

	length = l;
	width = w;
	height = h;
	coats = c;
}

Room::~Room() {} // Destructor

float Room::volume() { // Returns the volume of the given room object

	return length * width * height;
}

float Room::area() const { // Returns the surface are of the given room object

	return 2 * (length * height + width * height);
}

float Room::paintGallons() const { // Calculates the number of gallons of paint necessary to paint each individual room

	return area() / 400;
}

float Room::totalGallons(std::vector<Room> houseRooms) const{

	int totalGallons = 0;


	for (int i = 0; i < houseRooms.size(); i++) {

		totalGallons += houseRooms.at(i).paintGallons();
	}

	return totalGallons;
}


void Room::setLength(float x) { // Prompts user and retrieves the room's length

	length = x;
}

void Room::setHeight(float x) { // Prompts user and retrieves the room's height

	height = x;
}

void Room::setWidth(float x) { // Prompts user and retrieves the room's width

	width = x;
}

void Room::setCoats(int c) {

	coats = c;
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

int Room::getCoats() const {

	return coats;
}