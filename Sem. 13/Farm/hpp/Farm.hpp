#pragma once
#include "Animal.h"

class Farm
{
	Animal** animals;
	size_t size, capacity;
public:
	Farm();
	Farm(size_t capacity);
	Farm(const Farm&);
	Farm& operator=(const Farm&);
	~Farm();

	void addAnimal(const Animal&);
	bool deleteAnimal(size_t index);
	void soundOfAllAnimals();
private:
	void resize();
	void copy(const Farm&);
	void free();
};