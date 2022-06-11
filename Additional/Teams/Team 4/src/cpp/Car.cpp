#include "Car.h"

Car::Car() : Ground()
{
	t = CAR;
	brand = nullptr;
	model = nullptr;
	fuelType = nullptr;
}

Car::Car(int maxPassengers, int maxSpeed, const MyString& name, int year, MyString color, size_t doorsCount,
	MyString brand, MyString model, MyString fuelType) : Ground(maxPassengers, maxSpeed, name, year, color, doorsCount)
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

void Car::setBrand(const MyString& brand)
{
	this->brand = brand;
}

void Car::setModel(const MyString& model)
{
	this->model = model;
}

void Car::setFuelType(const MyString& fuelType)
{
	this->fuelType = fuelType;
}

const MyString& Car::getBrand() const
{
	return brand;
}

const MyString& Car::getModel() const
{
	return model;
}

const MyString& Car::getFuelType() const
{
	return fuelType;
}
