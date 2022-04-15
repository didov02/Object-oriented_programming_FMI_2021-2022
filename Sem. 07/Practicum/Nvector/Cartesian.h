#pragma once
#include "NVector.h"


class Cartesian2D {
private:
	Nvector first;
	Nvector second;
public:
	Cartesian2D();
	Cartesian2D(const Nvector, const Nvector);
	Cartesian2D(const Cartesian2D&);
	Cartesian2D& operator=(const Cartesian2D&);
	~Cartesian2D()=default;

	Nvector getVectorByCoordinates(const Nvector&);
	Nvector getCoordinatesByVector(const Nvector&);
private:
	void copy(const Cartesian2D&);
};