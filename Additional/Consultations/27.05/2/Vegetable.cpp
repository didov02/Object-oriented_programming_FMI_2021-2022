#include "Vegetable.h"
#include <iostream>
#include <cstring>
#pragma warning (disable: 4996)

Vegetable::Vegetable() : StoreItem()
{
	sort = new char[1];
	sort[0] = '\0';
}
Vegetable::Vegetable(size_t calories, double price, const char* sort)
	: StoreItem(calories, price)
{
	type = Type::VEGETABLE;
	size_t size = strlen(sort);
	this->sort = new char[size + 1];
	strcpy(this->sort, sort);
}

Vegetable::Vegetable(const Vegetable& other)
	: StoreItem(other)
{
	copy(other);
}
Vegetable& Vegetable::operator=(const Vegetable& other)
{
	if (this != &other)
	{
		free();
		StoreItem::operator=(other);
		copy(other);
	}

	return *this;
}
Vegetable::~Vegetable()
{
	free();
}

void Vegetable::setSort(const char* sort)
{
	if (this->sort != nullptr)
		delete[] this->sort;

	size_t size = strlen(sort);
	this->sort = new char[size + 1];
	strcpy(this->sort, sort);
}
const char* Vegetable::getSort() const
{
	return sort;
}

StoreItem* Vegetable::clone() const
{
	return new Vegetable(*this);
}

void Vegetable::print() const
{
	StoreItem::print();
	std::cout << sort << std::endl;
}

void Vegetable::copy(const Vegetable& other)
{
	size_t size = strlen(other.sort);
	sort = new char[size + 1];
	strcpy(sort, other.sort);
}
void Vegetable::free()
{
	delete[] sort;
}