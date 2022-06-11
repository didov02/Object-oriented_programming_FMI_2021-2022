#pragma once
#include "MyString.h"

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
	MyString name;
	int year;

public:
	Vehicle();
	Vehicle(int maxPassengers, int maxSpeed, const MyString& name, int year);

	virtual void display() const = 0;
	virtual Vehicle* clone() const = 0;

	VehicleType getType() const;
	void setType(VehicleType);

	int getMaxPassengers() const;
	void setMaxPassengers(int);

	int getMaxSpeed() const;
	void setMaxSpeed(int);

	const MyString& getName() const;
	void setName(const MyString&);

	int getYear() const;
	void setYear(int);
};

