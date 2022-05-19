#ifndef CARPART_BATTERY_H
#define CARPART_BATTERY_H

#include "CarPart.h"

class Battery : public CarPart{
    unsigned long batteryId;
    double capacity; //Ah

public:
    Battery();

    Battery(unsigned long batteryId, double capacity, unsigned long id, const String &producer, const String &description);

    friend std::ostream &operator<<(std::ostream &out, const Battery &other);
};


#endif //CARPART_BATTERY_H
