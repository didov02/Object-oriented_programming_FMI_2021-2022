#ifndef CARPART_CAR_H
#define CARPART_CAR_H

#include <cmath>

#include "Engine.h"
#include "Tire.h"
#include "Battery.h"
#include "FuelTank.h"

const short TIRES_NUMBER = 5;
const double DRAG_DISTANCE = 0.4; //km

class Car {
    FuelTank tank;
    const Engine *engine;
    int tiresCount;
    const Tire *tires[TIRES_NUMBER];
    const Battery *accumulator;
    double kmTraveled;
    double weight; //kg

public:
    Car(const FuelTank &tank, const Engine *engine, const Battery *battery, double kmTraveled, double weight);

    void addTire(const Tire *tire, int count = 1);

    void drive(double km);

    double getFuel() const;

    const FuelTank &getFuelTank() const;

    double getWeight() const;

    const Engine &getEngine() const;

    friend Car *dragRace(Car *car1, Car *car2);

};


#endif //CARPART_CAR_H
