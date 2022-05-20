#include "../h/FuelTank.h"

FuelTank::FuelTank(double capacity) {
    this->capacity = capacity;
    this->fuel = capacity;
}

void FuelTank::fill(double litres) {
    fuel += litres;

    if (fuel > capacity)
        fuel = capacity;
}

void FuelTank::use(double litres) {
    if (fuel < litres)
        throw std::logic_error("Not enough fuel!");

    fuel -= litres;
}

double FuelTank::getFuel() const {
    return fuel;
}
