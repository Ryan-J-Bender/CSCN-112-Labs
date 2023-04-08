#include "rectangleType.h"

//std::ostream& operator<<(std::ostream& out, const rectangleType& rect) {
//
//	out << "length: " << rect.;
//
//
//	return out;
//}

//std::istream& operator>>(std::istream&, rectangleType&) {
//
//	// // O: insert return statement here
//
//}


rectangleType::rectangleType() {

	length = 0;
	width = 0;
}

rectangleType::rectangleType(int l, int w) {

	length = l;
	width = w;
}

rectangleType::~rectangleType() {}

rectangleType operator+(const rectangleType& rec1, const rectangleType& rec2) {


	int l = 0;
	int w = 0;

	l = rec1.length + rec2.length;
	w = rec1.width + rec2.width;

	return rectangleType(l, w);
}

rectangleType operator-(const rectangleType& rec1, const rectangleType& rec2) {

	int l = rec1.length;
	int w = rec1.width;

	if (l < rec2.length || w < rec2.width) {

		std::cout << "Unable to perform operation.";
	}
	else {

		l = rec1.length - rec2.length;
		w = rec1.width - rec2.width;

		return rectangleType(l, w);
	}
}

rectangleType rectangleType::operator++(int) {

	int l = 0;
	int w = 0;

	l = length + 1;
	w = width + 1;

	setLength(l);
	setWidth(w);

	return *this;
}

rectangleType rectangleType::operator++() {

	int l = 0;
	int w = 0;

	l = length + 1;
	w = width + 1;

	setLength(l);
	setWidth(w);

	return *this;
}

rectangleType rectangleType::operator--()
{

	int l = 0;
	int w = 0;

	l = length - 1;
	w = width - 1;

	if (w < 0) {
		w = 0;
	}
	if (l < 0) {
		l = 0;
	}

	setLength(l);
	setWidth(w);

	return *this;
}

rectangleType rectangleType::operator--(int)
{

	int l = 0;
	int w = 0;

	l = length - 1;
	w = width - 1;

	if (w < 0) {
		w = 0;
	}
	if (l < 0) {
		l = 0;
	}

	setLength(l);
	setWidth(w);

	return *this;
}

bool rectangleType::operator<=(const rectangleType& rect) const {

	bool test;

	if ((this->length * this->width) <= (rect.length * rect.width)) {

		test = true;
	}
	else {

		test = false;
	}


	return test;
}

bool rectangleType::operator>=(const rectangleType& rect) const {
	
	bool test;

	if ((this->length * this->width) >= (rect.length * rect.width)) {

		test = true;
	}
	else {

		test = false;
	}


	return test;
}

bool rectangleType::operator>(const rectangleType& rect) const {

	bool test;

	if ((this->length * this->width) > (rect.length * rect.width)) {

		test = true;
	}
	else {

		test = false;
	}


	return test;
}

bool rectangleType::operator<(const rectangleType& rect) const {

	bool test;

	if ((this->length * this->width) < (rect.length * rect.width)) {

		test = true;
	}
	else {

		test = false;
	}


	return test;
}

bool rectangleType::operator==(const rectangleType& recy) const {

	bool test = false;

	if (length * width == recy.length * recy.width) {

		test = true;
	}
	else {
		test = false;
	}

	return test;
}

bool rectangleType::operator!=(const rectangleType& recy) const {

	bool test = true;

	if (length * width == recy.length * recy.width) {

		test = false;
	}
	else {
		test = true;
	}

	return test;
}

int rectangleType::getLength()
{
	return length;
}

void rectangleType::setLength(int l) {

	length = l;

}

int rectangleType::getWidth()
{
	return width;
}

void rectangleType::setWidth(int w) {

	width = w;
}
