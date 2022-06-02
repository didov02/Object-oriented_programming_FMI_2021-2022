#pragma once
#include "RestaurantItem.h"

class Drink : public RestaurantItem
{
	char* name;
	double alc;
public:
	Drink();
	Drink(const size_t, const double, const char*, const double);
	Drink(const Drink&);
	Drink& operator=(const Drink&);
	~Drink();

	friend bool operator >(const Drink&, const Drink&);

	const char* getName() const;
	const double getAlc() const;

	void setName(const char* name);
	void setAlc(const double grams);

	void changeName(const char*) override;
	RestaurantItem* clone() const override;
	const char* typeToStr() const override;
	void print() const override;
private:
	void copy(const Drink&);
	void free();
};
