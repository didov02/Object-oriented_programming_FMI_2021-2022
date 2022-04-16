#include "Cartesian.h"
#include "NVector.h"

Cartesian2D::Cartesian2D()
{
	double e1[] = { 1,0 };
	double e2[] = { 0,1 };
	Nvector E1(e1, 2);
	Nvector E2(e2, 2);
	first = E1;
	second=E2;
}

Cartesian2D::Cartesian2D(const Nvector& first, const Nvector& second)
{
	this->first = first;
	this->second = second;
}

Cartesian2D::Cartesian2D(const Cartesian2D& other)
{
	first = other.first;
	second = other.second;
}

Cartesian2D& Cartesian2D::operator=(const Cartesian2D& other)
{
	if (this != &other) {
		copy(other);
	}
	return *this;
}

Nvector Cartesian2D::getVectorByCoordinates(const Nvector& other)
{
	double coordinates[2];
	coordinates[0] = other.getCoordinate(0) * first.getCoordinate(0) + other.getCoordinate(1) * second.getCoordinate(0);
	coordinates[1] = other.getCoordinate(0) * first.getCoordinate(1) + other.getCoordinate(1) * second.getCoordinate(1);
	Nvector temp(coordinates, 2);
	return temp;
}

Nvector Cartesian2D::getCoordinatesByVector(const Nvector& other)
{
	double coordinates[2];
	coordinates[1] = (first.getCoordinate(0) * other.getCoordinate(1) - first.getCoordinate(1) * other.getCoordinate(0)) / (first.getCoordinate(0) * second.getCoordinate(1) - first.getCoordinate(1) * second.getCoordinate(0));
	coordinates[0] = (other.getCoordinate(0) - (second.getCoordinate(0) * coordinates[1]))/first.getCoordinate(0);
	Nvector temp(coordinates,2);
	return temp;
}

void Cartesian2D::copy(const Cartesian2D& other)
{
	first = other.first;
	second = other.second;
}
