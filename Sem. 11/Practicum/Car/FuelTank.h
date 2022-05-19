#ifndef CARPART_FUELTANK_H
#define CARPART_FUELTANK_H

#include <iostream>

class FuelTank {
    double capacity; //in litres
    double fuel; //in litres

public:
    FuelTank();

    FuelTank(double capacity);

    void fill(double litres);

    void use(double litres);

    double getFuel() const;
};


#endif //CARPART_FUELTANK_H
