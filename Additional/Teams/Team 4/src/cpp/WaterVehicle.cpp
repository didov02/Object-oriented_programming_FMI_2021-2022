#include "WaterVehicle.h"

WaterVehicle::WaterVehicle()
{
	type = VehicleType::Water;
	length = 0;
	width = 0;
	crewSize = 0;
}

WaterVehicle::WaterVehicle(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year,
	double length, double width, size_t crewSize, const String& color, const String& model) : Vehicle(maxPassengers, maxSpeed, name, year)
{
	this->length = length;
	this->width = width;
	this->crewSize = crewSize;
	this->color = color;
	this->model = model;
	this->type = VehicleType::Water;
}

void WaterVehicle::setLength(double length)
{
	this->length = length;
}

double WaterVehicle::getLength() const
{
	return length;
}

void WaterVehicle::setWidth(double width)
{
	this->width = width;
}

double WaterVehicle::getWidth() const
{
	return width;
}

void WaterVehicle::setCrewSize(size_t size)
{
	this->crewSize = size;
}

size_t WaterVehicle::getCrewSize() const
{
	return crewSize;
}

void WaterVehicle::setColor(const String& color)
{
	this->color = color;
}

const String& WaterVehicle::getColor() const
{
	return color;
}

void WaterVehicle::setModel(const String& model)
{
	this->model = model;
}

const String& WaterVehicle::getModel() const
{
	return model;
}
