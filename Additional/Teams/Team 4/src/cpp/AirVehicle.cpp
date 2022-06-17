#include "AirVehicle.h"

AirVehicle::AirVehicle()
{
	wingspan = 0;
	maxAltitude = 0;
	type = VehicleType::Air;
}

AirVehicle::AirVehicle(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double wingspan, double maxAltitude, const String& color, const String& model) : Vehicle(maxPassengers, maxSpeed, name, year)
{
	this->wingspan = wingspan;
	this->maxAltitude = maxAltitude;
	this->color = color;
	this->model = model;
	type = VehicleType::Air;
}

void AirVehicle::setWingspan(double wingspan)
{
	this->wingspan = wingspan;
}

double AirVehicle::getWingspan() const
{
	return wingspan;
}

void AirVehicle::setMaxAltitude(double maxAltitude)
{
	this->maxAltitude = maxAltitude;
}

double AirVehicle::getMaxAltitude() const
{
	return maxAltitude;
}

void AirVehicle::setColor(const String& color)
{
	this->color = color;
}

const String& AirVehicle::getColor() const
{
	return color;
}

void AirVehicle::setModel(const String& model)
{
	this->model = model;
}

const String& AirVehicle::getModel() const
{
	return model;
}
