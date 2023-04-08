#pragma once

#include "Account.h";

class SavingsAccount : public Account {
public:

	SavingsAccount(); // Basic constructor
	SavingsAccount(double, double); // One argument constructor
	~SavingsAccount(); // Destructor

	double calculateInterest();
	void setInterestRate(double);
	double getInterestRate();

private:

	double interestRate;
};