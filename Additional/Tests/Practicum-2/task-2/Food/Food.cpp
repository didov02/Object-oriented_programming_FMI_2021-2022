#include "Food.h"
#include <iostream>
#include <cstring>
#pragma warning (disable : 4996)

Food::Food() :RestaurantItem(), grams(0)
{
	type = TypeOfItem::Food;
	name = new char[1];
	name[0] = '\0';
}

Food::Food(const size_t quantity, const double price, const char* name, const double grams)
	: RestaurantItem(quantity, price), grams(grams)
{
	type = TypeOfItem::Food;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Food::Food(const Food& other) : RestaurantItem(other)
{
	 copy(other);
}

Food& Food::operator=(const Food& other)
{
	if (this != &other)
	{
		free();
		RestaurantItem::operator=(other);
		copy(other);
	}

	return *this;
}

Food::~Food()
{
	free();
}

const char* Food::getName() const
{
	return name;
}

const double Food::getGrams() const
{
	return grams;
}

void Food::setName(const char* name)
{
	if (this->name != nullptr)
		delete[] name;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Food::setGrams(const double grams)
{
	this->grams = grams;
}

void Food::changeName(const char* name)
{
	setName(name);
}

RestaurantItem* Food::clone() const
{
	return new Food(*this);
}

const char* Food::typeToStr() const
{
	return "FOOD";
}

void Food::print() const
{
	RestaurantItem::print();
	std::cout << "Name: " << name << std::endl
		<< "Grams: " << grams << std::endl;
}


void Food::copy(const Food& other)
{
	type = TypeOfItem::Food;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	grams = other.grams;
}

void Food::free()
{
	delete[] name;
}
