#include "Car.h"

Car::Car() : GroundVehicle()
{
	t = CAR;
	brand = nullptr;
	model = nullptr;
	fuelType = nullptr;
}

Car::Car(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, const String& color, size_t doorsCount,
	const String& brand, const String& model, const String& fuelType) : GroundVehicle(maxPassengers, maxSpeed, name, year, color, doorsCount)
{
	this->t = GroundType::CAR;
	this->brand = brand;
	this->model = model;
	this->fuelType = fuelType;
}

Vehicle* Car::clone() const
{
	return new Car(*this);
}

GroundType Car::getType() const
{
	return t;
}

void Car::display() const
{
	std::cout << "Car" << std::endl;
	std::cout << "-Brand: " << brand << std::endl;
	std::cout << "-Model: " << model << std::endl;
	std::cout << "-Fuel Type: " << fuelType << std::endl;
	std::cout << "-Color: " << this->getColor() << std::endl;
}

void Car::setBrand(const String& brand)
{
	this->brand = brand;
}

void Car::setModel(const String& model)
{
	this->model = model;
}

void Car::setFuelType(const String& fuelType)
{
	this->fuelType = fuelType;
}

const String& Car::getBrand() const
{
	return brand;
}

const String& Car::getModel() const
{
	return model;
}

const String& Car::getFuelType() const
{
	return fuelType;
}
