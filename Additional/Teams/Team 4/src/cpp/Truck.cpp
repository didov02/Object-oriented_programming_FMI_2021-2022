#include "Truck.h"

Truck::Truck() : Ground()
{

}

Truck::Truck(int maxPassengers, int maxSpeed, const MyString& name, int year, MyString color, size_t doorsCount,
	MyString brand, size_t capacity) : Ground(maxPassengers, maxSpeed, name, year, color, doorsCount)
{
	this->brand = brand;
	this->capacity = capacity;
	this->t = GroundType::TRUCK;
}

Vehicle* Truck::clone() const
{
	return new Truck(*this);
}

GroundType Truck::getType() const
{
	return t;
}

void Truck::display() const
{
	std::cout << "Truck" << std::endl;
	std::cout << "-Brand: " << brand << std::endl;
	std::cout << "-Capacity: " << capacity << std::endl;
	std::cout << "-Color: " << this->getColor() << std::endl;
	std::cout << "-Doors count: " << this->getDoorsCount() << std::endl;
}

void Truck::setBrand(const MyString& brand)
{
	this->brand = brand;
}

void Truck::setCapacity(size_t capacity)
{
	this->capacity = capacity;
}

const MyString& Truck::getBrand() const
{
	return brand;
}

size_t Truck::getCapacity() const
{
	return capacity;
}
