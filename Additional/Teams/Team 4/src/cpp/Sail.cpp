#include "Sail.h"

Sail::Sail(int maxPassengers, int maxSpeed, const String& name, int year
    , double length, double width, int crewSize, const String& color, const String& model, bool hasEngine, int sailsCount) : WaterVehicle(maxPassengers, maxSpeed,
        name, year, length, width, crewSize, color, model)
{
    this->hasEngine = hasEngine;
    this->sailsCount = sailsCount;
    this->t = WaterType::SAIL;
}

Vehicle* Sail::clone() const
{
    return new Sail(*this);
}

WaterType Sail::getType() const
{
    return t;
}

void Sail::display() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Max speed: " << maxSpeed << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Crew size: " << crewSize << std::endl;
    std::cout << "Sails count: " << sailsCount << std::endl;
    if (hasEngine)
        std::cout << "Has engine: yes" << std::endl;
    else
        std::cout << "Has engine: no" << std::endl;
}

bool Sail::getHasEngine() const
{
    return hasEngine;
}

void Sail::setHasEngine(bool hasEngine)
{
    this->hasEngine = hasEngine;
}

int Sail::getSailsCount() const
{
    return sailsCount;
}

void Sail::setSailsCount(int sailsCount)
{
    this->sailsCount = sailsCount;
}
