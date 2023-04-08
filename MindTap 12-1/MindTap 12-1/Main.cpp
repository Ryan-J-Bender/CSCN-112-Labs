#include <iostream>
#include <cstring> 
#include <cctype> 

using namespace std;

int main()
{

    char* strPtr;

    strPtr = new char[81];
    int num = 0;

    int len;

    int i;

    cout << "Enter a string: ";
    cin >> num;
    cin.clear();
    cin.ignore();
    cin.get(strPtr, 80);
    cout << endl;
    cout << "String in upper case letters is:" << endl;

    len = strlen(strPtr);
    for (i = 0; i < len; i++)
        cout << static_cast<char>(toupper(strPtr[i]));
    cout << endl;

    return 0;
}
