#include "Jacht.h"

Jacht::Jacht(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year,
	double length, double width, size_t crewSize, const String& color, const String& model, bool hasSwimmingPool, size_t roomsCount) : WaterVehicle(maxPassengers, maxSpeed,
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

size_t Jacht::getRoomsCount() const
{
	return roomsCount;
}

void Jacht::setRoomsCount(size_t roomsCount)
{
	this->roomsCount = roomsCount;
}
