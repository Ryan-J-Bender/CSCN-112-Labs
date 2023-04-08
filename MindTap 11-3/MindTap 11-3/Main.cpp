// MindTap 11-3 Inheritance (again)

#include <iostream>
#include "circleType.h"
#include "cylinderType.h"

using namespace std;

int main() {
    
    cylinderType cyl(4.5, 6.75);

    //cyl.setRadius(4.5);

    //cyl.setHeight(6.75);

    cyl.print();

    system("pause");
    return 0;
}
