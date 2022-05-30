#include <iostream>
#include <iomanip>
#include "RestaurantItem.h"
RestaurantItem::RestaurantItem() :quantity(0), price(0) {}

RestaurantItem::RestaurantItem(const size_t quantity, const double price)
	: quantity(quantity) , price(price)
{}

void RestaurantItem::setQuantity(const size_t quantity)
{
	this->quantity = quantity;
}

void RestaurantItem::setPrice(const double price)
{
	this->price = price;
}

RestaurantItem::TypeOfItem RestaurantItem::getType() const
{
	return TypeOfItem::Unknown;
}

size_t RestaurantItem::getQuantity() const
{
	return this->quantity;
}

double RestaurantItem::getPrice() const
{
	return this->price;
}


const char* RestaurantItem::typeToStr() const
{
	return "Unknown";
}

void RestaurantItem::print() const
{
	std::cout << "Type: " << typeToStr() << std::endl
		<< "Quantity: " << getQuantity() << std::endl
		<< "Price: " << std::fixed << std::setprecision(2) << getPrice() << std::endl;
}