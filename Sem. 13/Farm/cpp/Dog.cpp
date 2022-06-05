#include "Dog.h"
#include <iostream>

void Dog::sound() const
{
	std::cout << "Bow wow" << std::endl;
}

Animal* Dog::clone() const
{
	return new Dog(*this);
}