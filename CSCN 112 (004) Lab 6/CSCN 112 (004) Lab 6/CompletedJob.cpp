#include "CompletedJob.h" // Includes CompletedJob class header file

CompletedJob::CompletedJob() { // Basic constructor: initializes all variables, assigns a random number to each invoice

	invoiceNum = rand() % 1001;
	roomsPainted = 0;
	canNum = 0;

	mileage = 0;

	clientName = "";
}

CompletedJob::CompletedJob(int i, int r, int c, float m, double l, double p, double t, std::string n) { // 8 Argument constructor

	invoiceNum = i;
	roomsPainted = r;
	canNum = c;

	mileage = m;

	clientName = n;
}

CompletedJob::~CompletedJob() {} // Destructor

void CompletedJob::setInvoiceNum(int x) { // Sets invoice number

	invoiceNum = x;
}

void CompletedJob::setRoomsPainted(int x) { // Sets number of painted rooms

	roomsPainted = x;
}

void CompletedJob::setCanNum(int x) { // Sets number of paint cans

	canNum = x;
}

void CompletedJob::setMileage(int x) { // Sets number of miles traveled

	mileage = x;
}

void CompletedJob::setClientName(std::string x) { // Sets the client's name

	clientName = x;
}

int CompletedJob::getInvoiceNum() const { // Returns the invoice number

	return invoiceNum;
}

int CompletedJob::getRoomsPainted() const { // Returns the number of painted rooms

	return roomsPainted;
}

int CompletedJob::getCanNum() const { // Returns number of paint cans used

	return canNum;
}

int CompletedJob::getMileage() const { // Returns miles traveled

	return mileage;
}

std::string CompletedJob::getClientName() const { // Returns the client's name

	return clientName;
}

void CompletedJob::printInvoice() const { // Prints an invoice for a given job

	std::cout << "Client Name: " << clientName << std::endl;
	std::cout << " Invoice Number: " << "#" << getInvoiceNum() << std::endl;
	std::cout << "  Rooms Painted: " << std::setw(10) << std::right << roomsPainted << std::endl;
	std::cout << "  Labor Charges: " << std::setw(10) << std::right << std::setprecision(2) << laborCharge() << std::endl;
	std::cout << "  Paint Cans: " << std::setw(13) << std::right << canNum << std::endl;
	std::cout << "  Product Charges: " << std::setw(8) << std::right << std::setprecision(2) << productCharge() << std::endl;
	std::cout << "  Mileage: " << std::setw(16) << std::right << mileage << std::endl;
	std::cout << "  Travel Charges: " << std::setw(9) << std::right << std::setprecision(2) << travelCharge() << std::endl;
	std::cout << "Total Cost" << std::setw(43) << std::right << std::setprecision(2) << calculateTotal() << std::endl << std::endl;
	std::cout << "_____________________________________________________" << std::endl;

}


double CompletedJob::laborCharge() const { // Returns charge due to labor

	return roomsPainted * pricePerHr;
}

double CompletedJob::productCharge() const { // Returns charge due to paint usage

	return canNum * pricePerCan;
}

double CompletedJob::travelCharge() const { // Returns charge due to travel

	return mileage * pricePerMile;
}

double CompletedJob::calculateTotal() const { // Returns total cost of a job

	return (travelCharge() + productCharge() + laborCharge());
}