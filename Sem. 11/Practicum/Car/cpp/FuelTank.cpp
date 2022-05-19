#include "../h/FuelTank.h"

FuelTank::FuelTank() {
    capacity = 0;
    fuel = 0;
}

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
    fuel -= litres;

    if (fuel < 0) {
        fuel += litres;
        throw std::logic_error("Not enough fuel!");
    }
}

double FuelTank::getFuel() const {
    return fuel;
}
