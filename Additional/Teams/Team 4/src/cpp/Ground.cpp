#include "Ground.h"
#include <iostream>


Ground::Ground() : Vehicle()
{

}

Ground::Ground(int maxPassengers, int maxSpeed, const MyString& name, int year, const MyString& color, size_t doorsCount) : 
	Vehicle(maxPassengers,maxSpeed,name,year)
{
	this->color = color;
	this->doorsCount = doorsCount;
	this->type = VehicleType::Ground;
}

void Ground::setColor(const MyString& color)
{
	this->color = color;
}

const MyString& Ground::getColor() const
{
	return color;
}

void Ground::setDoorsCount(size_t doorsCount)
{
	this->doorsCount = doorsCount;
}

size_t Ground::getDoorsCount() const
{
	return doorsCount;
}
