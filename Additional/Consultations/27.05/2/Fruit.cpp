#include "Fruit.h"
#include <iostream>
#include <cstring>
#pragma warning (disable: 4996)

Fruit::Fruit() : StoreItem()
{
	name = new char[1];
	name[0] = '\0';
	type = Type::FRUIT;
}
Fruit::Fruit(size_t calories, double price, const char* name)
	: StoreItem(calories,price)
{
	type = Type::FRUIT;
	size_t size = strlen(name);
	this->name = new char[size + 1];
	strcpy(this->name, name);
}

Fruit::Fruit(const Fruit& other) 
	: StoreItem(other)
{
	copy(other);
}
Fruit& Fruit::operator=(const Fruit& other)
{
	if (this != &other)
	{
		free();
		StoreItem::operator=(other);
		copy(other);
	}

	return *this;
}
Fruit::~Fruit()
{
	free();
}

void Fruit::setName(const char* name)
{
	if (this->name != nullptr)
		delete[] this->name;

	size_t size = strlen(name);
	this->name = new char[size + 1];
	strcpy(this->name, name);
}
const char* Fruit::getName() const
{
	return name;
}

StoreItem* Fruit::clone() const
{
	return new Fruit(*this);
}

bool operator>(const Fruit& f, const Fruit& s)
{
	return f.getCalories() > s.getCalories();
}

void Fruit::print() const
{
	StoreItem::print();
	std::cout << name << std::endl;
}

void Fruit::copy(const Fruit& other)
{
	size_t size = strlen(other.name);
	name = new char[size + 1];
	strcpy(name, other.name);
}
void Fruit::free()
{
	delete[] name;
}