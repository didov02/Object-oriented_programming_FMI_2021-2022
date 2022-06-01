#pragma once
#include "RestaurantItem.h"

class Food : public RestaurantItem
{
	char* name;
	double grams;
public:
	Food();
	Food(const size_t, const double, const char*, const double);
	Food(const Food&);
	Food& operator=(const Food&);
	~Food();

	const char* getName() const;
	const double getGrams() const;

	void setName(const char* name);
	void setGrams(const double grams);

	void changeName(const char*) override;
	RestaurantItem* clone() const override;
	const char* typeToStr() const override;
	void print() const override;
private:
	void copy(const Food&);
	void free();
};