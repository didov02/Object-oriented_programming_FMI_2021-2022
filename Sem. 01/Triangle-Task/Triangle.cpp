#include "pch.h"
#include "Triangle.h"

void readTriangle(Triangle& t)
{
	readPoint(t.A);
	readPoint(t.B);
	readPoint(t.C);
}

void readTriangles(Triangle* ts, size_t N)
{
	for (size_t i = 0; i < N; i++)
		readTriangle(ts[i]);
}

void print(const Triangle& t)
{
	print(t.A);
	print(t.B);
	print(t.C);
}

void print(const Triangle* ts, size_t size)
{
	for (size_t i = 0; i < size; i++)
		print(ts[i]);
}
