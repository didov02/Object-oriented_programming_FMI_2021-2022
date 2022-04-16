#pragma once
#include "NVector.h"


class Cartesian2D {
private:
	Nvector first;
	Nvector second;
public:
	Cartesian2D(const Nvector&, const Nvector&);

	Nvector getVectorByCoordinates(const Nvector&);
	Nvector getCoordinatesByVector(const Nvector&);
};
