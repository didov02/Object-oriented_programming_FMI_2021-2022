#pragma once
#include <iostream>

class ComplexNum
{

private:
	double real;
	double imaginary;

public:

	ComplexNum();
	ComplexNum(double, double);
	ComplexNum(const ComplexNum&) = default;
	ComplexNum& operator=(const ComplexNum&) = default;
	~ComplexNum() = default;


	ComplexNum& operator+=(const ComplexNum&);
	ComplexNum& operator-=(const ComplexNum&);
	ComplexNum& operator*=(const ComplexNum&);
	ComplexNum& operator/=(const ComplexNum&);
	ComplexNum& operator*=(const double);
	ComplexNum& operator/=(const double);

	friend ComplexNum operator+(const ComplexNum&, const ComplexNum&);
	friend ComplexNum operator-(const ComplexNum&, const ComplexNum&);
	friend ComplexNum operator*(const ComplexNum&, const ComplexNum&);
	friend ComplexNum operator/(const ComplexNum&, const ComplexNum&);
	friend ComplexNum operator*(const ComplexNum&, const double);
	friend ComplexNum operator/(const ComplexNum&, const double);

	friend std::ostream& operator<<(std::ostream& os, const ComplexNum& complexNum);
	friend std::istream& operator>>(std::istream& is, ComplexNum& complexNum);

};

