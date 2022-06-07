#pragma once
#include "Animal.h"

class Mouse : public Animal
{
	void sound() const override;
	Animal* clone() const override;
};