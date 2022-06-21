#pragma once
#include "GroundVehicle.h"

class Truck : public GroundVehicle
{
private:
	String brand;
	size_t capacity;
public:
	Truck() = default;
	Truck(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, const String& color, size_t doorsCount,
		const String& brand, size_t capacity);

	Vehicle* clone() const override;
	GroundType getType() const override;
	void display() const override;

	void setBrand(const String&);
	void setCapacity(size_t);

	const String& getBrand() const;
	size_t getCapacity() const;
};

