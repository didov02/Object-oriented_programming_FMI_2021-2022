#include "StoreItem.h"
#include <iostream>

StoreItem::StoreItem() : calories(0), price(0)
{}
StoreItem::StoreItem(size_t calories, double price)
	: calories(calories), price(price)
{}

void StoreItem::setCalories(size_t calories)
{
	this->calories = calories;
}
void StoreItem::setPrice(double price)
{
	this->price = price;
}

size_t StoreItem::getCalories() const
{
	return calories;
}
double StoreItem::getPrice() const
{
	return price;
}

void StoreItem::print() const
{
	std::cout << "Calories: " << calories << std::endl;
	std::cout << "Price: " << price << std::endl;
}