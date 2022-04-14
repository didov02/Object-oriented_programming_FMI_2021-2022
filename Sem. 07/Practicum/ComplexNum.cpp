#include "ComplexNum.h"

ComplexNum::ComplexNum()
{
	real = imaginary = 0;
}

ComplexNum::ComplexNum(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

ComplexNum& ComplexNum::operator+=(const ComplexNum& other)
{
	real += other.real;
	imaginary += other.imaginary;

	return *this;
}

ComplexNum& ComplexNum::operator-=(const ComplexNum& other)
{
	real -= other.real;
	imaginary -= other.imaginary;

	return *this;
}

ComplexNum& ComplexNum::operator*=(const ComplexNum& other)
{
	ComplexNum temp(real, imaginary);

	real = temp.real * other.real - temp.imaginary * other.imaginary;
	imaginary = temp.real * other.imaginary + temp.imaginary * other.real;

	return *this;
}

ComplexNum& ComplexNum::operator/=(const ComplexNum& other)
{
	ComplexNum temp(real, imaginary);

	real = (temp.real * other.real + temp.imaginary * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary);
	imaginary = (temp.imaginary * other.real - temp.real * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary);

	return *this;
}

ComplexNum& ComplexNum::operator*=(const double num)
{
	this->real *= num;
	this->imaginary *= num;

	return *this;
}

ComplexNum& ComplexNum::operator/=(const double num)
{
	this->real /= num;
	this->imaginary /= num;

	return *this;
}

ComplexNum operator+(ComplexNum& first, const ComplexNum& second)
{
	ComplexNum temp(first);
	first += second;
	return temp;
}

ComplexNum operator-(ComplexNum& first, const ComplexNum& second)
{

	ComplexNum temp(first);
	temp -= second;
	return temp;
}

ComplexNum operator*(ComplexNum& first, const ComplexNum& second)
{
	ComplexNum temp(first);
	temp *= second;
	return temp;
}

ComplexNum operator/(ComplexNum& first, const ComplexNum& second)
{
	ComplexNum temp(first);
	temp /= second;
	return temp;
}

ComplexNum operator*(ComplexNum& first, const double num)
{
	ComplexNum temp(first);
	temp *= num;
	return temp;
}

ComplexNum operator/(ComplexNum& first, const double num)
{
	ComplexNum temp(first);
	temp /= num;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const ComplexNum& complexNum)
{
	if (complexNum.imaginary > 0)
		os << complexNum.real << "+" << complexNum.imaginary << "*i";
	else if (complexNum.imaginary < 0)
		os << complexNum.real << complexNum.imaginary << "*i";
	else
		os << complexNum.real;
	return os;
}

std::istream& operator>>(std::istream& is, ComplexNum& complexNum)
{
	is >> complexNum.real >> complexNum.imaginary;
	return is;
}
