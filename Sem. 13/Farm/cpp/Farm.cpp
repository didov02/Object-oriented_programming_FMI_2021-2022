#include "Farm.h"

Farm::Farm()
{
	size = 0;
	capacity = 2;
	animals = new Animal * [capacity];
}
Farm::Farm(size_t capacity)
{
	size = 0;
	this->capacity = capacity;
	animals = new Animal * [capacity];
}
Farm::Farm(const Farm& other)
{
	copy(other);
}
Farm& Farm::operator=(const Farm& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}
Farm::~Farm()
{
	free();
}

void Farm::addAnimal(const Animal& animal)
{
	if (size >= capacity)
		resize();

	animals[size++] = animal.clone();
}
bool Farm::deleteAnimal(size_t index)
{
	if (index <= size)
	{
		delete animals[index];
		animals[index] = nullptr;
		return true;
	}

	return false;
}
void Farm::soundOfAllAnimals()
{
	for (size_t i = 0; i < size; i++)
		if(animals[i] != nullptr)
			animals[i]->sound();
}

void Farm::copy(const Farm& other)
{
	capacity = other.capacity;
	size = other.size;

	animals = new Animal * [capacity];

	for (size_t i = 0; i < size; i++)
		animals[i] = other.animals[i]->clone();
}
void Farm::resize()
{
	Animal** temp = new Animal * [capacity *= 2];
	for (size_t i = 0; i < size; i++)
		temp[i] = animals[i]; //temp to point to animal pointer(same obj)

	delete[] animals;
	animals = temp;
}
void Farm::free()
{
	for (size_t i = 0; i < size; i++)
		delete animals[i];

	delete[] animals;

	capacity = size = 0;
}