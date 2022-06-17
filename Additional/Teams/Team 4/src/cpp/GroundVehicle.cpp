#include "GroundVehicle.h"
#include <iostream>


GroundVehicle::GroundVehicle() : Vehicle()
{
	type = VehicleType::Ground;
	doorsCount = 0;
}

GroundVehicle::GroundVehicle(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, const String& color, size_t doorsCount) :
	Vehicle(maxPassengers,maxSpeed,name,year)
{
	this->color = color;
	this->doorsCount = doorsCount;
	this->type = VehicleType::Ground;
}

void GroundVehicle::setColor(const String& color)
{
	this->color = color;
}

const String& GroundVehicle::getColor() const
{
	return color;
}

void GroundVehicle::setDoorsCount(size_t doorsCount)
{
	this->doorsCount = doorsCount;
}

size_t GroundVehicle::getDoorsCount() const
{
	return doorsCount;
}
