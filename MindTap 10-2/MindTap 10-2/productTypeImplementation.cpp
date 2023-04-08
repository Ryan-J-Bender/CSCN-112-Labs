#include "productType.h"
#include <iostream>

// Default constructor    
productType::productType() {
    int x = 0;

    double y = 0.0;
    double z = 0.0;

    string s = "";
    string t = "";
    string u = "";

}

productType::productType(string s, string t, string u, int x, double y, double z) {


    productName = s;
    std::string manufacturer = t;
    std::string id = u;

    quantitiesInStock = x;

    price = y;
    discount = z;

}

void productType::set(string s, string t, string u, int x, double y, double z) {

    productName = s;
    manufacturer = t;
    id = u;

    quantitiesInStock = x;
    price = y;
    discount = z;

}



void productType::print() const {

    cout << "Product name: " << productName << "." << endl << endl << "Manufacturer: " << manufacturer << "." << endl << endl;

    cout << "Product ID: " << id << "." << endl << endl << "Quantity: " << quantitiesInStock << "." << endl << endl;

    cout << "Price: " << price << "." << endl << endl << "Discount: " << discount << "." << endl << endl;

}

void productType::setQuantitiesInStock(int x) {

    quantitiesInStock = x;

    while (x < 0) {

        cout << "Error. Please enter a non-negative integer: " << endl;
        cin >> x;
    }

}
void productType::updateQuantitiesInStock(int x) { // Add to int. error check for <=0 

    quantitiesInStock += x;

    if (quantitiesInStock <= 0)
        quantitiesInStock = 0;

}

int productType::getQuantitiesInStock() const {

    return quantitiesInStock;

}

void productType::setPrice(double x) {

    price = x;

}

double productType::getPrice() const {

    return price;
}

void productType::setDiscount(double d) {

    discount = d;

}

double productType::getDiscount() const {

    return discount;
}

