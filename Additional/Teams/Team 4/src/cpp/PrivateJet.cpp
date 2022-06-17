#include "PrivateJet.h"

PrivateJet::PrivateJet(size_t maxPassengers, size_t maxSpeed, const String& name, size_t year,
    double wingspan, double maxAltitude, const String& color, const String& model, bool hasDrinkBar, bool hasSleepingRoom) : AirVehicle(maxPassengers, maxSpeed, name, year, wingspan, maxAltitude, color, model)
{
    this->hasDrinkBar = hasDrinkBar;
    this->hasSleepingRoom = hasSleepingRoom;
    this->t = AirType::JET;
}

Vehicle* PrivateJet::clone() const
{
    return new PrivateJet(*this);
}

AirType PrivateJet::getType() const
{
    return t;
}

void PrivateJet::display() const
{
    std::cout << "Plane Jet" << std::endl;
    std::cout << "-Name: " << name << std::endl;
    std::cout << "-Year: " << year << std::endl;
    std::cout << "-Color: " << color << std::endl;
    std::cout << "-Wingspan: " << wingspan << std::endl;
    std::cout << "-Max Altitude: " << maxAltitude << std::endl;
    if(hasDrinkBar)
        std::cout << "-Has drinkbar: yes" << std::endl;
    else
        std::cout << "-Has drinkbar: no" << std::endl;

    if (hasSleepingRoom)
        std::cout << "-Has sleeping room: yes" << std::endl;
    else
        std::cout << "-Has sleeping room: no" << std::endl;
}

bool PrivateJet::getDrinkBar() const
{
    return hasDrinkBar;
}

void PrivateJet::setDrinkBar(bool hasDrinkBar)
{
    this->hasDrinkBar = hasDrinkBar;
}

bool PrivateJet::getSleepingRoom() const
{
    return hasSleepingRoom;
}

void PrivateJet::setSleepingRoom(bool hasSleepingRoom)
{
    this->hasSleepingRoom = hasSleepingRoom;
}
