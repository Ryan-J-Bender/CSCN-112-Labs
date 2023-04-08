#pragma once
#include "Paint.h"
#include <random>

class Flat : public Paint {
public:

	Flat() : Paint() { // Default constructor

		std::cout << "Invoking the default Flat Paint constructor." << std::endl;
	}

	Flat(std::string colorname, float num) : Paint(colorname, num) { // 2 Argument constructor

		setGlossLevel(randomGlossLevel());
		std::cout << "Invoking the 2 argument Flat Paint constructor." << std::endl;

	}

	Flat(std::string colorname, float gl, float num) : Paint(colorname, gl, num) { // 3 Argument constructor

		std::cout << "Invoking the 3 argument Flat Paint constructor." << std::endl;
	}

	~Flat() { // Default Destructor

		std::cout << "Invoking the default Flat Paint destructor." << std::endl;

	}
	float randomGlossLevel() { // Random number generator for gloss level

		std::random_device randomDevice;

		std::default_random_engine numberGenerator(randomDevice());

		std::uniform_real_distribution<double> distribution(0.1, 5);

		return distribution(numberGenerator);
	}

	void help() { // Help message for the style of paint

		system("CLS");
		std::cout << "Flat paint is less durable with less shine but will provide the most coverage.  This type of paint is best for low traffic areas." << std::endl;
	}
};
