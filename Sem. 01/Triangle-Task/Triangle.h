#pragma once
#include "Point.h"

struct Triangle
{
	Point A, B, C;
};

void readTriangle(Triangle&);
void readTriangles(Triangle*, size_t);
void print(const Triangle&);
void print(const Triangle*,size_t);