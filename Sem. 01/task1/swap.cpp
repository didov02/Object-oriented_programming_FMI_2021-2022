#include "pch.h"
#include "Triangle.h"

void swap(double &f, double &s)
{
	double temp = f;
	f = s;
	s = temp;
}

void swap(Triangle& f, Triangle& s)
{
	Triangle temp = f;
	f = s;
	s = temp;
}