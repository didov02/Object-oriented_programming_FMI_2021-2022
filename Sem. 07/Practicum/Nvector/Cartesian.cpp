#include "Cartesian.h"
#include "NVector.h"

Cartesian2D::Cartesian2D(const Nvector& first, const Nvector& second)
{
	this->first = first;
	this->second = second;
}

Nvector Cartesian2D::getVectorByCoordinates(const Nvector& other) const
{
	double coordinates[2];
	coordinates[0] = other.getCoordinate(0) * first.getCoordinate(0) + other.getCoordinate(1) * second.getCoordinate(0);
	coordinates[1] = other.getCoordinate(0) * first.getCoordinate(1) + other.getCoordinate(1) * second.getCoordinate(1);
	Nvector temp(coordinates, 2);
	return temp;
}

Nvector Cartesian2D::getCoordinatesByVector(const Nvector& other) const
{
	double coordinates[2];
	coordinates[1] = (first.getCoordinate(0) * other.getCoordinate(1) - first.getCoordinate(1) * other.getCoordinate(0)) / (first.getCoordinate(0) * second.getCoordinate(1) - first.getCoordinate(1) * second.getCoordinate(0));
	coordinates[0] = (other.getCoordinate(0) - (second.getCoordinate(0) * coordinates[1]))/first.getCoordinate(0);
	Nvector temp(coordinates,2);
	return temp;
}
