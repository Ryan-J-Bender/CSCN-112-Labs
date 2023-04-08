#pragma once

#include <iostream>

class rectangleType {

    //// Overload << and >> operators (insertion/extraction)
    //friend std::ostream& operator<<(std::ostream&, const rectangleType&);
    //friend std::istream& operator>>(std::istream&, rectangleType&);

    // Overload + operator
    friend rectangleType operator+(const rectangleType&, const rectangleType&);

    friend rectangleType operator-(const rectangleType&, const rectangleType&);

public:

    rectangleType(); 
    rectangleType(int, int);
    ~rectangleType();

    // Overload post-increment operator
    rectangleType operator++(int);

    // Overload the pre-increment operator
    rectangleType operator++();

    rectangleType operator--();

    rectangleType operator--(int);

    bool operator<=(const rectangleType&) const;

    bool operator>=(const rectangleType&) const;

    bool operator>(const rectangleType&) const;

    bool operator<(const rectangleType&) const;

    bool operator==(const rectangleType&) const;

    bool operator!=(const rectangleType&) const;

    int getLength();
    void setLength(int);

    int getWidth();
    void setWidth(int);

protected:

	int length;
	int width;

private:

};