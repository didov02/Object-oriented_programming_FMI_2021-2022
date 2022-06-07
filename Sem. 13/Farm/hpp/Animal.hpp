#pragma once

class Animal
{
public:
	virtual void sound() const = 0;
	virtual Animal* clone() const = 0;
	virtual ~Animal() {}
};
