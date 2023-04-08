#include <iostream>
#include "extClockType.h"
#include "clockType.h"
using namespace std;

int main() {

    extClockType clock;

    clock.setTime(5, 15, 34, "EST");
    clock.printTime();
    // Write your main here
    return 0;
}
