#pragma once
#include "GroundVehicle.h"

class Motorcycle : public GroundVehicle
{
private:
	String brand;
	String model;
	String frameType;
public:
	Motorcycle();
	Motorcycle(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, const String& color, size_t doorsCount,
		const String& brand, const String& model, const String& frameType);

	Vehicle* clone() const override;
	GroundType getType() const override;
	void display() const override;

	void setBrand(const String&);
	void setModel(const String&);
	void setFrameType(const String&);

	const String& getBrand() const;
	const String& getModel() const;
	const String& getFrameType() const;
};

