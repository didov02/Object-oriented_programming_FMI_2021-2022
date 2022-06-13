#pragma once
#include "GroundVehicle.h"

class Car : public GroundVehicle
{
private:
	String brand;
	String model;
	String fuelType;
public:
	Car();
	Car(int maxPassengers, int maxSpeed, const String& name, int year, const String& color, size_t doorsCount,
		const String& brand, const String& model, const String& fuelType);

	Vehicle* clone() const override;
	GroundType getType() const override;
	void display() const override;

	void setBrand(const String&);
	void setModel(const String&);
	void setFuelType(const String&);

	const String& getBrand() const;
	const String& getModel() const;
	const String& getFuelType() const;
};

