#include "pch.h"
#include "Point.h"
#include <iostream>

void readPoint(Point& p)
{
	std::cin >> p.x >> p.y;
}

void print(const Point& p)
{
	std::cout << p.x << " " << p.y << std::endl;
}