#include "Nvector.h"
#include <iostream>

void Nvector::copy(const Nvector& currentVector)
{
	size = currentVector.size;
	for (int i = 0; i < size; i++)
	{
		coordinates[i] = currentVector.coordinates[i];
	}
}

void Nvector::free()
{
	delete[] coordinates;
}

Nvector::Nvector()
{
	size = 0;
	coordinates = nullptr;
}

Nvector::Nvector(size_t size)
{
	this->size = size;

	for (int i = 0; i < size; i++)
	{
		coordinates[i] = 0;
	}
}

Nvector::Nvector(const Nvector& other)
{
	copy(other);
}

Nvector& Nvector:: operator = (const Nvector& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

Nvector::~Nvector()
{
	free();
}

Nvector Nvector::operator+=(const Nvector& other) const
{
	if (size != other.size)
		throw "Vectors have different sizes";

	Nvector result(size);

	for (int i = 0; i < size; i++)
	{
		result.coordinates[i] = coordinates[i] + other.coordinates[i];
	}

	return result;
}

Nvector Nvector::operator-=(const Nvector& other) const
{
	if (size != other.size)
		throw "Vectors have different sizes";

	Nvector result(size);

	for (int i = 0; i < size; i++)
	{
		result.coordinates[i] = coordinates[i] - other.coordinates[i];
	}

	return result;
}

Nvector Nvector::operator*=(const int multiplier) const
{
	if (size == 0)
	{
		throw "Exception!";
	}

	Nvector result(size);
	for (int i = 0; i < size; i++)
	{
		result.coordinates[i] = coordinates[i] * multiplier;
	}

	return result;
}

bool Nvector::areParallel(const Nvector& other) const
{
	double multiplier = coordinates[0] / other.coordinates[0];
	
	for (int i = 1; i < size; i++)
	{
		if (other.coordinates[i] * multiplier != other.coordinates[i])
			return false;
	}

	return true;
}

bool Nvector::arePerpendicular(const Nvector& other) const
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += coordinates[i] * other.coordinates[i];
	}

	if (sum != 0)
		return false;

	return true;
}

double Nvector::getSizeOfVector() const
{
	double sizeOfVector = 0;

	for (int i = 0; i < size; i++)
	{
		sizeOfVector += coordinates[i] * coordinates[i];
	}

	return sqrt(sizeOfVector);
}

int& Nvector::operator[](int index) 
{
	return coordinates[index];
}

int Nvector::operator[](int index) const
{
	return coordinates[index];
}

std::istream& operator>>(std::istream& in, Nvector vector)
{
	for (int i = 0; i < vector.size; i++)
	{
		in >> vector.coordinates[i];
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const Nvector& vector)
{
	for (int i = 0; i < vector.size; i++)
	{
		out << vector.coordinates[i]<<" ";
	}
	
	return out;
}
