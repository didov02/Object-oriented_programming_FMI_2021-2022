#ifndef CARPART_CARPART_H
#define CARPART_CARPART_H

#include "String.h"
#include <iostream>

class CarPart {
    unsigned long id;
    String producer;
    String description;

public:
    CarPart() = default;

    CarPart(unsigned long id, const String &producer, const String &description);

    friend std::ostream &operator<<(std::ostream &out, const CarPart &other);


};


#endif //CARPART_CARPART_H
