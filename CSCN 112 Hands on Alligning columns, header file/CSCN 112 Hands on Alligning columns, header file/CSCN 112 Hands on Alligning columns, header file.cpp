// Formatting Program

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    string name = "Professor M";
    string course = "CSCN 112";
    string day1 = "Monday";
    string day2 = "Tuesday";
    string day3 = "Wednesday";
    string day4 = "Thursday";
    string day5 = "Friday";

    float grade1 = 90;
    float grade2 = 91;
    float grade3 = 85;
    float grade4 = 75;
    float grade5 = 100;

    float percent1 = 100.0;
    float percent2 = 88.1;
    float percent3 = 73.6;
    float percent4 = 99.2;
    float percent5 = 25.1;


    // practice using setw
    cout << left << setw(15) << name << course << endl;

    // print header for table
    cout << left << setw(16) << "Day of Week" << setw(14) << "Grade" << "Percent" << endl << endl;
    cout << left << setw(15) << day1 << right << setw(6) << fixed << setprecision(2) << grade1 << right << setw(16) << percent1 << endl;
    cout << left << setw(15) << day2 << right << setw(6) << fixed << setprecision(2) << grade2 << right << setw(16) << percent2 << endl;
    cout << left << setw(15) << day3 << right << setw(6) << fixed << setprecision(2) << grade3 << right << setw(16) << percent3 << endl;
    cout << left << setw(15) << day4 << right << setw(6) << fixed << setprecision(2) << grade4 << right << setw(16) << percent4 << endl;
    cout << left << setw(15) << day5 << right << setw(6) << fixed << setprecision(2) << grade5 << right << setw(16) << percent5 << endl;


    system("pause");
    return 0;
}

