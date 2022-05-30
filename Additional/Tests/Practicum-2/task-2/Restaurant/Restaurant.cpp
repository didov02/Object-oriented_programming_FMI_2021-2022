#include <iostream>
#include "Restaurant.h"
#include "Drink.h"

//Big 4
Restaurant::Restaurant()
{
	capacity = 2;
	size = 0;

	items = new RestaurantItem* [capacity];
}
Restaurant::Restaurant(const Restaurant& other)
{
	copy(other);
}
Restaurant& Restaurant::operator=(const Restaurant& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}
Restaurant::~Restaurant()
{
	free();
}

//Add + delete methods
void Restaurant::addItem(const RestaurantItem& item)
{
	if (size >= capacity)
		resize();

	items[size++] = item.clone();
}
bool Restaurant::eraseItem(const size_t index)
{
	if (index >= size)
		return false;

	delete items[index];
	items[index] = nullptr;
	return true;
}

//Change an attribute methods
bool Restaurant::changePrice(const size_t index, const double price)
{
	if (index >= size)
		return false;

	items[index]->setPrice(price);
	return true;
}
bool Restaurant::changeName(const size_t index, const char* name)
{
	if (index >= size)
		return false;

	items[index]->changeName(name);
	return true;
}

//Print methods
void Restaurant::printAllNonAlcDrinks() const
{
	/*
	* Example with dynamic_cast:
	for (size_t i = 0; i < size; i++)
	{
		if (items[i] != nullptr)
		{
			Drink* d = dynamic_cast<Drink*>(items[i]); // dynamic cast

			if (d != nullptr && d->getAlc() == 0)
				items[i]->print();
		}
	}
	*/

	for (size_t i = 0; i < size; i++)
	{
		if(items[i] != nullptr)
			if(strcmp(items[i]->typeToStr(), "DRINK") == 0)
			{
				Drink* d = (Drink*)items[i]; // static cast
				if (d->getAlc() == 0.00)
					items[i]->print();
			}
	}
}
void Restaurant::printAllProducts() const
{
	for (size_t i = 0; i < size; i++)
	{
		if(items[i] != nullptr)
			items[i]->print();
	}
}

//Private functions/methods
void Restaurant::resize()
{
	RestaurantItem** temp = new RestaurantItem* [capacity *= 2];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = items[i];
	}

	delete[] items;
	items = temp;
}
void Restaurant::copy(const Restaurant& other)
{
	capacity = other.capacity;
	size = other.size;

	items = new RestaurantItem * [capacity];

	for (size_t i = 0; i < size; i++)
		items[i] = other.items[i]->clone();
}
void Restaurant::free()
{
	for (size_t i = 0; i < size; i++)
		delete items[i];

	delete[] items;

	capacity = size = 0;
}