#include "../h/Car.h"

Car::Car(const FuelTank &tank, const Engine *engine, const Battery *battery, double kmTraveled,
         double weight) : tank(tank), engine(engine), accumulator(battery), kmTraveled(kmTraveled),
                          weight(weight), tiresCount(0) {}

void Car::addTire(const Tire *tire, int count) {
    for (int i = 0; i < count; ++i) {
        if (tiresCount >= TIRES_NUMBER)
            throw std::logic_error("No more space for tires!");

        tires[tiresCount++] = tire;
    }
}

void Car::drive(double km) {
    if (tiresCount < 4)
        throw std::logic_error("The car does not have 4 tires!");

    tank.use(km); //throws exception if not enough fuel
    kmTraveled += km; //stays unchanged if exception is thrown
}

double Car::getFuel() const {
    return tank.getFuel();
}

const FuelTank &Car::getFuelTank() const {
    return tank;
}

double Car::getWeight() const {
    return weight;
}

const Engine &Car::getEngine() const {
    return *engine;
}

Car *dragRace(Car *car1, Car *car2) {
    bool canDrive1 = true;

    try {
        car1->drive(DRAG_DISTANCE);
    } catch (std::logic_error &e) {
        canDrive1 = false; // car1 cannot travel this distance
    }

    try {
        car2->drive(DRAG_DISTANCE);
    } catch (std::logic_error &e) {
        if (canDrive1)
            return car1;
        return nullptr;
    }

    if (!canDrive1)
        return car2;

    double ratio1 = car1->getRaceRatio();
    double ratio2 = car2->getRaceRatio();

    if (ratio1 < ratio2)
        return car1;
    if (ratio2 < ratio1)
        return car2;
    return nullptr;
}

double Car::getRaceRatio() const {
    return weight / engine->getHp();
}
