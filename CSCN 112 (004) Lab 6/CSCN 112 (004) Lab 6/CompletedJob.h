#pragma once

#include <iostream> // Cin, cout, etc.
#include <string> // String type, getline, etc.
#include <iomanip> // Setw, fixed, etc.

class CompletedJob {

public:

	CompletedJob(); // Default constructor
	CompletedJob(int, int, int, float, double, double, double, std::string); // 8 Argument constructor
	~CompletedJob(); // Destructor

	void setInvoiceNum(int); // Sets random number to be applied to the invoice
	void setRoomsPainted(int); // Sets the number of rooms painted
	void setCanNum(int); // Sets number of paint cans used
	void setMileage(int); // Sets number of traveled miles

	void setClientName(std::string); // Sets the client's name

	int getInvoiceNum() const; // Returns the number applied to the invoice
	int getRoomsPainted() const; // Returns the number of rooms painted
	int getCanNum() const; // Returns the number of paint cans used

	int getMileage() const; // Returns the number of traveled miles

	std::string getClientName() const; // Returns the client's name

	double calculateTotal() const; // Calculates the total cost of a given job

	void printInvoice() const; // Prints an invoice for a given job

	double laborCharge() const; // Calculates and returns charge from labor
	double productCharge() const; // Calculates and returns charge from paint
	double travelCharge() const; // Calculates and returns charge from traveled miles



private:

	int invoiceNum; // Random Number for each invoice
	int roomsPainted; // Number of rooms painted in a job
	int canNum; // Number of paint cans used
	int mileage; // Number of miles traveled

	// Constant prices
	const double pricePerHr = 18.50;
	const double pricePerCan = 70.35;
	const double pricePerMile = 1.34;

	std::string clientName; // Client name

};
