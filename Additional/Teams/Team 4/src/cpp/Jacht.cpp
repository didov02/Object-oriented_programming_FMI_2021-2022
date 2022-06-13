#include "Jacht.h"

Jacht::Jacht(int maxPassengers, int maxSpeed, const String& name, int year,
	double length, double width, int crewSize, const String& color, const String& model, bool hasSwimmingPool, int roomsCount) : WaterVehicle(maxPassengers, maxSpeed,
		name, year, length, width, crewSize, color, model)
{
	this->hasSwimmingPool = hasSwimmingPool;
	this->roomsCount = roomsCount;
	this->t = WaterType::JACHT;
}

Vehicle* Jacht::clone() const
{
	return new Jacht(*this);
}

WaterType Jacht::getType() const
{
	return t;
}

void Jacht::display() const
{
	std::cout << "Yacht" << std::endl;
    std::cout << "-Name: " << name << std::endl;
    std::cout << "-Year: " << year << std::endl;
    std::cout << "-Color: " << color << std::endl;
    std::cout << "-Crew size: " << crewSize << std::endl;
    std::cout << "-Rooms count: " << roomsCount << std::endl;
    if (hasSwimmingPool)
        std::cout << "-Has swimming pool: yes" << std::endl;
    else
        std::cout << "-Has swimming pool: no" << std::endl;
}

bool Jacht::getHasSwimmingPool() const
{
	return hasSwimmingPool;
}

void Jacht::setHasSwimmingPoll(bool swim)
{
	this->hasSwimmingPool = swim;
}

int Jacht::getRoomsCount() const
{
	return roomsCount;
}

void Jacht::setRoomsCount(int roomsCount)
{
	this->roomsCount = roomsCount;
}
