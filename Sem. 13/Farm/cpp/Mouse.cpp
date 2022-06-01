#include "Mouse.h"
#include <iostream>

void Mouse::sound() const
{
	std::cout << "Cr" << std::endl;
}
Animal* Mouse::clone() const
{
	return new Mouse(*this);
}
