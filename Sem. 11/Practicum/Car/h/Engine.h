#ifndef CARPART_ENGINE_H
#define CARPART_ENGINE_H

#include <iostream>

#include "CarPart.h"

class Engine : public CarPart {
    double hp;

public:
    Engine(double hp, unsigned long id, const String &producer, const String &description);

    friend std::ostream &operator<<(std::ostream &out, const Engine &other);

    double getHp() const;
};


#endif //CARPART_ENGINE_H
