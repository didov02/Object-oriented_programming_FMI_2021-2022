#include "Vehicle.h"

Vehicle::Vehicle()
{
	maxPassengers = 0;
	maxSpeed = 0;
	year = 0;
}

Vehicle::Vehicle(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year)
{
	this->maxPassengers = maxPassengers;
	this->maxSpeed = maxSpeed;
	this->name = name;
	this->year = year;
}

VehicleType Vehicle::getType() const
{
	return type;
}

void Vehicle::setType(VehicleType type)
{
	this->type = type;
}

size_t Vehicle::getMaxPassengers() const
{
	return maxPassengers;
}

void Vehicle::setMaxPassengers(size_t maxPassengers)
{
	this->maxPassengers = maxPassengers;
}

size_t Vehicle::getMaxSpeed() const
{
	return maxSpeed;
}

void Vehicle::setMaxSpeed(size_t maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

const String& Vehicle::getName() const
{
	return name;
}

void Vehicle::setName(const String& name)
{
	this->name = name;
}

size_t Vehicle::getYear() const
{
	return year;
}

void Vehicle::setYear(size_t year)
{
	this->year = year;
}
