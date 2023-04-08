#include <iostream>
#include "productType.h"

using namespace std;

int main() {
    
    productType product1("Pencil", "AsStrat", "Num2", 10, 50.00, 4.5);
    product1.print();

    product1.updateQuantitiesInStock(5);
    product1.print();

    return 0;
}
