#include "Motorcycle.h"

Motorcycle::Motorcycle() : Ground()
{
	t = MOTORCYCLE;
	brand = nullptr;
	model = nullptr;
	frameType = nullptr;
}

Motorcycle::Motorcycle(int maxPassengers, int maxSpeed, const MyString& name, int year, MyString color, size_t doorsCount,
	MyString brand, MyString model, MyString frameType) : Ground(maxPassengers, maxSpeed, name, year, color, doorsCount)
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

void Motorcycle::setBrand(const MyString& brand)
{
	this->brand = brand;
}

void Motorcycle::setModel(const MyString& model)
{
	this->model = model;
}

void Motorcycle::setFrameType(const MyString& frameType)
{
	this->frameType = frameType;
}

const MyString& Motorcycle::getBrand() const
{
	return brand;
}

const MyString& Motorcycle::getModel() const
{
	return model;
}

const MyString& Motorcycle::getFrameType() const
{
	return frameType;
}
