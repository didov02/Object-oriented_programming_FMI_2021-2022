#ifndef CARPART_TIRE_H
#define CARPART_TIRE_H

#include "CarPart.h"

const short MAX_WIDTH = 365; //mm
const short MIN_WIDTH = 155; //mm
const short MAX_PROFILE = 80; //mm
const short MIN_PROFILE = 30; //mm
const short MAX_DIAMETER = 21; //inches
const short MIN_DIAMETER = 13; //inches

class Tire : public CarPart {
    double width; //between 155 and 365 mm
    double profile; //between 30 and 80 mm;
    double diameter; //between 13 and 21 inches

public:
    Tire();

    Tire(double width, double profile, double diameter, unsigned long id, const String &producer, const String &description);

    friend std::ostream &operator<<(std::ostream &out, const Tire &other);


};


#endif //CARPART_TIRE_H
