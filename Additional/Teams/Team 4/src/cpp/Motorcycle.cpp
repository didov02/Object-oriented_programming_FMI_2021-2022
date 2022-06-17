#include "Motorcycle.h"

Motorcycle::Motorcycle() : GroundVehicle()
{
	t = MOTORCYCLE;
	brand = nullptr;
	model = nullptr;
	frameType = nullptr;
}

Motorcycle::Motorcycle(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, const String& color, size_t doorsCount,
	const String& brand, const String& model, const String& frameType) : GroundVehicle(maxPassengers, maxSpeed, name, year, color, doorsCount)
{
	t = GroundType::MOTORCYCLE;
	this->brand = brand;
	this->model = model;
	this->frameType = frameType;
}

Vehicle* Motorcycle::clone() const
{
	return new Motorcycle(*this);
}

GroundType Motorcycle::getType() const
{
	return t;
}

void Motorcycle::display() const
{
	std::cout << "Motorcycle" << std::endl;
	std::cout << "-Brand: " << brand << std::endl;
	std::cout << "-Model: " << model << std::endl;
	std::cout << "-Frame type: " << frameType << std::endl;
}

void Motorcycle::setBrand(const String& brand)
{
	this->brand = brand;
}

void Motorcycle::setModel(const String& model)
{
	this->model = model;
}

void Motorcycle::setFrameType(const String& frameType)
{
	this->frameType = frameType;
}

const String& Motorcycle::getBrand() const
{
	return brand;
}

const String& Motorcycle::getModel() const
{
	return model;
}

const String& Motorcycle::getFrameType() const
{
	return frameType;
}
