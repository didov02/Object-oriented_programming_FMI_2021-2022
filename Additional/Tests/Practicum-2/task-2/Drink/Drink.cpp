#include "Drink.h"
#include <iostream>
#include <cstring>
#pragma warning (disable : 4996)

Drink::Drink() :RestaurantItem(), alc(0)
{
	type = TypeOfItem::Drink;
	name = new char[1];
	name[0] = '\0';
}

Drink::Drink(const size_t quantity, const double price, const char* name, const double alc)
	: RestaurantItem(quantity, price), alc(alc)
{
	type = TypeOfItem::Drink;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Drink::Drink(const Drink& other) : RestaurantItem(other)
{
	copy(other);
}

Drink& Drink::operator=(const Drink& other)
{
	if (this != &other)
	{
		free();
		RestaurantItem::operator=(other);
		copy(other);
	}

	return *this;
}

Drink::~Drink()
{
	free();
}

const char* Drink::getName() const
{
	return name;
}

const double Drink::getAlc() const
{
	return alc;
}

void Drink::setName(const char* name)
{
	if (this->name != nullptr)
		delete[] name;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Drink::setAlc(const double grams)
{
	this->alc = alc;
}

void Drink::changeName(const char* name)
{
	setName(name);
}

RestaurantItem* Drink::clone() const
{
	return new Drink(*this);
}

const char* Drink::typeToStr() const
{
	return "DRINK";
}

void Drink::print() const
{
	RestaurantItem::print();
	std::cout << "Name: " << name << std::endl
		<< "Alcohol percentage: " << alc << "%" << std::endl;
}

void Drink::copy(const Drink& other)
{
	type = TypeOfItem::Drink;

	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	alc = other.alc;
}

void Drink::free()
{
	delete[] name;
}
