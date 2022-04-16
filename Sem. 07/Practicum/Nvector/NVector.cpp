#include "NVector.h"

Nvector::Nvector()
{
	size = 1;
	coordinates = new double[size];
	coordinates[0] = 0;
}

Nvector::Nvector(const double* coordinates, const size_t size)
{
	this->size= size;
	this->coordinates = new double[size];
	for (int i = 0; i < size; i++) {
		this->coordinates[i] = coordinates[i];
	}
}

Nvector::Nvector(const Nvector& other)
{
	copy(other);
}

Nvector& Nvector::operator=(const Nvector& other)
{
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

Nvector::~Nvector()
{
	free();
}

Nvector& Nvector::operator+=(const Nvector& other)
{
	try {
		if (size != other.size) {
			throw - 1;
		}
		for (int i=0; i < size; i++) {
			coordinates[i] += other.coordinates[i];
		}
		return *this;
	}
	catch (int) {
		std::cout << "Different sizes"<<std::endl;
		return *this;
	}
}

Nvector& Nvector::operator-=(const Nvector& other)
{
	try {
		if (size != other.size) {
			throw - 1;
		}
		for (int i=0; i < size; i++) {
			coordinates[i] -= other.coordinates[i];
		}
		return *this;
	}
	catch (int) {
		std::cout << "Different sizes" << std::endl;
		return *this;
	}
}

Nvector& Nvector::operator*=(const double num)
{
	for (int i=0; i < size; i++) {
		coordinates[i] *= num;
	}
	return *this;
}

void Nvector::print() const
{
	for (int i = 0; i < size; i++) {
		std::cout << "[" << i << "]=" << coordinates[i] << " ";
	}
}

double Nvector::operator[](size_t index) const
{
	if (index > size - 1) {
		throw "Invalid index";
	}
	return coordinates[index];
}

double& Nvector::operator[](size_t index)
{
	if (index > size - 1) {
		throw "Invalid index";
	}
	return coordinates[index];
}

bool Nvector::isCollinear(const Nvector& other) const
{
	try {
		if (size != other.size) {
			throw - 1;
		}
		if (size != other.size) {
			return false;
		}
		double ratio = coordinates[0] / other.coordinates[0];
		double currRatio;
		for (int i = 1; i < size; i++) {
			currRatio = coordinates[i] / other.coordinates[i];
			if (currRatio - ratio<0 || currRatio - ratio>EPSILON) {
				return false;
			}
		}
		return true;
	}
	catch(int) {
		return false; // Different sizes
	}
}

bool Nvector::isPerpendicular(const Nvector& other) const
{
	try {
		if (size != other.size) {
			throw - 1;
		}
		if (dotProduct(other) == 0) {
			return true;
		}
		else return false; 
	}
	catch (int) {
		return false; //Different sizes
	}
}

size_t Nvector::getSize() const
{
	return size;
}

double Nvector::dotProduct(const Nvector& other) const
{
	double product = 0;
	for (int i = 0; i < size; i++) {
		product += coordinates[i] * other.coordinates[i];
	}
	return product;
}

std::ostream& operator<<(std::ostream& out, const Nvector& vector)
{
	for (int i = 0; i < vector.size; i++) {
		out << vector.coordinates[i] << " ";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Nvector& vector)
{
	int size;
	in >> size;
	double* buffer = new double[size];
	for (int i = 0; i < size; i++) {
		in >> buffer[i];
	}

	vector.free();
	vector.size = size;
	vector.coordinates = buffer;
	buffer=nullptr;
	return in;
}

Nvector operator+(const Nvector& first, const Nvector& second)
{
	Nvector temp(first);
	temp += second;
	return temp;
}

Nvector operator-(const Nvector& first, const Nvector& second)
{
	Nvector temp(first);
	temp -= second;
	return temp;
}

Nvector operator*(const Nvector& vector, const double num)
{
	Nvector temp(vector);
	temp *= num;
	return temp;
}

Nvector operator*(const double num, const Nvector& vector)
{
	Nvector temp(vector);
	temp *= num;
	return temp;
}

void Nvector::copy(const Nvector& other)
{
	size = other.size;
	coordinates = new double[size];
	for (int i = 0; i < size; i++) {
		coordinates[i] = other.coordinates[i];
	}
}

void Nvector::free()
{
	delete[] coordinates;
}
