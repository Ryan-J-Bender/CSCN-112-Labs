// implementation file for cylinderType class

#include <iostream>
#include "cylinderType.h"
#include <cmath>

cylinderType::cylinderType() { // Basic constructor

	height = 0;
}

cylinderType::cylinderType(double r, double h): circleType(r) { // 2 Argument constructor

	height = h;
}

cylinderType::~cylinderType() {} // Destructor

void cylinderType::setHeight(double h) {

	height = h;
}

double cylinderType::getHeight() {

	return height;
}

double cylinderType::area() { // Calculates surface area of cylinder

	return 2 * circleType::area() + circumference() * height;
}

double cylinderType::volume() { // Calculates volume of cylinder

	return circleType::area() * height;
}

void cylinderType::print() { // Prints out variable values and calculated values

	std::cout << "Radius = " << getRadius() << std::endl
		<< "Height = " << getHeight() << std::endl
		<< "Area = " << area() << std::endl
		<< "Circumference = " << circumference() << std::endl
		<< "Volume = " << volume() << std::endl;
}