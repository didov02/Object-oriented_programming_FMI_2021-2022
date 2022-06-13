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
	int maxPassengers;
	int maxSpeed;
	String name;
	int year;

public:
	Vehicle();
	Vehicle(int maxPassengers, int maxSpeed, const String& name, int year);
	virtual ~Vehicle() = default;

	virtual void display() const = 0;
	virtual Vehicle* clone() const = 0;

	VehicleType getType() const;
	void setType(VehicleType);

	int getMaxPassengers() const;
	void setMaxPassengers(int);

	int getMaxSpeed() const;
	void setMaxSpeed(int);

	const String& getName() const;
	void setName(const String&);

	int getYear() const;
	void setYear(int);
};

