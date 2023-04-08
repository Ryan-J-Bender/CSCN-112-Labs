#pragma once
#include "Paint.h"
#include <random>
#include <string>

class Satin : public Paint {
public:

	Satin() : Paint() { // Default constructor

		std::cout << "Invoking the default Satin Paint constructor." << std::endl;
	}

	Satin(std::string colorname, float num) : Paint(colorname, num) { // 2 Argument constructor

		setGlossLevel(randomGlossLevel());
		std::cout << "Invoking the 2 argument Satin Paint constructor." << std::endl;

	}

	Satin(std::string colorname, float gl, float num) : Paint(colorname, gl, num) { // 3 Argument constructor

		std::cout << "Invoking the 3 argument Satin Paint constructor." << std::endl;
	}

	~Satin() { // Default Destructor

		std::cout << "Invoking the default Satin Paint destructor." << std::endl;

	}

	float randomGlossLevel() { // Random number generator for gloss level

		std::random_device randomDevice;

		std::default_random_engine numberGenerator(randomDevice());

		std::uniform_real_distribution<double> distribution(25.5, 35);

		return distribution(numberGenerator);
	}

	void help() { // Help message for the style of paint

		system("CLS");
		std::cout << "Satin paint is the most common interior paint.It is easier to clean than flat or eggshell, but it can be very tricky to touch - up if errors are made during application.This type of paint is great for high - traffic areas." << std::endl;
	}
};
