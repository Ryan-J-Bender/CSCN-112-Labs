#pragma once

#include "clockType.h"
#include <string>

class extClockType : public clockType {
public:

	extClockType();
	extClockType(int hours, int minutes, int seconds, std::string tZ);

    void setTime(int h, int m, int s, std::string tZ);

    void printTime() const; 
    //Function to print the time.
    //Postcondition: The time is printed in the form
    //               hh:mm:ss. 

    void incrementSeconds();
    //Function to increment the time by one second.
    //Postcondition: The time is incremented by one 
    //               second.
    //   If the before-increment time is 23:59:59, the 
    //   time is reset to 00:00:00.

    void incrementMinutes();
    //Function to increment the time by one minute.
    //Postcondition: The time is incremented by one 
    //               minute. 
    //   If the before-increment time is 23:59:53,
    //   the time is reset to 00:00:53.

    void incrementHours();
    //Function to increment the time by one hour.
    //Postcondition: The time is incremented by one
    //               hour. 
    //   If the before-increment time is 23:45:53, the 
    //   time is reset to 00:45:53.

private:
	std::string timeZone;
};
