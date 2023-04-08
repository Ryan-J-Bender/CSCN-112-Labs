// CSCN 112 Lab 1 Recursive Loan Calculator ------- Ryan Bender

/*								Algorithm
* 
*		1. Ask for and grab the loan calulation variables from the user; do math.
*		2. Test for errors in the loan amount, interest rate, and pay-period.
*		3. Recursively calculate number of total months.
*		4. Recursively calculate for the monthly payment (should be the most complicated math and should stay constant)
*		5. Recursively calculate the interest for each individual month.
*		6. Recursively calculate the principle for each individual month.
*		7. Recursively calculate the balance after the monthly payment.
*		8. Align text, format.
*		9. Review error checking, documentation.
*		10. Review assignment instructions, rubric, make final adjustments to program.
* 
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
void getVars(double &p, double &r, int &l, double &monthPay, double &bal);

int Amortize(int &monthNum, double &monthPay, double &p, double &interest, double &bal, int &l, double &r);


int main()
{
	cout << "CSCN 112 (004) ---- Lab 1: Loan Calculator (Recursion) ---- Ryan Bender" << endl;

	// Variables
	double p = 0;
	double r = 0;
	double monthPay = 0;
	double interest = 0;
	double bal = 0;

	int l = 0;
	int monthNum = 1;
	
	getVars(p, r, l, monthPay, bal);

	// Print Header
	cout << left << setw(14) << "Payment #" << setw(12) << "Ammount" << setw(13) << "Interest" << setw(14) << "Principle" << "Balance" << endl << endl;
	cout << right << setw(60) << bal << endl;;

	Amortize(monthNum, monthPay, p, interest, bal, l, r);
	

	system("pause");
	return 0;
}

// Function Definitions

// Function for variable input from user; display Principle, Life of Loan, Annual Interest Rate.
void getVars(double& p, double& r, int& l, double& monthPay, double &bal) {


	cout << endl << "Enter the loan amount:	 ";
	cin >> p;

		while (p <= 0) { // Check for error (p is not a positive, non-zero integer)
			cout << endl << "ERROR: Please enter a positive, non-zero number:  ";

			cin.clear(); // Clear cin error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Remove any and all excess characters
		
			cin >> p; // Re-input variable
	
		}

	cout << endl << "Enter annual rate of interest:  ";
	cin >> r;

		while (r <= 0) { // Error Checking
			cout << endl << "ERROR: Please enter a positive, non-zero number:  ";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cin >> r;

		}

	cout << endl << "Enter the period over which the loan is to be paid (must be 5, 10, or 15 years):  ";
	cin >> l;

		while (l != 5 && l != 10 && l != 15 ) { // Error Checking
				cout << endl << "ERROR: Please enter a positive, non-zero number (must be 5, 10, or 15):  ";

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cin >> l; 

		}

		r = 0.01 * (r / 12); // Converting user inputs to proper values.
		l = l * 12;
		bal = p;

		monthPay = p * ( (r * pow((1 + r), l)) / (pow((1 + r), l) - 1)); // Calculates monthly payment


//								Display the user-set information and required monthly payment

		system("CLS");
		cout << "Loan amount: $" << fixed << showpoint << setprecision(2) << p << endl;
		cout << "Annual Interest Rate: " << resetiosflags(ios::fixed | ios::showpoint) << r * (12 / 0.01) << "%" << endl;
		cout << "Period over which the loan is to be paid: " << l / 12 << " Years or " << l << " months." << endl;
		cout << "Required Monthly Payment: $" << fixed << showpoint << setprecision(2) << monthPay << endl;


}


// Amortization function: Recursively calculate Number of Months, Monthly Payment, Interest, Principle, Remaining Balance.

int Amortize(int& monthNum, double& monthPay, double& p, double& interest, double& bal, int& l, double& r) {

	



// Base case: monthNum has increased to l. There are no more months for which a payment will occur.
	if (monthNum > l) {

		return 1;


	}


	else {

		// Math to be done at every instance of the recursively printed statement.
		interest = bal * r;
		p = monthPay - interest;
		bal = bal + interest - monthPay;

		if (bal <= 0.00)
			bal = 0.00;

		// Recursion
		
		// Statement to be recursively printed.
		cout << left << setw(10) << monthNum << right << setw(11) << monthPay << setw(13) << interest << setw(14) << p << setw(12) << bal << endl;
		

		Amortize(monthNum = monthNum + 1, monthPay, p, interest, bal, l, r); // Function call for recursion.
	}


}