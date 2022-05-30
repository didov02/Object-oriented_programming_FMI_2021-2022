#pragma once
#include "Animal.h"

class Dog : public Animal
{
	void sound() const override;
	Animal* clone() const override;
};