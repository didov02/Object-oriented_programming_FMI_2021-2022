#include "Cat.h"
#include <iostream>

void Cat::sound() const
{
	std::cout << "Meow" << std::endl;
}
Animal* Cat::clone() const
{
	return new Cat(*this);
}