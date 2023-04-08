// cylinderType class. inherits from circleType

#pragma once

#include "circleType.h"

class cylinderType : public circleType {
public:

	cylinderType();
	cylinderType(double r, double h);
	~cylinderType();

	void setHeight(double h);
	double getHeight();

	double area();

	double volume();

	void print();

private:

	double height;
};
