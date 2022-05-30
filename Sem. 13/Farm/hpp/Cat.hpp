#pragma once
#include "Animal.h"

class Cat : public Animal
{
	void sound() const override;
	Animal* clone() const override;
};