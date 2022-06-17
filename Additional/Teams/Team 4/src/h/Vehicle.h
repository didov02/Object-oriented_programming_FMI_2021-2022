#pragma once
#include "String.h"

enum VehicleType {
	Ground,
	Air,
	Water,
	Unknown
};

class Vehicle
{
protected:
	VehicleType type;
	size_t maxPassengers;
	size_t maxSpeed;
	String name;
	size_t year;

public:
	Vehicle();
	Vehicle(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year);
	virtual ~Vehicle() = default;

	virtual void display() const = 0;
	virtual Vehicle* clone() const = 0;

	VehicleType getType() const;
	void setType(VehicleType);

	size_t getMaxPassengers() const;
	void setMaxPassengers(size_t);

	size_t getMaxSpeed() const;
	void setMaxSpeed(size_t);

	const String& getName() const;
	void setName(const String&);

	size_t getYear() const;
	void setYear(size_t);
};

