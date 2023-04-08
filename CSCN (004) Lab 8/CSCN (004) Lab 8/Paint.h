#pragma once

class Paint {
public:

	Paint() { // Default Constructor
		
		color = "";
		gloss_level = 0;
		numberOfCans = 0;

		std::cout << "Invoking the default Paint constructor." << std::endl;
	}

	Paint(std::string c, float n) { // 2 Argument constructor

		color = c;
		gloss_level = 0;
		numberOfCans = n;

		std::cout << "Invoking the two-argument Paint constructor." << std::endl;
	}

	Paint(std::string c, float gl, float n) { // 3 Argument constructor

		color = c;
		gloss_level = gl;
		numberOfCans = n;

		std::cout << "Invoking the two-argument Paint constructor." << std::endl;
	}

	virtual ~Paint() { // Default Destructor

		std::cout << "Invoking the default Paint destructor." << std::endl;
	}

	void setColor(std::string s) { // Sets color variable

		color = s;
	}

	std::string getColor() { // Returns color variable

		return color;
	}

	void setGlossLevel(float l) { // Sets gloss level

		gloss_level = l;
	}

	float getGlossLevel() { // Returns gloss level

		return gloss_level;
	}

	void setNumberOfCans(float n) { // Sets number of paint cans

		numberOfCans = n;
	}

	float getNumberOfCans() { // Returns the number of paint cans

		return numberOfCans;
	}

	virtual void help() = 0; // Virtual help function defined in derived classes


private:

	std::string color;
	
	float gloss_level;

	float numberOfCans;

};