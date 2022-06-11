#include "WaterVehicle.h"

WaterVehicle::WaterVehicle()
{
}

WaterVehicle::WaterVehicle(int maxPassengers, int maxSpeed, const MyString& name, int year,
	double length, double width, double crewSize, const MyString& color, const MyString& model) : Vehicle(maxPassengers, maxSpeed, name, year)
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

void WaterVehicle::setCrewSize(double size)
{
	this->crewSize = size;
}

double WaterVehicle::getCrewSize() const
{
	return crewSize;
}

void WaterVehicle::setColor(const MyString& color)
{
	this->color = color;
}

const MyString& WaterVehicle::getColor() const
{
	return color;
}

void WaterVehicle::setModel(const MyString& model)
{
	this->model = model;
}

const MyString& WaterVehicle::getModel() const
{
	return model;
}
