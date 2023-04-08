#pragma once
#include "Paint.h"
#include <random>

class Eggshell : public Paint {
public:


	Eggshell() : Paint() { // Default constructor

		std::cout << "Invoking the default Eggshell Paint constructor." << std::endl;
	}

	Eggshell(std::string colorname, float num) : Paint(colorname, num) { // 2 Argument constructor

		setGlossLevel(randomGlossLevel());
		std::cout << "Invoking the 2 argument Eggshell Paint constructor." << std::endl;

	}

	Eggshell(std::string colorname, float gl, float num) : Paint(colorname, gl, num) { // 3 Argument constructor
	
		std::cout << "Invoking the 3 argument Eggshell Paint constructor." << std::endl;
	}

	~Eggshell() { // Default Destructor

		std::cout << "Invoking the default Eggshell Paint destructor." << std::endl;

	}

	float randomGlossLevel() { // Random number generator for gloss level

		std::random_device randomDevice;

		std::default_random_engine numberGenerator(randomDevice());

		std::uniform_real_distribution<double> distribution(10.5, 25);

		return distribution(numberGenerator);
	}

	void help() { // Help message for the style of paint

		system("CLS");
		std::cout << "Eggshell paint is more durable that flat paint and has slightly more luster.  This  type of paint is great for places that experience low or medium traffic." << std::endl;
	}
};
