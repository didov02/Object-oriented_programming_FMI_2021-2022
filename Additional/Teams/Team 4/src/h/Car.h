#pragma once
#include "Ground.h"

class Car : public Ground
{
private:
	MyString brand;
	MyString model;
	MyString fuelType;
public:
	Car();
	Car(int maxPassengers, int maxSpeed, const MyString& name, int year, MyString color, size_t doorsCount,
		MyString brand, MyString model, MyString fuelType);

	Vehicle* clone() const override;
	GroundType getType() const override;
	void display() const override;

	void setBrand(const MyString&);
	void setModel(const MyString&);
	void setFuelType(const MyString&);

	const MyString& getBrand() const;
	const MyString& getModel() const;
	const MyString& getFuelType() const;
};

