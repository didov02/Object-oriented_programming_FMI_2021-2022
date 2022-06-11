#pragma once
#include "Ground.h"

class Truck : public Ground
{
private:
	MyString brand;
	size_t capacity;
public:
	Truck();
	Truck(int maxPassengers, int maxSpeed, const MyString& name, int year, MyString color, size_t doorsCount,
		MyString brand, size_t capacity);

	Vehicle* clone() const override;
	GroundType getType() const override;
	void display() const override;

	void setBrand(const MyString&);
	void setCapacity(size_t);

	const MyString& getBrand() const;
	size_t getCapacity() const;
};

