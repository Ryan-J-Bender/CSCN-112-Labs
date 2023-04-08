#include "rectangleType.h"

using namespace std;

int main() {

	rectangleType rec1(10, 12);
	rectangleType rec2(8, 4);
	rectangleType rec3(13, 8);
	rectangleType recy(14, 9);

	rectangleType rec5 = rec3;
	rec5++;

	cout << rec5.getLength() << " " << rec5.getWidth() << endl;

	if (rec5 == recy) {

		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}



	rectangleType test = ++rec5;

	cout << rec5.getLength() << " " << rec5.getWidth() << endl;



	if (test == rec5) {

		cout << endl << "true" << endl; 
	}
	else {
		cout << endl << "false" << endl;
	}
	//
	//cout << "rec1 + rec2: " << (rec1 + rec2) << endl;
	//cout << "rec1 - rec2: " << (rec1 - rec2) << endl;
	//
	//if (rec1 == rec2) {

	//	cout << "rec1 == rec2" << endl;
	//}
	//if (rec1 != rec2) {

	//	cout << "rec1 != rec2" << endl;
	//}
	//if (rec2 == rec3) {

	//	rec2++;
	//	cout << "rec2 == rec3" << endl;
	//}


	system("pause");
	return 0;
}
