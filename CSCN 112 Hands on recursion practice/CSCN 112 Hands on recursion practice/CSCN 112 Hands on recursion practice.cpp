// Hands on recursion practice

#include <iostream> // Cin Cout etc

using namespace std;

// Function Prototypes
int factorial(int first);



int main()
{
    std::cout << "Practice using Recursion CSIS 112 ------- Ryan Bender" << endl;

    // Practice using the factorial function
    cout << factorial(4) << endl;

    cout << factorial(6) << endl;
    // Create an array with random numbers

    // Print out array using iteration

    // Print out array using recursion

    system("pause");
    return 0;

}

//                           Function Definitions

// Factorial function brings in an integer. If that integer is 1, return 1, else returns that number times the function again with (n-1).
int factorial(int first)
{
    // Step 1: Error Check for a Negative
    if (first == 0)
    {
        return 1;
    }
    if (first < 0)
    {
        cout << "ERROR:  Cannot process a negative number. Continuing with the absolute value." << endl;
        first = -first;
    }

    // Step 1b: Check for Base Case (if start = 1)
    if (first == 1)
    {
        return 1;
    }

    // Step 2: Else return that number again times (n-1)
    else
    {
        return (first * factorial(first - 1));
    }
}