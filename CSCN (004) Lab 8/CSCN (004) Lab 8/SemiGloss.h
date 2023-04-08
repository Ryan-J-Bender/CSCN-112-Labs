#pragma once
#include "Paint.h"
#include <random>

class SemiGloss : public Paint {
public:

	SemiGloss() : Paint() { // Default constructor

		std::cout << "Invoking the default SemiGloss Paint constructor." << std::endl;
	}

	SemiGloss(std::string colorname, float num) : Paint(colorname, num) { // 2 Argument constructor

		setGlossLevel(randomGlossLevel());
		std::cout << "Invoking the 2 argument SemiGloss Paint constructor." << std::endl;

	}

	SemiGloss(std::string colorname, float gl, float num) : Paint(colorname, gl, num) { // 3 Argument constructor

		std::cout << "Invoking the 3 argument SemiGloss Paint constructor." << std::endl;
	}

	~SemiGloss() { // Default Destructor

		std::cout << "Invoking the default SemiGloss Paint destructor." << std::endl;

	}



	float randomGlossLevel() { // Random number generator for gloss level

		std::random_device randomDevice;

		std::default_random_engine numberGenerator(randomDevice());

		std::uniform_real_distribution<double> distribution(35.5, 70);

		return distribution(numberGenerator);
	}

	void help() { // Help message for the style of paint

		system("CLS");
		std::cout << "Semi-gloss is a very shiny and reflective paint.  It is durable and resistant to mildew, but will show more imperfections than flat, eggshell, or satin paint.This type of paint is great for rooms that have high moisture or high levels of wear and tear." << std::endl;
	}
};
