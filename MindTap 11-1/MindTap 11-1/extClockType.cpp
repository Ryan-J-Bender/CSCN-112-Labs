#include <iostream>
#include "extClockType.h"

void extClockType::setTime(int h, int m, int s, std::string tZ)
{
    timeZone = tZ;
    clockType::setTime(h, m, s);
}

void extClockType::incrementHours()
{
  
    clockType::incrementHours();
}

void extClockType::incrementMinutes()
{
  
    clockType::incrementMinutes();
}

void extClockType::incrementSeconds()
{
 
    clockType::incrementSeconds();
}

void extClockType::printTime() const
{
    
    std::cout << "Current time zone: " << timeZone << std::endl;
    clockType::printTime();
}

extClockType::extClockType(int h, int m, int s, std::string tZ): clockType(h, m, s)
{

    timeZone = tZ;
}

extClockType::extClockType(): clockType()  //default constructor
{
    timeZone = "";
}
