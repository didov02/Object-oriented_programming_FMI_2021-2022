#pragma once
#include "RestaurantItem.h"

class Restaurant
{
	RestaurantItem** items;
	size_t capacity, size;
public:
	Restaurant();
	Restaurant(const Restaurant&);
	Restaurant& operator=(const Restaurant&);
	~Restaurant();

	void addItem(const RestaurantItem&);
	bool eraseItem(const size_t);
	bool changePrice(const size_t, const double);
	bool changeName(const size_t, const char*);

	void printAllNonAlcDrinks() const;
	void printAllProducts() const;
private:
	void resize();
	void copy(const Restaurant&);
	void free();
};