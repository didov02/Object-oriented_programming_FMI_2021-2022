#include "Plane.h"

Plane::Plane(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year, double wingspan, double maxAltitude, const String& color, const String& model
    , double maxStorage, double maxAirTime) : AirVehicle(maxPassengers, maxSpeed, name, year, wingspan, maxAltitude, color, model)
{
    this->maxStorage = maxStorage;
    this->maxAirTime = maxAirTime;
    this->t = AirType::PLANE;
}

Vehicle* Plane::clone() const
{
    return new Plane(*this);
}

AirType Plane::getType() const
{
    return t;
}

void Plane::display() const
{
    std::cout << "Plane" << std::endl;
    std::cout << "-Name: " << name << std::endl;
    std::cout << "-Year: " << year << std::endl;
    std::cout << "-Color: " << color << std::endl;
    std::cout << "-Wingspan: " << wingspan << std::endl;
    std::cout << "-Max Altitude: " << maxAltitude << std::endl;
    std::cout << "-Max Storage: " << maxStorage << std::endl;
    std::cout << "-Max Airtime: " << maxAirTime << std::endl;
}

double Plane::getMaxStorage() const
{
    return maxStorage;
}

void Plane::setMaxStorage(double maxStorage)
{
    this->maxStorage = maxStorage;
}

double Plane::getMaxAirtime() const
{
    return maxAirTime;
}

void Plane::setMaxAirtime(double airTime)
{
    this->maxAirTime = airTime;
}
