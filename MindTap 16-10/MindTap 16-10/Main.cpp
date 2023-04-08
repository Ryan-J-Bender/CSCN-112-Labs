// MindTap 16-10 Vector Class Type

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function Prototypes
void fillVec(vector<string>& zString, string input);
//void seqSearch(const vector<string>& zString);
void seqSearch2(const vector<string>& zString);


int main() {

	vector <string> zString;
	string vecString = "";
	
	fillVec(zString, vecString);

	seqSearch2(zString);

//	seqSearch(zString);

	system("pause");
	return 0;
}

// Function Definitions
void fillVec(vector<string>& zString, string input) {

	int i = 0;
	bool found = false;

	cout << "Please enter vector elements or 'zzz' to exit." << endl;

	while (!found) {

		cout << "Element " << i << ": ";
		
		cin >> input;
		
		if (input != "zzz") {
			
			zString.push_back(input);
		}
		else 
			found = true;

		i++;
	}
}

void seqSearch2(const vector<string>& zString)
{

	string searchItem;

	cout << "Please enter a string for which you'd like to search: ";
	cin >> searchItem;

	if (find(zString.begin(), zString.end(), searchItem) != zString.end()) {

		cout << searchItem << " is found in the list" << endl;
	}
	else
		cout << searchItem << " is not in the list" << endl;
}

//void seqSearch(const vector<string>& zString) {
//	
//	string temp;
//	string searchItem;
//
//	cout << "Please enter a string for which you'd like to search: ";
//	cin >> searchItem;
//
//	for (int i = 0; i < zString.size(); i++) {
//
//		temp = zString.at(i);
//
//		if (searchItem == temp) {
//
//			cout << searchItem << " is found in the list" << endl;
//		}
//		else { 
//			
//			if (searchItem != temp && (i = zString.size())) {
//
//				cout << searchItem << " is not in the list" << endl;
//			}
//		}
//	}
//
//}