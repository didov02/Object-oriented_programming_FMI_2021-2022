#include "AirVehicle.h"

AirVehicle::AirVehicle()
{
	wingspan = 0;
	maxAltitude = 0;
	type = VehicleType::Air;
}

AirVehicle::AirVehicle(int maxPassengers, int maxSpeed, const MyString& name, int year, double wingspan, double maxAltitude, const MyString& color, const MyString& model) : Vehicle(maxPassengers, maxSpeed, name, year)
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

void AirVehicle::setColor(const MyString& color)
{
	this->color = color;
}

const MyString& AirVehicle::getColor() const
{
	return color;
}

void AirVehicle::setModel(const MyString& model)
{
	this->model = model;
}

const MyString& AirVehicle::getModel() const
{
	return model;
}
