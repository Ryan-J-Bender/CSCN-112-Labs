#pragma once
#include "Paint.h"
#include <random>

class HighGloss : public Paint {
public:


	HighGloss() : Paint() { // Default constructor

		std::cout << "Invoking the default HighGloss Paint constructor." << std::endl;
	}

	HighGloss(std::string colorname, float num) : Paint(colorname, num) { // 2 Argument constructor

		setGlossLevel(randomGlossLevel());
		std::cout << "Invoking the 2 argument HighGloss Paint constructor." << std::endl;

	}

	HighGloss(std::string colorname, float gl, float num) : Paint(colorname, gl, num) { // 3 Argument constructor

		std::cout << "Invoking the 3 argument HighGloss Paint constructor." << std::endl;
	}

	~HighGloss() { // Default Destructor

		std::cout << "Invoking the default HighGloss Paint destructor." << std::endl;

	}


	float randomGlossLevel() { // Random number generator for gloss level

		std::random_device randomDevice;

		std::default_random_engine numberGenerator(randomDevice());

		std::uniform_real_distribution<double> distribution(85, 90);

		return distribution(numberGenerator);
	}


	void help() { // Help message for the style of paint

		system("CLS");
		std::cout << "High-glass is the shiniest type of paint we offer, and also the most durable and washable.It can also be used as an outdoor paint!It is best for doors, trim, and cabinetry as it can show many imperfections if applied incorrectly." << std::endl;
	}
};
