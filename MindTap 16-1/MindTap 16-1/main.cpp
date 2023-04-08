#include <iostream>

using namespace std;

void bubbleSort(int list[], int length);
void inputList(int list[]);
void printList(const int list[]);

int seqSearch(const int list[], int length);

int main() {

    int list[10];

    inputList(list);

    bubbleSort(list, 10);
    
    printList(list);

    seqSearch(list, 10);

    system("pause");
    return 0;
}

void bubbleSort(int list[], int length) {

    int temp;
    for (int iteration = 1; iteration < length; iteration++) {

        for (int index = 0; index < length - iteration; index++) {
            if (list[index] > list[index + 1]) {

                temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }

        }
    }

}

void inputList(int list[]) {

    cout << "Please enter 10 integers that you wish to be sorted: " << endl;

    for (int i = 0; i < 10; i++) {

        cin >> list[i];
    }
}

void printList(const int list[]) {

    cout << endl << "After sorting, the elements are: " << endl;

    for (int i = 0; i < 10; i++) {

        cout << list[i] << " ";
    }

    cout << endl << endl;

}

int seqSearch(const int list[], int length) {

    // Local Variables
    int searchItem;
    int location;
    bool found = false;
    location = 0;

    cout << "Please enter the number you wish to find: " << endl;
    cin >> searchItem;
    cout << endl;

    while (location < length && !found) {

        if (list[location] == searchItem) {
            found = true;
        }
        else {
            location++;
        }
    }

    if (!found) {

        cout << searchItem << " is not in the list" << endl;

        location = -1;
    }
    
    else {
        
        cout << searchItem << " is found at position " << location << "." << endl;
    }

    cout << endl;

    return location;
}

