#include "NVector.h"

//Constructors&Destructor
Nvector::Nvector()
{
	size = 1;
	coordinates = new double[size]();
}

Nvector::Nvector(const double* coordinates, const size_t size)
{
	this->size = size;
	this->coordinates = new double[size];
	
	for (size_t i = 0; i < size; i++)
		this->coordinates[i] = coordinates[i];
}

Nvector::Nvector(const Nvector& other)
{
	copy(other);
}

Nvector& Nvector::operator=(const Nvector& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Nvector::~Nvector()
{
	free();
}

//Methods

void Nvector::print() const
{
	for (size_t i = 0; i < size; i++)
		std::cout << "[" << i << "]=" << coordinates[i] << " ";
}

bool Nvector::isCollinear(const Nvector& other) const
{
	if (size != other.size)
		return false;

	int counterOther = 0, counter = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (other.coordinates[i] == 0)
			counterOther++; //counter to check if it is the 0 vector, 0 vector is collinear with every other

		if (coordinates[i] == 0)
			counter++;
	}

	if (counterOther == other.size || counter == size)
		return true;

	double ratio = 0;

	for (size_t i = 0; i < size; i++)
	{
		// if both a zeros
		if (coordinates[i] == 0 && other.coordinates[i] == 0)
			continue;
		
		// if at current index one of the coordinates is zero and the other is != 0 => not collinear
		if ((coordinates[i] != 0 && other.coordinates[i] == 0) || (coordinates[i] == 0 && other.coordinates[i] != 0))
			return false;

		// ratio is impossible to be 0 when dividing two != 0 numbers
		// so we are using 0 as default case
		if (ratio == 0)
			ratio = coordinates[i] / other.coordinates[i];

		double currRatio = coordinates[i] / other.coordinates[i];

		if (currRatio - ratio != 0)
			return false;
	}
	return true;
}

bool Nvector::isPerpendicular(const Nvector& other) const
{
	if (size != other.size)
		return false;

	return (dotProduct(other) == 0);
}

size_t Nvector::getSize() const
{
	return size;
}

double Nvector::dotProduct(const Nvector& other) const
{
	double product = 0;
	for (size_t i = 0; i < size; i++)
		product += coordinates[i] * other.coordinates[i];
	return product;
}

//Operators
Nvector& Nvector::operator+=(const Nvector& other)
{
	if (size != other.size)
		throw "The vectors should have the same size!";

	for (size_t i = 0; i < size; i++)
		coordinates[i] += other.coordinates[i];

	return *this;
}

Nvector& Nvector::operator-=(const Nvector& other)
{
	if (size != other.size)
		throw "The vectors should have the same size!";

	for (size_t i = 0; i < size; i++)
		coordinates[i] -= other.coordinates[i];

	return *this;
}

Nvector& Nvector::operator*=(const double num)
{
	for (size_t i = 0; i < size; i++)
		coordinates[i] *= num;

	return *this;
}

double Nvector::operator[](size_t index) const
{
	if (index > size - 1)
		throw "Invalid index";

	return coordinates[index];
}

double& Nvector::operator[](size_t index)
{
	if (index > size - 1)
		throw "Invalid index";

	return coordinates[index];
}

std::ostream& operator<<(std::ostream& out, const Nvector& vector)
{
	for (int i = 0; i < vector.size; i++)
		out << vector.coordinates[i] << " ";

	return out;
}

std::istream& operator>>(std::istream& in, Nvector& vector)
{
	int size;
	in >> size;
	double* buffer = new double[size];

	for (int i = 0; i < size; i++)
		in >> buffer[i];

	vector.free();
	vector.size = size;
	vector.coordinates = buffer;
	buffer = nullptr;
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

//Private methods
void Nvector::copy(const Nvector& other)
{
	size = other.size;
	coordinates = new double[size];

	for (int i = 0; i < size; i++)
		coordinates[i] = other.coordinates[i];
}

void Nvector::free()
{
	delete[] coordinates;
}
